//{===========================================================================
//!@brief	 Cartoon "Walk with girlfriends"
//!				the first programm on C++        
//!@author	       Tatiana Pugovkina, 
//!				  sity Omsk, Liceum 64
//!@date				  2021
//}===========================================================================

#include <TXLib.h>
#include "Pugovkina.h"

void Morning ();

int main()
	{
	txCreateWindow (1100, 800);
	
	txBegin ();
	
	Titles (RGB (89, 184, 33), TX_WHITE, "����������", "�������� c ����������");
	
	Morning ();
	
	Titles (RGB (89, 184, 33), TX_WHITE, "����� ��������", "��������� �������");
	
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
			
	txSleep (1000);
    }
  


