#pragma once
#include<windows.h>
#include<conio.h>
using namespace std;
//==========
void khung2(const char* s, int* a);						//Tao khung 1 gach
void khung(const char* s, int* a);						//Tao khung 2 gach
void table2(const char* s, int* a);						//Tao bang 1 gach
void table(const char* s, int* a);						//Tao bang 2 gach
void XY(short x, short y);								//(x, y)
void BGcolor(int code);
int control(int num_control, int x, int y, char* s[]);
void hide(const char* s, int* a);
void SetWindowSize(SHORT width, SHORT height);
void SetScreenBufferSize(SHORT width, SHORT height);
void TestBGColor();
void WindowsCustomize();
void DisableResizeWindow();
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);
void ShowCur(bool CursorVisibility);
void Ruler();
//int menu();
//==========

void hide(const char* s, int* a)
{
	int x, y, row, col, dem = 0, pos_s = 0, len = 1;

	while (len > 0)
	{
		if ('c' == *(s + pos_s))
		{
			x = *(a + dem++);
			pos_s += 2;
		}
		else {
			x = 0;
			while ('x' != *(s + pos_s))
				x = x * 10 + *(s + pos_s++) - '0';
			pos_s++;
		}

		if ('c' == *(s + pos_s))
		{
			y = *(a + dem++);
			pos_s += 2;
		}
		else {
			y = 0;
			while ('.' != *(s + pos_s))
				y = y * 10 + *(s + pos_s++) - '0';
			pos_s++;
		}

		//So dong
		if ('c' == *(s + pos_s))
		{
			row = *(a + dem++);
			pos_s += 2;
		}
		else {
			row = 0;
			while ('x' != *(s + pos_s))
				row = row * 10 + *(s + pos_s++) - '0';
			pos_s++;
		}

		//So cot
		if ('c' == *(s + pos_s))
		{
			col = *(a + dem++);
			pos_s += 2;
		}
		else {
			col = 0;
			while ('\0' != *(s + pos_s))
			{
				col = col * 10 + *(s + pos_s++) - '0';

				if ('#' == *(s + pos_s))
				{
					len++;
					break;
				}
			}
			pos_s++;
		}

		for (; row > 0; row--)
		{
			XY(x, y + row - 1);
			for (int i = col; i > 0; i--)
				putchar(' ');
		}

		len--;
	}

}
void hienSoTrang(int page, int max_page)
{
	XY(39, 25); cout << "Trang: " << page << " / " << max_page;
}

int menu_02()
{
	int* abc = new int;

	const char* s[100] = { 
		"1. Nhap Xuat DSLK don",
		"2. Tim node trong DSLK don",
		"3. Them node vao dau DSLK don",
		"4. Them node vao cuoi DSLK don",
		"5. Them node p vao sau node q DSLK don",
		"6. Xoa node dau DSLK don",
		"7. Xoa node cuoi DSLK don",
		"8. Xoa node sau node q DSLK don",
		"9. Sap xep DSLK don tang theo gt InterchangeSort",
		"10.Sap xep DSLK don giam theo gt InterchangeSort",
		"11.So luong node trong DSLK don",
		"12.Tinh Tong cac node",
		"13.Xuat cac pt chan/le",
		"14.Xuat cac vi tri pt chan/le",
		"15.Dem phan tu X trong DSLK don",
		"16.Tim phan tu Max/Min trong DSLK don",
		"17.Tim phan tu chan nho nhat DSLK",
		"18.Tim phan tu le lon nhat DSLK",
		"19.Tim phan tu chan lon nhat DSLK",
		"20.Tim phan tu le nho nhat DSLK",
		"21.Xoa phan tu Max/Min DSLK",
		"22.Them phan tu lam sao cho phan tu do cuc dai",
		"23.Kiem tra DSLK Tang/Giam",
		"24.<In progress>",
		"25.Nhap Xuat Stack",
		"26.Kiem tra top Stack",
		"27.Them node top Stack",
		"28.",
		"29.", 
		"30."};
	
	//-----------------Khu vuc chinh sua tuy chon-----------------//
	int n = 30;	//So luong control
	int max_show = 14;	//So luong control trong 1 trang
	int pick = 1;	//Bien chon : lua chon bat dau tai 1
	int max_pick = max_show;	//So lua chon duoc hien thi tai trang hien hanh
	int start;	//Bien bat dau
	int page = 1;	//Trang : Bat dau o trang 1
	int max_page = (n - 1) / max_show + 1;	//Gioi han so trang
	int x = 22, y = 11;
	//-----------------------------------------------------------//
	/*table2("1x1.4x4.5.15", abc);*/
	WindowsCustomize();
	//Ruler();
	BGcolor(15);
	table("1x1.4x1.30.82#1x1.20x10.15.50", abc);
	BGcolor(14);
	XY(8, 30);
	cout << "[ESC]:EXIT";
	//--------------------------------------------------------//
	char c = 'd';	//Control button

	do {
		start = (page - 1) * max_show;
		max_pick = (n - start >= max_show) ? max_show : n - start;
		if (pick > max_pick)
			pick = max_pick;

		switch (c)
		{
		case 75: case 'a': case 77: case 'd':	//Chuyen qua trang tiep theo
			hide("5x5.25x10", abc);	//An di trang truoc
			for (int i = 0; i < max_show; i++)
			{
				XY(x, y + i);
				printf("\b                                                 \b");
			}
			for (int i = 0; i < max_show && i + start < n; i++)
			{
				XY(x, i + y);
				printf("%s", s[i + start]);
			}
			hienSoTrang(page, max_page);
			if (max_show + start >= n)
				max_pick = n - start;
			else
				max_pick = max_show;

		case 72: case 'w': case 80: case 's':
			BGcolor(142);	XY(x, pick + y - 1);	printf("%s", s[pick + start - 1]);
			BGcolor(14);
			break;
		}


		c = _getch();

		switch (c)
		{//72 : len, 80 : xuong, 75 : trai, 77 : phai, 13 : enter, 27 : esc
		case 75: case 'a':	//Left
			(page == 1) ? page = max_page : page--;	//Qua trang giam
			hienSoTrang(page, max_page);
			break;

		case 77: case 'd':  //Right
			(page == max_page) ? page = 1 : page++;	//Qua trang tang
			hienSoTrang(page, max_page);
			break;

		case 72: case 'w':	//Up
			XY(x, pick + y - 1);	BGcolor(14);
			printf("%s", s[pick + start - 1]);
			(pick == 1) ? pick = max_pick : pick--;
			break;

		case 80: case 's':	//Down
			XY(x, pick + y - 1);	BGcolor(14);
			printf("%s", s[pick + start - 1]);
			(pick == max_pick) ? pick = 1 : pick++;
			break;

		case 13:			//Enter
			//-----------------Thao tac output day-----------------//
			/*XY(0, 0);
			printf("Lua chon thu %d ne", pick + start);*/
			return pick + start;
			break;
		}

	} while (c != 27);//Khac Nut ESC

	delete abc;
}

int control(int num_control, int x, int y, const char* s[])
{//72 : len, 80 : xuong, 75 : trai, 77 : phai, 13 : enter, 27 : esc
	//In ra 14 lua chon dau tien 
	for (int i = 1; i < num_control; i++)

	{
		XY(x, y + i);
		printf("%s", s[i]);
	}
	int pick = 1;
	char c;
	bool check = true;
	do {
		XY(x, y + pick - 1);	BGcolor(142);	printf("%s", s[pick - 1]);
		c = _getch();
		XY(x, y + pick - 1);	BGcolor(14);	printf("%s", s[pick - 1]);
		switch (c)
		{
		case 80: case 's':	(pick == num_control) ? pick = 1 : pick++;	break;
		case 72: case 'w':	(pick == 1) ? pick = num_control : pick--;	break;
		case 27:	pick = 0;	check = false;	break;
		case 13:	check = false;				break;
		case 77: case 'd':
			for (int i = 0; i < num_control; i++)
			{
				XY(x, y + i);
				Sleep(100);
				printf("\b                                                 \b");
			}
		case 75: case 'a':	XY(x, y); cout << "\b \b";
		}
	} while (check);
	return pick;
}

void BGcolor(int code)
{
	static HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}

void table(const char* s, int* a)
{
	char p[50];
	int lenp, pos_s = 0;
	int* b, dem = 0, pos = 0, len = 1;
	while (len > 0)
	{
		pos += dem;
		lenp = -1;
		do {
			lenp++;
			switch (*(s + pos_s))
			{
			case '\0':	p[lenp] = '\0';					break;
			case '#':	p[lenp] = '\0';			len++;	break;
			case 'c':	p[lenp] = *(s + pos_s);	dem++;	break;
			default:	p[lenp] = *(s + pos_s);
			}
			pos_s++;
		} while (p[lenp] != '\0');
		len--;
		b = a + pos;
		khung(p, b);
	}
}

void table2(const char* s, int* a)
{
	char p[50];
	int lenp, pos_s = 0;

	int* b, dem = 0, pos = 0, len = 1;

	while (len > 0)
	{
		pos += dem;

		lenp = -1;
		do {
			lenp++;
			switch (*(s + pos_s))
			{
			case '\0':	p[lenp] = '\0';					break;
			case '#':	p[lenp] = '\0';			len++;	break;
			case 'c':	p[lenp] = *(s + pos_s);	dem++;	break;
			default:	p[lenp] = *(s + pos_s);
			}
			pos_s++;
		} while (p[lenp] != '\0');
		len--;
		b = a + pos;
		khung2(p, b);
	}
}

void khung(const char* s, int* a)
{
	int dong, cot, x, y, k = 0, dem = 0, * b;

	if (*(s + k) == 'c')
	{
		dong = *(a + dem++);
		k += 2;
	}
	else {
		dong = 0;
		do {
			dong = dong * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != 'x');
		k++;
	}

	if (*(s + k) == 'c')
	{
		cot = *(a + dem++);
		k += 2;
	}
	else {
		cot = 0;
		do {
			cot = cot * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != '.');
		k++;
	}

	if (*(s + k) == 'c')
	{
		x = *(a + dem++);
		k += 2;
	}
	else {
		x = 0;
		do {
			x = x * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != 'x');
		k++;
	}

	if (*(s + k) == 'c')
	{
		y = *(a + dem++);
		k += 2;
	}
	else {
		y = 0;
		do {
			y = y * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != '.');
		k++;
	}

	int len = dong + cot;
	b = (int*)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++)
	{
		if (*(s + k) == 'c')
		{
			*(b + i) = *(a + dem++);
			k += 2;
			continue;
		}
		else
			*(b + i) = 0;

		do {
			*(b + i) = *(b + i) * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != '.' && *(s + k) != '\0');
		k++;
	}

	//Hang doc
	int pointx = x, pointy;
	for (int i = 0; i <= cot; i++)
	{
		if (i != 0)
			pointx += *(b + dong + i - 1) + 1;
		pointy = y + 1;
		for (int j = 0; j < dong; j++)
		{
			for (k = 0; k < *(b + j); k++)
			{
				XY(pointx, pointy + k);
				printf("%c", 186);
			}
			pointy += *(b + j) + 1;
		}
	}
	pointy = y;
	//Hang ngang
	for (int i = 0; i <= dong; i++)
	{
		if (i != 0)
			pointy += *(b + i - 1) + 1;
		pointx = x + 1;
		for (int j = 0; j < cot; j++)
		{
			XY(pointx, pointy);
			for (k = 0; k < *(b + dong + j); k++)
				printf("%c", 205);
			pointx += *(b + dong + j) + 1;
		}
	}
	//Cac goc
	pointy = y;
	for (int i = 0; i <= dong; i++)
	{
		pointx = x;
		for (int j = 0; j <= cot; j++)
		{
			XY(pointx, pointy);

			if (j == 0)
			{
				if (i == 0)
					printf("%c", 201);
				if (i == dong)
					printf("%c", 200);
				if (i > 0 && i < dong)
					printf("%c", 204);
			}

			if (j == cot)
			{
				if (i == 0)
					printf("%c", 187);
				if (i == dong)
					printf("%c", 188);
				if (i > 0 && i < dong)
					printf("%c", 185);
			}

			if (j > 0 && j < cot)
			{
				if (i == 0)
					printf("%c", 203);
				if (i == dong)
					printf("%c", 202);
				if (i > 0 && i < dong)
					printf("%c", 206);
			}
			pointx += *(b + dong + j) + 1;
		}
		pointy += *(b + i) + 1;
	}
}

void khung2(const char* s, int* a)
{
	int dong, cot, x, y, k = 0, dem = 0, * b;

	if (*(s + k) == 'c')
	{
		dong = *(a + dem++);
		k += 2;
	}
	else {
		dong = 0;
		do {
			dong = dong * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != 'x');
		k++;
	}

	if (*(s + k) == 'c')
	{
		cot = *(a + dem++);
		k += 2;
	}
	else {
		cot = 0;
		do {
			cot = cot * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != '.');
		k++;
	}

	if (*(s + k) == 'c')
	{
		x = *(a + dem++);
		k += 2;
	}
	else {
		x = 0;
		do {
			x = x * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != 'x');
		k++;
	}

	if (*(s + k) == 'c')
	{
		y = *(a + dem++);
		k += 2;
	}
	else {
		y = 0;
		do {
			y = y * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != '.');
		k++;
	}

	int len = dong + cot;
	b = (int*)malloc(len * sizeof(int));

	for (int i = 0; i < len; i++)
	{
		if (*(s + k) == 'c')
		{
			*(b + i) = *(a + dem++);
			k += 2;
			continue;
		}
		else
			*(b + i) = 0;

		do {
			*(b + i) = *(b + i) * 10 + *(s + k) - '0';
			k++;
		} while (*(s + k) != '.' && *(s + k) != '\0');
		k++;
	}

	//Hang doc
	int pointx = x, pointy;
	for (int i = 0; i <= cot; i++)
	{
		if (i != 0)
			pointx += *(b + dong + i - 1) + 1;
		pointy = y + 1;
		for (int j = 0; j < dong; j++)
		{
			for (k = 0; k < *(b + j); k++)
			{
				XY(pointx, pointy + k);
				printf("%c", 179);
			}
			pointy += *(b + j) + 1;
		}
	}
	pointy = y;
	//Hang ngang
	for (int i = 0; i <= dong; i++)
	{
		if (i != 0)
			pointy += *(b + i - 1) + 1;
		pointx = x + 1;
		for (int j = 0; j < cot; j++)
		{
			XY(pointx, pointy);
			for (k = 0; k < *(b + dong + j); k++)
				printf("%c", 196);
			pointx += *(b + dong + j) + 1;
		}
	}
	//Cac goc
	pointy = y;
	for (int i = 0; i <= dong; i++)
	{
		pointx = x;
		for (int j = 0; j <= cot; j++)
		{
			XY(pointx, pointy);

			if (j == 0)
			{
				if (i == 0)
					printf("%c", 218);
				if (i == dong)
					printf("%c", 192);
				if (i > 0 && i < dong)
					printf("%c", 195);
			}

			if (j == cot)
			{
				if (i == 0)
					printf("%c", 191);
				if (i == dong)
					printf("%c", 217);
				if (i > 0 && i < dong)
					printf("%c", 180);
			}

			if (j > 0 && j < cot)
			{
				if (i == 0)
					printf("%c", 194);
				if (i == dong)
					printf("%c", 193);
				if (i > 0 && i < dong)
					printf("%c", 197);
			}
			pointx += *(b + dong + j) + 1;
		}
		pointy += *(b + i) + 1;
	}
}

void XY(short x, short y)
{
	static HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void SetWindowSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SMALL_RECT WindowSize;
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;

	SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD NewSize;
	NewSize.X = width;
	NewSize.Y = height;

	SetConsoleScreenBufferSize(hStdout, NewSize);
}

void TestBGColor()
{
	for (int i = 0; i < 256; i++)
	{
		BGcolor(i);
		cout << "||||||=====   ." << i << endl;
	}
}

void DisableResizeWindow()
{
	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void WindowsCustomize()
{
	DisableResizeWindow();
	SetWindowSize(90, 37);
	SetScreenBufferSize(90, 37);
	SetConsoleTitle(L"Beta Program");
	ShowCur(0);
}

void Ruler()
{
	int i = 0, j = 0;
	XY(0, 0);
	while (j <= 8)
	{
		cout << i++;
		if (i == 10)
		{
			i = 0;
			j++;
		}
	}
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		// The function failed. Call GetLastError() for details.
		COORD invalid = { 0, 0 };
		return invalid;
	}
}
void loading()
{

	char x = 176, z = 32;
	int y = 2;
	ShowCur(0);
	XY(1, 1);
	BGcolor(14);
	cout << "<!>Processing...";
	BGcolor(15);
	XY(1, 2);
	cout << "[";
	XY(27, 2);
	cout << "]";
	XY(2, 2);
	for (int i = 0; i < 25; i++)
	{
		cout << x;
	}
	x += 2;
	XY(2, 2);
	for (int i = 1; i <= 25; i++)
	{
		//Loading nums
		BGcolor(14);
		XY(17, 1);
		cout << i * 4 << "%";
		//Loading
		BGcolor(15);
		XY(y++, 2);
		cout << x;
		Sleep(50);
	}
	XY(0, 0);
	cout << z;
	XY(1, 1);
	system("color 0a");
	cout << "<!>Open file sucessfully!";
	XY(0, 3);
	BGcolor(14);
	cout << "  Redirect in 3 seconds";
	Sleep(1000);
	XY(23, 3);
	cout << ".";
	Sleep(1000);
	XY(25, 3);
	cout << ".";
	Sleep(1000);
	XY(27, 3);
	cout << "." << endl;
}
//int menu()
//{
//	int* a = new int;
//	const char* s[100] = { "1. Nhap Xuat DSLK don",
//		"2. Tim node trong DSLK don",
//		"3. Them node vao dau DSLK don",
//		"4. Them node vao cuoi DSLK don",
//		"5. Them node p vao sau node q DSLK don",
//		"6. Xoa node dau DSLK don",
//		"7. Xoa node cuoi DSLK don",
//		"8. Xoa node sau node q DSLK don",
//		"9. Sap xep DSLK don tang theo gt InterchangeSort",
//		"10.Sap xep DSLK don giam theo gt InterchangeSort",
//		"11.So luong node trong DSLK don",
//		"12.Tinh Tong cac node",
//		"13.Xuat cac pt chan/le",
//		"14.Xuat cac vi tri pt chan/le" };
//	WindowsCustomize();
//	Ruler();
//	BGcolor(15);
//	table("1x1.4x1.30.82#1x1.20x10.15.50", a);
//	BGcolor(14);
//	XY(8, 30);
//	cout << "[ESC]:EXIT";
//	return control(14, 22, 12, s);
//	XY(1, 32);
//	delete a;
//}
