//------------------------------------------------------------------------------
// Copyright 2015 Corey Toler-Franklin, University of Florida
// RayTracer.h
// Shades the objects in the scene based on information gathered by bouncing
// a ray in the scene and computing ray/surface intersections
//------------------------------------------------------------------------------

#ifndef __RAYTRACER_H__
#define __RAYTRACER_H__

#include "RGBR_f.h"
#include "Scene.h"
#include "defs.h"
#include <string>

class Shader;
class Camera;
class Light;

class RayTracer {

public:
    RayTracer(void);
    ~RayTracer(void);

    void Run(Scene* pScene, std::string fName, RenderMode mode, ProjectionType projectionType, int width, int height);

private:
    Shader* pShader;
    RenderMode renderMode;

    int m_maxLevel;
    float m_intensityThreshold;

    bool MinimumColor(RGBR_f color);

    RGBR_f Shade(Scene* pScene, Intersection* pIntersection, int level, RGBR_f finalColor);
};

#endif //__RAYTRACER_H__
