// MenuLogin.cpp
#include <iostream>
#include <cstring>
#include <conio.h>
#include "ModulosHB.h"
#include "Screen.h"

using namespace std;

// Leer clave ocultando caracteres con asteriscos
static void LeerClaveOculta(char claveOut[], int maxLen) {
    int i = 0;
    char c;
    while (true) {
        c = _getch();
        if (c == 13) { // Enter
            claveOut[i] = '\0';
            break;
        } else if (c == 8) { // Backspace
            if (i > 0) {
                i--;
                cout << "\b \b";
            }
        } else if (i < maxLen - 1 && c >= 32 && c <= 126) {
            claveOut[i++] = c;
            cout << '*';
        }
    }
}

int MenuLogin(Usuario aUsuarios[]) {
    long long dniInput;
    char usuarioInput[20];
    char claveInput[20];

    while (true) {
        Screen::clrScr();
        
        // Marco de la ventana usando las funciones de Screen
        Screen::Ventana(2, 2, 70, 22);

        // Encabezados
        Screen::GoToXY(8, 5);
        Screen::textColor(15); // Blanco
        cout << "Login";

        Screen::GoToXY(45, 5);
        Screen::textColor(10); // Verde
        cout << "Banco Mesopotamia";

        // Campos de ingreso
        Screen::textColor(15);
        Screen::GoToXY(8, 8);
        cout << "D.N.I. : ";
        cin >> dniInput;

        if (dniInput == 0) return -1; // Salir

        Screen::GoToXY(8, 9);
        cout << "Usuario: ";
        cin >> usuarioInput;

        Screen::GoToXY(8, 10);
        cout << "Clave  : ";
        LeerClaveOculta(claveInput, 20);

        // Validación de credenciales contra el array en memoria
        for (int i = 0; i < MAX_USUARIOS; i++) {
            if (aUsuarios[i].dni == dniInput &&
                strcmp(aUsuarios[i].usuario, usuarioInput) == 0 &&
                strcmp(aUsuarios[i].clave, claveInput) == 0) {
                
                return i; // Login exitoso
            }
        }

        // Error al validar
        Screen::GoToXY(8, 13);
        Screen::textColor(12); // Rojo
        cout << "Error: Datos incorrectos.";
        Screen::GoToXY(8, 14);
        Screen::textColor(7);
        cout << "Presione cualquier tecla para reintentar...";
        _getch();
    }
}