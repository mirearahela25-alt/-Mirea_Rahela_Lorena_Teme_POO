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

    Angajat& operator=(const Angajat& a) {
        if (this != &a) {
            nume = a.nume;
            varsta = a.varsta;
            salariu = a.salariu;
        }
        return *this;
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
    Angajat b("Maria", 30, 4000);

    Angajat* p = &a;

    cout << "Date initiale:" << endl;
    p->afisare();

    p->marireSalariu(10);

    cout << "Dupa marirea salariului:" << endl;
    p->afisare();

    b = a;

    cout << "Dupa atribuire:" << endl;
    b.afisare();

    return 0;
}
