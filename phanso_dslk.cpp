#include<bits/stdc++.h>

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
		bool operator > (const phanso &x) const {
			return tu * x.mau > x.tu * mau;
		}
		bool ispositive() const{
			return tu > 0;
		}
		double trave() const{
			return static_cast<double>(tu) / mau;
		}
};

struct node{
	phanso ps;
	node* next;
};

node* taonode(int tu, int mau){
	node *tem = new node;
	tem->ps = phanso(tu,mau);
	tem->next = NULL;
	return tem;
}

void chencuoi(node*& head ,int tu, int mau){
	node *newNode = taonode(tu,mau);
	if ( head == NULL){
		head = newNode;
	}else{
		node* tem = head;
		while( tem->next != NULL){
			tem = tem->next;
		}
		tem->next = newNode;
	}
	
}

void in(node* head) {
    node* tem = head;
    bool isFirst = true;
    while (tem != NULL) {
        if (!isFirst) {
            cout << ",";
        }
        cout << tem->ps;
        isFirst = false;
        tem = tem->next;
    }
    cout << endl;
}

void xoa(node *&head){
	while( head != NULL && fabs(head->ps.trave()) < 1){
		node *tem = head;
		head = head->next;
		delete tem;
	}
	
	node* tem = head;
	node* luu = NULL;
	while( tem != NULL){
		if( fabs(tem->ps.trave())< 1){
			luu->next = tem->next;
			delete tem;
			tem = luu->next;
		}else{
			luu = tem;
			tem = tem->next;
		}
	}
}

bool compare( phanso ps1, phanso ps2){
	return ps1 < ps2;
}
void sapxep(node *& head){
	if( head == NULL || head->next == NULL)	return;
	for(node *i = head;i->next != NULL; i = i->next){
		for( node *j = head;j->next != NULL ;j = j->next){
			if(i->ps > j->ps){
				swap(i->ps,j->ps);
			}
		}
	}
}


int main(){
	node *head = NULL;
	int tu,mau;
	while( true){
		cout<<"Nhap phan so: ";
		cin>>tu>>mau;
		if ( mau == 0 ) break;
		chencuoi(head,tu,mau);
	}
	cout<<"Danh sach phan so vua nhap: ";
	in(head);
//	cout<<"Danh sach sau khi xoa cac phan tu co gia tri < 1: ";
//	xoa(head);
//	in(head);
	cout<<"Danh sach phan so vua sapxep: ";
	sapxep(head);
	in(head);
	return 0;
}
