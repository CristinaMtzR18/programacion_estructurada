#include <iostream>
#include <fstream>
#include <string>
#include "archivos.h"

using namespace std;

void guardarDatos(int equipos[],
                  string bitacoraVisitantes[][COLUMNAS_VISITANTES], int totalVisitantes,
                  RegistroBitacora bitacoraIncidentes[], int totalIncidentes)
{
    ofstream archivo("bitacora.txt");

    if (!archivo)
    {
        cout << "Error: no se pudo abrir el archivo." << endl;
        return;
    }

    archivo << "EQUIPOS" << endl;
    for (int i = 0; i < TOTAL_EQUIPOS; i++)
    {
        archivo << equipos[i] << endl;
    }

    archivo << "VISITANTES " << totalVisitantes << endl;
    for (int i = 0; i < totalVisitantes; i++)
    {
        archivo << bitacoraVisitantes[i][0] << "|"
                << bitacoraVisitantes[i][1] << "|"
                << bitacoraVisitantes[i][2] << "|"
                << bitacoraVisitantes[i][3] << "|"
                << bitacoraVisitantes[i][4] << "|"
                << bitacoraVisitantes[i][5] << endl;
    }

    archivo << "INCIDENTES " << totalIncidentes << endl;
    for (int i = 0; i < totalIncidentes; i++)
    {
        archivo << bitacoraIncidentes[i].idEquipo << "|"
                << bitacoraIncidentes[i].hora << "|"
                << bitacoraIncidentes[i].tipoIncidente << "|"
                << bitacoraIncidentes[i].descripcion << endl;
    }

    archivo.close();
}

void cargarDatos(int equipos[],
                 string bitacoraVisitantes[][COLUMNAS_VISITANTES], int &totalVisitantes,
                 RegistroBitacora bitacoraIncidentes[], int &totalIncidentes)
{
    ifstream archivo("bitacora.txt");

    if (!archivo)
    {
        return;
    }

    string linea;
    string palabra;

    archivo >> palabra;
    if (palabra == "EQUIPOS")
    {
        for (int i = 0; i < TOTAL_EQUIPOS; i++)
        {
            archivo >> equipos[i];
        }
    }

    archivo >> palabra >> totalVisitantes;
    archivo.ignore();

    for (int i = 0; i < totalVisitantes; i++)
    {
        getline(archivo, linea);

        size_t p1 = linea.find('|');
        size_t p2 = linea.find('|', p1 + 1);
        size_t p3 = linea.find('|', p2 + 1);
        size_t p4 = linea.find('|', p3 + 1);
        size_t p5 = linea.find('|', p4 + 1);

        if (p1 != string::npos && p2 != string::npos && p3 != string::npos &&
            p4 != string::npos && p5 != string::npos)
        {
            bitacoraVisitantes[i][0] = linea.substr(0, p1);
            bitacoraVisitantes[i][1] = linea.substr(p1 + 1, p2 - p1 - 1);
            bitacoraVisitantes[i][2] = linea.substr(p2 + 1, p3 - p2 - 1);
            bitacoraVisitantes[i][3] = linea.substr(p3 + 1, p4 - p3 - 1);
            bitacoraVisitantes[i][4] = linea.substr(p4 + 1, p5 - p4 - 1);
            bitacoraVisitantes[i][5] = linea.substr(p5 + 1);
        }
    }

    archivo >> palabra >> totalIncidentes;
    archivo.ignore();

    for (int i = 0; i < totalIncidentes; i++)
    {
        getline(archivo, linea);

        size_t p1 = linea.find('|');
        size_t p2 = linea.find('|', p1 + 1);
        size_t p3 = linea.find('|', p2 + 1);

        if (p1 != string::npos && p2 != string::npos && p3 != string::npos)
        {
            bitacoraIncidentes[i].idEquipo = stoi(linea.substr(0, p1));
            bitacoraIncidentes[i].hora = linea.substr(p1 + 1, p2 - p1 - 1);
            bitacoraIncidentes[i].tipoIncidente = linea.substr(p2 + 1, p3 - p2 - 1);
            bitacoraIncidentes[i].descripcion = linea.substr(p3 + 1);
        }
    }

    archivo.close();
}