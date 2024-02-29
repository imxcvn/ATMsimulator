

class Transakcja {
private:
	std::string data;
	std::string operacja;  //mozna na enum zamienic
	int kwota;
public:
	Transakcja();
	Transakcja(const std::string& data, const std::string& operacja, int kwota);
	virtual ~Transakcja();
	void setData(const std::string& data);
	const std::string& getData() const;
	void setOperacja(const std::string& operacja);
	const std::string& getOperacja() const;
	void setKwota(int kwota);
	int getKwota() const;
	void wypisz(const std::string& wciecie) const;
	
};