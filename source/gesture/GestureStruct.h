#ifndef GESTURESTRUCT_H
#define GESTURESTRUCT_H

#include <QFileDialog>
#include <QMessageBox>
#include <QString>

#include <time.h>
#include <ctime>

#include <iostream>
#include <opencv/cv.h>
#include <opencv/cvaux.h>
#include <opencv/cvwimage.h>
#include <opencv/cxcore.h>

#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>

using namespace std;
using namespace cv;

const int FeatureNum=5;//定义手势特征的圈数

#define LEFT    0x01
#define RIGHT   0x02
#define COMEON  0x04
#define GO      0x8

class MyPoint
{
private:
    int m_x,m_y;
public:
    MyPoint(int x,int y)
    {
        m_x = x;
        m_y = y;
    }
    int X(){return m_x;}
    int Y(){return m_y;}
};

typedef struct _MyRect
{
    int m_x,m_y;
    int m_width,m_height;

    void initRect(int x,int y,int width,int height)
    {
        m_x = x;m_y = y;m_width = width;m_height = height;
    }

    void initPointRect (MyPoint top_left,MyPoint right_bottom)
    {
        m_x = top_left.X ();
        m_y = top_left.Y ();
        m_width = right_bottom.X ()-top_left.X ();
        m_height = right_bottom.Y ()-top_left.Y ();
    }

    void SetRectEmpty()
    {
        m_x = 0,m_y = 0;
        m_width = 0,m_height = 0;
    }

    bool IsRectEmpty()
    {
        if(m_width == 0 || m_height == 0)
            return true;
        return false;
    }

    MyPoint TopLeft()
    {
        MyPoint temp(m_x,m_y);
        return temp;
    }

    MyPoint BottomRight()
    {
        MyPoint temp(m_x+m_width,m_y+m_height);
        return temp;
    }

    int vertex_X(){return m_x;}
    int vertex_Y(){return m_y;}
    int Width(){return m_width;}
    int Height(){return m_height;}
}MyRect;

struct GestureStruct//定义一个手势结构
{
    float angle[FeatureNum][10];//肤色角度
    float anglecha[FeatureNum][10];//非肤色角度
    float count[FeatureNum];//角度肤色的个数
    string GestureName;//手势名字
    string angleName;//角度的名字，用于写入yml文件作为一个节点，用于识别的时候通过识别来提取参数
    string anglechaName;//角度的名字，用于写入yml文件作为一个节点，用于识别的时候通过识别来提取参数
    string countName;//角度的个数，可以理解为多少个手指（但实际上不只是这样),用于写入yml文件作为一个节点，用于识别的时候通过识别来提取参数
};

#endif
