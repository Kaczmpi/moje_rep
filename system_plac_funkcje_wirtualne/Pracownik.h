#ifndef Pracownik_h_
#define Pracownik_h
#include <string>
using std::string;

class Pracownik{
	private:
		string imie;
		string nazwisko;
		string nip;
		string pesel;
	public:
		Pracownik(string im="brak", string naz="brak", string ni="brak", string pe="brak");
		virtual void wypisz() const;
		virtual void wylicz_zarobki();
		virtual ~Pracownik();
};

class Stale : public Pracownik{
	private:
		double pensja;
	public:
		Stale(string im, string naz, string ni, string pe, double pens);
		virtual void wypisz() const;
		virtual void wylicz_zarobki();
		~Stale();
};

class Zlecenie : public Pracownik{
	private:
		double pensja;
		double stawka;
		double godziny;
	public:
		Zlecenie(string im, string naz, string ni, string pe, double staw, double godz);
		virtual void wypisz() const;
		virtual void wylicz_zarobki();
		~Zlecenie();
};

class Handlowiec : public Pracownik{
	private:
		double pensja;
		double sprzedarz;
		double procent;
	public:
		Handlowiec(string im, string naz, string ni, string pe, double sprzed, double pro);
		virtual void wypisz() const;
		virtual void wylicz_zarobki();
		~Handlowiec();
};

#endif
