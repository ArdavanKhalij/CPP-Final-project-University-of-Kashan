//
//  main.cpp
//  ShapesClass
//
//  Created by ardavan on 4/26/18.
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#include <iostream>
#include <cmath>
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
    void movePoint (double a,double b,double c) {
        this->x=this->x+x;
        this->y=this->y+y;
        this->z=this->y+y;
    }
    void printPoint (void){
        cout<<"Point : "<<"("<<this->x<<","<<this->y<<","<<this->z<<")\n";
    }
    point operator + (point c){
        point b;
        b.x=c.x+this->x;
        b.y=c.y+this->y;
        b.z=c.z+this->z;
        return b;
    }
    point operator - (point c){
        point b;
        b.x=c.x-this->x;
        b.y=c.y-this->y;
        b.z=c.z-this->z;
        return b;
    }
};
class shape {
public:
    double s,p;
};
class circle:public shape,public point {
public:
    double r;
    point o;
    void inputTheCenterOfCircle (void) {
        o.makeAPoint();
    }
    void moveCircle (void) {
        double a,b,c;
        cout<<"Enter x : ";
        cin>>a;
        cout<<"Enter y : ";
        cin>>b;
        cout<<"Enter z : ";
        cin>>c;
        o.movePoint(a,b,c);
    }
    void sCalculating (void) {
        s=3.14*r*r;
    }
    void ppCalculating (void) {
        p=2*3.14*r;
    }
};
class triangle:public shape {
    point a,b,c;
    double ta,tb,tc;
    void inputPointsOfTriangle (void){
        a.makeAPoint();
        b.makeAPoint();
        c.makeAPoint();
    }
    void inputAngles (void) {
        cout<<"Enter first angle : ";
        cin>>ta;
        cout<<"Enter seccond angle : ";
        cin>>tb;
        cout<<"Enter third angle : ";
        cin>>tc;
        while(ta+tb+tc!=180){
            cout<<"Your angles are young \n";
            cout<<"Enter first angle : ";
            cin>>ta;
            cout<<"Enter seccond angle : ";
            cin>>tb;
            cout<<"Enter third angle : ";
            cin>>tc;
        }
    }
    void moveTriagle (void) {
        double x,y,z;
        cout<<"Enter x : ";
        cin>>x;
        cout<<"Enter y : ";
        cin>>y;
        cout<<"Enter z : ";
        cin>>z;
        a.movePoint(x, y, z);
        b.movePoint(x, y, z);
        c.movePoint(x, y, z);
    }
    void sCalculating (void) {
        point ab,ac;
        ab=b-a;
        ac=c-a;
        s=sqrt(pow(ab.x, 2)+pow(ab.y, 2)+pow(ab.z, 2))*sqrt(pow(ac.x, 2)+pow(ac.y, 2)+pow(ac.z, 2))*0.5*sin(ta);
    }
    void ppCalculating (void) {
        point ab,ac,bc;
        ab=b-a;
        ac=c-a;
        bc=c-b;
        p=sqrt(pow(ab.x, 2)+pow(ab.y, 2)+pow(ab.z, 2))+sqrt(pow(ac.x, 2)+pow(ac.y, 2)+pow(ac.z, 2))+sqrt(pow(bc.x, 2)+pow(bc.y, 2)+pow(bc.z, 2));
    }
};
class rectangle:public shape {
    point a,b,c,d;
    void inputPointsOfRectriangle (void){
        a.makeAPoint();
        b.makeAPoint();
        c.makeAPoint();
        d.makeAPoint();
    }
    void MoveRectangle (void) {
        double x,y,z;
        cout<<"Enter x : ";
        cin>>x;
        cout<<"Enter y : ";
        cin>>y;
        cout<<"Enter z : ";
        cin>>z;
        a.movePoint(x, y, z);
        b.movePoint(x, y, z);
        c.movePoint(x, y, z);
        d.movePoint(x, y, z);
    }
    void sCalculating (void) {
        point ab,ac;
        ab=b-a;
        ac=c-a;
        s=sqrt(pow(ab.x, 2)+pow(ab.y, 2)+pow(ab.z, 2))*sqrt(pow(ac.x, 2)+pow(ac.y, 2)+pow(ac.z, 2));
    }
    void ppCalculating (void) {
        point ab,ac;
        p=(sqrt(pow(ab.x, 2)+pow(ab.y, 2)+pow(ab.z, 2))+sqrt(pow(ac.x, 2)+pow(ac.y, 2)+pow(ac.z, 2)))*2;
    }
};
int main() {
    return 0;
}
