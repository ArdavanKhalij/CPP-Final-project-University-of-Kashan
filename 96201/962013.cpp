//
//  main.cpp
//  V=RI
//
//  Created by ardavan on 4/26/18.
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#include <iostream>
using namespace std;
class v {
private:
    double R;
public:
    v (){this->R=R;}
    double I,V,P;
    void inputR (void){
        cout<<"Enter R : ";
        cin>>R;
    }
    void calculatI (void) {
        cout<<"Enter V : ";
        cin>>V;
        I=V/R;
        cout<<"I = "<<I<<endl;
    }
    double calculatV (void) {
        cout<<"Enter I : ";
        cin>>I;
        V=I*R;
        cout<<"V = "<<V<<endl;
        return V;
    }
    void calculatP (void) {
        P=I*this->calculatV();
        cout<<"P = "<<P<<endl;
    }
};
int main () {
    v v1;
    v1.inputR();
    v1.calculatI();
    v1.calculatV();
    v1.calculatP();
    return 0;
}
