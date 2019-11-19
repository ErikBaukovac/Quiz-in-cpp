#include "Kviz.h"

using namespace std;

void IgrajKviz();//Funkcija za igranje kviza
void UrediPitanja();//Funkcija za uredivanje pitanja
bool ProvjeraPonudjenogOdgovora(int, int, int, bool, bool);
bool ProvjeraUnosa(int, int, int);

int main() {

	int Odabir = 0; //Varijabla za odabir
	while (Odabir != 3) //While petlja za unos
	{
		system("cls"); //Funkcija za ciscenje ekrana 
		cout << "Dobrodosli.\nOdaberite redni broj ispred akcije:"<<endl<<endl;
		cout << "1. Igraj kviz" << endl;
		cout << "2. Uredi pitanja" << endl;
		cout << "3. Izlaz" << endl;

		cin >> Odabir; 

		if (ProvjeraUnosa(Odabir, 1, 3))
		{
			if (Odabir == 1)
			{
				IgrajKviz(); //Poziv funkcije za igranje kviza


				Odabir = 0;
			}
			if (Odabir == 2)
			{
				UrediPitanja(); //Poziv funkcije za uredivanje pitanja

				Odabir = 0;
			}

		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			Odabir = 0;
		}


	}
	system("cls");


	cout << "Hvala na igranju!" << endl; 
}

void IgrajKviz()
{
	Kviz Kviz; //inicijalizacija objekta klase Kviz
	Kviz.UcitajPitanja(); //Uèitavanje pitanja iz datoteke.
	Kviz.FiltrirajPitanja();
	int Odgovor = 0;
	for each(Pitanje p in Kviz.Pitanja) //Za svako Pitanje p (privremena varijabla) iz kolekcije Pitanja
	{
		while (Odgovor < 1 || Odgovor > 6)
		{
			system("cls");
			p.Ispis(); //Poziv funkcije klase

			if (Odgovor == -5)
			{
				p.JokerZovi();
			}

			if(!Kviz.IskoristioJokerZovi)
				cout << "\n5) Joker zovi" << endl;

			if (!Kviz.IskoristioJokerPolaPola)
				cout << "\n6) Joker pola-pola" << endl;

			cout << endl;
			cin >> Odgovor;
			
			if (ProvjeraPonudjenogOdgovora(Odgovor, 1, 6, Kviz.IskoristioJokerPolaPola, Kviz.IskoristioJokerZovi))
				switch (Odgovor)
				{
				case 1:
				case 2:
				case 3:
				case 4:
					if (p.PonudjenOdgovor(Odgovor))
					{
						Kviz.PovecajBodove(); //Funkcija za povecanje bodova 
						cout << endl << "Bravo, tocan odgovor!" << endl << endl;
					}

					else
					{
						cout << endl << "Vas odgovor nije tocan!\nTocan odgovor je pod rednim brojem " << p.TocanOdgovor << ". " << p.IspisiTocanOdgovor() << endl << endl;
					}

					system("Pause");

					break;
				case 5:
					Odgovor = -5;
					Kviz.IskoristioJokerZovi = true;
					break;
				case 6:
					p.JokerPolaPola();
					Kviz.IskoristioJokerPolaPola = true;
					Odgovor = 0;
					break;
				}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				Odgovor = 0;
			}

		}
		Odgovor = 0;
	}
	system("cls");
	cout << "Vas rezultat: " << Kviz.Bodovi << "/" << Kviz.BrojPitanja <<endl<<endl;
	cout << "Vas rezultat: " << Kviz.Bodovi * 100 / Kviz.BrojPitanja <<"%"<< endl << endl;
	system("Pause");

}

void UrediPitanja()
{
	Kviz Kviz;
	Kviz.UcitajPitanja();
	int OdabranoPitanje = 0; //Odabir pitanja ili izlaz
	int OdabranaAkcija = 0; //Odabrana akcija
	while (OdabranoPitanje != Kviz.BrojPitanja + 2) //Sve dok nije odabran povratak
	{
		int j = 1; //Unutarnji brojac koji se koristi se za brisanje Npr. Ako se obrise prvo pitanje onda æe prvo pitanje i dalje imati redni broj 2. ali ce se pristupati tome pitanju s 1 pa bude problem
		system("cls");
		for each(Pitanje p in Kviz.Pitanja)
		{
			cout << j << ". ";
			p.IspisiTekstPitanja();
			j++;
		}
		cout << endl;
		cout << Kviz.BrojPitanja + 1 << ". Dodaj pitanje" << endl;
		cout << Kviz.BrojPitanja + 2 << ". Povratak" << endl << endl;

		cin >> OdabranoPitanje;

		if (ProvjeraUnosa(OdabranoPitanje, 1, Kviz.BrojPitanja + 2))
		{
			if (OdabranoPitanje > 0 && OdabranoPitanje <= Kviz.BrojPitanja)
			{
				while (OdabranaAkcija != 3)
				{
					system("cls");
					Kviz.Pitanja[OdabranoPitanje - 1].Ispis();
					cout << endl;
					cout << "Odaberite redni broj ispred akcije:" << endl << endl;
					cout << "1. Uredi pitanje!" << endl;
					cout << "2. Obrisi pitanje!" << endl;
					cout << "3. Izlaz!" << endl << endl;

					cin >> OdabranaAkcija;

					if (ProvjeraUnosa(OdabranaAkcija, 1, 3))
					{

						if (OdabranaAkcija == 1)
							Kviz.UrediPitanje(OdabranoPitanje - 1);
						if (OdabranaAkcija == 2)
						{
							Kviz.ObrisiPitanje(OdabranoPitanje - 1);
							break;
						}
					}
					else
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						OdabranaAkcija = 0;
					}


				}
				OdabranaAkcija = 0; //Vracanje unosa na 0
			}

			if (OdabranoPitanje == Kviz.BrojPitanja + 1)
			{
				system("cls");
				Kviz.DodajPitanje(); //Funkcija za dodavanje pitanja
			}
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			OdabranoPitanje = 0;
		}

	}
	OdabranoPitanje = 0;
	system("cls");
	OdabranaAkcija = 0;
	while (OdabranaAkcija != 1 && OdabranaAkcija != 2)
	{
		cout << "Zelite li spremiti vase promjene?" << endl << endl; //Mogucnost spremanja promjena
		cout << "1. Da" << endl;
		cout << "2. Ne" << endl << endl;

		cin >> OdabranaAkcija;

		if (ProvjeraUnosa(OdabranaAkcija, 1, 2))
		{
			if (OdabranaAkcija == 1)
			{
				Kviz.SpremiPitanjaUDatoteku(); //Funkcija za spremanje promjena
			}
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			OdabranaAkcija = 0;
		}
	}

}



bool ProvjeraPonudjenogOdgovora(int odg, int min, int max, bool jokerpp, bool jokerz)
{
	bool dobarOdg = false;
	for (int i = min; i <= max; i++)
	{
		if (odg == i)
		{
			if (i >= 1 && i <= 4)
				dobarOdg = true;
			if (i == 5 && !jokerz)
				dobarOdg = true;
			if (i == 6 && !jokerpp)
				dobarOdg = true;

			break;
		}
	}


	return dobarOdg;

}

bool ProvjeraUnosa(int unos, int min, int max)
{
	bool dobarUnos = false;
	for (int i = min; i <= max; i++)
	{
		if (unos == i)
		{
			dobarUnos = true;
			break;
		}
	}

	return dobarUnos;
}
