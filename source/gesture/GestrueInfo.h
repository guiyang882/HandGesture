#ifndef GESTUREINFO_H
#define GESTUREINFO_H

#include <iostream>
#include "GestureStruct.h"

using namespace std;

class GestrueInfo {
public:
	GestrueInfo();
	virtual ~GestrueInfo();

public:
    MyRect GetRect() {
        return m_Rect;
    }

    void SetRect(MyRect rect) {
        m_Rect=rect;
    }

    string* GetGestureName() {
        return &m_GestureName[0];
    }

    void AddGestureName(string str) {
		m_GestureName[m_GestureNameCount]=str;
		m_GestureNameCount++;
	}

    bool IsTheSamePosition(MyRect rect,MyRect& comparerect);

protected:
    MyRect m_Rect;
    string m_GestureName[8];
	int m_GestureNameCount;
};

#endif
