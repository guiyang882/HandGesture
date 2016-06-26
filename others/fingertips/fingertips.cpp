#include <Windows.h>

#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

#pragma comment(lib,"cv210.lib")
#pragma comment(lib,"cxcore210.lib")
#pragma comment(lib,"highgui210.lib")

void ErrorHandler(char* message)
{
	cout<<message<<endl;
	exit(0);
}
#undef UNICODE
//Download by http://www.codefans.net
void fingerTip(char* imgname);

int main()
{
	WIN32_FIND_DATA FileData; 
	HANDLE hSearch; 
	BOOL fFinished = FALSE; 

	if(!SetCurrentDirectory("images")){
		cout<<"failed to change work directory"<<endl;
		exit(0);
	}

	hSearch = FindFirstFile("*.bmp", &FileData); 
	if (hSearch == INVALID_HANDLE_VALUE){ 
		ErrorHandler("No .bmp files found."); 
	} 
	while (!fFinished){ 
		fingerTip(FileData.cFileName);
		if (!FindNextFile(hSearch, &FileData)){
			if (GetLastError() == ERROR_NO_MORE_FILES){ 				
				fFinished = TRUE; 
			} else { 
				ErrorHandler("Couldn't find next file."); 
			} 
		}
		cvWaitKey(0);
	} 

	// Close the search handle. 
	if (!FindClose(hSearch)){ 
		ErrorHandler("Couldn't close search handle."); 
	} 
	
	return 0;
}

void fingerTip(char* imgname)
{
	IplImage* pImgColor=NULL;
	IplImage* pImgGray=NULL;
	IplImage* pImgContourAll=NULL;
	IplImage* pImgContourAppr=NULL;
	IplImage* pImgHull=NULL;
	IplImage* pImgDefects=NULL;
	pImgColor=cvLoadImage(imgname,CV_LOAD_IMAGE_COLOR);
	if (!pImgColor){
		cout<<"failed to load image"<<endl;
		exit(0);
	}

	pImgGray=cvCreateImage(cvGetSize(pImgColor),8,1);
	cvCvtColor(pImgColor,pImgGray,CV_RGB2GRAY);	
	pImgContourAppr=cvCreateImage(cvGetSize(pImgGray),8,3);
	pImgContourAll=cvCreateImage(cvGetSize(pImgGray),8,3);
	pImgHull=cvCreateImage(cvGetSize(pImgGray),8,3);
	pImgDefects=cvCreateImage(cvGetSize(pImgGray),8,3);
	cvZero(pImgContourAppr);
	cvZero(pImgContourAll);
	cvZero(pImgHull);
	cvZero(pImgDefects);

	//canny
	CvMemStorage* storage=cvCreateMemStorage();
	CvSeq* contourSeqAll=cvCreateSeq(0,sizeof(CvSeq),sizeof(CvPoint),storage);
	cvCanny(pImgGray,pImgGray,10,30,5);
	cvFindContours(pImgGray,storage,&contourSeqAll,sizeof(CvContour),CV_RETR_LIST,CV_LINK_RUNS);
	//original contours
	CvSeq* tseq=contourSeqAll;
	for (;contourSeqAll;contourSeqAll=contourSeqAll->h_next){
		cvDrawContours(pImgContourAll,contourSeqAll,cvScalar(255,0,0),cvScalar(0,0,255),0,2);
	}	
	contourSeqAll=tseq;

	CvMemStorage* storageAppr=cvCreateMemStorage();
	CvSeq* contourAppr=cvCreateSeq(0,sizeof(CvSeq),sizeof(CvPoint),storageAppr);
	contourAppr=cvApproxPoly(contourSeqAll,sizeof(CvContour),storageAppr,CV_POLY_APPROX_DP,5,1);	
	//approximated contours
	tseq=contourAppr;
	for (;contourAppr;contourAppr=contourAppr->h_next){
		cvDrawContours(pImgContourAppr,contourAppr,cvScalar(255,0,0),cvScalar(0,0,255),0,2);
	}		
	contourAppr=tseq;

	//print contours
	/*cout<<"contours:"<<endl;
	for (int i=0;i<contourAppr->total;i++){
	CvPoint* p=(CvPoint*)CV_GET_SEQ_ELEM(CvPoint,contourAppr,i);
	cout<<p->x<<","<<p->y<<endl;
	cvCircle(pImgHull,*p,3,cvScalar(0,255,255));
	cvShowImage("hull",pImgHull);
	cvWaitKey(0);
	}*/


	////convex hull
	CvSeq* hull=cvConvexHull2(contourAppr);		
	//convexity defects
	CvSeq* defectSeq=cvConvexityDefects(contourAppr,hull);
	//rearrange the detectSeq in linked sequence

	for (int i=0;i<defectSeq->total;i++){
		CvConvexityDefect* dp=(CvConvexityDefect*)CV_GET_SEQ_ELEM(CvConvexityDefect,defectSeq,i);

		cvLine(pImgDefects,*(dp->start),*(dp->end),cvScalar(0,0,255));
		cvLine(pImgDefects,*(dp->start),*(dp->depth_point),cvScalar(0x00,0x99,0xff));
		cvLine(pImgDefects,*(dp->depth_point),*(dp->end),cvScalar(0xff,0x99,0x00));
		cvCircle(pImgDefects,*(dp->depth_point),2,cvScalar(0xff,0x99,0x00));
		cout<<i<<"	:("<<dp->start->x<<","<<dp->start->y<<")"<<endl;	
	} 


	cvShowImage("original",pImgColor);
	cvShowImage("canny",pImgGray);
	cvShowImage("contour all",pImgContourAll);
	cvShowImage("contour appr",pImgContourAppr);
	cvShowImage("ConvexityDefects",pImgDefects);
	//cvShowImage("hull",pImgHull);


	cvWaitKey(0);	

	cvDestroyAllWindows();

	cvReleaseImage(&pImgColor);
	cvReleaseImage(&pImgGray);
	cvReleaseImage(&pImgContourAll);
	cvReleaseImage(&pImgContourAppr);
	cvReleaseImage(&pImgDefects);
	cvReleaseImage(&pImgHull);

	cvReleaseMemStorage(&storage);
	cvReleaseMemStorage(&storageAppr);
}