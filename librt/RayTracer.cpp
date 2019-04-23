//------------------------------------------------------------------------------
// Copyright 2015 Corey Toler-Franklin, University of Florida
// RayTracer.h
// Shades the objects in the scene based on information gathered by bouncing
// a ray in the scene and computing ray/surface intersections
//------------------------------------------------------------------------------

#include "RayTracer.h"
#include "Camera.h"
#include "Light.h"
#include "STColor3f.h"
#include "STColor4ub.h"
#include "STImage.h"
#include "Shader.h"
#include "utilities.h"
#include <assert.h>
#include <stdio.h>
#include <string>

RayTracer::RayTracer(void)
    : m_maxLevel(20)
    , m_intensityThreshold(0.001)
{
    pShader = new Shader();
}

RayTracer::~RayTracer()
{
}

//------------------------------------------------
// Main raytracing algorithm
// Cast Ray, Compute Intersections, Shade pixel
//-----------------------------------------------
void RayTracer::Run(Scene* pScene, std::string fName, RenderMode mode, ProjectionType projectionType, int width, int height)
{
    // begin
    std::cout << "Running... " << std::endl;

    // set the shader's render mode
    pShader->SetMode(mode);
    RGBR_f bkground = pScene->GetBackgroundColor();
    STImage* pImg = new STImage(width, height, STImage::Pixel(bkground.r, bkground.b, bkground.g, bkground.a * 255));

    float fov = 45;
    float focalLength = (width / 2) / tan(fov / 2);

    STVector3 U = pScene->GetCamera()->Right();
    STVector3 V = pScene->GetCamera()->Up();
    STVector3 W = pScene->GetCamera()->LookAt();

    STVector3 _camPos = pScene->GetCamera()->Position() + focalLength * W;

    int left = (width) / 2;
    int right = -(width) / 2;
    int bottom = -(height) / 2;
    int top = (height) / 2;

    switch (projectionType) {
    case PARALLEL:
        // loop through the pixels on the image
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                // Calculate the pixels position on the screen/frame
                float u = left + (right - left) * (i + 0.5f) / width;
                float v = bottom + (top - bottom) * (j + 0.5f) / height;
                // Calclate ray parameters
                Ray ray;
                ray.SetOrigin((u * U) + (v * V) + 0); // set the ray origin to the pixel position
                ray.SetDirection(-1.0f * W); // set the ray direction to the negative
                    // of the camera LookAt vector
                ray.Direction().Normalize(); // normalize the ray
                // find the closest intersection
                Intersection* intersection = new Intersection();
                int numInters = pScene->FindClosestIntersection(ray, intersection);
                if (numInters == 0) { // if no intersection is found color the pixel
                    // to the background color
                    RGBR_f bgc = pScene->GetBackgroundColor();
                    // convert the RGBA values to unsigned char and cap them at 255
                    // used 0-255 for RGB and 0.0-1.0 for alpha
                    unsigned char red = std::min(255.0f, bgc.r);
                    unsigned char green = std::min(255.0f, bgc.g);
                    unsigned char blue = std::min(255.0f, bgc.b);
                    unsigned char alpha = std::min(1.0f, bgc.a) * 255;
                    STColor4ub pixelColor = STImage::Pixel(red, green, blue, alpha);
                    pImg->SetPixel(i, j, pixelColor);
                } else { // if an intersection is found, run the shade function to
                    RGBR_f c = Shade(pScene, intersection, 1, RGBR_f(0, 0, 0, 0)); // get the pixel color
                    // convert the RGBA values to unsigned char and cap them at 255
                    // also make sure not to get negative values
                    // used 0-255 for RGB and 0.0-1.0 for alpha
                    unsigned char red = std::min(255.0f, std::max(0.0f, c.r));
                    unsigned char green = std::min(255.0f, std::max(0.0f, c.g));
                    unsigned char blue = std::min(255.0f, std::max(0.0f, c.b));
                    unsigned char alpha = std::min(1.0f, std::max(0.0f, c.a)) * 255;
                    STColor4ub pixelColor = STImage::Pixel(red, green, blue, alpha);
                    pImg->SetPixel(i, j, pixelColor); // color the pixel
                }
            }
        }
        break;
    case PERSPECTIVE:
        // loop through the pixels on the image
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                // Calculate the pixels position on the screen/frame
                float u = left + (right - left) * (i + 0.5f) / width;
                float v = bottom + (top - bottom) * (j + 0.5f) / height;
                STVector3 pixPos = STVector3(u, v, 0);
                // Calclate ray parameters
                Ray ray;
                STVector3 dir = STVector3(
                    pixPos - _camPos); // get the ray direction using the camera
                // position and the pixel position
                dir.Normalize(); // normalize the direciton
                ray.SetOrigin(pScene->GetCamera()->Position());
                // using the camera as the origin
                ray.SetDirection(dir);
                // find the closest intersection
                Intersection* intersection = new Intersection();
                int numInters = pScene->FindClosestIntersection(ray, intersection);
                if (numInters == 0) { // if no intersection is found color the pixel
                    // convert the RGBA values to unsigned char and cap them at 255
                    // used 0-255 for RGB and 0.0-1.0 for alpha
                    RGBR_f bgc = pScene->GetBackgroundColor();
                    unsigned char red = std::min(255.0f, bgc.r);
                    unsigned char green = std::min(255.0f, bgc.g);
                    unsigned char blue = std::min(255.0f, bgc.b);
                    unsigned char alpha = std::min(255.0f, bgc.a) * 255;
                    STColor4ub pixelColor = STImage::Pixel(red, green, blue, alpha);
                    pImg->SetPixel(i, j, pixelColor);
                } else { // if an intersection is found, run the shade function to
                    RGBR_f c = Shade(pScene, intersection, 1, RGBR_f(0, 0, 0, 0)); // get the pixel color
                    // convert the RGBA values to unsigned char and cap them at 255
                    // also make sure not to get negative values
                    // used 0-255 for RGB and 0.0-1.0 for alpha
                    unsigned char red = std::min(255.0f, std::max(0.0f, c.r));
                    unsigned char green = std::min(255.0f, std::max(0.0f, c.g));
                    unsigned char blue = std::min(255.0f, std::max(0.0f, c.b));
                    unsigned char alpha = std::min(1.0f, std::max(0.0f, c.a)) * 255;
                    STColor4ub pixelColor = STImage::Pixel(red, green, blue, alpha);
                    pImg->SetPixel(i, j, pixelColor); // color the pixel
                }
            }
        }
        break;
    default:
        break;
    }
    std::cout << "DONE... " << std::endl;
    pImg->Save(fName);
    std::cout << "saved file " << fName.c_str() << std::endl;
}

// This function computes all of the shading
// Recursively bounce the ray from object to object
// Use the Shader class to compute the final shading
RGBR_f RayTracer::Shade(Scene* pScene, Intersection* pIntersection, int level, RGBR_f finalColor) //added level and finalColor arguments to the Shade function. useful for recursion
{
    bool recurse = false; // used boolean for recursion with MIRROR mode

    // TO DO: Proj2 raytracer
    // Calculate the shading.
    // 1. Bounce the ray from object to object
    // 2. Compute the shading using the functions in the
    //    Shader class, attributes in pIntersection, and information
    //    about your scene
    // 3. Remember to stop the recursion
    // 4. Remember you need to add ambient lighting
    //------------------------------------------------
    // loop through the lights in the scene
    LightList lights = pScene->GetLightList();
    for (size_t i = 0; i < lights.size(); i++) {
        //for every light
        RGBR_f color = pIntersection->surface->GetColor(); //get the color of the currentSurface
        pShader->Run(pScene, pIntersection, &lights.at(i), level, &color, recurse); //run the shaded to update the color which is now passed by reference.
        //store color in finalcolor
        finalColor.r += color.r;
        finalColor.b += color.b;
        finalColor.g += color.g;
        finalColor.a += color.a;
        // if recursion is necessary (i.e. reflective surface)
        if (recurse && level < m_maxLevel) {
            level++; // increment level so recursion is not infinite
            Shade(pScene, pIntersection, level, finalColor); //recurse shade with the new level and color
        }
    }
    //------------------------------------------------------
    // return the color
    return (finalColor);
}

//------------------------------------------------------
// Always render with a minimum color so that the scene
// is not black
//------------------------------------------------------
bool RayTracer::MinimumColor(RGBR_f color)
{
    if ((color.r >= m_intensityThreshold) || (color.g >= m_intensityThreshold) || (color.b >= m_intensityThreshold)) {
        return (true);
    }

    return (false);
}