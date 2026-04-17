#include <iostream>
#include <limits>
#include "equipos.h"

using namespace std;

bool validarNumeroEquipo(int numeroEquipo)
{
    return (numeroEquipo >= 1 && numeroEquipo <= 20);
}

string obtenerTextoEstado(int estado)
{
    if (estado == 0) return "Libre";
    if (estado == 1) return "Ocupada";
    return "Mantenimiento";
}

void mostrarEstadoEquipos(int equipos[])
{
    cout << "\n--- ESTADO DE LAS COMPUTADORAS ---" << endl;

    for (int i = 0; i < TOTAL_EQUIPOS; i++)
    {
        cout << "Equipo " << (i + 1) << ": " << obtenerTextoEstado(equipos[i]) << endl;
    }
}

void cambiarEstadoEquipo(int equipos[])
{
    int numeroEquipo, nuevoEstado;

    cout << "\nIngrese el numero de equipo (1-20): ";
    cin >> numeroEquipo;

    while (cin.fail() || !validarNumeroEquipo(numeroEquipo))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: escribe un numero entre 1 y 20: ";
        cin >> numeroEquipo;
    }

    cout << "Nuevo estado:" << endl;
    cout << "0. Libre" << endl;
    cout << "1. Ocupada" << endl;
    cout << "2. Mantenimiento" << endl;
    cout << "Seleccione el nuevo estado: ";
    cin >> nuevoEstado;

    while (cin.fail() || nuevoEstado < 0 || nuevoEstado > 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: escribe 0, 1 o 2: ";
        cin >> nuevoEstado;
    }

    equipos[numeroEquipo - 1] = nuevoEstado;
    cout << "Estado actualizado correctamente." << endl;
}