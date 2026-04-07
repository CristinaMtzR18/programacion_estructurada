#include <iostream>
using namespace std;

void alertaBateria(int nivel) {

    if(nivel < 20) {
        cout << "Bateria critica" << endl;
    }
}

int main() {

    int bateria;

    cout << "Ingrese bateria: ";
    cin >> bateria;

    alertaBateria(bateria);
    return 0;
}