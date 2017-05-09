/* 
Idemo delat!
*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <winbgim.h>
using namespace std;

int main() {
    char move;
    int a,b,c,d;
    int lina,linb,linc,lind;
    a = 10;
    b = 20;
    c = 30;
    d = 40;
    lina = 100;
    linb = 302;
    linc = 560;
    lind = 302;
	// ovdje ide moj slatki program ;)
	int gdriver = 9; // Ovdje odreðujemo velièinu grafièkog prozora i broj boja.
	int gmode = 2;
	initgraph(&gdriver, &gmode, "");  // Otvaranje grafièkog prozora.
	setbkcolor(WHITE);		// Odreðivanje boje pozadine.
	setcolor(BLACK);		// Odreðivanje boje crte.
	cleardevice(); // Briše stari sadržaj zaslona i stare postavke boja. Pokušajmo pokrenuti program bez ove naredbe.
	rectangle(a,b,c,d);		// Naredba za crtanje kruga.
	line(lina,linb,linc,lind);
    			// kao i system(“PAUSE”) u “normalnim” programima.
	while (true){
        switch(getch()){
            case 80:
                if(d < linb  || c < lina || a > linc ||b > linb-5){
                cleardevice();
                b+= 5;
                d+=5;
                rectangle(a,b,c,d);
                line(lina,linb,linc,lind);
            }
                else{
                    cleardevice();
                    line(lina,linb,linc,lind);
                    rectangle(a,b,c,d);
                }
                break;
            case 72:
                if( b > linb  || c < lina || a > linc ||d < linb+5){
                cleardevice();
                b-=5;
                d-=5;
                rectangle(a,b,c,d);
                line(lina,linb,linc,lind);
            }
                else{
                    cleardevice();
                    line(lina,linb,linc,lind);
                    rectangle(a,b,c,d);
            }
                break;
            case 77:
                cleardevice();
                a+=5;
                c+=5;
                rectangle(a,b,c,d);
                line(lina,linb,linc,lind);
                break;
            case 75:
                cleardevice();
                a-=5;
                c-=5;
                rectangle(a,b,c,d);
                line(lina,linb,linc,lind);
                break;           
        }
    }
	closegraph();		// Zatvaranje grafièkog prozora.
	return 0;			// Ovo znaju i ptice na grani..
}
