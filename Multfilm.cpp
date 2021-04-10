#include<TXLib.h>

void BeginTitles();
void EndTitles();

int main ()
	{
	txCreateWindow (1100, 800);
	
	txBegin ();
	
	BeginTitles ();
	EndTitles ();
	
	txEnd ();
	
	return 0;
	}

void BeginTitles()
	{
	int t = 0;
	while (t <= 55)
		{
		txClear();
		
		txSetFillColor (RGB (0, 64, 128));
		
		txSelectFont ("Arial", 100);
		txTextOut (350, 700-t*10, "Мульфильм");
		txTextOut (200, 800-t*10, "Прогулка с друзьями");
		
		txSleep(100);
		
		t++;	
		}	
	}
	
void EndTitles()
	{
	int t = 0;
	while (t <= 45)
		{
		txClear();
		
		txSetFillColor (RGB (0, 64, 128));
		
		txSelectFont ("Arial", 100);
		txTextOut (290, 700-t*10, "Автор сценария");
		txTextOut (240, 800-t*10, "Пуговкина Татьяна");
		
		txSleep(90);
		
		t++;	
		}	
	}
