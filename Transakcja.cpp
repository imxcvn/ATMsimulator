#include "Naglowki.h"

Transakcja::Transakcja() {
	this->data = "20.06.2023";
	this->operacja = "operacja";
	this->kwota = 0;
}

Transakcja::Transakcja(const std::string& data, const std::string& operacja, int kwota) {
	this->data = data;
	this->operacja = operacja;
	this->kwota = kwota;
}

void Transakcja::setData(const std::string& data) {
	this->data = data;
}

const std::string& Transakcja::getData() const {
	return this->data;
}

void Transakcja::setOperacja(const std::string& operacja) {
	this->operacja = operacja;
}

const std::string& Transakcja::getOperacja() const {
	return this->operacja;
}

void Transakcja::setKwota(int kwota) {
	this->kwota = kwota;
}

int Transakcja::getKwota() const {
	return this->kwota;
}

void Transakcja::wypisz(const std::string& wciecie) const {
	std::cout << wciecie << "Data: " << this->data << "\n";
	std::cout << wciecie << "Operacja: " << this->operacja << "\n";
	std::cout << wciecie << "Kwota: " << this->kwota << std::endl;
}

Transakcja::~Transakcja() {

}