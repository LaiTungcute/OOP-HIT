#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

/*
    phieu: ma phieu, ngay kiem ke
    nhan vien: nhan vien, chuc vu
    phong: phong, ma phong, truong phong
    tai san: ten tai san, so luong , tinh trang
*/

class NhanVien {
private:
    string Ten;
    string ChucVu;
public:
    void Nhap();
    void Xuat();
};

void NhanVien::Nhap(){
    cout<<"Nhap ten nhan vien: "; fflush(stdin); getline(cin, Ten);
    cout<<"Nhap chuc vu: "; fflush(stdin); getline(cin, ChucVu);
}

void NhanVien::Xuat(){
    cout<<left<<setw(30)<<"Nhan vien kiem ke: "<<Ten<<setw(30)<<"Chuc vu: "<<ChucVu<<endl;
}

class Phong {
private:  
    string TenPhong;
    string Ma;
    string Truong;
public:
    void Nhap();
    void Xuat();
};

class TaiSan {
private:
    string TenTaiSan;
    int SoLuong;
    string TinhTrang;
public:
    string GetTenTaiSan(){
        return TenTaiSan;
    }
    int GetSoLuong(){
        return SoLuong;
    }
    string GetTinhTrang(){
        return TinhTrang;
    }
    void SetTenTaiSan(string TenTaiSan){
        this->TenTaiSan = TenTaiSan;
    }  
    void SetSoLuong(int SoLuong){
        if(TenTaiSan=="May vi tinh"){
            this->SoLuong = 20;
        }
        else{
            this->SoLuong = SoLuong;
        }
    }
    void SetTinhTrang(string TinhTrang){
        this->TinhTrang = TinhTrang;
    }
    void Nhap();
    void Xuat();    
};

void TaiSan::Nhap(){
    string temp;
    int temp2;
    cout<<"Nhap tai san: ";
    fflush(stdin);
    getline(cin,temp); SetTenTaiSan(temp);
    cout<<"Nhap so luong: ";
    cin>>temp; SetSoLuong(temp2);
    cout<<"Nhap tinh trang: ";
    fflush(stdin); getline(cin,TinhTrang); SetTinhTrang(temp);
}

void TaiSan::Xuat(){
    cout<<left<<setw(30)<<GetTenTaiSan<<setw(10)<<GetSoLuong<<setw(10)<<GetTinhTrang<<endl;
}

class Phieu {
private:
    string MaPhieu;
    string NgayKiem;
    NhanVien a;
    Phong b;
    int n;
    TaiSan *c;
public:
    void Nhap();
    void Xuat();      
};

void Phieu::Nhap(){
    cout<<"Nhap ma phieu: "; fflush(stdin); getline(cin, MaPhieu);
    cout<<"Nhap Ngay kiem: "; fflush(stdin); getline(cin, NgayKiem);
    a.Nhap();
    b.Nhap();
    cout<<"Nhap so luong tai san: "; cin >> n;
    c = new TaiSan[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin tai san thu "<<i+1<<endl;
        c[i].Nhap();
    }
}

void Phieu::Xuat(){
    cout<<left<<setw(30)<<"Ma Phieu: "<<MaPhieu<<setw(30)<<"Ngay kiem: "<<NgayKiem<<endl;
    a.Xuat();
    b.Xuat();
    for(int i=0;i<n;i++){
        c[i].Xuat();
    }
}

int main(int argc, char const *argv[])
{
    Phieu a;
    a.Nhap();
    a.Xuat();
    return 0;
}
