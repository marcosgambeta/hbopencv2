//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/imgproc/imgproc_c.h>
#include <hbapi.h>
#include <hbapiitm.h>
#include <hbapierr.h>
#include "hbopencv2.hpp"

// CVAPI(void) cvAcc( const CvArr* image, CvArr* sum, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVACC)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)))
  {
    cvAcc(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_cpar_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSquareAcc( const CvArr* image, CvArr* sqsum, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSQUAREACC)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)))
  {
    cvSquareAcc(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_cpar_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMultiplyAcc( const CvArr* image1, const CvArr* image2, CvArr* acc, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVMULTIPLYACC)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) &&
      (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvMultiplyAcc(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRunningAvg( const CvArr* image, CvArr* acc, double alpha, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVRUNNINGAVG)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) &&
      (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvRunningAvg(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCopyMakeBorder( const CvArr* src, CvArr* dst, CvPoint offset, int bordertype, CvScalar value
// CV_DEFAULT(cvScalarAll(0)) )
HB_FUNC(CVCOPYMAKEBORDER)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISARRAY(1) && HB_ISNUM(4) &&
      (HB_ISARRAY(5) || HB_ISNIL(5)))
  {
    PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
    CvPoint point3;
    point3.x = hb_arrayGetNI(pPoint3, 1);
    point3.y = hb_arrayGetNI(pPoint3, 2);
    PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
    CvScalar scalar5;
    scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
    scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
    scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
    scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
    cvCopyMakeBorder(cv_cpar_CvArr(1), cv_par_CvArr(2), point3, cv_par_int(4), HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSmooth( const CvArr* src, CvArr* dst, int smoothtype CV_DEFAULT(CV_GAUSSIAN), int size1 CV_DEFAULT(3),
// int size2 CV_DEFAULT(0), double sigma1 CV_DEFAULT(0), double sigma2 CV_DEFAULT(0) )
HB_FUNC(CVSMOOTH)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 7 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)) &&
      (HB_ISNUM(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)) &&
      (HB_ISNUM(7) || HB_ISNIL(7)))
  {
    cvSmooth(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_GAUSSIAN), cv_dpar_int(4, 3), cv_dpar_int(5, 0),
             cv_dpar_double(6, 0), cv_dpar_double(7, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvIntegral( const CvArr* image, CvArr* sum, CvArr* sqsum CV_DEFAULT(NULL), CvArr* tilted_sum
// CV_DEFAULT(NULL) )
HB_FUNC(CVINTEGRAL)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)) &&
      (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvIntegral(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_par_CvArr(3),
               HB_ISNIL(4) ? NULL : cv_par_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvPyrDown( const CvArr* src, CvArr* dst, int filter CV_DEFAULT(CV_GAUSSIAN_5x5) )
HB_FUNC(CVPYRDOWN)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cvPyrDown(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_GAUSSIAN_5x5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvPyrUp( const CvArr* src, CvArr* dst, int filter CV_DEFAULT(CV_GAUSSIAN_5x5) )
HB_FUNC(CVPYRUP)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cvPyrUp(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_GAUSSIAN_5x5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleasePyramid( CvMat*** pyramid, int extra_layers )
HB_FUNC(CVRELEASEPYRAMID) // TODO: fix
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(1))
  {
    cvReleasePyramid((CvMat ***)hb_parptr(1), cv_par_int(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWatershed( const CvArr* image, CvArr* markers )
HB_FUNC(CVWATERSHED)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvWatershed(cv_cpar_CvArr(1), cv_par_CvArr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSobel( const CvArr* src, CvArr* dst, int xorder, int yorder, int aperture_size CV_DEFAULT(3) )
HB_FUNC(CVSOBEL)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISNUM(4) &&
      (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    cvSobel(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_par_int(4), cv_dpar_int(5, 3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvLaplace( const CvArr* src, CvArr* dst, int aperture_size CV_DEFAULT(3) )
HB_FUNC(CVLAPLACE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cvLaplace(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, 3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCvtColor( const CvArr* src, CvArr* dst, int code )
HB_FUNC(CVCVTCOLOR)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3))
  {
    cvCvtColor(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvResize( const CvArr* src, CvArr* dst, int interpolation CV_DEFAULT(CV_INTER_LINEAR) )
HB_FUNC(CVRESIZE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cvResize(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_INTER_LINEAR));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWarpAffine( const CvArr* src, CvArr* dst, const CvMat* map_matrix, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
HB_FUNC(CVWARPAFFINE)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) &&
      (HB_ISNUM(4) || HB_ISNIL(4)) && (HB_ISARRAY(5) || HB_ISNIL(5)))
  {
    PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
    CvScalar scalar5;
    scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
    scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
    scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
    scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
    cvWarpAffine(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3),
                 cv_dpar_int(4, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS), HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cv2DRotationMatrix( CvPoint2D32f center, double angle, double scale, CvMat* map_matrix )
HB_FUNC(CV2DROTATIONMATRIX)
{
  if (hb_pcount() == 4 && HB_ISARRAY(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISPOINTER(4))
  {
    PHB_ITEM pPoint2D32f1 = hb_param(1, HB_IT_ARRAY);
    CvPoint2D32f point2D32f1;
    point2D32f1.x = (float)hb_arrayGetND(pPoint2D32f1, 1);
    point2D32f1.y = (float)hb_arrayGetND(pPoint2D32f1, 2);
    cv_ret_CvMat(cv2DRotationMatrix(point2D32f1, cv_par_double(2), cv_par_double(3), cv_par_CvMat(4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWarpPerspective( const CvArr* src, CvArr* dst, const CvMat* map_matrix, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
HB_FUNC(CVWARPPERSPECTIVE)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) &&
      (HB_ISNUM(4) || HB_ISNIL(4)) && (HB_ISARRAY(5) || HB_ISNIL(5)))
  {
    PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
    CvScalar scalar5;
    scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
    scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
    scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
    scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
    cvWarpPerspective(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3),
                      cv_dpar_int(4, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS), HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRemap( const CvArr* src, CvArr* dst, const CvArr* mapx, const CvArr* mapy, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
HB_FUNC(CVREMAP)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) &&
      HB_ISPOINTER(4) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISARRAY(6) || HB_ISNIL(6)))
  {
    PHB_ITEM pScalar6 = hb_param(6, HB_IT_ARRAY);
    CvScalar scalar6;
    scalar6.val[0] = hb_arrayGetND(pScalar6, 1);
    scalar6.val[1] = hb_arrayGetND(pScalar6, 2);
    scalar6.val[2] = hb_arrayGetND(pScalar6, 3);
    scalar6.val[3] = hb_arrayGetND(pScalar6, 4);
    cvRemap(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvArr(3), cv_cpar_CvArr(4),
            cv_dpar_int(5, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS), HB_ISNIL(6) ? cvScalarAll(0) : scalar6);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvConvertMaps( const CvArr* mapx, const CvArr* mapy, CvArr* mapxy, CvArr* mapalpha )
HB_FUNC(CVCONVERTMAPS)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4))
  {
    cvConvertMaps(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvLogPolar( const CvArr* src, CvArr* dst, CvPoint2D32f center, double M, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS) )
HB_FUNC(CVLOGPOLAR)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISARRAY(3) && HB_ISNUM(4) &&
      (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
    CvPoint2D32f point2D32f3;
    point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
    point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
    cvLogPolar(cv_cpar_CvArr(1), cv_par_CvArr(2), point2D32f3, cv_par_double(4),
               cv_dpar_int(5, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvLinearPolar( const CvArr* src, CvArr* dst, CvPoint2D32f center, double maxRadius, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS) )
HB_FUNC(CVLINEARPOLAR)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISARRAY(3) && HB_ISNUM(4) &&
      (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
    CvPoint2D32f point2D32f3;
    point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
    point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
    cvLinearPolar(cv_cpar_CvArr(1), cv_par_CvArr(2), point2D32f3, cv_par_double(4),
                  cv_dpar_int(5, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvUndistort2( const CvArr* src, CvArr* dst, const CvMat* camera_matrix, const CvMat* distortion_coeffs,
// const CvMat* new_camera_matrix CV_DEFAULT(0) )
HB_FUNC(CVUNDISTORT2)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) &&
      HB_ISPOINTER(4) && (HB_ISPOINTER(5) || HB_ISNIL(5)))
  {
    cvUndistort2(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3), cv_cpar_CvMat(4),
                 HB_ISNIL(5) ? 0 : cv_cpar_CvMat(5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvInitUndistortMap( const CvMat* camera_matrix, const CvMat* distortion_coeffs, CvArr* mapx, CvArr* mapy
// )
HB_FUNC(CVINITUNDISTORTMAP)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4))
  {
    cvInitUndistortMap(cv_cpar_CvMat(1), cv_cpar_CvMat(2), cv_par_CvArr(3), cv_par_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvInitUndistortRectifyMap( const CvMat* camera_matrix, const CvMat* dist_coeffs, const CvMat* R, const
// CvMat* new_camera_matrix, CvArr* mapx, CvArr* mapy )
HB_FUNC(CVINITUNDISTORTRECTIFYMAP)
{
  if (hb_pcount() == 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4) && HB_ISPOINTER(5) &&
      HB_ISPOINTER(6))
  {
    cvInitUndistortRectifyMap(cv_cpar_CvMat(1), cv_cpar_CvMat(2), cv_cpar_CvMat(3), cv_cpar_CvMat(4), cv_par_CvArr(5),
                              cv_par_CvArr(6));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvUndistortPoints( const CvMat* src, CvMat* dst, const CvMat* camera_matrix, const CvMat* dist_coeffs,
// const CvMat* R CV_DEFAULT(0), const CvMat* P CV_DEFAULT(0) )
HB_FUNC(CVUNDISTORTPOINTS)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) &&
      HB_ISPOINTER(4) && (HB_ISPOINTER(5) || HB_ISNIL(5)) && (HB_ISPOINTER(6) || HB_ISNIL(6)))
  {
    cvUndistortPoints(cv_cpar_CvMat(1), cv_par_CvMat(2), cv_cpar_CvMat(3), cv_cpar_CvMat(4),
                      HB_ISNIL(5) ? 0 : cv_cpar_CvMat(5), HB_ISNIL(6) ? 0 : cv_cpar_CvMat(6));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseStructuringElement( IplConvKernel** element )
HB_FUNC(CVRELEASESTRUCTURINGELEMENT)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    IplConvKernel *element = cv_par_IplConvKernel(1);
    cvReleaseStructuringElement(&element);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvErode( const CvArr* src, CvArr* dst, IplConvKernel* element CV_DEFAULT(NULL), int iterations
// CV_DEFAULT(1) )
HB_FUNC(CVERODE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)) &&
      (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvErode(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_par_IplConvKernel(3), cv_dpar_int(4, 1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvDilate( const CvArr* src, CvArr* dst, IplConvKernel* element CV_DEFAULT(NULL), int iterations
// CV_DEFAULT(1) )
HB_FUNC(CVDILATE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)) &&
      (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvDilate(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_par_IplConvKernel(3), cv_dpar_int(4, 1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMorphologyEx( const CvArr* src, CvArr* dst, CvArr* temp, IplConvKernel* element, int operation, int
// iterations CV_DEFAULT(1) )
HB_FUNC(CVMORPHOLOGYEX)
{
  if (hb_pcount() >= 5 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) &&
      HB_ISPOINTER(4) && HB_ISNUM(5) && (HB_ISNUM(6) || HB_ISNIL(6)))
  {
    cvMorphologyEx(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_CvArr(3), cv_par_IplConvKernel(4), cv_par_int(5),
                   cv_dpar_int(6, 1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSampleLine( const CvArr* image, CvPoint pt1, CvPoint pt2, void* buffer, int connectivity CV_DEFAULT(8) )
HB_FUNC(CVSAMPLELINE)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISARRAY(3) && HB_ISPOINTER(4) &&
      (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
    CvPoint point2;
    point2.x = hb_arrayGetNI(pPoint2, 1);
    point2.y = hb_arrayGetNI(pPoint2, 2);
    PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
    CvPoint point3;
    point3.x = hb_arrayGetNI(pPoint3, 1);
    point3.y = hb_arrayGetNI(pPoint3, 2);
    cv_ret_int(cvSampleLine(cv_cpar_CvArr(1), point2, point3, cv_par_voidptr(4), cv_dpar_int(5, 8)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvGetRectSubPix( const CvArr* src, CvArr* dst, CvPoint2D32f center )
HB_FUNC(CVGETRECTSUBPIX)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISARRAY(3))
  {
    PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
    CvPoint2D32f point2D32f3;
    point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
    point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
    cvGetRectSubPix(cv_cpar_CvArr(1), cv_par_CvArr(2), point2D32f3);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvGetQuadrangleSubPix( const CvArr* src, CvArr* dst, const CvMat* map_matrix )
HB_FUNC(CVGETQUADRANGLESUBPIX)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvGetQuadrangleSubPix(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMatchTemplate( const CvArr* image, const CvArr* templ, CvArr* result, int method )
HB_FUNC(CVMATCHTEMPLATE)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISNUM(4))
  {
    cvMatchTemplate(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_int(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvApproxChains( CvSeq* src_seq, CvMemStorage* storage, int method CV_DEFAULT(CV_CHAIN_APPROX_SIMPLE),
// double parameter CV_DEFAULT(0), int minimal_perimeter CV_DEFAULT(0), int recursive CV_DEFAULT(0) )
HB_FUNC(CVAPPROXCHAINS)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)) &&
      (HB_ISNUM(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)))
  {
    cv_ret_CvSeq(cvApproxChains(cv_par_CvSeq(1), cv_par_CvMemStorage(2), cv_dpar_int(3, CV_CHAIN_APPROX_SIMPLE),
                                cv_dpar_double(4, 0), cv_dpar_int(5, 0), cv_dpar_int(6, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvApproxPoly( const void* src_seq, int header_size, CvMemStorage* storage, int method, double eps, int
// recursive CV_DEFAULT(0) )
HB_FUNC(CVAPPROXPOLY)
{
  if (hb_pcount() >= 5 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISPOINTER(3) && HB_ISNUM(4) &&
      HB_ISNUM(5) && (HB_ISNUM(6) || HB_ISNIL(6)))
  {
    cv_ret_CvSeq(cvApproxPoly(cv_cpar_voidptr(1), cv_par_int(2), cv_par_CvMemStorage(3), cv_par_int(4),
                              cv_par_double(5), cv_dpar_int(6, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvArcLength( const void* curve, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ), int is_closed CV_DEFAULT(-1) )
HB_FUNC(CVARCLENGTH)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 3 && HB_ISPOINTER(1) && (HB_ISARRAY(2) || HB_ISNIL(2)) &&
      (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
    CvSlice slice2;
    slice2.start_index = hb_arrayGetNI(pSlice2, 1);
    slice2.end_index = hb_arrayGetNI(pSlice2, 2);
    cv_ret_double(cvArcLength(cv_cpar_voidptr(1), HB_ISNIL(2) ? CV_WHOLE_SEQ : slice2, cv_dpar_int(3, -1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE double cvContourPerimeter( const void* contour )
HB_FUNC(CVCONTOURPERIMETER)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_double(cvContourPerimeter(cv_cpar_voidptr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvRect) cvBoundingRect( CvArr* points, int update CV_DEFAULT(0) )
HB_FUNC(CVBOUNDINGRECT)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2)))
  {
    CvRect rect;
    rect = cvBoundingRect(cv_par_CvArr(1), cv_dpar_int(2, 0));
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutNI(t, rect.x);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutNI(t, rect.y);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutNI(t, rect.width);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutNI(t, rect.height);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvContourArea( const CvArr* contour, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ), int oriented CV_DEFAULT(0)
// )
HB_FUNC(CVCONTOURAREA)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 3 && HB_ISPOINTER(1) && (HB_ISARRAY(2) || HB_ISNIL(2)) &&
      (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
    CvSlice slice2;
    slice2.start_index = hb_arrayGetNI(pSlice2, 1);
    slice2.end_index = hb_arrayGetNI(pSlice2, 2);
    cv_ret_double(cvContourArea(cv_cpar_CvArr(1), HB_ISNIL(2) ? CV_WHOLE_SEQ : slice2, cv_dpar_int(3, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvMatchShapes( const void* object1, const void* object2, int method, double parameter CV_DEFAULT(0) )
HB_FUNC(CVMATCHSHAPES)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) &&
      (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cv_ret_double(cvMatchShapes(cv_cpar_voidptr(1), cv_cpar_voidptr(2), cv_par_int(3), cv_dpar_double(4, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvConvexHull2( const CvArr* input, void* hull_storage CV_DEFAULT(NULL), int orientation
// CV_DEFAULT(CV_CLOCKWISE), int return_points CV_DEFAULT(0) )
HB_FUNC(CVCONVEXHULL2)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 4 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) || HB_ISNIL(2)) &&
      (HB_ISNUM(3) || HB_ISNIL(3)) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cv_ret_CvSeq(cvConvexHull2(cv_cpar_CvArr(1), HB_ISNIL(2) ? NULL : cv_par_voidptr(2),
                               cv_dpar_int(3, CV_CLOCKWISE), cv_dpar_int(4, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvCheckContourConvexity( const CvArr* contour )
HB_FUNC(CVCHECKCONTOURCONVEXITY)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvCheckContourConvexity(cv_cpar_CvArr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvConvexityDefects( const CvArr* contour, const CvArr* convexhull, CvMemStorage* storage
// CV_DEFAULT(NULL) )
HB_FUNC(CVCONVEXITYDEFECTS)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)))
  {
    cv_ret_CvSeq(
        cvConvexityDefects(cv_cpar_CvArr(1), cv_cpar_CvArr(2), HB_ISNIL(3) ? NULL : cv_par_CvMemStorage(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvPointPolygonTest( const CvArr* contour, CvPoint2D32f pt, int measure_dist )
HB_FUNC(CVPOINTPOLYGONTEST)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISNUM(3))
  {
    PHB_ITEM pPoint2D32f2 = hb_param(2, HB_IT_ARRAY);
    CvPoint2D32f point2D32f2;
    point2D32f2.x = (float)hb_arrayGetND(pPoint2D32f2, 1);
    point2D32f2.y = (float)hb_arrayGetND(pPoint2D32f2, 2);
    cv_ret_double(cvPointPolygonTest(cv_cpar_CvArr(1), point2D32f2, cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseHist( CvHistogram** hist )
HB_FUNC(CVRELEASEHIST)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvHistogram *hist = cv_par_CvHistogram(1);
    cvReleaseHist(&hist);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvClearHist( CvHistogram* hist )
HB_FUNC(CVCLEARHIST)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvClearHist(cv_par_CvHistogram(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvNormalizeHist( CvHistogram* hist, double factor )
HB_FUNC(CVNORMALIZEHIST)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cvNormalizeHist(cv_par_CvHistogram(1), cv_par_double(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvThreshHist( CvHistogram* hist, double threshold )
HB_FUNC(CVTHRESHHIST)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cvThreshHist(cv_par_CvHistogram(1), cv_par_double(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvCompareHist( const CvHistogram* hist1, const CvHistogram* hist2, int method )
HB_FUNC(CVCOMPAREHIST)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3))
  {
    cv_ret_double(cvCompareHist(cv_cpar_CvHistogram(1), cv_cpar_CvHistogram(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCopyHist( const CvHistogram* src, CvHistogram** dst )
HB_FUNC(CVCOPYHIST) // TODO: fix parameter 2
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvCopyHist(cv_cpar_CvHistogram(1), (CvHistogram **)hb_parptr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCalcBayesianProb( CvHistogram** src, int number, CvHistogram** dst )
HB_FUNC(CVCALCBAYESIANPROB) // TODO: fix parameters 1 and 3
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISPOINTER(3))
  {
    cvCalcBayesianProb((CvHistogram **)hb_parptr(1), cv_par_int(2), (CvHistogram **)hb_parptr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCalcArrHist( CvArr** arr, CvHistogram* hist, int accumulate CV_DEFAULT(0), const CvArr* mask
// CV_DEFAULT(NULL) )
HB_FUNC(CVCALCARRHIST) // TODO: fix parameter 1
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)) &&
      (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvCalcArrHist((CvArr **)hb_parptr(1), cv_par_CvHistogram(2), cv_dpar_int(3, 0),
                  HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE void cvCalcHist( IplImage** image, CvHistogram* hist, int accumulate CV_DEFAULT(0), const CvArr* mask
// CV_DEFAULT(NULL) )
HB_FUNC(CVCALCHIST) // TODO: fix parameter 1
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)) &&
      (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvCalcHist((IplImage **)hb_parptr(1), cv_par_CvHistogram(2), cv_dpar_int(3, 0),
               HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCalcArrBackProject( CvArr** image, CvArr* dst, const CvHistogram* hist )
HB_FUNC(CVCALCARRBACKPROJECT) // TODO: fix parameter 1
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvCalcArrBackProject((CvArr **)hb_parptr(1), cv_par_CvArr(2), cv_cpar_CvHistogram(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCalcArrBackProjectPatch( CvArr** image, CvArr* dst, CvSize range, CvHistogram* hist, int method, double
// factor )
HB_FUNC(CVCALCARRBACKPROJECTPATCH) // TODO: fix parameter 1
{
  if (hb_pcount() == 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISARRAY(3) && HB_ISPOINTER(4) && HB_ISNUM(5) &&
      HB_ISNUM(6))
  {
    PHB_ITEM pSize3 = hb_param(3, HB_IT_ARRAY);
    CvSize size3;
    size3.width = hb_arrayGetNI(pSize3, 1);
    size3.height = hb_arrayGetNI(pSize3, 2);
    cvCalcArrBackProjectPatch((CvArr **)hb_parptr(1), cv_par_CvArr(2), size3, cv_par_CvHistogram(4), cv_par_int(5),
                              cv_par_double(6));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCalcProbDensity( const CvHistogram* hist1, const CvHistogram* hist2, CvHistogram* dst_hist, double
// scale CV_DEFAULT(255) )
HB_FUNC(CVCALCPROBDENSITY)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) &&
      (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvCalcProbDensity(cv_cpar_CvHistogram(1), cv_cpar_CvHistogram(2), cv_par_CvHistogram(3), cv_dpar_double(4, 255));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvEqualizeHist( const CvArr* src, CvArr* dst )
HB_FUNC(CVEQUALIZEHIST)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvEqualizeHist(cv_cpar_CvArr(1), cv_par_CvArr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvThreshold( const CvArr* src, CvArr* dst, double threshold, double max_value, int threshold_type )
HB_FUNC(CVTHRESHOLD)
{
  if (hb_pcount() == 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISNUM(4) && HB_ISNUM(5))
  {
    cv_ret_double(cvThreshold(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3), cv_par_double(4), cv_par_int(5)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvAdaptiveThreshold( const CvArr* src, CvArr* dst, double max_value, int adaptive_method
// CV_DEFAULT(CV_ADAPTIVE_THRESH_MEAN_C), int threshold_type CV_DEFAULT(CV_THRESH_BINARY), int block_size CV_DEFAULT(3),
// double param1 CV_DEFAULT(5) )
HB_FUNC(CVADAPTIVETHRESHOLD)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 7 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) &&
      (HB_ISNUM(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)) &&
      (HB_ISNUM(7) || HB_ISNIL(7)))
  {
    cvAdaptiveThreshold(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3), cv_dpar_int(4, CV_ADAPTIVE_THRESH_MEAN_C),
                        cv_dpar_int(5, CV_THRESH_BINARY), cv_dpar_int(6, 3), cv_dpar_double(7, 5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCanny( const CvArr* image, CvArr* edges, double threshold1, double threshold2, int aperture_size
// CV_DEFAULT(3) )
HB_FUNC(CVCANNY)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISNUM(4) &&
      (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    cvCanny(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3), cv_par_double(4), cv_dpar_int(5, 3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvPreCornerDetect( const CvArr* image, CvArr* corners, int aperture_size CV_DEFAULT(3) )
HB_FUNC(CVPRECORNERDETECT)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cvPreCornerDetect(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, 3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCornerEigenValsAndVecs( const CvArr* image, CvArr* eigenvv, int block_size, int aperture_size
// CV_DEFAULT(3) )
HB_FUNC(CVCORNEREIGENVALSANDVECS)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) &&
      (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvCornerEigenValsAndVecs(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_dpar_int(4, 3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCornerMinEigenVal( const CvArr* image, CvArr* eigenval, int block_size, int aperture_size CV_DEFAULT(3)
// )
HB_FUNC(CVCORNERMINEIGENVAL)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) &&
      (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvCornerMinEigenVal(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_dpar_int(4, 3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCornerHarris( const CvArr* image, CvArr* harris_response, int block_size, int aperture_size
// CV_DEFAULT(3), double k CV_DEFAULT(0.04) )
HB_FUNC(CVCORNERHARRIS)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) &&
      (HB_ISNUM(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    cvCornerHarris(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_dpar_int(4, 3), cv_dpar_double(5, 0.04));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvHoughLines2( CvArr* image, void* line_storage, int method, double rho, double theta, int threshold,
// double param1 CV_DEFAULT(0), double param2 CV_DEFAULT(0) )
HB_FUNC(CVHOUGHLINES2)
{
  if (hb_pcount() >= 6 && hb_pcount() <= 8 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISNUM(4) &&
      HB_ISNUM(5) && HB_ISNUM(6) && (HB_ISNUM(7) || HB_ISNIL(7)) && (HB_ISNUM(8) || HB_ISNIL(8)))
  {
    cv_ret_CvSeq(cvHoughLines2(cv_par_CvArr(1), cv_par_voidptr(2), cv_par_int(3), cv_par_double(4), cv_par_double(5),
                               cv_par_int(6), cv_dpar_double(7, 0), cv_dpar_double(8, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvHoughCircles( CvArr* image, void* circle_storage, int method, double dp, double min_dist, double
// param1 CV_DEFAULT(100), double param2 CV_DEFAULT(100), int min_radius CV_DEFAULT(0), int max_radius CV_DEFAULT(0) )
HB_FUNC(CVHOUGHCIRCLES)
{
  if (hb_pcount() >= 5 && hb_pcount() <= 9 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISNUM(4) &&
      HB_ISNUM(5) && (HB_ISNUM(6) || HB_ISNIL(6)) && (HB_ISNUM(7) || HB_ISNIL(7)) && (HB_ISNUM(8) || HB_ISNIL(8)) &&
      (HB_ISNUM(9) || HB_ISNIL(9)))
  {
    cv_ret_CvSeq(cvHoughCircles(cv_par_CvArr(1), cv_par_voidptr(2), cv_par_int(3), cv_par_double(4), cv_par_double(5),
                                cv_dpar_double(6, 100), cv_dpar_double(7, 100), cv_dpar_int(8, 0), cv_dpar_int(9, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}
