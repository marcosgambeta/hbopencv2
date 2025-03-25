//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/photo/photo_c.h>
#include <hbapi.h>

// CVAPI(void) cvInpaint( const CvArr* src, const CvArr* inpaint_mask, CvArr* dst, double inpaintRange, int flags )
HB_FUNC(CVINPAINT)
{
  cvInpaint((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), hb_parnd(4), hb_parni(5));
}
