//Comentairos
#include <iostream>
#include <limits>
#include "equipos.h"
#include "visitantes.h"
#include "incidentes.h"
#include "archivos.h"
#include "utilidades.h"

using namespace std;

int main()
{
    int opcion;
    int equipos[TOTAL_EQUIPOS] = {0};
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