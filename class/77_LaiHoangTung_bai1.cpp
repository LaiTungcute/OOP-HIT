#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class Nguoi {
    private:
    char HoTen[30];
    int tuoi;
    char GioiTinh[5];
    public:
    void Nhap();
    void Xuat();
};

void Nguoi::Nhap(){
    cout<<"Nhap ho ten: "; fflush(stdin); gets(HoTen);
    cout<<"Nhap tuoi: "; cin>>tuoi;
    cout<<"Nhap gioi tinh: "; fflush(stdin); gets(GioiTinh);
}

void Nguoi::Xuat(){
    cout<<left<<setw(30)<<HoTen<<setw(10)<<tuoi<<setw(10)<<GioiTinh;
}

class NhanVien : public Nguoi{
    private:
    char MaNV[20];
    char ChucVu[20];
    int luong;
    public:
    void Nhap();
    void Xuat();
    friend class CongTy;
};

void NhanVien::Nhap(){
    Nguoi::Nhap();
    cout<<"Nhap MaNV: "; fflush(stdin); gets(MaNV);
    cout<<"Nhap chuc vu: "; fflush(stdin); gets(ChucVu);
    cout<<"Nhap tien luong: "; cin>>luong;
}

void NhanVien::Xuat(){
    cout<<left<<setw(30)<<"Ho ten "<<setw(10)<<"Tuoi "<<setw(10)<<"Gioi tinh";
    cout<<setw(20)<<"MaNV"<<setw(20)<<"ChucVu"<<setw(10)<<"Luong"<<endl;
    Nguoi::Xuat();
    cout<<left<<setw(10)<<MaNV<<setw(20)<<ChucVu<<setw(10)<<luong<<endl;
}

class CongTy {
    private:
    char MaCT[10];
    char DiaChi[30];
    NhanVien *x;
    int n;
    public:
    void Nhap();
    void Xuat();
    void SapXep();
};

void CongTy::Nhap(){
    cout<<"Nhap ma cong ty: "; fflush(stdin); gets(MaCT);
    cout<<"Nhap dia chi: "; fflush(stdin); gets(DiaChi);
    cout<<"Nhap so luong nhan vien: "; cin>>n;
    x = new NhanVien[n];
    for(int i=0;i<n;i++){
        cout<<"Thong tin nhan vien so "<<i+1<<": "<<endl;
        x[i].Nhap();
    }
}

void CongTy::Xuat(){
    cout<<"Ma cong ty: "<<MaCT<<endl;
    cout<<"Dia chi: "<<DiaChi<<endl;
    for(int i=0;i<n;i++){
        x[i].Xuat();
    }
}

// void CongTy::SapXep(){
//     for(int i=0;i<n-1;i++){
//         for(int j = i+1;j<n;j++){
//             if(x[i].luong < x[j].luong){ 
//                 NhanVien t = x[i];
//                 x[i] = x[j];
//                 x[j] = t;
//             }
//         }
//     }
// }

int main(){
    CongTy a;
    a.Nhap();
    a.Xuat();
    return 0;
}