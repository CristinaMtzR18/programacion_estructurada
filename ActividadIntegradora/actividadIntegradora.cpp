#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

const int TOTAL_EQUIPOS = 20;
const int MAX_VISITANTES = 50;
const int MAX_INCIDENTES = 100;
const int COLUMNAS_VISITANTES = 6;

struct RegistroBitacora
{
    int idEquipo;
    string hora;
    string tipoIncidente;
    string descripcion;
};

// Prototipos
void mostrarBienvenida();
void mostrarMenu();

bool validarHorario(int hora);
bool validarIDVisitante(int id);
bool validarNumeroEquipo(int numeroEquipo);
string obtenerTextoEstado(int estado);
string obtenerNivelEstudio(int nivel);

void mostrarEstadoEquipos(int equipos[]);
void cambiarEstadoEquipo(int equipos[]);

void registrarVisitante(int equipos[], string bitacoraVisitantes[][COLUMNAS_VISITANTES], int &totalVisitantes);
void mostrarBitacoraVisitantes(string bitacoraVisitantes[][COLUMNAS_VISITANTES], int totalVisitantes);

void registrarIncidente(RegistroBitacora bitacoraIncidentes[], int &totalIncidentes);
void mostrarHistorialIncidentes(RegistroBitacora bitacoraIncidentes[], int totalIncidentes);

void guardarDatos(int equipos[],
                  string bitacoraVisitantes[][COLUMNAS_VISITANTES], int totalVisitantes,
                  RegistroBitacora bitacoraIncidentes[], int totalIncidentes);

void cargarDatos(int equipos[],
                 string bitacoraVisitantes[][COLUMNAS_VISITANTES], int &totalVisitantes,
                 RegistroBitacora bitacoraIncidentes[], int &totalIncidentes);

int main()
{
    int opcion;
    int equipos[TOTAL_EQUIPOS] = {0}; // 0 libre, 1 ocupada, 2 mantenimiento
    string bitacoraVisitantes[MAX_VISITANTES][COLUMNAS_VISITANTES];
    RegistroBitacora bitacoraIncidentes[MAX_INCIDENTES];
    int totalVisitantes = 0;
    int totalIncidentes = 0;

    mostrarBienvenida();
    cargarDatos(equipos, bitacoraVisitantes, totalVisitantes, bitacoraIncidentes, totalIncidentes);

    do
    {
        mostrarMenu();
        cin >> opcion;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: escribe una opcion numerica valida: ";
            cin >> opcion;
        }

        switch (opcion)
        {
            case 1:
                mostrarEstadoEquipos(equipos);
                break;

            case 2:
                cambiarEstadoEquipo(equipos);
                break;

            case 3:
                registrarVisitante(equipos, bitacoraVisitantes, totalVisitantes);
                break;

            case 4:
                mostrarBitacoraVisitantes(bitacoraVisitantes, totalVisitantes);
                break;

            case 5:
                registrarIncidente(bitacoraIncidentes, totalIncidentes);
                break;

            case 6:
                mostrarHistorialIncidentes(bitacoraIncidentes, totalIncidentes);
                break;

            case 7:
                guardarDatos(equipos, bitacoraVisitantes, totalVisitantes, bitacoraIncidentes, totalIncidentes);
                cout << "\nDatos guardados correctamente. Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Error: opcion no valida." << endl;
                break;
        }

    } while (opcion != 7);

    return 0;
}

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

bool validarNumeroEquipo(int numeroEquipo)
{
    return (numeroEquipo >= 1 && numeroEquipo <= 20);
}

string obtenerTextoEstado(int estado)
{
    if (estado == 0)
    {
        return "Libre";
    }
    else if (estado == 1)
    {
        return "Ocupada";
    }
    else
    {
        return "Mantenimiento";
    }
}

string obtenerNivelEstudio(int nivel)
{
    if (nivel == 1)
    {
        return "Primaria";
    }
    else if (nivel == 2)
    {
        return "Secundaria";
    }
    else if (nivel == 3)
    {
        return "Bachillerato";
    }
    else
    {
        return "Universidad";
    }
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
    int numeroEquipo;
    int nuevoEstado;

    cout << "\nIngrese el numero de equipo (1-20): ";
    cin >> numeroEquipo;

    while (cin.fail() || !validarNumeroEquipo(numeroEquipo))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: escribe un numero de equipo entre 1 y 20: ";
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