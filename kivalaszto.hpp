#ifndef KIVALASZTO_HPP_INCLUDED
#define KIVALASZTO_HPP_INCLUDED
#include "graphics.hpp"
#include "widgetalap.hpp"
#include <vector>

class Kivalaszto:public Widget{
protected:
    int kivalasztott=0,db,i_potlo=1,szin;
    std::string elotte,utana;
    std::vector<std::string>elemek;
    bool megnyitva=false;
///---LegorduloMenuGyorsAtalakitasa---
    int keret=3;
    int tavolsag=2;
    int beljebb=4;
    bool fokozatos=true;
///-----------------------
public:
    Kivalaszto(int x,int y,int x2,int y2,int menuHossz,std::vector<std::string>elemV,int p);
    virtual void funkciok(genv::event ev);
    virtual void kirajzol(bool kijelolt,int ki);
    virtual std::string visszaad();
};
#endif // KIVALASZTO_HPP_INCLUDED
