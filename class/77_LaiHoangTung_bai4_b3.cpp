#include<iostream>
#include<string.h>
using namespace std;

class School{
    private :
    char Name[30];
    char Date[30];
    public:
    friend class Faculty;
};

class Faculty{
    private:
    char Name[30];
    char Date[30];
    School x;
    public:
    void input();
    void output();
};

void Faculty::input(){
    cout<<"Nhap ten truong: ";
    fflush(stdin); gets(x.Name);
    cout<<"Nhap ngay do: ";
    fflush(stdin); gets(x.Date);
    cout<<"Nhap ten: ";
    fflush(stdin); gets(Name);
    cout<<"Nhap ngay: ";
    fflush(stdin); gets(Date);
}

void Faculty::output(){
    cout<<"Ten truong: "<<x.Name<<endl;
    cout<<"Ngay do: "<<x.Date<<endl;
    cout<<"Ten: "<<Name<<endl;
    cout<<"Ngay: "<<Date<<endl;
}

class Student{
    private:
    Faculty y;
    char Class[12];
    double Score;
    public:
    void input();
    void output();
    Student();
};

Student::Student(){
    strcpy(Class,"");
    Score = 0;
}

void Student::input(){
    cout<<"Nhap ten lop: "; fflush(stdin); gets(Class);
    cout<<"Nhap diem: "; cin>>Score;
    y.input();
}

void Student::output(){
    y.output();
    cout<<"Lop: "<<Class<<endl;
    cout<<"Diem: "<<Score<<endl;
}

int main(){
    int n;
    cout<<"Nhap so sv: ";
    cin>>n;
    Student *a = new Student[n];
    for(int i=0;i<n;i++){
        a[i].input();
        cout<<"=====Thong tin sinh vien thu "<<i+1<<" =====\n";
        a[i].output();
    }   
    return 0;
}