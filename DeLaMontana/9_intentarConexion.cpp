#include <iostream>
using namespace std;

void intentarConexion(int intentos) {

    if(intentos > 0) {
        cout << "Intentando conectar..." << endl;
        intentarConexion(intentos - 1);
    }
}

int main() {
    int intentos;

    cout << "Ingrese cantidad de intentos: ";
    cin >> intentos;
    intentarConexion(intentos);

    return 0;
}