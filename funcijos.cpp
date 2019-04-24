#include "funkcijos.h"
#include "struktura.h"

void meniu()
{
    ir ir_temp; vector<ir> lentele; char kr;
    do{
        ir_temp.pild();
        lentele.push_back(ir_temp);
        cout << "Kitas irasas? T/n: ";
       cin>>kr;
    }while (kr=='t' || kr=='T');


    for (ir i : lentele){
        cout<<i.var<<endl;
        cout<<i.pav<<endl;
        cout<<i.vid<<endl;
        cout<<i.med<<endl;
        for (int j : i.paz)
                    cout<<j<<" | ";
        cout<<endl;
    }
}
