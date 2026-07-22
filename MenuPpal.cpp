// MenuPpal.cpp
#include <iostream>
#include "ModulosHB.h"
#include "Screen.h"

using namespace std;

int MenuPpal(Usuario &usr) {
    Screen::clrScr();

    // 1. Marco exterior
    Screen::Ventana(2, 2, 70, 23);

    // 2. Encabezado
    Screen::GoToXY(8, 5);
    Screen::textColor(11); // Celeste
    cout << "Menu Din\xA0mico";

    Screen::GoToXY(45, 5);
    Screen::textColor(10); // Verde
    cout << "Banco Mesopotamia";

    // 3. Matriz de opciones fija (coincide exactamente con el char[][25] que pide MenuNavegar)
    char opciones[12][25] = {
        "Token",
        "Simulacion Plazo Fijo",
        "Inversion Plazo Fijo",
        "Datos Personales",
        "CBU",
        "Movimientos CA",
        "Movimientos TD",
        "Movimientos TC",
        "Deposito",
        "Compra",
        "Ordenar Usuarios",
        "Cerrar Sesion"
    };

    // Parámetros de posición para el menú
    short linIni = 8;
    short linFin = 8 + 12 - 1; // Fila inicial + cantidad de opciones - 1
    short colIni = 12;

    // Imprimimos la lista inicial de opciones en pantalla
    for (int i = 0; i < 12; i++) {
        Screen::GoToXY(colIni, linIni + i);
        Screen::textColor(15);
        cout << opciones[i];
    }

    // 4. Invocamos la función navegable de la cátedra
    // (Maneja la navegación con flechas, los mensajes de ayuda al pie y detecta la tecla ESCAPE)
    int indiceElegido = Screen::MenuNavegar(opciones, linIni, linFin, colIni);

    // Devuelve la opción elegida (de 1 a 12)
    return indiceElegido + 1;
}