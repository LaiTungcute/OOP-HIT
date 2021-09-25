#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class Date
{
private:
    int D;
    int M;
    int Y;    
public:
   void Nhap();
   void Xuat();
   friend class NhanSu;
};

void Date::Nhap(){
    cout<<"Nhap ngay: ";
    cin>>this->D;
    cout<<"Nhap thang: ";
    cin>>this->M;
    cout<<"Nhap nam: ";
    cin>>this->Y;
}

void Date::Xuat(){
    cout<<D<<"/"<<M<<"/"<<Y<<endl;
}

class NhanSu
{
private:
    string Hoten;
    Date NS;  
    static int Manhansu;
    int Count;
public:
    NhanSu(){
        Manhansu++;
        Count = Manhansu;
    } 
    void Nhap();
    void Xuat();   
};

void NhanSu::Nhap(){
    cout<<"Nhap Ho ten: "; fflush(stdin); getline(cin,Hoten);
    NS.Nhap();
}

void NhanSu::Xuat(){
    cout<<left<<setw(30)<<Count<<setw(30)<<Hoten;
    NS.Xuat();
    cout<<endl;
}

int NhanSu::Manhansu = 0;


int main(){
    int n;
    cout<<"Nhap so nhan vien: ";
    cin>>n;
    NhanSu *z = new NhanSu[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin nhan vien thu "<<i+1<<endl;
        z[i].Nhap();
    }
    cout<<left<<setw(30)<<"Ma nhan su"<<setw(30)<<"Ho ten"<<setw(20)<<"Ngay"<<endl;
    for(int i=0;i<n;i++){
        z[i].Xuat();        
    }
}