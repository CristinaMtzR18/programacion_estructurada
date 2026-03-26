#include <iostream>
using namespace std;

int main() {

    int equipo;
    int bateria;

    cout << "Numero de equipo: ";
    cin >> equipo;

    cout << "Nivel de bateria: ";
    cin >> bateria;

    cout << "Equipo " << equipo << " listo para trabajar" << endl;
    cout << "Bateria: " << bateria << "%" << endl;

    return 0;
}