#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class Array {
    private:
    int n;
    int *a;
    public:
    Array();
    Array(int n, int *a);
    ~Array();
    Array o
    friend istream &operator>>(istream &is, Array &x);
    friend ostream &operator<<(ostream &os, Array x);
};

istream &operator>>(istream &is, Array &x){
    is>>x.n;
    x.a  = new int[x.n]; 
    for(int i=0;i<x.n;i++){
        is>>x.a[i];
    }
}

ostream &operator<<(ostream &os, Array x){
    for(int i=0;i<x.n;i++){
        os<<x.a[i]<<" ";
    }
}