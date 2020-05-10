#ifndef JATEKMESTER_HPP_INCLUDED
#define JATEKMESTER_HPP_INCLUDED
#include "widgetalap.hpp"
#include <vector>

class JatekMester{
protected:
    const int XX=810;
    const int YY=850;
    int x_szeles,y_hosszu;
    std::string jatekos1,jatekos2;
    std::vector<Widget*> widgetek;
    std::vector<std::vector<int>> koordinatak;
    unsigned int kijelolt;
    bool mehetmeg,ures,iksz,kor;
    int ki,x,y;
    int tolasX,tolasY,gyoztes;
    bool megegyszer;
public:
    void widget_manager(int menu);
    bool kereses(unsigned int x, unsigned int y,int xvo);
    void menu();
    void jatek();
    void vege();
    bool ujra();
};

#endif // JATEKMESTER_HPP_INCLUDED
