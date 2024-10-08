#include<iostream>
#include<iomanip>

using namespace std;

class Time{
	private:
		int gio,phut,giay;
	public:
		Time();
		Time(int giay, int phut, int gio);
		Time(Time &tm);
		void setTime( int gio, int phut, int giay);
		void chuanHoa(int x);
		bool kiemtra();
		int getGio();
		int getPhut();
		int getGiay();
		friend istream &operator >> ( istream &in, Time &tm);
		friend ostream &operator << ( ostream &out, Time &tm);
		Time &operator +( Time &x) const;
		Time &operator -( Time &x) const;
		bool operator > (Time &x) const;
		bool operator >= (Time &x) const;
		bool operator < (Time &x) const;
		bool operator <= (Time &x) const;
		bool operator == (Time &x) const;
		bool operator != (Time &x) const;
		
		
};
Time::Time(){
	this->giay = 0;
	this->gio = 0;
	this->phut = 0;
}
Time::Time(int giay, int phut, int gio){
	this->giay = giay;
	this->gio = gio;
	this->phut = phut;
}
Time::Time( Time &tm){
	gio = this->gio;
	giay = this->giay;
	phut = this->phut;
}
void Time::setTime(int gio, int phut, int giay){
	this->giay = giay;
	this->gio = gio;
	this->phut = phut;
}
int Time::getGio(){
	return gio;
}
int Time::getPhut(){
	return phut;
}
int Time::getGiay(){
	return giay;
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
void Time::chuanHoa(int x){
	gio = x/3600;
	phut = x%3600/60;
	giay = x%3600/60;
}
bool Time::operator >(Time &X) const{
	return gio > x.gio || phut > x.phut || giay > x.giay;
}
bool Time::operator <(Time &X) const{
	return gio < x.gio || phut > x.phut || giay > x.giay;
}
bool Time::operator >(Time &X) const{
	return gio > x.gio || phut > x.phut || giay > x.giay;
}
bool Time::operator >(Time &X) const{
	return gio > x.gio || phut > x.phut || giay > x.giay;
}
bool Time::operator == (Time &X) const{
	return gio == x.gio && phut == x.phut && giay == x.giay;
}
bool Time::operator != (Time &X) const{
	return !(*this == x);
}int main(){

	return 0;
}
