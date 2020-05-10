#include "graphics.hpp"
#include "gomb.hpp"

using namespace genv;

Gomb::Gomb(int x,int y,int x2,int y2,bool vissza,std::string szoveg):Widget(x,y,x2,y2){
    iVh=vissza;
    srg=szoveg;
}

void Gomb::funkciok(event ev){
    if((ev.button==btn_left&&ev.pos_x>x_kezdo&&ev.pos_x<x_kezdo+szelesseg&&ev.pos_y>y_kezdo&&ev.pos_y<y_kezdo+hosszusag)||ev.keycode==key_enter) iVh=true;
}

void Gomb::kirajzol(bool kijelolt,int ki){
    gout<<color(100,100,100)<<move_to(x_kezdo,y_kezdo)<<box(szelesseg,hosszusag);
    if(kijelolt) gout<<color(250,250,250);
    else gout<<color(200,200,200);
    gout<<move_to(x_kezdo+5,y_kezdo+5)<<box(szelesseg-10,hosszusag-10);
    gout<<color(100,100,100)<<move_to(x_kezdo+szelesseg/2-20,y_kezdo+hosszusag/2+5)<<text(srg);
}

std::string Gomb::visszaad(){
    if(iVh) return "i";
    else return "h";
}
