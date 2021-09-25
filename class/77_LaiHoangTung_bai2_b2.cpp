#include<iostream>
#include<cmath>
using namespace std;

class Fraction{
    private:
    int a;
    int b;
    public:
    void nhap();
    void xuat();
    void rut();
    Fraction();
    Fraction(int x, int y);
    ~Fraction(){};
};

void Fraction::nhap(){
    cout<<"Nhap tu so: ";
    cin>>a;
    cout<<"Nhap mau so: ";
    do{
        cin>>b;
        if(b==0){
            cout<<"Nhap lai mau so: ";
        }
    }while(b==0);
}

void Fraction::xuat(){
    cout<<a<<"/"<<b;
}

void Fraction::rut(){
    int s=a;
    int t=b;
    int r = a%b;
    while(r!=0){
        a = b;
        b = r;
        r = a%b;
    }
    int t1 = s/b;
    int t2 = t/b;
    if(t1==0){
        cout<<"0";
    }
    else{
        if(t2<0){
            t2*=-1;
            t1*=-1;
            cout<<t1<<"/"<<t2;
        }
        else if(t2!=1){
            cout<<t1<<"/"<<t2;
        }
        else{
            cout<<t1;
        }
    }
}

Fraction::Fraction(){
    a=0;
    b=0;
}

Fraction::Fraction(int x, int y){
    a = x;
    b = y;
}

int main(){
    Fraction P(5,10);
    cout<<"\n==========Thong tin ve phan so P==========\n";
    cout<<"Phan so ban dau: ";
    P.xuat();
    cout<<"\nPhan so sau khi rut gon: ";
    P.rut();
    Fraction Q;
    cout<<"\n";
    Q.nhap();
    cout<<"\n==========Thong tin ve phan so Q==========\n";
    cout<<"Phan so ban dau: ";
    Q.xuat();
    cout<<"\nPhan so sau khi rut gon: ";
    Q.rut();
}