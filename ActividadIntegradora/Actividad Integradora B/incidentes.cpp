#include <iostream>
#include <limits>
#include "incidentes.h"
#include "equipos.h"

using namespace std;

void registrarIncidente(RegistroBitacora bitacoraIncidentes[], int &totalIncidentes)
{
    if (totalIncidentes >= MAX_INCIDENTES)
    {
        cout << "La bitacora de incidentes ya esta llena." << endl;
        return;
    }

    cout << "\n--- REGISTRO DE INCIDENTE ---" << endl;
    cout << "ID del equipo: ";
    cin >> bitacoraIncidentes[totalIncidentes].idEquipo;

    while (cin.fail() || !validarNumeroEquipo(bitacoraIncidentes[totalIncidentes].idEquipo))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: escribe un numero de equipo entre 1 y 20: ";
        cin >> bitacoraIncidentes[totalIncidentes].idEquipo;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Hora del incidente: ";
    getline(cin, bitacoraIncidentes[totalIncidentes].hora);

    while (bitacoraIncidentes[totalIncidentes].hora.empty())
    {
        cout << "Error: la hora no puede quedar vacia. Intente de nuevo: ";
        getline(cin, bitacoraIncidentes[totalIncidentes].hora);
    }

    cout << "Tipo de incidente: ";
    getline(cin, bitacoraIncidentes[totalIncidentes].tipoIncidente);

    while (bitacoraIncidentes[totalIncidentes].tipoIncidente.empty())
    {
        cout << "Error: el tipo de incidente no puede quedar vacio. Intente de nuevo: ";
        getline(cin, bitacoraIncidentes[totalIncidentes].tipoIncidente);
    }

    cout << "Descripcion: ";
    getline(cin, bitacoraIncidentes[totalIncidentes].descripcion);

    while (bitacoraIncidentes[totalIncidentes].descripcion.empty())
    {
        cout << "Error: la descripcion no puede quedar vacia. Intente de nuevo: ";
        getline(cin, bitacoraIncidentes[totalIncidentes].descripcion);
    }

    totalIncidentes++;
    cout << "Incidente registrado correctamente." << endl;
}

void mostrarHistorialIncidentes(RegistroBitacora bitacoraIncidentes[], int totalIncidentes)
{
    cout << "\n--- HISTORIAL DE INCIDENTES ---" << endl;

    if (totalIncidentes == 0)
    {
        cout << "No hay incidentes registrados." << endl;
        return;
    }

    for (int i = 0; i < totalIncidentes; i++)
    {
        cout << "\nIncidente " << (i + 1) << endl;
        cout << "Equipo: " << bitacoraIncidentes[i].idEquipo << endl;
        cout << "Hora: " << bitacoraIncidentes[i].hora << endl;
        cout << "Tipo: " << bitacoraIncidentes[i].tipoIncidente << endl;
        cout << "Descripcion: " << bitacoraIncidentes[i].descripcion << endl;
    }
}