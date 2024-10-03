#include<iostream>

using namespace std;

class phanSo{
	private:
		int tu,mau;
	public:
		phanSo();
		phanSo(int t, int m);
		phanSo(const phanSo &ps);
		int layTuSo();
		int layMauSo();
		void thietlapTuso(int t);
		void thietlapMauso(int m);
		bool phanSoHopLe();
		void ChuanHoa();
		void rutgon();
		void thietlap(int t, int m);
		phanSo operator + ( const phanSo &ps) const;
		phanSo operator - ( const phanSo &ps) const;
		phanSo operator * ( const phanSo &ps) const;
		phanSo operator / ( const phanSo &ps) const;
		phanSo& operator += ( const phanSo &ps) ;
		phanSo& operator -= ( const phanSo &ps) ;
		phanSo& operator *= ( const phanSo &ps) ;
		phanSo& operator /= ( const phanSo &ps) ;
		
};

phanSo::phanSo(){
	tu = 0;
	mau = 1;
}

phanSo::phanSo(int t, int m){
	tu = t;
	mau = m;
}

phanSo::phanSo(const phanSo &ps){
		tu = ps.tu;
		mau = ps.mau;
}

int phanSo::layTuSo(){
		return tu;
}

int phanSo::layMauSo(){
	return mau;
}

void phanSo::thietlapTuso(int t){
	tu = t;
}

void phanSo::thietlapMauso(int m){
	mau = m;
}

bool phanSo::phanSoHopLe(){
	if(mau == 0)
		return false;
	return true;
}

void phanSo::ChuanHoa(){
	if(mau < 0){
		tu = -tu;
		mau = -mau;
	}
}

void phanSo::thietlap(int t, int m){
	tu = t;
	mau = m;
	rutgon();
	ChuanHoa();
}

int gcd( int a, int b){
	if ( b == 0 ) return a;
	else return gcd(b, a%b);
}

void phanSo::rutgon(){
	int r = gcd(tu,mau);
	tu /= r;
	mau /= r;
}

phanSo phanSo::operator + ( const phanSo &ps) const{
//	phanSo(int t, int m); constructor
	phanSo tong(tu*ps.mau + mau*ps.tu, ps.mau*mau);
	tong.rutgon();
	return tong;
}

phanSo phanSo::operator - ( const phanSo &ps) const{
//	phanSo(int t, int m); constructor
	phanSo hieu(tu*ps.mau - ps.tu* mau, ps.mau * mau);
	hieu.rutgon();
	return hieu;
}

phanSo phanSo::operator * ( const phanSo &ps) const{
//	phanSo(int t, int m); constructor
	phanSo tich(tu * ps.tu, mau * ps.mau);
	tich.rutgon();
	return tich;
}

phanSo phanSo::operator / ( const phanSo &ps) const{
//	phanSo(int t, int m); constructor
	phanSo thuong(tu * ps.mau, mau * ps.tu);
	thuong.rutgon();
	return thuong;
}

phanSo &phanSo::operator +=( const phanSo &ps){
	tu = tu*ps.mau + ps.tu*mau;
	mau = mau * ps.mau;
	rutgon();
	return *this;
}
phanSo &phanSo::operator -=( const phanSo &ps){
	tu = tu*ps.mau - ps.tu*mau;
	mau = mau * ps.mau;
	rutgon();
	return *this;
}
phanSo &phanSo::operator *=( const phanSo &ps){
	tu = tu*ps.tu;
	mau = mau * ps.mau;
	rutgon();
	return *this;
}
phanSo &phanSo::operator /=( const phanSo &ps){
	tu = tu*ps.mau;
	mau = mau*ps.tu;
	rutgon();
	return *this;
}
int main(){
	phanSo ps;
	int t,m;
	cin>>t>>m;
	ps.thietlap(t,m);
 	cout << "Phan so ps1: " << ps.layTuSo() << "/" << ps.layMauSo() << endl;
	phanSo ps2(1,3);
	cout << "Phan so ps2: " << ps2.layTuSo() << "/" << ps2.layMauSo() << endl;
	phanSo ps3 = ps + ps2;
	cout<<"Toan tu + - * / : \n";
	cout<<	"phan so ps3 sau khi cong "<< ps3.layTuSo()<< "/" << ps3.layMauSo() << endl;
	ps3 = ps - ps2;
	cout<<	"phan so ps3 sau khi tru "<< ps3.layTuSo()<< "/" << ps3.layMauSo() << endl;
	ps3 = ps * ps2;
	cout<<	"phan so ps3 sau khi nhan "<< ps3.layTuSo()<< "/" << ps3.layMauSo() << endl;
	ps3 = ps / ps2;
	cout<<	"phan so ps3 sau khi chia "<< ps3.layTuSo()<< "/" << ps3.layMauSo() << endl;
	cout<<"Toan tu += -= *= /= : \n" ;
	ps += ps2;
	cout<< "Phan so ps1 += ps2 sau khi cong " << ps.layTuSo()<<"/"<<ps.layMauSo()<<endl;
	ps -= ps2;
	cout<< "Phan so ps1 -= ps2 sau khi cong " << ps.layTuSo()<<"/"<<ps.layMauSo()<<endl;
	ps *= ps2;
	cout<< "Phan so ps1 *= ps2 sau khi cong " << ps.layTuSo()<<"/"<<ps.layMauSo()<<endl;
	ps /= ps2;
	cout<< "Phan so ps1 /= ps2 sau khi cong " << ps.layTuSo()<<"/"<<ps.layMauSo()<<endl;
	return 0;
}
