//{=============================================================================
//!@brief    ������ ����������
//!
//!@author   ������� ��������
//!
//!@date     2021
//!
//!@mainpage
//!          �������:
//!
//!         - @ref DrawSun()
//!         - @ref DrawCloud()
//!         - @ref DrawElka()
//!         - @ref DrawHaus()
//!         - @ref DrawCat()
//!         - @ref DrawChick()
//!         - @ref DrawGirl()
//!         - @ref DrawAirplan()
//!         - @ref DrawBus()
//!
//! @image html Images/Example.jpg
//}=============================================================================

#include <cmath>
#include "TXLib.h"

void DrawSun      (int x, int y, int rSun, int luch);
void DrawElka     (int x, int y, double size, int crown1, int crown2, int crown3,
                   int kachanie, int widthTrunk);
void DrawHaus     (int x, int y, double sizeX, double sizeY,
                   int shiftKrisha, int heightKrisha, int widthWindow, int heightWindow,
                   COLORREF wallColor, COLORREF krishaColor, COLORREF windowColor);
void DrawCat      (int x, int y, double size, int lengthTail, int heightTail,
                   int pawsL, int pawsR, int us1, int us2, int us3, COLORREF catColor);
void DrawChick    (int x, int y, double sizeX, double sizeY,
                   int moveWing, int lengthStep, int moveBeak);
void DrawAirplan  (int x, int y, double sizeX, double sizeY, COLORREF airplanColor, COLORREF windowColor);
void DrawCloud    (int x, int y, double sizeCloud, COLORREF cloudColor);
void DrawBus      (int x, int y, double sizeX, double sizeY, double moveWheel,
                   bool headlights, COLORREF busColor, COLORREF windowColor);
void DrawGirl     (int x, int y, double sizeGirl, int legs, int eyeR, int crazy, int face,
                   int moveHandR, int moveHandL, int smile, COLORREF bodyColor);

//{=============================================================================
//! ������ ������
//!
//! ������ ������ � ��������
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Sun.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x    x - ���������� ������ ������
//! @param y    y - ���������� ������ ������
//! @param rSun ������ ������
//! @param luch ����� ���� ������
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par        ������ �������������:
//! @code
//!         DrawSun (100, 100, 17, 25);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawSun (int x, int y, int rSun, int luch)
    {
    txSetColor (TX_YELLOW, 3);
    txSetFillColor (TX_YELLOW);
    txCircle (x, y, rSun);
    txLine (x,               y - rSun - luch, x,               y + rSun + luch);
    txLine (x - rSun - luch, y,               x + rSun + luch, y);
    txLine (x - 0.75 * (rSun + luch), y - 0.75 * (rSun + luch),
            x + 0.75 * (rSun + luch), y + 0.75 * (rSun + luch));
    txLine (x - 0.75 * (rSun + luch), y + 0.75 * (rSun + luch),
            x + 0.75 * (rSun + luch), y - 0.75 * (rSun + luch));
    }

//{=============================================================================
//! ������  ������
//!
//! ������ ������� �������� ������
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Elka.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x          x - ���������� �������� ������
//! @param y          y - ���������� �������� ������
//! @param size       ������ ������
//! @param crown1     ������ ������� ����� ������
//! @param crown2     ������ ������� ����� ������
//! @param crown3     ������ ������ ����� ������
//! @param kachanie   ������ ����� ������������
//! @param widthTrunk ������ ������ ������
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par              ������ �������������:
//! @code
//!         DrawElka (100, 100, 0.7, 10, 20, 30, 0, 20);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawElka (int x, int y, double size, int crown1, int crown2, int crown3, int kachanie, int widthTrunk)
    {
    txSetColor (TX_GREEN);
    txSetFillColor (TX_GREEN);

    POINT Treug1[3] = {{ROUND ((x - 17 - crown1/2) * size), ROUND ((y + 36 + kachanie/2) * size)},
                       {ROUND ((x - kachanie) * size),      ROUND (y * size)},
                       {ROUND ((x + 17 + crown1/2) * size), ROUND ((y + 36 - kachanie/2) * size)}};
    txPolygon (Treug1, 3);

    POINT Treug2[3] = {{ROUND ((x - 25 - crown2/2) * size), ROUND ((y + 60 + kachanie/2) * size)},
                       {ROUND ((x - kachanie/2) * size),    ROUND ((y + 36) * size)},
                       {ROUND ((x + 25 + crown2/2) * size), ROUND ((y + 60 - kachanie/2) * size)}};
    txPolygon (Treug2, 3);

    POINT Treug3[3] = {{ROUND ((x - 30 - crown3/2) * size), ROUND ((y + 90 + kachanie/2) * size)},
                       {ROUND ((x - kachanie/3) * size),    ROUND ((y + 60) * size)},
                       {ROUND ((x + 30 + crown3/2) * size), ROUND ((y + 90 - kachanie/2) * size)}};
    txPolygon (Treug3, 3);

    txSetColor (TX_BROWN);
    txSetFillColor (TX_BROWN);
    txRectangle (ROUND ((x - widthTrunk/2) * size), ROUND ((y +  90) * size),
                 ROUND ((x + widthTrunk/2) * size), ROUND ((y + 115) * size));
    }

//{=============================================================================
//! ������ �����
//!
//! ������ ����� ����������� ����� � ����� �����
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Haus.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x            x - ���������� ������ ������ (����� ��������)
//! @param y            y - ���������� ������ ������ (����� ��������)
//! @param sizeX        ������ ������ ������
//! @param sizeY        ������ ������ ������
//! @param shiftKrisha  ����� ����� ������. ������ ����� �������������
//! @param heightKrisha ���������� ��� ���������� ������ ����� ������
//! @param widthWindow  ������ ���� ������
//! @param heightWindow ������ ���� ������
//! @param wallColor    ���� ����� ������
//! @param krishaColor  ���� ����� ������
//! @param windowColor  ���� ���� ������
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par                ������ �������������:
//! @code
//!         DrawHaus (100, 100, 1, 1, 20, 0, 50, 50, TX_YELLOW, TX_RED, TX_BLUE);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawHaus (int x, int y, double sizeX, double sizeY,
               int shiftKrisha, int heightKrisha, int widthWindow, int heightWindow,
               COLORREF wallColor, COLORREF krishaColor, COLORREF windowColor)
    {
    txSetColor (TX_BLACK);
    txSetFillColor (krishaColor);
    POINT Krisha[3] = {{ROUND(x - 80 * sizeX),  ROUND(y + 100 * sizeY)},
                       {ROUND(x + shiftKrisha), ROUND(y - heightKrisha)},
                       {ROUND(x + 80 * sizeX),  ROUND(y + 100 * sizeY)}};
    txPolygon (Krisha, 3);

    txSetFillColor (wallColor);
    txRectangle (ROUND(x - 80 * sizeX), ROUND(y + 100 * sizeY),
                 ROUND(x + 80 * sizeX), ROUND(y + 250 * sizeY));
    txSetFillColor (windowColor);
    txRectangle (ROUND(x - 38 * sizeX - widthWindow/2), ROUND(y + 139 * sizeY - heightWindow/2),
                 ROUND(x + 40 * sizeX + widthWindow/2), ROUND(y + 208 * sizeY + heightWindow/2));
    txLine (ROUND(x - 38 * sizeX - widthWindow/2), ROUND(y + 174 * sizeY - heightWindow/2),
            ROUND(x + 40 * sizeX + widthWindow/2), ROUND(y + 174 * sizeY - heightWindow/2));
    txLine (ROUND(x + sizeX),                      ROUND(y + 174 * sizeY - heightWindow/2),
            ROUND(x + sizeX),                      ROUND(y + 208 * sizeY + heightWindow/2));
    }

//{=============================================================================
//! ������ �������
//!
//! ������ ������� � �������� ������� � ������� ��������
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Girl.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x         x - ���������� ��� �������
//! @param y         y - ���������� ��� �������
//! @param sizeGirl  ������ �������. ������� ����� ���� ���������� � ��������
//! @param legs      ������ ���� �������. ������� ����� ������ ������ ��� �����
//! @param eyeR      ������ ���� �������
//! @param crazy     � ������� ����� ���� ������ �� �������� �����
//! @param face      ������� ����� ����������� ������ (�.�. ��� ����)
//! @param moveHandR �������� ������ ���� �������
//! @param moveHandL �������� ����� ���� �������
//! @param smile     ������ �������
//! @param bodyColor ���� ������ �������
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par             ������ �������������:
//! @code
//!                  DrawGirl (500, 100, 0.9, 2, 3, 1, 1, 40, 0, 8, TX_GREEN);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawGirl (int x, int y, double sizeGirl, int legs, int eyeR, int crazy, int face,
               int moveHandR, int moveHandL, int smile, COLORREF bodyColor)
    {
    txSetFillColor (bodyColor);
    txSetColor (TX_BLACK);
    POINT Girl[3] = {{ROUND (x - 35 * sizeGirl), ROUND (y + 130 * sizeGirl)},
                     {ROUND (x -  1 * sizeGirl), ROUND (y -   1 * sizeGirl)},
                     {ROUND (x + 35 * sizeGirl), ROUND (y + 130 * sizeGirl)}};
    txPolygon (Girl, 3);

    txSetFillColor (TX_RED);
    POINT Bant1[3] = {{ROUND (x - 24 * sizeGirl), ROUND (y - 36 * sizeGirl)},
                      {ROUND (x - 24 * sizeGirl), ROUND (y - 68 * sizeGirl)},
                      {ROUND (x +  1 * sizeGirl), ROUND (y - 51 * sizeGirl)}};
    txPolygon (Bant1, 3);
    POINT Bant2[3] = {{ROUND (x + 26 * sizeGirl), ROUND (y - 36 * sizeGirl)},
                      {ROUND (x + 26 * sizeGirl), ROUND (y - 68 * sizeGirl)},
                      {ROUND (x +  1 * sizeGirl), ROUND (y - 51 * sizeGirl)}};
    txPolygon (Bant2, 3);

    txSetFillColor (TX_WHITE);
    txCircle (ROUND (x - 1 * sizeGirl), ROUND (y - 25 * sizeGirl), ROUND (25 * sizeGirl));
    txCircle (ROUND (x - 1 * sizeGirl), ROUND (y - 21 * sizeGirl), ROUND ( 2 * sizeGirl) * face);

    txSetColor (TX_BLACK);
    txSetFillColor (RGB (70, 130, 180));
    txCircle (ROUND (x - 6 * sizeGirl), ROUND (y - 30 * sizeGirl), ROUND (eyeR * sizeGirl - crazy * sizeGirl) * face);
    txCircle (ROUND (x + 7 * sizeGirl), ROUND (y - 30 * sizeGirl), ROUND (eyeR * sizeGirl + crazy * sizeGirl) * face);

    txSetColor (TX_RED, 2);
    txLine (ROUND (x - 10 * sizeGirl) * face, ROUND (y - 9 * sizeGirl) * face,
            ROUND (x +  1 * sizeGirl) * face, ROUND (y - 9 * sizeGirl + smile * sizeGirl) * face);
    txLine (ROUND (x + 10 * sizeGirl) * face, ROUND (y - 9 * sizeGirl) * face,
            ROUND (x +  1 * sizeGirl) * face, ROUND (y - 9 * sizeGirl + smile * sizeGirl) * face);

    txSetColor (TX_BLACK, 3);
    txLine (ROUND (x -  9 * sizeGirl), ROUND (y + 35 * sizeGirl),
            ROUND (x - 56 * sizeGirl), ROUND (y + 57 * sizeGirl + moveHandR * sizeGirl));
    txLine (ROUND (x + 11 * sizeGirl), ROUND (y + 36 * sizeGirl),
            ROUND (x + 56 * sizeGirl), ROUND (y + 59 * sizeGirl + moveHandL * sizeGirl));

    txSetColor (TX_RED, 3);
    txLine (ROUND (x - 2 * sizeGirl), ROUND (y + 130 * sizeGirl),
            ROUND (x - 4 * sizeGirl), ROUND (y + 174 * sizeGirl + 5 * legs * sizeGirl));
    txLine (ROUND (x + 2 * sizeGirl), ROUND (y + 130 * sizeGirl),
            ROUND (x + 4 * sizeGirl), ROUND (y + 174 * sizeGirl - 5 * legs * sizeGirl));
    }

//{=============================================================================
//! ������ ����
//!
//! ������ ������ ������
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Cat.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x          x - ���������� ������ ������ ����
//! @param y          y - ���������� ������ ������ ����
//! @param size       ������ ����
//! @param lengthTail ����� �������� ���� (���� ������ ������ ������)
//! @param heightTail ������ ������� �������� ���� (0 - �������������)
//! @param pawsL      ��� ������ ��� ����
//! @param pawsR      ��� �������� ��� ����
//! @param us1        ���������/�������� ������� �� ����
//! @param us2        ���������/�������� ������� �� ����
//! @param us3        ���������/�������� ������ �� ����
//! @param catColor   ���� ����
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par              ������ �������������:
//! @code
//!         DrawCat (500, 100, 1.5, 30, 10, 10, 20, 3, 1, -2, TX_WHITE);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawCat (int x, int y, double size, int lengthTail, int heightTail,
              int pawsL, int pawsR, int us1, int us2, int us3, COLORREF catColor)
    {
    txSetColor (TX_LIGHTGRAY);
    txSetFillColor (catColor);
    txRectangle (ROUND ((x - 105) * size), ROUND ((y + 16) * size),
                 ROUND ((x -  10) * size), ROUND ((y + 56) * size));

    POINT Ear1[3] = {{ROUND ((x - 13) * size), ROUND ((y - 22) * size)},
                     {ROUND ((x -  4) * size), ROUND ((y - 38) * size)},
                     {ROUND ((x +  5) * size), ROUND ((y - 22) * size)}};
    txPolygon (Ear1, 3);
    POINT Ear2[3] = {{ROUND ((x +  5) * size), ROUND ((y - 20) * size)},
                     {ROUND ((x + 10) * size), ROUND ((y - 35) * size)},
                     {ROUND ((x + 15) * size), ROUND ((y - 20) * size)}};
    txPolygon (Ear2, 3);

    txCircle (ROUND (x * size), ROUND (y * size), ROUND (23 * size));

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txCircle (ROUND ((x +  9) * size), ROUND ((y - 5) * size), ROUND (2 * size));
    txCircle (ROUND ((x + 23) * size), ROUND ((y + 1) * size), ROUND (2 * size));
    txLine (ROUND ((x + 20) * size), ROUND ((y +  1) * size),
            ROUND ((x + 10) * size), ROUND ((y +  1 - us1) * size));
    txLine (ROUND ((x + 20) * size), ROUND ((y +  1) * size),
            ROUND ((x + 10) * size), ROUND ((y +  5 - us2) * size));
    txLine (ROUND ((x + 20) * size), ROUND ((y +  1) * size),
            ROUND ((x + 13) * size), ROUND ((y + 10 - us3) * size));

    txSetColor (TX_BLACK, 3);
    txLine (ROUND ((x - 153 - lengthTail) * size), ROUND ((y + 16 - heightTail) * size),
            ROUND ((x - 105) * size),              ROUND ((y + 16) * size));

    txLine (ROUND ((x - 86 - pawsL/2) * size), ROUND ((y + 88) * size), ROUND ((x - 86) * size), ROUND ((y + 55) * size));
    txLine (ROUND ((x - 86 + pawsL/2) * size), ROUND ((y + 86) * size), ROUND ((x - 86) * size), ROUND ((y + 55) * size));
    txLine (ROUND ((x - 30 - pawsR/2) * size), ROUND ((y + 87) * size), ROUND ((x - 30) * size), ROUND ((y + 55) * size));
    txLine (ROUND ((x - 30 + pawsR/2) * size), ROUND ((y + 86) * size), ROUND ((x - 30) * size), ROUND ((y + 55) * size));
    }

//{=============================================================================
//! ������ ��������
//!
//! ������ ������ ����
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Chick.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x          x - ���������� ������ �������� ��������
//! @param y          y - ���������� ������ �������� ��������
//! @param sizeX      ������ ������ ��������
//! @param sizeY      ������ ������ �������� (���� ������������, �� ������� ������)
//! @param moveWing   �������� ����� ��������
//! @param lengthStep ����� ���� ��������
//! @param moveBeak   �������� ����� �������� (����� �������!)
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par              ������ �������������:
//! @code
//!         DrawChick (500, 500,  2, 2, 20, 20, 6);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawChick (int x, int y, double sizeX, double sizeY, int moveWing, int lengthStep, int moveBeak)
    {
    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (x, y, 25 * sizeX);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    POINT Beak1[3] = {{ROUND(x - 37 * sizeX), ROUND(y -                23 * sizeY)},
                      {ROUND(x - 46 * sizeX), ROUND(y - (18 + moveBeak/2) * sizeY)},
                      {ROUND(x - 37 * sizeX), ROUND(y -                18 * sizeY)}};
    txPolygon (Beak1, 3);
    POINT Beak2[3] = {{ROUND(x - 37 * sizeX), ROUND(y -                15 * sizeY)},
                      {ROUND(x - 46 * sizeX), ROUND(y - (18 - moveBeak/2) * sizeY)},
                      {ROUND(x - 37 * sizeX), ROUND(y -                18 * sizeY)}};
    txPolygon (Beak2, 3);

    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txCircle (ROUND (x - 23 * sizeX), ROUND (y - 21 * sizeY), ROUND (15 * sizeX));
    txCircle (ROUND (x + 19 * sizeX), ROUND (y -  5 * sizeY), ROUND (10 * sizeX));

    txSetColor (TX_BLACK);
    txSetFillColor (TX_YELLOW);
    POINT Wing[3] = {{ROUND(x -  7 * sizeX), ROUND(y -        7 * sizeY)},
                     {ROUND(x + 11 * sizeX), ROUND(y - moveWing * sizeY)},
                     {ROUND(x + 14 * sizeX), ROUND(y -        7 * sizeY)}};
    txPolygon (Wing, 3);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);
    txCircle (x - 31 * sizeX, y - 20 * sizeY, 2 * sizeX);
    txLine ((x -  3 * sizeX), (y + 26 * sizeY), (x -  3 - lengthStep/2 * sizeX), (y + 40 * sizeY));
    txLine ((x +  2 * sizeX), (y + 26 * sizeY), (x +  2 + lengthStep/2 * sizeX), (y + 40 * sizeY));
    }

//{=============================================================================
//! ������ �������
//!
//! ������ �������
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Airplan.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x            x - ���������� ������ ��������
//! @param y            y - ���������� ������ ��������
//! @param sizeX        ������ ����� ��������
//! @param sizeY        ������ ������ ��������
//! @param airplanColor ���� ��������
//! @param windowColor  ���� ������������ ��������
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par        ������ �������������:
//! @code
//!         DrawAirplan (500, 200, 1, 1, TX_BLUE, TX_LIGHTGRAY);
//! @endcode
//}-----------------------------------------------------------------------------
void DrawAirplan (int x, int y, double sizeX, double sizeY, COLORREF airplanColor, COLORREF windowColor)
    {
    txSetColor (airplanColor);
    txSetFillColor (airplanColor);
    POINT Airplan[14] = {{ROUND ( x        * sizeX), ROUND ( y        * sizeY)}, {ROUND ((x +  30) * sizeX), ROUND ( y        * sizeY)},
                         {ROUND ((x +  50) * sizeX), ROUND ((y +  30) * sizeY)}, {ROUND ((x +  75) * sizeX), ROUND ((y +  30) * sizeY)},
                         {ROUND ((x +  60) * sizeX), ROUND ((y -  10) * sizeY)}, {ROUND ((x +  90) * sizeX), ROUND ((y -  10) * sizeY)},
                         {ROUND ((x + 115) * sizeX), ROUND ((y +  30) * sizeY)}, {ROUND ((x + 160) * sizeX), ROUND ((y +  30) * sizeY)},
                         {ROUND ((x + 210) * sizeX), ROUND ((y +  70) * sizeY)}, {ROUND ((x + 115) * sizeX), ROUND ((y +  70) * sizeY)},
                         {ROUND ((x +  90) * sizeX), ROUND ((y + 110) * sizeY)}, {ROUND ((x +  60) * sizeX), ROUND ((y + 110) * sizeY)},
                         {ROUND ((x +  75) * sizeX), ROUND ((y +  70) * sizeY)}, {ROUND ((x +  20) * sizeX), ROUND ((y +  70) * sizeY)}};
    txPolygon (Airplan, 14);
    txSetColor (windowColor);
    txSetFillColor (windowColor);
    int kWindow = 0;
    while (kWindow <= 4)
        {
        txCircle (ROUND ((x + 75 + 20 * kWindow) * sizeX), ROUND ((y + 45) * sizeY), ROUND (5 * sizeX));
        kWindow += 1;
        }
    }

//{=============================================================================
//! ������ ������
//!
//! ������ �������, ������� ����� ����� �� ����
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Cloud.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x          x - ���������� ������� ������ ����� ������
//! @param y          y - ���������� ����� ������� ����� ������
//! @param sizeCloud  ������ ������
//! @param cloudColor ���� ������ (������ ����� ����� ����� ������)
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par        ������ �������������:
//! @code
//!             DrawCloud (100, 10, 2, TX_GRAY);
//! @endcode
//}-----------------------------------------------------------------------------

void DrawCloud (int x, int y, double sizeCloud, COLORREF cloudColor)
    {
    txSetColor (cloudColor);
    txSetFillColor (cloudColor);

    txEllipse (ROUND( x       * sizeCloud), ROUND((y + 20) * sizeCloud), ROUND((x + 40) * sizeCloud), ROUND((y + 40) * sizeCloud));
    txEllipse (ROUND((x + 20) * sizeCloud), ROUND( y       * sizeCloud), ROUND((x + 80) * sizeCloud), ROUND((y + 40) * sizeCloud));
    txEllipse (ROUND((x + 20) * sizeCloud), ROUND((y + 30) * sizeCloud), ROUND((x + 60) * sizeCloud), ROUND((y + 50) * sizeCloud));
    }

//{=============================================================================
//! ������ �������
//!
//! ������ ����������� �������
//!
//! <table border = 0>
//! <tr valign=middle>
//! <td>
//!
//! @image html Images/Bus.jpg
//!
//! </td>
//!
//! <td>
//!
//! @param x           x - ���������� ������ ������� ��������
//! @param y           y - ���������� ����� ��������
//! @param sizeX       ������ ����� ��������
//! @param sizeY       ������ ������ ��������
//! @param moveWheel   �������� ������ �������� (�����/����)
//! @param headlights  ���� ��� (��� ����� ����� ������ ������)
//! @param busColor    ���� ��������
//! @param windowColor ���� ���� ��������
//!
//! </td>
//! </tr>
//! </table>
//!
//! @par              ������ �������������:
//! @code
//!         DrawBus (200, 200, 10, 10, 0, true, RGB (222, 184, 135), RGB (240, 230, 140));
//! @endcode
//}-----------------------------------------------------------------------------

void DrawBus (int x, int y, double sizeX, double sizeY, double moveWheel,
              bool headlights, COLORREF busColor, COLORREF windowColor)
    {
    txSetColor (busColor);
    txSetFillColor (busColor);
    txRectangle (x - 10 * sizeX, y, x + 10 * sizeX, y + 10 * sizeY);

    if (headlights == true)
        {
        txSetColor (RGB (255, 160, 122));
        txSetFillColor (RGB (255, 160, 122));
        POINT Fara[4] = {{ROUND(x +  9 * sizeX), ROUND(y +  6 * sizeY)},
                         {ROUND(x + 30 * sizeX), ROUND(y +  5 * sizeY)},
                         {ROUND(x + 30 * sizeX), ROUND(y + 12 * sizeY)},
                         {ROUND(x +  9 * sizeX), ROUND(y +  8 * sizeY)}};
        txPolygon (Fara, 4);
        }

    txSetFillColor (TX_ORANGE);
    txCircle (x + 9 * sizeX, y + 7 * sizeY, 1 * sizeX);

    txSetColor (windowColor);
    txSetFillColor (windowColor);
    txRectangle (x -  9 * sizeX, y + 2 * sizeY, x + 10 * sizeX, y +  6 * sizeY);
    txSetColor (RGB (128, 128, 128), 3);
    txLine (x - 9 * sizeX, y +  2 * sizeY, x -  9 * sizeX, y +  6 * sizeY);
    txLine (x - 6 * sizeX, y +  2 * sizeY, x -  6 * sizeX, y +  6 * sizeY);
    txLine (x - 2 * sizeX, y +  2 * sizeY, x -  2 * sizeX, y + 10 * sizeY);
    txLine (x + 2 * sizeX, y +  2 * sizeY, x +  2 * sizeX, y + 10 * sizeY);
    txLine (x + 6 * sizeX, y +  2 * sizeY, x +  6 * sizeX, y +  6 * sizeY);
    txLine (x - 9 * sizeX, y +  2 * sizeY, x + 10 * sizeX, y +  2 * sizeY);
    txLine (x - 9 * sizeX, y +  6 * sizeY, x + 10 * sizeX, y +  6 * sizeY);
    txLine (x - 2 * sizeX, y + 10 * sizeY, x +  2 * sizeX, y + 10 * sizeY);

    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txCircle (x - 6 * sizeX, y + 10 * sizeY - moveWheel, 2 * sizeX);
    txCircle (x + 6 * sizeX, y + 10 * sizeY + moveWheel, 2 * sizeX);
    }
