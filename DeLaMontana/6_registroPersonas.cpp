#include <iostream>
using namespace std;

int main() {

    int edad;
    int mayores = 0;

    for(int i = 1; i <= 5; i++) {

        cout << "Edad de persona " << i << ": ";
        cin >> edad;

        if(edad >= 18) {
            mayores++;
        }
    }

    cout << "Mayores registrados: " << mayores << endl;

    return 0;
}