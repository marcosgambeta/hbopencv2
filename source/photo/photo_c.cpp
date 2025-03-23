/*

  OpenCV 2 for [x]Harbour - Bindings libraries for [x]Harbour and OpenCV 2

  Copyright (C) 2021 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>

*/

#include <opencv2/photo/photo_c.h>
#include <hbapi.h>

/*
CVAPI(void) cvInpaint( const CvArr* src, const CvArr* inpaint_mask, CvArr* dst, double inpaintRange, int flags )
*/
HB_FUNC( CVINPAINT )
{
  cvInpaint( ( const CvArr* ) hb_parptr( 1 ), ( const CvArr* ) hb_parptr( 2 ), ( CvArr* ) hb_parptr( 3 ), hb_parnd( 4 ), hb_parni( 5 ) );
}
