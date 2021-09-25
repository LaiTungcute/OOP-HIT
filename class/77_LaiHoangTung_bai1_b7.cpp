#include<iostream>
#include<iomanip>
using namespace std;

class SP{
    private:
    double thuc;
    double ao;
    public:
    SP();
    SP(double thuc, double ao);
    SP operator+(SP x);
    SP operator-(SP x);
    friend ostream &operator<<(ostream &os, SP sp);
};

SP::SP(){
    this->ao = 0;
    this->thuc = 0;
}

SP::SP(double thuc, double ao){
    this->thuc = thuc;
    this->ao = ao;
}

ostream &operator<<(ostream &os, SP sp){
    os<<sp.thuc<<" + i* "<<sp.ao<<endl;
    return os;
}

SP SP::operator+(SP x){
    SP c;
    c.thuc = this->thuc + x.thuc;
    c.ao = this->ao + x.ao;
    return c;
}

SP SP::operator-(SP x){
    SP c;
    c.thuc = this->thuc - x.thuc;
    c.ao = this->ao - x.ao;
    return c;
}

int main(){
    SP SP1(3,4) , SP2(5,6);
    SP SP3 = SP1 + SP2;
    SP SP4 = SP1 - SP2;
    cout<<"SP3= ";
    cout<<SP3;
    cout<<"SP4= "<<SP4;
    return 0;
}