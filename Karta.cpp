#include "Naglowki.h"

Karta::Karta() {
	this->uzytkownik = nullptr;
	this->numerKarty = "000000";
	this->pin = "123";
	this->saldo = 0;
	this->blokada = false;
}

Karta::Karta(const std::string& numerKarty, const std::string& pin, double saldo, bool blokada) {
	this->uzytkownik = nullptr;
	this->numerKarty = numerKarty;
	this->pin = pin;
	this->saldo = saldo;
	this->blokada = blokada;
	
}  

Uzytkownik* Karta::getUzytkownik() const {
	return this->uzytkownik;
}

void Karta::dodajUzytkownik(Uzytkownik* uzytkownik) {
	this->uzytkownik = uzytkownik;
}

Konto* Karta::getKonto() const {
	return this->konto;
}
void Karta::setKonto(Konto* konto) {
	this->konto = konto;
}

void Karta::dodajTransakcje(Transakcja* transakcja) {
	historiaTransakcji.push_back(transakcja);
}

int Karta::getLiczbaTransakcji() const {
	return this->historiaTransakcji.size();
}

Transakcja* Karta::getTransakcja(int i) const {
	return this->historiaTransakcji[i];
}

void Karta::setNumerKarty(const std::string& numerKarty) {
	this->numerKarty = numerKarty;
}

const std::string& Karta::getNumerKarty() const {
	return this->numerKarty;
}

void Karta::setPin(const std::string& pin) {
	this->pin = pin;
}

const std::string& Karta::getPin() const {
	return this->pin;
}

void Karta::setSaldo(double saldo) {
	this->saldo = saldo;
}

double Karta::getSaldo() const {
	return this->saldo;
}

void Karta::setBlokada(bool blokada) {
	this->blokada = blokada;
} 

bool Karta::getBlokada() {
	return this->blokada;
}

void Karta::wypisz(const std::string& wciecie) const {
	std::cout << wciecie << "Numer karty: " << this->numerKarty << "\n";
	std::cout << wciecie << "Pin: " << this->pin << "\n";
	std::cout << wciecie << "Saldo: " << this->saldo << "\n";
	std::cout << wciecie << "Blokada: " << this->blokada << "\n";
	std::cout << wciecie << "Ilosc transakcji: " << this->historiaTransakcji.size() << std::endl;
 }

void Karta::wplata(double kwota) {
	this->saldo += kwota;
	std::cout << "Wplata dokonana." << std::endl;
}

void Karta::wyplata(double kwota) {
	this->saldo -= kwota;
	std::cout << "Wyplata dokonana." << std::endl;
}

Karta::~Karta() {
	for (int i = 0; i < historiaTransakcji.size(); i++) {
		delete historiaTransakcji[i];
	}
}