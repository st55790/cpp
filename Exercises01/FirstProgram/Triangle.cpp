#include <iostream>
using namespace std;

int main() {
    
    double a, b, c;
    char repeat = 'n';

    cout << "Test, zda lze sestrojit trojuhelnik" << endl;

    while(repeat != 'y'){

        cout << "Zadej stranu A:";
        cin >> a;
        cout << "Zadej stranu B:";
        cin >> b;
        cout << "Zadej stranu C:";
        cin >> c;

        if (a < 0|| b < 0 || c < 0) {
            cout << "Zadal si neplatne parametry" << endl;
        }
        if ((a + b > c) && (a + c > b) && (b+c > a)) {
            cout << "Trojuhelnik lze sestrojit" << endl;
            int o = a + b + c;
            cout << "Obvod tohoto trojuhelniku je " << o << endl;
        }
        else {
            cout << "Trojuhelnik nelze sestrojit" << endl;
        }

        cout << "Konec programu y/n:";
        cin >> repeat;
    }

    return 0;
}
