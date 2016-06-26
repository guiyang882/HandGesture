#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
#include<cmath>
#include<stdio.h>
#include<iostream>
#include <fstream>
using namespace	std;
#define	SQRT(x,	y) sqrt((x)*(x)	+ (y)*(y))

void ColorSegmentation(IplImage* img,IplImage* P_);//肤色分割
int	otsu (IplImage*	image);// 大津法求取阈值
void Processing(IplImage* P_);//对图像进行各种处理
void Outline(IplImage* P_);//轮廓提取
void  Fourier(IplImage*	pContourImg,CvSeq* pcontour);//计算傅立叶描述子
const char*	filename="E:\\vs工程\\Gesture Recognition\\测试\\1.6.jpg";//待检测图像
	ofstream outfile("E:\\vs工程\\Gesture Recognition\\数据\\1.6.txt");//傅立叶描述子存储的txt文件

int	_tmain(int argc, _TCHAR* argv[])
{ 
	
	
	cvNamedWindow("外轮廓提取",1);
	IplImage* img=cvLoadImage(filename,CV_WINDOW_AUTOSIZE);	 //加载图像
	IplImage* P_=cvCreateImage(cvGetSize(img),8,1);//肤色相似灰度图
	
	
	ColorSegmentation(img,P_);
	Processing(P_);
	Outline(P_);

	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&P_);
	cvDestroyWindow("外轮廓提取");
	
	return 0;
}

void ColorSegmentation(IplImage* img,IplImage* P_)
{
	IplImage* img_YCrCb=cvCreateImage(cvGetSize(img),8,3);//YCrCb空间同道图像
	IplImage* Y=cvCreateImage(cvGetSize(img),8,1);//Y空间图像
	IplImage* Cr=cvCreateImage(cvGetSize(img),8,1);//Cr空间图像
	IplImage* Cb=cvCreateImage(cvGetSize(img),8,1);//Cb空间图像

	cvCvtColor(img,img_YCrCb,CV_BGR2YCrCb);//将图像从RGB空间转换到YCrCb空间
	cvSplit(img_YCrCb,Y,Cr,Cb,0);//将YCrCb多通道图像分割成3个单通道图像

	IplImage* P=cvCreateImage(cvGetSize(img),IPL_DEPTH_32F,1);//浮点型单同道图像
	
	int	step=P->widthStep/sizeof(float);
	float *data_p=(float*)P->imageData;
	float max=0.0;

	for(int	i=0;i<img->height;i++)
	{
		for(int	j=0;j<img->width;j++)
		{
			float wr,wb;
			float y=CV_IMAGE_ELEM(Y,uchar,i,j);//获取第i行D第j列的Y的值
			float cr=CV_IMAGE_ELEM(Cr,uchar,i,j);//获取第i行第j列的Cr的值
			float cb=CV_IMAGE_ELEM(Cb,uchar,i,j);//获取第i行D第j列的Cb的值
			wr=cr-156.5599;
			wb=cb-117.4361;
			 data_p[i*step+j]=exp(-0.5*(wr*0.00334967-wb*0.00025401)*wr-0.5*(-wr*0.00025401+wb*0.00626418)*wb);//高斯肤色概率模型
			if(max<=data_p[i*step+j])
				max=data_p[i*step+j];//最大概率
		}
	}
	for(int	i=0;i<img->height;i++)
	{
		for(int	j=0;j<img->width;j++)
		{
			(P_->imageData+i*P_->widthStep)[j]=255*data_p[i*step+j]/max;//归一化
		}

	}
	cvSaveImage("E:\\vs工程\\Gesture Recognition\\图片\\picture1.jpg",P_ );	//保存图片
	
	
	cvReleaseImage(&img_YCrCb);//释放图像空间
	cvReleaseImage(&Y);
	cvReleaseImage(&Cr);
	cvReleaseImage(&Cb);
	cvReleaseImage(&P);

}

int	otsu (IplImage *image)
{
	int	w =	image->width;
	int	h =	image->height;

	unsigned char *np; // 图像指针
	unsigned char pixel;
	int	thresholdValue=1; // 阈值
	int	ihist[256];	// 图像直方图，	256个点

	int	i, j, k; 
	int	n, n1, n2, gmin, gmax;
	double m1, m2, sum,	csum, fmax,	sb;

	memset(ihist, 0, sizeof(ihist)); //	对直方图置零...

	gmin=255; gmax=0;
	// 生成直方图
	for	(i = 0;	i <	h; i++)	
	{
		np = (unsigned char*)(image->imageData + image->widthStep*i);
		for	(j = 0;	j <	w; j++)	
		{
			pixel =	np[j];
			ihist[ pixel]++;
			if(pixel > gmax) gmax= pixel;
			if(pixel < gmin) gmin= pixel;
		}
	}
	sum	= csum = 0.0;
	n =	0;

	for	(k = 0;	k <= 255; k++) 
		{
			sum	+=(double)k	*(double)ihist[k]; //x*f(x)	质量矩
			n += ihist[k]; //f(x) 质量 
		}

	if (!n)	
	{
		thresholdValue = 160;
	}

	fmax = -1.0;
	n1 = 0;
	for	(k = 0;	k <	255; k++) 
	{
		n1 += ihist[k];
		if (!n1) { continue; }
		n2 = n - n1;
		if (n2 == 0) { break; }
		csum +=(double)	k *ihist[k];
		m1 = csum /	n1;
		m2 = (sum -	csum) /	n2;
		sb =(double) n1	*(double) n2 *(m1 -	m2)	* (m1 -	m2);
		if (sb > fmax)
			{
				fmax = sb;
				thresholdValue = k;
			}
	}
	return(thresholdValue);
}

void Processing(IplImage* P_)
{
	cvThreshold(P_,P_,otsu (P_)-10,255,CV_THRESH_BINARY	);//自适应阈值二值化
	
	cvSaveImage("E:\\vs工程\\Gesture Recognition\\图片\\picture2.jpg",P_ );	//保存jpg格式图片

	cvSmooth(P_,P_,CV_MEDIAN ,3,0,0,0 );//平滑处理

	cvMorphologyEx(P_,P_,0,NULL,CV_MOP_OPEN	 ,1	);//开运算
	cvMorphologyEx(P_,P_,0,NULL,CV_MOP_CLOSE  ,1 );//闭运算
	
	cvSaveImage("E:\\vs工程\\Gesture Recognition\\图片\\picture3.jpg",P_ );	
	cvCanny(P_,P_,2,4,3	);//canny边缘检测
	
}

void Outline(IplImage* P_)
{
	IplImage* opContourImg=cvCreateImage(cvGetSize(P_),8,1);
	IplImage* pContourImg=cvCreateImage(cvGetSize(P_),8,1);
	cvZero(pContourImg);//0初始化
	cvZero(opContourImg);

	int	contoursNum=0;//提取轮廓的数目?

	CvMemStorage * storage=cvCreateMemStorage(0);//提取轮廓需要的储容量0为默认64KB
	CvSeq *	pcontour=0;	//提取轮廓的序列指针
	CvSeq* contoursHead	= 0;
	CvSeq* p = NULL;
	CvSeq* q = NULL;
	CvSeq* seqMidObj=0;

	cvFindContours(	P_,	storage, &pcontour,	sizeof(CvContour),	CV_RETR_EXTERNAL);//只查找外轮廓

	cvDrawContours(	opContourImg,pcontour,	cvScalarAll(255),cvScalar(255,0,0,0),1);//画提取的外轮廓
	
	cvSaveImage("E:\\vs工程\\Gesture Recognition\\图片	\\picture4.jpg",opContourImg); 
	
	contoursHead = pcontour;//contours的头ª
	 //去除小面积区域
	int	contArea = 0;
	int	imgArea	= P_->height * P_->width;
 
	for( ; pcontour	!= 0; pcontour = pcontour->h_next )
	{
		//如果面积过小,	则排除
		contArea = fabs(cvContourArea( pcontour, CV_WHOLE_SEQ ));
		if ( (double)contArea/imgArea <	0.015 ){continue;}
		//建立轮廓链表
		q =	p;
		p =	pcontour;
		if(q ==	NULL)
		{
			seqMidObj =	p;
		}
		else
		{
			q->h_next =	p;
			p->h_prev =	q;
		}
	}
	if(seqMidObj)
	{
		seqMidObj->h_prev =	NULL;
		p->h_next =	NULL;
	}

	cvDrawContours(	pContourImg,seqMidObj, cvScalarAll(255),cvScalar(255,0,0,0),1);//画最终提取的轮廓
	cvShowImage("外轮廓提取",pContourImg);
	contoursNum=cvFindContours(pContourImg,storage,&pcontour,sizeof(CvContour),CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);//将轮廓链码转换为点序列
	cout<<"轮廓个数为："<<contoursNum<<" "<<endl;

	Fourier(pContourImg,pcontour);

	cvReleaseImage(&pContourImg);
	cvReleaseImage(&opContourImg);
}

void  Fourier(IplImage*	pContourImg,CvSeq* pcontour)
{
	
	IplImage* img=cvLoadImage(filename,CV_WINDOW_AUTOSIZE);	//加载图像
	
	CvScalar color=CV_RGB(255,0,0);//红色
	CvMat *re =	cvCreateMat(1,pcontour->total,CV_32FC1);//实部
	CvMat *im =	cvCreateMat(1,pcontour->total,CV_32FC1);//虚部
	CvMat *re_dst =	cvCreateMat(1,pcontour->total,CV_32FC1);//变换后实部
	CvMat *im_dst =	cvCreateMat(1,pcontour->total,CV_32FC1);//变换后虚部
	CvMat *sum_src = cvCreateMat(1,pcontour->total,CV_32FC2);//实部虚部结合体
	CvMat *sum_dst = cvCreateMat(1,pcontour->total,CV_32FC2);//变换后实部虚部结合体
	int	total=pcontour->total;
	float *real,*image,*fourier,*value;
	real = (float *) malloc(sizeof(float)*(pcontour->total)); //实部
	image =	(float *) malloc(sizeof(float)*(pcontour->total)); //虚部
	fourier	= (float *)	malloc(sizeof(float)*(pcontour->total)); //傅立叶系数
	value =	(float *) malloc(sizeof(float)*(pcontour->total));//傅立叶描绘子
	for	(;pcontour!=0;pcontour=pcontour->h_next)
	{
		int	hmax=0;
		int	hmin=1000;
		int	wmax=0;
		int	wmin=1000;
		int	xsum=0;
		int	ysum=0;
		for(int	j =	0; j < pcontour->total;	++j) 
		{  
			CvPoint	*p = (CvPoint *)cvGetSeqElem(pcontour, j);
			xsum+=p->x;
			ysum+=p->y;
		}
		float a=(float)(pContourImg->width/2-xsum/pcontour->total);
		float b=(float)(pContourImg->height/2-ysum/pcontour->total);
		for(int	j =	0; j < pcontour->total;	++j) 
		{  
			CvPoint	*p = (CvPoint *)cvGetSeqElem(pcontour, j);	
			*(real+j)=p->x-a;
			*(image+j)=p->y-b;
		   if(wmax<=p->x)
				wmax=p->x;
			if(hmax<=p->y)
				hmax=p->y;
			if(wmin>=p->x)
				wmin=p->x;
			if(hmin>=p->y)
				hmin=p->y;
		}	
		CvPoint	max,min;
		//矩形边界
		max.x=wmax,max.y=hmax;
		min.x=wmin,min.y=hmin;
		cvRectangle(img,max, min,color ,1,8,0 );//画手区域矩形框
		
		cvInitMatHeader(re,	1, pcontour->total,	CV_32FC1, real); //初始化实部
		cvInitMatHeader(im,	1, pcontour->total,	CV_32FC1, image); //初始化虚部
		cvMerge(re,im,0,0,sum_src);
		cvDFT(sum_src,sum_dst,CV_DXT_FORWARD,0);//傅立叶变换
		cvSplit(sum_dst,re_dst,im_dst,0,0);
		
		for(int	i =	0; i <14; i++)
		{
		float a=cvmGet(re_dst,0,i)/pcontour->total;// 傅立叶变换后实部
		float b=cvmGet(im_dst,0,i)/pcontour->total;// 傅立叶变换后虚部
		*(fourier+i)=SQRT(a,b);	
		}
		for(int	i =2 ; i <14;i++)
		{
			float a=*(fourier+1);
			*(value+i)=*(fourier+i)/a;// 傅立叶描述子
			outfile<<*(value+i)<<" ";
		}
		outfile<<endl;
	}
cvSaveImage("E:\\vs工程\\Gesture Recognition\\图片\\picture5.jpg",pContourImg);	
}
