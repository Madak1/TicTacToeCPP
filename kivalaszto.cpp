#include "graphics.hpp"
#include "kivalaszto.hpp"

using namespace genv;

Kivalaszto::Kivalaszto(int x,int y,int x2,int y2,int menuHossz,std::vector<std::string>elemV,int p):Widget(x,y,x2,y2){
    elemek=elemV;
    db=menuHossz;
    szin=p;
}

void Kivalaszto::funkciok(event ev){

    if(ev.pos_x>x_kezdo&&ev.pos_x<x_kezdo+szelesseg&&ev.pos_y>y_kezdo&&ev.pos_y<y_kezdo+hosszusag){
        megnyitva=true;
    } else megnyitva=false;

    if(ev.keycode==key_up||(ev.button==btn_wheelup&&megnyitva)){
        if(kivalasztott==0) kivalasztott=elemek.size()-1;
        else kivalasztott--;
    }
    if(ev.keycode==key_pgup) kivalasztott=0;

    if(ev.keycode==key_down||(ev.button==btn_wheeldown&&megnyitva)){
        if(kivalasztott==elemek.size()-1) kivalasztott=0;
        else kivalasztott++;
    }
    if(ev.keycode==key_pgdn) kivalasztott=elemek.size()-1;
}

void Kivalaszto::kirajzol(bool kijelolt,int ki){
    gout<<color(255,255,255)<<move_to(x_kezdo,y_kezdo)<<box(szelesseg,hosszusag);
    if(kijelolt){
        if(szin==1) gout<<color(200,10,10);
        if(szin==2) gout<<color(10,10,200);
        gout<<move_to(x_kezdo+2,y_kezdo+2)<<box(szelesseg-4,hosszusag-4)<<color(255,255,255);
    }
    else gout<<color(0,0,0);
    gout<<move_to(x_kezdo+7,y_kezdo+hosszusag/2+5)<<text(elemek[kivalasztott]);

    if(megnyitva&&kijelolt){
        if(db<0) db=0;
        if(db>elemek.size()) db=elemek.size();
        for(int i=1;i<db+1;i++){
            if(kivalasztott-i<0){
                for(int e=1;e<db+1;e++){
                    if(kivalasztott-i==-e) elotte=elemek[elemek.size()-e];
                }
            }
            else elotte=elemek[kivalasztott-i];

            if(kivalasztott+i>elemek.size()-1){
                for(int u=0;u<db;u++){
                    if(kivalasztott+i==elemek.size()+u) utana=elemek[u];
                }
            }
            else utana=elemek[kivalasztott+i];

            if(fokozatos) i_potlo=i;
            if(y_kezdo-i*(hosszusag+tavolsag)>3){
                gout<<color(100,100,100)<<move_to(x_kezdo+i_potlo*beljebb,y_kezdo-i*(hosszusag+tavolsag))
                <<box(szelesseg-2*i_potlo*beljebb,hosszusag);
                gout<<color(200,200,200)<<move_to(x_kezdo+i_potlo*beljebb+keret,y_kezdo-i*(hosszusag+tavolsag)+keret)
                <<box(szelesseg-2*i_potlo*beljebb-2*keret,hosszusag-2*keret);
                gout<<color(50,50,50)<<move_to(x_kezdo+7+i_potlo*beljebb,y_kezdo-i*(hosszusag+tavolsag)+hosszusag/2+5)
                <<text(elotte);
            }
            if(400>y_kezdo+(i+1)*(hosszusag+tavolsag)){
                gout<<color(100,100,100)<<move_to(x_kezdo+i_potlo*beljebb,y_kezdo+i*(hosszusag+tavolsag))
                <<box(szelesseg-2*i_potlo*beljebb,hosszusag);
                gout<<color(200,200,200)<<move_to(x_kezdo+i_potlo*beljebb+keret,y_kezdo+i*(hosszusag+tavolsag)+keret)
                <<box(szelesseg-2*i_potlo*beljebb-2*keret,hosszusag-2*keret);
                gout<<color(50,50,50)<<move_to(x_kezdo+7+i_potlo*beljebb,y_kezdo+i*(hosszusag+tavolsag)+hosszusag/2+5)
                <<text(utana);
            }
        }
    }
}

std::string Kivalaszto::visszaad(){
    return elemek[kivalasztott];
}
