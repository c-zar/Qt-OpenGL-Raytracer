//------------------------------------------------------------------------------
// Copyright 2015 Corey Toler-Franklin, University of Florida
// Surface.h
// Defines the base class for surfaces
//-----------------------------------------------------------------------------

#ifndef _SURFACE_H
#define _SURFACE_H

#include "Intersection.h"
#include "Lists.h"
#include "Ray.h"
#include "STVector3.h"
#include "defs.h"

class Surface {

public:
    Surface();
    ~Surface(void);
    bool IsTransparent(void);
    float GetTranspValue(void);
    RGBR_f GetColor(void);
    virtual bool FindIntersection(Ray ray, Intersection* pIntersection) { return (false); }
    bool IsReflective(void);

protected:
    STVector3 m_center;
    RGBR_f m_color;
    float m_transparent;
    bool reflective;
};

#endif //_SURFACE_H
