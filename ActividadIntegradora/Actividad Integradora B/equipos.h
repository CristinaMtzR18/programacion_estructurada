#ifndef EQUIPOS_H
#define EQUIPOS_H

#include <string>
using namespace std;

const int TOTAL_EQUIPOS = 20;

bool validarNumeroEquipo(int numeroEquipo);
string obtenerTextoEstado(int estado);
void mostrarEstadoEquipos(int equipos[]);
void cambiarEstadoEquipo(int equipos[]);

#endif