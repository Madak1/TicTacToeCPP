#ifndef WIDGETALAP_HPP_INCLUDED
#define WIDGETALAP_HPP_INCLUDED
#include "graphics.hpp"

class Widget{
protected:
    int x_kezdo,y_kezdo,szelesseg,hosszusag;
public:
    Widget(int x,int y,int x2,int y2);
    virtual bool felette(int ex,int ey);
    virtual void funkciok(genv::event ev)=0;
    virtual void kirajzol(bool kijelolt,int ki)=0;
    virtual std::string visszaad()=0;
};

#endif // WIDGETALAP_HPP_INCLUDED
