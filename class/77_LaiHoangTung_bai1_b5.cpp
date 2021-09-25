#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class Student
{
private:
    char* Ma = new char[30];
    char* HoTen = new char[30];
    int Day, Month, Year;
    char* GioiTinh = new char[10];
    double DiemTB;
    char* DaoDuc = new char[30];
public:
    Student();
    Student(char Ma[], char HoTen[], int Day, int Month, int Year, char GioiTinh[], double DiemTB, char DaoDuc[]);
    ~Student();
    char GetMa();
    char GetHoTen();
    int GetDay();
    int GetMonth();
    int GetYear();
    char GetGioiTinh();
    double GetDiemTB();
    char GetDaoDuc();
    void SetMa(char* Ma);
    void SetHoTen(char* HoTen);
    void SetDay(int Day);
    void SetMonth(int Month);
    void SetYear(int Year);
    void SetGioiTinh(char* GioiTinh);
    void SetDiemTB(double DiemTB);
    void SetDaoDuc(char* DaoDuc);
//    friend void Nhap(Student a);
};

Student::Student()
{
    strcpy(Ma,"");
    strcpy(HoTen,"");
    Day = 0;
    Month = 0;
    Year = 0;
    strcpy(GioiTinh,"");
    DiemTB = 0;
    strcpy(DaoDuc,"");
}

Student::Student(char Ma[], char HoTen[], int Day, int Month, int Year, char GioiTinh[], double DiemTB, char DaoDuc[]){
    this->Ma[30] = Ma[30];
    this->HoTen[30] = HoTen[30];
    this->Day = Day;
    this->Month = Month;
    this->Year = Year;
    this-> GioiTinh[10] = GioiTinh[10];
    this-> DiemTB = DiemTB;
    this->DaoDuc[30] = DaoDuc[30];
}

Student::~Student()
{
    strcpy(Ma,"");
    strcpy(HoTen,"");
    Day = 0;
    Month = 0;
    Year = 0;
    strcpy(GioiTinh,"");
    DiemTB = 0;
    strcpy(DaoDuc,"");
}

char Student::GetMa(){
    return *Ma;
}
char Student::GetHoTen(){
    return *HoTen;
}
int Student::GetDay(){
    return Day;
}
int Student::GetMonth(){
    return Month;
}
int Student::GetYear(){
    return Year;
}
char Student::GetGioiTinh(){
    return *GioiTinh;
}
double Student::GetDiemTB(){
    return DiemTB;
}
char Student::GetDaoDuc(){
    return *DaoDuc;
}
void Student::SetMa(char* Ma){
    this->Ma[30] = Ma[30];
}
void Student::SetHoTen(char* HoTen){
    this->HoTen[30] = HoTen[30];
}
void Student::SetDay(int Day){
    this->Day = Day;
}
void Student::SetMonth(int Month){
    this->Month = Month;
}
void Student::SetYear(int Year){
    this->Year = Year;
}
void Student::SetGioiTinh(char* GioiTinh){
    this->GioiTinh[30] = GioiTinh[30];
}
void Student::SetDiemTB(double DiemTB){
    this->DiemTB = DiemTB;
}
void Student::SetDaoDuc(char* DaoDuc){
    if(DaoDuc[30] == 'Tot'){
        this->DaoDuc[30] = DaoDuc[30];
    }
}

void Nhap(int n,Student *a){
    char temp[30];
    int temp2;
    double temp3;
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
        cout<<"Nhap Ma sv: "; fflush(stdin); gets(temp); a[i].SetMa(temp);
        cout<<"Nhap Ho ten sv: "; fflush(stdin); gets(temp); a[i].SetHoTen(temp);
        cout<<"Nhap ngay: "; cin>>temp2; a[i].SetDay(temp2);
        cout<<"Nhap thang: "; cin>>temp2; a[i].SetMonth(temp2);
        cout<<"Nhap nam: "; cin>>temp2; a[i].SetYear(temp2);
        cout<<"Nhap Gioi tinh sv: "; fflush(stdin); gets(temp); a[i].SetGioiTinh(temp);
        cout<<"Nhap diem tb cua sv"; cin>>temp3; a[i].SetDiemTB(temp3);
        cout<<"Nhap xep loai dao duc sv: "; fflush(stdin); gets(temp); a[i].SetDaoDuc(temp);
    }
}

void Xuat(int n, Student *a){
    cout<<left<<setw(30)<<"Ma sv"<<setw(30)<<"Ho ten"<<setw(30)<<"Ngay sinh"<<setw(30)<<"Gioi tinh"<<setw(20)<<"Diem tb"<<setw(10)<<"Dao duc"<<endl;
    for(int i=0;i<n;i++){
        cout<<left<<setw(30)<<a[i].GetMa()<<setw(30)<<a[i].GetHoTen()<<setw(30)<<a[i].GetDay()<<"/"<<a[i].GetMonth()<<"/"<<a[i].GetYear()<<setw(30)<<a[i].GetGioiTinh()<<setw(10)<<a[i].GetDiemTB()<<setw(10)<<a[i].GetDaoDuc()<<endl;   
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Nhap so luong sinh vien"; cin>>n;
    Student *a = new Student[n];
    Nhap(n,a);
    cout<<"\n\n\n\nDanh sach sinh vien"<<endl;
    Xuat(n,a);   
    return 0;
}
