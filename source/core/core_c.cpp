//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/core/core_c.h>
#include <hbapi.h>
#include <hbapiitm.h>
#include <hbapierr.h>
#include "hbopencv2.hpp"

// CVAPI(void*) cvAlloc( size_t size )
HB_FUNC(CVALLOC)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    cv_ret_voidptr(cvAlloc(cv_par_size_t(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvFree_( void* ptr )
HB_FUNC(CVFREE_)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvFree_(cv_par_voidptr(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvCreateImageHeader( CvSize size, int depth, int channels )
HB_FUNC(CVCREATEIMAGEHEADER)
{
  if (hb_pcount() == 3 && HB_ISARRAY(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    PHB_ITEM pSize1 = hb_param(1, HB_IT_ARRAY);
    CvSize size1;
    size1.width = hb_arrayGetNI(pSize1, 1);
    size1.height = hb_arrayGetNI(pSize1, 2);
    cv_ret_IplImage(cvCreateImageHeader(size1, cv_par_int(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvInitImageHeader( IplImage* image, CvSize size, int depth, int channels, int origin CV_DEFAULT(0),
// int align CV_DEFAULT(4) )
HB_FUNC(CVINITIMAGEHEADER)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISNUM(3) && HB_ISNUM(4) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)))
  {
    PHB_ITEM pSize2 = hb_param(2, HB_IT_ARRAY);
    CvSize size2;
    size2.width = hb_arrayGetNI(pSize2, 1);
    size2.height = hb_arrayGetNI(pSize2, 2);
    cv_ret_IplImage(
        cvInitImageHeader(cv_par_IplImage(1), size2, cv_par_int(3), cv_par_int(4), cv_dpar_int(5, 0), cv_dpar_int(6, 4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvCreateImage( CvSize size, int depth, int channels )
HB_FUNC(CVCREATEIMAGE)
{
  if (hb_pcount() == 3 && HB_ISARRAY(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    PHB_ITEM pSize1 = hb_param(1, HB_IT_ARRAY);
    CvSize size1;
    size1.width = hb_arrayGetNI(pSize1, 1);
    size1.height = hb_arrayGetNI(pSize1, 2);
    cv_ret_IplImage(cvCreateImage(size1, cv_par_int(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseImageHeader( IplImage** image )
HB_FUNC(CVRELEASEIMAGEHEADER)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    IplImage *image = cv_par_IplImage(1);
    cvReleaseImageHeader(&image);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseImage( IplImage** image )
HB_FUNC(CVRELEASEIMAGE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    IplImage *image = cv_par_IplImage(1);
    cvReleaseImage(&image);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvCloneImage( const IplImage* image )
HB_FUNC(CVCLONEIMAGE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_IplImage(cvCloneImage(cv_cpar_IplImage(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetImageCOI( IplImage* image, int coi )
HB_FUNC(CVSETIMAGECOI)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cvSetImageCOI(cv_par_IplImage(1), cv_par_int(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetImageCOI( const IplImage* image )
HB_FUNC(CVGETIMAGECOI)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvGetImageCOI(cv_cpar_IplImage(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetImageROI( IplImage* image, CvRect rect )
HB_FUNC(CVSETIMAGEROI)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISARRAY(2))
  {
    PHB_ITEM pRect2 = hb_param(2, HB_IT_ARRAY);
    CvRect rect2;
    rect2.x = hb_arrayGetNI(pRect2, 1);
    rect2.y = hb_arrayGetNI(pRect2, 2);
    rect2.width = hb_arrayGetNI(pRect2, 3);
    rect2.height = hb_arrayGetNI(pRect2, 4);
    cvSetImageROI(cv_par_IplImage(1), rect2);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvResetImageROI( IplImage* image )
HB_FUNC(CVRESETIMAGEROI)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvResetImageROI(cv_par_IplImage(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvRect) cvGetImageROI( const IplImage* image )
HB_FUNC(CVGETIMAGEROI)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvRect rect;
    rect = cvGetImageROI(cv_cpar_IplImage(1));
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

// CVAPI(CvMat*) cvCreateMatHeader( int rows, int cols, int type )
HB_FUNC(CVCREATEMATHEADER)
{
  if (hb_pcount() == 3 && HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    cv_ret_CvMat(cvCreateMatHeader(cv_par_int(1), cv_par_int(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvInitMatHeader( CvMat* mat, int rows, int cols, int type, void* data CV_DEFAULT(NULL), int step
// CV_DEFAULT(CV_AUTOSTEP) )
HB_FUNC(CVINITMATHEADER)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4) && (HB_ISPOINTER(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)))
  {
    cv_ret_CvMat(cvInitMatHeader(cv_par_CvMat(1), cv_par_int(2), cv_par_int(3), cv_par_int(4), cv_dpar_voidptr(5, NULL),
                                 cv_dpar_int(6, CV_AUTOSTEP)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvCreateMat( int rows, int cols, int type )
HB_FUNC(CVCREATEMAT)
{
  if (hb_pcount() == 3 && HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    cv_ret_CvMat(cvCreateMat(cv_par_int(1), cv_par_int(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseMat( CvMat** mat )
HB_FUNC(CVRELEASEMAT)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvMat *mat = cv_par_CvMat(1);
    cvReleaseMat(&mat);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE void cvDecRefData( CvArr* arr )
HB_FUNC(CVDECREFDATA)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvDecRefData(cv_par_CvArr(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE int cvIncRefData( CvArr* arr )
HB_FUNC(CVINCREFDATA)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvIncRefData(cv_par_CvArr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvCloneMat( const CvMat* mat )
HB_FUNC(CVCLONEMAT)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_CvMat(cvCloneMat(cv_cpar_CvMat(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvGetSubRect( const CvArr* arr, CvMat* submat, CvRect rect )
HB_FUNC(CVGETSUBRECT)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISARRAY(3))
  {
    PHB_ITEM pRect3 = hb_param(3, HB_IT_ARRAY);
    CvRect rect3;
    rect3.x = hb_arrayGetNI(pRect3, 1);
    rect3.y = hb_arrayGetNI(pRect3, 2);
    rect3.width = hb_arrayGetNI(pRect3, 3);
    rect3.height = hb_arrayGetNI(pRect3, 4);
    cv_ret_CvMat(cvGetSubRect(cv_cpar_CvArr(1), cv_par_CvMat(2), rect3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvGetRows( const CvArr* arr, CvMat* submat, int start_row, int end_row, int delta_row CV_DEFAULT(1) )
HB_FUNC(CVGETROWS)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISNUM(4) && (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    cv_ret_CvMat(cvGetRows(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3), cv_par_int(4), cv_dpar_int(5, 1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE CvMat* cvGetRow( const CvArr* arr, CvMat* submat, int row )
HB_FUNC(CVGETROW)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3))
  {
    cv_ret_CvMat(cvGetRow(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvGetCols( const CvArr* arr, CvMat* submat, int start_col, int end_col )
HB_FUNC(CVGETCOLS)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISNUM(4))
  {
    cv_ret_CvMat(cvGetCols(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3), cv_par_int(4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE CvMat* cvGetCol( const CvArr* arr, CvMat* submat, int col )
HB_FUNC(CVGETCOL)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3))
  {
    cv_ret_CvMat(cvGetCol(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvGetDiag( const CvArr* arr, CvMat* submat, int diag CV_DEFAULT(0) )
HB_FUNC(CVGETDIAG)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cv_ret_CvMat(cvGetDiag(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_dpar_int(3, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMatND*) cvCreateMatNDHeader( int dims, const int* sizes, int type )
HB_FUNC(CVCREATEMATNDHEADER)
{
  if (hb_pcount() == 3 && HB_ISNUM(1) && HB_ISARRAY(2) && HB_ISNUM(3))
  {
    PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
    int *values2 = NULL;
    if (a2)
    {
      const int lenght = hb_arrayLen(a2);
      values2 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values2[i] = hb_arrayGetNI(a2, i + 1);
      }
    }
    cv_ret_CvMatND(cvCreateMatNDHeader(cv_par_int(1), (const int *)values2, cv_par_int(3)));
    if (a2)
    {
      delete[] values2;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMatND*) cvCreateMatND( int dims, const int* sizes, int type )
HB_FUNC(CVCREATEMATND)
{
  if (hb_pcount() == 3 && HB_ISNUM(1) && HB_ISARRAY(2) && HB_ISNUM(3))
  {
    PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
    int *values2 = NULL;
    if (a2)
    {
      const int lenght = hb_arrayLen(a2);
      values2 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values2[i] = hb_arrayGetNI(a2, i + 1);
      }
    }
    cv_ret_CvMatND(cvCreateMatND(cv_par_int(1), (const int *)values2, cv_par_int(3)));
    if (a2)
    {
      delete[] values2;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMatND*) cvInitMatNDHeader( CvMatND* mat, int dims, const int* sizes, int type, void* data CV_DEFAULT(NULL) )
HB_FUNC(CVINITMATNDHEADER)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISARRAY(3) && HB_ISNUM(4) && (HB_ISPOINTER(5) || HB_ISNIL(5)))
  {
    PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
    int *values3 = NULL;
    if (a3)
    {
      const int lenght = hb_arrayLen(a3);
      values3 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values3[i] = hb_arrayGetNI(a3, i + 1);
      }
    }
    cv_ret_CvMatND(cvInitMatNDHeader(cv_par_CvMatND(1), cv_par_int(2), (const int *)values3, cv_par_int(4),
                                     cv_dpar_voidptr(5, NULL)));
    if (a3)
    {
      delete[] values3;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE void cvReleaseMatND( CvMatND** mat )
HB_FUNC(CVRELEASEMATND)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvMatND *mat = cv_par_CvMatND(1);
    cvReleaseMatND(&mat);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMatND*) cvCloneMatND( const CvMatND* mat )
HB_FUNC(CVCLONEMATND)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_CvMatND(cvCloneMatND(cv_cpar_CvMatND(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSparseMat*) cvCreateSparseMat( int dims, const int* sizes, int type )
HB_FUNC(CVCREATESPARSEMAT)
{
  if (hb_pcount() == 3 && HB_ISNUM(1) && HB_ISARRAY(2) && HB_ISNUM(3))
  {
    PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
    int *values2 = NULL;
    if (a2)
    {
      const int lenght = hb_arrayLen(a2);
      values2 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values2[i] = hb_arrayGetNI(a2, i + 1);
      }
    }
    cv_ret_CvSparseMat(cvCreateSparseMat(cv_par_int(1), (const int *)values2, cv_par_int(3)));
    if (a2)
    {
      delete[] values2;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseSparseMat( CvSparseMat** mat )
HB_FUNC(CVRELEASESPARSEMAT)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvSparseMat *mat = cv_par_CvSparseMat(1);
    cvReleaseSparseMat(&mat);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSparseMat*) cvCloneSparseMat( const CvSparseMat* mat )
HB_FUNC(CVCLONESPARSEMAT)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_CvSparseMat(cvCloneSparseMat(cv_cpar_CvSparseMat(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSparseNode*) cvInitSparseMatIterator( const CvSparseMat* mat, CvSparseMatIterator* mat_iterator )
HB_FUNC(CVINITSPARSEMATITERATOR)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cv_ret_CvSparseNode(cvInitSparseMatIterator(cv_cpar_CvSparseMat(1), cv_par_CvSparseMatIterator(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE CvSparseNode* cvGetNextSparseNode( CvSparseMatIterator* mat_iterator )
HB_FUNC(CVGETNEXTSPARSENODE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_CvSparseNode(cvGetNextSparseNode(cv_par_CvSparseMatIterator(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvInitNArrayIterator( int count, CvArr** arrs, const CvArr* mask, CvMatND* stubs, CvNArrayIterator*
// array_iterator, int flags CV_DEFAULT(0) )
HB_FUNC(CVINITNARRAYITERATOR) // TODO: fix parameter 2
{
  cv_ret_int(cvInitNArrayIterator(cv_par_int(1), (CvArr **)hb_parptr(2), cv_cpar_CvArr(3), cv_par_CvMatND(4),
                                  cv_par_CvNArrayIterator(5), cv_dpar_int(6, 0)));
}

// CVAPI(int) cvNextNArraySlice( CvNArrayIterator* array_iterator )
HB_FUNC(CVNEXTNARRAYSLICE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvNextNArraySlice(cv_par_CvNArrayIterator(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetElemType( const CvArr* arr )
HB_FUNC(CVGETELEMTYPE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvGetElemType(cv_cpar_CvArr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetDimSize( const CvArr* arr, int index )
HB_FUNC(CVGETDIMSIZE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cv_ret_int(cvGetDimSize(cv_cpar_CvArr(1), cv_par_int(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvScalar) cvGet1D( const CvArr* arr, int idx0 )
HB_FUNC(CVGET1D)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    CvScalar scalar;
    scalar = cvGet1D(cv_cpar_CvArr(1), cv_par_int(2));
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutND(t, scalar.val[0]);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutND(t, scalar.val[1]);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, scalar.val[2]);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutND(t, scalar.val[3]);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvScalar) cvGet2D( const CvArr* arr, int idx0, int idx1 )
HB_FUNC(CVGET2D)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    CvScalar scalar;
    scalar = cvGet2D(cv_cpar_CvArr(1), cv_par_int(2), cv_par_int(3));
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutND(t, scalar.val[0]);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutND(t, scalar.val[1]);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, scalar.val[2]);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutND(t, scalar.val[3]);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvScalar) cvGet3D( const CvArr* arr, int idx0, int idx1, int idx2 )
HB_FUNC(CVGET3D)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4))
  {
    CvScalar scalar;
    scalar = cvGet3D(cv_cpar_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_int(4));
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutND(t, scalar.val[0]);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutND(t, scalar.val[1]);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, scalar.val[2]);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutND(t, scalar.val[3]);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvScalar) cvGetND( const CvArr* arr, const int* idx )
HB_FUNC(CVGETND)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISARRAY(2))
  {
    CvScalar scalar;
    PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
    int *values2 = NULL;
    if (a2)
    {
      const int lenght = hb_arrayLen(a2);
      values2 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values2[i] = hb_arrayGetNI(a2, i + 1);
      }
    }
    scalar = cvGetND(cv_cpar_CvArr(1), (const int *)values2);
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutND(t, scalar.val[0]);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutND(t, scalar.val[1]);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, scalar.val[2]);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutND(t, scalar.val[3]);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
    if (a2)
    {
      delete[] values2;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvGetReal1D( const CvArr* arr, int idx0 )
HB_FUNC(CVGETREAL1D)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cv_ret_double(cvGetReal1D(cv_cpar_CvArr(1), cv_par_int(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvGetReal2D( const CvArr* arr, int idx0, int idx1 )
HB_FUNC(CVGETREAL2D)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    cv_ret_double(cvGetReal2D(cv_cpar_CvArr(1), cv_par_int(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvGetReal3D( const CvArr* arr, int idx0, int idx1, int idx2 )
HB_FUNC(CVGETREAL3D)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4))
  {
    cv_ret_double(cvGetReal3D(cv_cpar_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_int(4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvGetRealND( const CvArr* arr, const int* idx )
HB_FUNC(CVGETREALND)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISARRAY(2))
  {
    PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
    int *values2 = NULL;
    if (a2)
    {
      const int lenght = hb_arrayLen(a2);
      values2 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values2[i] = hb_arrayGetNI(a2, i + 1);
      }
    }
    cv_ret_double(cvGetRealND(cv_cpar_CvArr(1), (const int *)values2));
    if (a2)
    {
      delete[] values2;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSet1D( CvArr* arr, int idx0, CvScalar value )
HB_FUNC(CVSET1D)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISARRAY(3))
  {
    PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
    CvScalar scalar3;
    scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
    scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
    scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
    scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
    cvSet1D(cv_par_CvArr(1), cv_par_int(2), scalar3);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSet2D( CvArr* arr, int idx0, int idx1, CvScalar value )
HB_FUNC(CVSET2D)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISARRAY(4))
  {
    PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
    CvScalar scalar4;
    scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
    scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
    scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
    scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
    cvSet2D(cv_par_CvArr(1), cv_par_int(2), cv_par_int(3), scalar4);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSet3D( CvArr* arr, int idx0, int idx1, int idx2, CvScalar value )
HB_FUNC(CVSET3D)
{
  if (hb_pcount() == 5 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4) && HB_ISARRAY(5))
  {
    PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
    CvScalar scalar5;
    scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
    scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
    scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
    scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
    cvSet3D(cv_par_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_int(4), scalar5);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetND( CvArr* arr, const int* idx, CvScalar value )
HB_FUNC(CVSETND)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISARRAY(3))
  {
    PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
    int *values2 = NULL;
    if (a2)
    {
      const int lenght = hb_arrayLen(a2);
      values2 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values2[i] = hb_arrayGetNI(a2, i + 1);
      }
    }
    PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
    CvScalar scalar3;
    scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
    scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
    scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
    scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
    cvSetND(cv_par_CvArr(1), (const int *)values2, scalar3);
    if (a2)
    {
      delete[] values2;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetReal1D( CvArr* arr, int idx0, double value )
HB_FUNC(CVSETREAL1D)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    cvSetReal1D(cv_par_CvArr(1), cv_par_int(2), cv_par_double(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetReal2D( CvArr* arr, int idx0, int idx1, double value )
HB_FUNC(CVSETREAL2D)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4))
  {
    cvSetReal2D(cv_par_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_double(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetReal3D( CvArr* arr, int idx0, int idx1, int idx2, double value )
HB_FUNC(CVSETREAL3D)
{
  if (hb_pcount() == 5 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4) && HB_ISNUM(5))
  {
    cvSetReal3D(cv_par_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_int(4), cv_par_double(5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetRealND( CvArr* arr, const int* idx, double value )
HB_FUNC(CVSETREALND)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISNUM(3))
  {
    PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
    int *values2 = NULL;
    if (a2)
    {
      const int lenght = hb_arrayLen(a2);
      values2 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values2[i] = hb_arrayGetNI(a2, i + 1);
      }
    }
    cvSetRealND(cv_par_CvArr(1), (const int *)values2, cv_par_double(3));
    if (a2)
    {
      delete[] values2;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvClearND( CvArr* arr, const int* idx )
HB_FUNC(CVCLEARND)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISARRAY(2))
  {
    PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
    int *values2 = NULL;
    if (a2)
    {
      const int lenght = hb_arrayLen(a2);
      values2 = new int[lenght];
      for (int i = 0; i < lenght; ++i)
      {
        values2[i] = hb_arrayGetNI(a2, i + 1);
      }
    }
    cvClearND(cv_par_CvArr(1), (const int *)values2);
    if (a2)
    {
      delete[] values2;
    }
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(IplImage*) cvGetImage( const CvArr* arr, IplImage* image_header )
HB_FUNC(CVGETIMAGE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cv_ret_IplImage(cvGetImage(cv_cpar_CvArr(1), cv_par_IplImage(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMat*) cvReshape( const CvArr* arr, CvMat* header, int new_cn, int new_rows CV_DEFAULT(0) )
HB_FUNC(CVRESHAPE)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cv_ret_CvMat(cvReshape(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3), cv_dpar_int(4, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRepeat( const CvArr* src, CvArr* dst )
HB_FUNC(CVREPEAT)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvRepeat(cv_cpar_CvArr(1), cv_par_CvArr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCreateData( CvArr* arr )
HB_FUNC(CVCREATEDATA)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvCreateData(cv_par_CvArr(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseData( CvArr* arr )
HB_FUNC(CVRELEASEDATA)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvReleaseData(cv_par_CvArr(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetData( CvArr* arr, void* data, int step )
HB_FUNC(CVSETDATA)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3))
  {
    cvSetData(cv_par_CvArr(1), cv_par_voidptr(2), cv_par_int(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSize) cvGetSize( const CvArr* arr )
HB_FUNC(CVGETSIZE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvSize size;
    size = cvGetSize(cv_cpar_CvArr(1));
    PHB_ITEM a = hb_itemArrayNew(2);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutNI(t, size.width);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutNI(t, size.height);
    hb_itemArrayPut(a, 2, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCopy( const CvArr* src, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVCOPY)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)))
  {
    cvCopy(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_cpar_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSet( CvArr* arr, CvScalar value, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSET)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISARRAY(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvSet(cv_par_CvArr(1), scalar2, HB_ISNIL(3) ? NULL : cv_cpar_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetZero( CvArr* arr )
HB_FUNC(CVSETZERO)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvSetZero(cv_par_CvArr(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSplit( const CvArr* src, CvArr* dst0, CvArr* dst1, CvArr* dst2, CvArr* dst3 )
HB_FUNC(CVSPLIT)
{
  if (hb_pcount() == 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4) && HB_ISPOINTER(5))
  {
    cvSplit(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_CvArr(3), cv_par_CvArr(4), cv_par_CvArr(5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMerge( const CvArr* src0, const CvArr* src1, const CvArr* src2, const CvArr* src3, CvArr* dst )
HB_FUNC(CVMERGE)
{
  if (hb_pcount() == 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4) && HB_ISPOINTER(5))
  {
    cvMerge(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_cpar_CvArr(4), cv_par_CvArr(5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMixChannels( const CvArr** src, int src_count, CvArr** dst, int dst_count, const int* from_to, int
// pair_count )
HB_FUNC(CVMIXCHANNELS) // TODO: fix parameters 1 and 3
{
  PHB_ITEM a5 = hb_param(5, HB_IT_ARRAY);
  int *values5 = NULL;
  if (a5)
  {
    const int lenght = hb_arrayLen(a5);
    values5 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values5[i] = hb_arrayGetNI(a5, i + 1);
    }
  }
  cvMixChannels((const CvArr **)hb_parptr(1), cv_par_int(2), (CvArr **)hb_parptr(3), cv_par_int(4),
                (const int *)values5, cv_par_int(6));
  if (a5)
  {
    delete[] values5;
  }
}

// CVAPI(void) cvConvertScale( const CvArr* src, CvArr* dst, double scale CV_DEFAULT(1), double shift CV_DEFAULT(0) )
HB_FUNC(CVCONVERTSCALE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvConvertScale(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_double(3, 1), cv_dpar_double(4, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvConvertScaleAbs( const CvArr* src, CvArr* dst, double scale CV_DEFAULT(1), double shift CV_DEFAULT(0) )
HB_FUNC(CVCONVERTSCALEABS)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvConvertScaleAbs(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_double(3, 1), cv_dpar_double(4, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvTermCriteria) cvCheckTermCriteria( CvTermCriteria criteria, double default_eps, int default_max_iters )
HB_FUNC(CVCHECKTERMCRITERIA)
{
  if (hb_pcount() == 3 && HB_ISARRAY(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    CvTermCriteria tc;
    PHB_ITEM pTC1 = hb_param(1, HB_IT_ARRAY);
    CvTermCriteria tc1;
    tc1.type = hb_arrayGetNI(pTC1, 1);
    tc1.max_iter = hb_arrayGetNI(pTC1, 2);
    tc1.epsilon = hb_arrayGetND(pTC1, 3);
    tc = cvCheckTermCriteria(tc1, cv_par_double(2), cv_par_int(3));
    PHB_ITEM a = hb_itemArrayNew(3);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutNI(t, tc.type);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutNI(t, tc.max_iter);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, tc.epsilon);
    hb_itemArrayPut(a, 3, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvAdd( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVADD)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvAdd(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvAddS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVADDS)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvAddS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSub( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSUB)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvSub(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE void cvSubS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSUBS)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvSubS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSubRS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSUBRS)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvSubRS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMul( const CvArr* src1, const CvArr* src2, CvArr* dst, double scale CV_DEFAULT(1) )
HB_FUNC(CVMUL)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvMul(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_dpar_double(4, 1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvDiv( const CvArr* src1, const CvArr* src2, CvArr* dst, double scale CV_DEFAULT(1) )
HB_FUNC(CVDIV)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvDiv(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_dpar_double(4, 1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvScaleAdd( const CvArr* src1, CvScalar scale, const CvArr* src2, CvArr* dst )
HB_FUNC(CVSCALEADD)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvScaleAdd(cv_cpar_CvArr(1), scalar2, cv_cpar_CvArr(3), cv_par_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvAddWeighted( const CvArr* src1, double alpha, const CvArr* src2, double beta, double gamma, CvArr* dst
// )
HB_FUNC(CVADDWEIGHTED)
{
  if (hb_pcount() == 6 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISPOINTER(3) && HB_ISNUM(4) && HB_ISNUM(5) && HB_ISPOINTER(6))
  {
    cvAddWeighted(cv_cpar_CvArr(1), cv_par_double(2), cv_cpar_CvArr(3), cv_par_double(4), cv_par_double(5),
                  cv_par_CvArr(6));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvDotProduct( const CvArr* src1, const CvArr* src2 )
HB_FUNC(CVDOTPRODUCT)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cv_ret_double(cvDotProduct(cv_cpar_CvArr(1), cv_cpar_CvArr(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvAnd( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVAND)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvAnd(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvAndS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVANDS)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvAndS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvOr( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVOR)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvOr(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvOrS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVORS)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvOrS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvXor( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVXOR)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvXor(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvXorS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVXORS)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvXorS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvNot( const CvArr* src, CvArr* dst )
HB_FUNC(CVNOT)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvNot(cv_cpar_CvArr(1), cv_par_CvArr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvInRange( const CvArr* src, const CvArr* lower, const CvArr* upper, CvArr* dst )
HB_FUNC(CVINRANGE)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4))
  {
    cvInRange(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_par_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvInRangeS( const CvArr* src, CvScalar lower, CvScalar upper, CvArr* dst )
HB_FUNC(CVINRANGES)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISARRAY(3) && HB_ISPOINTER(4))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
    CvScalar scalar3;
    scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
    scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
    scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
    scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
    cvInRangeS(cv_cpar_CvArr(1), scalar2, scalar3, cv_par_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCmp( const CvArr* src1, const CvArr* src2, CvArr* dst, int cmp_op )
HB_FUNC(CVCMP)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISNUM(4))
  {
    cvCmp(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_int(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCmpS( const CvArr* src, double value, CvArr* dst, int cmp_op )
HB_FUNC(CVCMPS)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISPOINTER(3) && HB_ISNUM(4))
  {
    cvCmpS(cv_cpar_CvArr(1), cv_par_double(2), cv_par_CvArr(3), cv_par_int(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMin( const CvArr* src1, const CvArr* src2, CvArr* dst )
HB_FUNC(CVMIN)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvMin(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMax( const CvArr* src1, const CvArr* src2, CvArr* dst )
HB_FUNC(CVMAX)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvMax(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMinS( const CvArr* src, double value, CvArr* dst )
HB_FUNC(CVMINS)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISPOINTER(3))
  {
    cvMinS(cv_cpar_CvArr(1), cv_par_double(2), cv_par_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMaxS( const CvArr* src, double value, CvArr* dst )
HB_FUNC(CVMAXS)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISPOINTER(3))
  {
    cvMaxS(cv_cpar_CvArr(1), cv_par_double(2), cv_par_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvAbsDiff( const CvArr* src1, const CvArr* src2, CvArr* dst )
HB_FUNC(CVABSDIFF)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvAbsDiff(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvAbsDiffS( const CvArr* src, CvArr* dst, CvScalar value )
HB_FUNC(CVABSDIFFS)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISARRAY(3))
  {
    PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
    CvScalar scalar3;
    scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
    scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
    scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
    scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
    cvAbsDiffS(cv_cpar_CvArr(1), cv_par_CvArr(2), scalar3);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCartToPolar( const CvArr* x, const CvArr* y, CvArr* magnitude, CvArr* angle CV_DEFAULT(NULL), int
// angle_in_degrees CV_DEFAULT(0) )
HB_FUNC(CVCARTTOPOLAR)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    cvCartToPolar(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_dpar_CvArr(4, NULL), cv_dpar_int(5, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvPolarToCart( const CvArr* magnitude, const CvArr* angle, CvArr* x, CvArr* y, int angle_in_degrees
// CV_DEFAULT(0) )
HB_FUNC(CVPOLARTOCART)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    cvPolarToCart(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_CvArr(4), cv_dpar_int(5, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvPow( const CvArr* src, CvArr* dst, double power )
HB_FUNC(CVPOW)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3))
  {
    cvPow(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvExp( const CvArr* src, CvArr* dst )
HB_FUNC(CVEXP)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvExp(cv_cpar_CvArr(1), cv_par_CvArr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvLog( const CvArr* src, CvArr* dst )
HB_FUNC(CVLOG)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvLog(cv_cpar_CvArr(1), cv_par_CvArr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(float) cvFastArctan( float y, float x )
HB_FUNC(CVFASTARCTAN)
{
  if (hb_pcount() == 2 && HB_ISNUM(1) && HB_ISNUM(2))
  {
    cv_ret_float(cvFastArctan(cv_par_float(1), cv_par_float(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(float) cvCbrt( float value )
HB_FUNC(CVCBRT)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    cv_ret_float(cvCbrt(cv_par_float(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvCheckArr( const CvArr* arr, int flags CV_DEFAULT(0), double min_val CV_DEFAULT(0), double max_val
// CV_DEFAULT(0) )
HB_FUNC(CVCHECKARR)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 4 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2)) && (HB_ISNUM(3) || HB_ISNIL(3)) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cv_ret_int(cvCheckArr(cv_cpar_CvArr(1), cv_dpar_int(2, 0), cv_dpar_double(3, 0), cv_dpar_double(4, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSort( const CvArr* src, CvArr* dst CV_DEFAULT(NULL), CvArr* idxmat CV_DEFAULT(NULL), int flags
// CV_DEFAULT(0) )
HB_FUNC(CVSORT)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 4 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) || HB_ISNIL(2)) && (HB_ISPOINTER(3) || HB_ISNIL(3)) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvSort(cv_cpar_CvArr(1), cv_dpar_CvArr(2, NULL), cv_dpar_CvArr(3, NULL), cv_dpar_int(4, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSolveCubic( const CvMat* coeffs, CvMat* roots )
HB_FUNC(CVSOLVECUBIC)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cv_ret_int(cvSolveCubic(cv_cpar_CvMat(1), cv_par_CvMat(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSolvePoly( const CvMat* coeffs, CvMat* roots2, int maxiter CV_DEFAULT(20), int fig CV_DEFAULT(100) )
HB_FUNC(CVSOLVEPOLY)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvSolvePoly(cv_cpar_CvMat(1), cv_par_CvMat(2), cv_dpar_int(3, 20), cv_dpar_int(4, 100));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCrossProduct( const CvArr* src1, const CvArr* src2, CvArr* dst )
HB_FUNC(CVCROSSPRODUCT)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvCrossProduct(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvGEMM( const CvArr* src1, const CvArr* src2, double alpha, const CvArr* src3, double beta, CvArr* dst,
// int tABC CV_DEFAULT(0) )
HB_FUNC(CVGEMM)
{
  if (hb_pcount() >= 6 && hb_pcount() <= 7 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISPOINTER(4) && HB_ISNUM(5) && HB_ISPOINTER(6) && (HB_ISNUM(7) || HB_ISNIL(7)))
  {
    cvGEMM(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_double(3), cv_cpar_CvArr(4), cv_par_double(5), cv_par_CvArr(6),
           cv_dpar_int(7, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvTransform( const CvArr* src, CvArr* dst, const CvMat* transmat, const CvMat* shiftvec CV_DEFAULT(NULL)
// )
HB_FUNC(CVTRANSFORM)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)))
  {
    cvTransform(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3), HB_ISNIL(4) ? NULL : cv_cpar_CvMat(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvPerspectiveTransform( const CvArr* src, CvArr* dst, const CvMat* mat )
HB_FUNC(CVPERSPECTIVETRANSFORM)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvPerspectiveTransform(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMulTransposed( const CvArr* src, CvArr* dst, int order, const CvArr* delta CV_DEFAULT(NULL), double
// scale CV_DEFAULT(1.) )
HB_FUNC(CVMULTRANSPOSED)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    cvMulTransposed(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4),
                    cv_dpar_double(5, 1.));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvTranspose( const CvArr* src, CvArr* dst )
HB_FUNC(CVTRANSPOSE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvTranspose(cv_cpar_CvArr(1), cv_par_CvArr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCompleteSymm( CvMat* matrix, int LtoR CV_DEFAULT(0) )
HB_FUNC(CVCOMPLETESYMM)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2)))
  {
    cvCompleteSymm(cv_par_CvMat(1), cv_dpar_int(2, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvFlip( const CvArr* src, CvArr* dst CV_DEFAULT(NULL), int flip_mode CV_DEFAULT(0) )
HB_FUNC(CVFLIP)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 3 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) || HB_ISNIL(2)) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cvFlip(cv_cpar_CvArr(1), cv_dpar_CvArr(2, NULL), cv_dpar_int(3, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSVD( CvArr* A, CvArr* W, CvArr* U CV_DEFAULT(NULL), CvArr* V CV_DEFAULT(NULL), int flags CV_DEFAULT(0)
// )
HB_FUNC(CVSVD)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) || HB_ISNIL(3)) && (HB_ISPOINTER(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)))
  {
    cvSVD(cv_par_CvArr(1), cv_par_CvArr(2), cv_dpar_CvArr(3, NULL), cv_dpar_CvArr(4, NULL), cv_dpar_int(5, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSVBkSb( const CvArr* W, const CvArr* U, const CvArr* V, const CvArr* B, CvArr* X, int flags )
HB_FUNC(CVSVBKSB)
{
  if (hb_pcount() == 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4) && HB_ISPOINTER(5) && HB_ISNUM(6))
  {
    cvSVBkSb(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_cpar_CvArr(4), cv_par_CvArr(5), cv_par_int(6));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvInvert( const CvArr* src, CvArr* dst, int method CV_DEFAULT(CV_LU) )
HB_FUNC(CVINVERT)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cv_ret_double(cvInvert(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_LU)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSolve( const CvArr* src1, const CvArr* src2, CvArr* dst, int method CV_DEFAULT(CV_LU) )
HB_FUNC(CVSOLVE)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISNUM(4) && HB_ISNIL(4)))
  {
    cv_ret_int(cvSolve(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_dpar_int(4, CV_LU)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvDet( const CvArr* mat )
HB_FUNC(CVDET)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_double(cvDet(cv_cpar_CvArr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvScalar) cvTrace( const CvArr* mat )
HB_FUNC(CVTRACE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvScalar scalar;
    scalar = cvTrace(cv_cpar_CvArr(1));
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutND(t, scalar.val[0]);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutND(t, scalar.val[1]);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, scalar.val[2]);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutND(t, scalar.val[3]);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvEigenVV( CvArr* mat, CvArr* evects, CvArr* evals, double eps CV_DEFAULT(0), int lowindex
// CV_DEFAULT(-1), int highindex CV_DEFAULT(-1) )
HB_FUNC(CVEIGENVV)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISNUM(4) && HB_ISNIL(4)) && (HB_ISNUM(5) && HB_ISNIL(5)) && (HB_ISNUM(6) && HB_ISNIL(6)))
  {
    cvEigenVV(cv_par_CvArr(1), cv_par_CvArr(2), cv_par_CvArr(3), cv_dpar_double(4, 0), cv_dpar_int(5, -1),
              cv_dpar_int(6, -1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetIdentity( CvArr* mat, CvScalar value CV_DEFAULT(cvRealScalar(1)) )
HB_FUNC(CVSETIDENTITY)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISARRAY(2) && HB_ISNIL(2)))
  {
    PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
    CvScalar scalar2;
    scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
    scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
    scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
    scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
    cvSetIdentity(cv_par_CvArr(1), HB_ISNIL(2) ? cvRealScalar(1) : scalar2);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvArr*) cvRange( CvArr* mat, double start, double end )
HB_FUNC(CVRANGE)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    cv_ret_CvArr(cvRange(cv_par_CvArr(1), cv_par_double(2), cv_par_double(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCalcCovarMatrix( const CvArr** vects, int count, CvArr* cov_mat, CvArr* avg, int flags )
HB_FUNC(CVCALCCOVARMATRIX) // TODO: fix parameter 1
{
  cvCalcCovarMatrix((const CvArr **)hb_parptr(1), cv_par_int(2), cv_par_CvArr(3), cv_par_CvArr(4), cv_par_int(5));
}

// CVAPI(void) cvCalcPCA( const CvArr* data, CvArr* mean, CvArr* eigenvals, CvArr* eigenvects, int flags )
HB_FUNC(CVCALCPCA)
{
  if (hb_pcount() == 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4) && HB_ISNUM(5))
  {
    cvCalcPCA(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_CvArr(3), cv_par_CvArr(4), cv_par_int(5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvProjectPCA( const CvArr* data, const CvArr* mean, const CvArr* eigenvects, CvArr* result )
HB_FUNC(CVPROJECTPCA)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4))
  {
    cvProjectPCA(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_par_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvBackProjectPCA( const CvArr* proj, const CvArr* mean, const CvArr* eigenvects, CvArr* result )
HB_FUNC(CVBACKPROJECTPCA)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISPOINTER(4))
  {
    cvBackProjectPCA(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_par_CvArr(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvMahalanobis( const CvArr* vec1, const CvArr* vec2, const CvArr* mat )
HB_FUNC(CVMAHALANOBIS)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cv_ret_double(cvMahalanobis(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvScalar) cvSum( const CvArr* arr )
HB_FUNC(CVSUM)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvScalar scalar;
    scalar = cvSum(cv_cpar_CvArr(1));
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutND(t, scalar.val[0]);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutND(t, scalar.val[1]);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, scalar.val[2]);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutND(t, scalar.val[3]);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvCountNonZero( const CvArr* arr )
HB_FUNC(CVCOUNTNONZERO)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvCountNonZero(cv_cpar_CvArr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvScalar) cvAvg( const CvArr* arr, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVAVG)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) && HB_ISNIL(2)))
  {
    CvScalar scalar;
    scalar = cvAvg(cv_cpar_CvArr(1), HB_ISNIL(2) ? NULL : cv_cpar_CvArr(2));
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutND(t, scalar.val[0]);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutND(t, scalar.val[1]);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, scalar.val[2]);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutND(t, scalar.val[3]);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(double) cvNorm( const CvArr* arr1, const CvArr* arr2 CV_DEFAULT(NULL), int norm_type CV_DEFAULT(CV_L2), const
// CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVNORM)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 4 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) && HB_ISNIL(2)) && (HB_ISNUM(3) && HB_ISNIL(3)) && (HB_ISARRAY(4) && HB_ISNIL(4)))
  {
    cv_ret_double(cvNorm(cv_cpar_CvArr(1), HB_ISNIL(2) ? NULL : cv_cpar_CvArr(2), cv_dpar_int(3, CV_L2),
                         HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvNormalize( const CvArr* src, CvArr* dst, double a CV_DEFAULT(1.), double b CV_DEFAULT(0.), int
// norm_type CV_DEFAULT(CV_L2), const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVNORMALIZE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) && HB_ISNIL(3)) && (HB_ISNUM(4) && HB_ISNIL(4)) && (HB_ISNUM(5) && HB_ISNIL(5)) && (HB_ISPOINTER(6) && HB_ISNIL(6)))
  {
    cvNormalize(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_double(3, 1.), cv_dpar_double(4, 0.), cv_dpar_int(5, CV_L2),
                HB_ISNIL(6) ? NULL : cv_cpar_CvArr(6));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReduce( const CvArr* src, CvArr* dst, int dim CV_DEFAULT(-1), int op CV_DEFAULT(CV_REDUCE_SUM) )
HB_FUNC(CVREDUCE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) && HB_ISNIL(3)) && (HB_ISNUM(4) && HB_ISNIL(4)))
  {
    cvReduce(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, -1), cv_dpar_int(4, CV_REDUCE_SUM));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvDFT( const CvArr* src, CvArr* dst, int flags, int nonzero_rows CV_DEFAULT(0) )
HB_FUNC(CVDFT)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && (HB_ISNUM(4) && HB_ISNIL(4)))
  {
    cvDFT(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_dpar_int(4, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvMulSpectrums( const CvArr* src1, const CvArr* src2, CvArr* dst, int flags )
HB_FUNC(CVMULSPECTRUMS)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISNUM(4))
  {
    cvMulSpectrums(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_int(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetOptimalDFTSize( int size0 )
HB_FUNC(CVGETOPTIMALDFTSIZE)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    cv_ret_int(cvGetOptimalDFTSize(cv_par_int(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvDCT( const CvArr* src, CvArr* dst, int flags )
HB_FUNC(CVDCT)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3))
  {
    cvDCT(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSliceLength( CvSlice slice, const CvSeq* seq )
HB_FUNC(CVSLICELENGTH)
{
  if (hb_pcount() == 2 && HB_ISARRAY(1) && HB_ISPOINTER(2))
  {
    PHB_ITEM pSlice1 = hb_param(1, HB_IT_ARRAY);
    CvSlice slice1;
    slice1.start_index = hb_arrayGetNI(pSlice1, 1);
    slice1.end_index = hb_arrayGetNI(pSlice1, 2);
    cv_ret_int(cvSliceLength(slice1, cv_cpar_CvSeq(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMemStorage*) cvCreateMemStorage( int block_size CV_DEFAULT(0) )
HB_FUNC(CVCREATEMEMSTORAGE)
{
  if (hb_pcount() >= 0 && hb_pcount() <= 1 && (HB_ISNUM(1) && HB_ISNIL(1)))
  {
    cv_ret_CvMemStorage(cvCreateMemStorage(cv_dpar_int(1, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvMemStorage*) cvCreateChildMemStorage( CvMemStorage* parent )
HB_FUNC(CVCREATECHILDMEMSTORAGE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_CvMemStorage(cvCreateChildMemStorage(cv_par_CvMemStorage(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseMemStorage( CvMemStorage** storage )
HB_FUNC(CVRELEASEMEMSTORAGE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvMemStorage *storage = cv_par_CvMemStorage(1);
    cvReleaseMemStorage(&storage);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvClearMemStorage( CvMemStorage* storage )
HB_FUNC(CVCLEARMEMSTORAGE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvClearMemStorage(cv_par_CvMemStorage(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSaveMemStoragePos( const CvMemStorage* storage, CvMemStoragePos* pos )
HB_FUNC(CVSAVEMEMSTORAGEPOS)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvSaveMemStoragePos(cv_cpar_CvMemStorage(1), cv_par_CvMemStoragePos(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRestoreMemStoragePos( CvMemStorage* storage, CvMemStoragePos* pos )
HB_FUNC(CVRESTOREMEMSTORAGEPOS)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvRestoreMemStoragePos(cv_par_CvMemStorage(1), cv_par_CvMemStoragePos(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void*) cvMemStorageAlloc( CvMemStorage* storage, size_t size )
HB_FUNC(CVMEMSTORAGEALLOC)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cv_ret_voidptr(cvMemStorageAlloc(cv_par_CvMemStorage(1), cv_par_size_t(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvCreateSeq( int seq_flags, size_t header_size, size_t elem_size, CvMemStorage* storage )
HB_FUNC(CVCREATESEQ)
{
  if (hb_pcount() == 4 && HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISPOINTER(4))
  {
    cv_ret_CvSeq(cvCreateSeq(cv_par_int(1), cv_par_size_t(2), cv_par_size_t(3), cv_par_CvMemStorage(4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetSeqBlockSize( CvSeq* seq, int delta_elems )
HB_FUNC(CVSETSEQBLOCKSIZE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cvSetSeqBlockSize(cv_par_CvSeq(1), cv_par_int(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSeqPop( CvSeq* seq, void* element CV_DEFAULT(NULL) )
HB_FUNC(CVSEQPOP)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) && HB_ISNIL(2)))
  {
    cvSeqPop(cv_par_CvSeq(1), cv_dpar_voidptr(2, NULL));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSeqPopFront( CvSeq* seq, void* element CV_DEFAULT(NULL) )
HB_FUNC(CVSEQPOPFRONT)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) && HB_ISNIL(2)))
  {
    cvSeqPopFront(cv_par_CvSeq(1), cv_dpar_voidptr(2, NULL));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSeqPushMulti( CvSeq* seq, const void* elements, int count, int in_front CV_DEFAULT(0) )
HB_FUNC(CVSEQPUSHMULTI)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && (HB_ISNUM(4) && HB_ISNIL(4)))
  {
    cvSeqPushMulti(cv_par_CvSeq(1), cv_cpar_voidptr(2), cv_par_int(3), cv_dpar_int(4, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSeqPopMulti( CvSeq* seq, void* elements, int count, int in_front CV_DEFAULT(0) )
HB_FUNC(CVSEQPOPMULTI)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && (HB_ISNUM(4) && HB_ISNIL(4)))
  {
    cvSeqPopMulti(cv_par_CvSeq(1), cv_par_voidptr(2), cv_par_int(3), cv_dpar_int(4, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSeqRemove( CvSeq* seq, int index )
HB_FUNC(CVSEQREMOVE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cvSeqRemove(cv_par_CvSeq(1), cv_par_int(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvClearSeq( CvSeq* seq )
HB_FUNC(CVCLEARSEQ)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvClearSeq(cv_par_CvSeq(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSeqElemIdx( const CvSeq* seq, const void* element, CvSeqBlock** block CV_DEFAULT(NULL) )
HB_FUNC(CVSEQELEMIDX)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISPOINTER(3) && HB_ISNIL(3)))
  {
    cv_ret_int(cvSeqElemIdx(cv_cpar_CvSeq(1), cv_cpar_voidptr(2), HB_ISNIL(3) ? NULL : (CvSeqBlock **)hb_parptr(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvStartAppendToSeq( CvSeq* seq, CvSeqWriter* writer )
HB_FUNC(CVSTARTAPPENDTOSEQ)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvStartAppendToSeq(cv_par_CvSeq(1), cv_par_CvSeqWriter(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvStartWriteSeq( int seq_flags, int header_size, int elem_size, CvMemStorage* storage, CvSeqWriter*
// writer )
HB_FUNC(CVSTARTWRITESEQ)
{
  if (hb_pcount() == 5 && HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISPOINTER(4) && HB_ISPOINTER(5))
  {
    cvStartWriteSeq(cv_par_int(1), cv_par_int(2), cv_par_int(3), cv_par_CvMemStorage(4), cv_par_CvSeqWriter(5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvEndWriteSeq( CvSeqWriter* writer )
HB_FUNC(CVENDWRITESEQ)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_CvSeq(cvEndWriteSeq(cv_par_CvSeqWriter(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvFlushSeqWriter( CvSeqWriter* writer )
HB_FUNC(CVFLUSHSEQWRITER)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvFlushSeqWriter(cv_par_CvSeqWriter(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvStartReadSeq( const CvSeq* seq, CvSeqReader* reader, int reverse CV_DEFAULT(0) )
HB_FUNC(CVSTARTREADSEQ)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISNUM(3) && HB_ISNIL(3)))
  {
    cvStartReadSeq(cv_cpar_CvSeq(1), cv_par_CvSeqReader(2), cv_dpar_int(3, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetSeqReaderPos( CvSeqReader* reader )
HB_FUNC(CVGETSEQREADERPOS)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvGetSeqReaderPos(cv_par_CvSeqReader(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetSeqReaderPos( CvSeqReader* reader, int index, int is_relative CV_DEFAULT(0) )
HB_FUNC(CVSETSEQREADERPOS)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && (HB_ISNUM(3) && HB_ISNIL(3)))
  {
    cvSetSeqReaderPos(cv_par_CvSeqReader(1), cv_par_int(2), cv_dpar_int(3, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void*) cvCvtSeqToArray( const CvSeq* seq, void* elements, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ) )
HB_FUNC(CVCVTSEQTOARRAY)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && (HB_ISARRAY(3) && HB_ISNIL(3)))
  {
    PHB_ITEM pSlice3 = hb_param(3, HB_IT_ARRAY);
    CvSlice slice3;
    slice3.start_index = hb_arrayGetNI(pSlice3, 1);
    slice3.end_index = hb_arrayGetNI(pSlice3, 2);
    cv_ret_voidptr(cvCvtSeqToArray(cv_cpar_CvSeq(1), cv_par_voidptr(2), HB_ISNIL(3) ? CV_WHOLE_SEQ : slice3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvMakeSeqHeaderForArray( int seq_type, int header_size, int elem_size, void* elements, int total,
// CvSeq* seq, CvSeqBlock* block )
HB_FUNC(CVMAKESEQHEADERFORARRAY) // TODO: fix parameter 4
{
  if (hb_pcount() == 7 && HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISPOINTER(4) && HB_ISNUM(5) && HB_ISPOINTER(6) && HB_ISPOINTER(7))
  {
    cv_ret_CvSeq(cvMakeSeqHeaderForArray(cv_par_int(1), cv_par_int(2), cv_par_int(3), cv_par_voidptr(4), cv_par_int(5),
                                       cv_par_CvSeq(6), (CvSeqBlock *)hb_parptr(7)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvSeqSlice( const CvSeq* seq, CvSlice slice, CvMemStorage* storage CV_DEFAULT(NULL), int copy_data
// CV_DEFAULT(0) )
HB_FUNC(CVSEQSLICE)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISARRAY(2) && (HB_ISPOINTER(3) && HB_ISNIL(3)) && (HB_ISNUM(4) && HB_ISNIL(4)))
  {
    PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
    CvSlice slice2;
    slice2.start_index = hb_arrayGetNI(pSlice2, 1);
    slice2.end_index = hb_arrayGetNI(pSlice2, 2);
    cv_ret_CvSeq(cvSeqSlice(cv_cpar_CvSeq(1), slice2, cv_dpar_CvMemStorage(3, NULL), cv_dpar_int(4, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE CvSeq* cvCloneSeq( const CvSeq* seq, CvMemStorage* storage CV_DEFAULT(NULL) )
HB_FUNC(CVCLONESEQ)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) && HB_ISNIL(2)))
  {
    cv_ret_CvSeq(cvCloneSeq(cv_cpar_CvSeq(1), cv_dpar_CvMemStorage(2, NULL)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSeqRemoveSlice( CvSeq* seq, CvSlice slice )
HB_FUNC(CVSEQREMOVESLICE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISARRAY(2))
  {
    PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
    CvSlice slice2;
    slice2.start_index = hb_arrayGetNI(pSlice2, 1);
    slice2.end_index = hb_arrayGetNI(pSlice2, 2);
    cvSeqRemoveSlice(cv_par_CvSeq(1), slice2);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSeqInsertSlice( CvSeq* seq, int before_index, const CvArr* from_arr )
HB_FUNC(CVSEQINSERTSLICE)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISPOINTER(3))
  {
    cvSeqInsertSlice(cv_par_CvSeq(1), cv_par_int(2), cv_cpar_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSeqInvert( CvSeq* seq )
HB_FUNC(CVSEQINVERT)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvSeqInvert(cv_par_CvSeq(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvChangeSeqBlock( void* reader, int direction )
HB_FUNC(CVCHANGESEQBLOCK)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cvChangeSeqBlock(cv_par_voidptr(1), cv_par_int(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCreateSeqBlock( CvSeqWriter* writer )
HB_FUNC(CVCREATESEQBLOCK)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvCreateSeqBlock(cv_par_CvSeqWriter(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSet*) cvCreateSet( int set_flags, int header_size, int elem_size, CvMemStorage* storage )
HB_FUNC(CVCREATESET)
{
  if (hb_pcount() == 4 && HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISPOINTER(4))
  {
    cv_ret_CvSet(cvCreateSet(cv_par_int(1), cv_par_int(2), cv_par_int(3), cv_par_CvMemStorage(4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSetAdd( CvSet* set_header, CvSetElem* elem CV_DEFAULT(NULL), CvSetElem** inserted_elem CV_DEFAULT(NULL)
// )
HB_FUNC(CVSETADD) // TODO: fix parameter 3
{
  if (hb_pcount() >= 1 && hb_pcount() <= 3 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) && HB_ISNIL(2)) && (HB_ISPOINTER(3) && HB_ISNIL(3)))
  {
    cv_ret_int(cvSetAdd(cv_par_CvSet(1), HB_ISNIL(2) ? NULL : (CvSetElem *)hb_parptr(2),
                        HB_ISNIL(3) ? NULL : (CvSetElem **)hb_parptr(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE CvSetElem* cvSetNew( CvSet* set_header )
HB_FUNC(CVSETNEW)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_CvSetElem(cvSetNew(cv_par_CvSet(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE void cvSetRemoveByPtr( CvSet* set_header, void* elem )
HB_FUNC(CVSETREMOVEBYPTR)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvSetRemoveByPtr(cv_par_CvSet(1), cv_par_voidptr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetRemove( CvSet* set_header, int index )
HB_FUNC(CVSETREMOVE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cvSetRemove(cv_par_CvSet(1), cv_par_int(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE CvSetElem* cvGetSetElem( const CvSet* set_header, int idx )
HB_FUNC(CVGETSETELEM)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cv_ret_CvSetElem(cvGetSetElem(cv_cpar_CvSet(1), cv_par_int(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvClearSet( CvSet* set_header )
HB_FUNC(CVCLEARSET)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvClearSet(cv_par_CvSet(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvGraph*) cvCreateGraph( int graph_flags, int header_size, int vtx_size, int edge_size, CvMemStorage* storage )
HB_FUNC(CVCREATEGRAPH)
{
  if (hb_pcount() == 5 && HB_ISNUM(1) && HB_ISNUM(2) && HB_ISNUM(3) && HB_ISNUM(4) && HB_ISPOINTER(5))
  {
    cv_ret_CvGraph(cvCreateGraph(cv_par_int(1), cv_par_int(2), cv_par_int(3), cv_par_int(4), cv_par_CvMemStorage(5)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGraphAddVtx( CvGraph* graph, const CvGraphVtx* vtx CV_DEFAULT(NULL), CvGraphVtx** inserted_vtx
// CV_DEFAULT(NULL) )
HB_FUNC(CVGRAPHADDVTX)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 3 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) && HB_ISNIL(2)) && (HB_ISPOINTER(3) && HB_ISNIL(3)))
  {
    cv_ret_int(cvGraphAddVtx((CvGraph *)hb_parptr(1), HB_ISNIL(2) ? NULL : (const CvGraphVtx *)hb_parptr(2),
                             HB_ISNIL(3) ? NULL : (CvGraphVtx **)hb_parptr(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGraphRemoveVtx( CvGraph* graph, int index )
HB_FUNC(CVGRAPHREMOVEVTX)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cv_ret_int(cvGraphRemoveVtx((CvGraph *)hb_parptr(1), cv_par_int(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGraphRemoveVtxByPtr( CvGraph* graph, CvGraphVtx* vtx )
HB_FUNC(CVGRAPHREMOVEVTXBYPTR)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cv_ret_int(cvGraphRemoveVtxByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGraphAddEdge( CvGraph* graph, int start_idx, int end_idx, const CvGraphEdge* edge CV_DEFAULT(NULL),
// CvGraphEdge** inserted_edge CV_DEFAULT(NULL) )
HB_FUNC(CVGRAPHADDEDGE)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)) && (HB_ISPOINTER(5) || HB_ISNIL(5)))
  {
    cv_ret_int(cvGraphAddEdge((CvGraph *)hb_parptr(1), cv_par_int(2), cv_par_int(3),
                              HB_ISNIL(4) ? NULL : (const CvGraphEdge *)hb_parptr(4),
                              HB_ISNIL(5) ? NULL : (CvGraphEdge **)hb_parptr(5)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGraphAddEdgeByPtr( CvGraph* graph, CvGraphVtx* start_vtx, CvGraphVtx* end_vtx, const CvGraphEdge* edge
// CV_DEFAULT(NULL), CvGraphEdge** inserted_edge CV_DEFAULT(NULL) )
HB_FUNC(CVGRAPHADDEDGEBYPTR)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISPOINTER(4) || HB_ISNIL(4)) && (HB_ISPOINTER(5) || HB_ISNIL(5)))
  {
    cv_ret_int(cvGraphAddEdgeByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2), (CvGraphVtx *)hb_parptr(3),
                                   HB_ISNIL(4) ? NULL : (const CvGraphEdge *)hb_parptr(4),
                                   HB_ISNIL(5) ? NULL : (CvGraphEdge **)hb_parptr(5)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvGraphRemoveEdge( CvGraph* graph, int start_idx, int end_idx )
HB_FUNC(CVGRAPHREMOVEEDGE)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    cvGraphRemoveEdge((CvGraph *)hb_parptr(1), cv_par_int(2), cv_par_int(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvGraphRemoveEdgeByPtr( CvGraph* graph, CvGraphVtx* start_vtx, CvGraphVtx* end_vtx )
HB_FUNC(CVGRAPHREMOVEEDGEBYPTR)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvGraphRemoveEdgeByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2), (CvGraphVtx *)hb_parptr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvGraphEdge*) cvFindGraphEdge( const CvGraph* graph, int start_idx, int end_idx )
HB_FUNC(CVFINDGRAPHEDGE)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISNUM(3))
  {
    cv_ret_CvGraphEdge(cvFindGraphEdge((const CvGraph *)hb_parptr(1), cv_par_int(2), cv_par_int(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvGraphEdge*) cvFindGraphEdgeByPtr( const CvGraph* graph, const CvGraphVtx* start_vtx, const CvGraphVtx*
// end_vtx )
HB_FUNC(CVFINDGRAPHEDGEBYPTR)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cv_ret_CvGraphEdge(cvFindGraphEdgeByPtr((const CvGraph *)hb_parptr(1), (const CvGraphVtx *)hb_parptr(2),
                                          (const CvGraphVtx *)hb_parptr(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvClearGraph( CvGraph* graph )
HB_FUNC(CVCLEARGRAPH)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvClearGraph((CvGraph *)hb_parptr(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGraphVtxDegree( const CvGraph* graph, int vtx_idx )
HB_FUNC(CVGRAPHVTXDEGREE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISNUM(2))
  {
    cv_ret_int(cvGraphVtxDegree((const CvGraph *)hb_parptr(1), cv_par_int(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGraphVtxDegreeByPtr( const CvGraph* graph, const CvGraphVtx* vtx )
HB_FUNC(CVGRAPHVTXDEGREEBYPTR)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cv_ret_int(cvGraphVtxDegreeByPtr((const CvGraph *)hb_parptr(1), (const CvGraphVtx *)hb_parptr(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvGraphScanner*) cvCreateGraphScanner( CvGraph* graph, CvGraphVtx* vtx CV_DEFAULT(NULL), int mask
// CV_DEFAULT(CV_GRAPH_ALL_ITEMS) )
HB_FUNC(CVCREATEGRAPHSCANNER)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 3 && HB_ISPOINTER(1) && (HB_ISPOINTER(2) || HB_ISNIL(2)) && (HB_ISNUM(3) || HB_ISNIL(3)))
  {
    cv_ret_CvGraphScanner(cvCreateGraphScanner((CvGraph *)hb_parptr(1), HB_ISNIL(2) ? NULL : (CvGraphVtx *)hb_parptr(2),
                                               cv_dpar_int(3, CV_GRAPH_ALL_ITEMS)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseGraphScanner( CvGraphScanner** scanner )
HB_FUNC(CVRELEASEGRAPHSCANNER)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvGraphScanner *scanner = (CvGraphScanner *)hb_parptr(1);
    cvReleaseGraphScanner(&scanner);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvNextGraphItem( CvGraphScanner* scanner )
HB_FUNC(CVNEXTGRAPHITEM)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvNextGraphItem((CvGraphScanner *)hb_parptr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvGraph*) cvCloneGraph( const CvGraph* graph, CvMemStorage* storage )
HB_FUNC(CVCLONEGRAPH)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cv_ret_CvGraph(cvCloneGraph((const CvGraph *)hb_parptr(1), cv_par_CvMemStorage(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvLine( CvArr* img, CvPoint pt1, CvPoint pt2, CvScalar color, int thickness CV_DEFAULT(1), int line_type
// CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVLINE)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 7 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISARRAY(3) && HB_ISARRAY(4) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)) && (HB_ISNUM(7) || HB_ISNIL(7)))
  {
    PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
    CvPoint point2;
    point2.x = hb_arrayGetNI(pPoint2, 1);
    point2.y = hb_arrayGetNI(pPoint2, 2);
    PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
    CvPoint point3;
    point3.x = hb_arrayGetNI(pPoint3, 1);
    point3.y = hb_arrayGetNI(pPoint3, 2);
    PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
    CvScalar scalar4;
    scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
    scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
    scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
    scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
    cvLine(cv_par_CvArr(1), point2, point3, scalar4, cv_dpar_int(5, 1), cv_dpar_int(6, 8), cv_dpar_int(7, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRectangle( CvArr* img, CvPoint pt1, CvPoint pt2, CvScalar color, int thickness CV_DEFAULT(1), int
// line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVRECTANGLE)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 7 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISARRAY(3) && HB_ISARRAY(4) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)) && (HB_ISNUM(7) || HB_ISNIL(7)))
  {
    PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
    CvPoint point2;
    point2.x = hb_arrayGetNI(pPoint2, 1);
    point2.y = hb_arrayGetNI(pPoint2, 2);
    PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
    CvPoint point3;
    point3.x = hb_arrayGetNI(pPoint3, 1);
    point3.y = hb_arrayGetNI(pPoint3, 2);
    PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
    CvScalar scalar4;
    scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
    scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
    scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
    scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
    cvRectangle(cv_par_CvArr(1), point2, point3, scalar4, cv_dpar_int(5, 1), cv_dpar_int(6, 8), cv_dpar_int(7, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRectangleR( CvArr* img, CvRect r, CvScalar color, int thickness CV_DEFAULT(1), int line_type
// CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVRECTANGLER)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISARRAY(3) && (HB_ISNUM(4) || HB_ISNIL(4)) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)))
  {
    PHB_ITEM pRect2 = hb_param(2, HB_IT_ARRAY);
    CvRect rect2;
    rect2.x = hb_arrayGetNI(pRect2, 1);
    rect2.y = hb_arrayGetNI(pRect2, 2);
    rect2.width = hb_arrayGetNI(pRect2, 3);
    rect2.height = hb_arrayGetNI(pRect2, 4);
    PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
    CvScalar scalar3;
    scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
    scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
    scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
    scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
    cvRectangleR(cv_par_CvArr(1), rect2, scalar3, cv_dpar_int(4, 1), cv_dpar_int(5, 8), cv_dpar_int(6, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvCircle( CvArr* img, CvPoint center, int radius, CvScalar color, int thickness CV_DEFAULT(1), int
// line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVCIRCLE)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 7 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISNUM(3) && HB_ISARRAY(4) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)) && (HB_ISNUM(7) || HB_ISNIL(7)))
  {
    PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
    CvPoint point2;
    point2.x = hb_arrayGetNI(pPoint2, 1);
    point2.y = hb_arrayGetNI(pPoint2, 2);
    PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
    CvScalar scalar4;
    scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
    scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
    scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
    scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
    cvCircle(cv_par_CvArr(1), point2, cv_par_int(3), scalar4, cv_dpar_int(5, 1), cv_dpar_int(6, 8), cv_dpar_int(7, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvEllipse( CvArr* img, CvPoint center, CvSize axes, double angle, double start_angle, double end_angle,
// CvScalar color, int thickness CV_DEFAULT(1), int line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVELLIPSE)
{
  if (hb_pcount() >= 7 && hb_pcount() <= 10 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISARRAY(3) && HB_ISNUM(4) && HB_ISNUM(5) && HB_ISNUM(6) && HB_ISARRAY(7) && (HB_ISNUM(8) || HB_ISNIL(8)) && (HB_ISNUM(9) || HB_ISNIL(9)) && (HB_ISNUM(10) || HB_ISNIL(10)))
  {
    PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
    CvPoint point2;
    point2.x = hb_arrayGetNI(pPoint2, 1);
    point2.y = hb_arrayGetNI(pPoint2, 2);
    PHB_ITEM pSize3 = hb_param(3, HB_IT_ARRAY);
    CvSize size3;
    size3.width = hb_arrayGetNI(pSize3, 1);
    size3.height = hb_arrayGetNI(pSize3, 2);
    PHB_ITEM pScalar7 = hb_param(7, HB_IT_ARRAY);
    CvScalar scalar7;
    scalar7.val[0] = hb_arrayGetND(pScalar7, 1);
    scalar7.val[1] = hb_arrayGetND(pScalar7, 2);
    scalar7.val[2] = hb_arrayGetND(pScalar7, 3);
    scalar7.val[3] = hb_arrayGetND(pScalar7, 4);
    cvEllipse(cv_par_CvArr(1), point2, size3, cv_par_double(4), cv_par_double(5), cv_par_double(6), scalar7,
              cv_dpar_int(8, 1), cv_dpar_int(9, 8), cv_dpar_int(10, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvInitLineIterator( const CvArr* image, CvPoint pt1, CvPoint pt2, CvLineIterator* line_iterator, int
// connectivity CV_DEFAULT(8), int left_to_right CV_DEFAULT(0) )
HB_FUNC(CVINITLINEITERATOR)
{
  if (hb_pcount() >= 4 && hb_pcount() <= 6 && HB_ISPOINTER(1) && HB_ISARRAY(2) && HB_ISARRAY(3) && HB_ISPOINTER(4) && (HB_ISNUM(5) || HB_ISNIL(5)) && (HB_ISNUM(6) || HB_ISNIL(6)))
  {
    PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
    CvPoint point2;
    point2.x = hb_arrayGetNI(pPoint2, 1);
    point2.y = hb_arrayGetNI(pPoint2, 2);
    PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
    CvPoint point3;
    point3.x = hb_arrayGetNI(pPoint3, 1);
    point3.y = hb_arrayGetNI(pPoint3, 2);
    cv_ret_int(cvInitLineIterator(cv_cpar_CvArr(1), point2, point3, (CvLineIterator *)hb_parptr(4), cv_dpar_int(5, 8),
                                  cv_dpar_int(6, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvScalar) cvColorToScalar( double packed_color, int arrtype )
HB_FUNC(CVCOLORTOSCALAR)
{
  if (hb_pcount() == 2 && HB_ISNUM(1) && HB_ISNUM(2))
  {
    CvScalar scalar;
    scalar = cvColorToScalar(cv_par_double(1), cv_par_int(2));
    PHB_ITEM a = hb_itemArrayNew(4);
    PHB_ITEM t = hb_itemNew(NULL);
    hb_itemPutND(t, scalar.val[0]);
    hb_itemArrayPut(a, 1, t);
    hb_itemPutND(t, scalar.val[1]);
    hb_itemArrayPut(a, 2, t);
    hb_itemPutND(t, scalar.val[2]);
    hb_itemArrayPut(a, 3, t);
    hb_itemPutND(t, scalar.val[3]);
    hb_itemArrayPut(a, 4, t);
    hb_itemRelease(t);
    hb_itemReturnRelease(a);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvLUT( const CvArr* src, CvArr* dst, const CvArr* lut )
HB_FUNC(CVLUT)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvLUT(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvArr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvInitTreeNodeIterator( CvTreeNodeIterator* tree_iterator, const void* first, int max_level )
HB_FUNC(CVINITTREENODEITERATOR)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3))
  {
    cvInitTreeNodeIterator(cv_par_CvTreeNodeIterator(1), cv_cpar_voidptr(2), cv_par_int(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void*) cvNextTreeNode( CvTreeNodeIterator* tree_iterator )
HB_FUNC(CVNEXTTREENODE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_voidptr(cvNextTreeNode(cv_par_CvTreeNodeIterator(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void*) cvPrevTreeNode( CvTreeNodeIterator* tree_iterator )
HB_FUNC(CVPREVTREENODE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_voidptr(cvPrevTreeNode(cv_par_CvTreeNodeIterator(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvInsertNodeIntoTree( void* node, void* parent, void* frame )
HB_FUNC(CVINSERTNODEINTOTREE)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvInsertNodeIntoTree(cv_par_voidptr(1), cv_par_voidptr(2), cv_par_voidptr(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRemoveNodeFromTree( void* node, void* frame )
HB_FUNC(CVREMOVENODEFROMTREE)
{
  if (hb_pcount() == 2 && HB_ISPOINTER(1) && HB_ISPOINTER(2))
  {
    cvRemoveNodeFromTree(cv_par_voidptr(1), cv_par_voidptr(2));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvSeq*) cvTreeToNodeSeq( const void* first, int header_size, CvMemStorage* storage )
HB_FUNC(CVTREETONODESEQ)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISNUM(2) && HB_ISPOINTER(3))
  {
    cv_ret_CvSeq(cvTreeToNodeSeq(cv_cpar_voidptr(1), cv_par_int(2), cv_par_CvMemStorage(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvRegisterModule( const CvModuleInfo* module_info )
HB_FUNC(CVREGISTERMODULE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_int(cvRegisterModule(cv_cpar_CvModuleInfo(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvUseOptimized( int on_off )
HB_FUNC(CVUSEOPTIMIZED)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    cv_ret_int(cvUseOptimized(cv_par_int(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvFileStorage*) cvOpenFileStorage( const char* filename, CvMemStorage* memstorage, int flags, const char*
// encoding CV_DEFAULT(NULL) )
HB_FUNC(CVOPENFILESTORAGE)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISCHAR(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && (HB_ISCHAR(4) || HB_ISNIL(4)))
  {
    cv_ret_CvFileStorage(
        cvOpenFileStorage(hb_parc(1), cv_par_CvMemStorage(2), cv_par_int(3), HB_ISNIL(4) ? NULL : hb_parc(4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReleaseFileStorage( CvFileStorage** fs )
HB_FUNC(CVRELEASEFILESTORAGE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    CvFileStorage *fs = cv_par_CvFileStorage(1);
    cvReleaseFileStorage(&fs);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvEndWriteStruct( CvFileStorage* fs )
HB_FUNC(CVENDWRITESTRUCT)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvEndWriteStruct(cv_par_CvFileStorage(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWriteInt( CvFileStorage* fs, const char* name, int value )
HB_FUNC(CVWRITEINT)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISCHAR(2) && HB_ISNUM(3))
  {
    cvWriteInt(cv_par_CvFileStorage(1), hb_parc(2), cv_par_int(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWriteReal( CvFileStorage* fs, const char* name, double value )
HB_FUNC(CVWRITEREAL)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISCHAR(2) && HB_ISNUM(3))
  {
    cvWriteReal(cv_par_CvFileStorage(1), hb_parc(2), cv_par_double(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWriteString( CvFileStorage* fs, const char* name, const char* str, int quote CV_DEFAULT(0) )
HB_FUNC(CVWRITESTRING)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISCHAR(2) && HB_ISCHAR(3) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cvWriteString(cv_par_CvFileStorage(1), hb_parc(2), hb_parc(3), cv_dpar_int(4, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWriteComment( CvFileStorage* fs, const char* comment, int eol_comment )
HB_FUNC(CVWRITECOMMENT)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISCHAR(2) && HB_ISNUM(3))
  {
    cvWriteComment(cv_par_CvFileStorage(1), hb_parc(2), cv_par_int(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvStartNextStream( CvFileStorage* fs )
HB_FUNC(CVSTARTNEXTSTREAM)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvStartNextStream(cv_par_CvFileStorage(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWriteRawData( CvFileStorage* fs, const void* src, int len, const char* dt )
HB_FUNC(CVWRITERAWDATA)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISCHAR(4))
  {
    cvWriteRawData(cv_par_CvFileStorage(1), cv_cpar_voidptr(2), cv_par_int(3), hb_parc(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvStringHashNode*) cvGetHashedKey( CvFileStorage* fs, const char* name, int len CV_DEFAULT(-1), int
// create_missing CV_DEFAULT(0) )
HB_FUNC(CVGETHASHEDKEY)
{
  if (hb_pcount() >= 2 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISCHAR(2) && (HB_ISNUM(3) || HB_ISNIL(3)) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cv_ret_CvStringHashNode(cvGetHashedKey(cv_par_CvFileStorage(1), hb_parc(2), cv_dpar_int(3, -1), cv_dpar_int(4, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvFileNode*) cvGetRootFileNode( const CvFileStorage* fs, int stream_index CV_DEFAULT(0) )
HB_FUNC(CVGETROOTFILENODE)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2)))
  {
    cv_ret_CvFileNode(cvGetRootFileNode(cv_cpar_CvFileStorage(1), cv_dpar_int(2, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvFileNode*) cvGetFileNode( CvFileStorage* fs, CvFileNode* map, const CvStringHashNode* key, int create_missing
// CV_DEFAULT(0) )
HB_FUNC(CVGETFILENODE)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cv_ret_CvFileNode(cvGetFileNode(cv_par_CvFileStorage(1), cv_par_CvFileNode(2), (const CvStringHashNode *)hb_parptr(3),
                                    cv_dpar_int(4, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvFileNode*) cvGetFileNodeByName( const CvFileStorage* fs, const CvFileNode* map, const char* name )
HB_FUNC(CVGETFILENODEBYNAME)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISCHAR(3))
  {
    cv_ret_CvFileNode(cvGetFileNodeByName(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), hb_parc(3)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE int cvReadInt( const CvFileNode* node, int default_value CV_DEFAULT(0) )
HB_FUNC(CVREADINT)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2)))
  {
    cv_ret_int(cvReadInt(cv_cpar_CvFileNode(1), cv_dpar_int(2, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE int cvReadIntByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, int default_value
// CV_DEFAULT(0) )
HB_FUNC(CVREADINTBYNAME)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISCHAR(3) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cv_ret_int(cvReadIntByName(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), hb_parc(3), cv_dpar_int(4, 0)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE double cvReadReal( const CvFileNode* node, double default_value CV_DEFAULT(0.) )
HB_FUNC(CVREADREAL)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISNUM(2) || HB_ISNIL(2)))
  {
    cv_ret_double(cvReadReal(cv_cpar_CvFileNode(1), cv_dpar_double(2, 0.)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE double cvReadRealByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, double
// default_value CV_DEFAULT(0.) )
HB_FUNC(CVREADREALBYNAME)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISCHAR(3) && (HB_ISNUM(4) || HB_ISNIL(4)))
  {
    cv_ret_double(cvReadRealByName(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), hb_parc(3), cv_dpar_double(4, 0.)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE const char* cvReadString( const CvFileNode* node, const char* default_value CV_DEFAULT(NULL) )
HB_FUNC(CVREADSTRING)
{
  if (hb_pcount() >= 1 && hb_pcount() <= 2 && HB_ISPOINTER(1) && (HB_ISCHAR(2) || HB_ISNIL(2)))
  {
    hb_retc(cvReadString(cv_cpar_CvFileNode(1), HB_ISNIL(2) ? NULL : hb_parc(2)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CV_INLINE const char* cvReadStringByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, const
// char* default_value CV_DEFAULT(NULL) )
HB_FUNC(CVREADSTRINGBYNAME)
{
  if (hb_pcount() >= 3 && hb_pcount() <= 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISCHAR(3) && (HB_ISCHAR(4) || HB_ISNIL(4)))
  {
    hb_retc(
        cvReadStringByName(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), hb_parc(3), HB_ISNIL(4) ? NULL : hb_parc(4)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvStartReadRawData( const CvFileStorage* fs, const CvFileNode* src, CvSeqReader* reader )
HB_FUNC(CVSTARTREADRAWDATA)
{
  if (hb_pcount() == 3 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3))
  {
    cvStartReadRawData(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), cv_par_CvSeqReader(3));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReadRawDataSlice( const CvFileStorage* fs, CvSeqReader* reader, int count, void* dst, const char* dt )
HB_FUNC(CVREADRAWDATASLICE)
{
  if (hb_pcount() == 5 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISNUM(3) && HB_ISPOINTER(4) && HB_ISCHAR(5))
  {
    cvReadRawDataSlice(cv_cpar_CvFileStorage(1), cv_par_CvSeqReader(2), cv_par_int(3), cv_par_voidptr(4), hb_parc(5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvReadRawData( const CvFileStorage* fs, const CvFileNode* src, void* dst, const char* dt )
HB_FUNC(CVREADRAWDATA)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISPOINTER(2) && HB_ISPOINTER(3) && HB_ISCHAR(4))
  {
    cvReadRawData(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), cv_par_voidptr(3), hb_parc(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvWriteFileNode( CvFileStorage* fs, const char* new_node_name, const CvFileNode* node, int embed )
HB_FUNC(CVWRITEFILENODE)
{
  if (hb_pcount() == 4 && HB_ISPOINTER(1) && HB_ISCHAR(2) && HB_ISPOINTER(3) && HB_ISNUM(4))
  {
    cvWriteFileNode(cv_par_CvFileStorage(1), hb_parc(2), cv_cpar_CvFileNode(3), cv_par_int(4));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(const char*) cvGetFileNodeName( const CvFileNode* node )
HB_FUNC(CVGETFILENODENAME)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    hb_retc(cvGetFileNodeName(cv_cpar_CvFileNode(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRegisterType( const CvTypeInfo* info )
HB_FUNC(CVREGISTERTYPE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cvRegisterType((const CvTypeInfo *)hb_parptr(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvUnregisterType( const char* type_name )
HB_FUNC(CVUNREGISTERTYPE)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1))
  {
    cvUnregisterType(hb_parc(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvTypeInfo*) cvFirstType( void )
HB_FUNC(CVFIRSTTYPE)
{
  if (hb_pcount() == 0)
  {
    cv_ret_CvTypeInfo(cvFirstType());
  }
}

// CVAPI(CvTypeInfo*) cvFindType( const char* type_name )
HB_FUNC(CVFINDTYPE)
{
  if (hb_pcount() == 1 && HB_ISCHAR(1))
  {
    cv_ret_CvTypeInfo(cvFindType(hb_parc(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(CvTypeInfo*) cvTypeOf( const void* struct_ptr )
HB_FUNC(CVTYPEOF)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_CvTypeInfo(cvTypeOf(cv_cpar_voidptr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvRelease( void** struct_ptr )
HB_FUNC(CVRELEASE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    void *struct_ptr = cv_par_voidptr(1);
    cvRelease(&struct_ptr);
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void*) cvClone( const void* struct_ptr )
HB_FUNC(CVCLONE)
{
  if (hb_pcount() == 1 && HB_ISPOINTER(1))
  {
    cv_ret_voidptr(cvClone(cv_cpar_voidptr(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int64) cvGetTickCount( void )
HB_FUNC(CVGETTICKCOUNT)
{
  if (hb_pcount() == 0)
  {
    hb_retnll(cvGetTickCount());
  }
}

// CVAPI(double) cvGetTickFrequency( void )
HB_FUNC(CVGETTICKFREQUENCY)
{
  if (hb_pcount() == 0)
  {
    cv_ret_double(cvGetTickFrequency());
  }
}

// CVAPI(int) cvCheckHardwareSupport( int feature )
HB_FUNC(CVCHECKHARDWARESUPPORT)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    cv_ret_int(cvCheckHardwareSupport(cv_par_int(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetNumThreads( void )
HB_FUNC(CVGETNUMTHREADS)
{
  if (hb_pcount() == 0)
  {
    cv_ret_int(cvGetNumThreads());
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetNumThreads( int threads CV_DEFAULT(0) )
HB_FUNC(CVSETNUMTHREADS)
{
  if (hb_pcount() >= 0 && hb_pcount() <= 1 && (HB_ISNUM(1) || HB_ISNIL(1)))
  {
    cvSetNumThreads(cv_dpar_int(1, 0));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetThreadNum( void )
HB_FUNC(CVGETTHREADNUM)
{
  if (hb_pcount() == 0)
  {
    cv_ret_int(cvGetThreadNum());
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetErrStatus( void )
HB_FUNC(CVGETERRSTATUS)
{
  if (hb_pcount() == 0)
  {
    cv_ret_int(cvGetErrStatus());
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvSetErrStatus( int status )
HB_FUNC(CVSETERRSTATUS)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    cvSetErrStatus(cv_par_int(1));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGetErrMode( void )
HB_FUNC(CVGETERRMODE)
{
  if (hb_pcount() == 0)
  {
    cv_ret_int(cvGetErrMode());
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvSetErrMode( int mode )
HB_FUNC(CVSETERRMODE)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    cv_ret_int(cvSetErrMode(cv_par_int(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(void) cvError( int status, const char* func_name, const char* err_msg, const char* file_name, int line )
HB_FUNC(CVERROR)
{
  if (hb_pcount() == 5 && HB_ISNUM(1) && HB_ISCHAR(2) && HB_ISCHAR(3) && HB_ISCHAR(4) && HB_ISNUM(5))
  {
    cvError(cv_par_int(1), hb_parc(2), hb_parc(3), hb_parc(4), cv_par_int(5));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(const char*) cvErrorStr( int status )
HB_FUNC(CVERRORSTR)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    hb_retc(cvErrorStr(cv_par_int(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvErrorFromIppStatus( int ipp_status )
HB_FUNC(CVERRORFROMIPPSTATUS)
{
  if (hb_pcount() == 1 && HB_ISNUM(1))
  {
    cv_ret_int(cvErrorFromIppStatus(cv_par_int(1)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvNulDevReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line,
// void* userdata )
HB_FUNC(CVNULDEVREPORT)
{
  if (hb_pcount() == 6 && HB_ISNUM(1) && HB_ISCHAR(2) && HB_ISCHAR(3) && HB_ISCHAR(4) && HB_ISNUM(5) && HB_ISPOINTER(6))
  {
    cv_ret_int(cvNulDevReport(cv_par_int(1), hb_parc(2), hb_parc(3), hb_parc(4), cv_par_int(5), cv_par_voidptr(6)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvStdErrReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line,
// void* userdata )
HB_FUNC(CVSTDERRREPORT)
{
  if (hb_pcount() == 6 && HB_ISNUM(1) && HB_ISCHAR(2) && HB_ISCHAR(3) && HB_ISCHAR(4) && HB_ISNUM(5) && HB_ISPOINTER(6))
  {
    cv_ret_int(cvStdErrReport(cv_par_int(1), hb_parc(2), hb_parc(3), hb_parc(4), cv_par_int(5), cv_par_voidptr(6)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}

// CVAPI(int) cvGuiBoxReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line,
// void* userdata )
HB_FUNC(CVGUIBOXREPORT)
{
  if (hb_pcount() == 6 && HB_ISNUM(1) && HB_ISCHAR(2) && HB_ISCHAR(3) && HB_ISCHAR(4) && HB_ISNUM(5) && HB_ISPOINTER(6))
  {
    cv_ret_int(cvGuiBoxReport(cv_par_int(1), hb_parc(2), hb_parc(3), hb_parc(4), cv_par_int(5), cv_par_voidptr(6)));
  }
  else
  {
    hb_errRT_BASE(EG_ARG, 3012, NULL, HB_ERR_FUNCNAME, HB_ERR_ARGS_BASEPARAMS);
  }
}
