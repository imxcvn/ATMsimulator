#include "Naglowki.h"

KartaD::KartaD() {
	this->dodatkowaOplata = 0;
}

KartaD::KartaD(double dodatkowaOplata) {
	this->dodatkowaOplata = dodatkowaOplata;
}

void KartaD::setDodatkowaOplata(double dodatkowaOplata) {
	this->dodatkowaOplata = dodatkowaOplata;
}

double KartaD::getDodatkowaOplata() const {
	return this->dodatkowaOplata;
}

void KartaD::wypisz(const std::string& wciecie) const {
	std::cout << wciecie << "Typ karty: debetowa" << "\n";
	Karta::wypisz(wciecie);
	std::cout << wciecie << "Dodatkowa oplata: " << this->dodatkowaOplata << std::endl;
 }

KartaD::~KartaD() {

}