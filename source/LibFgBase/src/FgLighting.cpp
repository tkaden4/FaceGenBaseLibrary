//
// Copyright (c) 2015 Singular Inversions Inc. (facegen.com)
// Use, modification and distribution is subject to the MIT License,
// see accompanying file LICENSE.txt or facegen.com/base_library_license.txt
//
// Authors:     Andrew Beatty
// Created:     July 1, 2011
//

#include "stdafx.h"

#include "FgLighting.hpp"
#include "FgImage.hpp"
#include "FgMath.hpp"

using namespace std;

FgImgRgbaUb
FgLighting::createSpecularMap() const
{
    FGASSERT(m_lights.size() > 0);

    float   fresnelLow = 1.5f,      // 90 degree angle brightness
            fresnelHigh = 1.5f,     // 0 degree angle brightness
            falloffStd = 0.1f;      // Must be greater than 0 and less than 1/sqrt(2).

    float                    invVar = 1.0f / (2.0f * fgSqr(falloffStd));
    FgImgRgbaUb              img(128,128);
    for (uint py=0; py<128; py++) {
        float    yy = ((float)py - 63.5f) / 64.0f;
        for (uint px=0; px<128; px++) {
            float   xx = ((float)px - 63.5f) / 64.0f,
                    sq = xx*xx + yy*yy;
            if (sq > 1.0f)                    // Outside valid spherical region.
                img.elem(px,py) = FgRgbaUB(0,0,0,1);
            else {
                float   aa = 2.0f * sqrt(1.0f - sq),
                        sr = sqrt(sq),
                        fresnel = (1.0f - sr) * fresnelLow + sr * fresnelHigh;
                FgVect3F        r(aa*xx,aa*yy,1.0f-2.0f*sq);
                FgRgbaF         pix(0,0,0,255);
                for (uint ll=0; ll<m_lights.size(); ll++)
                {
                    float       diffSqr = (r - m_lights[ll].m_direction).lengthSqr(),
                                bright = exp(-diffSqr * invVar) * fresnel * 255.0f;
                    pix.red() += m_lights[ll].m_colour[0] * bright;
                    pix.green() += m_lights[ll].m_colour[1] * bright;
                    pix.blue() += m_lights[ll].m_colour[2] * bright;
                }
                if (pix.red() > 255.0f) pix.red() = 255.0f;
                if (pix.green() > 255.0f) pix.green() = 255.0f;
                if (pix.blue() > 255.0f) pix.blue() = 255.0f;
                fgConvert_(pix,img.elem(px,py));
            }
        }
    }
    return img;
}

// */