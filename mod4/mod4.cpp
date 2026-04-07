#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

// ------------------------------------------------------------
// CONSTANTES
// ------------------------------------------------------------
// TOTAL_EQUIPOS representa la cantidad total de computadoras
// disponibles en el laboratorio.
const int TOTAL_EQUIPOS = 20;

// MAX_REGISTROS representa el numero maximo de visitantes
// que se guardaran en la bitacora diaria.
const int MAX_REGISTROS = 10;

// COLUMNAS_BITACORA representa cuantas columnas tendra
// la matriz bidimensional de la bitacora.
const int COLUMNAS_BITACORA = 6;

// ------------------------------------------------------------
// FUNCION: mostrarBienvenida
// ------------------------------------------------------------
// Esta funcion muestra el encabezado del sistema y las
// reglas principales del laboratorio.
void mostrarBienvenida()
{
    cout << "\n====================================================" << endl;
    cout << " UNIVERSIDAD NACIONAL ROSARIO CASTELLANOS - UNRC" << endl;
    cout << " Sistema de control y bitacora de visitantes" << endl;
    cout << "====================================================" << endl;
    cout << "Bienvenida y bienvenido al laboratorio de computo." << endl;
    cout << "Reglas de uso del laboratorio:" << endl;
    cout << "1. No introducir alimentos ni bebidas." << endl;
    cout << "2. Cuidar el equipo asignado." << endl;
    cout << "3. Respetar el horario establecido." << endl;
    cout << "4. Usar el equipo solo con fines academicos." << endl;
    cout << "====================================================" << endl;
}

// ------------------------------------------------------------
// FUNCION: validarHorario
// ------------------------------------------------------------
// Esta funcion revisa si la hora esta en formato correcto
// de 24 horas y si se encuentra dentro del horario permitido.
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

// ------------------------------------------------------------
// FUNCION: validarIDEstudiante
// ------------------------------------------------------------
// Esta funcion revisa que el ID sea mayor que 0 y menor
// o igual a 1000.
bool validarIDEstudiante(int idEstudiante)
{
    return (idEstudiante > 0 && idEstudiante <= 1000);
}

// ------------------------------------------------------------
// FUNCION: obtenerNivelEstudio
// ------------------------------------------------------------
// Esta funcion convierte el numero del nivel de estudio
// en una palabra mas facil de entender.
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

// ------------------------------------------------------------
// FUNCION: mostrarEquiposDisponibles
// ------------------------------------------------------------
// Esta funcion recorre el arreglo de equipos.
// Si encuentra 0, significa disponible.
// Si encuentra 1, significa ocupado.
void mostrarEquiposDisponibles(int equipos[])
{
    int cantidadDisponibles = 0;

    cout << "\n--- ESTADO DE LOS EQUIPOS ---" << endl;

    for (int i = 0; i < TOTAL_EQUIPOS; i++)
    {
        cout << "Equipo " << (i + 1) << ": ";

        if (equipos[i] == 0)
        {
            cout << "Disponible" << endl;
            cantidadDisponibles++;
        }
        else
        {
            cout << "Ocupado" << endl;
        }
    }

    cout << "Total de equipos disponibles: " << cantidadDisponibles << endl;
}

// ------------------------------------------------------------
// FUNCION: asignarEquipo
// ------------------------------------------------------------
// Esta funcion revisa si el equipo solicitado esta libre.
// Si esta libre, cambia su valor de 0 a 1.
// Si ya estaba ocupado, no lo asigna.
bool asignarEquipo(int equipos[], int numeroEquipo)
{
    if (numeroEquipo < 1 || numeroEquipo > TOTAL_EQUIPOS)
    {
        cout << "Error: el numero de equipo debe estar entre 1 y 20." << endl;
        return false;
    }

    if (equipos[numeroEquipo - 1] == 0)
    {
        equipos[numeroEquipo - 1] = 1;
        return true;
    }
    else
    {
        cout << "Ese equipo ya esta ocupado. Debe elegir otro." << endl;
        return false;
    }
}

// ------------------------------------------------------------
// FUNCION: registrarVisitante
// ------------------------------------------------------------
// Esta funcion registra a un visitante en la bitacora.
// La bitacora es una matriz bidimensional de 10 filas y 6 columnas.
// Columnas:
// 0 = ID
// 1 = Nombre
// 2 = Hora de entrada
// 3 = Tiempo de uso
// 4 = Nivel de estudio
// 5 = Equipo asignado
void registrarVisitante(int equipos[], string bitacora[][COLUMNAS_BITACORA], int &totalRegistros)
{
    if (totalRegistros >= MAX_REGISTROS)
    {
        cout << "La bitacora diaria ya esta llena. Solo se permiten 10 registros por dia." << endl;
        return;
    }

    int identificadorUsuario;
    string nombreUsuario;
    int horaEntrada;
    int tiempoUso;
    int nivelEstudioSeleccionado;
    int numeroEquipo;

    cout << "\n--- REGISTRO DE VISITANTE ---" << endl;

    // --------------------------------------------------------
    // VALIDACION DEL ID
    // --------------------------------------------------------
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

    // Limpiar el buffer antes de usar getline para el nombre.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // --------------------------------------------------------
    // NOMBRE DEL USUARIO
    // --------------------------------------------------------
    cout << "Ingrese el nombre del usuario: ";
    getline(cin, nombreUsuario);

    // --------------------------------------------------------
    // VALIDACION DE HORA
    // --------------------------------------------------------
    cout << "Ingrese la hora de entrada (0-23): ";
    cin >> horaEntrada;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: ingrese una hora numerica valida: ";
        cin >> horaEntrada;
    }

    if (!validarHorario(horaEntrada))
    {
        cout << "No se permite el acceso fuera del horario establecido (08:00 a 20:00)." << endl;
        return;
    }

    // --------------------------------------------------------
    // TIEMPO DE USO
    // --------------------------------------------------------
    cout << "Ingrese el tiempo de uso en minutos: ";
    cin >> tiempoUso;

    while (cin.fail() || tiempoUso <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: el tiempo de uso debe ser un numero mayor que 0: ";
        cin >> tiempoUso;
    }

    // --------------------------------------------------------
    // NIVEL DE ESTUDIO
    // --------------------------------------------------------
    cout << "Nivel de estudio:" << endl;
    cout << "1. Primaria" << endl;
    cout << "2. Secundaria" << endl;
    cout << "3. Bachillerato" << endl;
    cout << "4. Universidad" << endl;
    cout << "Seleccione una opcion: ";
    cin >> nivelEstudioSeleccionado;

    while (cin.fail() || nivelEstudioSeleccionado < 1 || nivelEstudioSeleccionado > 4)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: seleccione una opcion valida del 1 al 4: ";
        cin >> nivelEstudioSeleccionado;
    }

    // --------------------------------------------------------
    // NUMERO DE EQUIPO
    // --------------------------------------------------------
    cout << "Ingrese el numero de equipo que desea usar (1-20): ";
    cin >> numeroEquipo;

    while (cin.fail() || numeroEquipo < 1 || numeroEquipo > 20)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: el numero de equipo debe estar entre 1 y 20. Intente de nuevo: ";
        cin >> numeroEquipo;
    }

    // Si el equipo ya esta ocupado, se vuelve a pedir otro.
    while (!asignarEquipo(equipos, numeroEquipo))
    {
        cout << "Ingrese otro numero de equipo: ";
        cin >> numeroEquipo;

        while (cin.fail() || numeroEquipo < 1 || numeroEquipo > 20)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: el numero de equipo debe estar entre 1 y 20. Intente de nuevo: ";
            cin >> numeroEquipo;
        }
    }

    // --------------------------------------------------------
    // GUARDAR EN LA BITACORA BIDIMENSIONAL
    // --------------------------------------------------------
    bitacora[totalRegistros][0] = to_string(identificadorUsuario);
    bitacora[totalRegistros][1] = nombreUsuario;
    bitacora[totalRegistros][2] = to_string(horaEntrada);
    bitacora[totalRegistros][3] = to_string(tiempoUso);
    bitacora[totalRegistros][4] = obtenerNivelEstudio(nivelEstudioSeleccionado);
    bitacora[totalRegistros][5] = to_string(numeroEquipo);

    totalRegistros++;

    // --------------------------------------------------------
    // RESUMEN DEL REGISTRO
    // --------------------------------------------------------
    cout << "\nRegistro guardado correctamente en la bitacora." << endl;
    cout << "Resumen del registro:" << endl;
    cout << "ID: " << identificadorUsuario << endl;
    cout << "Nombre: " << nombreUsuario << endl;
    cout << "Hora de entrada: " << horaEntrada << ":00 hrs" << endl;
    cout << "Tiempo de uso: " << tiempoUso << " minutos" << endl;
    cout << "Nivel de estudio: " << obtenerNivelEstudio(nivelEstudioSeleccionado) << endl;
    cout << "Equipo asignado: " << numeroEquipo << endl;
}

// ------------------------------------------------------------
// FUNCION: mostrarBitacora
// ------------------------------------------------------------
// Esta funcion muestra en pantalla todos los registros
// guardados en la matriz bidimensional.
void mostrarBitacora(string bitacora[][COLUMNAS_BITACORA], int totalRegistros)
{
    cout << "\n--- BITACORA DEL DIA ---" << endl;

    if (totalRegistros == 0)
    {
        cout << "No hay registros guardados en la bitacora." << endl;
        return;
    }

    for (int i = 0; i < totalRegistros; i++)
    {
        cout << "Registro " << (i + 1) << endl;
        cout << "ID: " << bitacora[i][0] << endl;
        cout << "Nombre: " << bitacora[i][1] << endl;
        cout << "Hora de entrada: " << bitacora[i][2] << ":00 hrs" << endl;
        cout << "Tiempo de uso: " << bitacora[i][3] << " minutos" << endl;
        cout << "Nivel de estudio: " << bitacora[i][4] << endl;
        cout << "Equipo asignado: " << bitacora[i][5] << endl;
        cout << "--------------------------------------------" << endl;
    }
}

// ------------------------------------------------------------
// FUNCION: generar_reporte
// ------------------------------------------------------------
// Esta funcion crea el archivo reporte_dia.txt y guarda
// toda la informacion de la bitacora.
void generar_reporte(string bitacora[][COLUMNAS_BITACORA], int totalRegistros)
{
    ofstream archivo("reporte_dia.txt");

    if (!archivo)
    {
        cout << "Error: no se pudo crear el archivo reporte_dia.txt" << endl;
        return;
    }

    archivo << "UNIVERSIDAD NACIONAL ROSARIO CASTELLANOS - UNRC" << endl;
    archivo << "REPORTE DIARIO DE VISITANTES" << endl;
    archivo << "============================================" << endl;

    if (totalRegistros == 0)
    {
        archivo << "No hay registros en la bitacora." << endl;
    }
    else
    {
        for (int i = 0; i < totalRegistros; i++)
        {
            archivo << "Registro " << (i + 1) << endl;
            archivo << "ID: " << bitacora[i][0] << endl;
            archivo << "Nombre: " << bitacora[i][1] << endl;
            archivo << "Hora de entrada: " << bitacora[i][2] << ":00 hrs" << endl;
            archivo << "Tiempo de uso: " << bitacora[i][3] << " minutos" << endl;
            archivo << "Nivel de estudio: " << bitacora[i][4] << endl;
            archivo << "Equipo asignado: " << bitacora[i][5] << endl;
            archivo << "--------------------------------------------" << endl;
        }
    }

    archivo.close();
    cout << "El archivo reporte_dia.txt se genero correctamente." << endl;
}

// ------------------------------------------------------------
// FUNCION: consultar_reporte
// ------------------------------------------------------------
// Esta funcion abre el archivo reporte_dia.txt y muestra
// su contenido en pantalla.
void consultar_reporte()
{
    ifstream archivo("reporte_dia.txt");

    if (!archivo)
    {
        cout << "Error: no se pudo abrir el archivo reporte_dia.txt" << endl;
        return;
    }

    string linea;

    cout << "\n--- CONTENIDO DEL REPORTE ---" << endl;

    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
}

// ------------------------------------------------------------
// FUNCION PRINCIPAL
// ------------------------------------------------------------
int main()
{
    int opcionMenu;

    // Arreglo unidimensional de equipos.
    // 0 = disponible
    // 1 = ocupado
    int equipos[TOTAL_EQUIPOS] = {0};

    // Matriz bidimensional para la bitacora.
    // Filas = visitantes
    // Columnas = datos del visitante
    string bitacora[MAX_REGISTROS][COLUMNAS_BITACORA];

    // Contador de registros guardados.
    int totalRegistros = 0;

    mostrarBienvenida();

    do
    {
        cout << "\n========================================" << endl;
        cout << "   MENU PRINCIPAL DEL SISTEMA" << endl;
        cout << "========================================" << endl;
        cout << "1. Registrar visitante" << endl;
        cout << "2. Ver equipos disponibles" << endl;
        cout << "3. Mostrar bitacora diaria" << endl;
        cout << "4. Generar reporte del dia" << endl;
        cout << "5. Consultar reporte guardado" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: debe ingresar una opcion numerica valida: ";
            cin >> opcionMenu;
        }

        switch (opcionMenu)
        {
            case 1:
                registrarVisitante(equipos, bitacora, totalRegistros);
                break;

            case 2:
                mostrarEquiposDisponibles(equipos);
                break;

            case 3:
                mostrarBitacora(bitacora, totalRegistros);
                break;

            case 4:
                generar_reporte(bitacora, totalRegistros);
                break;

            case 5:
                consultar_reporte();
                break;

            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Error: opcion invalida. Seleccione del 1 al 6." << endl;
                break;
        }

    } while (opcionMenu != 6);

    cout << "Fin de la jornada de registro local." << endl;

    return 0;
}