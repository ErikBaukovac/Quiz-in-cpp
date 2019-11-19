#include <string>
#include <vector>
#include <iostream>
using namespace std;
#pragma once
class Pitanje
{
public:
	int RedniBroj;
	string TekstPitanja;
	vector<string> PonudjeniOdgovori;
	int TocanOdgovor;

	Pitanje(int); //Konstruktor za Redni broj
	Pitanje(int,string); //Konstruktor za Redni broj i tekst pitanja
	~Pitanje();//Destruktor 

	void Ispis(); //Ispis pitanja i odgovora
	bool PonudjenOdgovor(int); //bool-moze biti samo tocno ili netocno.Provjeravamo tocnost odgovora
	string IspisiTocanOdgovor(); //Vraca tocan odgovor 
	void IspisiTekstPitanja(); //Ispis pitanja
	string IspisZaDatoteku(); //Upis u datoteku
	void JokerZovi();
	void JokerPolaPola();
};