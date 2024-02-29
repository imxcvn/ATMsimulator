

class Bank {
private:
	double m_dodatkowaOplata;  
	std::vector<Konto*> m_konta;
	std::vector<Karta*> m_karty;
	std::vector<Uzytkownik*> m_uzytkownicy;
public:
	Bank();
	//Bank(double dodatkowa_oplata, const std::vector<Konto*>& konto, const std::vector<Karta*>& karta);
	void dodajKarte(Karta* karta);
	void dodajKonto(Konto* konto);
	void dodajUzytkownika(Uzytkownik* uzytkownik);
	void setDodatkowaOplata(double dodatkowaOplata);
	int getLiczbaUzytkownikow() const;
	Uzytkownik* getUzytkownik(int indeks) const;
	double getDodatkowaOplata();
	void wypisz() const;
	//void setKonto(const std::vector<Konto>& konto);
	//const std::vector<Konto>& getKonto() const;
	//void setKarta(const std::vector<Karta>& karta);
	//const std::vector<Karta>& getKarta() const;
	// 
	
	Karta* znajdzKarte(const std::string& numerKarty);
	~Bank();
};