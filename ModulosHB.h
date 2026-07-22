#ifndef MODULOS_HB_H
#define MODULOS_HB_H

#include <iostream>
#include <string>

using namespace std;

// ============================================================================
// 1. CONSTANTES DEL SISTEMA
// ============================================================================
const int MAX_USUARIOS = 5;
const int SALIR = 0;

// Constantes para nombres de archivos
const string ARCHIVO_CA = "MovimientosCA.txt";
const string ARCHIVO_TD = "MovimientosTD.txt";
const string ARCHIVO_TC = "MovimientosTC.txt";
const string ARCHIVO_LISTADOS = "ListadosHB.Txt";

// ============================================================================
// 2. ESTRUCTURAS DE DATOS (STRUCTS)
// ============================================================================

// Registro para los Datos Personales y Cuentas en memoria (los 5 usuarios)
struct Usuario {
    long dni;
    char apellidoNombre[50];
    char fechaNac[11];       // Formato "DD/MM/AAAA"
    char usuario[20];
    char clave[20];
    char celular[15];
    char email[40];
    char domicilio[50];
    char nroCuentaCA[20];
    char cbu[23];            // 22 dígitos + terminador nulo '\0'
    
    // Saldos actualizables en memoria
    float saldoPesos;
    float saldoDolares;
    bool cuentaActiva;
};

// Registro para Movimientos de Caja de Ahorro (MovimientosCA.txt)
struct MovimientoCA {
    short dia;
    short mes;
    short anio;
    char tipoMov;            // 'D' (Debe/Ingreso) o 'H' (Haber/Egreso)
    char detalle[30];
    float importe;
    float saldoResultante;
};

// Registro para Movimientos de Tarjeta de Débito (MovimientosTD.txt)
struct MovimientoTD {
    short dia;
    short mes;
    short anio;
    char comercio[30];
    float importe;
};

// Registro para Movimientos de Tarjeta de Crédito (MovimientosTC.txt)
struct MovimientoTC {
    short dia;
    short mes;
    short anio;
    char comercio[30];
    char cuotas[6];          // Ej: "1/3" o "N/A"
    long nroComprobante;
    float importe;
};

// ============================================================================
// 3. PROTOTIPOS DE FUNCIONES GENERALES Y CORE (INTEGRANTE A y B)
// ============================================================================
void CargarUsuariosIniciales(Usuario aUsuarios[]);
void SistemaHomeBanking();
int MenuLogin(Usuario aUsuarios[]);
int MenuPpal(Usuario &usr);

// Funciones de utilidad compartidas
bool ActualizarSaldo(Usuario &usr, float monto, char tipoMoneda, char operacion); // 'S' suma, 'R' resta

// ============================================================================
// 4. MÓDULOS DE INTEGRANTE A (Autenticación, Perfil y Tarjetas)
// ============================================================================
void Menu_Logout(int &posUsuarioLogueado);
void Menu_GenToken();
void Menu_VerDatosPersonales(Usuario usr);
void Menu_VerMisCuentas(Usuario usr);
void Menu_MostrarCBU(Usuario usr);
void Menu_CrearNuevaCuenta(Usuario &usr);
void Menu_ModificarClave(Usuario &usr);
void Menu_VerMovimientosTD();
void Menu_VerMovimientosTC();

// ============================================================================
// 5. MÓDULOS DE INTEGRANTE B (Transacciones, Operaciones e Inversiones)
// ============================================================================
void Menu_VerMovimientosCA();
void Menu_TransferirDinero(Usuario &usr);
void Menu_RecargarServicio(Usuario &usr, string servicio); // Sube o Celular
void Menu_Deposito(Usuario &usr);
void Menu_RegistrarCompra(Usuario &usr);
void Menu_SimularPlazoFijo();
void Menu_InversionPlazoFijo(Usuario &usr);
void Menu_InversionFondoComun(Usuario &usr);
void Menu_CompraVentaDolares(Usuario &usr);

#endif // MODULOS_HB_H