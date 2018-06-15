//
//  main.cpp
//  ardavan2
//
//  Created by ardavan on 6/15/18.
//  Copyright © 2018 Apple Inc. All rights reserved.
//
//////////////////////////////////////////////////////////////////////
//                          Ardavan Khalij                          //
//                            9621160013                            //
//                       Mohammad Jamal Asadi                       //
//                            9621160004                            //
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
//////////////////////////////////////////////////
using namespace std;
//////////////////////////////////////////////////
class date{
public:
    int year,month,day;
    friend istream& operator >> (istream&in,date &a);
    friend ostream& operator << (ostream&in,date &a);
};
//////////////////////////////////////////////////
class student{
public:
    char stnum[15];
    char fname[15];
    char lname[15];
    date birthday;
    friend istream& operator >> (istream&in,student &a);
    friend ostream& operator << (ostream&out,student &b);
};
//////////////////////////////////////////////////
class teacher{
public:
    int tnum;
    char fname[15];
    char lname[15];
    date t_estekhdam;
    friend istream& operator >> (istream&in,teacher &a);
    friend ostream& operator << (ostream&out,teacher &a);
};
//////////////////////////////////////////////////
class course{
public:
    int csnum;
    char cname[20];
    friend istream& operator >> (istream&in,course&a);
    friend ostream& operator << (ostream&out,course&a);
};
//////////////////////////////////////////////////
class teacher_course{
public:
    int tnum;
    int csnum;
    friend istream& operator >> (istream&in,teacher_course&a);
    friend ostream& operator << (ostream&out,teacher_course&a);
};
//////////////////////////////////////////////////
class student_course{
public:
    char stnum[15];
    int csnum;
    double grade;
    student_course (double x=200){
        grade=x;
    }
    friend istream& operator >> (istream&in,student_course&a);
    friend ostream& operator << (ostream&out,student_course&a);
    bool operator == (student_course &a){
        int q=0,ww,cc,mm=0;
        for(ww=0;stnum[ww];ww++);
        for(cc=0;a.stnum[cc];cc++);
        for(int f=0;f<15&&stnum[f]&&a.stnum[f];f++){
            if(a.stnum[f]==stnum[f]){
                q++;
            }
        }
        if(csnum==a.csnum&&grade==a.grade){
            mm=1;
        }
        if(q==ww&&q==cc&&mm==1){
            return true;
        }
        return false;
    }
};
//////////////////////////////////////////////////
int add_tch (int x,teacher *w);
int add_std (int x,student *w);
int add_crss (int x,course *w);
int add_tchs_crss (teacher *w,teacher_course *e,course *r,int tedad,int tc,int tt);
int add_stds_crss (student *w,student_course *e,course *r,int tedad,int tc,int ts);
int rem_stds_crss (student_course *w,int x);
bool moghayese (char a[],char b[]);
int disp_stds_crss (student_course *c,int tcs,student *b,int ts);
void dis_crss_stds (course *c,int ts,student_course *b,int tcs);
void showTeachers (void);
void showStudent (void);
void showCourse (void);
void disp_tchs_crss(void);
void std_average(void);
void cs_average(void);
void tchr_average(void);
void disp_tch_stds(void);
void disp_stds_tch(void);
//////////////////////////////////////////////////
class info{
public:
    teacher a[20];
    student b[200];
    course c[40];
    teacher_course d[600];
    student_course e[2000];
    int tn,sn,cn,tcn,scn;
    info(int tn=0,int sn=0,int cn=0,int tcn=0, int scn=0){
        this->tn=tn;
        this->sn=sn;
        this->cn=cn;
        this->tcn=tcn;
        this->scn=scn;
    }
    info (char*){
        ifstream f1("info.bin",ios::binary);
        f1.read((char *)&(*this), sizeof(info));
        f1.close();
    }
};
//////////////////////////////////////////////////
ostream& operator << (ostream&out,student_course&a){
    cout<<"The student number : ";
    out<<a.stnum;
    cout<<"The course number : ";
    out<<a.csnum;
    cout<<"The mark : ";
    out<<a.grade;
    return out;
}
ostream& operator << (ostream&out,teacher_course&a){
    cout<<"The teacher number : ";
    out<<a.tnum;
    cout<<"The course's number : ";
    out<<a.csnum;
    return out;
}
ostream& operator << (ostream &out,student &a){
    cout<<"First name : ";
    out<<a.fname<<" ";
    cout<<"Last name : ";
    out<<a.lname<<" ";
    cout<<"Student name : ";
    out<<a.stnum<<" ";
    cout<<"Student birthday date : "<<a.birthday<<endl;
    return out;
}
ostream& operator << (ostream&in,date &a){
    in<<a.year;
    cout<<"/";
    in<<a.month;
    cout<<"/";
    in<<a.day<<endl;
    return in;
}
ostream& operator << (ostream&out,course &a){
    cout<<"Course name : ";
    out<<a.cname<<" ";
    cout<<"Course number : ";
    out<<a.csnum<<endl;
    return out;
}
ostream& operator << (ostream&out,teacher &a){
    cout<<"teacher's number : ";
    out<<a.tnum;
    cout<<"teachers first name : ";
    out<<a.fname;
    cout<<"teachers last name : ";
    out<<a.lname;
    cout<<"teacher's recruitment date : "<<endl;
    cout<<a.t_estekhdam;
    return out;
}
//////////////////////////////////////////////////
istream& operator >> (istream&in,teacher_course&a){
    cout<<"Enter the teacher number : ";
    in>>a.tnum;
    cout<<"Enter the course's number : ";
    in>>a.csnum;
    return in;
}
istream& operator >> (istream&in,teacher &a){
    cout<<"Enter teacher's number: ";
    in>>a.tnum;
    cout<<"Enter teacher's first name: ";
    in>>a.fname;
    cout<<"Enter teacher's last name: ";
    in>>a.lname;
    cout<<"Enter the date of recruitment: ";
    cin>>a.t_estekhdam;
    return in;
}
istream& operator >> (istream&in,date &a){
    cout<<"Enter day: ";
    in>>a.day;
    cout<<"Enter month: ";
    in>>a.month;
    cout<<"Enter year: ";
    in>>a.year;
    return in;
}
istream& operator >> (istream&in,student &a){
    cout<<"Enter student's number: ";
    in>>a.stnum;
    cout<<"Enter student's first name: ";
    in>>a.fname;
    cout<<"Enter student's last name: ";
    in>>a.lname;
    cout<<"Enter student's birthday: ";
    cin>>a.birthday;
    return in;
}
istream& operator >> (istream&in,student_course&a){
    cout<<"Enter the student's number: ";
    in>>a.stnum;
    cout<<"Enter the course's number: ";
    in>>a.csnum;
    cout<<"Enter the student's mark in course number "<<a.csnum<<": ";
    in>>a.grade;
    return in;
}
istream& operator >> (istream&in,course&a){
    cout<<"Enter course's name: ";
    in>>a.cname;
    cout<<"Enter course'e number: ";
    in>>a.csnum;
    return in;
}
//////////////////////////////////////////////////
int main(){
    info a;
    char choose,yOrN='y';
    while(yOrN=='y'){
        cout<<"Hello and welcom.\n";
        cout<<"+--------------------------------------------------------------------------+\n";
        cout<<"|If you want to add a teacher enter 'a'.                                   |\n";//done
        cout<<"|If you want to add a student enter 'b'.                                   |\n";//done
        cout<<"|If you want to add a course for a teacher enter 'c'.                      |\n";//done
        cout<<"|If you want to add a course for a student enter 'd'.                      |\n";//done
        cout<<"|If you want to add a course enter 'e'.                                    |\n";//done
        cout<<"|If you want to delete a course for a student enter 'f'.                   |\n";//done
        cout<<"|If you want to see the informations of the students of a course,enter 'g'.|\n";//done
        cout<<"|If you want to see the course informations of a student enter 'h'.        |\n";//done
        cout<<"|If you want to see the courses of a teacher enter 'i'.                    |\n";//done
        cout<<"|If you want to see the avarege of a student enter 'j'.                    |\n";//done
        cout<<"|If you want to see the avarege of the courses of a student enter 'k'.     |\n";//done
        cout<<"|If you want to see the average of a teacher enter 'l'.                    |\n";//done
        cout<<"|If you want to see the students of a teacher enter 'm'.                   |\n";//done
        cout<<"|If you want to see the students enter 'n'                                 |\n";//done
        cout<<"|If you want to see the courses enter 'o'                                  |\n";//done
        cout<<"|If you want to see the teachers enter 'p'                                 |\n";//done
        cout<<"|If you want to see the teschers of a student enter 'q'.                   |\n";
        cout<<"+--------------------------------------------------------------------------+\n";
        cin>>choose;
        switch (choose) {
            case 'a'://DONE
                add_tch(a.tn, a.a);
                break;
            case 'b'://DONE
                add_std(a.sn, a.b);
                break;
            case 'c'://DONE
                add_tchs_crss(a.a, a.d, a.c, a.tcn, a.cn, a.tn);
                break;
            case 'd'://DONE
                add_stds_crss(a.b, a.e, a.c, a.scn, a.cn, a.sn);
                break;
            case 'e'://DONE
                add_crss(a.cn, a.c);
                break;
            case 'f':
                rem_stds_crss(a.e, a.scn);
                break;
            case 'g'://DONE
                disp_stds_crss(a.e, a.scn, a.b, a.sn);
                break;
            case 'h'://DONE
                dis_crss_stds(a.c, a.cn, a.e, a.scn);
                break;
            case 'i'://DONE
                disp_tchs_crss();
                break;
            case 'j'://DONE
                std_average();
                break;
            case 'k'://DONE
                cs_average();
                break;
            case 'l'://DONE
                tchr_average();
                break;
            case 'm'://DONE
                disp_tch_stds();
                break;
            case 'n'://DONE
                showStudent();
                break;
            case 'o'://DONE
                showCourse();
                break;
            case 'p'://DONE
                showTeachers();
                break;
            case 'q':
                disp_stds_tch();
                break;
            default://DONE
                cout<<"There is no such a commend. Try again later.\n";
                break;
        }
        cout<<"Do you want any thing else [y/n]?\n";
        cin>>yOrN;
    }
    return 0;
}
//////////////////////////////////////////////////
int add_tch (int x,teacher *w){//Done
    int xx;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"How many teachers do you want to add?\n";
    cin>>xx;
    for(int i=a.tn;i<a.tn+xx;i++){
        cin>>a.a[i];
    }
    a.tn=a.tn+xx;
    ofstream f2("info.bin",ios::binary);
    f2.write((char *)&a,sizeof(info));
    f2.close();
    return a.tn;
}
//////////////////////////////////////////////////
void showTeachers (void){//DONE
    info a;
    ifstream  f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    for(int i=0;i<a.tn;i++){
        cout<<a.a[i];
    }
    f1.close();
}
//////////////////////////////////////////////////
int add_std (int x,student *w){//DONE
    int xx;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"How many students do you want to add?\n";
    cin>>xx;
    for(int i=a.sn;i<a.sn+xx;i++){
        cin>>a.b[i];
    }
    a.sn=a.sn+xx;
    ofstream f2("info.bin",ios::binary);
    f2.write((char *)&a,sizeof(info));
    f2.close();
    return a.sn;
}
//////////////////////////////////////////////////
void showStudent (void){//DONE
    info a;
    ifstream  f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    for(int i=0;i<a.sn;i++){
        cout<<a.b[i];
    }
    f1.close();
}
//////////////////////////////////////////////////
int add_crss (int x,course *w){//DONE
    int xx;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"How many courses do you want to add?\n";
    cin>>xx;
    for(int i=a.cn;i<a.cn+xx;i++){
        cin>>a.c[i];
    }
    a.cn=a.cn+xx;
    ofstream f2("info.bin",ios::binary);
    f2.write((char *)&a,sizeof(info));
    f2.close();
    return a.cn;
}
//////////////////////////////////////////////////
void showCourse (void){//DONE
    info a;
    ifstream  f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    for(int i=0;i<a.cn;i++){
        cout<<a.c[i];
    }
    f1.close();
}
//////////////////////////////////////////////////
int add_tchs_crss (teacher *w,teacher_course *e,course *r,int tedad,int tc,int tt){//////
    int k,h=0,l=0;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"How many teacher_course do you want to add?\n";
    cin>>k;
    for(int i=a.tcn;i<a.tcn+k;i++){
        cin>>a.d[i];
        for(int j=0;j<a.cn;j++){
            if(a.d[i].csnum==a.c[j].csnum){
                h=1;
            }
        }
        if(h==0){
            cout<<"You enter the course number rong please enter your number again.\n";
        }
        for(int j=0;j<a.tn;j++){
            if(a.d[i].tnum==a.a[j].tnum){
                l=1;
            }
        }
        if(l==0){
            cout<<"You enter the teacher number rong please enter your number again.\n";
        }
        if(l==0||h==0){
            i--;
        }
    }
    a.tcn=a.tcn+k;
    ofstream f2("info.bin",ios::binary);
    f2.write((char *)&a,sizeof(info));
    f2.close();
    return a.tcn;
}
//////////////////////////////////////////////////
int add_stds_crss (student *w,student_course *e,course *r,int tedad,int tc,int ts){////////
    int k,h=0,l=0;
    info a;
    bool f;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"How many student_course do you want to add?\n";
    cin>>k;
    for(int i=a.scn;i<a.scn+k;i++){
        cin>>a.e[i];
        for(int j=0;j<a.cn;j++){
            if(a.e[i].csnum==a.c[j].csnum){
                h=1;
            }
        }
        if(h==0){
            cout<<"You enter the course number rong please enter your number again.\n";
        }
        for(int j=0;j<a.sn;j++){
            f=moghayese(a.b[j].stnum,a.e[i].stnum);
            if(f){
                l=1;
            }
        }
        if(l==0){
            cout<<"You enter the student number rong please enter your number again.\n";
        }
        if(l==0||h==0){
            i--;
        }
    }
    a.scn=a.scn+k;
    ofstream f2("info.bin",ios::binary);
    f2.write((char *)&a,sizeof(info));
    f2.close();
    return a.scn;
}
//////////////////////////////////////////////////
int rem_stds_crss (student_course *w,int x){
    int xx;
    info a;
    info b;
    student_course c[2000];
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"How many student_course do you want to delete?\n";
    cin>>xx;
    while(xx>a.scn){
        cout<<"There is not this many data to delete please enter again\n";
        cin>>xx;
    }
    for(int i=0;i<xx;i++){
        cin>>c[i];
        for(int j=0;j<a.scn;j++){
            if(c[i]==a.e[j]){
                for(int k=j;k<a.scn-1;k++){
                    a.e[k].csnum=a.e[k+1].csnum;
                    a.e[k].grade=a.e[k+1].grade;
                    for(int l=0;a.e[k].stnum[l];l++){
                        a.e[k].stnum[l]=a.e[k+1].stnum[l];
                    }
                    a.scn--;
                }
            }
        }
    }
    ofstream f2("info.bin",ios::binary);
    f2.write((char *)&a,sizeof(info));
    f2.close();
    return a.scn;
}
//////////////////////////////////////////////////
int disp_stds_crss (student_course *c,int tcs,student *b,int ts){/////
    int x;
    bool f;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"Enter the course number: ";
    cin>>x;
    cout<<"Here the information of the students of the course: \n";
    for(int i=0;i<a.scn;i++){
        if(a.e[i].csnum==x){
            for(int j=0;j<a.sn;j++){
                f = moghayese(a.b[j].stnum, a.e[i].stnum);
                if(f){
                    cout<<a.b[j];
                }
            }
        }
    }
    return a.scn;
}
//////////////////////////////////////////////////
bool moghayese (char a[],char b[]){/////////////////
    int i,j;
    for(i=0;a[i];i++);
    for(j=0;a[j];j++);
    if(i==j){
        for(int k=0;k<i;k++){
            if(a[k]!=b[k]){
                return false;
            }
        }
        return true;
    }
    return false;
}
//////////////////////////////////////////////////
void dis_crss_stds (course *c,int ts,student_course *b,int tcs){/////////
    char x[15];
    bool f;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"Enter the student number: ";
    cin>>x;
    cout<<"Here the information of the courses of the student: \n";
    for(int i=0;i<a.scn;i++){
        f=moghayese(x, a.e[i].stnum);
        if(f){
            for(int j=0;j<a.sn;j++){
                if(a.c[j].csnum==a.e[i].csnum){
                    cout<<a.c[j];
                }
            }
        }
    }
}
///////////////////////////////////////////////////
void disp_tchs_crss(void){
    int x;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"Entre the teacher num:";
    cin>>x;
    cout<<"here the info of the courses of teacher"<<endl;
    for( int i=0;i<a.tcn;i++){
        if(x==a.d[i].tnum){
            for(int j=0;j<a.cn;j++){
                if(a.c[j].csnum==a.e[i].csnum){
                    cout<<a.c[j];
                }
            }
        }
    }
}
///////////////////////////////////////////////////
void std_average(void){
    double sum=0;
    int sh=0;
    char x[15];
    info a;
    bool f;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"enter student num";
    cin>>x;
    cout<<"the average is:\n";
    for(int i=0;i<a.scn;i++){
        f=moghayese(x,a.e[i].stnum);
        if(f){
            sum=sum+a.e[i].grade;
            sh++;
        }
    }
    if(sh!=0){
        sum=sum/sh;
        cout<<sum;
    }
}
////////////////////////////
void cs_average(void){
    int x,sh=0;
    double sum=0;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"enter course num:";
    cin>>x;
    cout<<"the average if this course is:";
    for(int i=0;i<a.scn;i++){
        if(x==a.e[i].csnum){
            sum=sum+a.e[i].grade;
            sh++;
        }
    }
    if(sh!=0){
        sum=sum/sh;
        cout<<sum;
    }
}
///////////////////////
void tchr_average(void){
    int x,sh=0;
    double sum=0;
    info a;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"enter teacher num :";
    cin>>x;
    cout<<"the average of courses for this teacher is:\n";
    for(int i=0;i<a.tcn;i++){
        if(x==a.d[i].tnum){
            for(int j=0;j<a.scn;j++){
                if(a.d[i].csnum==a.e[j].csnum){
                    sum=sum+a.e[j].grade;
                    sh++;
                }
            }
        }
    }
    if(sh!=0){
        sum=sum/sh;
        cout<<sum;
    }
}
////////////////////////
void disp_tch_stds(void){
    int x;
    info a;
    bool f;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"enter teacher num :";
    cin>>x;
    cout<<"the students of this teacher are:\n";
    for(int i=0;i<a.tcn;i++){
        if(x==a.d[i].tnum){
            for(int j=0;j<a.scn;j++){
                if(a.d[i].csnum==a.e[j].csnum){
                    for(int z=0;z<a.sn;z++){
                        f=moghayese(a.e[j].stnum,a.b[z].stnum);
                        if(f){
                            cout<<a.b[z];
                        }
                    }
                }
            }
        }
    }
}
//////////////////////////////////////////////////
void disp_stds_tch(void){
    char x[15];
    info a;
    bool f;
    ifstream f1("info.bin",ios::binary);
    f1.read((char *)&a,sizeof(info));
    f1.close();
    cout<<"enter student num:";
    cin>>x;
    cout<<"teachers of this student are:";
    for(int i=0;i<a.scn;i++){
        f=moghayese(x,a.e[i].stnum);
        if(f){
            for(int j=0;j<a.tcn;j++){
                if(a.e[i].csnum==a.d[j].csnum){
                    for(int z=0;z<a.tn;z++){
                        if(a.d[j].tnum==a.a[z].tnum){
                            cout<<a.a[z];
                        }
                    }
                }
            }
        }
    }
}
///////////////////////////////////////
