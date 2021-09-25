#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

/*
    Phieu: Ma phieu, ngay
    Person: nguoi di cho
    adress: sdt,dia chi
    hang: ten hang, don gia, so luong, thanh tien
*/

class Person{
private:
    string Name;
public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void Person::Nhap(){
    cout<<"Nhap ten nguoi di cho: ";
    fflush(stdin);
    getline(cin,Name);
}

void Person::Xuat(){
  cout<<"Ho va ten nguoi di cho: "<<Name<<endl;
}

class Address{
private:
    string DiaChi;
    string SDT;
public:
    void Nhap();
    void Xuat();    
    friend class Phieu;
};

void Address::Nhap(){
    cout<<"NHap dia chi: ";
    fflush(stdin);
    getline(cin,DiaChi);
     cout<<"Nhap so dien thoai: ";
    fflush(stdin); getline(cin,SDT);
}

void Address::Xuat(){
    cout<<"Dia chi: "<<DiaChi<<endl<<"SDT: "<<SDT<<endl;
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
  Person a;
  Address b;
  int n;
  Hang *c = new Hang[n];
  int t;
public:
   void Nhap();
   void Xuat();
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
    int s = 0;
    for(int i=0;i<n;i++){
        c[i].Xuat();
    }
    for(int i=0;i<n;i++){
        s+=c[i].t;
    }
    cout<<left<<setw(50)<<"Cong thanh tien: "<<setw(10)<<t<<endl;
}

int main(int argc, char const *argv[])
{
    Phieu a;
    a.Nhap();
    cout<<"\n\t\t\t\tPHIEU DI CHO"<<endl;
    a.Xuat();
    cout<<"Luu y: Phieu chi co tac dung trong BTVN buoi 4 cua lop OOP 2021";
    return 0;
}
