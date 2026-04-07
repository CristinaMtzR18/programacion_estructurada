#include <iostream>
#include <limits>
using namespace std;

// ------------------------------------------------------------
// VARIABLE GLOBAL
// ------------------------------------------------------------
// Esta variable guarda el total de equipos disponibles en el laboratorio.
// Se inicia en 20 porque el laboratorio cuenta con 20 computadoras.
int totalEquiposDisponibles = 20;

// ------------------------------------------------------------
// FUNCION: mostrarBienvenida
// TIPO DE RETORNO: void
// PARAMETROS: ninguno
// PROPOSITO:
// Mostrar un banner institucional, un mensaje de bienvenida
// y algunas reglas de uso del laboratorio.
// ------------------------------------------------------------
void mostrarBienvenida()
{
    cout << "\n====================================================" << endl;
    cout << " UNIVERSIDAD NACIONAL ROSARIO CASTELLANOS - UNRC" << endl;
    cout << " Sistema de acceso al laboratorio de computo" << endl;
    cout << "====================================================" << endl;
    cout << "Bienvenida y bienvenido al sistema de registro." << endl;
    cout << "Reglas de uso del laboratorio:" << endl;
    cout << "1. No introducir alimentos ni bebidas." << endl;
    cout << "2. Cuidar el equipo asignado." << endl;
    cout << "3. Respetar el horario establecido." << endl;
    cout << "4. Usar el equipo solo con fines academicos." << endl;
    cout << "====================================================" << endl;
}

// ------------------------------------------------------------
// FUNCION: validarHorario
// TIPO DE RETORNO: bool
// PARAMETROS: int hora
// PROPOSITO:
// Validar que la hora exista en formato de 24 horas (0 a 23)
// y devolver true solo si se encuentra dentro del horario
// permitido, que es de 08:00 a 20:00.
// ------------------------------------------------------------
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
// TIPO DE RETORNO: bool
// PARAMETROS: int idEstudiante
// PROPOSITO:
// Validar que el ID del estudiante sea mayor que 0 y
// menor o igual a 1000.
// El parametro se recibe por valor.
// ------------------------------------------------------------
bool validarIDEstudiante(int idEstudiante)
{
    return (idEstudiante > 0 && idEstudiante <= 1000);
}

// ------------------------------------------------------------
// FUNCION: asignarEquipo
// TIPO DE RETORNO: void
// PARAMETROS: int &totalEquipos
// PROPOSITO:
// Restar una unidad al total de equipos disponibles.
// Se usa referencia para modificar la variable original.
// ------------------------------------------------------------
void asignarEquipo(int &totalEquipos)
{
    if (totalEquipos > 0)
    {
        totalEquipos--;
        cout << "Equipo asignado correctamente." << endl;
        cout << "Equipos disponibles ahora: " << totalEquipos << endl;
    }
    else
    {
        cout << "No hay equipos disponibles en este momento." << endl;
    }
}

// ------------------------------------------------------------
// FUNCION PRINCIPAL
// ------------------------------------------------------------
int main()
{
    // Variables locales del programa
    int opcionMenu;
    int identificadorUsuario;
    int numeroComputadora;
    int tiempoUsoMinutos;
    int nivelEstudioSeleccionado;
    int horaEntrada;
    char deseaContinuar;

    // Primero mostramos la bienvenida institucional.
    mostrarBienvenida();

    // Ciclo principal del sistema.
    do
    {
        cout << "\n========================================" << endl;
        cout << "   SISTEMA DE ACCESO SIG-CONECTA" << endl;
        cout << "========================================" << endl;
        cout << "1. Registrar ingreso" << endl;
        cout << "2. Consultar disponibilidad de equipos" << endl;
        cout << "3. Salir del sistema" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionMenu;

        // Validacion por si el usuario escribe algo que no sea numero.
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: debe ingresar una opcion numerica (1, 2 o 3): ";
            cin >> opcionMenu;
        }

        switch (opcionMenu)
        {
            case 1:
                cout << "\n--- REGISTRO DE INGRESO ---" << endl;

                // ------------------------------------------------
                // VALIDACION DEL ID DEL USUARIO
                // ------------------------------------------------
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

                // ------------------------------------------------
                // VALIDACION DE HORA DE ENTRADA
                // ------------------------------------------------
                cout << "Ingrese la hora de entrada en formato 24 horas (0-23): ";
                cin >> horaEntrada;

                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: ingrese una hora numerica valida entre 0 y 23: ";
                    cin >> horaEntrada;
                }

                if (!validarHorario(horaEntrada))
                {
                    cout << "No se permite el uso de equipos fuera del horario establecido (08:00 a 20:00)." << endl;
                    break;
                }

                // ------------------------------------------------
                // VALIDACION DE NUMERO DE PC
                // ------------------------------------------------
                cout << "Ingrese el numero de PC (1 a 20): ";
                cin >> numeroComputadora;

                while (cin.fail() || numeroComputadora < 1 || numeroComputadora > 20)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: el numero de PC debe estar entre 1 y 20. Intente de nuevo: ";
                    cin >> numeroComputadora;
                }

                // ------------------------------------------------
                // VALIDACION DEL TIEMPO DE USO
                // ------------------------------------------------
                cout << "Ingrese el tiempo de uso en minutos: ";
                cin >> tiempoUsoMinutos;

                while (cin.fail() || tiempoUsoMinutos <= 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Error: el tiempo de uso debe ser mayor que 0. Intente de nuevo: ";
                    cin >> tiempoUsoMinutos;
                }

                // ------------------------------------------------
                // VALIDACION DEL NIVEL DE ESTUDIO
                // ------------------------------------------------
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
                    cout << "Error: opcion invalida. Seleccione un nivel del 1 al 4: ";
                    cin >> nivelEstudioSeleccionado;
                }

                // ------------------------------------------------
                // ASIGNACION DE EQUIPO
                // ------------------------------------------------
                if (totalEquiposDisponibles > 0)
                {
                    asignarEquipo(totalEquiposDisponibles);
                }
                else
                {
                    cout << "No se puede realizar el registro porque no hay equipos disponibles." << endl;
                    break;
                }

                // ------------------------------------------------
                // RESUMEN DEL REGISTRO
                // ------------------------------------------------
                cout << "\nRegistro guardado exitosamente." << endl;
                cout << "Resumen del acceso:" << endl;
                cout << "ID del usuario: " << identificadorUsuario << endl;
                cout << "Hora de entrada: " << horaEntrada << ":00 hrs" << endl;
                cout << "Numero de PC: " << numeroComputadora << endl;
                cout << "Tiempo de uso: " << tiempoUsoMinutos << " minutos" << endl;

                if (nivelEstudioSeleccionado == 1)
                {
                    cout << "Nivel de estudio: Primaria" << endl;
                }
                else if (nivelEstudioSeleccionado == 2)
                {
                    cout << "Nivel de estudio: Secundaria" << endl;
                }
                else if (nivelEstudioSeleccionado == 3)
                {
                    cout << "Nivel de estudio: Bachillerato" << endl;
                }
                else
                {
                    cout << "Nivel de estudio: Universidad" << endl;
                }

                break;

            case 2:
                cout << "\n--- DISPONIBILIDAD DE EQUIPOS ---" << endl;
                cout << "Actualmente hay " << totalEquiposDisponibles << " equipos disponibles." << endl;
                break;

            case 3:
                cout << "\nCerrando el sistema..." << endl;
                break;

            default:
                cout << "\nError: opcion invalida. Por favor, seleccione 1, 2 o 3." << endl;
                break;
        }

        // --------------------------------------------------------
        // CONTROL DE CONTINUIDAD
        // --------------------------------------------------------
        if (opcionMenu != 3)
        {
            cout << "\nDesea registrar otro acceso? (S/N): ";
            cin >> deseaContinuar;

            while (deseaContinuar != 'S' && deseaContinuar != 's' &&
                   deseaContinuar != 'N' && deseaContinuar != 'n')
            {
                cout << "Error: escriba solo S o N: ";
                cin >> deseaContinuar;
            }
        }
        else
        {
            deseaContinuar = 'N';
        }

    } while (deseaContinuar == 'S' || deseaContinuar == 's');

    cout << "\nFin de la jornada de registro local." << endl;

    return 0;
}