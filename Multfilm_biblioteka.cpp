//{===========================================================================
//!@brief	 Cartoon "Walk with girlfriends"
//!				the first programm on C++        
//!@author	       Tatiana Pugovkina, 
//!				  sity Omsk, Liceum 64
//!@date				  2021
//}===========================================================================

#include <TXLib.h>
#include "Pugovkina.h"

void Fon_osnova ();

int main()
	{
	Fon_osnova ();
	
	return 0;	
	}

void Fon_osnova ()
	{
	Fon_Rectangle (RGB (151, 255, 255), TX_LIGHTGREEN);
	
	for (int kolichestvo = 0; kolichestvo <= 50; kolichestvo ++)
		Flowers (rand() % 1100, 260 + rand() % 800, 
				RGB ( 60 + rand() % 80, 190 + rand() % 30, 200 + rand() %  40), 
				RGB (210 + rand() % 11, 210 + rand() % 11,   0 + rand() % 166));
	}

