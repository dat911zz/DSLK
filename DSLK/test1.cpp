//#include<iostream>
//#include"MyLib.h"
//using namespace std;
//typedef char Data;
////Struct and Constant
//struct Node
//{
//	Data info;
//	Node* next; //Tro den Node tiep theo
//};
//struct SList
//{
//	Node* head;
//	Node* tail;
//};
//struct Stack
//{
//	Node* top;
//};
////Prototype
//void showStack(Stack& s);
//void checkTopStack(Stack s);
//void initStack(Stack& s);
//Node* createNode(Data x);
//Node* pushS(Stack& s, Node* p);
//Node* popS(Stack& s);
//void convertInfixToPostfix(Stack& s, char* P, char* Q);
////Main
//void main()
//{
//	int n;
//	Stack s;
//	char P[100], Q[100];
//	system("color 0a");
//	cout << "Nhap bieu thuc trung to: ";
//	cin >> P;
//	convertInfixToPostfix(s, P, Q);
//	cout << "\nBieu thuc hau to: " << Q << endl;
//	system("pause");
//}
////Functions
//void showStack(Stack& s)
//{
//	Node* p = s.top;
//	cout << "\n\n\t-Stack-" << endl;
//	if (!p)
//	{
//		cout << "\t<Empty!>" << endl;
//	}
//	while (p)
//	{
//		if (p == s.top)
//		{
//			cout << "-> " << p->info << "|";
//		}
//		else
//		{
//			if (!p->next)
//			{
//				cout << p->info << "]";
//			}
//			else
//			{
//				cout << p->info << "|";
//			}
//		}
//		p = p->next;
//	}
//}
//void checkTopStack(Stack s)
//{
//	if (s.top == NULL)
//	{
//		cout << "<Empty>";
//	}
//	else
//	{
//		cout << s.top->info;
//	}
//}
//void initStack(Stack& s)
//{
//	s.top = NULL;
//}
//Node* pushS(Stack& s, Node* p)
//{
//	if (p)
//	{
//		if (!s.top)
//		{
//			s.top = p;
//		}
//		else
//		{
//			p->next = s.top;
//			s.top = p;
//		}
//	}
//	return p;
//}
//Node* createNode(Data x)
//{
//	Node* p = new Node;
//	if (!p)
//	{
//		cout << "Not enough memory!" << endl;
//		return NULL;
//	}
//	p->info = x;
//	p->next = NULL;
//	return p;
//}
//Node* popS(Stack& s)
//{
//	Node* p = NULL;
//	if (s.top)
//	{
//		p = s.top;
//		s.top = s.top->next;
//		p->next = NULL;
//	}
//	return p;
//}
//int checkPriority(char x)
//{
//	if (x == '^')
//	{
//		return 3;
//	}
//	if (x == '*' || x == '/')
//	{
//		return 2;
//	}
//	return 1;
//}
//void convertInfixToPostfix(Stack& s, char* P, char* Q)//((6+4)/2+7)/3-(1+2)*2)
//{
//	Node* p;
//	char tmp;
//	int j = 0;
//	initStack(s);
//	pushS(s, createNode('('));
//	for (int i = 0; i < strlen(P); i++)
//	{
//		p = createNode(P[i]);
//		if (P[i] >= '0' && P[i] <= '9')
//		{
//			Q[j++] = P[i];
//		}
//		else
//		{
//			if (P[i] == '(')
//			{
//				pushS(s, p);
//			}
//			else
//			{
//				if (P[i] == '^' || P[i] == '*' || P[i] == '/' || P[i] == '+' || P[i] == '-')
//				{
//					while (checkPriority(P[i]) <= checkPriority(s.top->info) && s.top->info != '(')
//					{
//						Q[j++] = popS(s)->info;
//					}
//					pushS(s, p);
//				}
//				else
//				{
//					if (P[i] == ')')
//					{
//						while (s.top->info != '(')
//						{
//							Q[j++] = popS(s)->info;;
//						}
//						popS(s);
//					}
//				}
//			}
//		}
//	}
//	Q[j] = '\0';
//}