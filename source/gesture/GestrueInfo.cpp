#include "GestrueInfo.h"

GestrueInfo::GestrueInfo() {
	m_GestureNameCount=0;
}

GestrueInfo::~GestrueInfo() {

}

bool GestrueInfo::IsTheSamePosition(MyRect rect, MyRect &comparerect) {
    MyRect tmprect;
	if(!rect.IsRectEmpty()&&!comparerect.IsRectEmpty()) {
        /*find the public part*/
        int x = rect.vertex_X ()>comparerect.vertex_X ()?comparerect.vertex_X ():rect.vertex_X ();
        int y = rect.vertex_Y ()>comparerect.vertex_Y ()?comparerect.vertex_Y ():rect.vertex_Y ();
        int width = rect.Width ()>comparerect.Width ()?rect.Width ():comparerect.Width();
        int height = rect.Height ()>comparerect.Height ()?rect.Height ():comparerect.Height ();
        tmprect.initRect (x,y,width,height);

		if(tmprect.Width()*tmprect.Height()>rect.Width()*rect.Height()/2)
            return true;
        return false;
	}
    return false;
}
