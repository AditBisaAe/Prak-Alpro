#include <conio.h>
#include <iostream>
using namespace std;

class sorting {
	friend istream& operator>>(istream&, sorting&);
	friend ostream& operator>>(ostream&, const sorting&);
	public:
		void selection_sort();
		int pencarianBiner(int);
		void cetakbaris(int,int,int);
		void selection_sort(int&, int&);
		void cari_data();
		int data[10], n;
	private:
		void minimum(int, int, int&);
		void tukar (int&, int&);
};

void sorting::selection_sort(){ 
	int t;
	for (int i = 0; i<n; i++) {
		minimum(i, n, t);
		tukar(data[i], data[t]);
	}
}

void sorting::minimum(int dari, int n, int &tempat){
	int min = data[dari];
	tempat = dari;
	for (int i = dari+1; i<n; i++){
		if (data[i] < min){
			min = data[i];
			tempat = i;
		}
	}
}

void sorting::tukar (int &a, int &b){ 
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void sorting::cari_data(){
	int posisi = 0, kunciPencarian;
	cout <<"Cari Data : ";
	cin >> kunciPencarian;
	for(int i=0; i<n; i++){
		if(data[i] == kunciPencarian){
			posisi = i+1;
	}
}
	if(pencarianBiner(kunciPencarian) == -1)
		cout <<"Tidak ada"<<endl;
	else
		cout << "ada, posisi di : "<< posisi <<endl;
}

int sorting::pencarianBiner(int kunciPencarian){ 
	int middle, low=0, high=n;
	while (low <= high) {
		middle = (low+high) / 2;
		cetakbaris(low, middle, high);
	if (kunciPencarian == data[middle])
		return middle;
	else if (kunciPencarian < data[middle])
		high = middle - 1;
	else low = middle + 1;
	}
	return -1;
}

void sorting::cetakbaris(int low, int middle, int high){
	cout << low <<endl <<middle <<endl <<high <<endl;
}

istream& operator>>(istream& in, sorting& A){
	cout << "Masukkan jumlah data : ";
	cin>>A.n;
	for(int i=0; i<A.n;i++){
		cout <<"Data["<<i<<"] : ";
		in >>A.data[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const sorting& A){
	for(int i=0; i<A.n;i++){
		out<<A.data[i]<<" ";
	}
	return out;
}

int main(){
	sorting srt;
	cin >> srt;
	cout <<"Data sebelum sorting :"<<endl;
	cout << srt <<endl;
	srt.selection_sort();
	cout <<"Data sesudah sorting :"<<endl;
	cout << srt <<endl<<endl;
	srt.cari_data();
	return 0;
}
