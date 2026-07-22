// DatosIniciales.cpp
#include <cstring>
#include "ModulosHB.h"

void CargarUsuariosIniciales(Usuario aUsuarios[]) {
    // Usuario 0
    aUsuarios[0].dni = 12345678;
    strcpy(aUsuarios[0].apellidoNombre, "Lanuscou Zubair");
    strcpy(aUsuarios[0].fechaNac, "15/05/2002");
    strcpy(aUsuarios[0].usuario, "zubair");
    strcpy(aUsuarios[0].clave, "1234");
    strcpy(aUsuarios[0].celular, "1112345678");
    strcpy(aUsuarios[0].email, "zubair@email.com");
    strcpy(aUsuarios[0].domicilio, "Av. Siempre Viva 123");
    strcpy(aUsuarios[0].nroCuentaCA, "CA-001-01");
    strcpy(aUsuarios[0].cbu, "0000003100000000000001");
    aUsuarios[0].saldoPesos = 150000.50f;
    aUsuarios[0].saldoDolares = 500.00f;
    aUsuarios[0].cuentaActiva = true;

    // Usuario 1
    aUsuarios[1].dni = 23456789;
    strcpy(aUsuarios[1].apellidoNombre, "Gomez Ana");
    strcpy(aUsuarios[1].fechaNac, "20/08/1998");
    strcpy(aUsuarios[1].usuario, "agomez");
    strcpy(aUsuarios[1].clave, "qwerty");
    strcpy(aUsuarios[1].celular, "1122334455");
    strcpy(aUsuarios[1].email, "ana.gomez@email.com");
    strcpy(aUsuarios[1].domicilio, "Calle Falsa 456");
    strcpy(aUsuarios[1].nroCuentaCA, "CA-001-02");
    strcpy(aUsuarios[1].cbu, "0000003100000000000002");
    aUsuarios[1].saldoPesos = 85000.00f;
    aUsuarios[1].saldoDolares = 120.00f;
    aUsuarios[1].cuentaActiva = true;

    // Usuario 2
    aUsuarios[2].dni = 34567890;
    strcpy(aUsuarios[2].apellidoNombre, "Perez Carlos");
    strcpy(aUsuarios[2].fechaNac, "03/11/1995");
    strcpy(aUsuarios[2].usuario, "cperez");
    strcpy(aUsuarios[2].clave, "admin");
    strcpy(aUsuarios[2].celular, "1198765432");
    strcpy(aUsuarios[2].email, "cperez@email.com");
    strcpy(aUsuarios[2].domicilio, "San Martin 789");
    aUsuarios[2].nroCuentaCA[0] = '\0';
    strcpy(aUsuarios[2].cbu, "0000003100000000000003");
    aUsuarios[2].saldoPesos = 0.0f;
    aUsuarios[2].saldoDolares = 0.0f;
    aUsuarios[2].cuentaActiva = false;

    // Usuario 3
    aUsuarios[3].dni = 45678901;
    strcpy(aUsuarios[3].apellidoNombre, "Rodriguez Maria");
    strcpy(aUsuarios[3].fechaNac, "10/01/2001");
    strcpy(aUsuarios[3].usuario, "mrodriguez");
    strcpy(aUsuarios[3].clave, "mariya");
    strcpy(aUsuarios[3].celular, "1155667788");
    strcpy(aUsuarios[3].email, "mrodriguez@email.com");
    strcpy(aUsuarios[3].domicilio, "Belgrano 1011");
    strcpy(aUsuarios[3].nroCuentaCA, "CA-001-04");
    strcpy(aUsuarios[3].cbu, "0000003100000000000004");
    aUsuarios[3].saldoPesos = 340000.00f;
    aUsuarios[3].saldoDolares = 1500.00f;
    aUsuarios[3].cuentaActiva = true;

    // Usuario 4
    aUsuarios[4].dni = 56789012;
    strcpy(aUsuarios[4].apellidoNombre, "Fernandez Lucas");
    strcpy(aUsuarios[4].fechaNac, "28/02/1992");
    strcpy(aUsuarios[4].usuario, "lfernandez");
    strcpy(aUsuarios[4].clave, "lucas2026");
    strcpy(aUsuarios[4].celular, "1144332211");
    strcpy(aUsuarios[4].email, "lfernandez@email.com");
    strcpy(aUsuarios[4].domicilio, "Mitre 2020");
    strcpy(aUsuarios[4].nroCuentaCA, "CA-001-05");
    strcpy(aUsuarios[4].cbu, "0000003100000000000005");
    aUsuarios[4].saldoPesos = 12500.75f;
    aUsuarios[4].saldoDolares = 0.0f;
    aUsuarios[4].cuentaActiva = true;
}