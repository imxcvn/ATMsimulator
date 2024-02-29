

class KartaD : public Karta {
private:
	double dodatkowaOplata;
public:
	KartaD();
	KartaD(double dodatkowaOplata);
	~KartaD();
	void setDodatkowaOplata(double dodatkowaOplata);
	double getDodatkowaOplata() const;
	void wypisz(const std::string& wciecie) const override;
};