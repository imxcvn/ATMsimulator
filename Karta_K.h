

class KartaK : public Karta {
private:
	double dodatkowaOplata;
public:
	KartaK();
	KartaK(double dodatkowaOplata);
	~KartaK();
	void setDodatkowaOplata(double dodatkowaOplata);
	double getDodatkowaOplata() const;
	void wypisz(const std::string& wciecie) const override;
	
};