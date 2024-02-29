

enum class Tryb{normalny = 1, serwisowy = 2};
enum Nominaly{NOM10, NOM20, NOM50, NOM100, NOM200};



class Bankomat {
private:
	Bank* bank;
	Tryb tryb = Tryb::normalny;
	std::vector<Transakcja*> historiaTransakcji;
	std::array<Nominal, 5> nominaly;
	int minimalneZasoby;
	
public:
	Bankomat(Bank* bank);
	int obliczZasoby() const;
	void dodajTransakcje(Transakcja* transakcja);
	int getLiczbaTransakcji() const;
	Transakcja* getTransakcja(int indeks) const;
	void wypiszZasoby(const std::string& wciecie) const;
	std::vector<Nominal> wyplac(int kwota);
	int indeksNominalu(int wartosc) const;
	int getLiczbaNominalow() const;
	int getWartoscNominalu(int indeks) const;
	int getIloscNominalu(int indeks) const;
	void wplac(const std::vector<int>& v);
	void ustawIloscNom(int nominal, int ilosc);
	void uaktualnijTryb();
	void setMinimalneZasoby(int minimalneZasoby);
	int getMinimalneZasoby() const;
	Tryb getTryb() const;
	~Bankomat();
};