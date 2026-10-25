#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Masina
{
private:
    const int id;
    string marca;
    int nr_usi;
    float* vector_consum;   // consumul pe 100 km la fiecare dintre cele nr_usi... vezi nota de mai jos

public:
    static int nr_masini;

    Masina() : id(++nr_masini)
    {
        this->marca = "Default";
        this->nr_usi = 0;
        this->vector_consum = nullptr;
    }

    Masina(string marca, int nr_usi, float* vector_consum) : id(++nr_masini)
    {
        this->marca = marca;
        this->nr_usi = nr_usi;
        this->vector_consum = new float[nr_usi];
        for (int i = 0; i < this->nr_usi; i++)
        {
            this->vector_consum[i] = vector_consum[i];
        }
    }

    void afisare_masina()
    {
        cout << endl << "Id: " << this->id;
        cout << endl << "Marca: " << this->marca;
        cout << endl << "Numar de usi: " << this->nr_usi;

        if (this->nr_usi > 0)
        {
            cout << endl << "Valori: ";
            for (int i = 0; i < this->nr_usi - 1; i++)
            {
                cout << this->vector_consum[i] << " l/100km, ";
            }
            cout << this->vector_consum[this->nr_usi - 1] << " l/100km.";
        }
        cout << endl;
    }

    int getNr_usi()
    {
        return this->nr_usi;
    }

    void setNr_usi(int nr_usi_nou)
    {
        if (nr_usi_nou >= 0)
        {
            this->nr_usi = nr_usi_nou;
        }
        else
        {
            throw "Valoare negativa";
        }
    }

    float* getVector_consum()
    {
        float* vector_nou = new float[this->nr_usi];
        for (int i = 0; i < this->nr_usi; i++)
        {
            vector_nou[i] = this->vector_consum[i];
        }
        return vector_nou;
    }

    void setVector_consum(float* vector, int nr)
    {
        setNr_usi(nr);
        if (this->vector_consum != nullptr)
        {
            delete[] this->vector_consum;
        }
        this->vector_consum = new float[this->nr_usi];
        for (int i = 0; i < this->nr_usi; i++)
        {
            this->vector_consum[i] = vector[i];
        }
        delete[] vector;
    }

    ~Masina()
    {
        if (this->vector_consum != nullptr)
        {
            delete[] this->vector_consum;
        }
    }
};

int Masina::nr_masini = 0;

int main()
{
    Masina mDefault;
    mDefault.afisare_masina();

    try
    {
        mDefault.setNr_usi(4);
    }
    catch (int cod)
    {
        cout << endl << cod;
    }
    catch (const char* mesaj)
    {
        cout << endl << mesaj;
    }
    catch (...)
    {
        cout << endl << "Numar de usi negativ!" << endl;
    }

    cout << endl << "Noul numar de usi este: " << mDefault.getNr_usi() << endl;

    mDefault.setVector_consum(new float[3] {6.5f, 7.2f, 8.1f}, 3);
    float* vector = mDefault.getVector_consum();

    cout << endl << "Noile valori sunt: ";
    for (int i = 0; i < 3; i++)
    {
        if (i != 2)
            cout << vector[i] << " l/100km, ";
        else
            cout << vector[i] << " l/100km." << endl;
    }
    mDefault.afisare_masina();
    delete[] vector;

    float* vector_consum = new float[3] {5.8f, 6.4f, 7.9f};
    Masina* pAudi = new Masina("Audi", 3, vector_consum);
    pAudi->afisare_masina();
    delete pAudi;
    delete[] vector_consum;

    if (Masina::nr_masini == 1)
    {
        cout << endl << "Am construit o masina!" << endl;
    }
    else
    {
        cout << endl << "Am construit " << Masina::nr_masini << " masini!" << endl;
    }

    return 0;
}
