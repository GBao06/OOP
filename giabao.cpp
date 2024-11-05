#include<bits/stdc++.h>    

using namespace std;

class Time {
    private:
        int hour, minute, second;
    public:
        Time();
        Time(int h, int m, int s);
        Time(const Time &t);
        void SetTime(int h, int m, int s);
        void SetHour(int h);
        int getHour();
        void SetMinute(int m);
        int getMinute();
        void SetSecond(int s);
        int getSecond();
        bool Validate();
        string ToString(string strFormat);
        Time getGMT(int h);
        int Interval(const Time &t);
        Time operator + (const Time &t) const;
        Time operator - (const Time &t) const;
        Time operator += (const Time &t);
        Time operator -= (const Time &t);    
        bool operator < (const Time &t) const;
        bool operator <= (const Time &t) const;
        bool operator > (const Time &t) const;
        bool operator >= (const Time &t) const;
        bool operator == (const Time &t) const;
        bool operator != (const Time &t) const;
        Time operator ++();
        Time operator ++(int i);
        Time operator --();
        Time operator --(int i);
        friend istream &operator >> (istream &in, Time &tm) {
            in >> tm.hour >> tm.minute >> tm.second;
            return in;
        }
        friend ostream &operator << (ostream &out, Time &tm) {
            out << setfill('0') << setw(2) << tm.hour << ":"
                << setfill('0') << setw(2) << tm.minute << ":"
                << setfill('0') << setw(2) << tm.second << endl;
            return out;
        }
};

Time::Time() {
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
}

Time::Time(int h, int m, int s) {
    this->hour = h;
    this->minute = m;
    this->second = s;
}

Time::Time(const Time &t) {
    this->hour = t.hour;
    this->minute = t.minute;
    this->second = t.second;
}

int Time::getHour(){
    return this->hour;
}

int Time::getMinute(){
    return this->minute;
}

int Time::getSecond(){
    return this->second;
}

void Time::SetHour(int h){
    this->hour = h;
}

void Time::SetMinute(int m){
    this->minute = m;
}

void Time::SetSecond(int s){
    this->second = s;
}

void Time::SetTime(int h, int m, int s){
    this->hour = h;
    this->minute = m;
    this->second = s;
}

bool Time::operator >(const Time &x) const {
    if (hour != x.hour) return hour > x.hour;
    if (minute != x.minute) return minute > x.minute;
    return second > x.second;
}

bool Time::operator <(const Time &x) const {
    if (hour != x.hour) return hour < x.hour;
    if (minute != x.minute) return minute < x.minute;
    return second < x.second;
}

bool Time::operator >=(const Time &x) const {
    return (*this > x || *this == x);
}

bool Time::operator <=(const Time &x) const {
    return (*this < x || *this == x);
}

bool Time::operator ==(const Time &x) const {
    return hour == x.hour && minute == x.minute && second == x.second;
}

bool Time::operator !=(const Time &x) const {
    return !(*this == x);
}

Time Time::operator++() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
    }
    if (minute == 60) {
        minute = 0;
        hour++;
    }
    if (hour == 24) {
        hour = 0;
    }
    return *this;
}

Time Time::operator++(int i) {
    Time temp = *this;
    ++(*this);
    return temp;
}

Time Time::operator--() {
    second--;
    if (second == -1) {
        second = 59;
        minute--;
    }
    if (minute == -1) {
        minute = 59;
        hour--;
    }
    if (hour == -1) {
        hour = 23;
    }
    return *this;
}

Time Time::operator--(int i) {
    Time temp = *this;
    --(*this);
    return temp;
}

bool Time::Validate() {
    if (hour < 0 || hour >= 24) return false;
    if (minute < 0 || minute >= 60) return false;
    if (second < 0 || second >= 60) return false;
    return true;
}

Time Time::getGMT(int h) {
    Time s = *this;
    s.hour += h;
    if (s.hour >= 24) {
        s.hour -= 24;
    } else if (s.hour < 0) {
        s.hour += 24;
    }
    return s;
}

int Time::Interval(const Time &t) {
    int SecondsThis = hour * 3600 + minute * 60 + second;
    int SecondsT = t.hour * 3600 + t.minute * 60 + t.second;

    return abs(SecondsThis - SecondsT);
}

Time Time::operator + (const Time &t) const {
    int SecondsThis = hour * 3600 + minute * 60 + second;
    int SecondsT = t.hour * 3600 + t.minute * 60 + t.second;
    int sum = SecondsThis + SecondsT;

    return Time(sum / 3600, (sum % 3600) / 60, sum % 60);
}

Time Time::operator - (const Time &t) const {
    int SecondsThis = hour * 3600 + minute * 60 + second;
    int SecondsT = t.hour * 3600 + t.minute * 60 + t.second;
    int diff = SecondsThis - SecondsT;

    if (diff < 0) diff += 24 * 3600;

    return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
}
string Time::ToString(string strFormat) {
    string result = strFormat;
    size_t pos = result.find("hh");
    if (pos != string::npos) {
        result.replace(pos, 2, to_string(hour));
    }
    pos = result.find("mm");
    if (pos != string::npos) {
        result.replace(pos, 2, to_string(minute));
    }

    pos = result.find("ss");
    if (pos != string::npos) {
        result.replace(pos, 2, to_string(second));
    }
    if (hour < 10) {
        result.replace(result.find("hh"), 2, "0" + to_string(hour));
    }

    if (minute < 10) {
        result.replace(result.find("mm"), 2, "0" + to_string(minute));
    }

    if (second < 10) {
        result.replace(result.find("ss"), 2, "0" + to_string(second));
    }

    return result;
}

int main() {
    // a. 
    Time t1, t2;
    cout << "Nhap thoi gian 1 (hh mm ss): ";
    cin >> t1;
    cout << "Nhap thoi gian 2 (hh mm ss): ";
    cin >> t2;

    // b.
    cout << "Thoi gian 1: " << t1;
    cout << "Thoi gian 2: " << t2;

    // c. 
    Time sum = t1 + t2;
    Time diff = t1 - t2;
    cout << "Tong thoi gian: " << sum;
    cout << "Hieu thoi gian: " << diff;

    // d.
    int n;
    cout << "Nhap so luong thoi gian: ";
    cin >> n;

    Time times[100];
    cout << "Nhap " << n << " thoi gian: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    // e.
    Time t;
    cout << "Nhap thoi gian can so sanh: ";
    cin >> t;
    
    vector<Time> v;
    for (int i = 0; i < n; i++) {
        if (times[i] >= t) {
            v.push_back(times[i]);
        }
    }

    cout << "Danh sach thoi gian sau khi loc: " << endl;
	for (int i = 0; i < v.size(); i++) {
	    cout << v[i]; 
	}
    // f. 
    sort(v.begin(), v.end());

    cout << "Danh sach thoi gian sau khi sap xep: " << endl;
	for (int i = 0; i < v.size(); i++) {
	    cout << v[i];  
	}

    return 0;
}

