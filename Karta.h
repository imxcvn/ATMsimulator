
class Konto;

class Karta {
private:
	std::string numerKarty;
	std::string pin;
	double saldo;
	bool blokada;
	std::vector<Transakcja*> historiaTransakcji;
	Konto* konto;
	Uzytkownik* uzytkownik;
public:
	Karta();
	Karta(const std::string& numerKarty, const std::string& pin, double saldo, bool blokada);
	virtual ~Karta();
	Uzytkownik* getUzytkownik() const;
	void dodajUzytkownik(Uzytkownik* uzytkownik);
	Konto* getKonto() const;
	void setKonto(Konto* konto);
	void dodajTransakcje(Transakcja* transakcja);
	int getLiczbaTransakcji() const;
	Transakcja* getTransakcja(int i) const;
	void setNumerKarty(const std::string& numerKarty);
	const std::string& getNumerKarty() const;
	void setPin(const std::string& pin);
	const std::string& getPin() const;
	void setSaldo(double saldo);
	double getSaldo() const;
	void setBlokada(bool blokada);
	bool getBlokada(); 
	virtual void wypisz(const std::string& wciecie) const;
	virtual void wplata(double kwota);
	virtual void wyplata(double kwota);

};