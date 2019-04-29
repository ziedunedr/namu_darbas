#include "funkcijos.h"
#include "struktura.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

void meniu()
{
    ir ir_temp; vector<ir> lentele; char kr;
    do{
        ir_temp.pild();
        lentele.push_back(ir_temp);
        cout << "Kitas irasas? T/n: ";
       cin>>kr;
    }while (kr=='t' || kr=='T');

	cout << "Jei norite matyti galutini pagal medianna iveskite M; Jei norite matyti galutini pagal vidurki, iveskite V;";
	cin >> kr;

	std::string base;
	base.assign(48, '-');

	/////V.0.1 isvedimas i ekrana
	std::cout.width(15); std::cout << std::left << "Vardas";
	std::cout.width(15); std::cout << std::left   << "Pavarde";
	if (kr == 'M' || kr == 'm')////// V.0.1 tik vienas pasirinktas Galutinis (Vid.) arba Galutinis (Med.) yra išvedamas
	{
		std::cout.width(15); std::cout << std::right << "Galutinis (Med.)" << endl;
	}
	else if (kr == 'v' || kr == 'V')
	{
		std::cout.width(15); std::cout << std::right << "Galutinis (Vid.)" << endl;
	}
	std::cout << base << endl;

    for (ir i : lentele){
		std::cout.width(15); std::cout << std::left << i.var;
		std::cout.width(15); std::cout << std::left << i.pav;
		if (kr == 'M' || kr == 'm')
		{
			std::cout.width(15); std::cout << std::right << i.med << std::setprecision(2);
		}
		else if (kr == 'v' || kr == 'V')
		{
			std::cout.width(15); std::cout << std::right << i.vid << std::setprecision(2);
		}
		cout << endl;
    }
}

void printData(vector<ir> lentele)
{
	std::string base;
	base.assign(63, '-');
	std::cout.width(15); std::cout << std::left << "Vardas";
	std::cout.width(15); std::cout << std::left << "Pavarde";
	std::cout.width(15); std::cout << std::right << "Galutinis (Med.)";
	std::cout.width(15); std::cout << std::right << "Galutinis (Vid.)" << endl;
	std::cout << base << endl;

	for (ir i : lentele) {
		std::cout.width(15); std::cout << std::left << i.var;
		std::cout.width(15); std::cout << std::left << i.pav;
		std::cout.width(15); std::cout << std::right << i.med << std::setprecision(2);
		std::cout.width(15); std::cout << std::right << i.vid << std::setprecision(2);
		cout << endl;
	}
}

void readFromFile()
{
	ir ir_temp; vector<ir> lentele;
	int iterator = 0;
	string line;
	ifstream myfile("kursiokai.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);
		while (getline(myfile, line))
		{
			istringstream ss(line);
			int size = std::distance(std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>());
			ss.clear();
			ss.seekg(0, std::ios::beg);

			do {
				string word;
				ss >> word;
				if (iterator == 0)
				{
					ir_temp.var = word;
				}
				else if (iterator == 1)
				{
					ir_temp.pav = word;
				}
				else if (iterator == size - 1)
				{
					ir_temp.egz = stoi(word);
				}
				else if (word != "")
				{
					ir_temp.paz.push_back(stoi(word));
				}
				iterator++;
			} while (ss);
			ir_temp.vid = 0;
			for (int i : ir_temp.paz)
				ir_temp.vid += i;
			ir_temp.vid = (double(ir_temp.vid) / ir_temp.paz.size() * 0.4) + ir_temp.egz * 0.6;
			sort(ir_temp.paz.begin(), ir_temp.paz.end());
			ir_temp.med = (ir_temp.paz.size() % 2 == 1) ? ir_temp.paz[ir_temp.paz.size() / 2] : double(ir_temp.paz[ir_temp.paz.size() / 2] + ir_temp.paz[ir_temp.paz.size() / 2 - 1]) / 2;
			lentele.push_back(ir_temp);
			iterator = 0;
		}
		myfile.close();

		std::sort(lentele.begin(), lentele.end(), [](const ir &left, const ir &right)////studentu rikiavimas pagal abecele
		{ return (left.var < right.var); });

		printData(lentele);
	}

	else cout << "Failas nerastas.";
}

