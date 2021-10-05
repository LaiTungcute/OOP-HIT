#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

//class
class Phieu;
class SanPham {
private:
	char maSP[30];
	char tenSP[30];
	int soLuong;
	double donGia;
public: 
	void Nhap();
	void Xuat();
	double GetThanhTien() {
		return soLuong * donGia;
	}
	friend void ChangeSanPham(Phieu a);
//	friend class Phieu;
};

class NCC {
private:
	char maNCC[30];
	char tenNCC[30];
	char diaChi[30];
	char sdt[15];
public:
	void Nhap();
	void Xuat();
};

class Phieu {
private:
	char maPhieu[30];
	char ngayLap[15];
	NCC ncc;
	int n;
	SanPham *sanPhams;
public: 
	void Nhap();
	void Xuat();
	friend void SortSanPham(Phieu a);
	friend void Insert(Phieu &a, SanPham x, int pos);
	friend void Delete(Phieu &a, int pos);
	friend void ChangeSanPham(Phieu a);
};

//dinh nghia
void SanPham::Nhap() {
	cout << "Nhap ma SP   : "; fflush(stdin); gets(maSP);
	cout << "Nhap ten SP  : "; fflush(stdin); gets(tenSP);
	cout << "Nhap so luong: "; cin >> soLuong;
	cout << "Nhap don gia : "; cin >> donGia;
}
void SanPham::Xuat() {
//	cout << left << setw(15) << maSP << setw(20) << tenSP 
//		<< setw(15) << soLuong << setw(15) << donGia 
//		<< setw(15) << soLuong*donGia << endl;
	cout << left << setw(15) << maSP << setw(20) << tenSP 
		<< setw(15) << soLuong << setw(15) << donGia 
		<< setw(15) << GetThanhTien() << endl;
}

void NCC::Nhap() {
	cout << "Nhap ma NCC :"; fflush(stdin); gets(maNCC);
	cout << "Nhap ten NCC: "; fflush(stdin); gets(tenNCC);
	cout << "Nhap dia chi: "; fflush(stdin); gets(diaChi);
	cout << "Nhap SDT    : "; fflush(stdin); gets(sdt);
}
void NCC::Xuat() {
	cout << left << setw(25) << "Ma nha cung cap: "
		<< setw(20) << maNCC << "Ten nha cung cap: " << tenNCC << endl;
	cout << left << setw(25) << "Dia chi: "
		<< setw(20) << diaChi << "SDT: " << sdt << endl;
}

void Phieu::Nhap() {
	cout << "Nhap ma phieu: "; fflush(stdin); gets(maPhieu);
	cout << "Nhap ngay lap: "; fflush(stdin); gets(ngayLap);
	cout << "\tNhap thong tin nha cung cap" << endl;
	ncc.Nhap();
	cout << "\tNhap so luong san pham"; 
	cin >> n;
	sanPhams = new SanPham[n];
	for(int i=0; i<n; i++) {
		cout << "\tNhap thong tin san pham thu " << i + 1 << endl;
		sanPhams[i].Nhap();
	}
}
void Phieu::Xuat() {
	cout << "\nDai hoc Victory" << endl;
	cout << "\t\t\tPHIEU NHAP VAN PHONG PHAM" << endl;
	cout << left << setw(25) << "Ma phieu: "
		<< setw(20) << maPhieu << "Ngay lap: " << ngayLap << endl;
	ncc.Xuat();
	//tieu de san pham
	cout << left << setw(15) << "Ma SP" << setw(20) << "Ten SP" 
		<< setw(15) << "So Luong" << setw(15) << "Don Gia" 
		<< setw(15) << "Thanh Tien" << endl;
	//Tong tien
	double sum = 0;
	for(int i=0; i<n; i++) {
		sanPhams[i].Xuat();
//		sum += sanPhams[i].soLuong * sanPhams[i].donGia;//
		sum += sanPhams[i].GetThanhTien();
	}
	cout << setw(65) << "Tong" << setw(15) << sum << endl;
	cout << right << "\tHieu truong" << setw(25) << "Phong tai chinh" << setw(25) << "Nguoi Lap" << endl;
}

void SortSanPham(Phieu a) { //
	for(int i=0; i<a.n-1; i++) {
		for(int j=a.n-1; j>i; j--) {
			if(a.sanPhams[j-1].GetThanhTien() < a.sanPhams[j].GetThanhTien()) {
				SanPham temp = a.sanPhams[j-1];
				a.sanPhams[j-1] = a.sanPhams[j];
				a.sanPhams[j] = temp;
			}
		}
	}
}

void Insert(Phieu &a, SanPham x, int pos) { 
	a.sanPhams = (SanPham*)realloc(a.sanPhams, (a.n+1)*sizeof(SanPham)); 
	for(int i=a.n; i>=pos; i--) {
		a.sanPhams[i] = a.sanPhams[i-1];
	}
	a.sanPhams[pos-1] = x;
	a.n++;
}

void Delete(Phieu &a, int pos) {
	//if else vi tri
	for(int i=pos-1; i<a.n-1; i++) {
		a.sanPhams[i] = a.sanPhams[i+1];
	}
	a.sanPhams = (SanPham*)realloc(a.sanPhams, (a.n-1)*sizeof(SanPham)); 
	a.n--;
}

void ChangeSanPham(Phieu a) {
	for(int i=0; i<a.n; i++) {
		if(a.sanPhams[i].soLuong < 10) {
			a.sanPhams[i].soLuong = 10;
		}
	}
}

int main() {
	Phieu a;
	a.Nhap();
	cout << "\nPhieu vua nhap la: " << endl;
	a.Xuat();
	//Cau 2
//	SortSanPham(a);
//	cout << "\nPhieu sau khi sap xep la: " << endl;
//	a.Xuat();
	//Cau 3:
//	cout << "Nhap san pham can insert: " << endl;
//	SanPham x;
//	x.Nhap();
//	Insert(a, x, 1); 
//	cout << "\nPhieu sau khi chen them san pham la:" << endl;
//	a.Xuat(); 
	//Cau 4: 
//	int pos;
//	cout << "\nNhap vi tri can xoa: ";	cin >> pos;
//	Delete(a, pos);
//	cout << "\nPhieu sau khi xoa san pham la:" << endl;
//	a.Xuat();
	//C�u 5: 
	ChangeSanPham(a);
	cout << "\nPhieu sau khi thay doi so luong san pham" << endl;
	a.Xuat();
	
	return 0;
}