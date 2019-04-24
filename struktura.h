#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

struct ir{
    string var,pav;
	int egz;
    vector <int> paz;
    double vid,med;
    void pild();
	int pazArray[100];
};

void ir::pild(){
    int itemp;
	char autoGnr;
    cout << "Vardas: ";
    cin>>var;
    cout << "Pavarde: ";
    cin>>pav; 
	cout << "Balus generuoti automatiskai? T/n: ";
	cin >> autoGnr;
	int index = 0;
	if (autoGnr == 'T' || autoGnr == 't')/////V.0.1 ivertinimai generuojami atsitiktinai
	{
		egz = rand() % 10 + 1;
		for (size_t i = 0; i < 7; i++)
		{
			itemp = rand() % 10 + 1;
			paz.clear();
			if (itemp > 0 && itemp <= 10)
				pazArray[index] = itemp; /////V.0.1 pazymiu saugojimas i array
			index++;
			paz.push_back(itemp);
		}
	}
	else
	{
		cout << "Egzaminas: "; /////V.0.1 nuskaitom egzamina
		cin >> egz;
		paz.clear();
		do {
			cout << "ND: ";
			cin >> itemp;
			if (itemp > 0 && itemp <= 10)
				pazArray[index] = itemp; /////V.0.1 pazymiu saugojimas i array
			index++;
			paz.push_back(itemp);
		} while (itemp != 0);
	}
	
    vid=0;
    for (int i : paz)
        vid +=i;
    vid=(double(vid)/paz.size() * 0.4) + egz * 0.6; /////V.0.1 galutinio skaiciavimas
    sort(paz.begin(),paz.end());
    med = ( paz.size()%2 ==1)? paz[paz.size()/2]:double(paz[paz.size()/2]+paz[paz.size()/2 -1])/2;
}


#endif // STRUKTURA_H_INCLUDED
