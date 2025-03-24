//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/highgui/highgui_c.h>
#include <hbapi.h>

/*
CVAPI(void) cvDisplayOverlay( const char* name, const char* text, int delayms CV_DEFAULT(0) )
*/
#if 0
HB_FUNC(CVDISPLAYOVERLAY)
{
  cvDisplayOverlay(hb_parc(1), hb_parc(2), HB_ISNIL(3) ? 0 : hb_parni(3));
}
#endif

/*
CVAPI(void) cvDisplayStatusBar( const char* name, const char* text, int delayms CV_DEFAULT(0) )
*/
#if 0
HB_FUNC(CVDISPLAYSTATUSBAR)
{
  cvDisplayStatusBar(hb_parc(1), hb_parc(2), HB_ISNIL(3) ? 0 : hb_parni(3));
}
#endif

/*
CVAPI(void) cvSaveWindowParameters( const char* name )
*/
#if 0
HB_FUNC(CVSAVEWINDOWPARAMETERS)
{
  cvSaveWindowParameters(hb_parc(1));
}
#endif

/*
CVAPI(void) cvLoadWindowParameters( const char* name )
*/
#if 0
HB_FUNC(CVLOADWINDOWPARAMETERS)
{
  cvLoadWindowParameters(hb_parc(1));
}
#endif

/*
CVAPI(void) cvStopLoop( void )
*/
#if 0
HB_FUNC(CVSTOPLOOP)
{
  cvStopLoop();
}
#endif

/*
CVAPI(int) cvStartWindowThread( void )
*/
HB_FUNC(CVSTARTWINDOWTHREAD)
{
  hb_retni(cvStartWindowThread());
}

/*
CVAPI(int) cvNamedWindow( const char* name, int flags CV_DEFAULT(CV_WINDOW_AUTOSIZE) )
*/
HB_FUNC(CVNAMEDWINDOW)
{
  hb_retni(cvNamedWindow(hb_parc(1), HB_ISNIL(2) ? CV_WINDOW_AUTOSIZE : hb_parni(2)));
}

/*
CVAPI(void) cvSetWindowProperty( const char* name, int prop_id, double prop_value )
*/
HB_FUNC(CVSETWINDOWPROPERTY)
{
  cvSetWindowProperty(hb_parc(1), hb_parni(2), hb_parnd(3));
}

/*
CVAPI(double) cvGetWindowProperty( const char* name, int prop_id )
*/
HB_FUNC(CVGETWINDOWPROPERTY)
{
  hb_retnd(cvGetWindowProperty(hb_parc(1), hb_parni(2)));
}

/*
CVAPI(void) cvShowImage( const char* name, const CvArr* image )
*/
HB_FUNC(CVSHOWIMAGE)
{
  cvShowImage(hb_parc(1), (const CvArr *)hb_parptr(2));
}

/*
CVAPI(void) cvResizeWindow( const char* name, int width, int height )
*/
HB_FUNC(CVRESIZEWINDOW)
{
  cvResizeWindow(hb_parc(1), hb_parni(2), hb_parni(3));
}

/*
CVAPI(void) cvMoveWindow( const char* name, int x, int y )
*/
HB_FUNC(CVMOVEWINDOW)
{
  cvMoveWindow(hb_parc(1), hb_parni(2), hb_parni(3));
}

/*
CVAPI(void) cvDestroyWindow( const char* name )
*/
HB_FUNC(CVDESTROYWINDOW)
{
  cvDestroyWindow(hb_parc(1));
}

/*
CVAPI(void) cvDestroyAllWindows( void )
*/
HB_FUNC(CVDESTROYALLWINDOWS)
{
  cvDestroyAllWindows();
}

/*
CVAPI(void*) cvGetWindowHandle( const char* name )
*/
HB_FUNC(CVGETWINDOWHANDLE)
{
  hb_retptr((void *)cvGetWindowHandle(hb_parc(1)));
}

/*
CVAPI(const char*) cvGetWindowName( void* window_handle )
*/
HB_FUNC(CVGETWINDOWNAME)
{
  hb_retc(cvGetWindowName((void *)hb_parptr(1)));
}

/*
CVAPI(int) cvGetTrackbarPos( const char* trackbar_name, const char* window_name )
*/
HB_FUNC(CVGETTRACKBARPOS)
{
  hb_retni(cvGetTrackbarPos(hb_parc(1), hb_parc(2)));
}

/*
CVAPI(void) cvSetTrackbarPos( const char* trackbar_name, const char* window_name, int pos )
*/
HB_FUNC(CVSETTRACKBARPOS)
{
  cvSetTrackbarPos(hb_parc(1), hb_parc(2), hb_parni(3));
}

/*
CVAPI(void) cvSetTrackbarMax( const char* trackbar_name, const char* window_name, int maxval )
*/
HB_FUNC(CVSETTRACKBARMAX)
{
  cvSetTrackbarMax(hb_parc(1), hb_parc(2), hb_parni(3));
}

/*
CVAPI(IplImage*) cvLoadImage( const char* filename, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
*/
HB_FUNC(CVLOADIMAGE)
{
  hb_retptr((IplImage *)cvLoadImage(hb_parc(1), HB_ISNIL(2) ? CV_LOAD_IMAGE_COLOR : hb_parni(2)));
}

/*
CVAPI(CvMat*) cvLoadImageM( const char* filename, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
*/
HB_FUNC(CVLOADIMAGEM)
{
  hb_retptr((CvMat *)cvLoadImageM(hb_parc(1), HB_ISNIL(2) ? CV_LOAD_IMAGE_COLOR : hb_parni(2)));
}

/*
CVAPI(int) cvSaveImage( const char* filename, const CvArr* image, const int* params CV_DEFAULT(0) )
*/
HB_FUNC(CVSAVEIMAGE)
{
  PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
  int *values3;
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
  hb_retni(cvSaveImage(hb_parc(1), (const CvArr *)hb_parptr(2), HB_ISNIL(3) ? 0 : (const int *)values3));
  if (a3)
  {
    delete[] values3;
  }
}

/*
CVAPI(IplImage*) cvDecodeImage( const CvMat* buf, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
*/
HB_FUNC(CVDECODEIMAGE)
{
  hb_retptr((IplImage *)cvDecodeImage((const CvMat *)hb_parptr(1), HB_ISNIL(2) ? CV_LOAD_IMAGE_COLOR : hb_parni(2)));
}

/*
CVAPI(CvMat*) cvDecodeImageM( const CvMat* buf, int iscolor CV_DEFAULT(CV_LOAD_IMAGE_COLOR) )
*/
HB_FUNC(CVDECODEIMAGEM)
{
  hb_retptr((CvMat *)cvDecodeImageM((const CvMat *)hb_parptr(1), HB_ISNIL(2) ? CV_LOAD_IMAGE_COLOR : hb_parni(2)));
}

/*
CVAPI(CvMat*) cvEncodeImage( const char* ext, const CvArr* image, const int* params CV_DEFAULT(0) )
*/
HB_FUNC(CVENCODEIMAGE)
{
  PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
  int *values3;
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
  hb_retptr((CvMat *)cvEncodeImage(hb_parc(1), (const CvArr *)hb_parptr(2), HB_ISNIL(3) ? 0 : (const int *)values3));
  if (a3)
  {
    delete[] values3;
  }
}

/*
CVAPI(void) cvConvertImage( const CvArr* src, CvArr* dst, int flags CV_DEFAULT(0) )
*/
HB_FUNC(CVCONVERTIMAGE)
{
  cvConvertImage((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? 0 : hb_parni(3));
}

/*
CVAPI(int) cvWaitKey( int delay CV_DEFAULT(0) )
*/
HB_FUNC(CVWAITKEY)
{
  hb_retni(cvWaitKey(HB_ISNIL(1) ? 0 : hb_parni(1)));
}

/*
CVAPI(void) cvSetOpenGlContext( const char* window_name )
*/
HB_FUNC(CVSETOPENGLCONTEXT)
{
  cvSetOpenGlContext(hb_parc(1));
}

/*
CVAPI(void) cvUpdateWindow( const char* window_name )
*/
HB_FUNC(CVUPDATEWINDOW)
{
  cvUpdateWindow(hb_parc(1));
}

/*
CVAPI(CvCapture*) cvCreateFileCapture( const char* filename )
*/
HB_FUNC(CVCREATEFILECAPTURE)
{
  hb_retptr((CvCapture *)cvCreateFileCapture(hb_parc(1)));
}

/*
CVAPI(CvCapture*) cvCreateCameraCapture( int index )
*/
HB_FUNC(CVCREATECAMERACAPTURE)
{
  hb_retptr((CvCapture *)cvCreateCameraCapture(hb_parni(1)));
}

/*
CVAPI(int) cvGrabFrame( CvCapture* capture )
*/
HB_FUNC(CVGRABFRAME)
{
  hb_retni(cvGrabFrame((CvCapture *)hb_parptr(1)));
}

/*
CVAPI(IplImage*) cvRetrieveFrame( CvCapture* capture, int streamIdx CV_DEFAULT(0) )
*/
HB_FUNC(CVRETRIEVEFRAME)
{
  hb_retptr((IplImage *)cvRetrieveFrame((CvCapture *)hb_parptr(1), HB_ISNIL(2) ? 0 : hb_parni(2)));
}

/*
CVAPI(IplImage*) cvQueryFrame( CvCapture* capture )
*/
HB_FUNC(CVQUERYFRAME)
{
  hb_retptr((IplImage *)cvQueryFrame((CvCapture *)hb_parptr(1)));
}

/*
CVAPI(void) cvReleaseCapture( CvCapture** capture )
*/
HB_FUNC(CVRELEASECAPTURE)
{
  CvCapture* capture = (CvCapture *)hb_parptr(1);
  cvReleaseCapture(&capture);
}

/*
CVAPI(double) cvGetCaptureProperty( CvCapture* capture, int property_id )
*/
HB_FUNC(CVGETCAPTUREPROPERTY)
{
  hb_retnd(cvGetCaptureProperty((CvCapture *)hb_parptr(1), hb_parni(2)));
}

/*
CVAPI(int) cvSetCaptureProperty( CvCapture* capture, int property_id, double value )
*/
HB_FUNC(CVSETCAPTUREPROPERTY)
{
  hb_retni(cvSetCaptureProperty((CvCapture *)hb_parptr(1), hb_parni(2), hb_parnd(3)));
}

/*
CVAPI(int) cvGetCaptureDomain( CvCapture* capture )
*/
HB_FUNC(CVGETCAPTUREDOMAIN)
{
  hb_retni(cvGetCaptureDomain((CvCapture *)hb_parptr(1)));
}

/*
CV_INLINE int CV_FOURCC( char c1, char c2, char c3, char c4 )
*/
HB_FUNC(CV_FOURCC)
{
  hb_retni(CV_FOURCC((char)hb_parni(1), (char)hb_parni(2), (char)hb_parni(3), (char)hb_parni(4)));
}

/*
CVAPI(CvVideoWriter*) cvCreateVideoWriter( const char* filename, int fourcc, double fps, CvSize frame_size, int is_color
CV_DEFAULT(1) )
*/
HB_FUNC(CVCREATEVIDEOWRITER)
{
  PHB_ITEM pSize4 = hb_param(4, HB_IT_ARRAY);
  CvSize size4;
  size4.width = hb_arrayGetNI(pSize4, 1);
  size4.height = hb_arrayGetNI(pSize4, 2);
  hb_retptr(
      (CvVideoWriter *)cvCreateVideoWriter(hb_parc(1), hb_parni(2), hb_parnd(3), size4, HB_ISNIL(5) ? 1 : hb_parni(5)));
}

/*
CVAPI(int) cvWriteFrame( CvVideoWriter* writer, const IplImage* image )
*/
HB_FUNC(CVWRITEFRAME)
{
  hb_retni(cvWriteFrame((CvVideoWriter *)hb_parptr(1), (const IplImage *)hb_parptr(2)));
}

/*
CVAPI(void) cvReleaseVideoWriter( CvVideoWriter** writer )
*/
HB_FUNC(CVRELEASEVIDEOWRITER)
{
  CvVideoWriter* writer = (CvVideoWriter *)hb_parptr(1);
  cvReleaseVideoWriter(&writer);
}
