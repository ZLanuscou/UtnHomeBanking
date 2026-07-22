#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h> 
#include "Screen.h"
using namespace std;

#ifndef COLOR
#define COLOR 15
#endif

namespace Screen {
  void setConsoleColor(WORD c, WORD f) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c + 16 * f);
  }

  void GoToXY(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hConsole, pos);
  }

  int whereX() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
      return csbi.dwCursorPosition.X;
    return -1;
  }

  int whereY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
      return csbi.dwCursorPosition.Y;
    return -1;
  }

  void textColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
  }

  void textBackColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color * 16);
  }

  void clrScr() {
    DWORD n;
    DWORD size;
    COORD coord = {0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(h, &csbi);
    size = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
    GetConsoleScreenBufferInfo(h, &csbi);
    FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
    SetConsoleCursorPosition(h, coord);
  }

  void clrEol() {
    COORD coord;
    DWORD escrito;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(hStdOut, &info);
    coord = info.dwCursorPosition;

    int longitud = info.dwSize.X - coord.X;

    FillConsoleOutputCharacter(hStdOut, ' ', longitud, coord, &escrito);
    SetConsoleCursorPosition(hStdOut, coord);
  }

  void Window(short izquierda, short superior, short derecha, short inferior) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT windowSize;
    windowSize.Left = izquierda;
    windowSize.Top = superior;
    windowSize.Right = derecha;
    windowSize.Bottom = inferior;

    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
  }

  void MnsgBox(short x, short y, string mensaje, char alinea, short ancho) {
    Screen::GoToXY(x, y);
    if (alinea == 'i')
      cout << setw(ancho) << left << mensaje;
    else
      cout << setw(ancho) << right << mensaje;
  }

  void MnsgBox(short x, short y, string mensaje) {
    Screen::GoToXY(x, y);
    cout << mensaje;
  }

  void Marco(short x1, short y1, short x2, short y2, short color) {
    Screen::textColor(color);
    MnsgBox(x1 + 1, y1 + 1, "╔");
    MnsgBox(x2 - 1, y1 + 1, "╗");
    for (short i = 1; i <= x2 - x1 - 3; i++)
      MnsgBox(x1 + 1 + i, y1 + 1, "═");
    for (short i = 2; i <= y2 - y1 - 2; i++) {
      MnsgBox(x1 + 1, y1 + i, "║");
      MnsgBox(x2 - 1, y1 + i, "║");
    }
    MnsgBox(x1 + 1, y2 - 1, "╚");
    MnsgBox(x2 - 1, y2 - 1, "╝");
    for (short i = 1; i <= x2 - x1 - 3; i++)
      MnsgBox(x1 + 1 + i, y2 - 1, "═");
  }

  void Ventana(short x1, short y1, short x2, short y2) {
    SetConsoleOutputCP(CP_UTF8);
    Window(x1, y1, x2 + 2, y2);
    Screen::textColor(15);
    Screen::textBackColor(0);
    Screen::clrScr();
    Marco(x1, y1, x2, y2, COLOR);
  }

  void OcultarCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info);
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
  }

  void MostrarCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(consoleHandle, &info);
    info.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &info);
  }

  int MenuNavegar(char aMenu[][25], short lIni, short lFin, short cIni) {
    int Menu = lIni;

    Screen::OcultarCursor();
    Screen::MnsgBox(7, 20, "Flecha ↑ ↓ para moverse sobre el menú");
    Screen::MnsgBox(4, 21, "Tecla ESCAPE seleccionar la opción del menú");
    Screen::GoToXY(cIni, lIni);

    // Corregido: sintaxis limpia para la condición del while
    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
      Sleep(200);
      if (GetAsyncKeyState(VK_UP) & 0x8000) {
        if (Menu == lIni) {
          Screen::textColor(15);
          Screen::GoToXY(cIni, lIni);
          cout << aMenu[Menu - lIni];
          Menu = lFin;
          Screen::textColor(14);
          Screen::GoToXY(cIni, lFin);
          cout << aMenu[Menu - lIni];
        } else {
          Screen::textColor(15);
          Screen::GoToXY(cIni, Screen::whereY());
          cout << aMenu[Menu - lIni];
          Menu--;
          Screen::GoToXY(cIni, Screen::whereY() - 1);
          Screen::textColor(14);
          cout << aMenu[Menu - lIni];
        }
      } else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
        if (Menu == lFin) {
          Screen::textColor(15);
          Screen::GoToXY(cIni, lFin);
          cout << aMenu[Menu - lIni];
          Menu = lIni;
          Screen::GoToXY(cIni, lIni);
          Screen::textColor(14);
          cout << aMenu[Menu - lIni];
        } else {
          Screen::textColor(15);
          Screen::GoToXY(cIni, Screen::whereY());
          cout << aMenu[Menu - lIni];
          Menu++;
          Screen::GoToXY(cIni, Screen::whereY() + 1);
          Screen::textColor(14);
          cout << aMenu[Menu - lIni];
        }
      }
    }
    Screen::MostrarCursor();
    return Menu - lIni;
  }
} // namespace Screen

namespace FecHora {
  long GetTime(int &hh, int &mm, int &ss) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    hh = timeinfo->tm_hour;
    mm = timeinfo->tm_min;
    ss = timeinfo->tm_sec;
    return timeinfo->tm_hour * 10000 + timeinfo->tm_min * 100 + timeinfo->tm_sec;
  }

  long GetDate(int &year, int &mes, int &dia, int &ds) {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    year = 1900 + timeinfo->tm_year;
    mes = 1 + timeinfo->tm_mon;
    dia = timeinfo->tm_mday;
    ds = 1 + timeinfo->tm_wday;
    return (1900 + timeinfo->tm_year) * 10000 + (1 + timeinfo->tm_mon) * 100 + timeinfo->tm_mday;
  }
} 




