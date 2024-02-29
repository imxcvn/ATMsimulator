#include "Naglowki.h"

bool wczytajNiepustaLinie(std::istream& s, std::string& linia) {
    while (std::getline(s, linia)) {
        if (linia.size() > 0)
            return true;
   
    }
    return false;
}

bool wczytajBool(std::istream& s) {
    std::string linia;
    while (std::getline(s, linia)) {
        if (linia == "true")
            return true;
        else
            return false;
    }
    return false;
}

std::string wczytajNiepustaLinie(std::istream& s) {
    std::string linia;
    while (std::getline(s, linia)) {
        if (linia.size() > 0)
            return linia;
    }
    return {};
}

int wczytajInt(std::istream& s) {   
    std::string linia;
    if (wczytajNiepustaLinie(s, linia))
    {
        return atoi(linia.data());  
    }
    throw std::exception("Oczekiwano wartosci typu int");
}

int wczytajIntDoSkutku(int min, int max) {
    std::string linia;
    while (wczytajNiepustaLinie(std::cin, linia)) {
        char* end;
        int wartosc = strtol(linia.data(), &end, 10);
        if (*end == 0) {
            if (wartosc < min) {
                std::cout << "Za mala wartosc. Minimum to: " << min << std::endl;
            }
            else if (wartosc > max) {
                std::cout << "Za duza wartosc. Maksimum to: " << max << std::endl;
            } 
            else
                return wartosc;
        }
        else

            std::cout << "Musisz podac liczbe calkowita." << std::endl;
    }
    throw std::exception("Nie udalo sie wczytac wartosci typu int.");
}


double wczytajDouble(std::istream& s) {
    std::string linia;
    if (wczytajNiepustaLinie(s, linia)) {
        return std::stod(linia.data());
    }
    throw std::exception("Oczekiwano wartosci typu double");
}

double wczytajDoubleDoSkutku(double min, double max) {
    std::string linia;
    while (wczytajNiepustaLinie(std::cin, linia)) {
        char* end;
        double wartosc = strtod(linia.data(), &end);
        if (*end == 0) {
            if (wartosc < min) {
                std::cout << "Za mala wartosc. Minimum to: " << min << std::endl;
            }
            else if (wartosc > max) {
                std::cout << "Za duza wartosc. Maksimum to: " << max << std::endl;
            } 
            else
                 return wartosc;
        } 
        else
            std::cout << "Musisz podac liczbe typu double." << std::endl;
    }
    throw std::exception("Nie udalo sie wczytac wartosci typu double.");
}

void Zapisz(Bank* bank, Bankomat* bankomat, const std::string& sciezka) {

    std::ofstream plikWyjsciowy{ sciezka };
    if (plikWyjsciowy.is_open()) {
        plikWyjsciowy << bank->getLiczbaUzytkownikow() << std::endl;
        for (int i = 0; i < bank->getLiczbaUzytkownikow(); i++) {
            Uzytkownik* uzytkownik = bank->getUzytkownik(i);
            plikWyjsciowy << uzytkownik->getImie() << std::endl;
            plikWyjsciowy << uzytkownik->getNazwisko() << std::endl;
            plikWyjsciowy << uzytkownik->getEmail() << std::endl;
            plikWyjsciowy << uzytkownik->getAdres() << std::endl;
            plikWyjsciowy << uzytkownik->getNumerTelefonu() << std::endl;
            Konto* konto = uzytkownik->getKonto();
            plikWyjsciowy << konto->getLiczbaKart() << std::endl;
            for (int j = 0; j < konto->getLiczbaKart(); j++) {
                Karta* karta = konto->getKarta(j);
                if (KartaK* kredytowa = dynamic_cast<KartaK*>(karta))
                {
                    plikWyjsciowy << "kredytowa" << std::endl;
                    plikWyjsciowy << karta->getNumerKarty() << std::endl;
                    plikWyjsciowy << karta->getPin() << std::endl;
                    plikWyjsciowy << karta->getSaldo() << std::endl;
                    plikWyjsciowy << karta->getBlokada() << std::endl;
                    plikWyjsciowy << kredytowa->getDodatkowaOplata() << std::endl;
                }
                else if (KartaD* debetowa = dynamic_cast<KartaD*>(karta)){
                    plikWyjsciowy << "debetowa" << std::endl;
                    plikWyjsciowy << karta->getNumerKarty() << std::endl;
                    plikWyjsciowy << karta->getPin() << std::endl;
                    plikWyjsciowy << karta->getSaldo() << std::endl;
                    plikWyjsciowy << karta->getBlokada() << std::endl;
                    plikWyjsciowy << debetowa->getDodatkowaOplata() << std::endl;
                }

                plikWyjsciowy << karta->getLiczbaTransakcji() << std::endl;
                for (int k = 0; k < karta->getLiczbaTransakcji(); k++) {
                    Transakcja* transakcja = karta->getTransakcja(k);
                    plikWyjsciowy << transakcja->getData() << std::endl;
                    plikWyjsciowy << transakcja->getOperacja() << std::endl;
                    plikWyjsciowy << transakcja->getKwota() << std::endl;

                }
            }
            for (int n = 0; n < bankomat->getLiczbaNominalow(); n++) {
                plikWyjsciowy << bankomat->getIloscNominalu(n) << std::endl;
            }

            plikWyjsciowy << bankomat->getMinimalneZasoby() << std::endl;

            plikWyjsciowy << bankomat->getLiczbaTransakcji() << std::endl;
            for (int m = 0; m < bankomat->getLiczbaTransakcji(); m++) {
                Transakcja* transakcja = bankomat->getTransakcja(m);
                plikWyjsciowy << transakcja->getData() << std::endl;
                plikWyjsciowy << transakcja->getOperacja() << std::endl;
                plikWyjsciowy << transakcja->getKwota() << std::endl;

            }
        }

    }
    else
    {
        throw std::exception("Nie udalo sie otworzyc pliku do zapisu.");
    }
}

void wczytaj(Bank* bank, Bankomat* bankomat, const std::string& sciezka) {
    std::ifstream plik{ sciezka };
    if (plik.is_open() == false) {
        //std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
        throw std::exception("Nie udalo sie otworzyc pliku do odczytu");
    }
    int liczbaUzytkownikow;
    liczbaUzytkownikow = wczytajInt(plik);
    for (int i = 0; i < liczbaUzytkownikow; i++) {
        Uzytkownik* uzytkownik = new Uzytkownik{};
        Konto* konto = new Konto{};
        bank->dodajUzytkownika(uzytkownik);
        konto->setUzytkownik(uzytkownik);
        uzytkownik->setKonto(konto);
        bank->dodajKonto(konto);
        uzytkownik->setImie(wczytajNiepustaLinie(plik));
        uzytkownik->setNazwisko(wczytajNiepustaLinie(plik));
        uzytkownik->setEmail(wczytajNiepustaLinie(plik));
        uzytkownik->setAdres(wczytajNiepustaLinie(plik));
        uzytkownik->setNumerTelefonu(wczytajNiepustaLinie(plik));

        int liczbaKart = wczytajInt(plik);
        for (int j = 0; j < liczbaKart; j++) {

            std::string typKarty = wczytajNiepustaLinie(plik);

            if (typKarty == "kredytowa") {
                KartaK* kartaK = new KartaK{};
                kartaK->dodajUzytkownik(uzytkownik);
                konto->dodajKarte(kartaK);
                kartaK->setKonto(konto);
                bank->dodajKarte(kartaK);
                kartaK->setNumerKarty(wczytajNiepustaLinie(plik));
                kartaK->setPin(wczytajNiepustaLinie(plik));
                kartaK->setSaldo(wczytajDouble(plik));
                kartaK->setBlokada(wczytajBool(plik));
                kartaK->setDodatkowaOplata(wczytajDouble(plik));

                int liczbaTransakcji = wczytajInt(plik);
                for (int k = 0; k < liczbaTransakcji; k++) {
                    Transakcja* transakcja = new Transakcja{};
                    kartaK->dodajTransakcje(transakcja);
                    transakcja->setData(wczytajNiepustaLinie(plik));
                    transakcja->setOperacja(wczytajNiepustaLinie(plik));
                    transakcja->setKwota(wczytajInt(plik));
                }

            }
            else {
                KartaD* kartaD = new KartaD{};
                kartaD->dodajUzytkownik(uzytkownik);
                konto->dodajKarte(kartaD);
                kartaD->setKonto(konto);
                bank->dodajKarte(kartaD);
                kartaD->setNumerKarty(wczytajNiepustaLinie(plik));
                kartaD->setPin(wczytajNiepustaLinie(plik));
                kartaD->setSaldo(wczytajDouble(plik));
                kartaD->setBlokada(wczytajBool(plik));
                kartaD->setDodatkowaOplata(wczytajDouble(plik));

                int liczbaTransakcji = wczytajInt(plik);
                for (int k = 0; k < liczbaTransakcji; k++) {
                    Transakcja* transakcja = new Transakcja{};
                    kartaD->dodajTransakcje(transakcja);
                    transakcja->setData(wczytajNiepustaLinie(plik));
                    transakcja->setOperacja(wczytajNiepustaLinie(plik));
                    transakcja->setKwota(wczytajInt(plik));
                }






            }
        }

    }
    bankomat->ustawIloscNom(10, wczytajInt(plik));
    bankomat->ustawIloscNom(20, wczytajInt(plik));
    bankomat->ustawIloscNom(50, wczytajInt(plik));
    bankomat->ustawIloscNom(100, wczytajInt(plik));
    bankomat->ustawIloscNom(200, wczytajInt(plik));
    bankomat->setMinimalneZasoby(wczytajInt(plik));

    int liczbaTransakcji = wczytajInt(plik);
    for (int i = 0; i < liczbaTransakcji; i++) {
        Transakcja* transakcja = new Transakcja{};
        bankomat->dodajTransakcje(transakcja);
        transakcja->setData(wczytajNiepustaLinie(plik));
        transakcja->setOperacja(wczytajNiepustaLinie(plik));
        transakcja->setKwota(wczytajInt(plik));
    }

    plik.close();
}

void start()
{
    try
    {

        Bank bank;
        Bankomat bankomat{ &bank };

        wczytaj(&bank, &bankomat, "plik4.txt");
       
        bank.wypisz();

        Karta* znalezionaKarta = nullptr;
        bool kontynuujPetle = true;

        while (kontynuujPetle) {
            std::string numerKarty;
            std::system("cls");
            std::cout << "Podaj numer karty: " << std::endl;
            numerKarty = wczytajNiepustaLinie(std::cin);

            znalezionaKarta = bank.znajdzKarte(numerKarty);
            if (znalezionaKarta != nullptr) {
                std::cout << "Znaleziono karte." << std::endl;
                if (znalezionaKarta->getBlokada() == true) {
                    std::cout << "Karta jest zablokowana." << std::endl;

                }
                else
                    kontynuujPetle = false;

            }
            else
                std::cout << "Nie znaleziono karty." << std::endl;
        }

        int proby{ 3 };
        bool kontynuujPetle2 = true;
        while (kontynuujPetle2) {
            std::string numerPin;
            std::system("cls");
            std::cout << "Podaj numer pin: " << std::endl;
            numerPin = wczytajNiepustaLinie(std::cin);
            if (numerPin == znalezionaKarta->getPin()) {
                std::cout << "Poprawny pin." << std::endl;
                kontynuujPetle2 = false;
            }
            else {
                std::cout << "Niepoprawny pin." << std::endl;
                proby--;
                std::cout << "Pozostale proby: " << proby << std::endl;

                if (proby == 0) {
                    znalezionaKarta->setBlokada(true);
                    return;
                }

            }
        }

        bool koniec = false;
        while (koniec == false) {
            if (bankomat.getTryb() == Tryb::normalny) {
                std::cout << "Tryb pracy bankomatu: normalny." << std::endl;
                std::cout << "\nWybierz opcje: " << std::endl;
                std::cout << "1. Wyswietl informacje o koncie." << std::endl;
                std::cout << "2. Wyswietl informacje o transakcjach karty." << std::endl;
                std::cout << "3. Dokonaj wplaty." << std::endl;
                std::cout << "4. Dokonaj wyplaty." << std::endl;
                std::cout << "5. Wyswietl saldo." << std::endl;
                std::cout << "6. Wyswietl stan bankomatu." << std::endl;
                std::cout << "7. Wyswietl informacje o operacjach przeprowadzonych w bankomacie." << std::endl;
                std::cout << "8. Wyswietl informacje o blokadzie karty." << std::endl;
                std::cout << "9. Wyjscie." << std::endl;
                int numer = wczytajIntDoSkutku(1, 9);
                switch (numer) {
                case 1:
                    std::system("cls");
                    znalezionaKarta->getKonto()->wypisz("  ");
                    break;

                case 2:
                    std::system("cls");
                    for (int i = 0; i < znalezionaKarta->getLiczbaTransakcji(); i++) {
                        znalezionaKarta->getTransakcja(i)->wypisz(" ");

                    }
                    break;
                case 3:
                {
                    std::system("cls");
                    std::vector<int> iloscBanknotow(bankomat.getLiczbaNominalow());
                    std::cout << "Podaj liczbe wplacanych banknotow: " << std::endl;
                    for (int i = 0; i < iloscBanknotow.size(); i++) {
                        std::cout << bankomat.getWartoscNominalu(i) << ": ";
                        iloscBanknotow[i] = wczytajIntDoSkutku(0, 10);

                    }

                    int kwota{ 0 };
                    for (int i = 0; i < iloscBanknotow.size(); i++) {
                        kwota = kwota + (bankomat.getWartoscNominalu(i) * iloscBanknotow[i]);
                    }
                    std::cout << "Laczna kwota wplacona: " << kwota << "." << std::endl;

                    znalezionaKarta->wplata(kwota);
                    bankomat.wplac(iloscBanknotow);
                    std::string data = PobObecnaDate();
                    znalezionaKarta->dodajTransakcje(new Transakcja{ data, "wplata", kwota });
                    bankomat.dodajTransakcje(new Transakcja{ data, "wplata", kwota });
                    break;
                }

                case 4:
                {
                    std::system("cls");
                    std::cout << "Podaj kwote do wyplaty: " << std::endl;
                    int kwota = wczytajIntDoSkutku(0, std::min(bankomat.obliczZasoby(), (int)znalezionaKarta->getSaldo()));
                    if (kwota > znalezionaKarta->getSaldo()) {
                        std::cout << "Za duza kwota. Nie mozna dokonac wyplaty." << std::endl;

                    }

                    else {
                        std::vector<Nominal> wyplaconeNominaly = bankomat.wyplac(kwota);
                        if (wyplaconeNominaly.size() != 0) {
                            znalezionaKarta->wyplata(kwota);
                            for (int i = 0; i < wyplaconeNominaly.size(); i++) {
                                std::cout << "Wartosc: " << wyplaconeNominaly[i].getWartosc() << " ," << "Ilosc: " << wyplaconeNominaly[i].getIlosc() << std::endl;
                            }
                            std::string data = PobObecnaDate();
                            znalezionaKarta->dodajTransakcje(new Transakcja{ data, "wyplata", kwota });
                            bankomat.dodajTransakcje(new Transakcja{ data, "wyplata", kwota });

                        }
                        else {
                            std::cout << "Bankomat nie jest w stanie wyplacic wprowadzonej kwoty." << std::endl;
                        }

                    }

                    break;
                }

                case 5:
                    std::system("cls");
                    std::cout << "Saldo karty: " << znalezionaKarta->getSaldo() << "." << std::endl;
                    break;

                case 6:
                    std::system("cls");
                    std::cout << "Zasoby bankomatu: " << std::endl;
                    bankomat.wypiszZasoby("  ");
                    std::cout << "  Minimalne zasoby bankomatu: " << bankomat.getMinimalneZasoby() << std::endl;
                    break;

                case 7:
                    for (int i = 0; i < bankomat.getLiczbaTransakcji(); i++) {
                        bankomat.getTransakcja(i)->wypisz("  ");
                    }
                    break;

                case 8:
                    std::system("cls");
                    if (znalezionaKarta->getBlokada() == false) {
                        std::cout << "Karta nie jest zablokowana." << std::endl;
                    }
                    else {
                        std::cout << "Karta jest zablokowana." << std::endl;
                    }
                    break;

                case 9:
                    koniec = true;
                    break;
                default:
                    std::system("cls");
                    std::cout << "Nieprawidlowa opcja." << std::endl;
                    break;

                }

            }
            else {
                std::system("cls");
                std::cout << "Tryb pracy bankomatu: serwisowy." << std::endl;
                std::cout << "\nWybierz opcje." << std::endl;
                std::cout << "1. Uzupelnij zasoby." << std::endl;
                std::cout << "2. Wyjscie." << std::endl;
                int numer = wczytajIntDoSkutku(1, 2);
                switch (numer) {
                case 1: {
                    std::system("cls");
                    std::vector<int> iloscBanknotow(bankomat.getLiczbaNominalow());
                    std::cout << "Podaj liczbe wplacanych banknotow: " << std::endl;
                    for (int i = 0; i < iloscBanknotow.size(); i++) {
                        std::cout << bankomat.getWartoscNominalu(i) << ": ";
                        iloscBanknotow[i] = wczytajIntDoSkutku(0, 10);

                    }
                    int kwota{ 0 };
                    for (int i = 0; i < iloscBanknotow.size(); i++) {
                        kwota = kwota + (bankomat.getWartoscNominalu(i) * iloscBanknotow[i]);
                    }
                    std::cout << "Laczna kwota wplacona: " << kwota << "." << std::endl;
                    bankomat.wplac(iloscBanknotow);
                    break;

                }
                case 2: 
                    koniec = true;
                    break;
                
                }
            }


        }
        Zapisz(&bank, &bankomat, "plik3.txt");
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testBankomat1() {
    Bank bank;
    Bankomat bankomat{ &bank };
    bankomat.wypiszZasoby("  ");
    std::vector<Nominal> nominaly = bankomat.wyplac(5000000);
    for (int i = 0; i < nominaly.size(); i++) {
        std::cout << "Wartosc: " << nominaly[i].getWartosc() << " ," << "Ilosc: " << nominaly[i].getIlosc() << std::endl;
    }
    bankomat.wypiszZasoby("  ");
}

std::string PobObecnaDate() {
    std::time_t now = std::time(nullptr);
    char buf[sizeof "YYYY-MM-DD"];
    std::strftime(buf, sizeof buf, "%Y-%m-%d", std::localtime(&now));

    return std::string(buf);
};

int main() {
    start();
}