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
    renderMode = mode;
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
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                float u = left + (right - left) * (i + 0.5f) / width;
                float v = bottom + (top - bottom) * (j + 0.5f) / height;
                Ray ray;
                ray.SetOrigin((u * U) + (v * V) + 0);
                ray.SetDirection(-1.0f * W);
                ray.Direction().Normalize();
                Intersection* intersection = new Intersection();
                int numInters = pScene->FindClosestIntersection(ray, intersection);
                if (numInters == 0) {
                    RGBR_f bgc = pScene->GetBackgroundColor();
                    unsigned char red = std::min(255.0f, bgc.r);
                    unsigned char green = std::min(255.0f, bgc.g);
                    unsigned char blue = std::min(255.0f, bgc.b);
                    unsigned char alpha = std::min(255.0f, bgc.a) * 255;
                    STColor4ub pixelColor = STImage::Pixel(red, green, blue, alpha);
                    pImg->SetPixel(i, j, pixelColor);
                } else {
                    RGBR_f c = Shade(pScene, intersection, 1, RGBR_f(0, 0, 0, 0));
                    unsigned char red = std::min(255.0f, std::max(0.0f, c.r));
                    unsigned char green = std::min(255.0f, std::max(0.0f, c.g));
                    unsigned char blue = std::min(255.0f, std::max(0.0f, c.b));
                    unsigned char alpha = std::min(1.0f, std::max(0.0f, c.a)) * 255;
                    STColor4ub pixelColor = STImage::Pixel(red, green, blue, alpha);
                    pImg->SetPixel(i, j, pixelColor);
                }
            }
        }
        break;
    case PERSPECTIVE:
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                Ray ray;
                float u = left + (right - left) * (i + 0.5f) / width;
                float v = bottom + (top - bottom) * (j + 0.5f) / height;
                STVector3 pixPos = STVector3(u, v, 0);
                STVector3 dir = STVector3(pixPos - _camPos);
                dir.Normalize();
                ray.SetOrigin(pScene->GetCamera()->Position());
                ray.SetDirection(dir);
                Intersection* intersection = new Intersection();
                int numInters = pScene->FindClosestIntersection(ray, intersection);
                if (numInters == 0) {
                    RGBR_f bgc = pScene->GetBackgroundColor();
                    unsigned char red = std::min(255.0f, bgc.r);
                    unsigned char green = std::min(255.0f, bgc.g);
                    unsigned char blue = std::min(255.0f, bgc.b);
                    unsigned char alpha = std::min(255.0f, bgc.a) * 255;
                    STColor4ub pixelColor = STImage::Pixel(red, green, blue, alpha);
                    pImg->SetPixel(i, j, pixelColor);
                } else {
                    RGBR_f c = Shade(pScene, intersection, 1, RGBR_f(0, 0, 0, 0));
                    unsigned char red = std::min(255.0f, std::max(0.0f, c.r));
                    unsigned char green = std::min(255.0f, std::max(0.0f, c.g));
                    unsigned char blue = std::min(255.0f, std::max(0.0f, c.b));
                    unsigned char alpha = std::min(1.0f, std::max(0.0f, c.a)) * 255;
                    STColor4ub pixelColor = STImage::Pixel(red, green, blue, alpha);
                    pImg->SetPixel(i, j, pixelColor);
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
RGBR_f RayTracer::Shade(Scene* pScene, Intersection* pIntersection, int level, RGBR_f finalColor)
{
    int currlevel = level;
    Intersection* currIntersection = pIntersection;

    // TO DO: Proj2 raytracer
    // Calculate the shading.
    // 1. Bounce the ray from object to object
    // 2. Compute the shading using the functions in the
    //    Shader class, attributes in pIntersection, and information
    //    about your scene
    // 3. Remember to stop the recursion
    // 4. Remember you need to add ambient lighting
    //------------------------------------------------
    LightList lights = pScene->GetLightList();
    for (size_t i = 0; i < lights.size(); i++) {
        RGBR_f color = pIntersection->surface->GetColor();
        pShader->Run(pScene, pIntersection, &lights.at(i), level, &color);
        finalColor.r += color.r;
        finalColor.b += color.b;
        finalColor.g += color.g;
        finalColor.a += color.a;

        if (pIntersection->surface->IsReflective() && currlevel < m_maxLevel && renderMode == MIRROR) {
            currlevel++;
            STVector3 r = 2 * STVector3::Dot(pIntersection->normal, pIntersection->viewDirection) * pIntersection->normal - pIntersection->viewDirection;
            r.Normalize();
            Ray ray;
            ray.SetOrigin(pIntersection->point);
            ray.SetDirection(r);
            if (pScene->FindIntersection(ray, pIntersection)) {
                Shade(pScene, pIntersection, currlevel, finalColor);
            }
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
