#include <iostream>
using namespace std;

void intentarConexion(int intentos) {

    if(intentos > 0) {
        cout << "Intentando conectar..." << endl;
        intentarConexion(intentos - 1);
    }
}

int main() {

    intentarConexion(3);

    return 0;
}