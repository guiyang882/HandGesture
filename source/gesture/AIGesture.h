#ifndef AIGESTURE_H
#define AIGESTURE_H

#include "GestureStruct.h"
#include <QProgressDialog>

class HandGestureDialog;
class CAIGesture {
public:
	CAIGesture();
	virtual ~CAIGesture();

    void setMainUIPointer(HandGestureDialog* pDlg);

private:
    HandGestureDialog* pMainUI;

public:
	void SkinDetect(IplImage* src,IplImage* dst);
	//肤色检测,其中src为输入图像，dst为输出图像

	void FindBigContour(IplImage* src,CvSeq* (&contour),CvMemStorage* storage);
	//求最大的轮廓，src为输入图像，contour是输出轮廓,storage为opencv一个内存结构

	void ComputeCenter(CvSeq* (&contour),CvPoint& center,float &radius);
	//计算机出手势的中心，contour为输入轮廓，center为输出中心，radius为输出半径

	void GetFeature(IplImage* src,
		CvPoint& center,
		float radius,
		float angle[FeatureNum][10],
		float anglecha[FeatureNum][10],
		float count[FeatureNum]);
	//提取手势的特征，src为输入图像，center为输入中心，radius为输入半径，angle,anglecha,count为输出特征

    void OneGestureTrain(QDir GestureDir,CvFileStorage *fs,GestureStruct gesture);
	//对单类图像进行训练，GesturePath为输入手势训练文件夹，fs为一个文件存储器，gesture是一个手势结构

    void Train(QProgressDialog* pBar);
	//训练，其中FolderPath为训练样本的文件夹路径

    void Recognise(IplImage* src,string& result);
	//识别,src为输入图像，result为输出结果

	void Follow(IplImage* src,CvRect& track_window,CvBox2D &track_box);
	//手势跟踪,src为输入图像，track_window为一个跟踪矩形，track_box为一个输入参数，目前没用上，可能以后会用上

    void RecogniseSeq(CvPoint pt[8],float width,float height,string &result);
	//对一个序列进行识别，pt[8]是输入的8个点，result为输出的结果，flag为判断是否为第一次，因为只有两次识别才认为是命令
	void ColorRegulate(IplImage* src,IplImage* dst);
	//进行颜色校正，不过效果好像不是很好，src为输入图像，dst为输出图像

	void EqualImage(IplImage* src,IplImage*dst);
	//直方图均衡化,src为输入图像，dst为输出图像

	void SaveImage(IplImage* src);
	//保存图像用以训练

    void RecogniseResult(string str[8],string &result);
	//提取在str[8]中出现次数大于6的字符串保存到result中;

	/*下面程序段作为备用，目前还没有得到应用*/
	void CalcHist(IplImage* src,CvRect &rect,CvHistogram* (&hist));
	//计算rect内的肤色部分的直方图

    void Follow(IplImage* src,CvRect& track_window,CvHistogram* &hist,bool& Flag);
	//对手势进行跟踪

    void SaveForTrain(IplImage* src,CvPoint pt[8],string &result);
	//对一个点的序列进行保存，可以训练，可以用HMM模型试一下，不过，HMM模型看不出方向，应该指明方向

    void Location(IplImage* src[8],MyRect& rect);
};

#endif
