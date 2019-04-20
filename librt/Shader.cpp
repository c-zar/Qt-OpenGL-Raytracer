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
void Shader::Run(Scene* pScene, Intersection* pIntersection, Light* light, int level, RGBR_f* color)
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
        MirrorEffect(pScene, pIntersection, light, level, color);
        break;
    case TRANSPARENCY:
        MakeTransparent(pScene, pIntersection, light, color);
        break;
    default:
        Lambertian(pIntersection, light, color);
        break;
    }
}

// add AmbientLight to the pixel also making sure the r,g,b to resolve artifacts
void Shader::addAmbientLight(Intersection* pIntersection, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    // add ambient lighting
    //-----------------------------------------------------------------------
    float ambientStrength = 25;
    color->r = std::min(color->r + ambientStrength, 255.0f);
    color->g = std::min(color->g + ambientStrength, 255.0f);
    color->b = std::min(color->b + ambientStrength, 255.0f);
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
    addAmbientLight(pIntersection, color);
    STVector3 lightOrigin = light->GetPosition();
    STVector3 lightV = lightOrigin - pIntersection->point;
    float distance = lightV.Length();
    lightV.Normalize();
    float albedo = 0.2;
    float lightIntensity = light->GetColor().a / distance;
    float lambert = std::max(0.0f, STVector3::Dot(pIntersection->normal, lightV));
    color->r = (lambert * lightIntensity * light->GetColor().r * color->r * albedo);
    color->g = (lambert * lightIntensity * light->GetColor().g * color->g * albedo);
    color->b = (lambert * lightIntensity * light->GetColor().b * color->b * albedo);
    //-------------------------------------------------------------
}

// Implements diffuse shading using the lambertian lighting model
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
    STVector3 lightOrigin = light->GetPosition();
    STVector3 lightV = lightOrigin - pIntersection->point;
    float distance = lightV.Length();
    lightV.Normalize();
    addAmbientLight(pIntersection, color);
    float p = 100; // the exponential
    STVector3 r = 2 * (STVector3::Dot(pIntersection->normal, lightV), pIntersection->normal) - lightV;
    r.Normalize();
    float diffuse = std::max(0.0f, STVector3::Dot(pIntersection->normal, lightV));
    float albedo = 0.2;
    float lightIntensity = light->GetColor().a / distance;
    float phong = powf(std::max(0.0f, STVector3::Dot(pIntersection->viewDirection, r)), p);
    color->r = lightIntensity * light->GetColor().r * albedo * ((diffuse * color->r) + (phong * light->GetColor().r));
    color->g = lightIntensity * light->GetColor().g * albedo * ((diffuse * color->g) + (phong * light->GetColor().g));
    color->b = lightIntensity * light->GetColor().b * albedo * ((diffuse * color->b) + (phong * light->GetColor().b));

    /*color->r = color->r * diffuse + phong * light->GetColor().r;
    color->g = color->g * diffuse + phong * light->GetColor().g;
    color->b = color->b * diffuse + phong * light->GetColor().b;*/

    //---------------------------------------------------------
}

// shadow effects - you should use multiple lights to soften shadows
void Shader::ShadowEffect(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    // shadow effects - include results with multiple lights to soften shadows
    //--------------------------------------------------------------------
    Lambertian(pIntersection, light, color);
    STVector3 lightDirection = light->GetPosition();
    STVector3 lightV = lightDirection - pIntersection->point;
    lightV.Normalize();
    STVector3 point = pIntersection->point;
    point += (0.1f * lightV);
    Ray ray;
    Intersection temp;
    ray.SetOrigin(point);
    ray.SetDirection(lightV);
    ray.Direction().Normalize();
    if (pScene->FindIntersection(ray, &temp)) {
        color->r *= 0.7;
        color->g *= 0.7;
        color->b *= 0.7;
    }
    //----------------------------------------------------------------
}

// Mirror reflection
void Shader::MirrorEffect(Scene* pScene, Intersection* pIntersection, Light* light, int level, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    // Computes mirror reflections
    //--------------------------------------------------------------------
    Lambertian(pIntersection, light, color); // apply shading using lambertian
    //Phong(pScene, pIntersection, light, color);
    STVector3 r = 2 * STVector3::Dot(pIntersection->normal, pIntersection->viewDirection) * pIntersection->normal - pIntersection->viewDirection;
    float strength = std::max(0.0f, STVector3::Dot(pIntersection->viewDirection, r));
    if (pIntersection->surface->IsReflective()) {
        color->r /= level;
        color->g /= level;
        color->b /= level;
    }
    color->r /= strength;
    color->g /= strength;
    color->b /= strength;
    //---------------------------------------------------------------------
}

// Apply transparency effects
void Shader::MakeTransparent(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color)
{
    // TO DO: Proj2 raytracer
    // Applies transparency
    //------------------------------------------------------------------------------
    Intersection temp = *pIntersection;
    RGBR_f backgroundC = pScene->GetBackgroundColor();
    RGBR_f tempColor = *color;
    if (temp.surface->IsTransparent()) {
        float trans = temp.surface->GetTranspValue();
        STVector3 rayDir = -1.0f * temp.viewDirection;
        STVector3 point = temp.point;
        point += (0.1f * rayDir);
        Ray ray;
        ray.SetOrigin(point);
        ray.SetDirection(rayDir);
        ray.Direction().Normalize();
        if (pScene->FindIntersection(ray, &temp)) {
            color->r = color->r * trans + temp.surface->GetColor().r * (1 - trans);
            color->g = color->b * trans + temp.surface->GetColor().b * (1 - trans);
            color->b = color->g * trans + temp.surface->GetColor().g * (1 - trans);
        } else {
            color->r = color->r * trans + backgroundC.r * (1 - trans);
            color->g = color->b * trans + backgroundC.b * (1 - trans);
            color->b = color->g * trans + backgroundC.g * (1 - trans);
            return;
        }
    }
    //-------------------------------------------------------------------------------
}

Shader::~Shader()
{
}
