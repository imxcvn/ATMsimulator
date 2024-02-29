
class Nominal {
private:
	int m_wartosc;
	int m_ilosc;
public:
	Nominal();
	Nominal(int m_wartosc, int m_ilosc);
	void setWartosc(int wartosc);
	int getWartosc() const;
	void setIlosc(int ilosc);
	int getIlosc() const;
};