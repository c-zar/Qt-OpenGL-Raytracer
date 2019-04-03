//----------------------------------------------------------------
// Triangle.cpp
// Copyright: Corey Toler-Franklin, University of Florida
//
// Triangle surface class
// This class is represented by the surface enclosed by 3 points:m_a, m_b, m_c
//----------------------------------------------------------------
#include "Triangle.h"
#include "LinearSolver.h"
#include "defs.h"

// contructor
Triangle::Triangle(STVector3 a, STVector3 b, STVector3 c, RGBR_f color)
    : Surface()
{
    m_a = a;
    m_b = b;
    m_c = c;
    m_color = color;
    m_transparent = 0;
    reflective = false;
    initVertexBuffer();
}

Triangle::Triangle(STVector3 a, STVector3 b, STVector3 c, RGBR_f color, float transparent)
    : Surface()
{
    m_a = a;
    m_b = b;
    m_c = c;
    m_color = color;
    m_transparent = transparent;
    reflective = false;
    initVertexBuffer();
}

Triangle::Triangle(STVector3 a, STVector3 b, STVector3 c, RGBR_f color, bool reflective)
    : Surface()
{
    m_a = a;
    m_b = b;
    m_c = c;
    m_color = color;
    reflective = reflective;
    initVertexBuffer();
}

// clean up
Triangle::~Triangle()
{
}

STVector3* Triangle::getVertices()
{
    STVector3 verts[3];
    verts[0] = this->m_a;
    verts[1] = this->m_b;
    verts[2] = this->m_c;
    return verts;
}

void Triangle::initVertexBuffer()
{
    vertexBuffer[0] = m_a.x;
    vertexBuffer[1] = m_a.y;
    vertexBuffer[2] = m_a.z;

    vertexBuffer[3] = m_b.x;
    vertexBuffer[4] = m_b.y;
    vertexBuffer[5] = m_b.z;

    vertexBuffer[6] = m_c.x;
    vertexBuffer[7] = m_c.y;
    vertexBuffer[8] = m_c.z;
}

//-----------------------------------------------------------------
// Uses barycentric coordinates to solve for the interscetion
// of the Ray ray with the surface in the plane of A, B, C
// Updates the variables u, v, and w with the solution if found
// Returns true if found, otherwise false
//-----------------------------------------------------------------
bool Triangle::IntersectionSolver(Ray ray, STVector3 A, STVector3 B, STVector3 C,
    double& beta, double& gamma, double& t)
{
    LinearSolver L;
    // TO DO: Proj2 raytracer
    //          - Solve for intersections.
    // 1. Use barycentric coordinates and linear equations to solve for intersections
    // 2. If a solution is found return true, otherwise, return false
    // 3. If a solution is found, t, beta and gamma are updated; otherwise they are useless
    //------------------------------------------------
    float xE = ray.Origin().x;
    float yE = ray.Origin().y;
    float zE = ray.Origin().z;

    float xD = ray.Direction().x;
    float yD = ray.Direction().y;
    float zD = ray.Direction().z;

    float xA = A.x;
    float yA = A.y;
    float zA = A.z;

    float xB = B.x;
    float yB = B.y;
    float zB = B.z;

    float xC = C.x;
    float yC = C.y;
    float zC = C.z;
    /*
           Du + Ev + Fw + G = 0
           Hu + Iv + Jw + K = 0
           Lu + Mv + Nw + P = 0
    double D, double E, double F, double G,
    double H, double I, double J, double K,
    double L, double M, double N, double P,
    double &u, double &v, double& w*/
    if (L.Run_method3(
            xA - xB, xA - xC, xD, xE - xA,
            yA - yB, yA - yC, yD, yE - yA,
            zA - zB, zA - zC, zD, zE - zA,
            beta, gamma, t)) {
        if (t < EPSILON) {
            return false;
        }
    } else {
        return false;
    }

    //------------------------------------------------------

    return true;
}

//Method Working: http://www.lighthouse3d.com/tutorials/maths/ray-triangle-intersection/
//bool Triangle::IntersectionSolver(Ray ray, STVector3 A, STVector3 B, STVector3 C,
//    double& beta, double& gamma, double& t)
//{
//    STVector3 p = ray.Origin();
//    STVector3 d = ray.Direction();
//
//    STVector3 v0 = this->m_a;
//    STVector3 v1 = this->m_b;
//    STVector3 v2 = this->m_c;
//
//    STVector3 e1 = v1 - v0;
//    STVector3 e2 = v2 - v0;
//
//    STVector3 h = STVector3::Cross(d, e2);
//    float a = STVector3::Dot(e1, h);
//
//    //since we're working with floating points, we're gonna have to round for 0
//    if (a > -Tol && a < Tol)
//        return (false);
//
//    float f = 1 / a;
//    STVector3 s = (p - v0);
//    float u = f * STVector3::Dot(s, h);
//    if (u < 0.0f || u > 1.0f)
//        return (false);
//
//    STVector3 q = STVector3::Cross(s, e1);
//    float v = f * STVector3::Dot(d, q);
//    if (v < 0.0f || u + v > 1.0f)
//        return (false);
//
//    t = f * STVector3::Dot(e2, q);
//    if (t > Tol) {
//        return true;
//    } else {
//        return false;
//    }
//}

//----------------------------------------------------------------------------
// Compute the closest intersection point with the ray
// If an intersection exist, return true; otherwise false
// return the intersection point information in pIntersection
//-----------------------------------------------------------------------------
bool Triangle::FindIntersection(Ray ray, Intersection* pIntersection)
{
    bool bFound = false;

    // TO DO: Proj2 raytracer
    //          - Find Intersections.
    // 1. Find intersections with this object along the Ray ray
    //    Use barycentric coordinates and linear equations
    // 2. Store the results of the intersection
    // 3. If found return true, otherwise, return false
    // NOTE: The Intersection pIntersection should store:
    // hit point, surface normal, the time t of the ray at the hit point
    // and the surface being hit
    //------------------------------------------------------

    //Method 2: using linearSolver and the book
    double beta = 0;
    double gamma = 0;
    double time = 0;

    if (IntersectionSolver(ray, this->m_a, this->m_b, this->m_c, beta, gamma, time)) {

        if (beta < 0.0)
            return false;
        if (gamma < 0.0)
            return false;
        if ((beta + gamma) > 1.0f)
            return false;

        pIntersection->point = ray.Origin() + (time * ray.Direction());
        pIntersection->time = time;
        pIntersection->normal = ComputeNormalVector();
        pIntersection->surface = this;
        pIntersection->viewDirection = ray.Origin() - pIntersection->point;
        pIntersection->viewDirection.Normalize();

        bFound = true;
    }
    ////------------------------------------------------------

    return (bFound);
}

//-------------------------------------------------
// Computes the normal vector
//-------------------------------------------------
STVector3 Triangle::ComputeNormalVector(void)
{
    STVector3 normal;
    STVector3 V = m_b - m_a;
    STVector3 W = m_c - m_a;
    // TO DO: Proj2 raytracer
    // - Compute the surface normal.
    // 1. Compute the surface surface normal to the
    // plane whose points are m_a, m_b, and m_c
    //------------------------------------------------

    //takes the cross product of 2 vectors (sides of the triangle) to find the normal
    normal = STVector3::Cross(V, W);
    normal.Normalize();

    //---------------------------------------------------
    return (normal);
}
