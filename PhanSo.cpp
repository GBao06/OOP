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
		phanSo &operator ++();
		phanSo &operator ++(int i);
		phanSo &operator --();
		phanSo &operator --( int i);
		bool operator > ( const phanSo &ps) const;
		bool operator < ( const phanSo &ps) const;
		bool operator >= ( const phanSo &ps) const;
		bool operator <= ( const phanSo &ps) const;
		bool operator == ( const phanSo &ps) const;
		bool operator != ( const phanSo &ps) const;
		friend istream &operator >> (istream &in, phanSo &ps);
		friend ostream &operator << (ostream &out, phanSo &ps);
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
phanSo &phanSo::operator ++(){
	++tu;
	return *this;
}
phanSo &phanSo::operator ++(int i){
	tu--;
	return *this;
}
phanSo &phanSo::operator --(){
	--tu;
	return *this;
}
phanSo &phanSo::operator --(int i){
	tu--;
	return *this;
}



bool phanSo::operator < ( const phanSo& ps) const{
	return (float(tu/mau) < float(ps.tu/ps.mau));
}
bool phanSo::operator > ( const phanSo& ps) const{
	return (float(tu/mau) > float(ps.tu/ps.mau));
}
bool phanSo::operator <= ( const phanSo& ps) const{
	return (float(tu/mau) <= float(ps.tu/ps.mau));
}
bool phanSo::operator >= ( const phanSo& ps) const{
	return (float(tu/mau) >= float(ps.tu/ps.mau));
}
bool phanSo::operator == ( const phanSo& ps) const{
	return (float(tu/mau) == float(ps.tu/ps.mau));
}
bool phanSo::operator != ( const phanSo& ps) const{
	return (float(tu/mau) != float(ps.tu/ps.mau));
}

istream &operator >> (istream &in, phanSo &ps){
	in>> ps.tu >> ps.mau;
	return in;
}
ostream &operator << (ostream &out, phanSo &ps){
	out<<ps.tu << "/" << ps.mau;
	return out;
}


int main(){
	phanSo ps1,ps2;
	cin>>ps1;
	cin>>ps2;

	return 0;
}
