//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/highgui/highgui_c.h>
#include <hbapi.h>
#include <hbapierr.h>
#include "hbopencv2.hpp"

// CVAPI(void) cvDisplayOverlay( const char* name, const char* text, int delayms CV_DEFAULT(0) )
#if 0
HB_FUNC(CVDISPLAYOVERLAY)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 HB_ISCHAR(1) && HB_ISCHAR(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cvDisplayOverlay(hb_parc(1), hb_parc(2), cv_dpar_int(3, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}
#endif

// CVAPI(void) cvDisplayStatusBar( const char* name, const char* text, int delayms CV_DEFAULT(0) )
#if 0
HB_FUNC(CVDISPLAYSTATUSBAR)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 HB_ISCHAR(1) && HB_ISCHAR(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cvDisplayStatusBar(hb_parc(1), hb_parc(2), cv_dpar_int(3, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}
#endif

// CVAPI(void) cvSaveWindowParameters( const char* name )
#if 0
HB_FUNC(CVSAVEWINDOWPARAMETERS)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1))
  {
    cvSaveWindowParameters(hb_parc(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}
#endif

// CVAPI(void) cvLoadWindowParameters( const char* name )
#if 0
HB_FUNC(CVLOADWINDOWPARAMETERS)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1))
  {
    cvLoadWindowParameters(hb_parc(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}
#endif

// CVAPI(void) cvStopLoop( void )
#if 0
HB_FUNC(CVSTOPLOOP)
{
  if (hb_pcount() == 0)
  {
    cvStopLoop();
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}
#endif

// CVAPI(int) cvStartWindowThread( void )
HB_FUNC(CVSTARTWINDOWTHREAD)
{
  if (hb_pcount() == 0) {
    cv_ret_int(cvStartWindowThread());
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvNamedWindow( const char* name, int flags CV_DEFAULT(CV_WINDOW_AUTOSIZE) )
HB_FUNC(CVNAMEDWINDOW)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISCHAR(1) && (HB_ISNUM(2) || HB_ISNIL(2))) {
    cv_ret_int(cvNamedWindow(hb_parc(1), cv_dpar_int(2, CV_WINDOW_AUTOSIZE)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetWindowProperty( const char* name, int prop_id, double prop_value )
HB_FUNC(CVSETWINDOWPROPERTY)
{
  if (hb_pcount() == 3 && HB_ISCHAR(1) && HB_ISNUM(2) && HB_ISNUM(3)) {
    cvSetWindowProperty(hb_parc(1), cv_par_int(2), cv_par_double(3));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvGetWindowProperty( const char* name, int prop_id )
HB_FUNC(CVGETWINDOWPROPERTY)
{
  if (hb_pcount() == 2 && HB_ISCHAR(1) && HB_ISNUM(2)) {
    cv_ret_double(cvGetWindowProperty(hb_parc(1), cv_par_int(2)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvShowImage( const char* name, const CvArr* image )
HB_FUNC(CVSHOWIMAGE)
{
  if (hb_pcount() == 2 && HB_ISCHAR(1) && HB_ISPOINTER(2)) {
    cvShowImage(hb_parc(1), cv_cpar_CvArr(2));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvResizeWindow( const char* name, int width, int height )
HB_FUNC(CVRESIZEWINDOW)
{
  if (hb_pcount() == 3 && HB_ISCHAR(1) && HB_ISNUM(2) && HB_ISNUM(3)) {
    cvResizeWindow(hb_parc(1), cv_par_int(2), cv_par_int(3));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMoveWindow( const char* name, int x, int y )
HB_FUNC(CVMOVEWINDOW)
{
  if (hb_pcount() == 3 && HB_ISCHAR(1) && HB_ISNUM(2) && HB_ISNUM(3)) {
    cvMoveWindow(hb_parc(1), cv_par_int(2), cv_par_int(3));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvDestroyWindow( const char* name )
HB_FUNC(CVDESTROYWINDOW)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1)) {
    cvDestroyWindow(hb_parc(1));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvDestroyAllWindows( void )
HB_FUNC(CVDESTROYALLWINDOWS)
{
  if (hb_pcount() == 0) {
    cvDestroyAllWindows();
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void*) cvGetWindowHandle( const char* name )
HB_FUNC(CVGETWINDOWHANDLE)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1)) {
    cv_ret_voidptr(cvGetWindowHandle(hb_parc(1)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(const char*) cvGetWindowName( void* window_handle )
HB_FUNC(CVGETWINDOWNAME)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1)) {
    hb_retc(cvGetWindowName(cv_par_voidptr(1)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetTrackbarPos( const char* trackbar_name, const char* window_name )
HB_FUNC(CVGETTRACKBARPOS)
{
  if (hb_pcount() == 2 && HB_ISCHAR(1) && HB_ISCHAR(2)) {
    cv_ret_int(cvGetTrackbarPos(hb_parc(1), hb_parc(2)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetTrackbarPos( const char* trackbar_name, const char* window_name, int pos )
HB_FUNC(CVSETTRACKBARPOS)
{
  if (hb_pcount() == 3 && HB_ISCHAR(1) && HB_ISCHAR(2) && HB_ISNUM(3)) {
    cvSetTrackbarPos(hb_parc(1), hb_parc(2), cv_par_int(3));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetTrackbarMax( const char* trackbar_name, const char* window_name, int maxval )
HB_FUNC(CVSETTRACKBARMAX)
{
  if (hb_pcount() == 3 && HB_ISCHAR(1) && HB_ISCHAR(2) && HB_ISNUM(3)) {
    cvSetTrackbarMax(hb_parc(1), hb_parc(2), cv_par_int(3));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvLoadImage( const char* filename, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
HB_FUNC(CVLOADIMAGE)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISCHAR(1) && (HB_ISNUM(2) || HB_ISNIL(2))) {
    cv_ret_IplImage(cvLoadImage(hb_parc(1), cv_dpar_int(2, CV_LOAD_IMAGE_COLOR)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvLoadImageM( const char* filename, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
HB_FUNC(CVLOADIMAGEM)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISCHAR(1) && (HB_ISNUM(2) || HB_ISNIL(2))) {
    cv_ret_CvMat(cvLoadImageM(hb_parc(1), cv_dpar_int(2, CV_LOAD_IMAGE_COLOR)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSaveImage( const char* filename, const CvArr* image, const int* params CV_DEFAULT(0) )
HB_FUNC(CVSAVEIMAGE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISCHAR(1) && HB_ISPOINTER(2) && (HB_ISARRAY(3) || HB_ISNIL(3))) {
    PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
    int *values3 = NULL;
    if (a3) {
      const int lenght = hb_arrayLen(a3);
      values3 = new int[lenght + 1];
      for (int i = 0; i < lenght; ++i) {
        values3[i] = hb_arrayGetNI(a3, i + 1);
      }
      values3[lenght] = 0;
    }
    cv_ret_int(cvSaveImage(hb_parc(1), cv_cpar_CvArr(2), HB_ISNIL(3) ? 0 : (const int *)values3));
    if (a3) {
      delete[] values3;
    }
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvDecodeImage( const CvMat* buf, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
HB_FUNC(CVDECODEIMAGE)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2))) {
    cv_ret_IplImage(cvDecodeImage(cv_cpar_CvMat(1), cv_dpar_int(2, CV_LOAD_IMAGE_COLOR)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvDecodeImageM( const CvMat* buf, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
HB_FUNC(CVDECODEIMAGEM)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2))) {
    cv_ret_CvMat(cvDecodeImageM(cv_cpar_CvMat(1), cv_dpar_int(2, CV_LOAD_IMAGE_COLOR)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvEncodeImage( const char* ext, const CvArr* image, const int* params CV_DEFAULT(0) )
HB_FUNC(CVENCODEIMAGE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISCHAR(1) && HB_ISPOINTER(2) && (HB_ISARRAY(3) || HB_ISNIL(3))) {
    PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
    int *values3 = NULL;
    if (a3) {
      const int lenght = hb_arrayLen(a3);
      values3 = new int[lenght + 1];
      for (int i = 0; i < lenght; ++i) {
        values3[i] = hb_arrayGetNI(a3, i + 1);
      }
      values3[lenght] = 0;
    }
    cv_ret_CvMat(cvEncodeImage(hb_parc(1), cv_cpar_CvArr(2), HB_ISNIL(3) ? 0 : (const int *)values3));
    if (a3) {
      delete[] values3;
    }
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvConvertImage( const CvArr* src, CvArr* dst, int flags CV_DEFAULT(0) )
HB_FUNC(CVCONVERTIMAGE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3))) {
    cvConvertImage(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, 0));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvWaitKey( int delay CV_DEFAULT(0) )
HB_FUNC(CVWAITKEY)
{
  if (hb_pcount() >= 0 && hb_pcount() <= 1 && (HB_ISNUM(1) || HB_ISNIL(1))) {
    cv_ret_int(cvWaitKey(cv_dpar_int(1, 0)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetOpenGlContext( const char* window_name )
HB_FUNC(CVSETOPENGLCONTEXT)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1)) {
    cvSetOpenGlContext(hb_parc(1));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvUpdateWindow( const char* window_name )
HB_FUNC(CVUPDATEWINDOW)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1)) {
    cvUpdateWindow(hb_parc(1));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvCapture*) cvCreateFileCapture( const char* filename )
HB_FUNC(CVCREATEFILECAPTURE)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1)) {
    cv_ret_CvCapture(cvCreateFileCapture(hb_parc(1)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvCapture*) cvCreateCameraCapture( int index )
HB_FUNC(CVCREATECAMERACAPTURE)
{
  if (hb_pcount() == 1 && HB_ISNUM(1)) {
    cv_ret_CvCapture(cvCreateCameraCapture(cv_par_int(1)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGrabFrame( CvCapture* capture )
HB_FUNC(CVGRABFRAME)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1)) {
    cv_ret_int(cvGrabFrame(cv_par_CvCapture(1)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvRetrieveFrame( CvCapture* capture, int streamIdx CV_DEFAULT(0) )
HB_FUNC(CVRETRIEVEFRAME)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2))) {
    cv_ret_IplImage(cvRetrieveFrame(cv_par_CvCapture(1), cv_dpar_int(2, 0)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvQueryFrame( CvCapture* capture )
HB_FUNC(CVQUERYFRAME)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1)) {
    cv_ret_IplImage(cvQueryFrame(cv_par_CvCapture(1)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseCapture( CvCapture** capture )
HB_FUNC(CVRELEASECAPTURE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1)) {
    CvCapture *capture = cv_par_CvCapture(1);
    cvReleaseCapture(&capture);
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvGetCaptureProperty( CvCapture* capture, int property_id )
HB_FUNC(CVGETCAPTUREPROPERTY)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2)) {
    cv_ret_double(cvGetCaptureProperty(cv_par_CvCapture(1), cv_par_int(2)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSetCaptureProperty( CvCapture* capture, int property_id, double value )
HB_FUNC(CVSETCAPTUREPROPERTY)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3)) {
    cv_ret_int(cvSetCaptureProperty(cv_par_CvCapture(1), cv_par_int(2), cv_par_double(3)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetCaptureDomain( CvCapture* capture )
HB_FUNC(CVGETCAPTUREDOMAIN)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1)) {
    cv_ret_int(cvGetCaptureDomain(cv_par_CvCapture(1)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE int CV_FOURCC( char c1, char c2, char c3, char c4 )
HB_FUNC(CV_FOURCC)
{
  if (hb_pcount() == 4 && HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4)) {
    cv_ret_int(CV_FOURCC((char)hb_parni(1), (char)hb_parni(2), (char)hb_parni(3), (char)hb_parni(4)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvVideoWriter*) cvCreateVideoWriter( const char* filename, int fourcc, double fps, CvSize frame_size, int
// is_color CV_DEFAULT(1) )
HB_FUNC(CVCREATEVIDEOWRITER)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISCHAR(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISARRAY(4) &&
      (HB_ISNUM(5) || HB_ISNIL(5))) {
    PHB_ITEM pSize4 = hb_param(4, HB_IT_ARRAY);
    CvSize size4;
    size4.width = hb_arrayGetNI(pSize4, 1);
    size4.height = hb_arrayGetNI(pSize4, 2);
    cv_ret_CvVideoWriter(cvCreateVideoWriter(hb_parc(1), cv_par_int(2), cv_par_double(3), size4, cv_dpar_int(5, 1)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvWriteFrame( CvVideoWriter* writer, const IplImage* image )
HB_FUNC(CVWRITEFRAME)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2)) {
    cv_ret_int(cvWriteFrame(cv_par_CvVideoWriter(1), cv_cpar_IplImage(2)));
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseVideoWriter( CvVideoWriter** writer )
HB_FUNC(CVRELEASEVIDEOWRITER)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1)) {
    CvVideoWriter *writer = cv_par_CvVideoWriter(1);
    cvReleaseVideoWriter(&writer);
  } else {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}
