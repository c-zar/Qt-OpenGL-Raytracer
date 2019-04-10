//----------------------------------------------------------------
// Sphere.cpp
//----------------------------------------------------------------
#define _USE_MATH_DEFINES

#include "cylinder.h"
#include "defs.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string>

// constructor
Cylinder::Cylinder(float x1, float y1, float z1, float x2, float y2, float z2, RGBR_f color, float radius)
    : Surface()
{
    m_start = STVector3(x1, y1, z1);
    m_end = STVector3(x2, y2, z2);
    STVector3 direction(m_start - m_end);
    m_height = direction.Length();
    direction.Normalize();
    m_rotation = STVector3(acosf(direction.x), acosf(direction.y), acosf(direction.z));
    m_color = color;
    m_radius = radius;
    m_transparent = 0;
    reflective = false;
    initVertexArray();
}

Cylinder::Cylinder(float x1, float y1, float z1, float x2, float y2, float z2, RGBR_f color, float radius,
    float transparent)
    : Surface()
{
    m_start = STVector3(x1, y1, z1);
    m_end = STVector3(x2, y2, z2);
    m_color = color;
    m_radius = radius;
    m_transparent = transparent;
    reflective = false;
    initVertexArray();
}

Cylinder::Cylinder(float x1, float y1, float z1, float x2, float y2, float z2, RGBR_f color, float radius,
    bool reflective)
    : Surface()
{
    m_start = STVector3(x1, y1, z1);
    m_end = STVector3(x2, y2, z2);
    m_color = color;
    m_radius = radius;
    reflective = reflective;
    initVertexArray();
}

// clean up here
Cylinder::~Cylinder() {}

//----------------------------------------------------------------------------
// Compute the closest intersection point with the ray
// if it an intersection exist, return true; otherwise false
// return the intersection point information in pIntersection
//-----------------------------------------------------------------------------
// referenced https://stackoverflow.com/questions/4078401/trying-to-optimize-line-vs-cylinder-intersection
bool Cylinder::FindIntersection(Ray ray, Intersection* pIntersection)
{
    //bool bFound = false;

    //// TO DO: Proj2 raytracer
    //// 1. Find intersections with this object along the Ray ray
    //// 2. Store the results of the intersection
    //// 3. if found and return true, otherwise, return false
    //// NOTE: The IntersectionPoint pIntersection should store:
    //// hit point, surface normal, the time t of the ray at the hit point
    //// and the surface being hit
    ////------------------------------------------------

    //// Method 1: From the textbook
    //// First step: find discriminant
    //STVector3 rDir = ray.Direction();
    //STVector3 rOrigin = ray.Origin();
    //STVector3 sCenter = this->m_center;
    //float sRad = this->m_radius;

    ////vector from ray origin to sphere center
    //STVector3 V = rOrigin - sCenter;

    ////ray directions should be normlized so A = Dot(d,d) = 1
    //float A = STVector3::Dot(rDir, rDir);
    //float B = STVector3::Dot(rDir, V);
    //float C = (STVector3::Dot(V, V)) - (sRad * sRad);
    //float Discriminant = (B * B) - (A * C);

    ////If the discriminant is negative, there's no intersection
    //if (Discriminant < 0.0f)
    //    return false;

    ////If the discriminant is positive, there's 2 intersection but we need to find the first one
    //float t1 = (-B + sqrtf(Discriminant)) / (A);
    //float t2 = (-B - sqrtf(Discriminant)) / (A);

    //float time;
    //if (t1 < t2 && t1 > EPSILON) {
    //    time = t1;
    //} else if (t2 > EPSILON) {
    //    time = t2;
    //} else {
    //    return false;
    //}

    //STVector3 iPoint = rOrigin + (time * rDir);
    //STVector3 normal = (iPoint - sCenter);
    //normal.Normalize();

    //pIntersection->point = iPoint;
    //pIntersection->normal = normal;
    //pIntersection->time = time;
    //pIntersection->surface = this;
    //pIntersection->viewDirection = ray.Origin() - iPoint;
    //pIntersection->viewDirection.Normalize();

    //bFound = true;

    //return (bFound);

    STVector3 A = m_start;
    STVector3 B = m_end;
    float r = m_radius;
    STVector3 start = ray.Origin();
    STVector3 dir = ray.Direction();

    float cxmin, cymin, czmin, cxmax, cymax, czmax;
    if (A.z < B.z) {
        czmin = A.z - r;
        czmax = B.z + r;
    } else {
        czmin = B.z - r;
        czmax = A.z + r;
    }
    if (A.y < B.y) {
        cymin = A.y - r;
        cymax = B.y + r;
    } else {
        cymin = B.y - r;
        cymax = A.y + r;
    }
    if (A.x < B.x) {
        cxmin = A.x - r;
        cxmax = B.x + r;
    } else {
        cxmin = B.x - r;
        cxmax = A.x + r;
    }
    //if (optimize) {
    if (start.z >= czmax && (start.z + dir.z) > czmax)
        return false;
    if (start.z <= czmin && (start.z + dir.z) < czmin)
        return false;
    if (start.y >= cymax && (start.y + dir.y) > cymax)
        return false;
    if (start.y <= cymin && (start.y + dir.y) < cymin)
        return false;
    if (start.x >= cxmax && (start.x + dir.x) > cxmax)
        return false;
    if (start.x <= cxmin && (start.x + dir.x) < cxmin)
        return false;
    //}

    STVector3 AB = B - A;
    STVector3 AO = start - A;
    STVector3 AOxAB = STVector3::Cross(AO, AB);
    STVector3 VxAB = STVector3::Cross(dir, AB);
    float ab2 = STVector3::Dot(AB, AB);
    float a = STVector3::Dot(VxAB, VxAB);
    float b = 2 * STVector3::Dot(VxAB, AOxAB);
    float c = STVector3::Dot(AOxAB, AOxAB) - (r * r * ab2);
    float d = b * b - 4 * a * c;
    if (d < 0)
        return false;
    float time = (-b - sqrt(d)) / (2 * a);
    if (time < 0)
        return false;

    STVector3 intersection = start + dir * time; /// intersection point
    STVector3 projection = A + (STVector3::Dot(AB, (intersection - A)) / ab2) * AB; /// intersection projected onto cylinder axis
    if ((projection - A).Length() + (B - projection).Length() > AB.Length())
        return false;

    pIntersection->normal = (intersection - projection);
    pIntersection->normal.Normalize();
    pIntersection->time = time; /// at last

    return true;
}

// referenced http://www.songho.ca/opengl/gl_sphere.html
void Cylinder::initVertexArray()
{
    int numSteps = 20;
    float hl = m_height * 0.5f;
    float a = 0.0f;
    float step = M_PI_2 / (float)numSteps;
    for (int i = 0; i < numSteps; ++i) {
        float x =cosf(a) * m_radius;
        float y = sinf(a) * m_radius;
        vertices[i] = STVector3(x, y, hl);
        vertices[i + numSteps] = STVector3(x, y, -hl);

        a += step;
    }

    vertices[numSteps * 2 + 0] = STVector3(0.0f, 0.0f, +hl);
    vertices[numSteps * 2 + 1] = STVector3(0.0f, 0.0f, -hl);

    for (int i = 0; i < numSteps; ++i) {
        unsigned int i1 = i;
        unsigned int i2 = (i1 + 1) % numSteps;
        unsigned int i3 = i1 + numSteps;
        unsigned int i4 = i2 + numSteps;

        // Sides

        indices[i * 6 + 0] = i1;
        indices[i * 6 + 1] = i3;
        indices[i * 6 + 2] = i2;

        indices[i * 6 + 3] = i4;
        indices[i * 6 + 4] = i2;
        indices[i * 6 + 5] = i3;

        // Caps

        indices[numSteps * 6 + i * 6 + 0] = numSteps * 2 + 0;
        indices[numSteps * 6 + i * 6 + 1] = i1;
        indices[numSteps * 6 + i * 6 + 2] = i2;

        indices[numSteps * 6 + i * 6 + 3] = numSteps * 2 + 1;
        indices[numSteps * 6 + i * 6 + 4] = i4;
        indices[numSteps * 6 + i * 6 + 5] = i3;
    }
}

STVector3 Cylinder::getPos()
{
    return m_center;
}
