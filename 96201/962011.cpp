
//
//  main.cpp
//  PointClass
//
//  Created by ardavan on 4/26/18.
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#include <iostream>
using namespace std;
class point {
public:
    double x,y,z;
    point (double x=0,double y=0,double z=0){
        this->x=x;
        this->y=y;
        this->z=z;
    }
    void makeAPoint (void){
        cout<<"Enter X of your point : ";
        cin>>this->x;
        cout<<"Enter Y of your point : ";
        cin>>this->y;
        cout<<"Enter Z of your point : ";
        cin>>this->z;
    }
    void movePoint (void) {
        int x,y,z;
        cout<<"Enter the X change : ";
        cin>>x;
        this->x=this->x+x;
        cout<<"Enter the Y change : ";
        cin>>y;
        this->y=this->y+y;
        cout<<"Enter the Z change : ";
        cin>>z;
        this->z=this->y+y;
    }
    void printPoint (void){
        cout<<"Point : "<<"("<<this->x<<","<<this->y<<","<<this->z<<")\n";
    }
};
int main() {
    point p1;
    p1.makeAPoint();
    p1.printPoint();
    p1.movePoint();
    p1.printPoint();
    return 0;
}
