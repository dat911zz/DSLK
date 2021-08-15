#include<iostream>
#include<cstdlib>
#include"MyLib.h"
using namespace std;
//Macro
typedef int Data;

//=====================================
//Struct and Constant
//Single List
struct Node
{
	Data info;
	Node* next; //Tro den Node tiep theo
};
struct SList
{
	Node* head;
	Node* tail;
};
//Stack
struct Stack
{
	Node* top;
};

//=====================================
//Prototype
void thucHienChuongTrinh();
Node* createNode(Data x);
void deleteNode(Node*& p);
//Single List
void initList(SList& l);
bool isEmptyList(SList l);
void checkMemory(Node* p);
void createSList_Manual(SList& l, int n);
void createSList_Random(SList& l, int n);
void showSList(SList l);
void _nhapXuatDSLK(SList& l, int& n);
Node* searchSList(SList l, int x);
void addHeadSList(SList& l, Node* p);
void addTailSList(SList& l, Node* p);
void addAfterNodeSList(SList& l, Node* q, Node* p);
void nhapx(int& x);
void _themNodePsauNodeQ(SList& l, Node*& q, Node*& p, int& n);
void deleteHeadSList(SList& l);
void deleteTailSList(SList& l);
void interchangeSortSList_Ascending(SList& l);
void interchangeSortSList_Descending(SList& l);
void deleteAfterNodeSList(SList& l, Node* q, Node* p);
void _xoaNodePsauNodeQ(SList& l, Node*& p, Node*& q, int& n);
int countSList(SList l);
int sumOfSList(SList l);
void xuatCacPTChan(SList l);
void xuatCacPTLe(SList l);
void _XuatCacPTChan_Le(SList l);
void xuatCacPTVTChan(SList l);
void xuatCacPTVTLe(SList l);
void _XuatCacPTVTChan_Le(SList l);
int countXInSList(SList l, int x);
int timPTMaxSList(SList l);
int timPTMinSList(SList l);
int timPTChanMinSList(SList l);
//=====================================
//Main
void main()
{
	loading();
	thucHienChuongTrinh();
	//TestBGColor();
}

//=====================================
//Functions
void thucHienChuongTrinh()
{
	int a[100];
	int chon, n, x;
	SList l;
	Node* q, * p;
	srand((int)time(NULL));
	do
	{
		system("cls");
		XY(35, 6);
		BGcolor(6);
		cout << "-=Chuong trinh X=-";
		chon = menu_02();
		system("cls");
		cout << "Your choice is: " << chon << endl;
		ShowCur(1);
		switch (chon)
		{
		case 1:
		{
			_nhapXuatDSLK(l, n);
			break;
		}
		case 2:
		{
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			cout << "Nhap vao node can tim: ";
			cin >> x;
			q = searchSList(l, x);
			if (!q)
			{
				cout << "\t  <Not Found!>";
			}
			else
			{
				cout << "-Tim thay " << x << " tai vi tri truoc ";
				if (!q->next)
				{
					cout << "[NULL]" << endl;
				}
				else
				{
					cout << "[" << q->next->info << "]" << endl;
				}
			}
			break;
		}
		case 3:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			nhapx(x);
			q = createNode(x);
			addHeadSList(l, q);
			cout << endl;
			showSList(l);
			break;
		case 4:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			nhapx(x);
			q = createNode(x);
			addTailSList(l, q);
			cout << endl;
			showSList(l);
			break;
		case 5:
			_themNodePsauNodeQ(l, q, p, n);
			break;
		case 6:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			deleteHeadSList(l);
			showSList(l);
			break;
		case 7:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			deleteTailSList(l);
			showSList(l);
			break;
		case 8:
			_xoaNodePsauNodeQ(l, p, q, n);
			showSList(l);
			break;
		case 9:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			interchangeSortSList_Ascending(l);
			showSList(l);
			break;
		case 10:
			_nhapXuatDSLK(l, n);
			if (n <= 0)
			{
				break;
			}
			interchangeSortSList_Descending(l);
			showSList(l);
			break;
		case 11:
			_nhapXuatDSLK(l, n);
			cout << "-So luong phan tu trong DSLK don: " << countSList(l);
			break;
		case 12:
			_nhapXuatDSLK(l, n);
			cout << "-Tong cac node trong DSLK don: " << sumOfSList(l);
			break;
		case 13:
			_nhapXuatDSLK(l, n);
			_XuatCacPTChan_Le(l);
			break;
		case 14:
			_nhapXuatDSLK(l, n);
			_XuatCacPTVTChan_Le(l);
			break;
		case 15:
			_nhapXuatDSLK(l, n);
			cout << "Nhap phan tu can dem: ";
			cin >> x;
			cout << "Co " << countXInSList(l,x) << " phan tu " << x << " trong DSLK don";
			break;
		case 16:
			_nhapXuatDSLK(l, n);
			cout << "\nPhan tu lon nhat trong DSLK: " << timPTMaxSList(l);
			cout << "\nPhan tu nho nhat trong DSLK: " << timPTMinSList(l);
			break;
		case 17:
			_nhapXuatDSLK(l, n);
			cout << "\nPhan tu chan nho nhat trong DSLK: " << timPTChanMinSList(l);
			break;
		default:
			system("cls");
			XY(30, 2);
			cout << "Thanks for your patient!" << endl;
			break;
		}
		cout << endl;
		system("pause");
	} while (chon > 0 && chon < 20);
}
//Node
Node* createNode(Data x)
{
	Node* p = new Node;
	if (!p)
	{
		cout << "Not enough memory!" << endl;
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}

void deleteNode(Node*& p)
{
	if (!p)
	{
		return;
	}
	delete p;
}
//Single List
void initList(SList& l)
{
	l.head = l.tail = NULL;
}

bool isEmptyList(SList l)
{
	return l.head == NULL;
}

void checkMemory(Node* p)
{
	if (!p)
	{
		BGcolor(4);
		cout << "Not Enough Memory!" << endl;
		return;
	}
}

void createSList_Manual(SList& l, int n)
{
	int x;
	Node* p;
	initList(l);
	for (int i = 0; i < n; i++)
	{
		//Input infomation
		cout << "Nhap node thu " << i << " :";
		cin >> x;
		//Create Node
		p = createNode(x);
		//Check memory
		if (!p)
		{
			BGcolor(4);
			cout << "Not Enough Memory!" << endl;
			return;
		}
		//Add p into SList
		if (isEmptyList(l) == 1)
		{
			l.head = l.tail = p;
		}
		else
		{						// [1|2]: [info|next]
			l.tail->next = p;	// [1|2]->[2|NULL]->NULL
			l.tail = p;			// [1|2]->[2|3]->[3|NULL]->NULL
		}
	}
}
void createSList_Random(SList& l, int n)
{
	int x;
	Node* p;
	initList(l);
	for (int i = 0; i < n; i++)
	{
		//Generate infomation
		x = rand() % 100;
		//Create Node
		p = createNode(x);
		//Check memory
		if (!p)
		{
			BGcolor(4);
			cout << "Not Enough Memory!" << endl;
			system("pause");
			return;
		}
		//Add p into SList l
		if (isEmptyList(l) == 1)
		{
			l.head = l.tail = p;
		}
		else
		{
			l.tail->next = p;
			l.tail = p;
		}
	}
}
void _nhapXuatDSLK(SList& l, int& n)
{
	int chon;
	cout << "Nhap n: ";
	cin >> n;
	if (n <= 0)
	{
		cout << "Processing to main Menu..." << endl;
		Sleep(500);
		return;
	}
	//Menu
	ShowCur(0);
	cout << "Vui long chon cach nhap DSLK: ";
	const char* s[100] = { "1. Nhap tu dong","2. Nhap thu cong" };
	chon = control(2, 30, 2, s);
	cout << endl;
	ShowCur(1);
	//-------
	switch (chon)
	{
	case 1:
		createSList_Random(l, n);
		goto x;
	case 2:
		createSList_Manual(l, n);
		goto x;
	default:
		cout << "Processing to main Menu..." << endl;
		Sleep(500);
		return;
	}
x: showSList(l);
}
void showSList(SList l)
{
	int i = 0;
	Node* p;
	p = l.head;
	cout << "\n\n\t-Single List-" << endl;
	if (!p)
	{
		cout << "\t  <Empty!>" << endl;
	}
	//while (p)
	//{
	//	cout << "\t  Node " << i++ << ": " << p->info << endl;
	//	p = p->next;
	//}
	//p = l.head;
	while (p)
	{
		cout << "[" << p->info << "]-> ";
		p = p->next;
	}
	if (!p)
	{
		cout << "[NULL]" << endl;
	}
}

Node* searchSList(SList l, int x)
{
	Node* p;
	p = l.head;
	while (p)
	{
		if (p->info == x)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

void addHeadSList(SList& l, Node* p)
{
	if (!p)
	{
		return;
	}
	else
	{
		if (isEmptyList(l) == 1)
		{
			l.head = l.tail = p;
		}
		else
		{
			p->next = l.head;
			l.head = p;
		}
	}
}

void nhapx(int& x)
{
	cout << "Nhap node muon them vao DSLK don: ";
	cin >> x;
}
void addTailSList(SList& l, Node* p)
{
	if (!p)
	{
		return;
	}
	else
	{
		if (isEmptyList(l) == 1)
		{
			l.head = l.tail = p;
		}
		else
		{
			l.tail->next = p;
			l.tail = p;
		}
	}
}

void addAfterNodeSList(SList& l, Node* q, Node* p)
{
	if (!p || !q)
	{
		return;
	}
	else
	{
		if (isEmptyList(l) == 1)
		{
			l.head = l.head = q;
		}
		else
		{
			if (q == l.tail)
			{
				addTailSList(l, p);
			}
			else
			{
				p->next = q->next;
				q->next = p;
			}
		}
	}
}

void _themNodePsauNodeQ(SList& l, Node*& q, Node*& p, int& n)
{
	int x, y;
	_nhapXuatDSLK(l, n);
	if (n <= 0)
	{
		return;
	}
	cout << "Nhap node q: ";
	cin >> y;
	cout << "Nhap node p muon them vao sau node q: ";
	cin >> x;
	p = createNode(x);
	q = l.head;
	while (q)
	{
		if (q->info == y)//Find node q
		{
			addAfterNodeSList(l, q, p);
		}
		q = q->next;
	}
	cout << endl;
	showSList(l);
}

void deleteHeadSList(SList& l)
{
	if (isEmptyList(l) == 1)
	{
		return;
	}
	else
	{
		Node* p = l.head;
		l.head = p->next;//Chuyen head cho node tiep theo
		p->next = NULL;
		delete p;
	}
}

void deleteTailSList(SList& l)
{
	if (isEmptyList(l) == 1)
	{
		return;
	}
	else
	{
		Node* p = l.tail;
		Node* q = l.head;
		//Cho q chay cho den node trc tail
		while (q->next != l.tail)
		{
			q = q->next;
		}
		//Cat node tail r thay q lam tail
		l.tail = q;
		l.tail->next = NULL;
		delete p;
	}
}

void deleteAfterNodeSList(SList& l, Node* q, Node* p)
{
	if (isEmptyList(l) == 1 || !p || !q)
	{
		return;
	}
	else
	{
		if (q == l.tail)
		{
			deleteTailSList(l);
		}
		else
		{
			if (q == l.head)
			{
				deleteHeadSList(l);
			}
			else
			{
				q->next = p->next;
				p->next = NULL;
				delete p;
			}
		}
	}
}

void _xoaNodePsauNodeQ(SList& l, Node*& p, Node*& q, int& n)
{
	int x, y;
	_nhapXuatDSLK(l, n);
	if (n <= 0)
	{
		return;
	}
	cout << "Nhap node p muon xoa: ";
	cin >> x;
	q = l.head;
	while (q)
	{
		if (q->next->info == x)
		{
			p = q->next; //Node can xoa
			deleteAfterNodeSList(l, q, p);
			return;
		}
		if (!q->next->info)
		{
			cout << "Not found!" << endl;
			return;
		}
		q = q->next;
	}
}

void interchangeSortSList_Ascending(SList& l)
{
	for (Node* p = l.head; p != l.tail; p = p->next)
	{
		for (Node* q = p->next; q != NULL; q = q->next)
		{
			if (p->info > q->info)
			{
				swap(p->info, q->info);
			}
		}
	}
}

void interchangeSortSList_Descending(SList& l)
{
	for (Node* p = l.head; p != l.tail; p = p->next)
	{
		for (Node* q = p->next; q != NULL; q = q->next)
		{
			if (p->info < q->info)
			{
				swap(p->info, q->info);
			}
		}
	}
}

int countSList(SList l)
{
	int count = 0;
	Node* p;
	p = l.head;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}

int sumOfSList(SList l)
{
	int S = 0;
	Node* p;
	p = l.head;
	while (p)
	{
		S += p->info;
		p = p->next;
	}
	return S;
}

void xuatCacPTChan(SList l)
{
	Node* p;
	p = l.head;
	while (p)
	{
		if (p->info % 2 == 0)
		{
			cout << "[" << p->info << "]-> ";
		}
		p = p->next;
	}
}

void xuatCacPTLe(SList l)
{
	Node* p;
	p = l.head;
	while (p)
	{
		if (p->info % 2 != 0)
		{
			cout << "[" << p->info << "]-> ";
		}
		p = p->next;
	}
}

void _XuatCacPTChan_Le(SList l)
{
	int chon = 0;
	ShowCur(0);
	cout << "Vui long chon loai xuat pt DSLK: ";
	const char* s[100] = { "1. Xuat pt chan","2. Xuat pt le" };
	chon = control(2, 33, 7, s);
	cout << endl;
	ShowCur(1);
	cout << "\n\n";
	switch (chon)
	{
	case 1:
		xuatCacPTChan(l);
		break;
	case 2:
		xuatCacPTLe(l);
		break;
	}
}

void xuatCacPTVTChan(SList l)
{
	int i = 0;
	Node* p = l.head;
	while (p)
	{
		if (i % 2 == 0)
		{
			cout << "[" << p->info << "]-> ";
		}
		i++;
		p = p->next;
	}
}

void xuatCacPTVTLe(SList l)
{
	int i = 0;
	Node* p = l.head;
	while (p)
	{
		if (i % 2 != 0)
		{
			cout << "[" << p->info << "]-> ";
		}
		i++;
		p = p->next;
	}
}

void _XuatCacPTVTChan_Le(SList l)
{
	int chon = 0;
	ShowCur(0);
	cout << "Vui long chon loai xuat pt DSLK: ";
	const char* s[100] = { "1. Xuat pt vi tri chan","2. Xuat pt vi tri le" };
	chon = control(2, 33, 7, s);
	cout << endl;
	ShowCur(1);
	cout << "\n\n";
	switch (chon)
	{
	case 1:
		xuatCacPTVTChan(l);
		break;
	case 2:
		xuatCacPTVTLe(l);
		break;
	}
}

int countXInSList(SList l, int x)
{
	int dem = 0;
	Node* p = l.head;

	while (p)
	{
		if (p->info == x)
		{
			dem++;
		}
		p = p->next;
	}

	return dem;
}

int timPTMaxSList(SList l)
{
	Node* p = l.head;
	int max = l.head->info;
	while (p)
	{
		if (p->info > max)
		{
			max = p->info;
		}
		p = p->next;
	}
	return max;
}

int timPTMinSList(SList l)
{
	Node* p = l.head;
	int min = l.head->info;
	while (p)
	{
		if (p->info < min)
		{
			min = p->info;
		}
		p = p->next;
	}
	return min;
}

int isEmptyEvenSList(SList l)
{
	Node* p = l.head;
	int check = 0;
	while (p)
	{
		if (p->info % 2 == 0)
		{
			check++;
		}
		p = p->next;
	}
	if (check == 0)
	{
		return 1;
	}
	return 0;
}

int timPTChanMinSList(SList l)
{
	Node* p = l.head;
	int min, dem = 0;
	//Check non-even num
	if (isEmptyEvenSList(l) == 1)
	{
		return -1;
	}
	//Find first even num
	while (p)
	{
		if (p->info % 2 == 0)
		{
			min = p->info;
			break;
		}
		p = p->next;
	}
	//Find min-even num
	while (p)
	{
		if (p->info % 2 == 0)
		{
			if (p->info < min)
			{
				min = p->info;
			}
		}
		p = p->next;
	}
	return min;
}
//Stack 