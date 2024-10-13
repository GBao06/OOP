#include<iostream>

using namespace std;

class date{
	private:
		int ngay, thang, nam;
	public:
		date(){
			ngay = thang = nam = 0;
		}
		date(int ngay,int thang,int nam){
			this->ngay = ngay;
			this->thang = thang;
			this->nam = nam;
		}
		date(date &x);
		bool kiemtra();
		int getNgay()const;
		int getThang() const;
		int getNam()const;
		void setNgay();
		void setThang();
		void setNam();
		void setNgay(int ngay, int thang, int nam);
		bool namNhuan(int nam);
		int ngaytrongThang(int thang, int nam);
		void chuanhoa();
		void chuyendoi( int x);
		void congNgay(int ngay);
		void truNgay(int ngay);
		void nhap();
		void xuat();
		friend istream &operator >> ( istream &in, date &x);
		friend ostream &operator << (ostream &out, date &x);
		bool operator < (date &x) const;
		bool operator > (date &x) const;
		bool operator == ( date &x) const;
		bool operator != (date &x) const;
};

date::date( date &x){
	ngay = this->ngay;
	thang = this->thang;
	nam = this->nam;
}
void date::setNgay( int ngay, int thang, int nam){
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}
int date::getNgay() const{ return ngay;}
int date::getThang() const{ return thang;}
int date::getNam() const {return nam;}
void date::setNgay(){ this->ngay = ngay;}
void date::setThang(){ this->thang = thang;}
void date::setNam(){ this->nam = nam;}

bool date::namNhuan(int nam) {
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}
int date::ngaytrongThang(int thang, int nam){
    int soNgay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (thang == 2 && namNhuan(nam)) return 29;
  	return soNgay[thang - 1];
}

void date::chuanhoa(){
	if ( thang < 1) thang = 1;
	if ( thang > 12) thang = 12;
	
	int isday = ngaytrongThang(thang,nam);
	if(ngay < 1) ngay = 1;
	if ( ngay > isday) ngay = isday;
}

bool date::kiemtra() {
    return (thang >= 1 && thang <= 12) && (ngay >= 1 && ngay <= ngaytrongThang(thang, nam)) && (nam >= 0);
}

void date::congNgay(int ngay) {
        while (ngay > 0) {
            int t = ngaytrongThang(thang, nam) - ngay;
            if (ngay <= t) {
                this->ngay += ngay;
                ngay = 0;
            } else {
                this->ngay = 1;
                ngay -= (t + 1);
                if (++thang > 12) {
                    thang = 1;
                    ++nam;
                }
            }
        }
    }
void date::truNgay(int ngay) {
        while (ngay > 0) {
            if (ngay < this->ngay) {
                this->ngay -= ngay;
                ngay = 0;
            } else {
                ngay -= this->ngay;
                if (--thang < 1) {
                    thang = 12;
                    --thang;
                }
                this->ngay = ngaytrongThang(thang, nam);
            }
        }
    }




void date::nhap(){
	cout<<"Nhap ngay: ";
	cin>>ngay;
	cout<<"Nhap thang: ";
	cin>>thang;
	cout<<"Nhap nam: ";
	cin>>nam;
}
void date::xuat(){
	cout<<ngay<< "/" << thang << "/" << nam << endl;
}
istream &operator >> (istream &in, date &x){
	in >> x.ngay >> x.thang >> x.nam;
	return in;
}
ostream &operator << (ostream &out, date &x){
	out << x.ngay << "/" << x.thang << "/" << x.nam << endl;	
}

bool date::operator >(date &x) const{
	if ( nam != x.nam) return nam > x.nam;
	if ( thang != x.thang) return thang > x.thang;
	return ngay > x.ngay; 
}
bool date::operator <(date &x) const{
	if ( nam != x.nam) return nam <x.nam;
	if ( thang != x.thang) return thang < x.thang;
	return ngay < x.ngay;
}
bool date::operator ==( date &x) const{
	return ngay == x.ngay && thang == x.thang && nam == x.nam;	
}
bool date::operator !=(date &x) const{
	return !(*this == x); 
} 



int main(){

	return 0;
}
