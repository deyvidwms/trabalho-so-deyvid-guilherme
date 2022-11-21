#include "trem.h"
#include "mainwindow.h"
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
        if(vel != 0)
            switch(ID){
            case 1:     //Trem 1
                if (x == 290 && y==40)
                    emit ocupaTrilho(this->ID, 0);
                else if(x==290 && y == 160){
                    x-=10;
                    emit desocupaTrilho(0);
                }
                else if (x == 310 && y == 140)
                    emit ocupaTrilho(this->ID, 2);
                else if (x == 150 && y == 160){
                    x-=10;
                    emit desocupaTrilho(2);
                }
                else if (y == 40 && x <310)
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
                if (x == 330 && y==160){
                    emit ocupaTrilho(this->ID, 0);
                }
                else if(x==310 && y == 40){
                    x+=10;
                    emit desocupaTrilho(0);
                }
                else if (x == 560 && y==40){
                    emit ocupaTrilho(this->ID, 1);
                }
                else if(x==560 && y == 160){
                    x-=10;
                    emit desocupaTrilho(1);
                }
                else if (x == 460 && y==160){
                    emit ocupaTrilho(this->ID, 3);
                }
                else if(x==310 && y == 140){
                    y-=10;
                    emit desocupaTrilho(3);
                }
                else if (x == 580 && y==140){
                    emit ocupaTrilho(this->ID, 4);
                }
                else if(x==420 && y == 160){
                    x-=10;
                    emit desocupaTrilho(4);
                }
                else if (y == 40 && x <580)
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
                if (x == 730 && y==160){
                    emit ocupaTrilho(this->ID, 5);
                }
                else if(x==580 && y == 140){
                    y-=10;
                    emit desocupaTrilho(5);
                }
                else if (x == 600 && y==160){
                    emit ocupaTrilho(this->ID, 1);
                }
                else if(x == 600 && y == 40){
                    x+=10;
                    emit desocupaTrilho(1);
                }
                else if (y == 40 && x <850)
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
                if (x == 170 && y==180){
                    emit ocupaTrilho(this->ID, 2);
                }
                else if(x==330 && y == 160){
                    x+=10;
                    emit desocupaTrilho(2);
                }
                else if (x == 290 && y==160){
                    emit ocupaTrilho(this->ID, 3);
                }
                else if(x == 440 && y == 180){
                    y+=10;
                    emit desocupaTrilho(3);
                }
                else if (x == 420 && y==160){
                    emit ocupaTrilho(this->ID, 6);
                }
                else if(x == 420 && y == 280){
                    x-=10;
                    emit desocupaTrilho(6);
                }
                else if (y == 160 && x <440)
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
                if (x == 440 && y== 180){
                    emit ocupaTrilho(this->ID, 4);
                }
                else if(x == 600 && y == 160){
                    x+=10;
                    emit desocupaTrilho(4);
                }
                else if (x == 560 && y==160){
                    emit ocupaTrilho(this->ID, 5);
                }
                else if(x == 710 && y == 180){
                    y+=10;
                    emit desocupaTrilho(5);
                }
                else if (x == 460 && y==280){
                    emit ocupaTrilho(this->ID, 6);
                }
                else if(x == 460 && y == 160){
                    x+=10;
                    emit desocupaTrilho(6);
                }
                else if (y == 160 && x <710)
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

int Trem::getX(){
    return this->x;
};

void Trem::setX(int x){
    this->x = x;
};

int Trem::getY(){
    return this->y;
};

void Trem::setY(int y){
    this->y = y;
};
