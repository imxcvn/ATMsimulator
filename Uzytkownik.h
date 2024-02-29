class Konto;

class Uzytkownik {
private:
	std::string imie;
	std::string nazwisko;
	std::string email;
	std::string adres;
	std::string numerTelefonu;
	Konto* konto;
public:
	Uzytkownik();
	Uzytkownik(const std::string& imie, const std::string& nazwisko, const std::string& email, const std::string& adres, const std::string& numerTelefonu);
	void setImie(const std::string& imie);
	const std::string& getImie() const;
	void setNazwisko(const std::string& nazwisko);
	const std::string& getNazwisko() const;
	void setEmail(const std::string& email);
	const std::string& getEmail() const;
	void setAdres(const std::string& adres);
	const std::string& getAdres() const;
	void setNumerTelefonu(const std::string& numerTelefonu);
	const std::string& getNumerTelefonu() const;
	void wypisz(const std::string& wciecie) const;
	void setKonto(Konto* konto);
	Konto* getKonto() const;
	
};