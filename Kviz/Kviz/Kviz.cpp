#include "Kviz.h"

Kviz::Kviz()
{
	Bodovi = 0; //Namjestamo bodove i broj pitanaja na 0
	BrojPitanja = 0;
	IskoristioJokerPolaPola = false;
	IskoristioJokerZovi = false;
}

Kviz::~Kviz()
{
}

void Kviz::UcitajPitanja()
{
	ifstream file("Pitanja.txt"); //Otvaranje datoteke
	string str; //Kreiramo privremene varijable
	int i = 1;
	while (getline(file, str)) //Ucitavamo red po red i spremamo tekst u str varijablu
	{
		Pitanja.push_back(Pitanje(i,str)); //.push_back()-dodajemo novi objekt klase Pitanje u vector Pitanja
		i++; //Povecavamo brojac za redni broj pitanja
		BrojPitanja++; //Povecavamo brojac za ukupan broj pitanja
	}
	file.close(); //Zatvaramo datoteku
}

void Kviz::FiltrirajPitanja()
{
	vector<Pitanje> temp;
	srand(time(NULL));
	int brPitanja = Pitanja.size() / 2;
	for (int i = 0; i < brPitanja; i++)
	{
		int randNum = rand() % (Pitanja.size() - 1);
		temp.push_back(Pitanja[randNum]);
		Pitanja.erase(Pitanja.begin() + randNum);
	}
	Pitanja = temp;

	for (int i = 0; i < Pitanja.size(); i++)
	{
		Pitanja[i].RedniBroj = i + 1;
	}

	BrojPitanja = Pitanja.size();
}

void Kviz::PovecajBodove()
{
	Bodovi++; //Povecavamo broj bodova
}

void Kviz::UrediPitanje(int Index)
{
	system("cls");
	string Tekst;
	int Tocan;

	cout << "Unesite pitanje:" << endl;
	cin.ignore(); //Uklanjamo "novi red" stream buffer-a.
	getline(cin, Tekst); //getline-unosi i sprema tekst u Tekst varijablu 
	Pitanja[Index].TekstPitanja = Tekst;
	cout << endl <<"Unesite prvi odgovor:" << endl;
	getline(cin, Tekst); //getline-unosimo odgovore
	Pitanja[Index].PonudjeniOdgovori[0] = Tekst;
	cout << endl << "Unesite drugi odgovor:" << endl;
	getline(cin, Tekst);
	Pitanja[Index].PonudjeniOdgovori[1] = Tekst;
	cout << endl << "Unesite treci odgovor:" << endl;
	getline(cin, Tekst);
	Pitanja[Index].PonudjeniOdgovori[2] = Tekst;
	cout << endl << "Unesite cetvrti odgovor:" << endl;
	getline(cin, Tekst);
	Pitanja[Index].PonudjeniOdgovori[3] = Tekst;
	cout << endl << "Unesite broj tocnog odgovora (1-4):" << endl;
	cin >> Tocan; //Unosimo broj tocnog odgovora
	Pitanja[Index].TocanOdgovor = Tocan;

}

void Kviz::ObrisiPitanje(int Index)
{
	Pitanja.erase(Pitanja.begin() + Index); //Brisemo pitanje sa liste i smanjujemo broj pitanja za 1
	BrojPitanja--;
}

void Kviz::SpremiPitanjaUDatoteku()
{
	ofstream file; //Kreiramo objekt za upis u datoteku
	file.open("Pitanja.txt", ofstream::out | ofstream::trunc); //Otvaramo datoteku.Brisemo sav sadrzaj prilikom otvaranja programa

	for each(Pitanje p in Pitanja) //Za svako pitanje ispisujemo formatirani upis u datoteku
	{
		file << p.IspisZaDatoteku(); 
	}

	file.close(); //Zatvaramo datoteku
}

void Kviz::DodajPitanje()
{
	Pitanje tempPitanje(BrojPitanja + 1); //Kreiramo prazni objekt samo za redni broj

	string Tekst; 
	int Tocan; 

	cout << "Unesite pitanje:" << endl;
	cin.ignore(); //Uklanjamo "novi red" stream buffer-a.
	getline(cin, Tekst); //getline-unosi i sprema tekst u Tekst varijablu
	tempPitanje.TekstPitanja = Tekst;
	cout << endl << "Unesite prvi odgovor:" << endl;
	getline(cin, Tekst); //getline-unosimo odgovore
	tempPitanje.PonudjeniOdgovori.push_back(Tekst); //push_back()-dodajemo stringu vector ponudenih odgovora
	cout << endl << "Unesite drugi odgovor:" << endl;
	getline(cin, Tekst);
	tempPitanje.PonudjeniOdgovori.push_back(Tekst);
	cout << endl << "Unesite treci odgovor:" << endl;
	getline(cin, Tekst);
	tempPitanje.PonudjeniOdgovori.push_back(Tekst);
	cout << endl << "Unesite cetvrti odgovor:" << endl;
	getline(cin, Tekst);
	tempPitanje.PonudjeniOdgovori.push_back(Tekst);
	cout << endl << "Unesite broj tocnog odgovora (1-4):" << endl;
	cin >> Tocan; //Unosimo broj tocnog odgovora
	tempPitanje.TocanOdgovor = Tocan;

	Pitanja.push_back(tempPitanje); //Dodajemo pitanje u vector
	BrojPitanja++;
}
