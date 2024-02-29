#include "Nominal.h"

Nominal::Nominal() {

}

Nominal::Nominal(int m_wartosc, int m_ilosc) {
	this->m_wartosc = m_wartosc;
	this->m_ilosc = m_ilosc;
}

void Nominal::setWartosc(int wartosc) {
	this->m_wartosc = wartosc;
}

int Nominal::getWartosc() const {
	return this->m_wartosc;
}

void Nominal::setIlosc(int ilosc) {
	this->m_ilosc = ilosc;
}

int Nominal::getIlosc() const {
	return this->m_ilosc;
}