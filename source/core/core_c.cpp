//
// OpenCV 2 para [x]Harbour - Biblioteca de ligação para [x]Harbour e OpenCV 2
//
// Copyright (C) 2021 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/core/core_c.h>
#include <hbapi.h>
#include <hbapiitm.h>

/*
CVAPI(void*) cvAlloc( size_t size )
*/
HB_FUNC(CVALLOC)
{
  hb_retptr((void *)cvAlloc(hb_parnl(1)));
}

/*
CVAPI(void) cvFree_( void* ptr )
*/
HB_FUNC(CVFREE_)
{
  cvFree_((void *)hb_parptr(1));
}

/*
CVAPI(IplImage*) cvCreateImageHeader( CvSize size, int depth, int channels )
*/
HB_FUNC(CVCREATEIMAGEHEADER)
{
  PHB_ITEM pSize1 = hb_param(1, HB_IT_ARRAY);
  CvSize size1;
  size1.width = hb_arrayGetNI(pSize1, 1);
  size1.height = hb_arrayGetNI(pSize1, 2);
  hb_retptr((IplImage *)cvCreateImageHeader(size1, hb_parni(2), hb_parni(3)));
}

/*
CVAPI(IplImage*) cvInitImageHeader( IplImage* image, CvSize size, int depth, int channels, int origin CV_DEFAULT(0), int
align CV_DEFAULT(4) )
*/
HB_FUNC(CVINITIMAGEHEADER)
{
  PHB_ITEM pSize2 = hb_param(2, HB_IT_ARRAY);
  CvSize size2;
  size2.width = hb_arrayGetNI(pSize2, 1);
  size2.height = hb_arrayGetNI(pSize2, 2);
  hb_retptr((IplImage *)cvInitImageHeader((IplImage *)hb_parptr(1), size2, hb_parni(3), hb_parni(4),
                                          HB_ISNIL(5) ? 0 : hb_parni(5), HB_ISNIL(6) ? 4 : hb_parni(6)));
}

/*
CVAPI(IplImage*) cvCreateImage( CvSize size, int depth, int channels )
*/
HB_FUNC(CVCREATEIMAGE)
{
  PHB_ITEM pSize1 = hb_param(1, HB_IT_ARRAY);
  CvSize size1;
  size1.width = hb_arrayGetNI(pSize1, 1);
  size1.height = hb_arrayGetNI(pSize1, 2);
  hb_retptr((IplImage *)cvCreateImage(size1, hb_parni(2), hb_parni(3)));
}

/*
CVAPI(void) cvReleaseImageHeader( IplImage** image )
*/
HB_FUNC(CVRELEASEIMAGEHEADER)
{
  cvReleaseImageHeader((IplImage **)hb_parptr(1));
}

/*
CVAPI(void) cvReleaseImage( IplImage** image )
*/
HB_FUNC(CVRELEASEIMAGE)
{
  cvReleaseImage((IplImage **)hb_parptr(1));
}

/*
CVAPI(IplImage*) cvCloneImage( const IplImage* image )
*/
HB_FUNC(CVCLONEIMAGE)
{
  hb_retptr((IplImage *)cvCloneImage((const IplImage *)hb_parptr(1)));
}

/*
CVAPI(void) cvSetImageCOI( IplImage* image, int coi )
*/
HB_FUNC(CVSETIMAGECOI)
{
  cvSetImageCOI((IplImage *)hb_parptr(1), hb_parni(2));
}

/*
CVAPI(int) cvGetImageCOI( const IplImage* image )
*/
HB_FUNC(CVGETIMAGECOI)
{
  hb_retni(cvGetImageCOI((const IplImage *)hb_parptr(1)));
}

/*
CVAPI(void) cvSetImageROI( IplImage* image, CvRect rect )
*/
HB_FUNC(CVSETIMAGEROI)
{
  PHB_ITEM pRect2 = hb_param(2, HB_IT_ARRAY);
  CvRect rect2;
  rect2.x = hb_arrayGetNI(pRect2, 1);
  rect2.y = hb_arrayGetNI(pRect2, 2);
  rect2.width = hb_arrayGetNI(pRect2, 3);
  rect2.height = hb_arrayGetNI(pRect2, 4);
  cvSetImageROI((IplImage *)hb_parptr(1), rect2);
}

/*
CVAPI(void) cvResetImageROI( IplImage* image )
*/
HB_FUNC(CVRESETIMAGEROI)
{
  cvResetImageROI((IplImage *)hb_parptr(1));
}

/*
CVAPI(CvRect) cvGetImageROI( const IplImage* image )
*/
HB_FUNC(CVGETIMAGEROI)
{
  CvRect rect;
  rect = cvGetImageROI((const IplImage *)hb_parptr(1));
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

/*
CVAPI(CvMat*) cvCreateMatHeader( int rows, int cols, int type )
*/
HB_FUNC(CVCREATEMATHEADER)
{
  hb_retptr((CvMat *)cvCreateMatHeader(hb_parni(1), hb_parni(2), hb_parni(3)));
}

/*
CVAPI(CvMat*) cvInitMatHeader( CvMat* mat, int rows, int cols, int type, void* data CV_DEFAULT(NULL), int step
CV_DEFAULT(CV_AUTOSTEP) )
*/
HB_FUNC(CVINITMATHEADER)
{
  hb_retptr((CvMat *)cvInitMatHeader((CvMat *)hb_parptr(1), hb_parni(2), hb_parni(3), hb_parni(4),
                                     HB_ISNIL(5) ? NULL : (void *)hb_parptr(5), HB_ISNIL(6) ? CV_AUTOSTEP : hb_parni(6)));
}

/*
CVAPI(CvMat*) cvCreateMat( int rows, int cols, int type )
*/
HB_FUNC(CVCREATEMAT)
{
  hb_retptr((CvMat *)cvCreateMat(hb_parni(1), hb_parni(2), hb_parni(3)));
}

/*
CVAPI(void) cvReleaseMat( CvMat** mat )
*/
HB_FUNC(CVRELEASEMAT)
{
  cvReleaseMat((CvMat **)hb_parptr(1));
}

/*
CV_INLINE void cvDecRefData( CvArr* arr )
*/
HB_FUNC(CVDECREFDATA)
{
  cvDecRefData((CvArr *)hb_parptr(1));
}

/*
CV_INLINE int cvIncRefData( CvArr* arr )
*/
HB_FUNC(CVINCREFDATA)
{
  hb_retni(cvIncRefData((CvArr *)hb_parptr(1)));
}

/*
CVAPI(CvMat*) cvCloneMat( const CvMat* mat )
*/
HB_FUNC(CVCLONEMAT)
{
  hb_retptr((CvMat *)cvCloneMat((const CvMat *)hb_parptr(1)));
}

/*
CVAPI(CvMat*) cvGetSubRect( const CvArr* arr, CvMat* submat, CvRect rect )
*/
HB_FUNC(CVGETSUBRECT)
{
  PHB_ITEM pRect3 = hb_param(3, HB_IT_ARRAY);
  CvRect rect3;
  rect3.x = hb_arrayGetNI(pRect3, 1);
  rect3.y = hb_arrayGetNI(pRect3, 2);
  rect3.width = hb_arrayGetNI(pRect3, 3);
  rect3.height = hb_arrayGetNI(pRect3, 4);
  hb_retptr((CvMat *)cvGetSubRect((const CvArr *)hb_parptr(1), (CvMat *)hb_parptr(2), rect3));
}

/*
CVAPI(CvMat*) cvGetRows( const CvArr* arr, CvMat* submat, int start_row, int end_row, int delta_row CV_DEFAULT(1) )
*/
HB_FUNC(CVGETROWS)
{
  hb_retptr((CvMat *)cvGetRows((const CvArr *)hb_parptr(1), (CvMat *)hb_parptr(2), hb_parni(3), hb_parni(4),
                               HB_ISNIL(5) ? 1 : hb_parni(5)));
}

/*
CV_INLINE CvMat* cvGetRow( const CvArr* arr, CvMat* submat, int row )
*/
HB_FUNC(CVGETROW)
{
  hb_retptr((CvMat *)cvGetRow((const CvArr *)hb_parptr(1), (CvMat *)hb_parptr(2), hb_parni(3)));
}

/*
CVAPI(CvMat*) cvGetCols( const CvArr* arr, CvMat* submat, int start_col, int end_col )
*/
HB_FUNC(CVGETCOLS)
{
  hb_retptr((CvMat *)cvGetCols((const CvArr *)hb_parptr(1), (CvMat *)hb_parptr(2), hb_parni(3), hb_parni(4)));
}

/*
CV_INLINE CvMat* cvGetCol( const CvArr* arr, CvMat* submat, int col )
*/
HB_FUNC(CVGETCOL)
{
  hb_retptr((CvMat *)cvGetCol((const CvArr *)hb_parptr(1), (CvMat *)hb_parptr(2), hb_parni(3)));
}

/*
CVAPI(CvMat*) cvGetDiag( const CvArr* arr, CvMat* submat, int diag CV_DEFAULT(0) )
*/
HB_FUNC(CVGETDIAG)
{
  hb_retptr((CvMat *)cvGetDiag((const CvArr *)hb_parptr(1), (CvMat *)hb_parptr(2), HB_ISNIL(3) ? 0 : hb_parni(3)));
}

/*
CVAPI(CvMatND*) cvCreateMatNDHeader( int dims, const int* sizes, int type )
*/
HB_FUNC(CVCREATEMATNDHEADER)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  hb_retptr((CvMatND *)cvCreateMatNDHeader(hb_parni(1), (const int *)values2, hb_parni(3)));
  if (a2)
  {
    delete[] values2;
  }
}

/*
CVAPI(CvMatND*) cvCreateMatND( int dims, const int* sizes, int type )
*/
HB_FUNC(CVCREATEMATND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  hb_retptr((CvMatND *)cvCreateMatND(hb_parni(1), (const int *)values2, hb_parni(3)));
  if (a2)
  {
    delete[] values2;
  }
}

/*
CVAPI(CvMatND*) cvInitMatNDHeader( CvMatND* mat, int dims, const int* sizes, int type, void* data CV_DEFAULT(NULL) )
*/
HB_FUNC(CVINITMATNDHEADER)
{
  PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
  int *values3;
  if (a3)
  {
    const int lenght = hb_arrayLen(a3);
    values3 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values3[i] = hb_arrayGetNI(a3, i + 1);
    }
  }
  hb_retptr((CvMatND *)cvInitMatNDHeader((CvMatND *)hb_parptr(1), hb_parni(2), (const int *)values3, hb_parni(4),
                                         HB_ISNIL(5) ? NULL : (void *)hb_parptr(5)));
  if (a3)
  {
    delete[] values3;
  }
}

/*
CV_INLINE void cvReleaseMatND( CvMatND** mat )
*/
HB_FUNC(CVRELEASEMATND)
{
  cvReleaseMatND((CvMatND **)hb_parptr(1));
}

/*
CVAPI(CvMatND*) cvCloneMatND( const CvMatND* mat )
*/
HB_FUNC(CVCLONEMATND)
{
  hb_retptr((CvMatND *)cvCloneMatND((const CvMatND *)hb_parptr(1)));
}

/*
CVAPI(CvSparseMat*) cvCreateSparseMat( int dims, const int* sizes, int type )
*/
HB_FUNC(CVCREATESPARSEMAT)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  hb_retptr((CvSparseMat *)cvCreateSparseMat(hb_parni(1), (const int *)values2, hb_parni(3)));
  if (a2)
  {
    delete[] values2;
  }
}

/*
CVAPI(void) cvReleaseSparseMat( CvSparseMat** mat )
*/
HB_FUNC(CVRELEASESPARSEMAT)
{
  cvReleaseSparseMat((CvSparseMat **)hb_parptr(1));
}

/*
CVAPI(CvSparseMat*) cvCloneSparseMat( const CvSparseMat* mat )
*/
HB_FUNC(CVCLONESPARSEMAT)
{
  hb_retptr((CvSparseMat *)cvCloneSparseMat((const CvSparseMat *)hb_parptr(1)));
}

/*
CVAPI(CvSparseNode*) cvInitSparseMatIterator( const CvSparseMat* mat, CvSparseMatIterator* mat_iterator )
*/
HB_FUNC(CVINITSPARSEMATITERATOR)
{
  hb_retptr(
      (CvSparseNode *)cvInitSparseMatIterator((const CvSparseMat *)hb_parptr(1), (CvSparseMatIterator *)hb_parptr(2)));
}

/*
CV_INLINE CvSparseNode* cvGetNextSparseNode( CvSparseMatIterator* mat_iterator )
*/
HB_FUNC(CVGETNEXTSPARSENODE)
{
  hb_retptr((CvSparseNode *)cvGetNextSparseNode((CvSparseMatIterator *)hb_parptr(1)));
}

/*
CVAPI(int) cvInitNArrayIterator( int count, CvArr** arrs, const CvArr* mask, CvMatND* stubs, CvNArrayIterator*
array_iterator, int flags CV_DEFAULT(0) )
*/
HB_FUNC(CVINITNARRAYITERATOR)
{
  hb_retni(cvInitNArrayIterator(hb_parni(1), (CvArr **)hb_parptr(2), (const CvArr *)hb_parptr(3),
                                (CvMatND *)hb_parptr(4), (CvNArrayIterator *)hb_parptr(5), HB_ISNIL(6) ? 0 : hb_parni(6)));
}

/*
CVAPI(int) cvNextNArraySlice( CvNArrayIterator* array_iterator )
*/
HB_FUNC(CVNEXTNARRAYSLICE)
{
  hb_retni(cvNextNArraySlice((CvNArrayIterator *)hb_parptr(1)));
}

/*
CVAPI(int) cvGetElemType( const CvArr* arr )
*/
HB_FUNC(CVGETELEMTYPE)
{
  hb_retni(cvGetElemType((const CvArr *)hb_parptr(1)));
}

/*
CVAPI(int) cvGetDimSize( const CvArr* arr, int index )
*/
HB_FUNC(CVGETDIMSIZE)
{
  hb_retni(cvGetDimSize((const CvArr *)hb_parptr(1), hb_parni(2)));
}

/*
CVAPI(CvScalar) cvGet1D( const CvArr* arr, int idx0 )
*/
HB_FUNC(CVGET1D)
{
  CvScalar scalar;
  scalar = cvGet1D((const CvArr *)hb_parptr(1), hb_parni(2));
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

/*
CVAPI(CvScalar) cvGet2D( const CvArr* arr, int idx0, int idx1 )
*/
HB_FUNC(CVGET2D)
{
  CvScalar scalar;
  scalar = cvGet2D((const CvArr *)hb_parptr(1), hb_parni(2), hb_parni(3));
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

/*
CVAPI(CvScalar) cvGet3D( const CvArr* arr, int idx0, int idx1, int idx2 )
*/
HB_FUNC(CVGET3D)
{
  CvScalar scalar;
  scalar = cvGet3D((const CvArr *)hb_parptr(1), hb_parni(2), hb_parni(3), hb_parni(4));
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

/*
CVAPI(CvScalar) cvGetND( const CvArr* arr, const int* idx )
*/
HB_FUNC(CVGETND)
{
  CvScalar scalar;
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  scalar = cvGetND((const CvArr *)hb_parptr(1), (const int *)values2);
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

/*
CVAPI(double) cvGetReal1D( const CvArr* arr, int idx0 )
*/
HB_FUNC(CVGETREAL1D)
{
  hb_retnd(cvGetReal1D((const CvArr *)hb_parptr(1), hb_parni(2)));
}

/*
CVAPI(double) cvGetReal2D( const CvArr* arr, int idx0, int idx1 )
*/
HB_FUNC(CVGETREAL2D)
{
  hb_retnd(cvGetReal2D((const CvArr *)hb_parptr(1), hb_parni(2), hb_parni(3)));
}

/*
CVAPI(double) cvGetReal3D( const CvArr* arr, int idx0, int idx1, int idx2 )
*/
HB_FUNC(CVGETREAL3D)
{
  hb_retnd(cvGetReal3D((const CvArr *)hb_parptr(1), hb_parni(2), hb_parni(3), hb_parni(4)));
}

/*
CVAPI(double) cvGetRealND( const CvArr* arr, const int* idx )
*/
HB_FUNC(CVGETREALND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  hb_retnd(cvGetRealND((const CvArr *)hb_parptr(1), (const int *)values2));
  if (a2)
  {
    delete[] values2;
  }
}

/*
CVAPI(void) cvSet1D( CvArr* arr, int idx0, CvScalar value )
*/
HB_FUNC(CVSET1D)
{
  PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
  CvScalar scalar3;
  scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
  scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
  scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
  scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
  cvSet1D((CvArr *)hb_parptr(1), hb_parni(2), scalar3);
}

/*
CVAPI(void) cvSet2D( CvArr* arr, int idx0, int idx1, CvScalar value )
*/
HB_FUNC(CVSET2D)
{
  PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
  CvScalar scalar4;
  scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
  scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
  scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
  scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
  cvSet2D((CvArr *)hb_parptr(1), hb_parni(2), hb_parni(3), scalar4);
}

/*
CVAPI(void) cvSet3D( CvArr* arr, int idx0, int idx1, int idx2, CvScalar value )
*/
HB_FUNC(CVSET3D)
{
  PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
  CvScalar scalar5;
  scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
  scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
  scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
  scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
  cvSet3D((CvArr *)hb_parptr(1), hb_parni(2), hb_parni(3), hb_parni(4), scalar5);
}

/*
CVAPI(void) cvSetND( CvArr* arr, const int* idx, CvScalar value )
*/
HB_FUNC(CVSETND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
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
  cvSetND((CvArr *)hb_parptr(1), (const int *)values2, scalar3);
  if (a2)
  {
    delete[] values2;
  }
}

/*
CVAPI(void) cvSetReal1D( CvArr* arr, int idx0, double value )
*/
HB_FUNC(CVSETREAL1D)
{
  cvSetReal1D((CvArr *)hb_parptr(1), hb_parni(2), hb_parnd(3));
}

/*
CVAPI(void) cvSetReal2D( CvArr* arr, int idx0, int idx1, double value )
*/
HB_FUNC(CVSETREAL2D)
{
  cvSetReal2D((CvArr *)hb_parptr(1), hb_parni(2), hb_parni(3), hb_parnd(4));
}

/*
CVAPI(void) cvSetReal3D( CvArr* arr, int idx0, int idx1, int idx2, double value )
*/
HB_FUNC(CVSETREAL3D)
{
  cvSetReal3D((CvArr *)hb_parptr(1), hb_parni(2), hb_parni(3), hb_parni(4), hb_parnd(5));
}

/*
CVAPI(void) cvSetRealND( CvArr* arr, const int* idx, double value )
*/
HB_FUNC(CVSETREALND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  cvSetRealND((CvArr *)hb_parptr(1), (const int *)values2, hb_parnd(3));
  if (a2)
  {
    delete[] values2;
  }
}

/*
CVAPI(void) cvClearND( CvArr* arr, const int* idx )
*/
HB_FUNC(CVCLEARND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  cvClearND((CvArr *)hb_parptr(1), (const int *)values2);
  if (a2)
  {
    delete[] values2;
  }
}

/*
CVAPI(IplImage*) cvGetImage( const CvArr* arr, IplImage* image_header )
*/
HB_FUNC(CVGETIMAGE)
{
  hb_retptr((IplImage *)cvGetImage((const CvArr *)hb_parptr(1), (IplImage *)hb_parptr(2)));
}

/*
CVAPI(CvMat*) cvReshape( const CvArr* arr, CvMat* header, int new_cn, int new_rows CV_DEFAULT(0) )
*/
HB_FUNC(CVRESHAPE)
{
  hb_retptr(
      (CvMat *)cvReshape((const CvArr *)hb_parptr(1), (CvMat *)hb_parptr(2), hb_parni(3), HB_ISNIL(4) ? 0 : hb_parni(4)));
}

/*
CVAPI(void) cvRepeat( const CvArr* src, CvArr* dst )
*/
HB_FUNC(CVREPEAT)
{
  cvRepeat((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2));
}

/*
CVAPI(void) cvCreateData( CvArr* arr )
*/
HB_FUNC(CVCREATEDATA)
{
  cvCreateData((CvArr *)hb_parptr(1));
}

/*
CVAPI(void) cvReleaseData( CvArr* arr )
*/
HB_FUNC(CVRELEASEDATA)
{
  cvReleaseData((CvArr *)hb_parptr(1));
}

/*
CVAPI(void) cvSetData( CvArr* arr, void* data, int step )
*/
HB_FUNC(CVSETDATA)
{
  cvSetData((CvArr *)hb_parptr(1), (void *)hb_parptr(2), hb_parni(3));
}

/*
CVAPI(CvSize) cvGetSize( const CvArr* arr )
*/
HB_FUNC(CVGETSIZE)
{
  CvSize size;
  size = cvGetSize((const CvArr *)hb_parptr(1));
  PHB_ITEM a = hb_itemArrayNew(2);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutNI(t, size.width);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutNI(t, size.height);
  hb_itemArrayPut(a, 2, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

/*
CVAPI(void) cvCopy( const CvArr* src, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVCOPY)
{
  cvCopy((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? NULL : (const CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvSet( CvArr* arr, CvScalar value, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSET)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvSet((CvArr *)hb_parptr(1), scalar2, HB_ISNIL(3) ? NULL : (const CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvSetZero( CvArr* arr )
*/
HB_FUNC(CVSETZERO)
{
  cvSetZero((CvArr *)hb_parptr(1));
}

/*
CVAPI(void) cvSplit( const CvArr* src, CvArr* dst0, CvArr* dst1, CvArr* dst2, CvArr* dst3 )
*/
HB_FUNC(CVSPLIT)
{
  cvSplit((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), (CvArr *)hb_parptr(4),
          (CvArr *)hb_parptr(5));
}

/*
CVAPI(void) cvMerge( const CvArr* src0, const CvArr* src1, const CvArr* src2, const CvArr* src3, CvArr* dst )
*/
HB_FUNC(CVMERGE)
{
  cvMerge((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (const CvArr *)hb_parptr(3),
          (const CvArr *)hb_parptr(4), (CvArr *)hb_parptr(5));
}

/*
CVAPI(void) cvMixChannels( const CvArr** src, int src_count, CvArr** dst, int dst_count, const int* from_to, int
pair_count )
*/
HB_FUNC(CVMIXCHANNELS)
{
  PHB_ITEM a5 = hb_param(5, HB_IT_ARRAY);
  int *values5;
  if (a5)
  {
    const int lenght = hb_arrayLen(a5);
    values5 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values5[i] = hb_arrayGetNI(a5, i + 1);
    }
  }
  cvMixChannels((const CvArr **)hb_parptr(1), hb_parni(2), (CvArr **)hb_parptr(3), hb_parni(4), (const int *)values5,
                hb_parni(6));
  if (a5)
  {
    delete[] values5;
  }
}

/*
CVAPI(void) cvConvertScale( const CvArr* src, CvArr* dst, double scale CV_DEFAULT(1), double shift CV_DEFAULT(0) )
*/
HB_FUNC(CVCONVERTSCALE)
{
  cvConvertScale((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? 1 : hb_parnd(3),
                 HB_ISNIL(4) ? 0 : hb_parnd(4));
}

/*
CVAPI(void) cvConvertScaleAbs( const CvArr* src, CvArr* dst, double scale CV_DEFAULT(1), double shift CV_DEFAULT(0) )
*/
HB_FUNC(CVCONVERTSCALEABS)
{
  cvConvertScaleAbs((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? 1 : hb_parnd(3),
                    HB_ISNIL(4) ? 0 : hb_parnd(4));
}

/*
CVAPI(CvTermCriteria) cvCheckTermCriteria( CvTermCriteria criteria, double default_eps, int default_max_iters )
*/
HB_FUNC(CVCHECKTERMCRITERIA)
{
  CvTermCriteria tc;
  PHB_ITEM pTC1 = hb_param(1, HB_IT_ARRAY);
  CvTermCriteria tc1;
  tc1.type = hb_arrayGetNI(pTC1, 1);
  tc1.max_iter = hb_arrayGetNI(pTC1, 2);
  tc1.epsilon = hb_arrayGetND(pTC1, 3);
  tc = cvCheckTermCriteria(tc1, hb_parnd(2), hb_parni(3));
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

/*
CVAPI(void) cvAdd( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVADD)
{
  cvAdd((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
        HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvAddS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVADDS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvAddS((const CvArr *)hb_parptr(1), scalar2, (CvArr *)hb_parptr(3), HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvSub( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSUB)
{
  cvSub((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
        HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CV_INLINE void cvSubS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSUBS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvSubS((const CvArr *)hb_parptr(1), scalar2, (CvArr *)hb_parptr(3), HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvSubRS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSUBRS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvSubRS((const CvArr *)hb_parptr(1), scalar2, (CvArr *)hb_parptr(3), HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvMul( const CvArr* src1, const CvArr* src2, CvArr* dst, double scale CV_DEFAULT(1) )
*/
HB_FUNC(CVMUL)
{
  cvMul((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), HB_ISNIL(4) ? 1 : hb_parnd(4));
}

/*
CVAPI(void) cvDiv( const CvArr* src1, const CvArr* src2, CvArr* dst, double scale CV_DEFAULT(1) )
*/
HB_FUNC(CVDIV)
{
  cvDiv((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), HB_ISNIL(4) ? 1 : hb_parnd(4));
}

/*
CVAPI(void) cvScaleAdd( const CvArr* src1, CvScalar scale, const CvArr* src2, CvArr* dst )
*/
HB_FUNC(CVSCALEADD)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvScaleAdd((const CvArr *)hb_parptr(1), scalar2, (const CvArr *)hb_parptr(3), (CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvAddWeighted( const CvArr* src1, double alpha, const CvArr* src2, double beta, double gamma, CvArr* dst )
*/
HB_FUNC(CVADDWEIGHTED)
{
  cvAddWeighted((const CvArr *)hb_parptr(1), hb_parnd(2), (const CvArr *)hb_parptr(3), hb_parnd(4), hb_parnd(5),
                (CvArr *)hb_parptr(6));
}

/*
CVAPI(double) cvDotProduct( const CvArr* src1, const CvArr* src2 )
*/
HB_FUNC(CVDOTPRODUCT)
{
  hb_retnd(cvDotProduct((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2)));
}

/*
CVAPI(void) cvAnd( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVAND)
{
  cvAnd((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
        HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvAndS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVANDS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvAndS((const CvArr *)hb_parptr(1), scalar2, (CvArr *)hb_parptr(3), HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvOr( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVOR)
{
  cvOr((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
       HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvOrS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVORS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvOrS((const CvArr *)hb_parptr(1), scalar2, (CvArr *)hb_parptr(3), HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvXor( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVXOR)
{
  cvXor((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
        HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvXorS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVXORS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvXorS((const CvArr *)hb_parptr(1), scalar2, (CvArr *)hb_parptr(3), HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvNot( const CvArr* src, CvArr* dst )
*/
HB_FUNC(CVNOT)
{
  cvNot((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2));
}

/*
CVAPI(void) cvInRange( const CvArr* src, const CvArr* lower, const CvArr* upper, CvArr* dst )
*/
HB_FUNC(CVINRANGE)
{
  cvInRange((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (const CvArr *)hb_parptr(3),
            (CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvInRangeS( const CvArr* src, CvScalar lower, CvScalar upper, CvArr* dst )
*/
HB_FUNC(CVINRANGES)
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
  cvInRangeS((const CvArr *)hb_parptr(1), scalar2, scalar3, (CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvCmp( const CvArr* src1, const CvArr* src2, CvArr* dst, int cmp_op )
*/
HB_FUNC(CVCMP)
{
  cvCmp((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), hb_parni(4));
}

/*
CVAPI(void) cvCmpS( const CvArr* src, double value, CvArr* dst, int cmp_op )
*/
HB_FUNC(CVCMPS)
{
  cvCmpS((const CvArr *)hb_parptr(1), hb_parnd(2), (CvArr *)hb_parptr(3), hb_parni(4));
}

/*
CVAPI(void) cvMin( const CvArr* src1, const CvArr* src2, CvArr* dst )
*/
HB_FUNC(CVMIN)
{
  cvMin((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvMax( const CvArr* src1, const CvArr* src2, CvArr* dst )
*/
HB_FUNC(CVMAX)
{
  cvMax((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvMinS( const CvArr* src, double value, CvArr* dst )
*/
HB_FUNC(CVMINS)
{
  cvMinS((const CvArr *)hb_parptr(1), hb_parnd(2), (CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvMaxS( const CvArr* src, double value, CvArr* dst )
*/
HB_FUNC(CVMAXS)
{
  cvMaxS((const CvArr *)hb_parptr(1), hb_parnd(2), (CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvAbsDiff( const CvArr* src1, const CvArr* src2, CvArr* dst )
*/
HB_FUNC(CVABSDIFF)
{
  cvAbsDiff((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvAbsDiffS( const CvArr* src, CvArr* dst, CvScalar value )
*/
HB_FUNC(CVABSDIFFS)
{
  PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
  CvScalar scalar3;
  scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
  scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
  scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
  scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
  cvAbsDiffS((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), scalar3);
}

/*
CVAPI(void) cvCartToPolar( const CvArr* x, const CvArr* y, CvArr* magnitude, CvArr* angle CV_DEFAULT(NULL), int
angle_in_degrees CV_DEFAULT(0) )
*/
HB_FUNC(CVCARTTOPOLAR)
{
  cvCartToPolar((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
                HB_ISNIL(4) ? NULL : (CvArr *)hb_parptr(4), HB_ISNIL(5) ? 0 : hb_parni(5));
}

/*
CVAPI(void) cvPolarToCart( const CvArr* magnitude, const CvArr* angle, CvArr* x, CvArr* y, int angle_in_degrees
CV_DEFAULT(0) )
*/
HB_FUNC(CVPOLARTOCART)
{
  cvPolarToCart((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), (CvArr *)hb_parptr(4),
                HB_ISNIL(5) ? 0 : hb_parni(5));
}

/*
CVAPI(void) cvPow( const CvArr* src, CvArr* dst, double power )
*/
HB_FUNC(CVPOW)
{
  cvPow((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parnd(3));
}

/*
CVAPI(void) cvExp( const CvArr* src, CvArr* dst )
*/
HB_FUNC(CVEXP)
{
  cvExp((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2));
}

/*
CVAPI(void) cvLog( const CvArr* src, CvArr* dst )
*/
HB_FUNC(CVLOG)
{
  cvLog((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2));
}

/*
CVAPI(float) cvFastArctan( float y, float x )
*/
HB_FUNC(CVFASTARCTAN)
{
  hb_retnd((float)cvFastArctan((float)hb_parnd(1), (float)hb_parnd(2)));
}

/*
CVAPI(float) cvCbrt( float value )
*/
HB_FUNC(CVCBRT)
{
  hb_retnd((float)cvCbrt((float)hb_parnd(1)));
}

/*
CVAPI(int) cvCheckArr( const CvArr* arr, int flags CV_DEFAULT(0), double min_val CV_DEFAULT(0), double max_val
CV_DEFAULT(0) )
*/
HB_FUNC(CVCHECKARR)
{
  hb_retni(cvCheckArr((const CvArr *)hb_parptr(1), HB_ISNIL(2) ? 0 : hb_parni(2), HB_ISNIL(3) ? 0 : hb_parnd(3),
                      HB_ISNIL(4) ? 0 : hb_parnd(4)));
}

/*
CVAPI(void) cvSort( const CvArr* src, CvArr* dst CV_DEFAULT(NULL), CvArr* idxmat CV_DEFAULT(NULL), int flags
CV_DEFAULT(0) )
*/
HB_FUNC(CVSORT)
{
  cvSort((const CvArr *)hb_parptr(1), HB_ISNIL(2) ? NULL : (CvArr *)hb_parptr(2), HB_ISNIL(3) ? NULL : (CvArr *)hb_parptr(3),
         HB_ISNIL(4) ? 0 : hb_parni(4));
}

/*
CVAPI(int) cvSolveCubic( const CvMat* coeffs, CvMat* roots )
*/
HB_FUNC(CVSOLVECUBIC)
{
  hb_retni(cvSolveCubic((const CvMat *)hb_parptr(1), (CvMat *)hb_parptr(2)));
}

/*
CVAPI(void) cvSolvePoly( const CvMat* coeffs, CvMat* roots2, int maxiter CV_DEFAULT(20), int fig CV_DEFAULT(100) )
*/
HB_FUNC(CVSOLVEPOLY)
{
  cvSolvePoly((const CvMat *)hb_parptr(1), (CvMat *)hb_parptr(2), HB_ISNIL(3) ? 20 : hb_parni(3),
              HB_ISNIL(4) ? 100 : hb_parni(4));
}

/*
CVAPI(void) cvCrossProduct( const CvArr* src1, const CvArr* src2, CvArr* dst )
*/
HB_FUNC(CVCROSSPRODUCT)
{
  cvCrossProduct((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvGEMM( const CvArr* src1, const CvArr* src2, double alpha, const CvArr* src3, double beta, CvArr* dst, int
tABC CV_DEFAULT(0) )
*/
HB_FUNC(CVGEMM)
{
  cvGEMM((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), hb_parnd(3), (const CvArr *)hb_parptr(4),
         hb_parnd(5), (CvArr *)hb_parptr(6), HB_ISNIL(7) ? 0 : hb_parni(7));
}

/*
CVAPI(void) cvTransform( const CvArr* src, CvArr* dst, const CvMat* transmat, const CvMat* shiftvec CV_DEFAULT(NULL) )
*/
HB_FUNC(CVTRANSFORM)
{
  cvTransform((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvMat *)hb_parptr(3),
              HB_ISNIL(4) ? NULL : (const CvMat *)hb_parptr(4));
}

/*
CVAPI(void) cvPerspectiveTransform( const CvArr* src, CvArr* dst, const CvMat* mat )
*/
HB_FUNC(CVPERSPECTIVETRANSFORM)
{
  cvPerspectiveTransform((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvMat *)hb_parptr(3));
}

/*
CVAPI(void) cvMulTransposed( const CvArr* src, CvArr* dst, int order, const CvArr* delta CV_DEFAULT(NULL), double scale
CV_DEFAULT(1.) )
*/
HB_FUNC(CVMULTRANSPOSED)
{
  cvMulTransposed((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parni(3),
                  HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4), HB_ISNIL(5) ? 1. : hb_parnd(5));
}

/*
CVAPI(void) cvTranspose( const CvArr* src, CvArr* dst )
*/
HB_FUNC(CVTRANSPOSE)
{
  cvTranspose((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2));
}

/*
CVAPI(void) cvCompleteSymm( CvMat* matrix, int LtoR CV_DEFAULT(0) )
*/
HB_FUNC(CVCOMPLETESYMM)
{
  cvCompleteSymm((CvMat *)hb_parptr(1), HB_ISNIL(2) ? 0 : hb_parni(2));
}

/*
CVAPI(void) cvFlip( const CvArr* src, CvArr* dst CV_DEFAULT(NULL), int flip_mode CV_DEFAULT(0) )
*/
HB_FUNC(CVFLIP)
{
  cvFlip((const CvArr *)hb_parptr(1), HB_ISNIL(2) ? NULL : (CvArr *)hb_parptr(2), HB_ISNIL(3) ? 0 : hb_parni(3));
}

/*
CVAPI(void) cvSVD( CvArr* A, CvArr* W, CvArr* U CV_DEFAULT(NULL), CvArr* V CV_DEFAULT(NULL), int flags CV_DEFAULT(0) )
*/
HB_FUNC(CVSVD)
{
  cvSVD((CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? NULL : (CvArr *)hb_parptr(3),
        HB_ISNIL(4) ? NULL : (CvArr *)hb_parptr(4), HB_ISNIL(5) ? 0 : hb_parni(5));
}

/*
CVAPI(void) cvSVBkSb( const CvArr* W, const CvArr* U, const CvArr* V, const CvArr* B, CvArr* X, int flags )
*/
HB_FUNC(CVSVBKSB)
{
  cvSVBkSb((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (const CvArr *)hb_parptr(3),
           (const CvArr *)hb_parptr(4), (CvArr *)hb_parptr(5), hb_parni(6));
}

/*
CVAPI(double) cvInvert( const CvArr* src, CvArr* dst, int method CV_DEFAULT(CV_LU) )
*/
HB_FUNC(CVINVERT)
{
  hb_retnd(cvInvert((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? CV_LU : hb_parni(3)));
}

/*
CVAPI(int) cvSolve( const CvArr* src1, const CvArr* src2, CvArr* dst, int method CV_DEFAULT(CV_LU) )
*/
HB_FUNC(CVSOLVE)
{
  hb_retni(cvSolve((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
                   HB_ISNIL(4) ? CV_LU : hb_parni(4)));
}

/*
CVAPI(double) cvDet( const CvArr* mat )
*/
HB_FUNC(CVDET)
{
  hb_retnd(cvDet((const CvArr *)hb_parptr(1)));
}

/*
CVAPI(CvScalar) cvTrace( const CvArr* mat )
*/
HB_FUNC(CVTRACE)
{
  CvScalar scalar;
  scalar = cvTrace((const CvArr *)hb_parptr(1));
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

/*
CVAPI(void) cvEigenVV( CvArr* mat, CvArr* evects, CvArr* evals, double eps CV_DEFAULT(0), int lowindex CV_DEFAULT(-1),
int highindex CV_DEFAULT(-1) )
*/
HB_FUNC(CVEIGENVV)
{
  cvEigenVV((CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), HB_ISNIL(4) ? 0 : hb_parnd(4),
            HB_ISNIL(5) ? -1 : hb_parni(5), HB_ISNIL(6) ? -1 : hb_parni(6));
}

/*
CVAPI(void) cvSetIdentity( CvArr* mat, CvScalar value CV_DEFAULT(cvRealScalar(1)) )
*/
HB_FUNC(CVSETIDENTITY)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvSetIdentity((CvArr *)hb_parptr(1), HB_ISNIL(2) ? cvRealScalar(1) : scalar2);
}

/*
CVAPI(CvArr*) cvRange( CvArr* mat, double start, double end )
*/
HB_FUNC(CVRANGE)
{
  hb_retptr((CvArr *)cvRange((CvArr *)hb_parptr(1), hb_parnd(2), hb_parnd(3)));
}

/*
CVAPI(void) cvCalcCovarMatrix( const CvArr** vects, int count, CvArr* cov_mat, CvArr* avg, int flags )
*/
HB_FUNC(CVCALCCOVARMATRIX)
{
  cvCalcCovarMatrix((const CvArr **)hb_parptr(1), hb_parni(2), (CvArr *)hb_parptr(3), (CvArr *)hb_parptr(4),
                    hb_parni(5));
}

/*
CVAPI(void) cvCalcPCA( const CvArr* data, CvArr* mean, CvArr* eigenvals, CvArr* eigenvects, int flags )
*/
HB_FUNC(CVCALCPCA)
{
  cvCalcPCA((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), (CvArr *)hb_parptr(4),
            hb_parni(5));
}

/*
CVAPI(void) cvProjectPCA( const CvArr* data, const CvArr* mean, const CvArr* eigenvects, CvArr* result )
*/
HB_FUNC(CVPROJECTPCA)
{
  cvProjectPCA((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (const CvArr *)hb_parptr(3),
               (CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvBackProjectPCA( const CvArr* proj, const CvArr* mean, const CvArr* eigenvects, CvArr* result )
*/
HB_FUNC(CVBACKPROJECTPCA)
{
  cvBackProjectPCA((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (const CvArr *)hb_parptr(3),
                   (CvArr *)hb_parptr(4));
}

/*
CVAPI(double) cvMahalanobis( const CvArr* vec1, const CvArr* vec2, const CvArr* mat )
*/
HB_FUNC(CVMAHALANOBIS)
{
  hb_retnd(cvMahalanobis((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (const CvArr *)hb_parptr(3)));
}

/*
CVAPI(CvScalar) cvSum( const CvArr* arr )
*/
HB_FUNC(CVSUM)
{
  CvScalar scalar;
  scalar = cvSum((const CvArr *)hb_parptr(1));
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

/*
CVAPI(int) cvCountNonZero( const CvArr* arr )
*/
HB_FUNC(CVCOUNTNONZERO)
{
  hb_retni(cvCountNonZero((const CvArr *)hb_parptr(1)));
}

/*
CVAPI(CvScalar) cvAvg( const CvArr* arr, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVAVG)
{
  CvScalar scalar;
  scalar = cvAvg((const CvArr *)hb_parptr(1), HB_ISNIL(2) ? NULL : (const CvArr *)hb_parptr(2));
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

/*
CVAPI(double) cvNorm( const CvArr* arr1, const CvArr* arr2 CV_DEFAULT(NULL), int norm_type CV_DEFAULT(CV_L2), const
CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVNORM)
{
  hb_retnd(cvNorm((const CvArr *)hb_parptr(1), HB_ISNIL(2) ? NULL : (const CvArr *)hb_parptr(2),
                  HB_ISNIL(3) ? CV_L2 : hb_parni(3), HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4)));
}

/*
CVAPI(void) cvNormalize( const CvArr* src, CvArr* dst, double a CV_DEFAULT(1.), double b CV_DEFAULT(0.), int norm_type
CV_DEFAULT(CV_L2), const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVNORMALIZE)
{
  cvNormalize((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? 1. : hb_parnd(3),
              HB_ISNIL(4) ? 0. : hb_parnd(4), HB_ISNIL(5) ? CV_L2 : hb_parni(5),
              HB_ISNIL(6) ? NULL : (const CvArr *)hb_parptr(6));
}

/*
CVAPI(void) cvReduce( const CvArr* src, CvArr* dst, int dim CV_DEFAULT(-1), int op CV_DEFAULT(CV_REDUCE_SUM) )
*/
HB_FUNC(CVREDUCE)
{
  cvReduce((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? -1 : hb_parni(3),
           HB_ISNIL(4) ? CV_REDUCE_SUM : hb_parni(4));
}

/*
CVAPI(void) cvDFT( const CvArr* src, CvArr* dst, int flags, int nonzero_rows CV_DEFAULT(0) )
*/
HB_FUNC(CVDFT)
{
  cvDFT((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parni(3), HB_ISNIL(4) ? 0 : hb_parni(4));
}

/*
CVAPI(void) cvMulSpectrums( const CvArr* src1, const CvArr* src2, CvArr* dst, int flags )
*/
HB_FUNC(CVMULSPECTRUMS)
{
  cvMulSpectrums((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), hb_parni(4));
}

/*
CVAPI(int) cvGetOptimalDFTSize( int size0 )
*/
HB_FUNC(CVGETOPTIMALDFTSIZE)
{
  hb_retni(cvGetOptimalDFTSize(hb_parni(1)));
}

/*
CVAPI(void) cvDCT( const CvArr* src, CvArr* dst, int flags )
*/
HB_FUNC(CVDCT)
{
  cvDCT((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parni(3));
}

/*
CVAPI(int) cvSliceLength( CvSlice slice, const CvSeq* seq )
*/
HB_FUNC(CVSLICELENGTH)
{
  PHB_ITEM pSlice1 = hb_param(1, HB_IT_ARRAY);
  CvSlice slice1;
  slice1.start_index = hb_arrayGetNI(pSlice1, 1);
  slice1.end_index = hb_arrayGetNI(pSlice1, 2);
  hb_retni(cvSliceLength(slice1, (const CvSeq *)hb_parptr(2)));
}

/*
CVAPI(CvMemStorage*) cvCreateMemStorage( int block_size CV_DEFAULT(0) )
*/
HB_FUNC(CVCREATEMEMSTORAGE)
{
  hb_retptr((CvMemStorage *)cvCreateMemStorage(HB_ISNIL(1) ? 0 : hb_parni(1)));
}

/*
CVAPI(CvMemStorage*) cvCreateChildMemStorage( CvMemStorage* parent )
*/
HB_FUNC(CVCREATECHILDMEMSTORAGE)
{
  hb_retptr((CvMemStorage *)cvCreateChildMemStorage((CvMemStorage *)hb_parptr(1)));
}

/*
CVAPI(void) cvReleaseMemStorage( CvMemStorage** storage )
*/
HB_FUNC(CVRELEASEMEMSTORAGE)
{
  cvReleaseMemStorage((CvMemStorage **)hb_parptr(1));
}

/*
CVAPI(void) cvClearMemStorage( CvMemStorage* storage )
*/
HB_FUNC(CVCLEARMEMSTORAGE)
{
  cvClearMemStorage((CvMemStorage *)hb_parptr(1));
}

/*
CVAPI(void) cvSaveMemStoragePos( const CvMemStorage* storage, CvMemStoragePos* pos )
*/
HB_FUNC(CVSAVEMEMSTORAGEPOS)
{
  cvSaveMemStoragePos((const CvMemStorage *)hb_parptr(1), (CvMemStoragePos *)hb_parptr(2));
}

/*
CVAPI(void) cvRestoreMemStoragePos( CvMemStorage* storage, CvMemStoragePos* pos )
*/
HB_FUNC(CVRESTOREMEMSTORAGEPOS)
{
  cvRestoreMemStoragePos((CvMemStorage *)hb_parptr(1), (CvMemStoragePos *)hb_parptr(2));
}

/*
CVAPI(void*) cvMemStorageAlloc( CvMemStorage* storage, size_t size )
*/
HB_FUNC(CVMEMSTORAGEALLOC)
{
  hb_retptr((void *)cvMemStorageAlloc((CvMemStorage *)hb_parptr(1), hb_parnl(2)));
}

/*
CVAPI(CvSeq*) cvCreateSeq( int seq_flags, size_t header_size, size_t elem_size, CvMemStorage* storage )
*/
HB_FUNC(CVCREATESEQ)
{
  hb_retptr((CvSeq *)cvCreateSeq(hb_parni(1), hb_parnl(2), hb_parnl(3), (CvMemStorage *)hb_parptr(4)));
}

/*
CVAPI(void) cvSetSeqBlockSize( CvSeq* seq, int delta_elems )
*/
HB_FUNC(CVSETSEQBLOCKSIZE)
{
  cvSetSeqBlockSize((CvSeq *)hb_parptr(1), hb_parni(2));
}

/*
CVAPI(void) cvSeqPop( CvSeq* seq, void* element CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSEQPOP)
{
  cvSeqPop((CvSeq *)hb_parptr(1), HB_ISNIL(2) ? NULL : (void *)hb_parptr(2));
}

/*
CVAPI(void) cvSeqPopFront( CvSeq* seq, void* element CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSEQPOPFRONT)
{
  cvSeqPopFront((CvSeq *)hb_parptr(1), HB_ISNIL(2) ? NULL : (void *)hb_parptr(2));
}

/*
CVAPI(void) cvSeqPushMulti( CvSeq* seq, const void* elements, int count, int in_front CV_DEFAULT(0) )
*/
HB_FUNC(CVSEQPUSHMULTI)
{
  cvSeqPushMulti((CvSeq *)hb_parptr(1), (const void *)hb_parptr(2), hb_parni(3), HB_ISNIL(4) ? 0 : hb_parni(4));
}

/*
CVAPI(void) cvSeqPopMulti( CvSeq* seq, void* elements, int count, int in_front CV_DEFAULT(0) )
*/
HB_FUNC(CVSEQPOPMULTI)
{
  cvSeqPopMulti((CvSeq *)hb_parptr(1), (void *)hb_parptr(2), hb_parni(3), HB_ISNIL(4) ? 0 : hb_parni(4));
}

/*
CVAPI(void) cvSeqRemove( CvSeq* seq, int index )
*/
HB_FUNC(CVSEQREMOVE)
{
  cvSeqRemove((CvSeq *)hb_parptr(1), hb_parni(2));
}

/*
CVAPI(void) cvClearSeq( CvSeq* seq )
*/
HB_FUNC(CVCLEARSEQ)
{
  cvClearSeq((CvSeq *)hb_parptr(1));
}

/*
CVAPI(int) cvSeqElemIdx( const CvSeq* seq, const void* element, CvSeqBlock** block CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSEQELEMIDX)
{
  hb_retni(cvSeqElemIdx((const CvSeq *)hb_parptr(1), (const void *)hb_parptr(2),
                        HB_ISNIL(3) ? NULL : (CvSeqBlock **)hb_parptr(3)));
}

/*
CVAPI(void) cvStartAppendToSeq( CvSeq* seq, CvSeqWriter* writer )
*/
HB_FUNC(CVSTARTAPPENDTOSEQ)
{
  cvStartAppendToSeq((CvSeq *)hb_parptr(1), (CvSeqWriter *)hb_parptr(2));
}

/*
CVAPI(void) cvStartWriteSeq( int seq_flags, int header_size, int elem_size, CvMemStorage* storage, CvSeqWriter* writer )
*/
HB_FUNC(CVSTARTWRITESEQ)
{
  cvStartWriteSeq(hb_parni(1), hb_parni(2), hb_parni(3), (CvMemStorage *)hb_parptr(4), (CvSeqWriter *)hb_parptr(5));
}

/*
CVAPI(CvSeq*) cvEndWriteSeq( CvSeqWriter* writer )
*/
HB_FUNC(CVENDWRITESEQ)
{
  hb_retptr((CvSeq *)cvEndWriteSeq((CvSeqWriter *)hb_parptr(1)));
}

/*
CVAPI(void) cvFlushSeqWriter( CvSeqWriter* writer )
*/
HB_FUNC(CVFLUSHSEQWRITER)
{
  cvFlushSeqWriter((CvSeqWriter *)hb_parptr(1));
}

/*
CVAPI(void) cvStartReadSeq( const CvSeq* seq, CvSeqReader* reader, int reverse CV_DEFAULT(0) )
*/
HB_FUNC(CVSTARTREADSEQ)
{
  cvStartReadSeq((const CvSeq *)hb_parptr(1), (CvSeqReader *)hb_parptr(2), HB_ISNIL(3) ? 0 : hb_parni(3));
}

/*
CVAPI(int) cvGetSeqReaderPos( CvSeqReader* reader )
*/
HB_FUNC(CVGETSEQREADERPOS)
{
  hb_retni(cvGetSeqReaderPos((CvSeqReader *)hb_parptr(1)));
}

/*
CVAPI(void) cvSetSeqReaderPos( CvSeqReader* reader, int index, int is_relative CV_DEFAULT(0) )
*/
HB_FUNC(CVSETSEQREADERPOS)
{
  cvSetSeqReaderPos((CvSeqReader *)hb_parptr(1), hb_parni(2), HB_ISNIL(3) ? 0 : hb_parni(3));
}

/*
CVAPI(void*) cvCvtSeqToArray( const CvSeq* seq, void* elements, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ) )
*/
HB_FUNC(CVCVTSEQTOARRAY)
{
  PHB_ITEM pSlice3 = hb_param(3, HB_IT_ARRAY);
  CvSlice slice3;
  slice3.start_index = hb_arrayGetNI(pSlice3, 1);
  slice3.end_index = hb_arrayGetNI(pSlice3, 2);
  hb_retptr(
      (void *)cvCvtSeqToArray((const CvSeq *)hb_parptr(1), (void *)hb_parptr(2), HB_ISNIL(3) ? CV_WHOLE_SEQ : slice3));
}

/*
CVAPI(CvSeq*) cvMakeSeqHeaderForArray( int seq_type, int header_size, int elem_size, void* elements, int total, CvSeq*
seq, CvSeqBlock* block )
*/
HB_FUNC(CVMAKESEQHEADERFORARRAY)
{
  hb_retptr((CvSeq *)cvMakeSeqHeaderForArray(hb_parni(1), hb_parni(2), hb_parni(3), (void *)hb_parptr(4), hb_parni(5),
                                             (CvSeq *)hb_parptr(6), (CvSeqBlock *)hb_parptr(7)));
}

/*
CVAPI(CvSeq*) cvSeqSlice( const CvSeq* seq, CvSlice slice, CvMemStorage* storage CV_DEFAULT(NULL), int copy_data
CV_DEFAULT(0) )
*/
HB_FUNC(CVSEQSLICE)
{
  PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
  CvSlice slice2;
  slice2.start_index = hb_arrayGetNI(pSlice2, 1);
  slice2.end_index = hb_arrayGetNI(pSlice2, 2);
  hb_retptr((CvSeq *)cvSeqSlice((const CvSeq *)hb_parptr(1), slice2, HB_ISNIL(3) ? NULL : (CvMemStorage *)hb_parptr(3),
                                HB_ISNIL(4) ? 0 : hb_parni(4)));
}

/*
CV_INLINE CvSeq* cvCloneSeq( const CvSeq* seq, CvMemStorage* storage CV_DEFAULT(NULL) )
*/
HB_FUNC(CVCLONESEQ)
{
  hb_retptr((CvSeq *)cvCloneSeq((const CvSeq *)hb_parptr(1), HB_ISNIL(2) ? NULL : (CvMemStorage *)hb_parptr(2)));
}

/*
CVAPI(void) cvSeqRemoveSlice( CvSeq* seq, CvSlice slice )
*/
HB_FUNC(CVSEQREMOVESLICE)
{
  PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
  CvSlice slice2;
  slice2.start_index = hb_arrayGetNI(pSlice2, 1);
  slice2.end_index = hb_arrayGetNI(pSlice2, 2);
  cvSeqRemoveSlice((CvSeq *)hb_parptr(1), slice2);
}

/*
CVAPI(void) cvSeqInsertSlice( CvSeq* seq, int before_index, const CvArr* from_arr )
*/
HB_FUNC(CVSEQINSERTSLICE)
{
  cvSeqInsertSlice((CvSeq *)hb_parptr(1), hb_parni(2), (const CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvSeqInvert( CvSeq* seq )
*/
HB_FUNC(CVSEQINVERT)
{
  cvSeqInvert((CvSeq *)hb_parptr(1));
}

/*
CVAPI(void) cvChangeSeqBlock( void* reader, int direction )
*/
HB_FUNC(CVCHANGESEQBLOCK)
{
  cvChangeSeqBlock((void *)hb_parptr(1), hb_parni(2));
}

/*
CVAPI(void) cvCreateSeqBlock( CvSeqWriter* writer )
*/
HB_FUNC(CVCREATESEQBLOCK)
{
  cvCreateSeqBlock((CvSeqWriter *)hb_parptr(1));
}

/*
CVAPI(CvSet*) cvCreateSet( int set_flags, int header_size, int elem_size, CvMemStorage* storage )
*/
HB_FUNC(CVCREATESET)
{
  hb_retptr((CvSet *)cvCreateSet(hb_parni(1), hb_parni(2), hb_parni(3), (CvMemStorage *)hb_parptr(4)));
}

/*
CVAPI(int) cvSetAdd( CvSet* set_header, CvSetElem* elem CV_DEFAULT(NULL), CvSetElem** inserted_elem CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSETADD)
{
  hb_retni(cvSetAdd((CvSet *)hb_parptr(1), HB_ISNIL(2) ? NULL : (CvSetElem *)hb_parptr(2),
                    HB_ISNIL(3) ? NULL : (CvSetElem **)hb_parptr(3)));
}

/*
CV_INLINE CvSetElem* cvSetNew( CvSet* set_header )
*/
HB_FUNC(CVSETNEW)
{
  hb_retptr((CvSetElem *)cvSetNew((CvSet *)hb_parptr(1)));
}

/*
CV_INLINE void cvSetRemoveByPtr( CvSet* set_header, void* elem )
*/
HB_FUNC(CVSETREMOVEBYPTR)
{
  cvSetRemoveByPtr((CvSet *)hb_parptr(1), (void *)hb_parptr(2));
}

/*
CVAPI(void) cvSetRemove( CvSet* set_header, int index )
*/
HB_FUNC(CVSETREMOVE)
{
  cvSetRemove((CvSet *)hb_parptr(1), hb_parni(2));
}

/*
CV_INLINE CvSetElem* cvGetSetElem( const CvSet* set_header, int idx )
*/
HB_FUNC(CVGETSETELEM)
{
  hb_retptr((CvSetElem *)cvGetSetElem((const CvSet *)hb_parptr(1), hb_parni(2)));
}

/*
CVAPI(void) cvClearSet( CvSet* set_header )
*/
HB_FUNC(CVCLEARSET)
{
  cvClearSet((CvSet *)hb_parptr(1));
}

/*
CVAPI(CvGraph*) cvCreateGraph( int graph_flags, int header_size, int vtx_size, int edge_size, CvMemStorage* storage )
*/
HB_FUNC(CVCREATEGRAPH)
{
  hb_retptr((CvGraph *)cvCreateGraph(hb_parni(1), hb_parni(2), hb_parni(3), hb_parni(4), (CvMemStorage *)hb_parptr(5)));
}

/*
CVAPI(int) cvGraphAddVtx( CvGraph* graph, const CvGraphVtx* vtx CV_DEFAULT(NULL), CvGraphVtx** inserted_vtx
CV_DEFAULT(NULL) )
*/
HB_FUNC(CVGRAPHADDVTX)
{
  hb_retni(cvGraphAddVtx((CvGraph *)hb_parptr(1), HB_ISNIL(2) ? NULL : (const CvGraphVtx *)hb_parptr(2),
                         HB_ISNIL(3) ? NULL : (CvGraphVtx **)hb_parptr(3)));
}

/*
CVAPI(int) cvGraphRemoveVtx( CvGraph* graph, int index )
*/
HB_FUNC(CVGRAPHREMOVEVTX)
{
  hb_retni(cvGraphRemoveVtx((CvGraph *)hb_parptr(1), hb_parni(2)));
}

/*
CVAPI(int) cvGraphRemoveVtxByPtr( CvGraph* graph, CvGraphVtx* vtx )
*/
HB_FUNC(CVGRAPHREMOVEVTXBYPTR)
{
  hb_retni(cvGraphRemoveVtxByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2)));
}

/*
CVAPI(int) cvGraphAddEdge( CvGraph* graph, int start_idx, int end_idx, const CvGraphEdge* edge CV_DEFAULT(NULL),
CvGraphEdge** inserted_edge CV_DEFAULT(NULL) )
*/
HB_FUNC(CVGRAPHADDEDGE)
{
  hb_retni(cvGraphAddEdge((CvGraph *)hb_parptr(1), hb_parni(2), hb_parni(3),
                          HB_ISNIL(4) ? NULL : (const CvGraphEdge *)hb_parptr(4),
                          HB_ISNIL(5) ? NULL : (CvGraphEdge **)hb_parptr(5)));
}

/*
CVAPI(int) cvGraphAddEdgeByPtr( CvGraph* graph, CvGraphVtx* start_vtx, CvGraphVtx* end_vtx, const CvGraphEdge* edge
CV_DEFAULT(NULL), CvGraphEdge** inserted_edge CV_DEFAULT(NULL) )
*/
HB_FUNC(CVGRAPHADDEDGEBYPTR)
{
  hb_retni(cvGraphAddEdgeByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2), (CvGraphVtx *)hb_parptr(3),
                               HB_ISNIL(4) ? NULL : (const CvGraphEdge *)hb_parptr(4),
                               HB_ISNIL(5) ? NULL : (CvGraphEdge **)hb_parptr(5)));
}

/*
CVAPI(void) cvGraphRemoveEdge( CvGraph* graph, int start_idx, int end_idx )
*/
HB_FUNC(CVGRAPHREMOVEEDGE)
{
  cvGraphRemoveEdge((CvGraph *)hb_parptr(1), hb_parni(2), hb_parni(3));
}

/*
CVAPI(void) cvGraphRemoveEdgeByPtr( CvGraph* graph, CvGraphVtx* start_vtx, CvGraphVtx* end_vtx )
*/
HB_FUNC(CVGRAPHREMOVEEDGEBYPTR)
{
  cvGraphRemoveEdgeByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2), (CvGraphVtx *)hb_parptr(3));
}

/*
CVAPI(CvGraphEdge*) cvFindGraphEdge( const CvGraph* graph, int start_idx, int end_idx )
*/
HB_FUNC(CVFINDGRAPHEDGE)
{
  hb_retptr((CvGraphEdge *)cvFindGraphEdge((const CvGraph *)hb_parptr(1), hb_parni(2), hb_parni(3)));
}

/*
CVAPI(CvGraphEdge*) cvFindGraphEdgeByPtr( const CvGraph* graph, const CvGraphVtx* start_vtx, const CvGraphVtx* end_vtx )
*/
HB_FUNC(CVFINDGRAPHEDGEBYPTR)
{
  hb_retptr((CvGraphEdge *)cvFindGraphEdgeByPtr((const CvGraph *)hb_parptr(1), (const CvGraphVtx *)hb_parptr(2),
                                                (const CvGraphVtx *)hb_parptr(3)));
}

/*
CVAPI(void) cvClearGraph( CvGraph* graph )
*/
HB_FUNC(CVCLEARGRAPH)
{
  cvClearGraph((CvGraph *)hb_parptr(1));
}

/*
CVAPI(int) cvGraphVtxDegree( const CvGraph* graph, int vtx_idx )
*/
HB_FUNC(CVGRAPHVTXDEGREE)
{
  hb_retni(cvGraphVtxDegree((const CvGraph *)hb_parptr(1), hb_parni(2)));
}

/*
CVAPI(int) cvGraphVtxDegreeByPtr( const CvGraph* graph, const CvGraphVtx* vtx )
*/
HB_FUNC(CVGRAPHVTXDEGREEBYPTR)
{
  hb_retni(cvGraphVtxDegreeByPtr((const CvGraph *)hb_parptr(1), (const CvGraphVtx *)hb_parptr(2)));
}

/*
CVAPI(CvGraphScanner*) cvCreateGraphScanner( CvGraph* graph, CvGraphVtx* vtx CV_DEFAULT(NULL), int mask
CV_DEFAULT(CV_GRAPH_ALL_ITEMS) )
*/
HB_FUNC(CVCREATEGRAPHSCANNER)
{
  hb_retptr((CvGraphScanner *)cvCreateGraphScanner((CvGraph *)hb_parptr(1),
                                                   HB_ISNIL(2) ? NULL : (CvGraphVtx *)hb_parptr(2),
                                                   HB_ISNIL(3) ? CV_GRAPH_ALL_ITEMS : hb_parni(3)));
}

/*
CVAPI(void) cvReleaseGraphScanner( CvGraphScanner** scanner )
*/
HB_FUNC(CVRELEASEGRAPHSCANNER)
{
  cvReleaseGraphScanner((CvGraphScanner **)hb_parptr(1));
}

/*
CVAPI(int) cvNextGraphItem( CvGraphScanner* scanner )
*/
HB_FUNC(CVNEXTGRAPHITEM)
{
  hb_retni(cvNextGraphItem((CvGraphScanner *)hb_parptr(1)));
}

/*
CVAPI(CvGraph*) cvCloneGraph( const CvGraph* graph, CvMemStorage* storage )
*/
HB_FUNC(CVCLONEGRAPH)
{
  hb_retptr((CvGraph *)cvCloneGraph((const CvGraph *)hb_parptr(1), (CvMemStorage *)hb_parptr(2)));
}

/*
CVAPI(void) cvLine( CvArr* img, CvPoint pt1, CvPoint pt2, CvScalar color, int thickness CV_DEFAULT(1), int line_type
CV_DEFAULT(8), int shift CV_DEFAULT(0) )
*/
HB_FUNC(CVLINE)
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
  cvLine((CvArr *)hb_parptr(1), point2, point3, scalar4, HB_ISNIL(5) ? 1 : hb_parni(5), HB_ISNIL(6) ? 8 : hb_parni(6),
         HB_ISNIL(7) ? 0 : hb_parni(7));
}

/*
CVAPI(void) cvRectangle( CvArr* img, CvPoint pt1, CvPoint pt2, CvScalar color, int thickness CV_DEFAULT(1), int
line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
*/
HB_FUNC(CVRECTANGLE)
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
  cvRectangle((CvArr *)hb_parptr(1), point2, point3, scalar4, HB_ISNIL(5) ? 1 : hb_parni(5), HB_ISNIL(6) ? 8 : hb_parni(6),
              HB_ISNIL(7) ? 0 : hb_parni(7));
}

/*
CVAPI(void) cvRectangleR( CvArr* img, CvRect r, CvScalar color, int thickness CV_DEFAULT(1), int line_type
CV_DEFAULT(8), int shift CV_DEFAULT(0) )
*/
HB_FUNC(CVRECTANGLER)
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
  cvRectangleR((CvArr *)hb_parptr(1), rect2, scalar3, HB_ISNIL(4) ? 1 : hb_parni(4), HB_ISNIL(5) ? 8 : hb_parni(5),
               HB_ISNIL(6) ? 0 : hb_parni(6));
}

/*
CVAPI(void) cvCircle( CvArr* img, CvPoint center, int radius, CvScalar color, int thickness CV_DEFAULT(1), int line_type
CV_DEFAULT(8), int shift CV_DEFAULT(0) )
*/
HB_FUNC(CVCIRCLE)
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
  cvCircle((CvArr *)hb_parptr(1), point2, hb_parni(3), scalar4, HB_ISNIL(5) ? 1 : hb_parni(5), HB_ISNIL(6) ? 8 : hb_parni(6),
           HB_ISNIL(7) ? 0 : hb_parni(7));
}

/*
CVAPI(void) cvEllipse( CvArr* img, CvPoint center, CvSize axes, double angle, double start_angle, double end_angle,
CvScalar color, int thickness CV_DEFAULT(1), int line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
*/
HB_FUNC(CVELLIPSE)
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
  cvEllipse((CvArr *)hb_parptr(1), point2, size3, hb_parnd(4), hb_parnd(5), hb_parnd(6), scalar7,
            HB_ISNIL(8) ? 1 : hb_parni(8), HB_ISNIL(9) ? 8 : hb_parni(9), HB_ISNIL(10) ? 0 : hb_parni(10));
}

/*
CVAPI(int) cvInitLineIterator( const CvArr* image, CvPoint pt1, CvPoint pt2, CvLineIterator* line_iterator, int
connectivity CV_DEFAULT(8), int left_to_right CV_DEFAULT(0) )
*/
HB_FUNC(CVINITLINEITERATOR)
{
  PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
  CvPoint point2;
  point2.x = hb_arrayGetNI(pPoint2, 1);
  point2.y = hb_arrayGetNI(pPoint2, 2);
  PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
  CvPoint point3;
  point3.x = hb_arrayGetNI(pPoint3, 1);
  point3.y = hb_arrayGetNI(pPoint3, 2);
  hb_retni(cvInitLineIterator((const CvArr *)hb_parptr(1), point2, point3, (CvLineIterator *)hb_parptr(4),
                              HB_ISNIL(5) ? 8 : hb_parni(5), HB_ISNIL(6) ? 0 : hb_parni(6)));
}

/*
CVAPI(CvScalar) cvColorToScalar( double packed_color, int arrtype )
*/
HB_FUNC(CVCOLORTOSCALAR)
{
  CvScalar scalar;
  scalar = cvColorToScalar(hb_parnd(1), hb_parni(2));
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

/*
CVAPI(void) cvLUT( const CvArr* src, CvArr* dst, const CvArr* lut )
*/
HB_FUNC(CVLUT)
{
  cvLUT((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvInitTreeNodeIterator( CvTreeNodeIterator* tree_iterator, const void* first, int max_level )
*/
HB_FUNC(CVINITTREENODEITERATOR)
{
  cvInitTreeNodeIterator((CvTreeNodeIterator *)hb_parptr(1), (const void *)hb_parptr(2), hb_parni(3));
}

/*
CVAPI(void*) cvNextTreeNode( CvTreeNodeIterator* tree_iterator )
*/
HB_FUNC(CVNEXTTREENODE)
{
  hb_retptr((void *)cvNextTreeNode((CvTreeNodeIterator *)hb_parptr(1)));
}

/*
CVAPI(void*) cvPrevTreeNode( CvTreeNodeIterator* tree_iterator )
*/
HB_FUNC(CVPREVTREENODE)
{
  hb_retptr((void *)cvPrevTreeNode((CvTreeNodeIterator *)hb_parptr(1)));
}

/*
CVAPI(void) cvInsertNodeIntoTree( void* node, void* parent, void* frame )
*/
HB_FUNC(CVINSERTNODEINTOTREE)
{
  cvInsertNodeIntoTree((void *)hb_parptr(1), (void *)hb_parptr(2), (void *)hb_parptr(3));
}

/*
CVAPI(void) cvRemoveNodeFromTree( void* node, void* frame )
*/
HB_FUNC(CVREMOVENODEFROMTREE)
{
  cvRemoveNodeFromTree((void *)hb_parptr(1), (void *)hb_parptr(2));
}

/*
CVAPI(CvSeq*) cvTreeToNodeSeq( const void* first, int header_size, CvMemStorage* storage )
*/
HB_FUNC(CVTREETONODESEQ)
{
  hb_retptr((CvSeq *)cvTreeToNodeSeq((const void *)hb_parptr(1), hb_parni(2), (CvMemStorage *)hb_parptr(3)));
}

/*
CVAPI(int) cvRegisterModule( const CvModuleInfo* module_info )
*/
HB_FUNC(CVREGISTERMODULE)
{
  hb_retni(cvRegisterModule((const CvModuleInfo *)hb_parptr(1)));
}

/*
CVAPI(int) cvUseOptimized( int on_off )
*/
HB_FUNC(CVUSEOPTIMIZED)
{
  hb_retni(cvUseOptimized(hb_parni(1)));
}

/*
CVAPI(CvFileStorage*) cvOpenFileStorage( const char* filename, CvMemStorage* memstorage, int flags, const char* encoding
CV_DEFAULT(NULL) )
*/
HB_FUNC(CVOPENFILESTORAGE)
{
  hb_retptr((CvFileStorage *)cvOpenFileStorage(hb_parc(1), (CvMemStorage *)hb_parptr(2), hb_parni(3),
                                               HB_ISNIL(4) ? NULL : hb_parc(4)));
}

/*
CVAPI(void) cvReleaseFileStorage( CvFileStorage** fs )
*/
HB_FUNC(CVRELEASEFILESTORAGE)
{
  cvReleaseFileStorage((CvFileStorage **)hb_parptr(1));
}

/*
CVAPI(void) cvEndWriteStruct( CvFileStorage* fs )
*/
HB_FUNC(CVENDWRITESTRUCT)
{
  cvEndWriteStruct((CvFileStorage *)hb_parptr(1));
}

/*
CVAPI(void) cvWriteInt( CvFileStorage* fs, const char* name, int value )
*/
HB_FUNC(CVWRITEINT)
{
  cvWriteInt((CvFileStorage *)hb_parptr(1), hb_parc(2), hb_parni(3));
}

/*
CVAPI(void) cvWriteReal( CvFileStorage* fs, const char* name, double value )
*/
HB_FUNC(CVWRITEREAL)
{
  cvWriteReal((CvFileStorage *)hb_parptr(1), hb_parc(2), hb_parnd(3));
}

/*
CVAPI(void) cvWriteString( CvFileStorage* fs, const char* name, const char* str, int quote CV_DEFAULT(0) )
*/
HB_FUNC(CVWRITESTRING)
{
  cvWriteString((CvFileStorage *)hb_parptr(1), hb_parc(2), hb_parc(3), HB_ISNIL(4) ? 0 : hb_parni(4));
}

/*
CVAPI(void) cvWriteComment( CvFileStorage* fs, const char* comment, int eol_comment )
*/
HB_FUNC(CVWRITECOMMENT)
{
  cvWriteComment((CvFileStorage *)hb_parptr(1), hb_parc(2), hb_parni(3));
}

/*
CVAPI(void) cvStartNextStream( CvFileStorage* fs )
*/
HB_FUNC(CVSTARTNEXTSTREAM)
{
  cvStartNextStream((CvFileStorage *)hb_parptr(1));
}

/*
CVAPI(void) cvWriteRawData( CvFileStorage* fs, const void* src, int len, const char* dt )
*/
HB_FUNC(CVWRITERAWDATA)
{
  cvWriteRawData((CvFileStorage *)hb_parptr(1), (const void *)hb_parptr(2), hb_parni(3), hb_parc(4));
}

/*
CVAPI(CvStringHashNode*) cvGetHashedKey( CvFileStorage* fs, const char* name, int len CV_DEFAULT(-1), int create_missing
CV_DEFAULT(0) )
*/
HB_FUNC(CVGETHASHEDKEY)
{
  hb_retptr((CvStringHashNode *)cvGetHashedKey((CvFileStorage *)hb_parptr(1), hb_parc(2), HB_ISNIL(3) ? -1 : hb_parni(3),
                                               HB_ISNIL(4) ? 0 : hb_parni(4)));
}

/*
CVAPI(CvFileNode*) cvGetRootFileNode( const CvFileStorage* fs, int stream_index CV_DEFAULT(0) )
*/
HB_FUNC(CVGETROOTFILENODE)
{
  hb_retptr((CvFileNode *)cvGetRootFileNode((const CvFileStorage *)hb_parptr(1), HB_ISNIL(2) ? 0 : hb_parni(2)));
}

/*
CVAPI(CvFileNode*) cvGetFileNode( CvFileStorage* fs, CvFileNode* map, const CvStringHashNode* key, int create_missing
CV_DEFAULT(0) )
*/
HB_FUNC(CVGETFILENODE)
{
  hb_retptr((CvFileNode *)cvGetFileNode((CvFileStorage *)hb_parptr(1), (CvFileNode *)hb_parptr(2),
                                        (const CvStringHashNode *)hb_parptr(3), HB_ISNIL(4) ? 0 : hb_parni(4)));
}

/*
CVAPI(CvFileNode*) cvGetFileNodeByName( const CvFileStorage* fs, const CvFileNode* map, const char* name )
*/
HB_FUNC(CVGETFILENODEBYNAME)
{
  hb_retptr((CvFileNode *)cvGetFileNodeByName((const CvFileStorage *)hb_parptr(1), (const CvFileNode *)hb_parptr(2),
                                              hb_parc(3)));
}

/*
CV_INLINE int cvReadInt( const CvFileNode* node, int default_value CV_DEFAULT(0) )
*/
HB_FUNC(CVREADINT)
{
  hb_retni(cvReadInt((const CvFileNode *)hb_parptr(1), HB_ISNIL(2) ? 0 : hb_parni(2)));
}

/*
CV_INLINE int cvReadIntByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, int default_value
CV_DEFAULT(0) )
*/
HB_FUNC(CVREADINTBYNAME)
{
  hb_retni(cvReadIntByName((const CvFileStorage *)hb_parptr(1), (const CvFileNode *)hb_parptr(2), hb_parc(3),
                           HB_ISNIL(4) ? 0 : hb_parni(4)));
}

/*
CV_INLINE double cvReadReal( const CvFileNode* node, double default_value CV_DEFAULT(0.) )
*/
HB_FUNC(CVREADREAL)
{
  hb_retnd(cvReadReal((const CvFileNode *)hb_parptr(1), HB_ISNIL(2) ? 0. : hb_parnd(2)));
}

/*
CV_INLINE double cvReadRealByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, double
default_value CV_DEFAULT(0.) )
*/
HB_FUNC(CVREADREALBYNAME)
{
  hb_retnd(cvReadRealByName((const CvFileStorage *)hb_parptr(1), (const CvFileNode *)hb_parptr(2), hb_parc(3),
                            HB_ISNIL(4) ? 0. : hb_parnd(4)));
}

/*
CV_INLINE const char* cvReadString( const CvFileNode* node, const char* default_value CV_DEFAULT(NULL) )
*/
HB_FUNC(CVREADSTRING)
{
  hb_retc(cvReadString((const CvFileNode *)hb_parptr(1), HB_ISNIL(2) ? NULL : hb_parc(2)));
}

/*
CV_INLINE const char* cvReadStringByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, const char*
default_value CV_DEFAULT(NULL) )
*/
HB_FUNC(CVREADSTRINGBYNAME)
{
  hb_retc(cvReadStringByName((const CvFileStorage *)hb_parptr(1), (const CvFileNode *)hb_parptr(2), hb_parc(3),
                             HB_ISNIL(4) ? NULL : hb_parc(4)));
}

/*
CVAPI(void) cvStartReadRawData( const CvFileStorage* fs, const CvFileNode* src, CvSeqReader* reader )
*/
HB_FUNC(CVSTARTREADRAWDATA)
{
  cvStartReadRawData((const CvFileStorage *)hb_parptr(1), (const CvFileNode *)hb_parptr(2),
                     (CvSeqReader *)hb_parptr(3));
}

/*
CVAPI(void) cvReadRawDataSlice( const CvFileStorage* fs, CvSeqReader* reader, int count, void* dst, const char* dt )
*/
HB_FUNC(CVREADRAWDATASLICE)
{
  cvReadRawDataSlice((const CvFileStorage *)hb_parptr(1), (CvSeqReader *)hb_parptr(2), hb_parni(3),
                     (void *)hb_parptr(4), hb_parc(5));
}

/*
CVAPI(void) cvReadRawData( const CvFileStorage* fs, const CvFileNode* src, void* dst, const char* dt )
*/
HB_FUNC(CVREADRAWDATA)
{
  cvReadRawData((const CvFileStorage *)hb_parptr(1), (const CvFileNode *)hb_parptr(2), (void *)hb_parptr(3),
                hb_parc(4));
}

/*
CVAPI(void) cvWriteFileNode( CvFileStorage* fs, const char* new_node_name, const CvFileNode* node, int embed )
*/
HB_FUNC(CVWRITEFILENODE)
{
  cvWriteFileNode((CvFileStorage *)hb_parptr(1), hb_parc(2), (const CvFileNode *)hb_parptr(3), hb_parni(4));
}

/*
CVAPI(const char*) cvGetFileNodeName( const CvFileNode* node )
*/
HB_FUNC(CVGETFILENODENAME)
{
  hb_retc(cvGetFileNodeName((const CvFileNode *)hb_parptr(1)));
}

/*
CVAPI(void) cvRegisterType( const CvTypeInfo* info )
*/
HB_FUNC(CVREGISTERTYPE)
{
  cvRegisterType((const CvTypeInfo *)hb_parptr(1));
}

/*
CVAPI(void) cvUnregisterType( const char* type_name )
*/
HB_FUNC(CVUNREGISTERTYPE)
{
  cvUnregisterType(hb_parc(1));
}

/*
CVAPI(CvTypeInfo*) cvFirstType( void )
*/
HB_FUNC(CVFIRSTTYPE)
{
  hb_retptr((CvTypeInfo *)cvFirstType());
}

/*
CVAPI(CvTypeInfo*) cvFindType( const char* type_name )
*/
HB_FUNC(CVFINDTYPE)
{
  hb_retptr((CvTypeInfo *)cvFindType(hb_parc(1)));
}

/*
CVAPI(CvTypeInfo*) cvTypeOf( const void* struct_ptr )
*/
HB_FUNC(CVTYPEOF)
{
  hb_retptr((CvTypeInfo *)cvTypeOf((const void *)hb_parptr(1)));
}

/*
CVAPI(void) cvRelease( void** struct_ptr )
*/
HB_FUNC(CVRELEASE)
{
  cvRelease((void **)hb_parptr(1));
}

/*
CVAPI(void*) cvClone( const void* struct_ptr )
*/
HB_FUNC(CVCLONE)
{
  hb_retptr((void *)cvClone((const void *)hb_parptr(1)));
}

/*
CVAPI(int64) cvGetTickCount( void )
*/
HB_FUNC(CVGETTICKCOUNT)
{
  hb_retnll(cvGetTickCount());
}

/*
CVAPI(double) cvGetTickFrequency( void )
*/
HB_FUNC(CVGETTICKFREQUENCY)
{
  hb_retnd(cvGetTickFrequency());
}

/*
CVAPI(int) cvCheckHardwareSupport( int feature )
*/
HB_FUNC(CVCHECKHARDWARESUPPORT)
{
  hb_retni(cvCheckHardwareSupport(hb_parni(1)));
}

/*
CVAPI(int) cvGetNumThreads( void )
*/
HB_FUNC(CVGETNUMTHREADS)
{
  hb_retni(cvGetNumThreads());
}

/*
CVAPI(void) cvSetNumThreads( int threads CV_DEFAULT(0) )
*/
HB_FUNC(CVSETNUMTHREADS)
{
  cvSetNumThreads(HB_ISNIL(1) ? 0 : hb_parni(1));
}

/*
CVAPI(int) cvGetThreadNum( void )
*/
HB_FUNC(CVGETTHREADNUM)
{
  hb_retni(cvGetThreadNum());
}

/*
CVAPI(int) cvGetErrStatus( void )
*/
HB_FUNC(CVGETERRSTATUS)
{
  hb_retni(cvGetErrStatus());
}

/*
CVAPI(void) cvSetErrStatus( int status )
*/
HB_FUNC(CVSETERRSTATUS)
{
  cvSetErrStatus(hb_parni(1));
}

/*
CVAPI(int) cvGetErrMode( void )
*/
HB_FUNC(CVGETERRMODE)
{
  hb_retni(cvGetErrMode());
}

/*
CVAPI(int) cvSetErrMode( int mode )
*/
HB_FUNC(CVSETERRMODE)
{
  hb_retni(cvSetErrMode(hb_parni(1)));
}

/*
CVAPI(void) cvError( int status, const char* func_name, const char* err_msg, const char* file_name, int line )
*/
HB_FUNC(CVERROR)
{
  cvError(hb_parni(1), hb_parc(2), hb_parc(3), hb_parc(4), hb_parni(5));
}

/*
CVAPI(const char*) cvErrorStr( int status )
*/
HB_FUNC(CVERRORSTR)
{
  hb_retc(cvErrorStr(hb_parni(1)));
}

/*
CVAPI(int) cvErrorFromIppStatus( int ipp_status )
*/
HB_FUNC(CVERRORFROMIPPSTATUS)
{
  hb_retni(cvErrorFromIppStatus(hb_parni(1)));
}

/*
CVAPI(int) cvNulDevReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line,
void* userdata )
*/
HB_FUNC(CVNULDEVREPORT)
{
  hb_retni(cvNulDevReport(hb_parni(1), hb_parc(2), hb_parc(3), hb_parc(4), hb_parni(5), (void *)hb_parptr(6)));
}

/*
CVAPI(int) cvStdErrReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line,
void* userdata )
*/
HB_FUNC(CVSTDERRREPORT)
{
  hb_retni(cvStdErrReport(hb_parni(1), hb_parc(2), hb_parc(3), hb_parc(4), hb_parni(5), (void *)hb_parptr(6)));
}

/*
CVAPI(int) cvGuiBoxReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line,
void* userdata )
*/
HB_FUNC(CVGUIBOXREPORT)
{
  hb_retni(cvGuiBoxReport(hb_parni(1), hb_parc(2), hb_parc(3), hb_parc(4), hb_parni(5), (void *)hb_parptr(6)));
}
