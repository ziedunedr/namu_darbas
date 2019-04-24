#ifndef STRUKTURA_H_INCLUDED
#define STRUKTURA_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct ir{
    string var,pav;
    vector <int> paz;
    double vid,med;
    void pild();
};

void ir::pild(){
    int itemp;
    cout << "Vardas: ";
    cin>>var;
    cout << "Pavarde: ";
    cin>>pav; paz.clear();
    do{
       cout << "ND: ";
       cin>>itemp;
        if (itemp>0 && itemp<=10)
                paz.push_back(itemp);
    }while (itemp!=0) ;
    vid=0;
    for (int i : paz)
        vid +=i;
    vid=double(vid)/paz.size();
    sort(paz.begin(),paz.end());
    med = ( paz.size()%2 ==1)? paz[paz.size()/2]:double(paz[paz.size()/2]+paz[paz.size()/2 -1])/2;
}


#endif // STRUKTURA_H_INCLUDED
