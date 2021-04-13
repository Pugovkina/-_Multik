#include<TXLib.h>

void BeginTitles      ();
void Sun_Day          ();
void Morning          ();
void FonDraw          ();
void SolnceDraw_speak ();

void SolnceDraw       (int x, int y, double sizeX, double sizeY, double eyes, 
				       double lenghLuch, double smile, COLORREF sunColor); 
				      
void TychkaDraw       (int x, int y, double sizeX, double sizeY, 
				       COLORREF tychaColor);
				      
void DomDraw_morning  (int x, int y, double sizeX, double sizeY, 
                       double opendverX, double opendverY,
			           COLORREF domColor, COLORREF krischaColor, 
			           COLORREF oknoColor, COLORREF trubaColor, 
			           COLORREF dverColor);
			          
void DomDraw          (int x, int y, double sizeX, double sizeY, 
                       double opendverX, double opendverY,
			           COLORREF domColor, COLORREF krischaColor, 
			           COLORREF oknoColor, COLORREF trubaColor, 
			           COLORREF dverColor);
			          
void GerlDraw         (int x, int y, double sizeX, double sizeY, double smile, 
		               double handR, double handL, COLORREF bantikColor,
			           COLORREF platieColor, COLORREF glazaColor);
			          
void KacheliDraw      (int x, int y, double sizeX, double sizeY, 
				       double height_kacheli, COLORREF kacheliColor);
				      
void ElkaDraw         (int x, int y, double sizeX, double sizeY, 
			           double veterX, double veterY,
			           COLORREF hvoiaColor, COLORREF stvolColor);
			          
void DerevoDraw       (int x, int y, double sizeX, double sizeY,
				       double veterX, double veterY,
                       COLORREF stvolColor, COLORREF appleColor);
                      
void Rain             (int x, int y, double lenght_Rain);

void DerevoDraw_Rain  (int x, int y, double sizeX, double sizeY,
				       double veterX, double veterY,
                       COLORREF stvolColor, COLORREF appleColor);
                      
void EndTitles        ();

int main ()
	{
	txCreateWindow (1100, 800);
	
	txBegin ();
	
	BeginTitles ();
	
	Morning ();
	
	SolnceDraw_speak ();
	
//	Sun_Day ();
	
	EndTitles ();
	
	txEnd ();
	
	return 0;
	}

void BeginTitles ()
	{
	int t = 0;
	while (t <= 35)
		{
		txClear ();
		
		txSetFillColor (RGB (0, 64, 128));
		
		txSelectFont ("Arial", 100);
		txTextOut (350, 700-t*10, "Мульфильм");
		txTextOut (200, 800-t*10, "Прогулка с друзьями");
		
		txSleep(100);
		
		t++;	
		}	
	}
	
void Morning ()
	{
	int t = 0;
	while (t <= 10)
		{
	    txSetColor     (RGB (151, 255, 255));
		txSetFillColor (RGB (151, 255, 255));
		txRectangle (0, 0, 1100, 250);
 	
    	txSetColor     (TX_LIGHTGREEN);
	    txSetFillColor (TX_LIGHTGREEN);
	    txRectangle (0, 250, 1100, 800);
	
	    int x = 60;
	    while (x <= 650)
		    {
	     	DomDraw_morning (x, 580, 1.5, 1.5, 1 - x%5, 1 - x%5, TX_BROWN, TX_BLUE, RGB (134, 134, 134), TX_DARKGRAY, TX_CYAN);
			
		    TychkaDraw (x + 340, 100, 1.5 - x%5, 2 - x%5, RGB (121, 206, 227));
		
		    ElkaDraw (x     -  10, 690,       1,         1,   0, 0, TX_GREEN,          TX_BROWN);
		    ElkaDraw (x/1.5 + 690, 670 - x/8, 0.9 + x%2, 1.3, 0, 0, RGB (75, 121, 43), RGB (191, 96, 0));
		    ElkaDraw (x/1.5 +  80, 300 - x/4, 1.2 + x%2, 1.3, 0, 0, RGB (55,  88, 31), RGB (130, 65, 0));		    
			ElkaDraw (x/1.5 + 450, 200 + x/4, 1   + x%2, 1,   0, 0, RGB (55,  88, 31), RGB (130, 65, 0));
			
			DerevoDraw (x/1.5 + 740, 450 - x/4, 1, 1, 0, 0, TX_BROWN, TX_RED);
			DerevoDraw (x/1.5 + 830, 530 - x/4, 1, 1, 0, 0, TX_BROWN, RGB (242, 162, 102));
			
			x += 215;
			}
		
	    SolnceDraw (150, 100, 2, 2, -6, 1, 0.1, TX_YELLOW);
			
	    KacheliDraw (400, 420, 1, 1, 1, TX_DARKGRAY);
	
	    txSleep(150);
		
		t++;	
		}
	}

void SolnceDraw (int x, int y, double sizeX, double sizeY, double eyes, 
				 double lenghLuch, double smile, COLORREF sunColor)
	{
	txSetColor     (sunColor, 3);
	txSetFillColor (sunColor);
	
	txEllipse (x - 27*sizeX, y - 27*sizeY, x + 27*sizeX, y + 27*sizeY);
	
	txLine (x + 28*sizeX, y,            x + 55*sizeX*lenghLuch,     y);
	txLine (x - 28*sizeX, y,            x - 60*sizeX*lenghLuch/1.5, y);
	txLine (x,            y + 28*sizeY, x,                          y + 60*sizeY*lenghLuch);
	txLine (x,            y - 28*sizeY, x,                          y - 80*sizeY*lenghLuch);
	txLine (x + 20*sizeX, y + 20*sizeY, x + 50*sizeX*lenghLuch,     y + 50*sizeY*lenghLuch);
	txLine (x + 20*sizeX, y - 20*sizeY, x + 50*sizeX*lenghLuch,     y - 40*sizeY*lenghLuch);
	txLine (x - 20*sizeX, y + 20*sizeY, x - 50*sizeX*lenghLuch,     y + 50*sizeY*lenghLuch);
	txLine (x - 20*sizeX, y - 20*sizeY, x - 40*sizeX*lenghLuch,     y - 40*sizeY*lenghLuch);
	
	txSetFillColor (RGB (119, 187, 255));
	txEllipse (x - 15*sizeX, y - 5*sizeY + eyes, x -  5*sizeX, y - 15*sizeY - eyes);
	txEllipse (x +  5*sizeX, y - 5*sizeY + eyes, x + 15*sizeX, y - 15*sizeY - eyes);
	    
	txSetFillColor (TX_BROWN);
	POINT Nos[] = {{x - 8*sizeX, y - 1*sizeY}, 
	               {x + 8*sizeX, y - 1*sizeY}, 
				   {x + 1*sizeX, y + 8*sizeY}};
	txPolygon (Nos, 3);
	
	txSetFillColor (TX_RED);
	txEllipse (x - 12*sizeX - smile, y + 13*sizeY + smile, x + 12*sizeX - smile, y + 18*sizeY - smile);
	}

void SolnceDraw_speak ()
	{
    int t = 1;
	while (t <= 10)
		{
		SolnceDraw (150, 100, 2, 2, 0.1 - t%4, 1.5, t%2 - 1.5, TX_YELLOW);	
		
		txSetColor   (TX_ORANGE);
	    txSelectFont ("Arial", 40);
	    txTextOut (185, 120, "С Добрым утром");
		
		txSleep(200);
		
		t++;
	    }
	    
	int x = 60;
	while (x < 650)
	    {
	     DomDraw (x, 580, 1.5, 1.5, 1, 1, TX_BROWN, TX_BLUE, RGB (rand()%243, rand()%243, rand()%101), 
		 	 	  TX_DARKGRAY, TX_CYAN);
	     	
		 GerlDraw (x + 100, 705, 0.7, 0.7, -0.5, -(x/10) % 2 * 2 - 1, (x/10) % 2 * 2 - 1, 
		           TX_YELLOW, RGB (rand()%207, rand()%159, rand()%255), TX_GREEN);
		              
		 x += 215;
		}
	}

void TychkaDraw (int x, int y, double sizeX, double sizeY, 
				 COLORREF tychaColor)
	{
	txSetColor     (tychaColor);
	txSetFillColor (tychaColor);
	txEllipse (x - 60*sizeX, y - 20*sizeY, x - 20*sizeX, y + 20*sizeY);
	txEllipse (x - 30*sizeX, y - 30*sizeY, x + 30*sizeX, y + 30*sizeY);
	txEllipse (x + 20*sizeX, y - 20*sizeY, x + 65*sizeX, y + 30*sizeY);
	}
	
void Sun_Day ()
	{
	int t = 0;
	while (t <= 10)
		{
	    txSetColor     (RGB (151, 255, 255));
		txSetFillColor (RGB (151, 255, 255));
		txRectangle (0, 0, 1100, 250);
 	
    	txSetColor     (TX_LIGHTGREEN);
	    txSetFillColor (TX_LIGHTGREEN);
	    txRectangle (0, 250, 1100, 800);
	
	    int x = 60;
	    while (x <= 650)
		    {
	     	DomDraw (x, 580, 1.5, 1.5, 1, 1, TX_BROWN, TX_BLUE, RGB (rand()%243, rand()%243, rand()%101), 
		 	 	  TX_DARKGRAY, TX_CYAN);
			
		    TychkaDraw (x + 340, 100, 1.5 - x%5, 2 - x%5, RGB (121, 206, 227));
		
		    ElkaDraw (x     -  10, 690,       1,         1,   0, 0, TX_GREEN,          TX_BROWN);
		    ElkaDraw (x/1.5 + 690, 670 - x/8, 0.9 + x%2, 1.3, 0, 0, RGB (75, 121, 43), RGB (191, 96, 0));
		    ElkaDraw (x/1.5 +  80, 300 - x/4, 1.2 + x%2, 1.3, 0, 0, RGB (55,  88, 31), RGB (130, 65, 0));		    
			ElkaDraw (x/1.5 + 450, 200 + x/4, 1   + x%2, 1,   0, 0, RGB (55,  88, 31), RGB (130, 65, 0));
			
			DerevoDraw (x/1.5 + 740, 450 - x/4, 1, 1, 0, 0, TX_BROWN, TX_RED);
			DerevoDraw (x/1.5 + 830, 530 - x/4, 1, 1, 0, 0, TX_BROWN, RGB (242, 162, 102));
			
			x += 215;
			}	
		
/*	txClear();
	int t = 0;
	while (t <= 10)
		{
		txClear();
		
		FonDraw ();
	/*	int x = 100;
		while (x <= 550)
			{
			
		
			TychkaDraw (x + 100, 100, 1.3, 0.8, RGB (  0,  94, 187));
		
			SolnceDraw (x,       100, 2,   2,   (x/10) % 2,   TX_YELLOW);
		
			TychkaDraw (x + 520,  40, 1,   1,   RGB (136, 196, 255));
			TychkaDraw (x + 300, 160, 0.8, 1.5, RGB ( 13, 134, 255));
			TychkaDraw (x -  50,  40, 1,   1,   RGB (136, 196, 255));
			TychkaDraw (x - 100, 160, 1.8, 1.5, RGB ( 13, 134, 255));
			TychkaDraw (x - 550,  80, 1,   1,   RGB (136, 196, 234));
			TychkaDraw (x - 400, 185, 1.8, 1.5, RGB ( 13, 184, 255));
		
			KacheliDraw (250, 390, 1.2, 1.2, (x/10) % 2 * 2 - 1, TX_DARKGRAY);
			
			/*GerlDraw (x + 110, 700, 1, 1, -0.5, -(x/10) % 2 * 2 - 1, (x/10) % 2 * 2 - 1, 
			          TX_YELLOW, TX_BLUE, TX_GREEN);
			GerlDraw (x + 110, 320, 0.6, 0.6, -0.5, (x/10) % 2 * 2 - 1, (x/10) % 2 * 2 - 1, 
		        	  TX_YELLOW, TX_BLUE, TX_GREEN);
		          
			txSleep (50);
			
			x++;
			}**/
				
    	txSleep (50);
		
		t++;
		}
	}


void FonDraw ()
	{
	txSetColor     (RGB (151, 255, 255));
	txSetFillColor (RGB (151, 255, 255));
	txRectangle (0, 0, 1100, 250);
	
	txSetColor     (TX_LIGHTGREEN);
	txSetFillColor (TX_LIGHTGREEN);
	txRectangle (0, 250, 1100, 800);
	
	int x = 60;
	while (x <= 650)
		{
		DomDraw (x, 580, 1.5,   1.5,   x%9,  x%9,  TX_BROWN,  TX_BLUE,   TX_YELLOW, TX_DARKGRAY, TX_CYAN);	
		
		x += 215;
		}
	
	ElkaDraw (  70, 690, 1,   1,   0, 0, TX_GREEN,          TX_BROWN);	
	ElkaDraw ( 750, 600, 0.9, 1.3, 0, 0, RGB (75, 121, 43), RGB (191, 96, 0));
	ElkaDraw (1020, 600, 1.7, 1.8, 0, 0, RGB (55,  88, 31), RGB (130, 65, 0));
	
	DerevoDraw (900, 550, 1,   1,   0, 0, TX_BROWN,          TX_RED);
	DerevoDraw (810, 440, 0.9, 1.3, 0, 0, RGB ( 88, 44, 44), TX_GREEN);
	DerevoDraw (880, 300, 1.3, 1.7, 5, 0, RGB (128, 64, 64), TX_ORANGE);	
	}

void DomDraw_morning (int x, int y, double sizeX, double sizeY, 
                      double opendverX, double opendverY,
			          COLORREF domColor, COLORREF krischaColor, 
			          COLORREF oknoColor, COLORREF trubaColor, 
			          COLORREF dverColor)
	{
	txSetColor (TX_BLACK, 3);
	
	txSetFillColor (domColor);
	txRectangle (x,            y,            x + 80*sizeX, y + 80*sizeY);
	txRectangle (x + 60*sizeX, y + 40*sizeY, x + 80*sizeX, y + 80*sizeY);
	
	txSetFillColor (krischaColor);
	txLine      (x + 40*sizeX, y - 40*sizeY, x - 10*sizeX, y + 10*sizeY);
	txLine      (x + 40*sizeX, y - 40*sizeY, x + 90*sizeX, y + 10*sizeY);
	txFloodFill (x + 40*sizeX, y - 10*sizeY);
	
	txSetFillColor (trubaColor);
	POINT Tryba[] = {{x + 60*sizeX, y - 20*sizeY}, 
	                 {x + 60*sizeX, y - 50*sizeY}, 
					 {x + 80*sizeX, y - 50*sizeY}, 
					 {x + 80*sizeX, y +  1*sizeY}};
	txPolygon (Tryba, 4);
	
	txSetFillColor (oknoColor);
	txRectangle (x + 20*sizeX, y + 20*sizeY, x + 50*sizeX, y + 40*sizeY);
	
	txSetFillColor (dverColor);
	POINT Dver[] = {{x + 60*sizeX,             y + 40*sizeY}, 
	                {x + 60*sizeX,             y + 80*sizeY}, 
					{x + 80*sizeX - opendverX, y + 80*sizeY + opendverY}, 
					{x + 80*sizeX - opendverX, y + 40*sizeY + opendverY}};
	txPolygon (Dver, 4);

	txSetFillColor (TX_BLACK);
	txEllipse (x + 70*sizeX - opendverX/2, y + 55*sizeY + opendverY/2, 
			   x + 75*sizeX - opendverX/2, y + 65*sizeY + opendverY/2);
	}

void DomDraw (int x, int y, double sizeX, double sizeY, 
              double opendverX, double opendverY,
			  COLORREF domColor, COLORREF krischaColor, 
			  COLORREF oknoColor, COLORREF trubaColor, 
			  COLORREF dverColor)
	{
	txSetColor (TX_BLACK, 3);
	
	txSetFillColor (domColor);
	txRectangle (x,            y,            x + 80*sizeX, y + 80*sizeY);
	txRectangle (x + 60*sizeX, y + 40*sizeY, x + 80*sizeX, y + 80*sizeY);
	
	txSetFillColor (krischaColor);
	txLine      (x + 40*sizeX, y - 40*sizeY, x - 10*sizeX, y + 10*sizeY);
	txLine      (x + 40*sizeX, y - 40*sizeY, x + 90*sizeX, y + 10*sizeY);
	txFloodFill (x + 40*sizeX, y - 10*sizeY);
	
	txSetFillColor (trubaColor);
	POINT Tryba[] = {{x + 60*sizeX, y - 20*sizeY}, 
	                 {x + 60*sizeX, y - 50*sizeY}, 
					 {x + 80*sizeX, y - 50*sizeY}, 
					 {x + 80*sizeX, y +  1*sizeY}};
	txPolygon (Tryba, 4);
	
	txSetFillColor (oknoColor);
	txRectangle (x + 20*sizeX, y + 20*sizeY, x + 50*sizeX, y + 40*sizeY);
	
	int t = 0;
	while (t <=10)
	    {
    	txSetColor (RGB (221, 221, 221), 15);
	    txArc (x + 70*sizeX * (t%2), y - 70*sizeY * (t%2), x +  90*sizeX * (t%2), y - 60*sizeY * (t%2),  30 + (10 + t%2), 180);
	    txArc (x + 80*sizeX * (t%2), y - 80*sizeY * (t%2), x + 110*sizeX * (t%2), y - 70*sizeY * (t%2), 180 + (10 - t%2), 180);

        txSetColor (TX_BLACK);
        txSetFillColor (dverColor);

	    POINT Dver[] = {{x + 60*sizeX,                         y + 40*sizeY}, 
	                    {x + 60*sizeX,                         y + 80*sizeY}, 
				     	{x + 80*sizeX - opendverX * (t%2 - 1), y + 80*sizeY + opendverY * (t%3 + 6)}, 
				    	{x + 80*sizeX - opendverX * (t%2 - 1), y + 40*sizeY + opendverY * (t%3 + 6)}};
    	txPolygon (Dver, 4);

        txSetFillColor (TX_BLACK);
	    txEllipse (x + 70*sizeX - opendverX/2 * (t%2), y + 55*sizeY + opendverY/2 * (t%2), 
		           x + 75*sizeX - opendverX/2 * (t%2), y + 65*sizeY + opendverY/2 * (t%2));

        txSleep(150);
        
		t++;
        }
	}
	
void GerlDraw (int x, int y, double sizeX, double sizeY, double smile, 
		       double handR, double handL, COLORREF bantikColor,
			   COLORREF platieColor, COLORREF glazaColor)
	{
	txSetColor (TX_BLACK, 2);
	
	txSetFillColor (RGB (208, 208, 208));
	txEllipse (x - 25*sizeX, y - 50*sizeY, x + 25*sizeX, y - 1*sizeY);
	
	txSetFillColor (glazaColor);
	txEllipse (x - 15*sizeX, y - 40*sizeY, x -  5*sizeX, y - 25*sizeY);
	txEllipse (x +  5*sizeX, y - 40*sizeY, x + 15*sizeX, y - 25*sizeY);
	
	POINT nos[] = {{x,           y - 25*sizeY},
				   {x + 5*sizeX, y - 20*sizeY},
				   {x - 5*sizeX, y - 20*sizeY}};
	txPolygon (nos, 3);
	
	txSetColor (TX_RED, 3);
	txLine (x - 10*sizeX, y - (15 + 3.0*smile)*sizeY, x,            y - 12*sizeY);
	txLine (x,            y - 12*sizeY,           x + 10*sizeX, y - (15 + 3.0*smile)*sizeY);
	
	txSetFillColor (bantikColor);
    POINT bantik[] = {{x - 20*sizeX, y - 42*sizeY}, 
	                  {x - 12*sizeX, y - 70*sizeY}, 
					  {x +  2*sizeX, y - 45*sizeY}, 
					  {x - 20*sizeX, y - 42*sizeY}, 
					  {x - 40*sizeX, y - 47*sizeY}, 
					  {x - 28*sizeX, y - 20*sizeY}};
	txPolygon (bantik, 6);
	
	txSetColor (TX_BLACK, 3);
	txLine (x - 40*sizeX, y + (20 + 9*handR)*sizeY, x - 10*sizeX, y + 15*sizeY);
	txLine (x + 10*sizeX, y + 15*sizeY,             x + 40*sizeX, y + (20 - 9*handL)*sizeY);
	txLine (x - 15*sizeX, y + 55*sizeY,             x - 15*sizeX, y + 85*sizeY);
	txLine (x - 15*sizeX, y + 85*sizeY,             x - 20*sizeX, y + 85*sizeY);
	txLine (x + 15*sizeX, y + 55*sizeY,             x + 15*sizeX, y + 85*sizeY);
	txLine (x + 15*sizeX, y + 85*sizeY,             x + 20*sizeX, y + 85*sizeY);
	
	txSetColor (platieColor, 3);
	txSetFillColor (platieColor);
	txLine (x,            y,            x + 40*sizeX, y + 55*sizeY);
	txLine (x + 40*sizeX, y + 55*sizeY, x - 40*sizeX, y + 55*sizeY);
	txLine (x - 40*sizeX, y + 55*sizeY, x,            y);
	txFloodFill (x, y + 35*sizeY);	
	}

void KacheliDraw (int x, int y, double sizeX, double sizeY, 
				  double height_kacheli, COLORREF kacheliColor)
	{
	txSetColor (kacheliColor, 3);
	txSetFillColor (kacheliColor);
	
	txLine (x + 40*sizeX, y + 20*sizeY, x - 40*sizeX, y + 20*sizeY);
	txLine (x,            y,            x + 40*sizeX, y + 20*sizeY);
	txLine (x - 40*sizeX, y + 20*sizeY, x,            y);
	
	txFloodFill (x, y + 10*sizeY);
	
	if (height_kacheli == 1)
		{
	    txLine (x - 100*sizeX, y + 20*sizeY, x + 100*sizeX, y - 20*sizeY);
	    txLine (x + 100*sizeX, y - 20*sizeY, x +  95*sizeX, y - 35*sizeY);
	    txLine (x - 100*sizeX, y + 20*sizeY, x - 107*sizeX, y);
	    }
	else
	    {
		txLine (x - 100*sizeX, y - 20*sizeY, x + 100*sizeX, y+20);
	    txLine (x + 100*sizeX, y + 17*sizeY, x + 105*sizeX, y);
	    txLine (x - 100*sizeX, y - 20*sizeY, x - 95*sizeX, y-43);	
	    }	
	}
	
void ElkaDraw (int x, int y, double sizeX, double sizeY, 
			   double veterX, double veterY,
			   COLORREF hvoiaColor, COLORREF stvolColor)
	{
	txSetColor (hvoiaColor, 3);
	txSetFillColor (hvoiaColor);
	POINT elka_verh[] = {{x + veterX,   y - veterY},
					     {x + 20*sizeX, y + 40*sizeY}, 
					     {x - 20*sizeX, y + 40*sizeY}};
	txPolygon (elka_verh, 3);
	POINT elka_niz[] = {{x,            y + 30*sizeY}, 
					    {x + 40*sizeX, y + 70*sizeY}, 
					    {x - 40*sizeX, y + 70*sizeY}};
	txPolygon (elka_niz, 3);
	
	txSetColor (stvolColor, 3);
	txSetFillColor (stvolColor);
	txRectangle (x - 10*sizeX, y + 73*sizeY, x + 10*sizeX, y + 95*sizeY);	
	}
	
void DerevoDraw (int x, int y, double sizeX, double sizeY,
				 double veterX, double veterY,
                 COLORREF stvolColor, COLORREF appleColor)
	{
	txSetColor (stvolColor, 3);
	txSetFillColor (stvolColor);
	POINT derevo[] = {{x + veterX,  y + veterY}, 
	                  {x + 8*sizeX, y + 100*sizeY}, 
	                  {x - 8*sizeX, y + 100*sizeY}};		
	txPolygon (derevo, 3);
	
	txLine (x +  5*sizeX, y + 30*sizeY, x + 40*sizeX, y - 15*sizeY);
	txLine (x + 20*sizeX, y + 10*sizeY, x + 24*sizeX, y - 16*sizeY);
	txLine (x + 10*sizeX, y + 25*sizeY, x + 30*sizeX, y + 20*sizeY);
	txLine (x - 30*sizeX, y + 10*sizeY, x -  5*sizeX, y + 60*sizeY);
	txLine (x - 15*sizeX, y + 17*sizeY, x - 20*sizeX, y + 31*sizeY);
	txLine (x - 35*sizeX, y + 30*sizeY, x - 19*sizeX, y + 35*sizeY);
	txLine (x - 30*sizeX, y + 32*sizeY, x - 30*sizeX, y + 37*sizeY);
	txLine (x + 20*sizeX, y + 22*sizeY, x + 20*sizeX, y + 27*sizeY);
	txLine (x + 39*sizeX, y - 15*sizeY, x + 39*sizeX, y +  2*sizeY);
	
	txSetColor (appleColor, 3);
	txSetFillColor (appleColor);
	txEllipse (x - 21*sizeX + 0.9*veterX, y + 37*sizeY, x - 40*sizeX, y + 58*sizeY - 0.8*veterY);
	txEllipse (x + 14*sizeX,              y + 28*sizeY, x + 32*sizeX, y + 45*sizeY);
	txEllipse (x + 34*sizeX,              y +  4*sizeY, x + 50*sizeX, y + 18*sizeY);
	}

void Rain (int x, int y, double lenght_Rain)
	{
	txSetColor (RGB (145, 145, 145), 3);
	
	for (int Kolichestvo_Rain = 1; Kolichestvo_Rain <= 8; Kolichestvo_Rain ++)
		{
		txLine (x,                    y,                     x -  15 + lenght_Rain,       y +  30 + lenght_Rain);
		txLine (x - 19 + lenght_Rain, y +  38 + lenght_Rain, x -  30 + lenght_Rain,       y +  68 - 0.5*lenght_Rain);
		txLine (x - 35 + lenght_Rain, y +  72 + lenght_Rain, x -  53 + 2.3 * lenght_Rain, y + 116 - 2.3*lenght_Rain);	
		txLine (x - 59 + lenght_Rain, y + 123 + lenght_Rain, x -  72 + 1.8 * lenght_Rain, y + 156 - 1.8*lenght_Rain);
		txLine (x - 86 + lenght_Rain, y + 170 + lenght_Rain, x - 100 + 3   * lenght_Rain, y + 200 - 3.0*lenght_Rain);
		x += 20;
		}
	}
	
void DerevoDraw_Rain (int x, int y, double sizeX, double sizeY,
				      double veterX, double veterY,
                      COLORREF stvolColor, COLORREF appleColor)
	{
	txSetColor (stvolColor, 3);
	txSetFillColor (stvolColor);
	POINT derevo[] = {{x + veterX,            y + veterY}, 
	                  {x + 8*sizeX, y + 100*sizeY}, 
	                  {x - 8*sizeX, y + 100*sizeY}};		
	txPolygon (derevo, 3);
	
	txLine (x +  5*sizeX, y + 30*sizeY, x + 40*sizeX, y - 20*sizeY);
	txLine (x + 20*sizeX, y + 10*sizeY, x + 24*sizeX, y - 16*sizeY);
	txLine (x + 10*sizeX, y + 25*sizeY, x + 30*sizeX, y + 20*sizeY);
	txLine (x - 30*sizeX, y + 10*sizeY, x -  5*sizeX, y + 60*sizeY);
	txLine (x - 15*sizeX, y + 17*sizeY, x - 20*sizeX, y + 31*sizeY);
	txLine (x - 35*sizeX, y + 30*sizeY, x - 19*sizeX, y + 35*sizeY);
	txLine (x - 30*sizeX, y + 32*sizeY, x - 30*sizeX, y + 37*sizeY);
	txLine (x + 20*sizeX, y + 22*sizeY, x + 20*sizeX, y + 27*sizeY);
	
	txSetColor (appleColor, 3);
	txSetFillColor (appleColor);
	txEllipse (x - 21*sizeX + 0.9*veterX, y + 37*sizeY, x - 40*sizeX, y + 58*sizeY - 0.8*veterY);
	txEllipse (x + 14*sizeX,              y + 28*sizeY, x + 32*sizeX, y + 45*sizeY);
	
	txSetColor (TX_LIGHTGREEN, 3);
	txSetFillColor (TX_LIGHTGREEN);
	txEllipse (918, 288, 948, 315);
	//txLine (933, 288, 933, 275);
	
	txSetFillColor (TX_ORANGE);
	txEllipse (955, 440, 1000, 465);
	}

void EndTitles()
	{
	int t = 0;
	while (t <= 45)
		{
		txClear();
		txSetColor(TX_WHITE);
		txSetFillColor (RGB (0, 64, 128));
		
		txSelectFont ("Arial", 100);
		txTextOut (290, 700-t*10, "Автор сценария");
		txTextOut (240, 800-t*10, "Пуговкина Татьяна");
		
		txSleep(90);
		
		t++;	
		}	
	}
