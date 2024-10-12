#include<iostream>
#include<iomanip>

using namespace std;

class Time{
	private:
		int gio,phut,giay;
	public:
		Time();
		Time(int gio, int phut, int giay);
		Time(Time &tm);
		void setTime( int gio, int phut, int giay);
		void chuanhoa();
		void chuyendoi(int x);
		bool kiemtra();
		int getGio();
		int getPhut();
		int getGiay();
		void nhap();
		void xuat();
		friend istream &operator >> ( istream &in, Time &tm);
		friend ostream &operator << ( ostream &out, Time &tm);
		Time operator +(Time &x) ;
		Time operator -(Time &x) ;
		bool operator > (const Time &x) const;
		bool operator >= (const Time &x) const;
		bool operator < (const Time &x) const;
		bool operator <= (const Time &x) const;
		bool operator == (const Time &x) const;
		bool operator != (const Time &x) const;
		Time congthemGiay(int x);
		Time congthemPhut(int x);
		Time congthemGio(int x);
		int tongSoGiay() const;
		void chuyenDoi12h() ;
		string phanLoaiThoiGianTrongNgay();
		int khoangCachThoiGian(Time &x);
		Time hieuThoiGian(Time &x);
};
//kiem_tra
bool Time::kiemtra() {
    return (gio >= 0 && gio < 24 && phut >= 0 && phut < 60 && giay >= 0 && giay < 60);
}

//nhap
void Time::nhap(){
	cout<<"Nhap gio: ";
	cin >> gio;
	cout<<"Nhap phut: ";
	cin>>phut;
	cout<<"Nhap giay: ";
	cin>>giay;
	chuanhoa();
}
void Time::xuat(){
	cout<<setfill('0')<<setw(2) << gio <<":"
	<<setfill('0')<<setw(2) << phut<< ":"<<
	setfill('0')<<setw(2) << giay<<endl;
	
}
istream &operator >> (istream &in, Time &tm){
	in>>tm.gio>>tm.phut>>tm.giay;
	return in;
}
ostream &operator << (ostream &out, Time &tm){
	out<<setfill('0')<<setw(2) << tm.gio <<":"
	<<setfill('0')<<setw(2) << tm.phut<< ":"<<
	setfill('0')<<setw(2) << tm.giay<<endl;
	return out;
}


//constructer
Time::Time(){
	this->giay = 0;
	this->gio = 0;
	this->phut = 0;
}
Time::Time(int gio, int phut, int giay){
	this->giay = giay;
	this->gio = gio;
	this->phut = phut;
}
Time::Time( Time &tm){
	gio = this->gio;
	giay = this->giay;
	phut = this->phut;
}

//gan
void Time::setTime(int gio, int phut, int giay){
	this->giay = giay;
	this->gio = gio;
	this->phut = phut;
}
//lay
int Time::getGio(){
	return gio;
}
int Time::getPhut(){
	return phut;
}
int Time::getGiay(){
	return giay;
}

//phuong thuc chuyen doi
void Time::chuyendoi(int x){
	gio = x/3600;
	phut = x%3600/60;
	giay = x%3600/60;
}
void Time::chuanhoa() {
    if (giay >= 60) {
        phut += giay / 60;
        giay = giay % 60;
    } else if (giay < 0) {
        phut -= (abs(giay) / 60) + 1;
        giay = 60 - abs(giay) % 60;
    }

    if (phut >= 60) {
        gio += phut / 60;
        phut = phut % 60;
    } else if (phut < 0) {
        gio -= (abs(phut) / 60) + 1;
        phut = 60 - abs(phut) % 60;
    }

    if (gio < 0) {
        gio = 0;
    }
}

// toan tu tai boi
Time Time::operator + (Time &x){
	x.chuanhoa();
	Time cong(gio+x.gio,phut+x.phut,giay+x.giay);
	cong.chuanhoa();
	return cong;
}
Time Time::operator-(Time &x){
    this->chuanhoa();
    x.chuanhoa();
    
    int tg_gio = gio - x.gio;
    int tg_phut = phut - x.phut;
    int tg_giay = giay - x.giay;
    
    if (tg_giay < 0) {
        tg_giay += 60;
        tg_phut--;
    }
    if (tg_phut < 0) {
        tg_phut += 60;
        tg_gio--;
    }
	Time hieu(tg_gio, tg_phut, tg_giay);
    return hieu;
}


bool Time::operator >(const Time &x) const {
    if (gio != x.gio) return gio > x.gio;
    if (phut != x.phut) return phut > x.phut;
    return giay > x.giay;
}

bool Time::operator <(const Time &x) const {
    if (gio != x.gio) return gio < x.gio;
    if (phut != x.phut) return phut < x.phut;
    return giay < x.giay;
}

bool Time::operator >=(const Time &x) const {
    return (*this > x || *this == x);
}

bool Time::operator <=(const Time &x) const {
    return (*this < x || *this == x);
}

bool Time::operator ==(const Time &x) const {
    return gio == x.gio && phut == x.phut && giay == x.giay;
}

bool Time::operator !=(const Time &x) const {
    return !(*this == x);
}


Time Time::congthemGiay(int x){
	giay += x;
	chuanhoa();
}
Time Time::congthemPhut(int x){
	phut += x;
	chuanhoa();
}
Time Time::congthemGio(int x){
	gio += x;
	chuanhoa();
}
int Time::tongSoGiay() const{
	return gio * 3600 + phut * 60 + giay;
}

int Time::khoangCachThoiGian(Time &x) {
    int t1 = this->tongSoGiay();
    int t2 = x.tongSoGiay();
    return abs(t1 - t2);
}
Time Time::hieuThoiGian(Time &x) {
    int khoangCach = this->khoangCachThoiGian(x);
    Time ketQua;
    ketQua.chuyendoi(khoangCach);
    return ketQua;
}
void Time::chuyenDoi12h(){
    string period = "AM";
    int gio12 = gio;

    if (gio == 0) {
        gio12 = 12;  
    } else if (gio == 12) {
        period = "PM";  
    } else if (gio > 12) {
        gio12 = gio - 12;
        period = "PM";
    }

    cout << setfill('0') << setw(2) << gio12 << ":"
         << setfill('0') << setw(2) << phut << ":"
         << setfill('0') << setw(2) << giay << " " << period << endl;
}
string Time::phanLoaiThoiGianTrongNgay(){
    if (gio >= 0 && gio < 12)
        return "Buoi sang";
    else if (gio >= 12 && gio < 18)
        return "Buoi chieu";
    else
        return "Buoi toi";
}



int main(){
	Time t1, t2, t3;
    cout << "Nhap thoi gian thu nhat (gio phut giay): ";
    cin >> t1;
    cout << "Nhap thoi gian thu hai (gio phut giay): ";
    cin >> t2;

    t3 = t1 - t2;
    cout << "Hieu thoi gian: " << t3;
	return 0;
}
