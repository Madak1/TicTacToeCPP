#include "widgetalap.hpp"

Widget::Widget(int x,int y,int x2,int y2){
    x_kezdo=x;
    y_kezdo=y;
    szelesseg=x2;
    hosszusag=y2;
}

bool Widget::felette(int ex, int ey){
    return ex>x_kezdo&&ex<x_kezdo+szelesseg&&ey>y_kezdo&&ey<y_kezdo+hosszusag;
}
