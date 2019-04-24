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
    m_transparent = 1;
    reflective = false;
    initVertexArray();
}

Triangle::Triangle(STVector3 a, STVector3 b, STVector3 c, RGBR_f color, float transparent)
    : Surface()
{
    m_a = a;
    m_b = b;
    m_c = c;
    m_color = color;
    m_transparent = std::min(1.f, transparent);
    reflective = false;
    initVertexArray();
}

Triangle::Triangle(STVector3 a, STVector3 b, STVector3 c, RGBR_f color, bool reflective, float transparent = 1)
    : Surface()
{
    m_a = a;
    m_b = b;
    m_c = c;
    m_color = color;
    m_transparent = std::min(1.f, transparent);
    this->reflective = reflective;
    initVertexArray();
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

void Triangle::initVertexArray()
{
    vertexArray.push_back(m_a.x);
    vertexArray.push_back(m_a.y);
    vertexArray.push_back(m_a.z);

    vertexArray.push_back(m_b.x);
    vertexArray.push_back(m_b.y);
    vertexArray.push_back(m_b.z);

    vertexArray.push_back(m_c.x);
    vertexArray.push_back(m_c.y);
    vertexArray.push_back(m_c.z);
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

    // store the values for the system of equations into variables
    // makes it easier to organize
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

    // implemented a new method as the other ones don't seem to work
    // reference: https://cplusplus.happycodings.com/mathematics/code5.html
    // reference: Fundamentals of Computer Graphics
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

bool Triangle::FindIntersection(Ray ray, Intersection* pIntersection)
{
    bool bFound = false;

    double beta = 0;
    double gamma = 0;
    double time = 0;

    // call intersection solvor with triangle vertexes, beta, gamma, and time values
    if (IntersectionSolver(ray, this->m_a, this->m_b, this->m_c, beta, gamma, time)) {

        // checkes to make sure solutions are accurate
        if (beta < 0.0)
            return false;
        if (gamma < 0.0)
            return false;
        if ((beta + gamma) > 1.0f)
            return false;

        // set the values of pIntersection
        pIntersection->point = ray.Origin() + (time * ray.Direction());
        pIntersection->time = time;
        pIntersection->normal = ComputeNormalVector();
        pIntersection->surface = this;
        pIntersection->viewDirection = ray.Origin() - pIntersection->point;
        pIntersection->viewDirection.Normalize();

        bFound = true;
    }
    //------------------------------------------------------
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

    //takes the cross product of 2 vectors (sides of the triangle) to find the normal
    normal = STVector3::Cross(V, W);
    normal.Normalize();

    //---------------------------------------------------
    return (normal);
}
