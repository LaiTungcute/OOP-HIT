#include<iostream>
using namespace std;

class TamThuc{
    private:
    double a,b,c;
    public:
    TamThuc operator--(); //đảo dấu
    TamThuc operator+(TamThuc t2);
    TamThuc operator-(TamThuc t2);
    friend istream &operator>>(istream &is, TamThuc &t);
    friend ostream &operator<<(ostream &os, TamThuc t);
};

TamThuc TamThuc::operator--(){
    this->a = -a;
    this->b = -b;
    this->c = -c;
    return *this;
}

TamThuc TamThuc::operator+(TamThuc t2){
    TamThuc c;
    c.a = this->a + t2.a;
    c.b = this->b + t2.b;
    c.c = this->c + t2.c;
    return c;
}

TamThuc TamThuc::operator-(TamThuc t2){
    TamThuc c;
    c.a = this->a - t2.a;
    c.b = this->b - t2.b;
    c.c = this->c - t2.c;
    return c;
}

istream &operator>>(istream &is, TamThuc &t){
    cout<<"Nhap a= ";
    is>>t.a;
    cout<<"Nhap b= ";
    is>>t.b;
    cout<<"Nhap c= ";
    is>>t.c;
    return is;
}

ostream &operator<<(ostream &os, TamThuc t){
    os<<t.a<<"x2 + "<<t.b<<"x + "<<t.c<<endl;
    return os;
}

int main(){
    TamThuc t1,t2;
    cout<<"Nhap t1: "<<endl;
    cin>>t1;
    t1 = t1.operator--();
    cout<<"t1 sau khi dao dau la: "<<t1;
    cout<<"Nhap t2: "<<endl;
    cin>>t2;
    t2 = t2.operator--();
    cout<<"t2 sau khi dao dau la: "<<t2;
    TamThuc t3,t4;
    t3 = t1 + t2;
    t4 = t1-t2;
    cout<<"t3= "<<t3<<"\nt4= "<<t4;
    return 0;
}