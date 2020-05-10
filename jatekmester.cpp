#include "graphics.hpp"
#include "jatekmester.hpp"
#include "hatter.hpp"
#include "kivalaszto.hpp"
#include "szambeallito.hpp"
#include "gomb.hpp"
#include "palya.hpp"
#include <vector>
#include <sstream>

using namespace genv;
using namespace std;

vector<string> kivalaszto_feltolto(int kategoria){
    if(kategoria==0){
        vector<string>elemek{"Flugi","X","Player 1","A Verhetetlen","Ismeretlen"};
        return elemek;
    }else if(kategoria==1){
        vector<string>elemek{"Vendég","Kör","Player 2","Vendég","A Bajnok","Ismeretlen"};
        return elemek;
    }else{
        vector<string>elemek{"???"};
        return elemek;
    }
}

bool JatekMester::kereses(unsigned int x, unsigned int y,int xvo){
    int darab=2;
    if(y>=1){
        if(koordinatak[x][y-1]==xvo){
            for(int i=2;i<5;i++){
                if(y>=i){
                    if(koordinatak[x][y-i]==xvo) darab++;
                }
            }
            if(darab==5) return true;
            else darab = 2;
        }
    }
    if(x+1<koordinatak.size()){
        if(koordinatak[x+1][y]==xvo){
            for(int i=2;i<5;i++){
                if(x+i<koordinatak.size()){
                    if(koordinatak[x+i][y]==xvo) darab++;
                }
            }
            if(darab==5) return true;
            else darab = 2;
        }
    }
    if(x+1<koordinatak.size()&&y>=1){
        if(koordinatak[x+1][y-1]==xvo){
            for(int i=2;i<5;i++){
                if(x+i<koordinatak.size()&&y>=i){
                    if(koordinatak[x+i][y-i]==xvo) darab++;
                }
            }
            if(darab==5) return true;
            else darab = 2;
        }
    }
    if(x>=1&&y>=1){
        if(koordinatak[x-1][y-1]==xvo){
            for(int i=2;i<5;i++){
                if(x>=i&&y>=i){
                   if(koordinatak[x-i][y-i]==xvo) darab++;
                }
            }
            if(darab==5) return true;
            else darab = 2;
        }
    }
    return false;
}

void JatekMester::widget_manager(int felulet){
    if(felulet==0){
        Hatter*h=new Hatter(0,0,450,220,1,"","",koordinatak);
        widgetek.push_back(h);
        Kivalaszto*kv1=new Kivalaszto(120,60,180,25,2,kivalaszto_feltolto(0),1);
        widgetek.push_back(kv1);
        Kivalaszto*kv2=new Kivalaszto(120,100,180,25,2,kivalaszto_feltolto(1),2);
        widgetek.push_back(kv2);
        Szambeallito*sz1=new Szambeallito(320,85,100,40,20,15,30);
        widgetek.push_back(sz1);
        Szambeallito*sz2=new Szambeallito(320,155,100,40,20,15,30);
        widgetek.push_back(sz2);
        Gomb*g=new Gomb(30,140,270,55,false,"START");
        widgetek.push_back(g);
    }else if(felulet==1){
        Hatter*h=new Hatter(0,0,XX,YY,0,jatekos1,jatekos2,koordinatak);
        widgetek.push_back(h);
        tolasX=(30-x_szeles)/2;
        tolasY=(30-y_hosszu)/2;
        for(int y=0;y<y_hosszu;y++){
            for(int x=0;x<x_szeles;x++){
                Palya*p=new Palya(30+(x+tolasX)*25,70+(y+tolasY)*25,25,25,0);
                widgetek.push_back(p);
            }
        }
    }else{
        if(gyoztes==1){
            Hatter*h=new Hatter(0,0,XX/2,YY/3*2,2,"","",koordinatak);
            widgetek.push_back(h);
        }
        if(gyoztes==2){
            Hatter*h=new Hatter(0,0,XX/2,YY/3*2,3,"","",koordinatak);
            widgetek.push_back(h);
        }
        if(gyoztes==0){
            Hatter*h=new Hatter(0,0,XX/2,YY/3*2,4,"","",koordinatak);
            widgetek.push_back(h);
        }
        Gomb*ujra=new Gomb(XX/4-150,YY/3*2-170,300,60,false,"ÚJRA");
        widgetek.push_back(ujra);
        Gomb*exit=new Gomb(XX/4-100,YY/3*2-100,200,60,false,"VÉGE");
        widgetek.push_back(exit);
    }
}

void JatekMester::menu(){
    gout.open(450,220);
    widget_manager(0);

    kijelolt=1;

    event ev;
    while(gin>>ev&&widgetek[5]->visszaad()=="h"&&ev.keycode!=key_escape){
        if(ev.button==btn_left){
            for(unsigned int i=1;i<widgetek.size();i++){
                if(widgetek[i]->felette(ev.pos_x,ev.pos_y)) kijelolt=i;
            }
        }

        if(ev.keycode==key_tab){
            if(kijelolt==widgetek.size()-1) kijelolt=1;
            else kijelolt++;
        }

        for(Widget*widget:widgetek) widget->kirajzol(false,0);
        widgetek[kijelolt]->funkciok(ev);
        widgetek[kijelolt]->kirajzol(true,0);
        gout<<refresh;
    }
    stringstream ss;
    ss<<widgetek[3]->visszaad();
    ss>>x_szeles;
    ss.clear();
    ss<<widgetek[4]->visszaad();
    ss>>y_hosszu;
    ss.clear();
    jatekos1=widgetek[1]->visszaad();
    jatekos2=widgetek[2]->visszaad();
    widgetek.resize(0);
}

void JatekMester::jatek(){
    gout.open(XX,YY);
    widget_manager(1);

    kijelolt=1;
    ki=0;
    gyoztes=0;
    iksz=false;
    kor=false;
    megegyszer=false;
    mehetmeg=true;

    koordinatak.resize(0);
    koordinatak.resize(x_szeles);
    for(unsigned int i=0;i<koordinatak.size();i++){
        koordinatak[i].resize(y_hosszu);
    }

    event ev;
    while(gin>>ev&&gyoztes==0&&ev.keycode!=key_escape&&mehetmeg){
        mehetmeg=false;
        if(ev.button==btn_left){
            for(unsigned int i=1;i<widgetek.size();i++){
                if(widgetek[i]->felette(ev.pos_x,ev.pos_y)&&widgetek[i]->visszaad()=="üres") kijelolt=i;
            }
        }

        if(widgetek[kijelolt]->visszaad()=="üres") ures=true;
        else ures=false;

        for(Widget*widget:widgetek) widget->kirajzol(false,ki);
        widgetek[kijelolt]->funkciok(ev);
        widgetek[kijelolt]->kirajzol(true,ki);

        if(ev.button==btn_left&&ures){if(ki==0) ki=1; else ki=0;}

        x=y=0;
        for(Widget*w:widgetek){
            if(w->visszaad()=="X") koordinatak[x][y]=1;
            else if(w->visszaad()=="O") koordinatak[x][y]=2;
            else if(w->visszaad()=="üres") koordinatak[x][y]=0;
            if(w->visszaad()=="üres"||w->visszaad()=="X"||w->visszaad()=="O"){
                if(x!=x_szeles-1) x++;
                else{x=0;y++;}
            }
        }

        for(unsigned int x=0;x<koordinatak.size();x++){
            for(unsigned int y=0;y<koordinatak[x].size();y++){
                if(koordinatak[x][y]==1&&!iksz) iksz = kereses(x,y,1);
                if(koordinatak[x][y]==2&&!kor) kor = kereses(x,y,2);
                if(koordinatak[x][y]==0) mehetmeg=true;
            }
        }

        if(iksz)gyoztes=1;
        if(kor)gyoztes=2;

        gout<<refresh;
    }
    widgetek.resize(0);
}

void JatekMester::vege(){
    gout.open(XX/2,YY/3*2);
    widget_manager(2);

    kijelolt=1;

    event ev;
    while(gin>>ev&&widgetek[2]->visszaad()=="h"&&megegyszer==false){
        if(ev.button==btn_left){
            for(unsigned int i=1;i<widgetek.size();i++){
                if(widgetek[i]->felette(ev.pos_x,ev.pos_y)) kijelolt=i;
            }
        }

        if(widgetek[1]->visszaad()=="i"){
            megegyszer=true;
        }

        if(ev.keycode==key_tab){
            if(kijelolt==widgetek.size()-1) kijelolt=1;
            else kijelolt++;
        }

        for(Widget*widget:widgetek) widget->kirajzol(false,0);
        widgetek[kijelolt]->funkciok(ev);
        widgetek[kijelolt]->kirajzol(true,0);
        gout<<refresh;
    }
    widgetek.resize(0);
}

bool JatekMester::ujra(){
    return megegyszer;
}
