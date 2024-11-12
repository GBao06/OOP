#include<bits/stdc++.h>

using namespace std;

class MyDate{
	private:
		int ngay, thang,nam;
	public:
		MyDate();
		MyDate(int ngay, int thang, int nam);
		void hienthi() const ;
		bool operator > ( const MyDate &m) const;
};

MyDate::MyDate(){
	this->nam = this->thang = this->ngay = 0;
}
MyDate::MyDate(int ngay, int thang, int nam){
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}
void MyDate::hienthi() const {
	cout<<ngay<<" "<<thang<<" "<<nam<<endl;
}
bool MyDate::operator > ( const MyDate &m) const{
	if( nam != m.nam )	return nam > m.nam;
	else if( thang != m.thang ) return thang > m.thang;
	else	return ngay > m.ngay;
}



class myPerson : public MyDate {
	private:
		string name, address,phone;
	public:
		myPerson();
		myPerson(int ngay, int thang, int nam ,string name, string address, string phone);
		void hienthi2() const ;
};

myPerson::myPerson(){
	this->name = this->address = this->phone = "";
}
myPerson::myPerson(int ngay, int thang, int nam, string name,string address, string phone)
:MyDate(ngay,thang,nam){
	this->name = name;
	this->address = address;
	this->phone = phone;
}
void myPerson::hienthi2() const {
	cout<<"Ten: "<<name<<endl;
	cout<<"Dia chi: "<<address<<endl;
	cout<<"SDT: "<<phone<<endl;
	hienthi();
}

class Officer : public myPerson{
	private:
		float salary;
	public:
		Officer();
		Officer(int ngay, int thang, int nam ,string name, string address, string phone, float salary);
		void hienthi3() const;
};
Officer::Officer(){
	salary = 0.0;
}
Officer::Officer(int ngay, int thang, int nam ,string name, string address, string phone, float salary)
:myPerson(ngay,thang,nam,name,address,phone){
	this->salary = salary;
}
void Officer::hienthi3() const{
	hienthi2();
	cout<<"Luong: "<<salary;
}

bool compareOfficer(const Officer &a, const Officer &b) {
    return a > b;
}
int main(){
  cout << "Nhap so luong Persons: ";
    int n; cin >> n;

    vector<Officer> persons(n);
    for (int i = 0; i < n; ++i) {
        int ngay, thang, nam;
        string name, address, phone;
        float salary;

        cout << "\nNhap thong tin cho officer " << i + 1 << ":\n";
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> ngay >> thang >> nam;
        cin.ignore(); 
        cout << "Nhap ten: ";
        getline(cin, name);
        cout << "Nhap dia chi: ";
        getline(cin, address);
        cout << "Nhap SDT: ";
        getline(cin, phone);
        cout << "Nhap luong: ";
        cin >> salary;

        persons[i] = Officer(ngay, thang, nam, name, address, phone, salary);
    }

    sort(persons.begin(), persons.end(), compareOfficer);


    cout << "\nDanh sach Officers sau khi sap xep:\n";
    for (const auto &person : persons) {
        person.hienthi3();
        cout << "\n--------------------------\n";
    }
	
	return 0;
}
