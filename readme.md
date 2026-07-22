# 🏦 Home Banking UTN

Bienvenido al proyecto. Esta guía está pensada para que cualquier persona pueda entender rápidamente cómo está organizado el sistema, cómo se navega entre pantallas y cómo agregar una nueva funcionalidad.

## ✨ Idea general

El programa está dividido en módulos para que cada parte tenga una responsabilidad clara:

- el punto de entrada vive en main
- el flujo principal está en ModulosHB
- cada pantalla tiene su propio archivo
- la librería visual se usa desde Screen

## 📁 Archivos principales

- main.cpp: inicia la aplicación.
- ModulosHB.h: define estructuras, constantes y prototipos de funciones.
- ModulosHB.cpp: controla el flujo general del programa y el switch de opciones.
- Screen.h / Screen.cpp: funciones de interfaz visual y navegación del menú.
- DatosIniciales.cpp: carga los datos iniciales del sistema.
- MenuLogin.cpp: pantalla de login.
- MenuPpal.cpp: menú principal interactivo.

## 🔄 Cómo funciona el flujo

Cuando el usuario elige una opción en el menú, esa selección pasa por el switch de ModulosHB.cpp.

```cpp
int opcion = MenuPpal(aUsuarios[posUsuario]);

switch (opcion) {
    case 4:
        Menu_VerDatosPersonales(aUsuarios[posUsuario]);
        break;
    case 12:
        sesionActiva = false;
        break;
}
```

En resumen: el menú devuelve una opción y el módulo principal decide qué pantalla ejecutar.

## 🛠️ Cómo agregar una nueva feature

Sigue estos pasos:

1. Declarar la función en ModulosHB.h

```cpp
// ModulosHB.h
void Menu_VerDatosPersonales(Usuario &usr);
```

2. Crear un archivo nuevo para la pantalla

```cpp
// VerDatosPersonales.cpp
#include <iostream>
#include <conio.h>
#include "ModulosHB.h"
#include "Screen.h"

using namespace std;

void Menu_VerDatosPersonales(Usuario &usr) {
    Screen::clrScr();
    Screen::Ventana(2, 2, 70, 20);

    Screen::GoToXY(5, 4);
    Screen::textColor(11);
    cout << "=== DATOS PERSONALES ===";

    Screen::GoToXY(5, 6);
    cout << "Nombre: " << usr.apellidoNombre;

    Screen::GoToXY(5, 7);
    cout << "DNI   : " << usr.dni;

    Screen::GoToXY(5, 15);
    cout << "Presione cualquier tecla para volver al menu...";
    _getch();
}
```

3. Conectar la función en ModulosHB.cpp

```cpp
case 4:
    Menu_VerDatosPersonales(aUsuarios[posUsuario]);
    break;
```

4. Compilar incluyendo el nuevo archivo

```bash
g++ main.cpp ModulosHB.cpp DatosIniciales.cpp MenuLogin.cpp MenuPpal.cpp VerDatosPersonales.cpp Screen.cpp -o app.exe
```

## ▶️ Compilar y ejecutar

### Compilar

```bash
g++ main.cpp ModulosHB.cpp DatosIniciales.cpp MenuLogin.cpp MenuPpal.cpp Screen.cpp -o app.exe
```

### Ejecutar

```bash
./app.exe
```

Si estás en PowerShell:

```powershell
.\app.exe
```

## 🚀 Git: guardar y subir cambios

```bash
git add .
git commit -m "feat: agregada nueva pantalla"
git push origin main
```

## 💡 Nota rápida

Si una pantalla nueva se agrega al menú, también hay que pensar en qué número de opción corresponde y enlazarla correctamente en el switch.
