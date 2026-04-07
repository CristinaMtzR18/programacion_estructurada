#include <iostream>
#include <limits>
using namespace std;

// Variable principal que lleva el conteo de equipos disponibles
int totalEquiposDisponibles = 20;

// Esta función muestra el banner institucional, la bienvenida
// y algunas reglas básicas para el uso del laboratorio.
void mostrarBienvenida()
{
    cout << "==============================================" << endl;
    cout << " UNIVERSIDAD NACIONAL ROSARIO CASTELLANOS" << endl;
    cout << " Sistema de acceso al laboratorio - UNRC" << endl;
    cout << "==============================================" << endl;
    cout << "Bienvenida y bienvenido al laboratorio." << endl;
    cout << "Reglas de uso:" << endl;
    cout << "1. No introducir alimentos." << endl;
    cout << "2. Cuidar el equipo asignado." << endl;
    cout << "3. Respetar el horario del laboratorio." << endl;
    cout << "==============================================" << endl;
}

// Esta función valida primero que la hora exista en formato 24 horas.
// Después devuelve true solo si está dentro del horario permitido.
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

// Esta función valida que el ID del estudiante sea mayor que 0
// y menor o igual a 1000. El dato se recibe por valor.
bool validarIDEstudiante(int idEstudiante)
{
    return (idEstudiante > 0 && idEstudiante <= 1000);
}

// Esta función resta una unidad al total de equipos disponibles.
// Se usa referencia para modificar la variable original.
void asignarEquipo(int &totalEquipos)
{
    if (totalEquipos > 0)
    {
        totalEquipos--;
        cout << "Equipo asignado correctamente." << endl;
        cout << "Equipos disponibles: " << totalEquipos << endl;
    }
    else
    {
        cout << "No hay equipos disponibles." << endl;
    }
}

int main()
{
    int identificadorUsuario;
    int horaEntrada;

    mostrarBienvenida();

    cout << "Ingrese el ID del usuario: ";
    cin >> identificadorUsuario;

    while (cin.fail() || !validarIDEstudiante(identificadorUsuario))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Error: el ID debe ser un numero mayor que 0 y menor o igual a 1000." << endl;
        cout << "Ingrese nuevamente el ID del usuario: ";
        cin >> identificadorUsuario;
    }

    cout << "Ingrese la hora de entrada (0-23): ";
    cin >> horaEntrada;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: ingrese una hora numerica valida: ";
        cin >> horaEntrada;
    }

    if (validarHorario(horaEntrada))
    {
        cout << "Horario permitido. Registro autorizado." << endl;
        asignarEquipo(totalEquiposDisponibles);
    }
    else
    {
        cout << "No se permite el uso de equipos fuera del horario establecido." << endl;
    }

    return 0;
}