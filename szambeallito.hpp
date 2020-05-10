#ifndef SZAMBEALLITO_HPP_INCLUDED
#define SZAMBEALLITO_HPP_INCLUDED
#include "graphics.hpp"
#include "widgetalap.hpp"
#include <sstream>

class Szambeallito:public Widget{
protected:
    int uj_szelesseg,fel_x,fel_y,fel_szelesseg,fel_hosszusag,
    le_x,le_y,le_szelesseg,le_hosszusag,szam,kov,maxErtek,minErtek;
    std::string sszam,skov;
    std::stringstream ss;
public:
    Szambeallito(int x,int y,int x2,int y2,int kezdo,int mini,int maxi);
    virtual void funkciok(genv::event ev);
    virtual void kirajzol(bool kijelolt,int ki);
    virtual std::string visszaad();
};

#endif // SZAMBEALLITO_HPP_INCLUDED
