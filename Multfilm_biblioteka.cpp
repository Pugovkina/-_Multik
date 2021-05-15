//{===========================================================================
//!@brief	 Cartoon "Walk with girlfriends"
//!				the first programm on C++
//!@author	       Tatiana Pugovkina,
//!				  sity Omsk, Lyceum 64
//!@date				  2021
//}===========================================================================

#include <TXLib.h>
#include "Pugovkina_Lib.h"

void Morning ();
void SolnceDraw_speak ();

int main()
	{
	txCreateWindow (1100, 800);

	txBegin ();

	//Titles (RGB (89, 184, 33), TX_WHITE, "Мультфильм", "Прогулка c подружками");

	Morning ();
	SolnceDraw_speak ();

	//Titles (RGB (89, 184, 33), TX_WHITE, "Автор сценария", "Пуговкина Татьяна");

	txEnd ();

	return 0;
	}

void Morning ()
	{
	Fon_Rectangle (RGB (151, 255, 255), TX_LIGHTGREEN);

	for (int kolichestvo = 0; kolichestvo <= 50; kolichestvo ++)
		Flowers (rand() % 1100, 260 + rand() % 800,
				RGB ( 60 + rand() % 80, 190 + rand() % 30, 200 + rand() %  40),
				RGB (210 + rand() % 11, 210 + rand() % 11,   0 + rand() % 166));

	for (int kolichestvo = 0; kolichestvo <= 7; kolichestvo ++)
		CloudDraw (200 + rand() % 1000, 230 - rand() % 450, 1, 1, RGB (160, 217, 250));

	SolnceDraw (150, 100, 1, 1, -2.5, 1, 1, TX_YELLOW);

	int koordinata = 50;
	while (koordinata <= 450)
	    {
	    DomDraw (koordinata, 650 - koordinata*0.7, 2 - koordinata%2, 2 - koordinata%2, 1.5, 1.5, TX_BROWN, TX_BLUE, RGB (134, 134, 134), TX_DARKGRAY, TX_YELLOW);

	    koordinata += 200;
	    }

    for (int kolichestvo = 0; kolichestvo <= 7; kolichestvo ++)
      {
        ElkaDraw (650 + rand() % 800, 180 + rand() % 300, 1, 1, 0, 0, TX_GREEN, TX_BROWN);
        ElkaDraw (rand() % 250, 180 + rand() % 250, 1, 1, 0, 0, TX_GREEN, TX_BROWN);
      }

    KacheliDraw (750, 600, 1, 1, 0, TX_DARKGRAY);

    txSleep (1000);
    }

void SolnceDraw_speak ()
    {
    int t = 1;
    while (t <= 10)
        {
        SolnceDraw (150, 100, 1.2, 1.2, 0.2 - t%4, 0.15*t , t%4 - 2.5, TX_YELLOW);

        txSetColor   (TX_ORANGE);
        txSelectFont ("Arial", 40);
        txTextOut (185, 120, "С добрым утром");

        txSleep(200);

        t++;
        }

    int koordinata = 50;
	while (koordinata <= 450)
	    {
	    DomDraw (koordinata, 650 - koordinata*0.7, 2 - koordinata%2, 2 - koordinata%2, 1.5, 1.5, TX_BROWN, TX_BLUE, RGB (rand()%243, rand()%243, rand()%101), TX_DARKGRAY, TX_YELLOW);

        GerlDraw (koordinata + 230, 780 - koordinata*0.7, 0.7, 0.7, -0.5, 1, -(koordinata/10) % 2 * 2 - 1, (koordinata/10) % 2 * 2 - 1,
                  TX_YELLOW, RGB (rand()%207, rand()%159, rand()%255), TX_GREEN);

	    koordinata += 200;
	    }

    }

