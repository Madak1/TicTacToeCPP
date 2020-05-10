#include "graphics.hpp"
#include "hatter.hpp"
using namespace genv;

Hatter::Hatter(int x,int y,int x2,int y2,int palya,std::string ki1,std::string ki2,std::vector<std::vector<int>>v):Widget(x,y,x2,y2){
    szin=palya;
    kicsoda1=ki1;
    kicsoda2=ki2;
    k=v;
}

void Hatter::funkciok(event ev){
}

void Hatter::kirajzol(bool kijelolt,int ki){
    if(szin==0){
        gout<<color(173,134,87)<<move_to(x_kezdo,y_kezdo)<<box(szelesseg,hosszusag);
        gout<<color(193,154,107)<<move_to(x_kezdo+10,y_kezdo+10)<<box(szelesseg-20,hosszusag-20);
        gout<<color(0,0,0)<<move_to(x_kezdo+30,y_kezdo+35)<<text("TIC TAC TOE  -  GAME");
        gout<<move_to(x_kezdo+25,y_kezdo+40)<<line(175,0);
        gout<<move_to(x_kezdo+30,y_kezdo+60)<<text(kicsoda1)<<text(" VS ")<<text(kicsoda2);

    }
    if(szin==1){
        gout<<color(50,50,50)<<move_to(x_kezdo,y_kezdo)<<box(szelesseg,hosszusag);
        gout<<color(140,150,160)<<move_to(x_kezdo+10,y_kezdo+10)<<box(szelesseg-20,hosszusag-20);
        gout<<color(0,0,0)<<move_to(x_kezdo+30,y_kezdo+40)<<text("TIC TAC TOE  -  MAIN MENU");
        gout<<move_to(x_kezdo+25,y_kezdo+50)<<line(400,0);
        gout<<move_to(x_kezdo+30,y_kezdo+75)<<text("1.Játékos:");
        gout<<move_to(x_kezdo+30,y_kezdo+120)<<text("2.Játékos:");
        gout<<move_to(x_kezdo+320,y_kezdo+75)<<text("Szélesség:");
        gout<<move_to(x_kezdo+320,y_kezdo+145)<<text("Hoszzúság:");
    }
    if(szin==2){
        gout<<color(200,20,20)<<move_to(x_kezdo,y_kezdo)<<box(szelesseg,hosszusag);
        gout<<color(140,150,160)<<move_to(x_kezdo+10,y_kezdo+10)<<box(szelesseg-20,hosszusag-20);
    }
    if(szin==3){
        gout<<color(20,20,200)<<move_to(x_kezdo,y_kezdo)<<box(szelesseg,hosszusag);
        gout<<color(140,150,160)<<move_to(x_kezdo+10,y_kezdo+10)<<box(szelesseg-20,hosszusag-20);
    }
    if(szin==4){
        gout<<color(50,50,50)<<move_to(x_kezdo,y_kezdo)<<box(szelesseg,hosszusag);
        gout<<color(140,150,160)<<move_to(x_kezdo+10,y_kezdo+10)<<box(szelesseg-20,hosszusag-20);
    }
    if(szin>1){
        gout<<color(255,255,255)<<move_to(x_kezdo+30,y_kezdo+40)<<text("TIC TAC TOE  -  GAME OVER");
        gout<<move_to(x_kezdo+25,y_kezdo+50)<<line(215,0);
        for(int x=0;x<k.size();x++){
           for(int y=0;y<k[x].size();y++){
                gout<<move_to(szelesseg/2-k.size()*5+x*10,hosszusag/2-k[x].size()*5+y*10-50)<<color(255,255,255);
                if(k[x][y]==1) gout<<color(250,0,0)<<text("X");
                else if(k[x][y]==2) gout<<color(0,0,250)<<text("O");
                else gout<<text("*");
           }
        }
    }
}

std::string Hatter::visszaad(){
    return "háttér";
}
