#include "graphics.hpp"
#include "palya.hpp"
using namespace genv;

Palya::Palya(int x,int y,int x2,int y2,int kikezd):Widget(x,y,x2,y2){
    valtozo=kikezd;
}

void Palya::funkciok(event ev){
    if(ev.button==btn_left&&valtozo<3&&ev.pos_x>x_kezdo&&ev.pos_x<x_kezdo+szelesseg&&ev.pos_y>y_kezdo&&ev.pos_y<y_kezdo+hosszusag){
        valtozo=1;
    }
}

void Palya::kirajzol(bool kijelolt,int ki){
    if(valtozo!=2){
        gout<<move_to(x_kezdo,y_kezdo)<<color(135,206,235)<<box(szelesseg,hosszusag);
        if(kijelolt) gout<<color(215,215,215);
        else gout<<color(255,255,255);
        gout<<move_to(x_kezdo+1,y_kezdo+1)<<box(szelesseg-2,hosszusag-2);
    }
    if((ki==0&&valtozo==1)||valtozo==3){
        gout<<color(200,0,0);
        gout<<move_to(x_kezdo+4,y_kezdo+4)<<line(szelesseg-8,hosszusag-8);
        gout<<move_to(x_kezdo+5,y_kezdo+4)<<line(szelesseg-9,hosszusag-9);
        gout<<move_to(x_kezdo+4,y_kezdo+hosszusag-5)<<line(szelesseg-8,-hosszusag+8);
        gout<<move_to(x_kezdo+5,y_kezdo+hosszusag-5)<<line(szelesseg-9,-hosszusag+9);
        valtozo=3;
    }
    if((ki==1&&valtozo==1)||valtozo==4){
        gout<<color(0,0,200);
        for (int x=x_kezdo; x<x_kezdo+szelesseg; x++){
            for(int y=y_kezdo; y<y_kezdo+hosszusag; y++){
                if(((x-(x_kezdo+szelesseg/2))*(x-(x_kezdo+szelesseg/2)))+((y-(y_kezdo+hosszusag/2))*(y-(y_kezdo+hosszusag/2)))<=10*10
                 &&((x-(x_kezdo+szelesseg/2))*(x-(x_kezdo+szelesseg/2)))+((y-(y_kezdo+hosszusag/2))*(y-(y_kezdo+hosszusag/2)))>=10*10/2+15){
                    gout<<move_to(x,y)<<dot;
                }
            }
        }
        valtozo=4;
    }
}

std::string Palya::visszaad(){
    if(valtozo==3)return "X";
    else if(valtozo==4)return "O";
    else return "üres";
}
