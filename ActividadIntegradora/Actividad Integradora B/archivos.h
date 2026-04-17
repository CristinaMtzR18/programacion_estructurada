#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <string>
#include "equipos.h"
#include "visitantes.h"
#include "incidentes.h"

using namespace std;

void guardarDatos(int equipos[],
                  string bitacoraVisitantes[][COLUMNAS_VISITANTES], int totalVisitantes,
                  RegistroBitacora bitacoraIncidentes[], int totalIncidentes);

void cargarDatos(int equipos[],
                 string bitacoraVisitantes[][COLUMNAS_VISITANTES], int &totalVisitantes,
                 RegistroBitacora bitacoraIncidentes[], int &totalIncidentes);

#endif