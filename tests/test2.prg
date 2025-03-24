//
// hbopencv2 test
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

// Compile with:
// hbmk2 test2 \path_to_hbopencv2\hbopencv2.hbc

// Before run the test, create a file named test2.txt with the video URL

#include "opencv.ch"

REQUEST hb_gt_win_default

FUNCTION Main()

   LOCAL videoURL
   LOCAL capture
   LOCAL frameWidth
   LOCAL frameHeight
   LOCAL frame

   CLS

   // get the URL of the video
   videoURL := MemoRead("test2.txt")
   ? "videoURL=", videoURL
   WAIT

   // open video stream
   capture := cvCreateFileCapture(videoURL)
   ? "capture=", capture

   // check if the video stream was opened successfully
   IF Empty(capture)
      ? "Error: Could not open video stream from URL."
      RETURN -1
   ENDIF

   // get video width and height for displaying the video
   frameWidth := cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH)
   ? "frameWidth=", frameWidth
   frameHeight := cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
   ? "frameHeight=", frameHeight

   // create a window to display the video
   cvNamedWindow("Video from URL", CV_WINDOW_AUTOSIZE)

   DO WHILE .T.
      // capture frame-by-frame
      frame := cvQueryFrame(capture)

      // if the frame is empty, break the loop
      IF Empty(frame)
         ? "Error: Could not grab a frame."
         EXIT
      ENDIF

      // display the resulting frame
      cvShowImage("Video from URL", frame)

      // wait for 30ms, break the loop if user presses 'q'
      IF cvWaitKey(30) == Asc("q")
         EXIT
      ENDIF
   ENDDO

   // release the capture object and destroy all windows
   cvReleaseCapture(capture)
   cvDestroyAllWindows()

RETURN 0
