#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50
#define ESC_KEY     0x1B
using namespace std;
int main(){
    system ("title SNAKE by AnTi");
    system ("color 0a");
    char mreja[20][79],key;
    string strink="";
    long long fog=1,x=4,y=0,daljina= 6,zmq[2][1000],temp1=0,temp2=0,quit = 1,timer=0;
    srand(time(NULL));
    long long pregrada[200][2],broi_pregraadi =0;
    long long apple[3][2],speed=150,score=0,level=1,izqdeni=0,n=0,frames=0,tim=time(NULL),fps=0;
    for (long long a=0;a<7;a++){
        zmq[0][a]=0;
        zmq[1][a]=4-a;
    }
    for(int g=0;g<3;g++){
    apple[g][0] = rand() % 20;
    apple[g][1] = rand() % 79;
    }
    pregrada[0][0] = rand() % 20;
    pregrada[0][1] = rand() % 79;
    while (quit){
        timer ++;
        ///fps ===========================
        if ( tim == time(NULL)){frames ++;}
        else {fps = frames;frames = 1;tim = time (NULL);}
        ///Poverka natisnat buton ===========================
        if (level > 0){Sleep (speed);} // <------------- SPEED
        if (kbhit())
            {
            key = getch();
            gio:
            if (key == ARROW_LEFT && fog != 3 && fog != 0){fog = 0;}
            if (key == ARROW_DOWN && fog != 2 && fog != 1){fog = 1;}
            if (key == ARROW_UP && fog != 1 && fog !=2){fog = 2;}
            if (key == ARROW_RIGHT && fog != 0 && fog != 3){fog = 3;}
            if (key == ESC_KEY){system("pause");}
            if (key == '+'){level ++;}
            if (key == '-'){level --;}
            if (key == '/'){daljina --;}
            if (key == '*'){daljina ++;}

            }
        ///Smqna na posoka ==========================
        if (fog == 0){y--;}
        if (fog == 1){x++;}
        if (fog == 2){x--;}
        if (fog == 3){y++;}
        ///proverka za crash =======================
        if(level >= 3){
            if(x==-1 ||x==20 ||y==-1 ||y==79){quit = 0;break;}
        }
        else{
            if (x==20){x=0;}
            if (x==-1){x=20;}
            if (y==79){y=0;}
            if (y==-1){y=79;}
        }
        for (long long a = 0; a<daljina;a++){
        if (zmq[0][a] == y && zmq[1][a] == x) {quit =0;break;}
        }
        for(long long a=0;a<=broi_pregraadi;a++){
            if (x==pregrada[a][0] && y == pregrada[a][1]){quit =0;break;}
        }
        ///Level up! ====================================
        if (izqdeni == 5) {level++;izqdeni = 0;}
        if (level >3){score +=10;}
        ///apple pie!!!!!!! =======================================
    for(int g=0;g<3;g++){
        if(x==apple[g][0] && y == apple [g][1]){
            daljina +=1;

            izqdeni ++;
            Beep (880,100);
            if (level ==1){score +=10;}
            if (level ==2){score +=100;}
            if (level >2){score +=1000;}
                broi_pregraadi++;
                pregrada[broi_pregraadi][0] = rand() % 20;
                pregrada[broi_pregraadi][1] = rand() % 79;

            if(speed>20){speed -=10;}
            for(int g=0;g<3;g++){
            apple[g][0] = rand() % 20;
            apple[g][1] = rand() % 79;}
            }
    }
        ///Sledvane na chastite na zmqta ============================
        for(long long a=daljina;a > 0;a--){
        zmq[0][a]=zmq[0][a-1];
        zmq[1][a]=zmq[1][a-1];
        }
        zmq[0][0] = y;
        zmq[1][0] = x;
        ///Naslagvane =========================================
        strink = "";
        for(long long a=0;a < daljina;a++){
        }
        for (int a=0;a<20;a++){
        for (int i=0;i<79;i++){
            n=0;
            for(int g=0;g<3;g++){
            if (a==apple[g][0] && i == apple[g][1]/* && timer%2 ==0*/){strink += "@";n=1;}
            }
            for(long long f=0;f<=broi_pregraadi;f++){
            if (a==pregrada[f][0] && i == pregrada[f][1]){strink += char(178);n=1;}
            }
            for(long long f=1;f < daljina;f++){
                if (a==zmq[1][f] && i == zmq[0][f]){
                    if (f != daljina-1 && n==0){ /// angles
                        if(zmq[1][f]== zmq [1][f+1] && zmq[1][f]== zmq [1][f-1])
                        {strink += char (205);n=1;}
                        else if(zmq[0][f]== zmq [0][f+1] && zmq[0][f]== zmq [0][f-1])
                        {strink += char(186);n=1;}
                        else if(
                        zmq[1][f]== zmq [1][f+1] &&
                        zmq[0][f] > zmq [0][f+1] &&
                        zmq [0][f] == zmq[0][f-1] &&
                        zmq[1][f] > zmq[1][f-1] ||
                        zmq[1][f]== zmq [1][f-1] &&
                        zmq[0][f] > zmq [0][f-1] &&
                        zmq [0][f] == zmq[0][f+1] &&
                        zmq[1][f] > zmq[1][f+1]){strink +=char(188);n=1;}
                        else if (
                        zmq[0][f]==zmq[0][f+1]&&
                        zmq[1][f] > zmq[1][f+1] &&
                        zmq[1][f] == zmq[1][f-1] &&
                        zmq[0][f] < zmq [0][f-1] ||
                        zmq[0][f]==zmq[0][f-1]&&
                        zmq[1][f] > zmq[1][f-1] &&
                        zmq[1][f] == zmq[1][f+1] &&
                        zmq[0][f] < zmq [0][f+1]){strink +=char(200);n=1;}
                        else if (
                        zmq[1][f]==zmq[1][f+1]&&
                        zmq[0][f] < zmq[0][f+1]&&
                        zmq[0][f] == zmq[0][f-1]&&
                        zmq[1][f] < zmq[1][f-1] ||
                        zmq[1][f]==zmq[1][f-1]&&
                        zmq[0][f] < zmq[0][f-1]&&
                        zmq[0][f] == zmq[0][f+1]&&
                        zmq[1][f] < zmq[1][f+1]){strink +=char(201);n=1;}
                        else {strink +=char(187);n=1;}
                    }
                    if (f == daljina-1){
                    strink +="!";n=1;
                    }
                }
            }
            if (a == x&& i == y){
                if (fog == 0){strink += char(17);}
                if (fog == 1){strink += char(31);}
                if (fog == 2){strink += char(30);}
                if (fog == 3){strink += char(16);}
                n=1;
                }
            if (n==0){strink+=" ";}
        }
        strink +="\n";
        }
        ///razpechatvane ====================================================
        system("cls");
        cout << strink;
        cout <<"level: " <<level << " "<<endl;
        cout <<"score: " <<score<<endl;
        cout <<"fps: " <<fps;

    }
    cout << endl;
    system ("pause");
    return 0;
    }
