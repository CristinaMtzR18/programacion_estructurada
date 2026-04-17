#include <iostream>
#include "utilidades.h"

using namespace std;

void mostrarBienvenida()
{
    cout << "\n==============================================" << endl;
    cout << "   SISTEMA SIG-CONECTA - ACTIVIDAD INTEGRADORA" << endl;
    cout << "==============================================" << endl;
    cout << "Bienvenida y bienvenido al sistema." << endl;
    cout << "Aqui podras controlar equipos, visitantes e incidentes." << endl;
    cout << "==============================================" << endl;
}

void mostrarMenu()
{
    cout << "\n--------------- MENU PRINCIPAL ---------------" << endl;
    cout << "1. Consultar estado de computadoras" << endl;
    cout << "2. Modificar estado de computadora" << endl;
    cout << "3. Registrar visitante" << endl;
    cout << "4. Consultar bitacora de visitantes" << endl;
    cout << "5. Registrar incidente" << endl;
    cout << "6. Consultar historial de incidentes" << endl;
    cout << "7. Guardar y salir" << endl;
    cout << "Seleccione una opcion: ";
}