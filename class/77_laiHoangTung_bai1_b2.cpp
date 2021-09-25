#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;

class Quadratic{
    private:
    double a;
    double b;
    double c;
    public:
    void nhap();
    void xuat();
    void giai();
    Quadratic();
    Quadratic(double x, double y, double z);
    ~Quadratic(){
        a=0;
        b=0;
        c=0;
    };
};

void Quadratic::nhap(){
    cout<<"Nhap a= ";
    cin>>a;
    cout<<"Nhap b= ";
    cin>>b;
    cout<<"Nhap c= ";
    cin>>c;
}

void Quadratic::xuat(){
    cout<<"PT co dang: "<<a<<"x^2 + "<<b<<"x + "<<c<<" =0";
}

void Quadratic::giai(){
    if(a==0){
        if(b==0){
            if(c==0) cout<<"\nPT vo so nghiem";
            else cout<<"\nPT vo nghiem";
        }
        else{
            cout<<"\nPT co nghiem la: "<<-c/b;
        }
    }
    else{
        double delta = b*b - 4*a*c;
        if(delta>0){
            cout<<"\nPT co 2 nghiem: x1= "<<(-b+sqrt(delta))/2*a<<" va x2= "<<(-b-sqrt(delta))/2*a;
        }
        else if(delta==0){
            cout<<"\nPT co nghiem kep: x= "<<-b/2*a;
        }
        else{
            cout<<"\nPT vo nghiem!!!";
        }
    }
}

Quadratic::Quadratic(){
    a=0;
    b=0;
    c=0;
}

Quadratic::Quadratic(double x, double y, double z){
    a = x;
    b = y;
    c = z;
}

int main(){
    Quadratic P(1,2,3);
    P.xuat();
    cout<<"\nGiai PT P ta co: ";
    P.giai();
    // P.~Quadratic();
    cout<<endl;
    Quadratic Q;
    Q.nhap();
    Q.xuat();
    cout<<"\nGiai PT Q ta co: ";
    Q.giai();
}