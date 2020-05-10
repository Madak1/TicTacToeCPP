#ifndef PALYA_HPP_INCLUDED
#define PALYA_HPP_INCLUDED

#include "graphics.hpp"
#include "widgetalap.hpp"

class Palya:public Widget{
protected:
    int valtozo;
    int pluszX,pluszY;
    int x_szer,y_szor;
public:
    Palya(int x,int y,int x2,int y2,int kikezd);
    virtual void funkciok(genv::event ev);
    virtual void kirajzol(bool kijelolt,int ki);
    virtual std::string visszaad();
};

#endif // PALYA_HPP_INCLUDED
