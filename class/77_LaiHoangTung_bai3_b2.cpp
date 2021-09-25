#include<iostream>
#include<string.h>

using namespace std;

class Hang
{
private:
    char maHang[30];
    char tenHang[30];
    char ngayNhap[30];
    char ngaySX[30];
    double donGia;
    int soLuong;
public:
    void nhap();
    void xuat();
    Hang();
    Hang(char maHang[], char tenHang[], char ngayNhap[], char ngaySX[], int donGia, int soLuong);
    ~Hang(){};
};

Hang::Hang()
{
    strcpy(maHang,"");
    strcpy(tenHang,"");
    strcpy(ngayNhap,"");
    strcpy(ngaySX,"");
    donGia = 0;
    soLuong = 0;
}

Hang::Hang(char maHangA[], char tenHangA[], char ngayNhapA[], char ngaySXA[], int donGiaA, int soLuongA){
    strcpy(maHang,maHangA);
    strcpy(tenHang,tenHangA);
    strcpy(ngayNhap,ngayNhapA);
    strcpy(ngaySX,ngaySXA);
    donGia = donGiaA;
    soLuong = soLuongA;
}

void Hang::nhap(){
    cout<<"Nhap ma hang: ";
    gets(maHang);
    fflush(stdin);
    cout<<"Nhap ten hang: ";
    gets(tenHang);
    fflush(stdin);
    cout<<"Ngay nhap hang: ";
    gets(ngayNhap);
    fflush(stdin);
    cout<<"Nhap ngay san xuat: ";
    gets(ngaySX);
    cout<<"Nhap don gia: ";
    cin>>donGia;
    cout<<"Nhap so luong: ";
    cin>>soLuong;
}

void Hang::xuat(){
    cout<<"Ma hang: ";
    cout<<maHang;
    cout<<"\nTen hang: ";
    cout<<tenHang;
    cout<<"\nNgay nhap: ";
    cout<<ngayNhap;
    cout<<"\nNgay san xuat: ";
    cout<<ngaySX;
    cout<<"\nDon gia: ";
    cout<<donGia;
    cout<<"\nSo luong: ";
    cout<<soLuong;
    double t = donGia*soLuong;
    cout<<"\nThanh tien: ";
    cout<<t;
}

// Hang::~Hang()
// {
// }

int main(){
    Hang P;
    P.nhap();
    cout<<"===============Thong tin mat hang P===============\n";
    P.xuat();
    cout<<"\n";
    Hang Q("abc123","Xa bong","03/08/2021","02/07/2021",65000, 3);
    cout<<"\n===============Thong tin mat hang Q===============\n";
    Q.xuat();
    return 0;
}