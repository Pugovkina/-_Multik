//{===========================================================================
//! @brief	         Function library
//!			           
//! @author	        Tatiana Pugovkina, 
//!				  sity Omsk, Liceum 64
//! @date				  2021
//!
//! @mainpage  Функции:
//!				- @ref Titles ()
//!				- @ref Flowers ()
//!				- @ref CloudDraw ()
//!				- @ref SolnceDraw ()
//!				- @ref Fon_Rectangle ()
//!
//! @note      <i>В мире нет ничего лучше и приятнее дружбы; исключить из жизни дружбу -
//!            всё равно, что лишить мир солнечного света</i> &nbsp;&nbsp; /Цицирон/
//}===========================================================================

#include "TXLib.h"

void Fon_Rectangle (COLORREF nebo_Color, COLORREF zemlia_Color);

void Flowers (int flower_centerX, int flower_centerY, COLORREF flower_center_Color, COLORREF lepestok_Color);

void Titles (COLORREF fon_Color, COLORREF text_Color, char text_first_string[], char text_second_string[]);

void SolnceDraw (int x, int y, double sizeX, double sizeY, double eyes, double lenghLuch, double smile, COLORREF sunColor);

void CloudDraw (int x, int y, double sizeX, double sizeY, COLORREF cloudColor);

void DomDraw_morning (int x, int y, double sizeX, double sizeY, double opendverX, double opendverY,
			          COLORREF domColor, COLORREF krischaColor, COLORREF oknoColor, COLORREF trubaColor, 
			          COLORREF dverColor)

//{-------------------------------------------------------------------------------------------------------------
//! Разделяет экран на две части: 1я-часть - небо и 2я-часть - "земля"
//! Разделение происходит по линии с координатами (0, 250, 1100, 250)
//!
//! @param nebo_Color    nebo_Color   - цвет неба
//! @param zemlia_Color  zemlia_Color - цвет "земли"
//!
//! @note                Цвет неба и "земли" зависит от погоды. При солнечной погоде - светлые тона,
//!						 при пасмурной - более тёмные тона
//!
//! @par				 Пример использования:
//! @code
//!						 Fon_Rectangle (RGB (151, 255, 255), TX_LIGHTGREEN);
//! @endcode
//}-------------------------------------------------------------------------------------------------------------

void Fon_Rectangle (COLORREF nebo_Color, COLORREF zemlia_Color)
	{
    txSetColor     (nebo_Color);
    txSetFillColor (nebo_Color);
    
    txRectangle (0, 0, 1100, 250);

    txSetColor     (zemlia_Color);
    txSetFillColor (zemlia_Color);
    
    txRectangle (0, 250, 1100, 800);
	}

//{-------------------------------------------------------------------------------------------------------------
//! Рисует цветок
//! Рисование цветка: 5 лепестков и серединка
//!
//! @param flower_centerX       flower_centerX      - координата X центра середины цветка
//! @param flower_centerY       flower_centerY      - координата Y центра середины цветка
//! @param flower_center_Color  flower_center_Color - цвет серединки цветка
//! @param lepestok_Color       lepestok_Color      - цвет лепестков цветка
//! 
//! @note                       Сначала рисуются лепестки, начиная с верхнего левого, затем рисуется серединка.
//!                             Цвет лепестков выбирается случайным образом в диапазоне от светло-жёлтого до тёмно-жёлтого;
//!								цвет серединки - в диапазоне от светло-голубого до тёмно-голубого
//!
//! @par			            Пример использования:
//! @code
//! 							Flowers (300, 260, RGB ( 60 + rand() % 80, 190 + rand() % 30, 200 + rand() %  40), 
//! 											   RGB (210 + rand() % 11, 210 + rand() % 11,   0 + rand() % 166));
//! @endcode
//}-------------------------------------------------------------------------------------------------------------

void Flowers (int flower_centerX, int flower_centerY, COLORREF flower_center_Color, COLORREF lepestok_Color)
	{
    txSetColor     (lepestok_Color);
    txSetFillColor (lepestok_Color);
    
    txCircle (flower_centerX + 3, flower_centerY - 5, 5);
    txCircle (flower_centerX + 5, flower_centerY + 2, 5);
    txCircle (flower_centerX,     flower_centerY + 5, 5);
    txCircle (flower_centerX - 5, flower_centerY + 2, 5);
    txCircle (flower_centerX - 3, flower_centerY - 5, 5);
    
    txSetColor     (flower_center_Color);
    txSetFillColor (flower_center_Color);
    
    txCircle (flower_centerX, flower_centerY, 3);
	}

//{-------------------------------------------------------------------------------------------------------------
//! Выводит надпись на экран.  
//! Надпись выводится снизу вверх, состоит из 2-х строчек. 
//! Текст типа Arial, размер шрифта - 100
//!
//! @param fon_Color             fon_Color            - задаёт цвет фона
//! @param text_Color            text_Color           - задаёт цвет текста
//! @param text_first_string[]   text_first_string[]  - выводит текст на первой строчке
//! @param text_second_string[]  text_second_string[] - выводит текст на второй строчке
//! 
//! @note                        Текст выводится по центру относительно координаты Х = 550.
//!                              Текст появляется снизу экрана, начиная с координаты по Y  
//!                              для первой строки: Y = 700, 
//!                              для второй строки: Y = 800
//!                              и движется вверх по координате Y, до Y = 350 (первая строчка)
//!
//! @see                         txSetTextAlign ()
//!
//! @par			             Пример использования:
//! @code
//!                              Titles (RGB (89, 184, 33), TX_WHITE, "Мультфильм", "Прогулка c подружками");							
//! @endcode
//}-------------------------------------------------------------------------------------------------------------

void Titles (COLORREF fon_Color, COLORREF text_Color, char text_first_string[], char text_second_string[])
    {
    int t = 0;
    while (t <= 35)
        {
     	txClear ();
     	txSetColor (text_Color);
        txSetFillColor (fon_Color);

        txSetTextAlign (TA_CENTER);
        
		txSelectFont ("Arial", 100);
        txTextOut (550, 700 - t*10, text_first_string);
        txTextOut (550, 800 - t*10, text_second_string);
        
        txSetTextAlign ();
        
        txSleep (90);

        t++;	
        }	
    }

//{-------------------------------------------------------------------------------------------------------------
//! Рисует солнце с лучиками
//! 
//! @param x          x         - Х-координата центра солнца
//! @param y          y         - Y-координата центра солнца
//! @param sizeX      sizeX     - изменение размера по координате Х
//! @param sizeY      sizeY     - изменение размера по координате Y
//! @param eyes       eyes      - изменение размера глаз
//! @param lenghLuch  lenghLuch - длина луча
//! @param smile      smile     - ширина улыбки 
//! @param sunColor   sunColor  - цвет солнца
//! 
//! @note                        Солнце рисуется с помощью элипса. Радиус солнца - 30 пикселей. У солнца - 8 лучиков.
//!                              Для рисования носа используется полигон.    
//!                              Для рисования рта и глаз используется элипс. 
//!                              При изменении значения аргумента smile (-3 до 1) можно сделать, чтобы солнце - "разговаривало"
//!                              При изменении значения аргумента eyes (-2.5 до 2.5) можно сделать, чтобы солнце - "мигало"
//!                              
//! @par			             Пример использования:
//! @code
//!                              SolnceDraw (150, 100, 1, 1, -2, 1, 0.1, TX_YELLOW);                             							
//! @endcode
//! см.также элипс, линия. полигон
//}-------------------------------------------------------------------------------------------------------------

void SolnceDraw (int x, int y, double sizeX, double sizeY, double eyes, double lenghLuch, double smile, COLORREF sunColor)
    {
    txSetColor     (sunColor, 3);
    txSetFillColor (sunColor);

    txEllipse (x - 30*sizeX, y - 30*sizeY, x + 30*sizeX, y + 30*sizeY);

    txLine (x + 20*sizeX, y,            x + 60*sizeX * lenghLuch, y);
    txLine (x - 20*sizeX, y,            x - 60*sizeX * lenghLuch, y);
    txLine (x,            y + 20*sizeY, x,                        y + 60*sizeY * lenghLuch);
    txLine (x,            y - 20*sizeY, x,                        y - 60*sizeY * lenghLuch);
    txLine (x + 20*sizeX, y + 20*sizeY, x + 50*sizeX * lenghLuch, y + 50*sizeY * lenghLuch);
    txLine (x + 20*sizeX, y - 20*sizeY, x + 50*sizeX * lenghLuch, y - 50*sizeY * lenghLuch);
    txLine (x - 20*sizeX, y + 20*sizeY, x - 50*sizeX * lenghLuch, y + 50*sizeY * lenghLuch);
    txLine (x - 20*sizeX, y - 20*sizeY, x - 50*sizeX * lenghLuch, y - 50*sizeY * lenghLuch);

    txSetFillColor (RGB (119, 187, 255));
    txEllipse (x - 15*sizeX, y - 5*sizeY + eyes, x -  5*sizeX, y - 15*sizeY - eyes);
    txEllipse (x +  5*sizeX, y - 5*sizeY + eyes, x + 15*sizeX, y - 15*sizeY - eyes);

    txSetFillColor (TX_BROWN);
    POINT Nos[] = {{x - 8*sizeX, y - 1*sizeY}, 
                   {x + 8*sizeX, y - 1*sizeY}, 
                   {x + 1*sizeX, y + 8*sizeY}};
    txPolygon (Nos, 3);

    txSetFillColor (TX_RED);
    txEllipse (x - 22*sizeX - smile, y + 13*sizeY + smile, x + 18*sizeX - smile + 5, y + 20*sizeY - smile);
    }

//{-------------------------------------------------------------------------------------------------------------
//! Рисует облако
//! 
//! @param x           x          - Х-координата центра облака
//! @param y           y          - Y-координата центра облака
//! @param sizeX       sizeX      - изменение размера по координате Х
//! @param sizeY       sizeY      - изменение размера по координате Y
//! @param cloudColor  cloudColor - цвет облака
//! 
//! @note                        Облако рисуется с помощью 3-х элипсов. 
//!                              
//! @par			             Пример использования:
//! @code
//!                              CloudDraw (200, 230, 1, 1.2, RGB (160, 217, 250));                             							
//! @endcode
//}-------------------------------------------------------------------------------------------------------------

void CloudDraw (int x, int y, double sizeX, double sizeY, COLORREF cloudColor)
    {
    txSetColor     (cloudColor);
    txSetFillColor (cloudColor);
        
	txEllipse (x - 60*sizeX, y - 20*sizeY, x - 20*sizeX, y + 20*sizeY);
    txEllipse (x - 30*sizeX, y - 30*sizeY, x + 30*sizeX, y + 30*sizeY);
    txEllipse (x + 20*sizeX, y - 20*sizeY, x + 65*sizeX, y + 30*sizeY);
    }

//{-------------------------------------------------------------------------------------------------------------
//! Рисует дом с треугольной крышей и трубой
//! 
//! @param x           x          - Х-координата центра облака
//! @param y           y          - Y-координата центра облака
//! @param sizeX       sizeX      - изменение размера по координате Х
//! @param sizeY       sizeY      - изменение размера по координате Y
//! @param cloudColor  cloudColor - цвет облака
//! 
//! @note                        Облако рисуется с помощью 3-х элипсов. 
//!                              
//! @par			             Пример использования:
//! @code
//!                              CloudDraw (200, 230, 1, 1.2, RGB (160, 217, 250));                             							
//! @endcode
//}-------------------------------------------------------------------------------------------------------------

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

