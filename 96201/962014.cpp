//
//  main.cpp
//  name
//
//  Created by ardavan on 4/27/18.
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;
class personalInformation {
public:
    string firstName;
    string midleName;
    string familyName;
    int birthdayMonth;
    int birthdayDay;
    int birthdayYear;
    string address;
    string postCode;
    string eMail;
    void inputPersonalInformation (void) {
        cout<<"Enter your first name : ";
        cin>>firstName;
        cout<<"Enter your midle name : ";
        cin>>midleName;
        cout<<"Enter your family name : ";
        cin>>familyName;
        cout<<"Enter your birthday day : ";
        cin>>birthdayDay;
        cout<<"Enter your birthday month : ";
        cin>>birthdayMonth;
        cout<<"Enter your birthday year : ";
        cin>>birthdayYear;
        cout<<"Enter your address : ";
        cin>>address;
        cout<<"Enter your post code : ";
        cin>>postCode;
        cout<<"Enter your email : ";
        cin>>eMail;
        cout<<"--------------------------------------------------------------\n";
    }
    void printPersonalInformation (void) {
        cout<<"First Name : "<<firstName<<endl;
        cout<<"Midle Name : "<<midleName<<endl;
        cout<<"Family Name : "<<familyName<<endl;
        cout<<"Birthday Time : "<<birthdayYear<<"/"<<birthdayMonth<<"/"<<birthdayDay<<endl;
        cout<<"Address : "<<address<<endl;
        cout<<"Post Code : "<<postCode<<endl;
        cout<<"Email : "<<eMail<<endl;
        cout<<"--------------------------------------------------------------\n";
    }
};
///////////////////////////////////////////////////////////////////////
void sortPersonalInformationsByFamilyName (personalInformation *P,int n);
void searchPersonalInformationsByFamilyName (personalInformation *P,int n);
///////////////////////////////////////////////////////////////////////
int main () {
    personalInformation *PI;
    int n,i;
    cout<<"How many personal information do you want to add ? ";
    cin>>n;
    PI=(personalInformation *)malloc(sizeof(personalInformation)*n);
    for(i=0;i<n;i++){
        cout<<"+------------------+\n";
        cout<<"|Person number "<<i+1<<" : |"<<endl;
        cout<<"+------------------+\n";
        PI[i].inputPersonalInformation();
    }
    for(i=0;i<n;i++){
        cout<<"+------------------+\n";
        cout<<"|Person number "<<i+1<<" : |"<<endl;
        cout<<"+------------------+\n";
        PI[i].printPersonalInformation();
    }
    cout<<"Sort with family name : \n";
    sortPersonalInformationsByFamilyName(PI,n);
    for(i=0;i<n;i++){
        cout<<"+------------------+\n";
        cout<<"|Person number "<<i+1<<" : |"<<endl;
        cout<<"+------------------+\n";
        PI[i].printPersonalInformation();
    }
    cout<<"Search for a family name : ";
    searchPersonalInformationsByFamilyName(PI, n);
    return 0;
}
//////////////////////////////////////////////////////////////////////////
void sortPersonalInformationsByFamilyName (personalInformation *P,int n){
    int i,j,k,a=0;
    personalInformation b[n];
    for(i=0;i<n;i++){
        for(j=0,a=0;j<n;j++){
            for(k=0;P[i].familyName[k];k++){
                if(P[i].familyName[k]>P[j].familyName[k]){
                    a++;
                    break;
                }
            }
        }
        b[a]=P[i];
    }
    for(i=0;i<n;i++){
        P[i]=b[i];
    }
}
/////////////////////////////////////////////////////////////////////////////
void searchPersonalInformationsByFamilyName (personalInformation *P,int n){
    int i;
    char a1,a2,a3,a4;
    cout<<"Please Press Enter after enter a character."<<endl;
    cout<<"Enter first character : ";
    cin>>a1;
    cout<<"Result : \n";
    for(i=0;i<n;i++){
        if(P[i].familyName[0]==a1){
            cout<<P[i].familyName<<endl;
        }
    }
    cout<<"Enter second character : ";
    cin>>a2;
    cout<<"Result : \n";
    for(i=0;i<n;i++){
        if(P[i].familyName[0]==a1&&P[i].familyName[1]==a2){
            cout<<P[i].familyName<<endl;
        }
    }
    cout<<"Enter third character : ";
    cin>>a3;
    cout<<"Result : \n";
    for(i=0;i<n;i++){
        if(P[i].familyName[0]==a1&&P[i].familyName[1]==a2&&P[i].familyName[2]==a3){
            cout<<P[i].familyName<<endl;
        }
    }
    cout<<"Enter fourth character : ";
    cin>>a4;
    cout<<"Result : \n";
    for(i=0;i<n;i++){
    if(P[i].familyName[0]==a1&&P[i].familyName[1]==a2&&P[i].familyName[2]==a3&&P[i].familyName[3]==a4){
            cout<<P[i].familyName<<endl;
        }
    }
}
