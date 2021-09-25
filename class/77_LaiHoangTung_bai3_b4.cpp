#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

/*
    Phieu: ma phieu, ten nha cung cap, ma nha cung cap
    Adrress: dia chi, SDT
    SanPham: ma sp, ten sp, tinh trang, so luong, don gia, thanh tien
*/

class SanPham
{
private:
    string Ma;
    string Ten;
    string TinhTrang;
    int SoLuong;
    int DonGia;
    int ThanhTien;
public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void SanPham::Nhap(){
    cout<<"Nhap ma sp: ";
    fflush(stdin);
    getline(cin,Ma);
    cout<<"Nhap ten sp: ";
    fflush(stdin);
    getline(cin,Ten);
    cout<<"Nhap tinh trang: ";
    fflush(stdin);
    getline(cin,TinhTrang);
    cout<<"Nhap so luong: "; cin>>SoLuong;
    cout<<"Nhap don gia: "; cin>>DonGia;
}

void SanPham::Xuat(){
    ThanhTien = SoLuong*DonGia;
    cout<<left<<setw(30)<<"MA SP"<<setw(30)<<"Ten san pham"<<setw(30)<<"Tinh trang"<<setw(10)<<"So luong"<<setw(15)<<"Don gia"<<setw(15)<<"Thanh tien"<<endl;
    cout<<left<<setw(30)<<Ma<<setw(30)<<Ten<<setw(30)<<TinhTrang<<setw(10)<<SoLuong<<setw(15)<<DonGia<<setw(15)<<ThanhTien<<endl;
}

class Address
{
private:
    string DiaChi;
    string SDT;
public:
    void Nhap();
    void Xuat();
    friend class Phieu;
};

void Address::Nhap(){
    cout<<"Nhap dia chi: ";
    fflush(stdin); getline(cin,DiaChi);
    cout<<"Nhap so dien thoai: ";
    fflush(stdin); getline(cin,SDT);
}

void Address::Xuat(){
    cout<<"Dia chi: "<<DiaChi<<setw(30)<<"SDT: "<<SDT<<endl;
}

class Phieu
{
private:
    string MaPhieu;
    string Ten;
    string MaNha;
    Address a;
    int n;
    SanPham *b = new SanPham[n];
public:
    void Nhap();
    void Xuat();
};

void Phieu::Nhap(){
    cout<<"Nhap Ma phieu: ";
    fflush(stdin);
    getline(cin,MaPhieu);
    cout<<"Nhap ten nha cung cap: ";
    fflush(stdin);
    getline(cin,Ten);
    cout<<"Nhap Ma nha cung cap: ";
    fflush(stdin);
    getline(cin,MaNha);
    a.Nhap();
    cout<<"Nhap so luong san pham: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin san pham thu "<<i+1<<endl;
        b[i].Nhap();
    }
}

void Phieu::Xuat(){
    cout<<"Ma phieu: "<<MaPhieu<<endl;
    cout<<"Ma nha cung cap: "<<MaNha<<setw(30)<<"Ten nha cung cap: "<<Ten<<endl;
    a.Xuat();
    for(int i=0;i<n;i++){
        b[i].Xuat();
    }
    int t=0;
    for(int i=0;i<n;i++){
        t+=b[i].ThanhTien;
    }
    cout<<left<<setw(5)<<"Tong so san pham "<<setw(20)<<n<<setw(5)<<"Cong thanh tien: "<<setw(12)<<t<<endl;	
}

int main(){
    Phieu s;
    s.Nhap();
    cout<<"Dai hoc cong nghiep Ha Noi"<<endl<<"\t\t\t\t\tPHIEU NHAP THIET BI MAY TINH"<<endl;
    s.Xuat();
}