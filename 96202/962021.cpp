///////////////////////////////////////////////////////////////////////////////////////////////////|
//////////////////////////////This program is for unsigned int type.///////////////////////////////|
///////////////////////////////////////////////////////////////////////////////////////////////////|
///////////////////////////////////////////////////////////////////////////////////////////////////|
//////////////////////////////////////| Ardavan.A Khalij |/////////////////////////////////////////|
//////////////////////////////////////|    9621160013    |/////////////////////////////////////////|
///////////////////////////////////////////////////////////////////////////////////////////////////|
#include<iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////
class larg_number {                                                                               
	public:                                                                                       
	int *number;                                                                                  
   	int n;                                                                                        
////////////////////////////////////////////////////////////////////////////////////////////////////
	larg_number(int num=1){                                                                       
		number=new int[num];                                                                      
		n=num;                                                                                    
	}                                                                                             
////////////////////////////////////////////////////////////////////////////////////////////////////
	~larg_number(){                          													  
		delete []number;																		  
		this->n=0;																				  
	}																							  
////////////////////////////////////////////////////////////////////////////////////////////////////
	larg_number(larg_number &b){																  
		n=b.n;																					  
		delete []number;																		  
		number=new int[n];																		  
		for(int i=0;i<n;i++){																	  
			number[i]=b.number[i];																  
		}																						  
	}																							  
////////////////////////////////////////////////////////////////////////////////////////////////////
	void operator = (const larg_number &b){														  
		n=b.n;																					  
		number=new int[n];																		 
		for(int i=0;i<n;i++){																	  
			number[i]=b.number[i];																  
		}																						  
	}																							  
////////////////////////////////////////////////////////////////////////////////////////////////////
    larg_number operator + (larg_number &b){
		int i,carry=0;
		if(n>b.n){
			larg_number c(n+1);
			for(i=0;i<b.n;i++){
				c.number[i]=carry+number[i]+b.number[i];
				if(c.number[i]>9){
					c.number[i]=c.number[i]-10;
					carry=1;
				}
				else{
					carry=0;
				}
			}
			for(i=b.n;i<n;i++){
				c.number[i]=number[i]+carry;
				if(c.number[i]>9){
					c.number[i]=c.number[i]-10;
					carry=1;
				}
				else{
					carry=0;
				}
			}
			c.number[n]=carry;
			return c;
		}
		if(n<b.n){
		    larg_number d(b.n+1);
			for(i=0;i<n;i++){
				d.number[i]=carry+number[i]+b.number[i];
				if(d.number[i]>9){
					d.number[i]=d.number[i]-10;
					carry=1;
				}
				else{
					carry=0;
				}
			}
			for(i=n;i<b.n;i++){
				d.number[i]=b.number[i]+carry;
				if(d.number[i]>9){
					d.number[i]=d.number[i]-10;
					carry=1;
				}
				else{
					carry=0;
				}
			}
			d.number[b.n]=carry;
			return d;
		}
		if(n==b.n){
			larg_number c(n+1);
			for(i=0;i<n;i++){
				c.number[i]=carry+number[i]+b.number[i];
				if(c.number[i]>9){
					c.number[i]=c.number[i]-10;
					carry=1;
				}
				else{
					carry=0;
				}
			}
			if(carry==0){
				c.number[n]=0;
			}
			else{
				c.number[n]=1;
			}
			return c;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
    larg_number operator - (larg_number &b){
		int i,over=0;
		if(n==b.n&&(*this)>b){
			larg_number c(n);
			for(i=0;i<n;i++){
				c.number[i]=over+number[i]-b.number[i];
				over=0;
				if(c.number[i]<0){
					c.number[i]=c.number[i]+10;
					over=-1;
				}
				if(i==n-1){
					c.number[i]=number[i]-b.number[i]+over;
					return c;
				}
			}
		}
		if(n==b.n&&(*this)<b){
			larg_number c(b.n);
			for(i=0;i<b.n;i++){
				c.number[i]=over+b.number[i]-number[i];
				over=0;
				if(c.number[i]<0){
					c.number[i]=c.number[i]+10;
					over=-1;
				}
				if(i==n-1){
					c.number[i]=-(b.number[i]-number[i]+over);
					return c;
				}
			}
		}
		if(*this==b){
			larg_number c(1);
			c.number[0]=0;
		}
		if(n>b.n){
			larg_number c(n);
			for(i=0;i<b.n;i++){
				c.number[i]=over+number[i]-b.number[i];
				over=0;
				if(c.number[i]<0){
					c.number[i]=c.number[i]+10;
					over=-1;
				}
			}
			for(;i<n;i++){
				c.number[i]=over+number[i];
				over=0;
				if(c.number[i]<0){
					c.number[i]=c.number[i]+10;
					over=-1;
				}
			}
			return c;
		}
		if(b.n>n){
			larg_number c(b.n);
			for(i=0;i<n;i++){
				c.number[i]=over+b.number[i]-number[i];
				over=0;
				if(c.number[i]<0){
					c.number[i]=c.number[i]+10;
					over=-1;
				}
			}
			for(;i<b.n;i++){
				c.number[i]=over+b.number[i];
				over=0;
				if(c.number[i]<0){
					c.number[i]=c.number[i]+10;
					over=-1;
				}
				if(i==b.n-1){
					c.number[i]=-c.number[i];
					return c;
				}
			}
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	bool operator < (larg_number &b){
		if(n>b.n){
			return false;
		}
		if(b.n>n){
			return true;
		}
		if(n==b.n){
			int i;
			for(i=n-1;i>=0;i--){
				if(number[i]<b.number[i]){
					return true;
				}
			}
		}
		return false;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	bool operator > (larg_number &b){
		if(n>b.n){
			return true;
		}
		if(b.n>n){
			return false;
		}
		if(n==b.n){
			int i;
			for(i=n-1;i>=0;i--){
				if(number[i]>b.number[i]){
					return true;
				}
			}
		}
		return false;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	bool operator == (larg_number &b){
		if(n==b.n){
			int i,j=0;
			for(i=0;i<n;i++){
				if(number[i]==b.number[i]){
					j++;
				}
			}
			if(j-1==n){
				return true;
			}
		}
		else{
			return false;
		}
		return false;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	bool operator != (larg_number &b){
		if(n==b.n){
			int i,j=0;
			for(i=0;i<n;i++){
				if(number[i]==b.number[i]){
					j++;
				}
			}
			if(j-1==n){
				return false;
			}
		}
		else{
			return true;
		}
		return true;
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	int operator [] (int k){
		if(k>n-1){
			cout<<"There is not such a data exist!"<<endl;
		}
		return number[k];
	}
////////////////////////////////////////////////////////////////////////////////////////////////////
	friend ostream& operator << (ostream& out,larg_number &b);									  
////////////////////////////////////////////////////////////////////////////////////////////////////
	friend istream& operator >> (istream& in ,larg_number &b);									  
////////////////////////////////////////////////////////////////////////////////////////////////////
};																								  
////////////////////////////////////////////////////////////////////////////////////////////////////
istream& operator >> (istream& in ,larg_number &b){												  
	string a;																					  
	in>>a;																						  
	int i,j;																					  
	for(i=0;a[i];i++);
	b.n=i;
	b.number=new int [b.n];
	for(i=b.n-1,j=0;i>=0&&j<b.n;i--,j++){
		b.number[i]=a[j]-'0';
	}
	return in;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator << (ostream& out,larg_number &b){
	int i;
	for(i=b.n-1;i>=0;i--){
		out<<b.number[i];
	}
	return out;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
int main (){
	larg_number a,b,c;
	cin>>b;
	cin>>a;
	if(a>b){cout<<"second one is more"<<endl;}
	if(a<b){cout<<"first one is more"<<endl;}
	c=b-a;
	cout<<c;
	c=a+b;
	cout<<c;
	c=a*b;
	cout<<c;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////