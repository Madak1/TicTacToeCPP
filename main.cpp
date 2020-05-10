#include "jatekmester.hpp"

int main(){
    JatekMester*j=new JatekMester();
    do{
        j->menu();
        j->jatek();
        j->vege();
    }while(j->ujra());
    return 0;
}
