#include "Naglowki.h"

Konto::Konto() {

}

Konto::Konto(Uzytkownik* uzytkownik) {
	this->uzytkownik = uzytkownik;
	
}


void Konto::dodajKarte(Karta* karta) {
	karty.push_back(karta);
}

void Konto::setUzytkownik(Uzytkownik* uzytkownik) {
	this->uzytkownik = uzytkownik; 
}

Uzytkownik* Konto::getUzytkownik() const {
	return this->uzytkownik;
}

void Konto::wypisz(const std::string& wciecie) const {
	std::cout << wciecie << "Uzytkownik: " << this->uzytkownik->getImie() << " " << this->uzytkownik->getNazwisko() << "\n";
	std::cout << wciecie << "Liczba kart: " << this->karty.size() << std::endl;
}

int Konto::getLiczbaKart() const {
	return this->karty.size();
}

Karta* Konto::getKarta(int indeks) const {
	return this->karty[indeks];
}

Konto::~Konto() {

}