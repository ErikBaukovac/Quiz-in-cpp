#include "Pitanje.h"

Pitanje::Pitanje(int Rb) //Zovemo konstruktor za Redni broj
{
	RedniBroj = Rb;
}

Pitanje::Pitanje(int Rb, string Linija) //Zovemo konstruktor za Redni broj i tekst Pitanja
{
	RedniBroj = Rb; //Varijabla za Redni broj
	string delimiter = ","; //Delimiter sluzi da program raspozna pitanje od odgovora

	TekstPitanja = Linija.substr(0, Linija.find(delimiter)); //substr-funkcija za vadenje dijela pitanja koji je oznacen
	Linija.erase(0, Linija.find(delimiter) + delimiter.length()); //Brisemo dio pitanja i delimiter koji smo izvadili

	PonudjeniOdgovori.push_back(Linija.substr(0, Linija.find(delimiter)));//Ponavljamo proces dok ne dobijemo sve informacije
	Linija.erase(0, Linija.find(delimiter) + delimiter.length());

	PonudjeniOdgovori.push_back(Linija.substr(0, Linija.find(delimiter)));
	Linija.erase(0, Linija.find(delimiter) + delimiter.length());

	PonudjeniOdgovori.push_back(Linija.substr(0, Linija.find(delimiter)));
	Linija.erase(0, Linija.find(delimiter) + delimiter.length());

	PonudjeniOdgovori.push_back(Linija.substr(0, Linija.find(delimiter)));
	Linija.erase(0, Linija.find(delimiter) + delimiter.length());

	TocanOdgovor = stoi(Linija); //stoi-kratica za string to integer
}

Pitanje::~Pitanje()
{
}

void Pitanje::Ispis()

{
	cout << RedniBroj << ". " << TekstPitanja << endl; //Ispisujemo redni broj i tekst pitanja
	for (unsigned int i = 1; i <= PonudjeniOdgovori.size(); i++) //I ispisujemo redni broj i tekst odgovora
		cout << i << ") " << PonudjeniOdgovori[i - 1] << endl;
	cout << endl;
}

bool Pitanje::PonudjenOdgovor(int Odgovor)
{
	if (Odgovor == TocanOdgovor) //Provjera tocnosti odgovora
		return true; // Tocan
	return false; // Pogresan
}

string Pitanje::IspisiTocanOdgovor()
{
	return PonudjeniOdgovori[TocanOdgovor - 1]; //Vracamo tocan odgovor
}

void Pitanje::IspisiTekstPitanja()
{
	cout << TekstPitanja << endl; //Ispis pitanja
}

string Pitanje::IspisZaDatoteku()//formatiranje stringa za pravilan upis
{
	string r = TekstPitanja + "," + PonudjeniOdgovori[0] + "," + PonudjeniOdgovori[1] + "," + PonudjeniOdgovori[2] + "," + PonudjeniOdgovori[3] + "," + to_string(TocanOdgovor) + "\n";
	return r;
}

void Pitanje::JokerZovi()
{
	cout << "\nPrijatelj: Tocan odgovor je " << PonudjeniOdgovori[TocanOdgovor - 1] << endl;
}

void Pitanje::JokerPolaPola()
{
	while (PonudjeniOdgovori.size() > 2)
	{
		int randNum = rand() % PonudjeniOdgovori.size();

		if (randNum != TocanOdgovor - 1)
		{
			if (randNum < TocanOdgovor - 1)
			{
				TocanOdgovor--;
			}
			PonudjeniOdgovori.erase(PonudjeniOdgovori.begin() + randNum);
		}
	}
}