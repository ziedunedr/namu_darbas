#include "funkcijos.h"
#include "struktura.h"
#include <string>
#include <iomanip>
#include <iostream>

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

	/////V.0.1 isvedimas i ekrana
	std::cout.width(15); std::cout << std::left << "Vardas";
	std::cout.width(15); std::cout << std::left   << "Pavarde";
	if (kr == 'M' || kr == 'm')////// V.0.1 tik vienas pasirinktas Galutinis (Vid.) arba Galutinis (Med.) yra išvedamas
	{
		std::cout.width(15); std::cout << std::right << "Galutinis (Med.)";
	}
	else if (kr == 'v' || kr == 'V')
	{
		std::cout.width(15); std::cout << std::right << "Galutinis (Vid.)";
	}
	cout << endl;

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
