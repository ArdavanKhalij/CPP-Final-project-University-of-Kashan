///////////////////////////////////////////////////////////////////////////////////
//  main.cpp                                                                     //
//  link list                                                                    //
//  Created by ardavan on 5/29/18.                                               //
//  Copyright © 2018 Apple Inc. All rights reserved.                             //
///////////////////////////////////////////////////////////////////////////////////
//*=============================================================================*//
//|                              Ardavan.A Khalij                               |//
//|                                 9621160013                                  |//
//|                                   962031                                    |//
//*=============================================================================*//
///////////////////////////////////////////////////////////////////////////////////
//*=============================================================================*//
//| dar in barname yeki az tabe haye nabudgar kar mikanad agar hardo baham dar  |//
//| barname mojud bashand tabe nabudgar node kar nakhahad kard va khataye zamane|//
//| ejra midahad.pas hardo baham kar nemikonand va ya bayad nabudgar node dashte|//
//| bashim ya link list be surate bazgashty.                                    |//
//*=============================================================================*//
///////////////////////////////////////////////////////////////////////////////////
#include <iostream>
///////////////////////////////////////////////////////////////////////////////////
using namespace std;
///////////////////////////////////////////////////////////////////////////////////
class node{
public:
    int a;
    node *next;
///////////////////////////////////////////////////////////////////////////////////
    node(int data=0){
        next=0;
        a=data;
    }
///////////////////////////////////////////////////////////////////////////////////
/*    ~node(){
        delete next;
        a=0;
    }
 */
///////////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////////
class link_list{
public:
    node head;
///////////////////////////////////////////////////////////////////////////////////
    link_list (int n=1){
        node *pn=head.next;
        pn=new node;
        pn->a=0;
        for(int i=0;i<n-1;i++){
            pn=pn->next;
            pn=new node;
            pn->a=0;
        }
        pn->next=0;
    }
///////////////////////////////////////////////////////////////////////////////////
    ~link_list(){
        static node *pn=head.next;
        cout<<"Delete"<<endl;
        if(pn&&pn->next==NULL){
            delete head.next;
        }
        else{
        pn=pn->next;
        this->~link_list();
        }
    }
///////////////////////////////////////////////////////////////////////////////////
    void addToEndOfLinkList (void){
        node *pn;
        pn=head.next;
        if(head.next==0){
            head.next=new node;
            cout<<"Enter your number : ";
            cin>>head.next->a;
        }
        else{
            for(;pn->next;pn=pn->next);
            pn->next=new node;
            pn->next->next=0;
            cout<<"Enter your number : ";
            cin>>pn->next->a;
        }
    }
///////////////////////////////////////////////////////////////////////////////////
    void deleteFromEndOfLinkList(void){
        node *pn=head.next,*pm;
        if (pn==0){
            cout<<"The link list was empty!"<<endl;
        }
        else if(pn->next==0){
            delete head.next;
            head.next=0;
            cout<<"The link list is empty now!"<<endl;
        }
        else{
            for(;pn->next->next;pn=pn->next);
            pm=pn->next;
            delete pm;
            pn->next=0;
        }
    }
///////////////////////////////////////////////////////////////////////////////////
    void deleteFromMiddleOfLinkList(int n){
        int m;
        node *pm,*pn=head.next,*pv=head.next;
        if(n==0){
            pn=head.next->next;
            delete head.next;
            head.next=pn;
        }
        else{
            for(m=0;pv;pv=pv->next,m++);
            if(m<n){
                cout<<"There is not such a data!\n";
            }
            else{
                for(int i=0;pn->next->next&&i<n-1;i++,pn=pn->next);
                pm=pn->next;
                delete pm;
                pn->next=pn->next->next;
            }
        }
    }
///////////////////////////////////////////////////////////////////////////////////
    int lengthOfTheLinkList(void){
        node *pn;
        int n=0;
        for(pn=head.next;pn;pn=pn->next,n++);
        return n;
    }
///////////////////////////////////////////////////////////////////////////////////
    int operator [] (int n){
        node *pn=head.next;
        if(lengthOfTheLinkList()<n){
            cout<<"There is not such a data!\n";
        }
        else{
            for(int i=0;pn->next&&i<n;i++,pn=pn->next);
        }
        return pn->a;
    }
///////////////////////////////////////////////////////////////////////////////////
    void sortTheLinkList(void){//Not compeleted
        int *b,hold;
        node *pn=head.next,*pm=head.next;
        b=new int[lengthOfTheLinkList()];
        for(int i=0;i<lengthOfTheLinkList();i++){
            b[i]=pn->a;
            pn=pn->next;
        }
        int n=lengthOfTheLinkList();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if(b[j]>b[j+1]){
                    hold=b[j];
                    b[j]=b[j+1];
                    b[j+1]=hold;
                }
            }
        }
        for(int i=0;i<lengthOfTheLinkList();i++){
            pm->a=b[i];
            pm=pm->next;
        }
    }
///////////////////////////////////////////////////////////////////////////////////
    void operator + (link_list pn){
        node *pm=head.next;
        int i=0;
        if(lengthOfTheLinkList()>=pn.lengthOfTheLinkList()){
            for(int i=0;i<lengthOfTheLinkList();i++){
                pm->a=pm->a+pn[i];
                pm=pm->next;
            }
        }
        else{
            int i;
            for(i=0;i<lengthOfTheLinkList();i++){
                pm->a=pm->a+pn[i];
                pm=pm->next;
            }
            for(;i<pn.lengthOfTheLinkList();i++){
                pm->next=new node;
                pm->next->a=pm->next->a+pn[i];
                pm=pm->next;
            }
            pm->next=0;
        }
        pm->a=pm->a+pn[i];
    }
///////////////////////////////////////////////////////////////////////////////////
    friend ostream& operator << (ostream &out,link_list &pn);
///////////////////////////////////////////////////////////////////////////////////
};
///////////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream &out,link_list &pn){
    for(int i=0;i<pn.lengthOfTheLinkList();i++){
        out<<"a["<<i<<"]  : "<<pn[i]<<endl;
    }
    cout<<"______________________________\n";
    return out;
}
///////////////////////////////////////////////////////////////////////////////////
int main(){
    link_list a;
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    a.addToEndOfLinkList();
    cout<<a;
    a.sortTheLinkList();
    cout<<a;
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////