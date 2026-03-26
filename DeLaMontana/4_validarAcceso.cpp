#include <iostream>
using namespace std;

int main() {

    int edad;

    cout << "Ingrese edad: ";
    cin >> edad;

    if (edad >= 18) {
        cout << "Acceso autorizado" << endl;
    } else {
        cout << "Acceso denegado" << endl;
    }

    return 0;
}