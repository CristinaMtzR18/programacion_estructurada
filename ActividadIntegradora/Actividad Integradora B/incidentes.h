#ifndef INCIDENTES_H
#define INCIDENTES_H

#include <string>
using namespace std;

const int MAX_INCIDENTES = 100;

struct RegistroBitacora
{
    int idEquipo;
    string hora;
    string tipoIncidente;
    string descripcion;
};

void registrarIncidente(RegistroBitacora bitacoraIncidentes[], int &totalIncidentes);
void mostrarHistorialIncidentes(RegistroBitacora bitacoraIncidentes[], int totalIncidentes);

#endif