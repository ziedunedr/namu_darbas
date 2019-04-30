#include "v04.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <fstream>

using namespace std;
struct new_IR
{
	string var;
	string pav;
	double egz;
	double gal;
	double vid;
};

void generateAndPrintStudents()
{
	clock_t tStart = clock();
	ofstream vargsiukai;
	ofstream kietiakai;
	kietiakai.open("kietiakai.txt");
	vargsiukai.open("vargsiukai.txt");
	int duomenuSkaicius;
	int pazymiuSkaicius;
	new_IR ir_temp;

	cout << "Iveskite kiek duomenu generuoti: "; /////V.0.1 nuskaitom egzamina
	cin >> duomenuSkaicius;

	cout << "Iveskite kiek pazymiu studentui generuoti: "; /////V.0.1 nuskaitom egzamina
	cin >> pazymiuSkaicius;

	try {
		if (cin.fail()) {
			throw "error";
		}
		std::string base;
		base.assign(46, '-');
		vargsiukai << setw(15) << left << "Vardas";
		vargsiukai << setw(15) << left << "Pavarde";
		vargsiukai << setw(15) << right << "Galutinis (Vid.)" << endl;
		vargsiukai << base << endl;

		kietiakai << setw(15) << left << "Vardas";
		kietiakai << setw(15) << left << "Pavarde";
		kietiakai << setw(15) << right << "Galutinis (Vid.)" << endl;
		kietiakai << base << endl;

		for (int i = 0; i < duomenuSkaicius; i++)
		{
			ir_temp.var = "Vardas" + to_string(i);
			ir_temp.pav = "Pavarde" + to_string(i);

			ir_temp.egz = rand() % 10 + 1;
			ir_temp.vid = 0;
			for (int j = 0; j < pazymiuSkaicius; j++)
			{
				ir_temp.vid += rand() % 10 + 1;
			}

			ir_temp.vid = ir_temp.vid / pazymiuSkaicius;
			ir_temp.gal  = ir_temp.vid * 0.4 + ir_temp.egz * 0.6;

			if (ir_temp.gal >= 5)
			{
				kietiakai << left << setw(15) << ir_temp.var << setw(15) << ir_temp.pav << right << setw(5) << ir_temp.gal << endl;
			}
			else
			{
				vargsiukai << left << setw(15) << ir_temp.var << setw(15) << ir_temp.pav << right << setw(5) << ir_temp.gal << endl;
			}

		}
		vargsiukai.close();
		kietiakai.close();
		cout << "Laikas:" << (double)(clock() - tStart) / CLOCKS_PER_SEC;
	}
	catch (char* error) { /////V.0.3 Blogai ivesta vartotojo duomenys, baigiam programos darba
		cout << error << endl;
		return;
	}
}