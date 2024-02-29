#include "Naglowki.h"

Uzytkownik::Uzytkownik() {

}

Uzytkownik::Uzytkownik(const std::string& imie, const std::string& nazwisko, const std::string& email, const std::string& adres, const std::string& numerTelefonu) {
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->email = email;
	this->adres = adres;
	this->numerTelefonu = numerTelefonu;
}

void Uzytkownik::setImie(const std::string& imie) {
	this->imie = imie;
}

const std::string& Uzytkownik::getImie() const {
	return this->imie;
}

void Uzytkownik::setNazwisko(const std::string& nazwisko) {
	this->nazwisko = nazwisko;
}

const std::string& Uzytkownik::getNazwisko() const {
	return this->nazwisko;
}

void Uzytkownik::setEmail(const std::string& email) {
	this->email = email;
}

const std::string& Uzytkownik::getEmail() const {
	return this->email;
}

void Uzytkownik::setAdres(const std::string& adres) {
	this->adres = adres;
}

const std::string& Uzytkownik::getAdres() const {
	return this->adres;
}

void Uzytkownik::setNumerTelefonu(const std::string& numerTelefonu) {
	this->numerTelefonu = numerTelefonu;
}

const std::string& Uzytkownik::getNumerTelefonu() const {
	return this->numerTelefonu;
}

void Uzytkownik::wypisz(const std::string& wciecie) const {
	std::cout << wciecie << "Imie: " << this->imie << "\n";
	std::cout << wciecie << "Nazwisko: " << this->nazwisko << "\n";
	std::cout << wciecie << "Email: " << this->email << "\n";
	std::cout << wciecie << "Adres: " << this->adres << "\n";
	std::cout << wciecie << "Numer telefonu: " << this->numerTelefonu << std::endl;
}

void Uzytkownik::setKonto(Konto* konto) {
	this->konto = konto;
} 

Konto* Uzytkownik::getKonto() const {
	return this->konto;
}