#include <iostream>
#include <string>
using namespace std;

struct kereta{
	int id_kereta;
	string nama_kereta;
	string Stasiun_keberangkatan;
	int harga_tiket;
};
typedef kereta kereta_api;

struct rute {
	kereta_api rute_kereta;
	int jumlah_gerbong;
};

typedef rute infotype;
typedef struct tNode *address;
typedef struct tNode {
	infotype Info;
	address Next;
}Node;
typedef Node *List;

void CreateEmpty(List &L) {
	L = NULL;
}

bool IsEmpty(List L) {
	return(L == NULL);
}

bool IsOneElmt(List L) {
	return (IsEmpty(L->Next));
}

void InsertFirst(List &L, address P) {
	P->Next = L;
	L = P;
}

void InsertAfter(List &L, address Prec, address P) {
	P->Next = Prec->Next;
	Prec->Next = P;
}

void InsertLast(List &L, address P) {
	if (IsEmpty(L))
		InsertFirst(L, P);
	else if (IsOneElmt(L))
		InsertAfter(L, L, P);
	else
		InsertLast(L->Next, P);
}

void DelFirst(List &L) {
	address P;
	P = L;
	L = L->Next;
	delete(P);
}

void DelLast(List &L) {
	if (IsOneElmt(L))
		DelFirst(L);
	else
		DelLast(L->Next);
}

void DelAt(List &L, address P) {
	if (!IsEmpty(L)) {
		if (L == P)
			DelFirst(L);
		else
			DelAt(L->Next, P);
	}
}

address Alokasi(infotype x) {
	address P = new(Node);
	if (P == NULL)
		return NULL;
	else {
		P->Info = x;
		P->Next = NULL;
		return P;
	}
}

void PrintInfo(List L) {
	if (IsEmpty(L)) {
		//no action
	}
	else {
		cout << "id Kereta         : "<<L->Info.rute_kereta.id_kereta<<endl;
		cout << "Harga Tiket       : Rp."<<L->Info.rute_kereta.harga_tiket<<endl;
		cout << "Nama Kereta       : "<<L->Info.rute_kereta.nama_kereta<<endl;
		cout << "Stasiun Berangkat : "<<L->Info.rute_kereta.Stasiun_keberangkatan<<endl;
		cout << "Jumlah Gerbong    : "<<L->Info.jumlah_gerbong<<endl<<endl;
		cout << "=========================================="<<endl<<endl;

		PrintInfo(L->Next);
	

	}
}

int main(){
	List myList;
	CreateEmpty(myList);
	infotype rute_kai;
	kereta_api tujuan_kereta;
	kereta_api jogja = {1, "Trans Jogja", "Yogyakarta", 150000};
	kereta_api jakarta = {2, "Fajar Utama", "Jakarta", 120000};
	kereta_api malang = {3, "Gajayana", "Malang", 110000};
	kereta_api cirebon = {4, "Semrani", "Cirebon", 200000};
	kereta_api solo = {5, "Argo Lawu", "Solo", 55000};

	cout<<"\n============ RUTE PERTAMA ================";
	rute_kai.rute_kereta = jakarta;
	rute_kai.jumlah_gerbong = 10;
	address tujuan = Alokasi(rute_kai);
	InsertFirst(myList, tujuan);
	
	rute_kai.rute_kereta = cirebon;
	rute_kai.jumlah_gerbong = 5;
	tujuan = Alokasi(rute_kai);
	InsertLast(myList, tujuan);

	rute_kai.rute_kereta = malang;
	rute_kai.jumlah_gerbong = 7;
	tujuan = Alokasi(rute_kai);
	InsertLast(myList, tujuan);
	cout<<"\n\n";
	PrintInfo(myList);
	cout<<"\n\n";
	system("pause");
	cout<<"\n\n";
	system("cls");

	cout<<"\n============= RUTE KEDUA ================";
	rute_kai.rute_kereta = jogja;
	rute_kai.jumlah_gerbong = 3;
	tujuan = Alokasi(rute_kai);
	InsertAfter(myList,myList->Next, tujuan);
	cout<<"\n\n";

	PrintInfo(myList);
	cout<<"\n\n";
	system("pause");
	cout<<"\n\n";
	system("cls");

	cout<<"\n============= RUTE KETIGA ================";
	rute_kai.rute_kereta = solo;
	rute_kai.jumlah_gerbong = 9;
	tujuan = Alokasi(rute_kai);
	InsertLast(myList, tujuan);
	DelAt(myList, myList->Next->Next->Next);
	cout<<"\n\n";

	PrintInfo(myList);
	cout<<"\n\n";
	system("pause");
	cout<<"\n\n";
	system("cls");

	cout<<"\n============ RUTE KEEMPAT ================";
	cout<<"\n\n";
	DelAt(myList, myList->Next);
	PrintInfo(myList);
	cout<<"\n\n";
	system("pause");
	cout<<"\n\n";
	system("cls");
}