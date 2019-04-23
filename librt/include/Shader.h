//------------------------------------------------------------------------------------------------
// Corey Toler-Franklin
// 10 February 2006
// Copyright 2006
//
// Shader.h
// Computes Shading
// RenderMode mode determines the type of shading algorithm used
// Given a normal, light direction, color and other shading input
//------------------------------------------------------------------------------------------------

#ifndef _SHADER_H
#define _SHADER_H

#include "STColor4f.h"
#include "STVector3.h"
#include "Scene.h"
#include "Sphere.h"
#include "Surface.h"
#include "defs.h"

class Intersection;
class Light;

class Shader {

public:
    Shader(void);
    ~Shader(void);

    void SetMode(RenderMode mode);
    void Run(Scene* pScene, Intersection* pIntersection, Light* light, int level, RGBR_f* color, bool& recurse);

    void addAmbientLight(Intersection* pIntersection, RGBR_f* color);

private:
    RenderMode m_mode; // The current shading mode - Lambertian, Phong or other method

    void Lambertian(Intersection* pIntersection, Light* light, RGBR_f* color);
    void Phong(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color);
    void ShadowEffect(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color);
    void MirrorEffect(Scene* pScene, Intersection* pIntersection, Light* light, int level, RGBR_f* color, bool& recurse);
    void MakeTransparent(Scene* pScene, Intersection* pIntersection, Light* light, RGBR_f* color);
};

#endif //_RAY_H