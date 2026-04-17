#ifndef VISITANTES_H
#define VISITANTES_H

#include <string>
using namespace std;

const int MAX_VISITANTES = 50;
const int COLUMNAS_VISITANTES = 6;

bool validarHorario(int hora);
bool validarIDVisitante(int id);
string obtenerNivelEstudio(int nivel);

void registrarVisitante(int equipos[], string bitacoraVisitantes[][COLUMNAS_VISITANTES], int &totalVisitantes);
void mostrarBitacoraVisitantes(string bitacoraVisitantes[][COLUMNAS_VISITANTES], int totalVisitantes);

#endif