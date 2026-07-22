#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <windows.h>

#ifndef COLOR
#define COLOR 15
#endif

namespace Screen {
    void setConsoleColor(WORD c, WORD f);
    void GoToXY(int x, int y);
    int whereX();
    int whereY();
    void textColor(int color);
    void textBackColor(int color);
    void clrScr();
    void clrEol();
    void Window(short izquierda, short superior, short derecha, short inferior);
    void MnsgBox(short x, short y, std::string mensaje, char alinea, short ancho = 0);
    void MnsgBox(short x, short y, std::string mensaje);
    void Marco(short x1, short y1, short x2, short y2, short color);
    void Ventana(short x1, short y1, short x2, short y2);
    void OcultarCursor();
    void MostrarCursor();
    int MenuNavegar(char aMenu[][25], short lIni, short lFin, short cIni);
}

namespace FecHora {
    long GetTime(int &hh, int &mm, int &ss);
    long GetDate(int &year, int &mes, int &dia, int &ds);
}

#endif // SCREEN_H