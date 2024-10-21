#include <bits/stdc++.h>

using namespace std;

class phanso{
	private:
		int tu,mau;
	public:
		phanso(){
			tu =  0;
			mau = 1;
			
		}
		phanso(int tu, int mau){
			this->tu = tu;
			this->mau = mau;
		}
		phanso(const phanso &x){
			tu = x.tu;
			mau = x.mau;
		}
		void ChuanHoa(){
			if(mau < 0){
				tu = -tu;
				mau = -mau;
			}
		}
		void thietlap(int t, int m){
			tu = t;
			mau = m;
			rutgon();
			ChuanHoa();
		}
		int gcd( int a, int b){
			if ( b == 0 ) return a;
			else return gcd(b, a%b);
		}

		void rutgon(){
			int r = gcd(tu,mau);
			tu /= r;
			mau /= r;
		}
		phanso operator + ( const phanso &x) const{
			phanso tong(tu*x.mau + x.tu*mau , mau*x.mau);
			tong.rutgon();
			return tong;
		}
		phanso operator - ( const phanso &x) const{
			phanso hieu(tu*x.mau - x.tu*mau, mau*x.mau);
			hieu.rutgon();
			return hieu;
		}
		phanso operator * ( const phanso &x) const {
			phanso tich (tu*x.tu, mau*x.mau);
			tich.rutgon();
			return tich;
		}
		phanso operator / (const phanso &x) const{
			phanso thuong(tu*x.mau,mau*x.tu);
			thuong.rutgon();
			return thuong;
		}
		friend istream &operator >> (istream &in, phanso &a){
			in>>a.tu>>a.mau;
			a.rutgon();
			a.ChuanHoa();
			return in;
		}
		friend ostream &operator << (ostream &out, phanso &a){
			cout<<a.tu<<"/"<<a.mau;
			return out;
		}
		bool operator < (const phanso &x) const {
			return tu * x.mau < x.tu * mau;
		}
};



int main(){
	//cau A
//	phanso ps1,ps2,ps;
//	cout<<"Nhap phan so 1: ";
//	cin>>ps1;
//	cout<<"Nhap phan so 2: ";
//	cin>>ps2;
//	ps = ps1 + ps2;
//	cout<<ps1<<" + "<<ps2<<" = "<<ps<<endl;
//	ps = ps1 - ps2;
//	cout<<ps1<<" - "<<ps2<<" = "<<ps<<endl;
//	ps = ps1 * ps2;
//	cout<<ps1<<" * "<<ps2<<" = "<<ps<<endl;
//	ps = ps1 / ps2;
//	cout<<ps1<<" / "<<ps2<<" = "<<ps<<endl;
	
	//cau B
	vector <phanso> arr;
	cout<<"Nhap so luong phan tu trong mang: ";
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		phanso temp;
		cout<<"Nhap phan so: ";
		cin>>temp;
		arr.push_back(temp);
	}
	cout<<"Cac phan tu vua nhap: ";
	for ( int i=0; i<n; i++){
		cout<<arr[i];
		if ( i < n-1){
			cout<<",";	
		}
	}
	cout<<endl;
	sort(arr.begin(),arr.end());
	cout<<"Cac phan tu vua sap xep: ";
	for ( int i=0; i<n; i++){
		cout<<arr[i];
		if ( i < n-1){
			cout<<",";	
		}
	}
	cout<<"\nNhap phan so de chen: ";
	phanso p; cin>>p;
	arr.push_back(p);
	cout<<"Cac phan tu vua chen: ";
	sort(arr.begin(),arr.end());
	for ( int i=0; i<n+1; i++){
		cout<<arr[i];
		if ( i < n){
			cout<<",";	
		}
	}
	return 0;
}
