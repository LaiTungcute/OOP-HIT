#include<iostream>
#include<string.h>
using namespace std;

class CanBo{
    public:
    int ma;
    char ten[255];
    int ngay;
    int thang;
    int nam;
    int ngay2; //số ngày làm việc trong tháng
    void Nhap();
    int TinhLuong();
    void Xuat();
};

void CanBo::Nhap(){
    cout<<"Nhap ma can bo: ";
    cin>>ma;
    fflush(stdin);
    cout<<"Nhap ten can bo: ";
    gets(ten);
    cout<<"Nhap ngay, thang, nam sinh: ";
    cin>>ngay>>thang>>nam; //nhập ngày tháng và năm sinh của cán bộ
    cout<<"Nhap so ngay lam viec trong thang: ";
    cin>>ngay2;
}

int CanBo::TinhLuong(){
    return 250000*ngay2;
}

void CanBo::Xuat(){
    cout<<"Ma can bo: ";
    cout<<ma<<endl;
    cout<<"Ten can bo: ";
    cout<<ten<<endl;
    cout<<"Date: ";
    cout<<ngay<<"/"<<thang<<"/"<<nam<<endl;
    cout<<"So ngay lam viec trong 1 thang la: "<<ngay2<<endl;
    cout<<"Tien luong cua can bo la: "<< TinhLuong();
}

int main(){
    CanBo a;
    cout<<"       Nhap thong tin cua can bo      "<<endl;
    a.Nhap();
    cout<<"\n           Thong tin cua can bo        "<<endl;
    a.Xuat();
}