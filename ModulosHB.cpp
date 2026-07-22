// ModulosHB.cpp
#include <iostream>
#include "ModulosHB.h"

using namespace std;

void SistemaHomeBanking() {
    // 1. Instanciamos el array de 5 usuarios
    Usuario aUsuarios[MAX_USUARIOS];
    
    // 2. Cargamos los datos iniciales (desde DatosIniciales.cpp)
    CargarUsuariosIniciales(aUsuarios);

    bool programaActivo = true;

    while (programaActivo) {
        // 3. Invocamos MenuLogin() (retorna la posición del usuario o -1 para salir)
        int posUsuario = MenuLogin(aUsuarios);

        if (posUsuario == -1) {
            // El usuario eligió salir desde la pantalla de login
            programaActivo = false;
        } else {
            // 4. Usuario autenticado con éxito -> Entra al flujo de sesión
            bool sesionActiva = true;

            while (sesionActiva) {
                // MenuPpal retorna la opción elegida
                int opcion = MenuPpal(aUsuarios[posUsuario]);

                switch (opcion) {
                    case 1:
                        // La opción 1 cierra el programa por ahora
                        sesionActiva = false;
                        programaActivo = false;
                        break;
                        
                    default:
                        // Para cualquier otra opción por ahora no hace nada
                        break;
                }
            }
        }
    }
}