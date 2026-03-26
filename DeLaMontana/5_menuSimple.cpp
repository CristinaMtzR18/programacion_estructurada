#include <iostream>
using namespace std;

int main() {

    int opcion;

    cout << "1 Registrar" << endl;
    cout << "2 Consultar" << endl;
    cout << "3 Salir" << endl;

    cin >> opcion;

    switch(opcion) {

        case 1:
            cout << "Registrando..." << endl;
            break;

        case 2:
            cout << "Consultando..." << endl;
            break;

        case 3:
            cout << "Saliendo..." << endl;
            break;

        default:
            cout << "Opcion incorrecta" << endl;
    }

    return 0;
}