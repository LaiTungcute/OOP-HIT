#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class VEHICLE
{
private:
    char NhanHieu[30];
    int NamSx;
    char Hang[10];
public:
    void Nhap();
    void Xuat();
};

void VEHICLE::Nhap(){
    cout<<"Nhap nhan hieu: ";
    fflush(stdin); gets(NhanHieu);
    cout<<"Nhap nam san xuat: ";
    cin>>NamSx;
    cout<<"Nhap hang san xuat: ";
    fflush(stdin); gets(Hang);
}

void VEHICLE::Xuat(){
    cout<<"Nhan hieu: "<<NhanHieu<<endl<<"Nam san xuat: "<<NamSx<<endl<<"Hang san xuat: "<<Hang<<endl;
}

class OTO : public VEHICLE
{
private:
    int SoCho;
    int DungTich;

public:
    void Nhap();
    void Xuat();
};

void OTO::Nhap(){
    VEHICLE::Nhap();
    cout<<"Nhap So cho ngoi: ";
    cin>> SoCho;
    cout<<"Nhap dung tich: ";
    cin>>DungTich;
}

void OTO::Xuat(){
    VEHICLE::Xuat();
    cout<<"So cho ngoi: "<<SoCho<<endl<<"Dung tich: "<<DungTich<<endl;
}

class MOTO : public VEHICLE
{
private:
    int PhanKhoi;

public:
    void Nhap();
    void Xuat();
};

void MOTO::Nhap(){
    VEHICLE::Nhap();
    cout<<"Nhap phan khoi: ";
    cin>>PhanKhoi;
}

void MOTO::Xuat(){
    VEHICLE::Xuat();
    cout<<"Phan khoi: "<<PhanKhoi<<endl;
}


int main(int argc, char const *argv[])
{
    OTO a;
    cout<<"Nhap du lieu cua oto: "<<endl;
    a.Nhap();
    cout<<"=====THONG TIN CUA XE OTO====="<<endl;
    a.Xuat();
    MOTO b;
    cout<<"Nhap du lieu cua moto: "<<endl;
    b.Nhap();
     cout<<"=====THONG TIN CUA XE MOTO====="<<endl;
    b.Xuat();
    return 0;
}
