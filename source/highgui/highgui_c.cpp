//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/highgui/highgui_c.h>
#include <hbapi.h>
#include "hbopencv2.hpp"

// CVAPI(void) cvDisplayOverlay( const char* name, const char* text, int delayms CV_DEFAULT(0) )
#if 0
HB_FUNC(CVDISPLAYOVERLAY)
{
  cvDisplayOverlay(hb_parc(1), hb_parc(2), cv_dpar_int(3, 0));
}
#endif

// CVAPI(void) cvDisplayStatusBar( const char* name, const char* text, int delayms CV_DEFAULT(0) )
#if 0
HB_FUNC(CVDISPLAYSTATUSBAR)
{
  cvDisplayStatusBar(hb_parc(1), hb_parc(2), cv_dpar_int(3, 0));
}
#endif

// CVAPI(void) cvSaveWindowParameters( const char* name )
#if 0
HB_FUNC(CVSAVEWINDOWPARAMETERS)
{
  cvSaveWindowParameters(hb_parc(1));
}
#endif

// CVAPI(void) cvLoadWindowParameters( const char* name )
#if 0
HB_FUNC(CVLOADWINDOWPARAMETERS)
{
  cvLoadWindowParameters(hb_parc(1));
}
#endif

// CVAPI(void) cvStopLoop( void )
#if 0
HB_FUNC(CVSTOPLOOP)
{
  cvStopLoop();
}
#endif

// CVAPI(int) cvStartWindowThread( void )
HB_FUNC(CVSTARTWINDOWTHREAD)
{
  cv_ret_int(cvStartWindowThread());
}

// CVAPI(int) cvNamedWindow( const char* name, int flags CV_DEFAULT(CV_WINDOW_AUTOSIZE) )
HB_FUNC(CVNAMEDWINDOW)
{
  cv_ret_int(cvNamedWindow(hb_parc(1), cv_dpar_int(2, CV_WINDOW_AUTOSIZE)));
}

// CVAPI(void) cvSetWindowProperty( const char* name, int prop_id, double prop_value )
HB_FUNC(CVSETWINDOWPROPERTY)
{
  cvSetWindowProperty(hb_parc(1), cv_par_int(2), cv_par_double(3));
}

// CVAPI(double) cvGetWindowProperty( const char* name, int prop_id )
HB_FUNC(CVGETWINDOWPROPERTY)
{
  cv_ret_double(cvGetWindowProperty(hb_parc(1), cv_par_int(2)));
}

// CVAPI(void) cvShowImage( const char* name, const CvArr* image )
HB_FUNC(CVSHOWIMAGE)
{
  cvShowImage(hb_parc(1), cv_cpar_CvArr(2));
}

// CVAPI(void) cvResizeWindow( const char* name, int width, int height )
HB_FUNC(CVRESIZEWINDOW)
{
  cvResizeWindow(hb_parc(1), cv_par_int(2), cv_par_int(3));
}

// CVAPI(void) cvMoveWindow( const char* name, int x, int y )
HB_FUNC(CVMOVEWINDOW)
{
  cvMoveWindow(hb_parc(1), cv_par_int(2), cv_par_int(3));
}

// CVAPI(void) cvDestroyWindow( const char* name )
HB_FUNC(CVDESTROYWINDOW)
{
  cvDestroyWindow(hb_parc(1));
}

// CVAPI(void) cvDestroyAllWindows( void )
HB_FUNC(CVDESTROYALLWINDOWS)
{
  cvDestroyAllWindows();
}

// CVAPI(void*) cvGetWindowHandle( const char* name )
HB_FUNC(CVGETWINDOWHANDLE)
{
  cv_ret_voidptr(cvGetWindowHandle(hb_parc(1)));
}

// CVAPI(const char*) cvGetWindowName( void* window_handle )
HB_FUNC(CVGETWINDOWNAME)
{
  hb_retc(cvGetWindowName((void *)hb_parptr(1)));
}

// CVAPI(int) cvGetTrackbarPos( const char* trackbar_name, const char* window_name )
HB_FUNC(CVGETTRACKBARPOS)
{
  cv_ret_int(cvGetTrackbarPos(hb_parc(1), hb_parc(2)));
}

// CVAPI(void) cvSetTrackbarPos( const char* trackbar_name, const char* window_name, int pos )
HB_FUNC(CVSETTRACKBARPOS)
{
  cvSetTrackbarPos(hb_parc(1), hb_parc(2), cv_par_int(3));
}

// CVAPI(void) cvSetTrackbarMax( const char* trackbar_name, const char* window_name, int maxval )
HB_FUNC(CVSETTRACKBARMAX)
{
  cvSetTrackbarMax(hb_parc(1), hb_parc(2), cv_par_int(3));
}

// CVAPI(IplImage*) cvLoadImage( const char* filename, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
HB_FUNC(CVLOADIMAGE)
{
  cv_ret_IplImage(cvLoadImage(hb_parc(1), cv_dpar_int(2, CV_LOAD_IMAGE_COLOR)));
}

// CVAPI(CvMat*) cvLoadImageM( const char* filename, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
HB_FUNC(CVLOADIMAGEM)
{
  cv_ret_CvMat(cvLoadImageM(hb_parc(1), cv_dpar_int(2, CV_LOAD_IMAGE_COLOR)));
}

// CVAPI(int) cvSaveImage( const char* filename, const CvArr* image, const int* params CV_DEFAULT(0) )
HB_FUNC(CVSAVEIMAGE)
{
  PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
  int *values3 = NULL;
  if (a3)
  {
    const int lenght = hb_arrayLen(a3);
    values3 = new int[lenght + 1];
    for (int i = 0; i < lenght; ++i)
    {
      values3[i] = hb_arrayGetNI(a3, i + 1);
    }
    values3[lenght] = 0;
  }
  cv_ret_int(cvSaveImage(hb_parc(1), cv_cpar_CvArr(2), HB_ISNIL(3) ? 0 : (const int *)values3));
  if (a3)
  {
    delete[] values3;
  }
}

// CVAPI(IplImage*) cvDecodeImage( const CvMat* buf, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
HB_FUNC(CVDECODEIMAGE)
{
  cv_ret_IplImage(cvDecodeImage(cv_cpar_CvMat(1), cv_dpar_int(2, CV_LOAD_IMAGE_COLOR)));
}

// CVAPI(CvMat*) cvDecodeImageM( const CvMat* buf, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
HB_FUNC(CVDECODEIMAGEM)
{
  cv_ret_CvMat(cvDecodeImageM(cv_cpar_CvMat(1), cv_dpar_int(2, CV_LOAD_IMAGE_COLOR)));
}

// CVAPI(CvMat*) cvEncodeImage( const char* ext, const CvArr* image, const int* params CV_DEFAULT(0) )
HB_FUNC(CVENCODEIMAGE)
{
  PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
  int *values3 = NULL;
  if (a3)
  {
    const int lenght = hb_arrayLen(a3);
    values3 = new int[lenght + 1];
    for (int i = 0; i < lenght; ++i)
    {
      values3[i] = hb_arrayGetNI(a3, i + 1);
    }
    values3[lenght] = 0;
  }
  cv_ret_CvMat(cvEncodeImage(hb_parc(1), cv_cpar_CvArr(2), HB_ISNIL(3) ? 0 : (const int *)values3));
  if (a3)
  {
    delete[] values3;
  }
}

// CVAPI(void) cvConvertImage( const CvArr* src, CvArr* dst, int flags CV_DEFAULT(0) )
HB_FUNC(CVCONVERTIMAGE)
{
  cvConvertImage(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, 0));
}

// CVAPI(int) cvWaitKey( int delay CV_DEFAULT(0) )
HB_FUNC(CVWAITKEY)
{
  cv_ret_int(cvWaitKey(cv_dpar_int(1, 0)));
}

// CVAPI(void) cvSetOpenGlContext( const char* window_name )
HB_FUNC(CVSETOPENGLCONTEXT)
{
  cvSetOpenGlContext(hb_parc(1));
}

// CVAPI(void) cvUpdateWindow( const char* window_name )
HB_FUNC(CVUPDATEWINDOW)
{
  cvUpdateWindow(hb_parc(1));
}

// CVAPI(CvCapture*) cvCreateFileCapture( const char* filename )
HB_FUNC(CVCREATEFILECAPTURE)
{
  cv_ret_CvCapture(cvCreateFileCapture(hb_parc(1)));
}

// CVAPI(CvCapture*) cvCreateCameraCapture( int index )
HB_FUNC(CVCREATECAMERACAPTURE)
{
  cv_ret_CvCapture(cvCreateCameraCapture(cv_par_int(1)));
}

// CVAPI(int) cvGrabFrame( CvCapture* capture )
HB_FUNC(CVGRABFRAME)
{
  cv_ret_int(cvGrabFrame(cv_par_CvCapture(1)));
}

// CVAPI(IplImage*) cvRetrieveFrame( CvCapture* capture, int streamIdx CV_DEFAULT(0) )
HB_FUNC(CVRETRIEVEFRAME)
{
  cv_ret_IplImage(cvRetrieveFrame(cv_par_CvCapture(1), cv_dpar_int(2, 0)));
}

// CVAPI(IplImage*) cvQueryFrame( CvCapture* capture )
HB_FUNC(CVQUERYFRAME)
{
  cv_ret_IplImage(cvQueryFrame(cv_par_CvCapture(1)));
}

// CVAPI(void) cvReleaseCapture( CvCapture** capture )
HB_FUNC(CVRELEASECAPTURE)
{
  CvCapture *capture = cv_par_CvCapture(1);
  cvReleaseCapture(&capture);
}

// CVAPI(double) cvGetCaptureProperty( CvCapture* capture, int property_id )
HB_FUNC(CVGETCAPTUREPROPERTY)
{
  cv_ret_double(cvGetCaptureProperty(cv_par_CvCapture(1), cv_par_int(2)));
}

// CVAPI(int) cvSetCaptureProperty( CvCapture* capture, int property_id, double value )
HB_FUNC(CVSETCAPTUREPROPERTY)
{
  cv_ret_int(cvSetCaptureProperty(cv_par_CvCapture(1), cv_par_int(2), cv_par_double(3)));
}

// CVAPI(int) cvGetCaptureDomain( CvCapture* capture )
HB_FUNC(CVGETCAPTUREDOMAIN)
{
  cv_ret_int(cvGetCaptureDomain(cv_par_CvCapture(1)));
}

// CV_INLINE int CV_FOURCC( char c1, char c2, char c3, char c4 )
HB_FUNC(CV_FOURCC)
{
  cv_ret_int(CV_FOURCC((char)hb_parni(1), (char)hb_parni(2), (char)hb_parni(3), (char)hb_parni(4)));
}

// CVAPI(CvVideoWriter*) cvCreateVideoWriter( const char* filename, int fourcc, double fps, CvSize frame_size, int
// is_color CV_DEFAULT(1) )
HB_FUNC(CVCREATEVIDEOWRITER)
{
  PHB_ITEM pSize4 = hb_param(4, HB_IT_ARRAY);
  CvSize size4;
  size4.width = hb_arrayGetNI(pSize4, 1);
  size4.height = hb_arrayGetNI(pSize4, 2);
  cv_ret_CvVideoWriter(cvCreateVideoWriter(hb_parc(1), cv_par_int(2), cv_par_double(3), size4, cv_dpar_int(5, 1)));
}

// CVAPI(int) cvWriteFrame( CvVideoWriter* writer, const IplImage* image )
HB_FUNC(CVWRITEFRAME)
{
  cv_ret_int(cvWriteFrame(cv_par_CvVideoWriter(1), cv_cpar_IplImage(2)));
}

// CVAPI(void) cvReleaseVideoWriter( CvVideoWriter** writer )
HB_FUNC(CVRELEASEVIDEOWRITER)
{
  CvVideoWriter *writer = cv_par_CvVideoWriter(1);
  cvReleaseVideoWriter(&writer);
}
