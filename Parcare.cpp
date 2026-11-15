
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

enum TipParcare { ACOPERITA = 1, DESCOPERITA = 2 };

class Parcare {
private:
    const int cod;
    string nume;
    float tarifOra;
    TipParcare tip;
    int nrMasini;
    float* durateStationare;

public:
    static int nrParcari;

    Parcare() : cod(++nrParcari) {
        nume = "Necunoscut";
        tarifOra = 0;
        tip = DESCOPERITA;
        nrMasini = 0;
        durateStationare = nullptr;
    }

    Parcare(int cod, string nume, float tarif, TipParcare tip,
        int nrMasini, const float* durate) : cod(cod) {
        this->nume = nume;
        this->tarifOra = tarif;
        this->tip = tip;
        this->nrMasini = nrMasini;
        this->durateStationare = nullptr;

        if (nrMasini < 0 || (nrMasini > 0 && durate == nullptr))
            throw invalid_argument("Date invalide");

        if (nrMasini > 0) {
            durateStationare = new float[nrMasini];

            for (int i = 0; i < nrMasini; i++) {
                durateStationare[i] = durate[i];
            }
        }

        nrParcari++;
    }

    Parcare(const Parcare& p) : cod(++nrParcari) {
        nume = p.nume;
        tarifOra = p.tarifOra;
        tip = p.tip;
        nrMasini = p.nrMasini;
        durateStationare = nullptr;

        if (nrMasini > 0) {
            durateStationare = new float[nrMasini];

            for (int i = 0; i < nrMasini; i++) {
                durateStationare[i] = p.durateStationare[i];
            }
        }
    }

    Parcare& operator=(const Parcare& p) {
        if (this != &p) {
            float* copie = nullptr;

            if (p.nrMasini > 0) {
                copie = new float[p.nrMasini];

                for (int i = 0; i < p.nrMasini; i++) {
                    copie[i] = p.durateStationare[i];
                }
            }

            delete[] durateStationare;

            nume = p.nume;
            tarifOra = p.tarifOra;
            tip = p.tip;
            nrMasini = p.nrMasini;
            durateStationare = copie;
        }

        return *this;
    }

    ~Parcare() {
        delete[] durateStationare;
    }

    void afisare() const {
        cout << "\nCod: " << cod;
        cout << "\nNume: " << nume;
        cout << "\nTarif pe ora: " << tarifOra;
        cout << "\nTip parcare: ";

        if (tip == ACOPERITA)
            cout << "Acoperita";
        else
            cout << "Descoperita";

        cout << "\nNumar masini: " << nrMasini;

        if (durateStationare != nullptr) {
            cout << "\nDurate stationare: ";

            for (int i = 0; i < nrMasini; i++) {
                cout << durateStationare[i] << " ore ";

                if (i < nrMasini - 1)
                    cout << ", ";
            }
        }

        cout << endl;
    }

    int getNrMasini() const {
        return nrMasini;
    }

    void setNrMasini(int numarNou) {
        if (numarNou < 0)
            throw invalid_argument("Numar invalid");

        float* vectorNou = nullptr;

        if (numarNou > 0) {
            vectorNou = new float[numarNou]{};

            int limita = numarNou < nrMasini ? numarNou : nrMasini;

            for (int i = 0; i < limita; i++) {
                vectorNou[i] = durateStationare[i];
            }
        }

        delete[] durateStationare;
        durateStationare = vectorNou;
        nrMasini = numarNou;
    }

    float* getDurateStationare() const {
        if (nrMasini == 0)
            return nullptr;

        float* copie = new float[nrMasini];

        for (int i = 0; i < nrMasini; i++) {
            copie[i] = durateStationare[i];
        }

        return copie;
    }

    void setDurateStationare(const float* durate, int numar) {
        if (numar < 0 || (numar > 0 && durate == nullptr))
            throw invalid_argument("Date invalide");

        float* vectorNou = nullptr;

        if (numar > 0) {
            vectorNou = new float[numar];

            for (int i = 0; i < numar; i++) {
                vectorNou[i] = durate[i];
            }
        }

        delete[] durateStationare;
        durateStationare = vectorNou;
        nrMasini = numar;
    }

    bool operator<(const Parcare& p) const {
        return nrMasini < p.nrMasini;
    }

    Parcare& operator+=(float suma) {
        tarifOra += suma;
        return *this;
    }

    bool operator!() const {
        return tarifOra == 0;
    }

    float operator()(float ore) const {
        return tarifOra * ore;
    }

    float& operator[](int index) {
        if (index < 0 || index >= nrMasini)
            throw out_of_range("Pozitie invalida");

        return durateStationare[index];
    }

    const float& operator[](int index) const {
        if (index < 0 || index >= nrMasini)
            throw out_of_range("Pozitie invalida");

        return durateStationare[index];
    }

    Parcare operator++(int) {
        Parcare copie(*this);
        tarifOra++;
        return copie;
    }

    Parcare& operator++() {
        tarifOra++;
        return *this;
    }

    explicit operator int() const {
        return nrMasini;
    }

    friend ostream& operator<<(ostream& out, const Parcare& p) {
        out << "\nParcare: " << p.nume;
        out << "\nCod: " << p.cod;
        out << "\nTarif: " << p.tarifOra;
        out << "\nTip: ";

        if (p.tip == ACOPERITA)
            out << "Acoperita";
        else
            out << "Descoperita";

        out << "\nMasini parcate: " << p.nrMasini;

        if (p.nrMasini > 0) {
            out << "\nDurate: ";

            for (int i = 0; i < p.nrMasini; i++) {
                out << p.durateStationare[i] << " h";

                if (i != p.nrMasini - 1)
                    out << ", ";
            }
        }

        out << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Parcare& p) {
        string numeNou;
        float tarifNou;
        int tipNou;
        int numar;

        cout << "\nNume parcare: ";
        in >> numeNou;

        cout << "Tarif ora: ";
        in >> tarifNou;

        cout << "Tip (1-Acoperita, 2-Descoperita): ";
        in >> tipNou;

        cout << "Numar masini: ";
        in >> numar;

        if (!in)
            return in;

        if (numar < 0 || (tipNou != 1 && tipNou != 2))
            throw invalid_argument("Date invalide");

        float* valori = nullptr;

        if (numar > 0) {
            valori = new float[numar];

            for (int i = 0; i < numar; i++) {
                cout << "Durata masina " << i + 1 << ": ";
                in >> valori[i];

                if (!in) {
                    delete[] valori;
                    return in;
                }
            }
        }

        delete[] p.durateStationare;

        p.durateStationare = valori;
        p.nrMasini = numar;
        p.nume = numeNou;
        p.tarifOra = tarifNou;
        p.tip = static_cast<TipParcare>(tipNou);

        return in;
    }
};

int Parcare::nrParcari = 0;

int main() {
    Parcare p1;

    p1 += 5;

    if (!p1) {
        cout << "\nParcarea este gratuita!";
    }
    else {
        cout << "\nParcarea are tarif!";
    }

    cout << "\nCost pentru 3 ore: " << p1(3);

    cout << p1;

    Parcare p2 = p1++;

    cout << "\nPostincrementare:";
    cout << p2;
    cout << p1;

    Parcare p3 = ++p1;

    cout << "\nPreincrementare:";
    cout << p3;
    cout << p1;

    float durate[] = { 2.5f, 4.0f, 1.5f, 3.0f };

    Parcare* p4 = new Parcare(
        10, "Parcare Mall", ACOPERITA == ACOPERITA ? 8.0f : 0.0f,
        ACOPERITA, 4, durate
    );

    p4->afisare();

    if (p1 < *p4) {
        cout << "\nPrima parcare are mai putine masini.";
    }
    else {
        cout << "\nPrima parcare nu are mai putine masini.";
    }

    (*p4)[1] = 6.5f;

    cout << "\nDurata modificata: " << (*p4)[1];

    cout << "\nNumar masini: " << (int)(*p4);

    cout << "\nTotal parcari create: " << Parcare::nrParcari;

    Parcare p5;
    p5 = *p4;

    cout << "\nParcare copiata prin atribuire:";
    cout << p5;

    float alteDurate[] = { 1.0f, 2.0f, 5.0f };

    p5.setDurateStationare(alteDurate, 3);

    cout << "\nDupa modificarea duratelor:";
    p5.afisare();

    delete p4;

    return 0;
}
