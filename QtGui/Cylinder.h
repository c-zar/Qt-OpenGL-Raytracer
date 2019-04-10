//------------------------------------------------------------------------------
// Copyright 2015 Corey Toler-Franklin, University of Florida
// Sphere.h
// Sphere surface object
//------------------------------------------------------------------------------

#pragma once

#include "Intersection.h"
#include "Ray.h"
#include "Surface.h"
#include <math.h>

class Cylinder : public Surface {

public:
    Cylinder(float x1, float y1, float z1, float x2, float y2, float z2, RGBR_f color, float radius);
    Cylinder(float x1, float y1, float z1, float x2, float y2, float z2, RGBR_f color, float radius, float transparent);
    Cylinder(float x1, float y1, float z1, float x2, float y2, float z2, RGBR_f color, float radius, bool reflective);
    ~Cylinder(void);

    bool FindIntersection(Ray ray, Intersection* pIntersection); // find ray sphere intersections

    STVector3 getPos();

    std::vector<STVector3> vertices;
    std::vector<float> normals;
    std::vector<float> texCoords;
    std::vector<unsigned int> indices;

    float m_radius;
    STVector3 m_rotation;
    STVector3 m_start;
    STVector3 m_end;   
    float m_height;

private:
    void initVertexArray();
};
