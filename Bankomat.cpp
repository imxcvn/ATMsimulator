#include "Naglowki.h"



Bankomat::Bankomat(Bank* bank) {
	this->bank = bank;
	nominaly[NOM10].setWartosc(10);
	

	nominaly[NOM20].setWartosc(20);
	

	nominaly[NOM50].setWartosc(50);
	

	nominaly[NOM100].setWartosc(100);
	

	nominaly[NOM200].setWartosc(200);
	

	this->minimalneZasoby = 0;
}

int Bankomat::obliczZasoby() const {
	int zasoby{ 0 };
	for (int i = 0; i < this->nominaly.size(); i++) {
		zasoby += nominaly[i].getIlosc() * nominaly[i].getWartosc();
	}
	return zasoby;
}

void Bankomat::dodajTransakcje(Transakcja* transakcja) {
	historiaTransakcji.push_back(transakcja);
}

int Bankomat::getLiczbaTransakcji() const {
	return this->historiaTransakcji.size();
}

Transakcja* Bankomat::getTransakcja(int indeks) const {
	return this->historiaTransakcji[indeks];
}

void Bankomat::wypiszZasoby(const std::string& wciecie) const {
	for (int i = 0; i < nominaly.size(); i++) {
		std::cout << wciecie << "Nominal: " << nominaly[i].getWartosc() << ".  " << "Ilosc: " << nominaly[i].getIlosc() << "." << std::endl;
	}
	double zasoby = obliczZasoby();
	std::cout << wciecie << "Laczne zasoby: " << zasoby << "." << std::endl;
}

std::vector<Nominal> Bankomat::wyplac(int kwota) {
	std::vector<Nominal> wynik;
	int nominal = nominaly.size() - 1;
	while (kwota > 0 && nominal >= 0) {
		if (nominaly[nominal].getIlosc() != 0) {
			int liczbaBanknotow = kwota / nominaly[nominal].getWartosc();
			if (liczbaBanknotow > nominaly[nominal].getIlosc()) {
				liczbaBanknotow = nominaly[nominal].getIlosc();
				
			}
			if (liczbaBanknotow > 0) {
				wynik.push_back({ nominaly[nominal].getWartosc(), liczbaBanknotow });
				kwota = kwota - nominaly[nominal].getWartosc() * liczbaBanknotow;
			}
			
		}
		nominal--;
	}
	if (kwota == 0) {
		for (int i = 0; i < wynik.size(); i++) {
			int j = indeksNominalu(wynik[i].getWartosc());
			nominaly[j].setIlosc(nominaly[j].getIlosc() - wynik[i].getIlosc());

		}
		uaktualnijTryb();
	}
	else {
		wynik.clear();

	}

	return wynik;
}

int Bankomat::indeksNominalu(int wartosc) const {
	for (int i = 0; i < nominaly.size(); i++) {
		if (wartosc == nominaly[i].getWartosc()) {
			return i;
		}
	}
	return -1;
}

int Bankomat::getLiczbaNominalow() const {
	return nominaly.size();
}

int Bankomat::getWartoscNominalu(int indeks) const {
	return nominaly[indeks].getWartosc();
}

int Bankomat::getIloscNominalu(int indeks) const {
	return nominaly[indeks].getIlosc();
}

void Bankomat::wplac(const std::vector<int>& v) {
	for (int i = 0; i < nominaly.size(); i++) {
		nominaly[i].setIlosc(nominaly[i].getIlosc() + v[i]);
	}
	uaktualnijTryb();
}

Tryb Bankomat::getTryb() const {
	return this->tryb;
}

void Bankomat::ustawIloscNom(int nominal, int ilosc) {
	int indeks = indeksNominalu(nominal);
	nominaly[indeks].setIlosc(ilosc);
}

void Bankomat::uaktualnijTryb() {
	double aktualneZasoby = obliczZasoby();
	if (aktualneZasoby >= this->minimalneZasoby) {
		this->tryb = Tryb::normalny;
	}
	else {
		this->tryb = Tryb::serwisowy;
	}
}

void Bankomat::setMinimalneZasoby(int minimalneZasoby) {
	this->minimalneZasoby = minimalneZasoby;
	uaktualnijTryb();
}

int Bankomat::getMinimalneZasoby() const {
	return this->minimalneZasoby;
}

Bankomat::~Bankomat() {
	for (int i = 0; i < historiaTransakcji.size(); i++) {
		delete historiaTransakcji[i];
	}
}