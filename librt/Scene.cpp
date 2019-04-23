//------------------------------------------------------------------------------
// Copyright 2015 Corey Toler-Franklin, University of Florida
// Scene.cpp
// Stores all the objects - lights, camera and surfaces for setting up the scene.
//------------------------------------------------------------------------------

#include "Scene.h"
#include "Intersection.h"
#include "Light.h"
#include "Sphere.h"
#include "Surface.h"
#include <assert.h>
#include <stdio.h>
#include <string>

// contructor
Scene::Scene(void)
    : m_background(RGBR_f(1, 1, 1, 1))
{
    // init camera
    m_pCamera = new Camera();
}

// destructor
Scene::~Scene()
{
}

// set the background color
void Scene::SetBackgroundColor(RGBR_f color)
{
    m_background = color;
}

// return the background color
RGBR_f Scene::GetBackgroundColor(void)
{
    return (m_background);
}

// ass a light
void Scene::AddLight(Light lightin)
{
    m_lights.push_back(lightin);
}

// returns the list of lights
LightList Scene::GetLightList(void)
{
    return (m_lights);
}

// add an object
void Scene::AddSurface(Surface* pSurfacein)
{
    m_surfaceList.push_back(pSurfacein);
}

// return the camera
Camera* Scene::GetCamera(void)
{
    return (m_pCamera);
}

//-----------------------------------------------------
// Find the intersection of the ray with objects in the scene
// Return the closest intersection
//-----------------------------------------------------
int Scene::FindClosestIntersection(Ray ray, Intersection* pIntersection)
{
    int numPoints = 0;

    //Must set it to false for further use
    numPoints = FindIntersection(ray, pIntersection);
    return (numPoints);
}

//-----------------------------------------------------
// Find the intersection of the ray with objects in the scene.
// Check for the closest intersections and retun the number
// of close intersections found.
// Returns the pIntersection  data for the closest intersection.
//------------------------------.-----------------------
int Scene::FindIntersection(Ray ray, Intersection* pIntersection)
{
    bool bFound = false; // true if an intersection is found
    int numPoints = 0; // tracks the number of intersectiouns
    Intersection closestIntersection; // the closest intersection

    IntersectionList intersectionList; // a list of all intersections
    SurfaceList::iterator iter = m_surfaceList.begin();
    SurfaceList::iterator end = m_surfaceList.end();

    // Evaluate this for each surface in the surface list
    for (; iter != end; ++iter) {

        // TO DO: Proj2 raytracer
        // 1. Check for intersections
        // 2. Update the list of intersections
        // 3. Set bFound to true if an intersection was found
        //---------------------------------------------------------------

        // if intersection is found,
        if ((*iter)->FindIntersection(ray, pIntersection)) {
            intersectionList.push_back((*pIntersection)); // push to intersection list
            numPoints = 1; // set num points equal to 1
            bFound = true; // set found to true
        }

        //----------------------------------------------------------------
    }

    if (bFound) {

        // TO DO: Proj2 raytracer
        // 1. bFound is true so find the closest intersection along the ray from the intersection list.
        // NOTE: you may have to resolve intersections that are too close within a margin of error.
        // You may choose to resolve this here and return 1 for numpoints or return the
        // number of close points and choose later (choosing later will require changing the code structure).
        // 2. set pIntersection to the closest intersection
        // 3. set the number of points and return
        //---------------------------------------------------------

        // loop through the list
        for (size_t i = 0; i < intersectionList.size(); i++) {
            if (intersectionList.at(i).time < pIntersection->time) { // compare the times of each intersection
                (*pIntersection) = intersectionList.at(i); // find the lowest time and set to pIntersection
            }
        }

        // return the number of close intersections found
    }

    return (numPoints);
}

//-----------------------------------------------------
// clear the scene by removing surfaces
//-----------------------------------------------------
void Scene::Clear(void)
{
    SurfaceList::iterator iter = m_surfaceList.begin();
    SurfaceList::iterator end = m_surfaceList.end();

    // delete objects
    for (; iter != end; ++iter) {
        delete *iter;
        *iter = NULL;
    }

    // clean up
    m_surfaceList.clear();
}