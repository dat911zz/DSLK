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
int isEmptyEvenSList(SList l);
int isEmptyOddSList(SList l);
int timPTChanMinSList(SList l);
int timPTLeMaxSList(SList l);
int timPTChanMaxSlist(SList l);
int timPTLeMinSList(SList l);
void xoaPTMaxDSLK(SList& l, int n);
void xoaPTMinDSLK(SList& l, int n);
void _XoaCacPTMax_Min(SList l, int n);
void themPTXCucDai(SList& l);
int isAscendingSList(SList l);
int isDescendingSList(SList l);
void _KiemTraDSLKTang_Giam(SList& l, int& n);
//Stack
void createStack_Random(Stack& s, int& n);
void showStack(Stack& s);
void _nhapXuatStack(Stack& s, int& n);
void checkTopStack(Stack s);
void _ThemVaoDinh(Stack& s);
int checkPriority(char x);
void convertInfixToPostfix(Stack& s, char* P, char* Q);
int calc(char op, int x, int y);
int calculateInfix(Stack s, char* Q);
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
	Stack s;
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
		SetScreenBufferSize(90, 90);
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
		case 18:
			_nhapXuatDSLK(l, n);
			cout << "\nPhan tu le lon nhat trong DSLK: " << timPTLeMaxSList(l);
			break;
		case 19:
			_nhapXuatDSLK(l, n);
			cout << "\nPhan tu chan lon nhat trong DSLK: " << timPTChanMaxSlist(l);
			break;
		case 20:
			_nhapXuatDSLK(l, n);
			cout << "\nPhan tu le nho nhat trong DSLK: " << timPTLeMinSList(l);
			break;
		case 21:
			_nhapXuatDSLK(l, n);
			_XoaCacPTMax_Min(l, n);
			showSList(l);
			break;
		case 22:
			_nhapXuatDSLK(l, n);
			themPTXCucDai(l);
			showSList(l);
			break;
		case 23:
			_KiemTraDSLKTang_Giam(l, n);
			break;
		case 24:
			break;
		case 25:
			_nhapXuatStack(s, n);
			break;
		case 26:
			_nhapXuatStack(s, n);
			cout << "Top of Stack: ";
			checkTopStack(s);
			break;
		case 27:
			char chon_1;
			_nhapXuatStack(s, n);
			do
			{
				_ThemVaoDinh(s);
				showStack(s);
				cout << "\nBan co muon them tiep ? Y/N - ";
				cin >> chon_1;
			} while (chon_1 == 'Y' || chon_1 == 'y');
			
			break;
		case 28:
			char P[100], Q[100];
			cout << "Nhap bieu thuc trung to: ";
			cin >> P;
			convertInfixToPostfix(s, P, Q);
			cout << "\nBieu thuc hau to: " << Q << endl;
			break;
		case 29:
			cout << "Nhap bieu thuc trung to: ";
			cin >> P;
			convertInfixToPostfix(s, P, Q);
			cout << "\nBieu thuc hau to: " << Q << endl;
			cout << "Ket qua: " << calculateInfix(s, Q);
			break;
		default:
			system("cls");
			XY(30, 2);
			cout << "Thanks for your patient!" << endl;
			break;
		}
		cout << endl;
		system("pause");
	} while (chon > 0 && chon < 30);
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
	if (n < 0)
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
		if (p == l.tail)
		{
			deleteTailSList(l);
		}
		else
		{
			if (p == l.head)
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

int isEmptyOddSList(SList l)
{
	Node* p = l.head;
	int check = 0;
	while (p)
	{
		if (p->info % 2 != 0)
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
	//Check List
	if (p == NULL || isEmptyEvenSList(l) == 1)
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
	//Find min even num
	while (p)
	{
		if (p->info % 2 == 0 && p->info < min)
		{
			min = p->info;
		}
		p = p->next;
	}
	return min;
}

int timPTLeMaxSList(SList l)
{
	int max;
	Node* p = l.head;
	//Check
	if (p == NULL || isEmptyOddSList(l) == 1)
	{
		return 0;
	}

	//Find first odd num
	while (p)
	{
		if (p->info % 2 != 0)
		{
			max = p->info;
			break;
		}
		p = p->next;
	}
	//Find max odd num
	while (p)
	{
		if (p->info % 2 != 0 && p->info > max)
		{
			max = p->info;
		}
		p = p->next;
	}
	return max;
}

int timPTChanMaxSlist(SList l)
{
	int max;
	Node* p = l.head;
	if (p == NULL || isEmptyEvenSList(l) == 1)
	{
		return -1;
	}
	while (p)
	{
		if (p->info % 2 == 0)
		{
			max = p->info;
			break;
		}
		p = p->next;
	}
	while (p)
	{
		if (p->info % 2  == 0 && p->info > max)
		{
			max = p->info;
		}
		p = p->next;
	}
	return max;
}

int timPTLeMinSList(SList l)
{
	int min;
	Node* p = l.head;
	if (p == NULL || isEmptyOddSList(l) == 1)
	{
		return 0;
	}
	while (p)
	{
		if (p->info % 2 != 0)
		{
			min = p->info;
			break;
		}
		p = p->next;
	}
	while (p)
	{
		if (p->info % 2 != 0 || p->info < min)
		{
			min = p->info;
		}
		p = p->next;
	}
	return min;
}

void xoaPTMaxDSLK(SList& l, int n)
{
	Node* q, * p;
	int x = timPTMaxSList(l);
	cout << "Phan tu Max: " << x;
	
	while (l.head->info == x)
	{
		deleteHeadSList(l);
		if (l.head == NULL)
		{
			return;
		}
	}
	
	while (l.tail->info == x)
	{
		deleteTailSList(l);
		if (l.tail == NULL)
		{
			return;
		}
	}
	
	q = l.head;
	while (q)
	{
		if (q->next == NULL)
		{
			break;
		}
		while (q->next->info == x)
		{
			p = q->next; //Node can xoa
			deleteAfterNodeSList(l, q, p);
		}
		q = q->next;
	}
}

void xoaPTMinDSLK(SList& l, int n)
{
	Node* q, * p;
	int x = timPTMinSList(l);
	cout << "Phan tu Min: " << x;
	while (l.head->info == x)
	{
		deleteHeadSList(l);
		if (l.head == NULL)
		{
			return;
		}
	}
	while (l.tail->info == x)
	{
		deleteTailSList(l);
		if (l.tail == NULL)
		{
			return;
		}
	}
	q = l.head;
	while (q)
	{
		if (q->next == NULL)
		{
			return;
		}
		if (q->next->info == x)
		{
			p = q->next;
			deleteAfterNodeSList(l, q, p);
		}
		q = q->next;
	}
}
void _XoaCacPTMax_Min(SList l, int n)
{
	int chon = 0;
	ShowCur(0);
	cout << "Vui long chon: ";
	const char* s[100] = { "1. Xoa PT Max","2. Xoa PT Min" };
	chon = control(2, 33, 7, s);
	cout << endl;
	ShowCur(1);
	cout << "\n\n";
	switch (chon)
	{
	case 1:
		xoaPTMaxDSLK(l, n);
		break;
	case 2:
		xoaPTMinDSLK(l, n);
		break;
	}
}

void themPTXCucDai(SList& l)
{
	int x;
	Node* q, * p;
	nhapx(x);
	q = l.head;
	while (q)
	{
		if (q->next == NULL)
		{
			return;
		}
		if (q->info < x && q->next->info < x)
		{
			p = createNode(x);
			addAfterNodeSList(l, q, p);
		}
		q = q->next;
	}
}

int isAscendingSList(SList l)
{
	Node* p = l.head;
	if (isEmptyList(l) == NULL)
	{
		return 0;
	}

	while (p)
	{
		if (p->info > p->next->info)
		{
			return 0;
		}
		p = p->next;
	}

	return 1;
}
int isDescendingSList(SList l)
{
	Node* p = l.head;
	if (isEmptyList(l) == NULL)
	{
		return 0;
	}

	while (p)
	{
		if (p->info < p->next->info)
		{
			return 0;
		}
		p = p->next;
	}

	return 1;
}
void _KiemTraDSLKTang_Giam(SList& l, int &n)
{
	int chon = 0;
	_nhapXuatDSLK(l, n);
	ShowCur(0);
	cout << "Vui long chon: ";
	const char* s[100] = { "1. Kiem tra DSLK tang","2. Kiem tra DSLK giam" };
	chon = control(2, 33, 7, s);
	cout << endl;
	ShowCur(1);
	cout << "\n\n";
	switch (chon)
	{
	case 1:	
		if (isAscendingSList(l) == 1)
		{
			cout << "\nTRUE" << endl;
		}
		else
		{
			cout << "\nFALSE" << endl;
		}
		break;
	case 2:
		if (isDescendingSList(l) == 1)
		{
			cout << "\nTRUE" << endl;
		}
		else
		{
			cout << "\nFALSE" << endl;
		}
		break;
	}
}
//================
//Stack 
Node* pushS(Stack& s, Node* p)
{
	if (p)
	{
		if (!s.top)
		{
			s.top = p;
		}
		else
		{
			p->next = s.top;
			s.top = p;
		}
	}
	return p;
}

Node* popS(Stack& s)
{
	Node* p = NULL;
	if (s.top)
	{
		p = s.top;
		s.top = s.top->next;
		p->next = NULL;
	}
	return p;
}

void initStack(Stack& s)
{
	s.top = NULL;
}

bool isEmptyStack(Stack s)
{
	return s.top == NULL;
}

void createStack_Random(Stack& s,int &n)
{
	int x;
	Node* q;
	cout << "Nhap n: ";
	cin >> n;
	initStack(s);
	for (int i = 0; i < n; i++)
	{
		x = rand() % 100;
		q = createNode(x);
		checkMemory(q);
		if (isEmptyStack(s) == 1)
		{
			s.top = q;
		}
		else
		{
			pushS(s, q);
		}
	}
}

void showStack(Stack& s)
{
	Node* p = s.top;
	cout << "\n\n\t-Stack-" << endl;
	if (!p)
	{
		cout << "\t<Empty!>" << endl;
	}
	while (p)
	{
		if (p == s.top)
		{
			cout << "-> " << p->info << "|";
		}
		else
		{
			if (!p->next)
			{
				cout << p->info << "]";
			}
			else
			{
				cout << p->info << "|";
			}
		}
		p = p->next;
	}
}

void _nhapXuatStack(Stack& s, int &n)
{
	createStack_Random(s, n);
	showStack(s);
	cout << endl;
}

void checkTopStack(Stack s)
{
	if (isEmptyStack(s) == 1)
	{
		cout << "<Empty>";
	}
	else
	{
		cout << s.top->info;
	}
}

void _ThemVaoDinh(Stack& s)
{
	int x;
	Node* p;
	nhapx(x);
	p = createNode(x);
	pushS(s, p);
}

int checkPriority(char x)
{
	if (x == '^')
	{
		return 3;
	}
	if (x == '*' || x == '/')
	{
		return 2;
	}
	return 1;
}
void convertInfixToPostfix(Stack& s, char* P, char* Q)//((6+4)/2+7)/3-(1+2)*2)
{
	Node* p;
	char tmp;
	int j = 0;
	initStack(s);
	pushS(s, createNode('('));
	for (int i = 0; i < strlen(P); i++)
	{
		p = createNode(P[i]);
		if (P[i] >= '0' && P[i] <= '9')
		{
			Q[j++] = P[i];
		}
		else
		{
			if (P[i] == '(')
			{
				pushS(s, p);
			}
			else
			{
				if (P[i] == '^' || P[i] == '*' || P[i] == '/' || P[i] == '+' || P[i] == '-')
				{
					while (checkPriority(P[i]) <= checkPriority(s.top->info) && s.top->info != '(')
					{
						Q[j++] = popS(s)->info;
					}
					pushS(s, p);
				}
				else
				{
					if (P[i] == ')')
					{
						while (s.top->info != '(')
						{
							Q[j++] = popS(s)->info;;
						}
						popS(s);
					}
				}
			}
		}
	}
	Q[j] = '\0';
}
int calc(char op, int x, int y)
{
	switch (op)
	{
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	}
}
int calculateInfix(Stack s, char* Q)
{
	Node* p;
	int x, y, result;
	initStack(s);
	for (int i = 0; i < strlen(Q); i++)
	{
		p = createNode(Q[i] - 48);
		if (Q[i] >= '0' && Q[i] <= '9')
		{
			pushS(s, p);
		}
		else
		{
			if (Q[i] == '^' || Q[i] == '*' || Q[i] == '/' || Q[i] == '+' || Q[i] == '-')
			{
				x = popS(s)->info;
				y = popS(s)->info;
				result = calc(Q[i], y, x);
				pushS(s, p = createNode(result));
			}
		}
	}
	return popS(s)->info;
}