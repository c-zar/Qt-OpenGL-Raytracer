//------------------------------------------------------------------------------
// Copyright 2015 Corey Toler-Franklin, University of Florida
// Sphere.h
// Sphere surface object
//------------------------------------------------------------------------------

#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Intersection.h"
#include "Ray.h"
#include "Surface.h"
#include <math.h>

class Sphere : public Surface {

public:
    Sphere(float x, float y, float z, RGBR_f color, float radius);
    Sphere(float x, float y, float z, RGBR_f color, float radius, float transparent);
    Sphere(float x, float y, float z, RGBR_f color, float radius, bool reflective, float transparent);
    ~Sphere(void);

    bool onSphere(STVector3 point);

    bool FindIntersection(Ray ray, Intersection* pIntersection); // find ray sphere intersections
    bool CompareTo(Sphere sphere); // compare shere objects
    STVector3 getPos();

    std::vector<STVector3> vertices;
    std::vector<STVector3> normals;
    std::vector<float> texCoords;
    std::vector<unsigned int> indices;

    float m_radius;

private:

    void initVertexArray();
};

#endif //__SPHERE_H__
