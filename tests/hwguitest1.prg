//
// hbopencv2 test
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

// Compile with:
// hbmk2 hwguitest1 \path_to_hbopencv2\hbopencv2.hbc \path_to_hwgui\hwgui.hbc

#include "hwgui.ch"
#include "opencv.ch"

STATIC nCount := 0

PROCEDURE Main()

   LOCAL oDialog
   LOCAL oTimer
   LOCAL pCapture

   pCapture := cvCreateCameraCapture(CV_CAP_ANY)

   cvNamedWindow("camera")

   INIT DIALOG oDialog TITLE "HWGUI + OpenCV" SIZE 800, 600 ON INIT {||Initialize(oDialog)}

   @ 800 - 150, 20 BUTTON "&Capture" SIZE 130,40 ON CLICK {||Capture(pCapture)}

   @ 800 - 150, 80 BUTTON "&Show" SIZE 130,40 ON CLICK {||Show()}

   @ 800 - 150, 140 BUTTON "C&lose" SIZE 130,40 ON CLICK {||oDialog:close()}

   SET TIMER oTimer OF oDialog VALUE 30 ACTION {||UpdateCamera(pCapture)}

   ACTIVATE DIALOG oDialog

   cvReleaseCapture(pCapture)

   cvDestroyWindow("camera")

RETURN

STATIC FUNCTION Initialize(oDialog)

   LOCAL pWnd
   LOCAL pParent

   // get the handle of the camera window
   pWnd := cvGetWindowHandle("camera")

   // get the parent of the window
   pParent := hwg_GetParent(pWnd)

   // set the dialog as the parent of the camera window
   SetParent(pWnd, oDialog:handle)

   // hide the original parent of the camera window
   hwg_ShowWindow(pParent, SW_HIDE)

RETURN NIL

STATIC FUNCTION Capture(pCapture)

   LOCAL pFrame

   IF cvGrabFrame(pCapture) == 1

      pFrame := cvRetrieveFrame(pCapture)

      IF !Empty(pFrame)
         ++nCount
         cvSaveImage("captura" + AllTrim(Str(nCount)) + ".jpg", pFrame)
      ENDIF

   ELSE

      hwg_MsgInfo("Error while capturing the camera image")

   ENDIF

RETURN NIL

STATIC FUNCTION Show()

   LOCAL cWindow
   LOCAL pImage

   cWindow := "window" + AllTrim(Str(nCount))

   cvNamedWindow(cWindow)

   pImage := cvLoadImage("capture" + AllTrim(Str(nCount)) + ".jpg")

   cvShowImage(cWindow, pImage)

   cvWaitKey()

   cvDestroyWindow(cWindow)

RETURN NIL

STATIC FUNCTION UpdateCamera(pCapture)

   LOCAL pFrame

   IF cvGrabFrame(pCapture) == 1

      pFrame := cvQueryFrame(pCapture)

      IF !Empty(pFrame)
         cvShowImage("camera", pFrame)
      ENDIF

   ENDIF

RETURN NIL

#pragma BEGINDUMP

#include <hbapi.h>
#include <windows.h>

#ifndef _WIN32_WINNT
   #define _WIN32_WINNT   0x0502
#endif

// HWND SetParent( [in] HWND hWndChild, [in, optional] HWND hWndNewParent )
HB_FUNC_STATIC(SETPARENT)
{
  hb_retptr((HWND)SetParent((HWND)hb_parptr(1), ISNIL(2) ? NULL : (HWND)hb_parptr(2)));
}

#pragma ENDDUMP
