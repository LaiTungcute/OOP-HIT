#include<iostream>
#include<string.h>
using namespace std;

class Employee{
    private:
    char id[30];
    char name[30];
    int age;
    public:
    static double salary;
    Employee(){
        salary = 150000;
    }
    void Nhap();
    void Xuat();
};

void Employee::Nhap(){
    cout<<"Nhap id cua nhan vien: ";
    fflush(stdin);
    gets(id);
    fflush(stdin);
    cout<<"Nhap ten cua nhan vien: ";
    gets(name);
    cout<<"Nhap tuoi: ";
    cin>>age;
}

void Employee::Xuat(){
    cout<<"Nhap id cua nhan vien: "<<id<<endl; 
    cout<<"Nhap ten cua nhan vien: "<<name<<endl;
    cout<<"Nhap tuoi: "<<age<<endl;
    cout<<"Luong cua nhan vien la: "<< Employee::salary<<endl;
}

double Employee::salary = 0;

int main(){
    Employee nv1,nv2;
    nv1.Nhap();
    cout<<"=====Thong tin cua nhan vien 1======"<<endl;
    nv1.Xuat();
    nv2.Nhap();
    cout<<"=====Thong tin cua nhan vien 2======"<<endl;
    nv2.Xuat();
}