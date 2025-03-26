//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/photo/photo_c.h>
#include <hbapi.h>
#include "hbopencv2.hpp"

// CVAPI(void) cvInpaint( const CvArr* src, const CvArr* inpaint_mask, CvArr* dst, double inpaintRange, int flags )
HB_FUNC(CVINPAINT)
{
  cvInpaint(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_double(4), cv_par_int(5));
}
