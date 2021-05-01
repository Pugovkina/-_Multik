//{===========================================================================
//!@brief	         Function library
//!			   the first function library on C++        
//!@author	        Tatiana Pugovkina, 
//!				  sity Omsk, Liceum 64
//!@date				  2021
//}===========================================================================

#include "TXLib.h"

void Fon_Rectangle (COLORREF nebo_Color, COLORREF zemlia_Color);

void Flowers (int flower_centerX, int flower_centerY, COLORREF flower_center_Color, COLORREF lepestok_Color);

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
    txCreateWindow (1100, 800);
	
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
