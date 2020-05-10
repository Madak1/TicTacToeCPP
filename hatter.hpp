#ifndef HATTER_HPP_INCLUDED
#define HATTER_HPP_INCLUDED
#include "graphics.hpp"
#include "widgetalap.hpp"
#include <vector>

class Hatter:public Widget{
protected:
    int szin;
    std::string kicsoda1,kicsoda2;
    std::vector<std::vector<int>>k;
public:
    Hatter(int x,int y,int x2,int y2,int palya,std::string ki1,std::string ki2,std::vector<std::vector<int>>v);
    virtual void funkciok(genv::event ev);
    virtual void kirajzol(bool kijelolt,int ki);
    virtual std::string visszaad();
};

#endif // HATTER_HPP_INCLUDED
