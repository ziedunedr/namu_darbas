#include"funkcijos.h"
#include"v04.h"
#include <iostream>

using namespace std;
int main()
{
	int failasArVartotojasIvesReiksmes;
	cout << "Jei irasus prideti is failo spauskite '1', jei noresite prideti patys - '2', jei norite automatisko generavimo + isvedimo i atskirus failus, pasirinkite 3?" << endl;
	cin >> failasArVartotojasIvesReiksmes;
	if (failasArVartotojasIvesReiksmes == 1)
	{
		readFromFile();
	}
	else if (failasArVartotojasIvesReiksmes == 2)
	{
		meniu();
	}
	else if (failasArVartotojasIvesReiksmes == 3)
	{
		generateAndPrintStudents();
	}
	cout << endl << "Sistema baige darba" << endl;
    return 0;
}
