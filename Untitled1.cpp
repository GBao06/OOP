#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Person {
	private:
	    string Name;
	    string Address;
	    string Phone;
	public:
	    Person(string name = "", string address = "", string phone = "") 
	        : Name(name), Address(address), Phone(phone) {}
	    ~Person() {}
	    void setName(const string& name) { Name = name; }
	    void setAddress(const string& address) { Address = address; }
	    void setPhone(const string& phone) { Phone = phone; }
	    string getName() const { return Name; }
	    string getAddress() const { return Address; }
	    string getPhone() const { return Phone; }
	    string getFirstName() const {
	        size_t pos = Name.find(' ');
	        return (pos != string::npos) ? Name.substr(0, pos) : Name;
	    }
	    
	    string getLastName() const {
	        size_t pos = Name.find(' ');
	        return (pos != string::npos) ? Name.substr(pos + 1) : "";
	    }
	    bool operator>(const Person& other) const {
	        return Name > other.Name;
	    }
	    bool operator>=(const Person& other) const {
	        return Name >= other.Name;
	    }
	    bool operator<(const Person& other) const {
	        return Name < other.Name;
	    }
	    bool operator<=(const Person& other) const {
	        return Name <= other.Name;
	    }
	    bool operator==(const Person& other) const {
	        return Name == other.Name;
	    }
	    bool operator!=(const Person& other) const {
	        return Name != other.Name;
	    }
	
	    friend istream& operator>>(istream& is, Person& person) {
	        cout << "Nhap ten: ";
	        getline(is, person.Name);
	        cout << "Nhap dia chi: ";
	        getline(is, person.Address);
	        cout << "Nhap so dien thoai: ";
	        getline(is, person.Phone);
	        return is;
	    }
	
	    friend ostream& operator<<(ostream& os, const Person& person) {
	        os << "Ten: " << person.Name<<endl; 
			os<< "Dia chi: " << person.Address<<endl; 
			os<< "So dien thoai: " << person.Phone<<endl;
	        return os;
	    }
};
class List {
private:
    Person* People;  
    int maxSize;
    int currentSize;

public:
    List(int size) : maxSize(size), currentSize(0) {
        People = new Person[maxSize];
    }
    ~List() {
        delete[] People;
    }
    void inputList() {
        while (currentSize < maxSize) {
            Person temp;
            cin >> temp;
            if (temp.getName().empty()) break;
            People[currentSize++] = temp;
        }
    }
    void displayList() const {
        for (int i = 0; i < currentSize; ++i) {
            cout << People[i] << endl;
        }
    }
    Person* searchByName(const string& name) {
        for (int i = 0; i < currentSize; ++i) {
            if (People[i].getName() == name)
                return &People[i];
        }
        return nullptr;
    }
    Person* searchByPhone(const string& phone) {
        for (int i = 0; i < currentSize; ++i) {
            if (People[i].getPhone() == phone)
                return &People[i];
        }
        return nullptr;
    }

    void deleteByName(const string& name) {
        int i = 0;
        while (i < currentSize) {
            if (People[i].getName() == name) {
                for (int j = i; j < currentSize - 1; ++j) {
                    People[j] = People[j + 1];
                }
                --currentSize;
            } else {
                ++i;
            }
        }
    }

    void sortList() {
        for (int i = 0; i < currentSize - 1; ++i) {
            for (int j = i + 1; j < currentSize; ++j) {
                if (People[i] > People[j]) {
                    swap(People[i], People[j]);
                }
            }
        }
    }
};
int main() {
    int maxSize;
    cout << "Nhap so luong can bo toi da: ";
    cin >> maxSize;
    cin.ignore(); 
    List list(maxSize);
    list.inputList();
    cout << "\nDanh sach can bo:\n";
    list.displayList();
    string phone;
    cout << "\nNhap so dien thoai can tim: ";
    getline(cin, phone);
    Person* found = list.searchByPhone(phone);
    if (found) {
        cout << "\nThong tin cua can bo: " << *found << endl;
    } else {
        cout << "KHONG TIM THAY\n";
    }
    string nameToDelete;
    cout << "\nNhap ten can bo can xoa: ";
    getline(cin, nameToDelete);
    list.deleteByName(nameToDelete);
    cout << "\nDanh sach can bo sau khi xoa:\n";
    list.displayList();
    list.sortList();
    cout << "\nDanh sach can bo sau khi sap xep:\n";
    list.displayList();

    return 0;
}


