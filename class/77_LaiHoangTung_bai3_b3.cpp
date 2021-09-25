#include<iostream>
using namespace std;

class Date {
    private:
    int day;
    int month;
    int year;
    public:
    void nhap();
    void xuat();
};

void Date::nhap(){
    cout<<"Nhap ngay: ";
    cin>>day;
    cout<<"Nhap thang: ";
    cin>>month;
    cout<<"Nhap nam: ";
    cin>>year;
}

void Date::xuat(){
    cout<<day<<"/"<<month<<"/"<<year<<endl;
}

class DiaChi {
    private:
    char dienThoai[12];
    char phuong[30];
    char quan[30];
    char thanhPho[30];
    friend class DoanhNghiep;
};

class DoanhNghiep{
    private:
    int maDn;
    char tenDn[60];
    Date ngayTl;
    DiaChi diaChi;
    char giamDoc[30];
    long doanhThu;
    public:
    void nhap();
    void xuat();
   // friend class DiaChi;
};

void DoanhNghiep::nhap(){
    cout<<"Nhap ma dn: ";
    cin>>maDn;
    cout<<"Nhap Ten dn: "; fflush(stdin); gets(tenDn);
    cout<<"Nhap ngay tl: "<<endl;
    ngayTl.nhap();
    fflush(stdin); cout<<"Nhap sdt: "; gets(diaChi.dienThoai);
    fflush(stdin); cout<<"Nhap ten phuong: "; gets(diaChi.phuong);
    fflush(stdin); cout<<"Nhap ten quan: "; gets(diaChi.quan);
    fflush(stdin); cout<<"Nhap ten thanh pho: "; gets(diaChi.thanhPho);
    cout<<"Nhap Ten giam doc: "; fflush(stdin); gets(giamDoc);
    cout<<"Nhap doanh thu: ";
    cin>>doanhThu;
}

void DoanhNghiep::xuat(){
    cout<<"Ma dn la: "<<maDn<<endl;
    cout<<"Ten dn la: "<<tenDn<<endl;
    cout<<"Ngay tl: ";
    ngayTl.xuat();
    cout<<"So dien thoai: "<<diaChi.dienThoai<<endl;
    cout<<"Dia chi: "<<diaChi.phuong<<" - "<<diaChi.quan<<" - "<<diaChi.thanhPho<<endl;
    cout<<"Ten giam doc: "<<giamDoc<<endl;
    cout<<"Doanh thu: "<<doanhThu<<endl;
}

int main(){
    DoanhNghiep a;
    a.nhap();
    cout<<"======Thong tin cua doanh nghiep======\n";
    a.xuat();
    return 0;
}