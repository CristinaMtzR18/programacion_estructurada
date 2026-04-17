#include <iostream>
#include <limits>
#include "visitantes.h"
#include "equipos.h"

using namespace std;

bool validarHorario(int hora)
{
    if (hora < 0 || hora > 23)
    {
        cout << "Error: la hora debe estar entre 0 y 23." << endl;
        return false;
    }

    if (hora >= 8 && hora <= 20)
    {
        return true;
    }

    return false;
}

bool validarIDVisitante(int id)
{
    return (id > 0 && id <= 1000);
}

string obtenerNivelEstudio(int nivel)
{
    if (nivel == 1) return "Primaria";
    if (nivel == 2) return "Secundaria";
    if (nivel == 3) return "Bachillerato";
    return "Universidad";
}

void registrarVisitante(int equipos[], string bitacoraVisitantes[][COLUMNAS_VISITANTES], int &totalVisitantes)
{
    if (totalVisitantes >= MAX_VISITANTES)
    {
        cout << "La bitacora de visitantes ya esta llena." << endl;
        return;
    }

    int idVisitante;
    string nombreVisitante;
    int horaEntrada;
    int tiempoUso;
    int nivelEstudio;
    int numeroEquipo;

    cout << "\n--- REGISTRO DE VISITANTE ---" << endl;

    cout << "Ingrese el ID del visitante: ";
    cin >> idVisitante;

    while (cin.fail() || !validarIDVisitante(idVisitante))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: el ID debe ser un numero mayor que 0 y menor o igual a 1000: ";
        cin >> idVisitante;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese el nombre del visitante: ";
    getline(cin, nombreVisitante);

    while (nombreVisitante.empty())
    {
        cout << "Error: el nombre no puede quedar vacio. Intente de nuevo: ";
        getline(cin, nombreVisitante);
    }

    cout << "Ingrese la hora de entrada en formato 24 horas (0-23): ";
    cin >> horaEntrada;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: escribe una hora numerica valida entre 0 y 23: ";
        cin >> horaEntrada;
    }

    if (!validarHorario(horaEntrada))
    {
        cout << "No se permite registrar visitantes fuera del horario establecido (08:00 a 20:00)." << endl;
        return;
    }

    cout << "Ingrese el tiempo de uso en minutos: ";
    cin >> tiempoUso;

    while (cin.fail() || tiempoUso <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: el tiempo de uso debe ser un numero mayor que 0: ";
        cin >> tiempoUso;
    }

    cout << "Nivel de estudio:" << endl;
    cout << "1. Primaria" << endl;
    cout << "2. Secundaria" << endl;
    cout << "3. Bachillerato" << endl;
    cout << "4. Universidad" << endl;
    cout << "Seleccione una opcion: ";
    cin >> nivelEstudio;

    while (cin.fail() || nivelEstudio < 1 || nivelEstudio > 4)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: selecciona una opcion del 1 al 4: ";
        cin >> nivelEstudio;
    }

    cout << "Ingrese el numero de equipo asignado (1-20): ";
    cin >> numeroEquipo;

    while (cin.fail() || !validarNumeroEquipo(numeroEquipo))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: el numero de equipo debe estar entre 1 y 20: ";
        cin >> numeroEquipo;
    }

    while (equipos[numeroEquipo - 1] != 0)
    {
        cout << "Ese equipo no esta libre. Elija otro equipo disponible (1-20): ";
        cin >> numeroEquipo;

        while (cin.fail() || !validarNumeroEquipo(numeroEquipo))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: el numero de equipo debe estar entre 1 y 20: ";
            cin >> numeroEquipo;
        }
    }

    equipos[numeroEquipo - 1] = 1;

    bitacoraVisitantes[totalVisitantes][0] = to_string(idVisitante);
    bitacoraVisitantes[totalVisitantes][1] = nombreVisitante;
    bitacoraVisitantes[totalVisitantes][2] = to_string(horaEntrada);
    bitacoraVisitantes[totalVisitantes][3] = to_string(tiempoUso);
    bitacoraVisitantes[totalVisitantes][4] = obtenerNivelEstudio(nivelEstudio);
    bitacoraVisitantes[totalVisitantes][5] = to_string(numeroEquipo);

    totalVisitantes++;
    cout << "Visitante registrado correctamente." << endl;
}

void mostrarBitacoraVisitantes(string bitacoraVisitantes[][COLUMNAS_VISITANTES], int totalVisitantes)
{
    cout << "\n--- BITACORA DE VISITANTES ---" << endl;

    if (totalVisitantes == 0)
    {
        cout << "No hay visitantes registrados." << endl;
        return;
    }

    for (int i = 0; i < totalVisitantes; i++)
    {
        cout << "\nRegistro " << (i + 1) << endl;
        cout << "ID: " << bitacoraVisitantes[i][0] << endl;
        cout << "Nombre: " << bitacoraVisitantes[i][1] << endl;
        cout << "Hora de entrada: " << bitacoraVisitantes[i][2] << ":00 hrs" << endl;
        cout << "Tiempo de uso: " << bitacoraVisitantes[i][3] << " minutos" << endl;
        cout << "Nivel de estudio: " << bitacoraVisitantes[i][4] << endl;
        cout << "Equipo asignado: " << bitacoraVisitantes[i][5] << endl;
    }
}