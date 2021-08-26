//#define _CRT_SECURE_NO_WARNINGS
//#include "stdio.h"
//#include "conio.h"
//#include "string.h"
//
//#define MAX 30
//struct Node
//{
//	char info;
//	Node* next;
//};
//
//struct Stack
//{
//	Node* top;
//};
//
//
//Node* Create_node(int x);
//void Create_stack(Stack& s);
//void Push(Stack& s, Node* p);
//Node* Pop(Stack& s);
//bool isEmpty(Stack s);
//void Print_stack(Stack s);
//void DePrint_stack(Stack s);
//void Input_stack(Stack& s);
//int Priority(char x);
//void Add_last_string(char str[], char a);
//
//
//void main()
//{
//	Stack P, Q;
//	char str[MAX];
//	Node* temp;
//
//	// T?o Stack S,Q,P.
//	Create_stack(P);
//	Create_stack(Q);
//
//	// Nh?p chu?i cho S.
//	printf("Nhap chuoi: ");
//	scanf("%s", &str);
//
//	// Thêm '(' ? ??u str và ')' ? top.
//	//=> ?? lúc nhâp không c?n nh?p 2 d?u ho?c phía ngoài.
//	Add_last_string(str, ')');
//	Push(P, temp = Create_node('('));
//	int i = 0;
//	while (i < strlen(str)) //Dk: ch?a ?i h?t bi?u th?c.
//	{
//		temp = Create_node(str[i]);// T?o m?t node có info = str[i].
//		if (str[i] >= 48 && str[i] <= 57)//Dk: kí t? là s?
//		{
//			Push(Q, temp);// L?y top str[i] qua top P.
//		}
//		else if (str[i] == '(')// Dk: kí t? là d?u '('.
//			Push(P, temp); // L?y str[i] qua P.
//		else if (str[i] == 42 || str[i] == 47 || str[i] == 43 || str[i] == 45)// Dk:kí t? thu?c '+', '-', '*', '/'.
//		{
//			while (Priority(str[i]) <= Priority(P.top->info) && P.top->info != '(') // So sánh ?? ?u tiên c?a toán t? và không l?y tr??ng h?p P.top = '('.
//				Push(Q, Pop(P));// L?y top P qua top Q.
//			Push(P, temp); // Lây top str[i] qua top P.
//		}
//		else if (str[i] == ')')// Dk: kí t? là d?u ')'.
//		{
//			while (P.top->info != '(')// L?y ??n khi g?p d?u '('.
//				Push(Q, Pop(P));
//			Pop(P); // Xóa '(' kh?i P và ko l?y ')' t? chu?i.
//		}
//		else
//		{
//			printf("Co ki tu khong hop le, ngung xu li.");
//			break;
//		}
//		i++;
//	}
//	DePrint_stack(Q);
//	_getch();
//}
//// T?o node.
//Node* Create_node(int x)
//{
//	Node* p = new Node;
//	if (p == NULL)
//	{
//		printf("Khong du bo nho de cap phat.\n");
//		return NULL;
//	}
//	p->info = x;
//	p->next = NULL;
//}
//
////Taao stack.
//void Create_stack(Stack& s)
//{
//	s.top = NULL;
//}
//
////Thêm vào ??u (top).
//void Push(Stack& s, Node* p)
//{
//	if (s.top == NULL)
//		s.top = p;
//	else
//	{
//		p->next = s.top;
//		s.top = p;
//	}
//}
//
////l?y ? ??u.
//Node* Pop(Stack& s)
//{
//	if (s.top != NULL)
//	{
//		Node* p = s.top;
//		s.top = s.top->next;
//		p->next = NULL;
//		return p;
//	}
//}
//
////Ki?m tra r?ng.
//bool isEmpty(Stack s)
//{
//	if (s.top == NULL)
//		return true;
//	return false;
//}
//
////Xu?t stack.
//void Print_stack(Stack s)
//{
//	for (Node* k = s.top; k != NULL; k = k->next)
//	{
//		printf("%c", k->info);
//	}
//}
//
////Xuát Stack ng??c.
//void DePrint_stack(Stack s)
//{
//	Stack temp;
//	Create_stack(temp);
//	while (isEmpty(s) == false)
//	{
//		Push(temp, Pop(s));
//	}
//	Print_stack(temp);
//}
//
//// Nh?p stack.
//void Input_stack(Stack& s)
//{
//	char str[MAX];
//	scanf("%s", &str);
//	for (int i = strlen(str) - 1; i >= 0; i--)
//	{
//		Node* p = Create_node(str[i]);
//		Push(s, p);
//	}
//}
//
//// ?? ?u tiên.
//int Priority(char x)
//{
//	if (x == '(')
//		return 3;
//	else if (x == '*' || x == '/')
//		return 2;
//	else
//		return 1;
//}
//
//// Thêm kí t? vào cu?i chu?i.
//void Add_last_string(char str[], char a)
//{
//	int temp = strlen(str);
//	str[temp] = a;
//	str[temp + 1] = '\0';
//
//}