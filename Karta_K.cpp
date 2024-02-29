#include "Naglowki.h"

KartaK::KartaK() {
	this->dodatkowaOplata = 30.20;         //0.04 * transakcja.getKwota();
}

KartaK::KartaK(double dodatkowaOplata) {
	this->dodatkowaOplata = dodatkowaOplata;
}

void KartaK::setDodatkowaOplata(double dodatkowaOplata) {
	this->dodatkowaOplata = dodatkowaOplata;
}

double KartaK::getDodatkowaOplata() const {
	return this->dodatkowaOplata;
}

void KartaK::wypisz(const std::string& wciecie) const {
	std::cout << wciecie << "Typ karty: kredytowa." << "\n";
	Karta::wypisz(wciecie);
	std::cout << wciecie << "Dodatkowa oplata: " << this->dodatkowaOplata << std::endl;
}

/*void KartaK::wyplata(double kwota) {
	double nowaKwota = kwota - (kwota * getDodatkowaOplata());
	Karta::wyplata(nowaKwota);
}
*/

KartaK::~KartaK() {

}