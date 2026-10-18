#include <iostream>
#include <string>

using namespace std;

class Casa {
private:
    const int adresa;           // numarul adresei (int, nu string), inlocuieste id-ul
    string oras;
    float pret;
    float suprafata;
    int nrCamere;
    float* suprafataCamere;     // vector alocat dinamic

public:
    static int nrCase;

    // constructor fara parametri (default)
    Casa() : adresa(0) {
        this->oras = "Necunoscut";
        this->pret = 0;
        this->suprafata = 0;
        this->nrCamere = 0;
        this->suprafataCamere = nullptr;
        nrCase++;
    }

    // constructor cu toti parametrii
    Casa(int adresa, string oras, float pret, float suprafata, int nrCamere, float* suprafataCamere) : adresa(adresa) {
        this->oras = oras;
        this->pret = pret;
        this->suprafata = suprafata;
        this->nrCamere = nrCamere;
        this->suprafataCamere = new float[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++) {
            this->suprafataCamere[i] = suprafataCamere[i];
        }
        nrCase++;
    }

    void afisareCasa() {
        cout << endl << "Adresa: " << this->adresa;
        cout << endl << "Oras: " << this->oras;
        cout << endl << "Pret: " << this->pret;
        cout << endl << "Suprafata: " << this->suprafata;
        cout << endl << "Nr camere: " << this->nrCamere;
        if (this->nrCamere > 0) {
            cout << endl << "Suprafata per camera: " << endl;
            for (int i = 0; i < this->nrCamere - 1; i++) {
                cout << "camera[" << i << "] " << this->suprafataCamere[i] << ", ";
            }
            cout << "camera[" << nrCamere - 1 << "] " << this->suprafataCamere[nrCamere - 1] << ".";
        }
        cout << endl;
    }

    ~Casa() {
        if (this->suprafataCamere != nullptr) {
            delete[] this->suprafataCamere;
        }
    }
};

int Casa::nrCase = 0;

int main() {
    Casa c1;
    cout << endl << "Am construit " << Casa::nrCase << " case!";
    c1.afisareCasa();

    float* suprafataCamere = new float[3] {20, 15.5f, 12};
    Casa* pCasa = new Casa(25, "Bucuresti", 120000, 85.5f, 3, suprafataCamere);
    pCasa->afisareCasa();
    cout << endl << "Am construit " << Casa::nrCase << " case!";

    delete pCasa;
    delete[] suprafataCamere;
    return 0;
}
