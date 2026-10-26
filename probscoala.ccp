
#include <iostream>
#include <string>

using namespace std;

class Scoala { //clasa
private:
	const int id;
	int nr_profesori;
	int nr_elevi;
	string denumire;
	int nr_locuri_clasa;


public:
	static int nr_scoli;
	Scoala() :id(++nr_scoli) { //constructor 
		this->nr_profesori = 30;
		this->nr_elevi = 150;
		this->denumire = "Default";
		this->nr_locuri_clasa = 30;


	}
	Scoala(int nrprofesori, int nrelevi, string denumire, int nrlocuriclasa) :id(++nr_scoli) { //constructor
		this->nr_profesori = nrprofesori;
		this->nr_elevi = nrelevi;
		this->denumire = denumire;
		this->nr_locuri_clasa = nrlocuriclasa;


	}
	void afisareScoala() { //metoda
		cout << "Denumirea scolii este : " << this->denumire << endl;
		cout << "Fiecare clasa are capacitatea de a avea " << this->nr_locuri_clasa << " elevi " << endl;
		cout << "In scoala sunt in prezent " << this->nr_elevi << " elevi  " << endl;
		cout << "In scoala sunt in prezent " << this->nr_profesori << " profesori " << endl;
		cout << endl;

	}

	void modificareScoala(int nrprofesori, int nrelevi, int nrlocuri) {
		this->nr_profesori = nrprofesori;
		this->nr_elevi = nrelevi;
		this->nr_locuri_clasa = nrlocuri;


	}

	void redenumireScoala(string noua_denumire) {
		this->denumire = noua_denumire;

	}


};
int Scoala::nr_scoli = 0;

void main() {
	Scoala IonelTeodoreanu;
	IonelTeodoreanu.afisareScoala();
	IonelTeodoreanu.modificareScoala(40, 190, 210);
	IonelTeodoreanu.redenumireScoala("Ionel Teodeoreanu");
	IonelTeodoreanu.afisareScoala();

	Scoala GrigoreMoisil(20, 90, "Grigore Moisil", 25);
	GrigoreMoisil.afisareScoala();

	//metoda diferita mai grea de creere
	//creem un pointer(cu steluta)
	Scoala* OctavOnicescu = new Scoala(24,110,"Octav Onicescu",33);
	OctavOnicescu->afisareScoala();

}
