#include<TXLib.h>
#include "Pugovkina_Lib.h"
#include "ElviraLib.h"

void kachely ();

int main ()
    {
    txCreateWindow (1100, 800);

	txBegin ();

	kachely ();

	txEnd ();

	return 0;
	}

 void kachely ()
    {
    int t = 0;
    while (t <= 10)
        {
        Fon_Rectangle (RGB (151, 255, 255), TX_LIGHTGREEN);

        for (int kolichestvo = 0; kolichestvo <= 7; kolichestvo ++)
            CloudDraw (200 + rand() % 1000, 230 - rand() % 450, 1, 1, RGB (160, 217, 250));

        SolnceDraw (150, 100, 1, 1, -2.5, 1, 1, TX_YELLOW);

        KacheliDraw (400, 420, 1, 1, 2 - t%2 - 1, TX_DARKGRAY);

        DrawChick (630 - 10*t, 380, 1, 1, 20 * (t%2 * 2 - 1), 20 * (t%2 * 2 - 1), 6-t);

        txSleep(1000);

        t++;
        }
    }
