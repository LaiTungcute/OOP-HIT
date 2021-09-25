#include <iostream>
#include <iomanip>
#include<cmath>
#include<string.h>
using namespace std;

class NSX
{
private:
    char Ten[30];
    char DiaChi[30];

public:
    void Nhap();
    void Xuat();
};

void NSX::Nhap(){
    cout<<"Nhap ten NXT: ";
    fflush(stdin); gets(Ten);
    cout<<"Nhap Dia chi: ";
    fflush(stdin); gets(DiaChi);
}

void NSX::Xuat(){
    cout<<"Ten nha san xuat: "<<Ten<<endl<<"Dia chi: "<<DiaChi<<endl;
}

class Hang
{
private:
    char TenHang[30];
    NSX x;
    double DonGia;

public:
    void Nhap();
    void Xuat();
    Hang();
};

Hang::Hang(){
    strcpy(TenHang,"");
    DonGia = 0.0;
}

void Hang::Nhap(){
  cout<<"Nhap ten hang: ";
  fflush(stdin); gets(TenHang);
  x.Nhap();
  cout<<"Nhap don gia: ";
  cin>>DonGia;  
}

void Hang::Xuat(){
    cout<<"Ten hang: "<<TenHang<<endl;
    x.Xuat();
    cout<<"Don gia: "<<DonGia<<endl;
}

class Date
{
private:
    int D;
    int M;
    int Y;

public:
    void Nhap();
    void Xuat();
};

void Date::Nhap(){
    cout<<"Nhap ngay: "; cin>>D;
    cout<<"Nhap thang: "; cin>>M;
    cout<<"Nhap nam: "; cin>>Y;
}

void Date::Xuat(){
    cout<<"Ngay nhap: "<<D<<"/"<<M<<"/"<<Y<<endl;
}

class TiVi : public Hang
{
private:
    char KichThuoc[30];
    Date NgayNhap;

public:
    void Nhap();
    void Xuat();
    TiVi();
};

TiVi::TiVi(){
    strcpy(KichThuoc,"");
}

void TiVi::Nhap(){
    Hang::Nhap();
    cout<<"Nhap kich thuoc: "; fflush(stdin); gets(KichThuoc);
    NgayNhap.Nhap();
}

void TiVi::Xuat(){
    Hang::Xuat();
    cout<<"Kich thuoc la: "<<KichThuoc<<endl;
    NgayNhap.Xuat();
}

int main(int argc, char const *argv[])
{
    TiVi a;
    cout<<"Nhap thong tin cua tivi"<<endl;
    a.Nhap();
    cout<<"=====THONG TIN CUA TIVI====="<<endl;
    a.Xuat();
    return 0;
}
