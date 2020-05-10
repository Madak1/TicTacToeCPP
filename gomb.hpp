#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include "graphics.hpp"
#include "widgetalap.hpp"

class Gomb:public Widget{
protected:
    bool iVh;
    std::string srg;
public:
    Gomb(int x,int y,int x2,int y2,bool vissza,std::string szoveg);
    virtual void funkciok(genv::event ev);
    virtual void kirajzol(bool kijelolt,int ki);
    virtual std::string visszaad();
};

#endif // GOMB_HPP_INCLUDED
