#include"funkcijos.h"
#include <iostream>

using namespace std;
int main()
{
	int failasArVartotojasIvesReiksmes;
	cout << "Jei irasus prideti is failo spauskite '1', jei noresite prideti patys - '2'?" << endl;
	cin >> failasArVartotojasIvesReiksmes;
	if (failasArVartotojasIvesReiksmes == 1)
	{
		readFromFile();
	}
	else if (failasArVartotojasIvesReiksmes == 2)
	{
		meniu();
	}
    
    return 0;
}
