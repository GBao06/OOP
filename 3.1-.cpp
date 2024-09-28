#include<iostream>

using namespace std;

class phanso{
	private:
		int tu,mau;
	public:
		phanso(){
		}
		phanso(int tu, int mau){
			this->tu = tu;
			this->mau = mau;
		}
		~phanso(){
		}
		void in(){
			cout<<"Phan so da nhap: "<<tu<<'/'<<mau<<endl;
		}
		int getTu(){
			return tu;
		}
		int getMau(){
			return mau;
		}
};

int gcd(int a, int b){
	if( b == 0 ) return a;
	return gcd(b, a % b );
}

void cong(int tu1, int mau1,int tu2, int mau2){
	int mauchung = mau1*mau2;
	tu1 *= mau2;
	tu2 *= mau1;
	int tuchung = tu1 + tu2;
	int gc = gcd(tuchung,mauchung);
	tuchung /= gc;	
	mauchung /= gc;
	if (tuchung == 0) {
        cout << "Cong 2 phan so: 0" << endl;
        return;
    }
    if (tuchung == mauchung) {
        cout << "Cong 2 phan so: 1" << endl;
        return;
    }
    cout << "Cong 2 phan so: " << tuchung << '/' << mauchung << endl;
}

void tru(int tu1, int mau1,int tu2, int mau2){
	int mauchung = mau1*mau2;
	tu1 *= mau2;
	tu2 *= mau1;
	int tuchung = tu1 - tu2;
	int gc = gcd(tuchung,mauchung);
	tuchung /= gc;	
	mauchung /= gc;
	 if (tuchung == 0) {
        cout << "Tru 2 phan so: 0" << endl;
        return;
    }
    if (tuchung == mauchung) {
        cout << "Tru 2 phan so: 1" << endl;
        return;
    }
    cout << "Tru 2 phan so: " << tuchung << '/' << mauchung << endl;
}

void nhan(int tu1, int mau1,int tu2, int mau2){
	int tu = tu1*tu2;
	int mau = mau1*mau2;
	int gc = gcd(tu,mau);
	tu /= gc;
	mau /= gc;
	if (tu== 0) {
        cout << "Nhan 2 phan so: 0" << endl;
        return;
    }
    if (tu == mau) {
        cout << "Nhan 2 phan so: 1" << endl;
        return;
    }
    cout << "Nhan 2 phan so: " << tu<< '/' << mau << endl;
}

void chia(int tu1, int mau1,int tu2, int mau2){
	int tu = tu1*mau2;
	int mau = mau1*tu2;
	int gc = gcd(tu,mau);
	tu /= gc;
	mau /= gc;
	if (tu== 0) {
        cout << "Chia 2 phan so: 0" << endl;
        return;
    }
    if (tu == mau) {
        cout << "Chia 2 phan so: 1" << endl;
        return;
    }
    cout << "Chia 2 phan so: " << tu<< '/' << mau << endl;
}

int main(){
	cout<<"Nhap phan so: ";
	int tu, mau;
	cin>>tu>>mau;
	phanso *ps1 = new phanso(tu,mau);
	ps1->in();
	cout<<"Nhap phan so: ";
	cin>>tu>>mau;
	phanso *ps2 = new phanso(tu,mau);
	ps2->in();
	
	//lay thogn tin
	int tu1 = ps1->getTu();
	int mau1 = ps1->getMau();
	int tu2 = ps2->getTu();
	int mau2 =ps2->getMau();
	//cong 2 phan so
	cout<<"\n************************\n";
	cong(tu1,mau1, tu2,mau2);
	tru(tu1,mau1, tu2,mau2);
	nhan(tu1,mau1, tu2,mau2);
	chia(tu1,mau1, tu2,mau2);
	delete ps1;
	delete ps2;
	return 0;
}
