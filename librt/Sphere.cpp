//----------------------------------------------------------------
// Sphere.cpp
//----------------------------------------------------------------
#include "Sphere.h"
#include "defs.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string>

// constructor
Sphere::Sphere(float x, float y, float z, RGBR_f color, float radius)
    : Surface()
{
    m_center = STVector3(x, y, z);
    m_color = color;
    m_radius = radius;
    m_transparent = 0;
    reflective = false;
}

Sphere::Sphere(float x, float y, float z, RGBR_f color, float radius,
    float transparent)
    : Surface()
{
    m_center = STVector3(x, y, z);
    m_color = color;
    m_radius = radius;
    m_transparent = transparent;
    reflective = false;
}

Sphere::Sphere(float x, float y, float z, RGBR_f color, float radius,
    bool reflective)
    : Surface()
{
    m_center = STVector3(x, y, z);
    m_color = color;
    m_radius = radius;
    reflective = reflective;
}

// clean up here
Sphere::~Sphere() {}

bool Sphere::onSphere(STVector3 point)
{
    float dist = (point - this->m_center).Length();
    return dist < (this->m_radius * this->m_radius);
}

//----------------------------------------------------------------------------
// Compute the closest intersection point with the ray
// if it an intersection exist, return true; otherwise false
// return the intersection point information in pIntersection
//-----------------------------------------------------------------------------

bool Sphere::FindIntersection(Ray ray, Intersection* pIntersection)
{
    bool bFound = false;

    // TO DO: Proj2 raytracer
    // 1. Find intersections with this object along the Ray ray
    // 2. Store the results of the intersection
    // 3. if found and return true, otherwise, return false
    // NOTE: The IntersectionPoint pIntersection should store:
    // hit point, surface normal, the time t of the ray at the hit point
    // and the surface being hit
    //------------------------------------------------

    // Method 1: From the textbook
    // First step: find discriminant
    STVector3 rDir = ray.Direction();
    STVector3 rOrigin = ray.Origin();
    STVector3 sCenter = this->m_center;
    float sRad = this->m_radius;

    //vector from ray origin to sphere center
    STVector3 V = rOrigin - sCenter;

    //ray directions should be normlized so A = Dot(d,d) = 1
    float A = STVector3::Dot(rDir, rDir);
    float B = STVector3::Dot(rDir, V);
    float C = (STVector3::Dot(V, V)) - (sRad * sRad);
    float Discriminant = (B * B) - (A * C);

    //If the discriminant is negative, there's no intersection
    if (Discriminant < 0.0f)
        return false;

    //If the discriminant is positive, there's 2 intersection but we need to find the first one
    float t1 = (-B + sqrtf(Discriminant)) / (A);
    float t2 = (-B - sqrtf(Discriminant)) / (A);

    float time;
    if (t1 < t2 && t1 > EPSILON) {
        time = t1;
    } else if (t2 > EPSILON) {
        time = t2;
    } else {
        return false;
    }

    STVector3 iPoint = rOrigin + (time * rDir);
    STVector3 normal = (iPoint - sCenter);
    normal.Normalize();

    pIntersection->point = iPoint;
    pIntersection->normal = normal;
    pIntersection->time = time;
    pIntersection->surface = this;
    pIntersection->viewDirection = ray.Origin() - iPoint;
    pIntersection->viewDirection.Normalize();

    bFound = true;

    return (bFound);
}


// Compare sphere
bool Sphere::CompareTo(Sphere sphere)
{
    // If spheres share the same center cooridnates and radius
    // We consider the the same
    return (this->m_center.x == sphere.m_center.x && this->m_center.y == sphere.m_center.y && this->m_center.z == sphere.m_center.z && this->m_radius == sphere.m_radius);
}
