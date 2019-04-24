//------------------------------------------------------------------------------------------------
// Corey Toler-Franklin
// 10 February 2006
// Copyright 2006
//
// Shader.cpp
// Shader class - computes shading functions
//------------------------------------------------------------------------------------------------

#include "Shader.h"
#include "Intersection.h"
#include "Light.h"
#include <algorithm>
#include <assert.h>

Shader::Shader(void)
    : m_mode(LAMBERTIAN)
{
}

void Shader::SetMode(RenderMode mode)
{
    m_mode = mode;
}

// Runs the shader according to the specified render mode
// added color and recurse arguments. used for recursion. color now passed by reference and updates that way
void Shader::Run(Scene* pScene, Intersection* pIntersection, Light* light, int level, RGBR_f* color, bool& recurse)
{
    switch (m_mode) {
    case LAMBERTIAN:
        Lambertian(pIntersection, light, color);
        break;
    case PHONG:
        Phong(pScene, pIntersection, light, color);
        break;
    case SHADOWS:
        ShadowEffect(pScene, pIntersection, light, color);
        break;
    case MIRROR:
        MirrorEffect(pScene, pIntersection, light, level, color, recurse);
        break;
    case TRANSPARENCY:
        MakeTransparent(pScene, pIntersection, light, color);
        break;
    case REFRACT:
        Refraction(pScene, pIntersection, light, color);
        break;
    default:
        Lambertian(pIntersection, light, color);
        break;
    }
}

void limitColor(RGBR_f* color, RGBR_f limit)
{
    color->r = std::min(limit.r, color->r);
    color->g = std::min(limit.g, color->g);
    color->b = std::min(limit.b, color->b);
}

// add AmbientLight to the pixel also making sure the r,g,b to resolve artifacts
void Shader::addAmbientLight(Intersection* pIntersection, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    // add ambient lighting
    //-----------------------------------------------------------------------
    //adds the color intensity multiplied by the 'strength' so they don't just turn whitish
    float ambientStrength = 25;
    //cap the color values to 255
    color->r = std::min(color->r + color->r / 255 * ambientStrength, 255.0f);
    color->g = std::min(color->g + color->g / 255 * ambientStrength, 255.0f);
    color->b = std::min(color->b + color->b / 255 * ambientStrength, 255.0f);
    //----------------------------------------
}

// Implements diffuse shading using the lambertian lighting model
void Shader::Lambertian(Intersection* pIntersection, Light* light, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    //         - Add shading lambertian shading.
    // 1. Lambertian shading is the dot product of the the
    //    normal and light direction
    // 2. Do not forget the multiply your albedo by the result
    //----------------------------------------------------------------
    assert(pIntersection);
    assert(light);
    STVector3 lightV = light->GetPosition() - pIntersection->point; // gets the direction to the light from the point on the surface
    float lightIntensity = light->GetColor().a / lightV.LengthSq(); // calculate light intensity using the alpha channel and distance
    lightV.Normalize(); // normalize the light direciton vector
    // calculate the lambertian value and set the colors using the value
    // Reference: Fundamentals of Computer Graphics, chapter 4
    // Reference: powerpoint - "Ray Tracing"
    // Reference: https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/diffuse-lambertian-shading for albedo
    float lambert = std::max(0.0f, STVector3::Dot(pIntersection->normal, lightV));
    color->r = (lambert * lightIntensity * light->GetColor().r * color->r);
    color->g = (lambert * lightIntensity * light->GetColor().g * color->g);
    color->b = (lambert * lightIntensity * light->GetColor().b * color->b);
    addAmbientLight(pIntersection, color); // add ambient light at the end
    limitColor(color, pIntersection->surface->GetColor());
    //-------------------------------------------------------------
}

// Implements diffuse shading using the lambertian lighting model
// Phong (NOT Bling-Phong)
void Shader::Phong(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color)
{
    //need to pass in the viewPoint

    assert(pIntersection);
    assert(light);

    // TO DO: Proj2 raytracer
    // Add Phong shading.
    // 1. Implement the phong shading equation here
    // 2. Remember to add any attributes you might need for shading to
    //    your surface objects as they are passed in with the pIntersection
    //---------------------------------------------------------
    STVector3 lightV = light->GetPosition() - pIntersection->point; //direction of vector from point to light
    float lightIntensity = light->GetColor().a / lightV.LengthSq(); // calculate light intensity using the alpha channel and distance
    lightV.Normalize(); //normalize to just get direction components
    float p = 24; // the exponential

    // calculate the reflect vector using the light direction
    // Reference: Fundamentals of Computer Graphics, chapter 4
    // Reference: powerpoint - "Ray Tracing"
    STVector3 r = 2 * (STVector3::Dot(pIntersection->normal, lightV), pIntersection->normal) - lightV;
    r.Normalize();

    float diffuse = std::max(0.0f, STVector3::Dot(pIntersection->normal, lightV)); // get the diffuse factor using same method as lambertian
    float phong = powf(std::max(0.0f, STVector3::Dot(pIntersection->viewDirection, r)), p); // calculate the phong factor from the reflect and view direction vectors

    // used the book and slides for reference for equation
    color->r = lightIntensity * light->GetColor().r * ((diffuse * color->r) + (phong * light->GetColor().r));
    color->g = lightIntensity * light->GetColor().g * ((diffuse * color->g) + (phong * light->GetColor().g));
    color->b = lightIntensity * light->GetColor().b * ((diffuse * color->b) + (phong * light->GetColor().b));
    addAmbientLight(pIntersection, color); // add ambient light at the end
    //---------------------------------------------------------
}

// shadow effects - you should use multiple lights to soften shadows
void Shader::ShadowEffect(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    // shadow effects - include results with multiple lights to soften shadows
    //--------------------------------------------------------------------

    Lambertian(pIntersection, light, color); // apply diffuse shading using lambertian
    assert(pIntersection);
    assert(light);

    //calculate light direction and normalize
    STVector3 lightV = light->GetPosition() - pIntersection->point;
    lightV.Normalize();

    // get the intersection point and offset towards light direction to prevent intersection with itself
    STVector3 point = pIntersection->point;
    point += (0.001f * lightV);

    // initialize a ray and temporary intersection. used to calculate intersection
    Ray ray;
    Intersection temp;
    ray.SetOrigin(point);
    ray.SetDirection(lightV);

    // if there is an intersection dim the colors based on shadow/shading contribution
    // Reference: powerpoint - "Ray Tracing Part 1."
    if (pScene->FindIntersection(ray, &temp)) {
        float shadowContribution = 0.3;
        color->r *= shadowContribution;
        color->g *= shadowContribution;
        color->b *= shadowContribution;
    }
    limitColor(color, pIntersection->surface->GetColor());
    //----------------------------------------------------------------
}

// Mirror reflection
void Shader::MirrorEffect(Scene* pScene, Intersection* pIntersection, Light* light, int level, RGBR_f* color, bool& recurse)
{
    // TO DO: Proj2 raytracer
    // Computes mirror reflections
    //--------------------------------------------------------------------
    Lambertian(pIntersection, light, color); // apply shading using lambertian
    //Phong(pScene, pIntersection, light, color); // apply shading using phong

    // calculate reflect vector using view direction and surface normal
    // Reference: Fundamentals of Computer Graphics, chapter 4
    // Referece: powerpoint - "Ray Tracing Part 1."
    STVector3 r = 2 * STVector3::Dot(pIntersection->normal, pIntersection->viewDirection) * pIntersection->normal - pIntersection->viewDirection;
    r.Normalize();
    float strength = 3 * std::max(0.0f, STVector3::Dot(pIntersection->normal, r));

    STVector3 point = pIntersection->point;
    point += (0.1f * r);

    // initialize a ray from the intersection point toward the reflection to find an intersection
    Ray ray;
    ray.SetOrigin(point);
    ray.SetDirection(r);

    // check for intersection and recurse if found
    if (pIntersection->surface->IsReflective()) {
        // divide the colors by the level as more reflection means more light/color loss
        color->r *= strength / level;
        color->g *= strength / level;
        color->b *= strength / level;
        recurse = pScene->FindIntersection(ray, pIntersection) > 0;
    }
    //---------------------------------------------------------------------
}

// Apply transparency effects
void Shader::MakeTransparent(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    // Applies transparency
    //------------------------------------------------------------------------------
    Lambertian(pIntersection, light, color); // applies diffuse shading using lambertian
    RGBR_f backgroundC = pScene->GetBackgroundColor();
    if (pIntersection->surface->IsTransparent()) {
        float trans = pIntersection->surface->GetTranspValue(); // transparent value of the surface. a float from 0.0-1.0.

        // make a temporary ray and intersection. used to find a surface behind the current surface
        Intersection temp = *pIntersection;
        Ray ray;
        STVector3 rayDir = -1.0f * pIntersection->viewDirection;
        STVector3 point = pIntersection->point;
        point += (0.1f * rayDir); // offset the interstions so it doesn't intesect itself
        ray.SetOrigin(point);
        ray.SetDirection(rayDir);
        ray.Direction().Normalize();

        if (pScene->FindIntersection(ray, &temp)) { // if intersection is found, calculate color
            RGBR_f tempColor = temp.surface->GetColor(); // make a temporary RGBR_f to get the color of the surface
            MakeTransparent(pScene, &temp, light, &tempColor); // apply lambertian to the temporary color to get the correct values
            // calculate the final color using the current surface color and the intersected surface color
            if (color->g > 0.1f) {
                int x = 0;
            }
            color->r = color->r * (trans) + tempColor.r * (1.0f - trans);
            color->b = color->b * (trans) + tempColor.b * (1.0f - trans);
            color->g = color->g * (trans) + tempColor.g * (1.0f - trans);
        } else {
            // if no intersection
            // calculate the final color using the current surface color and the background color
            color->r = color->r * (trans) + backgroundC.r * (1.0f - trans);
            color->b = color->b * (trans) + backgroundC.b * (1.0f - trans);
            color->g = color->g * (trans) + backgroundC.g * (1.0f - trans);
            return;
        }
    }
    //-------------------------------------------------------------------------------
}

// referenced: https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/reflection-refraction-fresnel
void Shader::Refraction(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    // Computes mirror reflections
    //--------------------------------------------------------------------
    Lambertian(pIntersection, light, color); // apply shading using lambertian
    //Phong(pScene, pIntersection, light, color); // apply shading using phong

    // calculate reflect vector using view direction and surface normal
    // Reference: Fundamentals of Computer Graphics, chapter 4
    // Referece: powerpoint - "Ray Tracing Part 1."
    STVector3 I = -pIntersection->viewDirection;
    float cosTheta = STVector3::Dot(pIntersection->normal, I);
    float sIndex = 1;
    float eIndex = REFRACT_INDEX_GLASS;
    STVector3 n = pIntersection->normal;
    if (cosTheta < 0) {
        cosTheta = -cosTheta;
    } else {
        std::swap(sIndex, eIndex);
        n = -pIntersection->normal;
    }
    float index = sIndex / eIndex;
    float k = 1 - index * index * (1 - cosTheta * cosTheta);
    STVector3 refracted = (k < 0 ? STVector3::Zero : index * I + (index * cosTheta - sqrtf(k)) * n);

    STVector3 point = pIntersection->point;
    point += (0.1f * refracted);

    // initialize a ray from the intersection point toward the reflection to find an intersection
    Ray ray;
    ray.SetOrigin(point);
    ray.SetDirection(refracted);
    Intersection temp;

    if (pIntersection->surface->IsReflective()) {
        if (pScene->FindIntersection(ray, &temp) > 0) {
            RGBR_f color2 = temp.surface->GetColor();
            Lambertian(&temp, light, &color2);

            color->r = color->r * .1 + color2.r * .95;
            color->g = color->g * .1 + color2.g * .95;
            color->b = color->b * .1 + color2.b * .95;
        } else {
            color->r = color->r * .1 + pScene->GetBackgroundColor().r * .95;
            color->g = color->g * .1 + pScene->GetBackgroundColor().g * .95;
            color->b = color->b * .1 + pScene->GetBackgroundColor().b * .95;
        }
    }
    limitColor(color, pIntersection->surface->GetColor());
}

Shader::~Shader()
{
}
