#include "Naglowki.h"

Bank::Bank() {
	
}

void Bank::dodajKarte(Karta* karta) {
	this->m_karty.push_back(karta);
}

void Bank::dodajKonto(Konto* konto) {
	this->m_konta.push_back(konto);
}

void Bank::dodajUzytkownika(Uzytkownik* uzytkownik) {
	this->m_uzytkownicy.push_back(uzytkownik);
}

void Bank::setDodatkowaOplata(double dodatkowaOplata) {
	this->m_dodatkowaOplata = dodatkowaOplata;
}

double Bank::getDodatkowaOplata() {
	return this->m_dodatkowaOplata;
}

void Bank::wypisz() const {
	std::cout << "Liczba kont: " << this->m_konta.size() << "\n";
	for (int i = 0; i < m_konta.size(); i++) {
		std::cout << "Konto " << i << ":" << "\n";
		m_konta[i]->wypisz("  ");

		//m_karty[i]->wypisz("  ");
		//m_uzytkownicy[i]->wypisz("  ");
		
 	}

	std::cout << "Liczba kart: " << this->m_karty.size() << "\n";
	for (int j = 0; j < m_karty.size(); j++) {
		std::cout << "Karta " << j << ":" << "\n";
		m_karty[j]->wypisz("  ");
		for (int y = 0; y < this->m_karty[j]->getLiczbaTransakcji(); y++) {
			std::cout << "  Transakcja " << y << ":" << "\n";
			this->m_karty[j]->getTransakcja(y)->wypisz("    ");
		}
	}

	for (int k = 0; k < m_uzytkownicy.size(); k++) {
		std::cout << "Uzytkownik " << k << ":" << "\n";
		m_uzytkownicy[k]->wypisz("  ");
	}
}

Karta* Bank::znajdzKarte(const std::string& numerKarty) {
	for (int i = 0; i < m_karty.size(); i++) {
		if (m_karty[i]->getNumerKarty() == numerKarty)
			return m_karty[i];
		
	}
	return nullptr;
}

/*const std::vector<Konto>& Bank::getKonto() const {
	return this->konto;
}

void Bank::setKarta(const std::vector<Karta>& karta) {
	this->karta = karta;
}

const std::vector<Karta>& Bank::getKarta() const {
	return this->karta;
}
*/

int Bank::getLiczbaUzytkownikow() const {
	return this->m_uzytkownicy.size();
}

Uzytkownik* Bank::getUzytkownik(int indeks) const {
	return m_uzytkownicy[indeks];
}

Bank::~Bank() {
	for (int i = 0; i < this->m_konta.size(); i++) {
		delete this->m_konta[i];
	}

	for (int i = 0; i < this->m_karty.size(); i++) {
		delete this->m_karty[i];
	}

	for (int i = 0; i < this->m_uzytkownicy.size(); i++) {
		delete this->m_uzytkownicy[i];
	}
}