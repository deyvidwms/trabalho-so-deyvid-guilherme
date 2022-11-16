#include "trem.h"
#include <QtCore>

Trem::Trem(int ID, int x, int y, int vel){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->vel = vel;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 40 && x <310)
                x+=10;
            else if (x == 310 && y < 160)
                y+=10;
            else if (x > 40 && y == 160)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y, vel);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 40 && x <580)
                x+=10;
            else if (x == 580 && y < 160)
                y+=10;
            else if (x > 310 && y == 160)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y, vel);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 40 && x <850)
                x+=10;
            else if (x == 850 && y < 160)
                y+=10;
            else if (x > 580 && y == 160)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y, vel);    //Emite um sinal
            break;
        case 4: //Trem 4
            if (y == 160 && x <440)
                x+=10;
            else if (x == 440 && y < 280)
                y+=10;
            else if (x > 170 && y == 280)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y, vel);    //Emite um sinal
            break;
        case 5: //Trem 5
            if (y == 160 && x <710)
                x+=10;
            else if (x == 710 && y < 280)
                y+=10;
            else if (x > 440 && y == 280)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x, y, vel);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep((vel-200)<0 ? -(vel-200) : (vel-200));
    }
}

void Trem::setVel(int value){
    vel = value;
}




