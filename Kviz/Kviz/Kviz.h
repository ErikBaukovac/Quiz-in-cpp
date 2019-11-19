#include <fstream>
#include <time.h>
#include "Pitanje.h"
using namespace std;
#pragma once
class Kviz
{
public:
	int BrojPitanja;
	int Bodovi;
	bool IskoristioJokerZovi;
	bool IskoristioJokerPolaPola;

	vector<Pitanje> Pitanja;//vector-Dinamicka lista na koju se pomocu funkcija brisu i upisuju elementi
	Kviz(); //Konstruktor
	~Kviz(); //Destruktor
	void UcitajPitanja(); //Ucitavamo pitanja u program
	void FiltrirajPitanja(); //Nasumican odabir pitanja
	void PovecajBodove(); //Povecavamo bodove
	void UrediPitanje(int); //Uredujemo pitanja
	void ObrisiPitanje(int); //Brisanje pitanja
	void SpremiPitanjaUDatoteku(); //Spremanje u datoteku 
	void DodajPitanje();//Dodavanje novih pitanja
};
