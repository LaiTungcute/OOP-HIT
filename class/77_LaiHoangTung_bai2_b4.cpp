#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

/*
    Phieu : Ma phieu, ngay lap
    NCC   : ma NCC, Ten NCC
    DiaChi: Dia chi
    Hang  : ten hang, don gia, So luong
*/

// class NCC;
// class Address;
// class Hang;


class NCC{
private:
    string Ma;
    string Ten;
public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void NCC::Nhap(){
    cout<<"Nhap Ma NCC: ";
    fflush(stdin);
    getline(cin,Ma);
    cout<<"Nhap Ten NCC: ";
    fflush(stdin);
    getline(cin,Ten);
}

void NCC::Xuat(){
   cout<<"Ma NCC: "<<Ma;
   cout<<setw(30)<<"Ten NCC: "<<Ten<<endl; 
}

class Address{
private:
    string DiaChi;
public:
    void Nhap();
    void Xuat();    
    friend class Phieu;
};

void Address::Nhap(){
    cout<<"NHap dia chi: ";
    fflush(stdin);
    getline(cin,DiaChi);
}

void Address::Xuat(){
    cout<<"Dia chi: "<<DiaChi<<endl;
}

class Hang{
private:    
    string TenHang;
    double DonGia;
    int SoLuong;
    double t;
public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void Hang::Nhap(){
    cout<<"Nhap ten hang: ";
    fflush(stdin);
    getline(cin,TenHang);
    cout<<"Nhap don gia: ";
    cin>>DonGia;
    cout<<"Nhap so luong: ";
    cin>>SoLuong;
}

void Hang::Xuat(){
    t = DonGia*SoLuong;
    cout<<left<<setw(30)<<TenHang<<setw(10)<<DonGia<<setw(10)<<SoLuong<<setw(10)<<t<<endl;
}

class Phieu
{
private:
  string MaPhieu;
  string NgayLap;
  NCC a;
  Address b;
  int n;
  Hang *c = new Hang[n];
public:
   void Nhap();
   void Xuat();
   double Sum();
};

void Phieu::Nhap(){
    cout<<"Nhap ma phieu: ";
    fflush(stdin);
    getline(cin,MaPhieu);
    cout<<"Nhap Ngay lap: ";
    fflush(stdin);
    getline(cin,NgayLap);
    a.Nhap();
    b.Nhap();
    cout<<"Nhap so mat hang: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin mat hang thu "<<i+1<<endl;
        c[i].Nhap();
    }
} 

void Phieu::Xuat(){
    cout<<"Ma phieu: "<<MaPhieu;
    cout<<setw(30)<<"Ngay lap: "<<NgayLap<<endl;
    a.Xuat();
    b.Xuat();
    cout<<left<<setw(30)<<"Ten hang"<<setw(10)<<"Don gia"<<setw(10)<<"So luong"<<setw(10)<<"Thanh tien"<<endl;
    for(int i=0;i<n;i++){
        c[i].Xuat();
    }
}

double Phieu::Sum(){
    double s = 0;
    for(int i=0;i<n;i++){
        s+=c[i].t;
    }
    return s;
}

int main(){
    Phieu p;
    p.Nhap();
    cout<<"\t\t\t\tPHIEU NHAP HANG"<<endl;      
    p.Xuat();
    cout<<left<<setw(50)<<"                              Cong thanh tien"<<setw(10)<<p.Sum();
}