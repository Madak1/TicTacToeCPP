#include "graphics.hpp"
#include "szambeallito.hpp"
using namespace genv;

Szambeallito::Szambeallito(int x,int y,int x2,int y2,int kezdo,int mini,int maxi):Widget(x,y,x2,y2){
    uj_szelesseg=szelesseg-hosszusag/2-2;

    fel_x=x_kezdo+szelesseg-hosszusag/2;
    fel_y=y_kezdo;
    fel_szelesseg=hosszusag/2-1;
    fel_hosszusag=hosszusag/2-1;

    le_x=x_kezdo+szelesseg-hosszusag/2;
    le_y=y_kezdo+hosszusag/2+1;
    le_szelesseg=hosszusag/2-1;
    le_hosszusag=hosszusag/2-1;

    szam=kezdo;
    minErtek=mini;
    maxErtek=maxi;
    }

void Szambeallito::funkciok(event ev){
    kov=szam;

    if (ev.keycode==key_backspace) kov=0;

    if((ev.keycode==key_up)
    ||(ev.pos_x>fel_x&&ev.pos_x<fel_x+fel_szelesseg&&ev.pos_y>fel_y&&ev.pos_y<fel_y+fel_hosszusag&&ev.button==btn_left)) kov++;
    if(ev.keycode==key_pgup) kov+=10;
    if(ev.button==btn_wheelup) kov+=100;

    if((ev.keycode==key_down)
    ||(ev.pos_x>le_x&&ev.pos_x<le_x+le_szelesseg&&ev.pos_y>le_y&&ev.pos_y<le_y+le_hosszusag&&ev.button==btn_left)) kov--;
    if(ev.keycode==key_pgdn) kov-=10;
    if(ev.button==btn_wheeldown) kov-=100;

    ss<<kov;
    ss>>skov;
    ss.clear();
    if(szelesseg-hosszusag/2-6>8*(skov.size()+1)-1) szam=kov;
    if(kov<minErtek) szam=minErtek;
    if(kov>maxErtek) szam=maxErtek;
}

void Szambeallito::kirajzol(bool kijelolt,int ki){
    ss<<szam;
    ss>>sszam;
    ss.clear();

    gout<<color(255,255,255)<<move_to(x_kezdo,y_kezdo)<<box(uj_szelesseg,hosszusag);

    gout<<color(220,220,220)<<move_to(fel_x,fel_y)<<box(fel_szelesseg,fel_hosszusag)<<move_to(le_x,le_y);
    if(hosszusag%2!=0) gout<<box(le_szelesseg,le_hosszusag+1);
    else gout<<box(le_szelesseg,le_hosszusag);

    gout <<color(0,0,0)<<move_to(fel_x+4,fel_y+fel_hosszusag-5)<<line_to(fel_x+fel_szelesseg-5,fel_y+fel_hosszusag-5)
    <<line_to(fel_x+fel_szelesseg/2,fel_y+4)<<line_to(fel_x+4,fel_y+fel_hosszusag-5);

    gout <<color(0,0,0)<<move_to(le_x+4,le_y+4)<<line_to(le_x+le_szelesseg-5,le_y+4)
    <<line_to(le_x+le_szelesseg/2,le_y+le_hosszusag-5)<<line_to(le_x+4,le_y+4);

    if(kijelolt) gout<<color(100,100,100)<<move_to(x_kezdo+2,y_kezdo+2)<<box(uj_szelesseg-4,hosszusag-4)<<color(255,255,255);
    else gout<<color(0,0,0);
    gout<<move_to(x_kezdo+5,y_kezdo+hosszusag/2+5)<<text(sszam);
}

std::string Szambeallito::visszaad(){
    return sszam;
}
