#include <iostream>
#include <string>
using namespace std;

class Angajat {
private:
    string nume;
    int varsta;
    double salariu;

public:
    Angajat(string n, int v, double s) {
        nume = n;
        varsta = v;
        salariu = s;
    }

    void afisare() {
        cout << "Nume: " << nume << endl;
        cout << "Varsta: " << varsta << endl;
        cout << "Salariu: " << salariu << endl;
    }

    void marireSalariu(double procent) {
        salariu += salariu * procent / 100;
    }
};

int main() {
    Angajat a("Ion", 25, 3000);

    cout << "Date initiale:" << endl;
    a.afisare();

    a.marireSalariu(10);

    cout << "Dupa marirea salariului:" << endl;
    a.afisare();

    return 0;
}
