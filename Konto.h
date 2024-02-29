

class Konto {
private:

	Uzytkownik* uzytkownik;
	std::vector<Karta*> karty;
public:
	Konto();
	Konto(Uzytkownik* uzytkownik);

	void dodajKarte(Karta* karta);
	void setUzytkownik(Uzytkownik* uzytkownik);
	Uzytkownik* getUzytkownik() const;
	void wypisz(const std::string& wciecie) const;
	int getLiczbaKart() const;
	Karta* getKarta(int indeks) const;
	~Konto();

};