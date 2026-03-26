#include <iostream>
using namespace std;

int capturarEdad() {

    int edad;

    cout << "Ingrese edad: ";
    cin >> edad;

    return edad;
}

int main() {

    int edad;

    edad = capturarEdad();

    cout << "Edad capturada: " << edad << endl;

    return 0;
}