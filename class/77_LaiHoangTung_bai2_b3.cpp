#include<iostream>
using namespace std;

class NSX{
    private:
    char Mansx[30];
    char Tennsx[30];
    char Dcnsx[30];
    public:
    void Nhap();
    void Xuat();
};

void NSX::Nhap(){
    cout<<"Nhap ma nsx: ";
    fflush(stdin);
    gets(Mansx);
    cout<<"Nhap ten nsx: ";
    fflush(stdin);
    gets(Tennsx);
    cout<<"Nhap dc nsx: ";
    fflush(stdin);
    gets(Dcnsx);
}

void NSX::Xuat(){
    cout<<"Ma nsx la: "<<Mansx<<endl;
    cout<<"Ten nsx la: "<<Tennsx<<endl;
    cout<<"Dc nxt la: "<<Dcnsx;
}

class Hang{
    private:
    char maHang[30];
    char tenHang[30];
    NSX x;
    public:
    void Nhap();
    void Xuat();
};

void Hang::Nhap(){
    cout<<"Nhap ma hang: ";
    fflush(stdin);
    gets(maHang);
    cout<<"Nhap ten hang: ";
    fflush(stdin);
    gets(tenHang);
    cout<<"Nhap ngay san xuat: "<<endl;
    x.Nhap();
}

void Hang::Xuat(){
    cout<<"Ma hang: "<<maHang<<endl;
    cout<<"Ten hang: "<<tenHang<<endl;
    x.Xuat();
}

int main(){
    int n;
    cout<<"Nhap so luong mat hang: ";
    cin>>n;
    Hang *a = new Hang[n];
    for(int i=0;i<n;i++){
        cout<<"\nNhap thong tin mat hang "<<i+1<<": "<<endl;
        a[i].Nhap();  
    }
    for(int i=0;i<n;i++){
        cout<<"\n======Thong tin mat hang "<<i+1<<" ====="<<endl;
        a[i].Xuat();     
    }
    return 0;
}