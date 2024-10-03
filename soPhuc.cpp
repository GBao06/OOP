#include<iostream>
#include<math.h>
using namespace std;

class soPhuc{
	private:
		float thuc, ao;
	public:
		soPhuc();
		soPhuc( float t, float a);
		soPhuc( soPhuc &sp);
		float getThuc();
		float getAo();
		string dau();
		friend istream &operator >> (istream &in, soPhuc &sp);
		friend ostream &operator << (ostream &out, soPhuc &sp);
		soPhuc operator + (const soPhuc &sp) const;
		soPhuc operator - (const soPhuc &sp) const;
		soPhuc operator * (const soPhuc &sp) const;
		soPhuc operator / (const soPhuc &sp) const;
		soPhuc &operator += ( const soPhuc &sp);
		soPhuc &operator -= ( const soPhuc &sp);
		soPhuc &operator *= ( const soPhuc &sp);
		soPhuc &operator /= ( const soPhuc &sp);
		soPhuc &operator ++ ();
		soPhuc &operator ++ (int i);
		soPhuc &operator -- ();
		soPhuc &operator -- (int i);
		bool operator < (const soPhuc &sp) const;
		bool operator > (const soPhuc &sp) const;
		bool operator == (const soPhuc &sp) const;
		bool operator != (const soPhuc &sp) const;
		bool operator <= (const soPhuc &sp) const;
		bool operator >= (const soPhuc &sp) const;
};

istream &operator >> (istream &in, soPhuc &sp){
	in >> sp.thuc >> sp.ao;
	return in;
}
ostream &operator << (ostream &out, soPhuc &sp){
	out << sp.thuc << sp.dau() <<sp.ao <<"i"<<endl;
	return out;
}


soPhuc::soPhuc(){
	thuc = 0;
	ao = 0;
}
soPhuc::soPhuc(float t, float a){
	thuc = t;
	ao = a;
}
soPhuc::soPhuc(soPhuc &sp){
	thuc = sp.thuc;
	ao = sp.ao;
}

float soPhuc::getThuc(){
	return thuc;
}
float soPhuc::getAo(){
	return ao;
}

string soPhuc::dau(){
	if( ao >= 0 )
		return "+";
	else 
		return "";
}

soPhuc soPhuc::operator + ( const soPhuc &sp) const{
	soPhuc tong(thuc+sp.thuc,ao+sp.ao);
	return tong;
}
soPhuc soPhuc::operator - ( const soPhuc &sp) const{
	soPhuc hieu(thuc-sp.thuc, ao-sp.ao);
	return hieu;
}
soPhuc soPhuc::operator *( const soPhuc &sp) const{
	soPhuc tich(thuc*sp.thuc - ao*sp.ao , thuc*sp.ao + ao*sp.thuc);
	return tich;
}
soPhuc soPhuc::operator / (const soPhuc &sp) const{
	float t = (thuc*sp.thuc +  ao*sp.ao);
	float a = (ao*sp.thuc -  thuc*sp.ao);
	float m = (sp.thuc*sp.thuc + sp.ao*sp.ao);
	soPhuc thuong( t /m, a /m );
	return thuong;
}

soPhuc &soPhuc::operator +=( const soPhuc &sp){
	thuc += sp.thuc;
	ao += sp.ao;
	return *this;
}
soPhuc &soPhuc::operator -=( const soPhuc &sp){
	thuc -= sp.thuc;
	ao -= sp.ao;
	return *this;
}
soPhuc &soPhuc::operator *=( const soPhuc &sp){
	thuc = thuc*sp.thuc - ao*sp.ao;
	ao = thuc*sp.ao + ao*sp.thuc;
	return *this;
}
soPhuc &soPhuc::operator /=( const soPhuc &sp){
	float t = (thuc*sp.thuc +  ao*sp.ao);
	float a = (ao*sp.thuc -  thuc*sp.ao);
	float m = (sp.thuc*sp.thuc + sp.ao*sp.ao);
	thuc = t/m;
	ao = a/m;
	return *this;
}

soPhuc &soPhuc::operator ++ (){
	++thuc;
	return *this;
}
soPhuc &soPhuc::operator ++ (int i){
	thuc++;
	return *this;
}
soPhuc &soPhuc::operator -- (){
	--thuc;
	return *this;
}
soPhuc &soPhuc::operator -- (int i){
	thuc--;
	return *this;
}

bool soPhuc::operator == (const soPhuc &sp) const{
	return (thuc == sp.thuc) && (ao == sp.ao);
}
bool soPhuc::operator != (const soPhuc &sp) const{
	return !(*this == sp);
}
bool soPhuc::operator <= (const soPhuc &sp) const{
	return !(*this == sp);
}
bool soPhuc::operator >= (const soPhuc &sp) const{
	return !(*this == sp);
}
bool soPhuc::operator < (const soPhuc &sp) const{
	return (sqrt(thuc*thuc+ao*ao)) < (sqrt(sp.thuc*sp.thuc+sp.ao*sp.ao));
}
bool soPhuc::operator > (const soPhuc &sp) const{
	return (sqrt(thuc*thuc+ao*ao)) > (sqrt(sp.thuc*sp.thuc+sp.ao*sp.ao));
}


int main(){
	soPhuc sp1,sp2,sp3;
	cin>>sp1;
	cin>>sp2;

	return 0;
}
