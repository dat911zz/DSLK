//#include<iostream>
//#include"MyLib.h"
//using namespace std;
//void hide(const char* s, int* a)
//{
//	int x, y, row, col, dem = 0, pos_s = 0, len = 1;
//
//	while (len > 0)
//	{
//		if ('c' == *(s + pos_s))
//		{
//			x = *(a + dem++);
//			pos_s += 2;
//		}
//		else {
//			x = 0;
//			while ('x' != *(s + pos_s))
//				x = x * 10 + *(s + pos_s++) - '0';
//			pos_s++;
//		}
//
//		if ('c' == *(s + pos_s))
//		{
//			y = *(a + dem++);
//			pos_s += 2;
//		}
//		else {
//			y = 0;
//			while ('.' != *(s + pos_s))
//				y = y * 10 + *(s + pos_s++) - '0';
//			pos_s++;
//		}
//
//		//So dong
//		if ('c' == *(s + pos_s))
//		{
//			row = *(a + dem++);
//			pos_s += 2;
//		}
//		else {
//			row = 0;
//			while ('x' != *(s + pos_s))
//				row = row * 10 + *(s + pos_s++) - '0';
//			pos_s++;
//		}
//
//		//So cot
//		if ('c' == *(s + pos_s))
//		{
//			col = *(a + dem++);
//			pos_s += 2;
//		}
//		else {
//			col = 0;
//			while ('\0' != *(s + pos_s))
//			{
//				col = col * 10 + *(s + pos_s++) - '0';
//
//				if ('#' == *(s + pos_s))
//				{
//					len++;
//					break;
//				}
//			}
//			pos_s++;
//		}
//
//		for (; row > 0; row--)
//		{
//			XY(x, y + row - 1);
//			for (int i = col; i > 0; i--)
//				putchar(' ');
//		}
//
//		len--;
//	}
//
//}
//
//int Menu_02()
//{
//	int* abc = new int;
//
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
//		"14.Xuat cac vi tri pt chan/le",
//		"15.A",
//		"16.B",
//		"17.C", 
//		"18.D", 
//		"19.E", };
//	//-----------------Khu vuc duoc chinh sua-----------------//
//	int n = 19;	//So luong control
//	int max_show = 14;	//So luong control trong 1 trang
//	int pick = 1;	//Bien chon : lua chon bat dau tai 1
//	int max_pick = max_show;	//So lua chon duoc hien thi tai trang hien hanh
//	int start;	//Bien bat dau
//	int page = 1;	//Trang : Bat dau o trang 1
//	int max_page = (n - 1) / max_show + 1;	//Gioi han so trang
//	int x = 22, y = 12;
//	//--------------------------------------------------------//
//	/*table2("1x1.4x4.5.15", abc);*/
//	table("1x1.4x1.30.82#1x1.20x10.15.50", abc);
//	BGcolor(14);
//	//--------------------------------------------------------//
//	char c = 'd';	//Control button
//
//	do {
//		start = (page - 1) * max_show;
//		max_pick = (n - start >= max_show) ? max_show : n - start;
//		if (pick > max_pick)
//			pick = max_pick;
//
//		switch (c)
//		{
//		case 75: case 'a': case 77: case 'd':	//Chuyen qua trang tiep theo
//			hide("5x5.25x10", abc);	//An di trang truoc
//			for (int i = 0; i < max_show; i++)
//			{
//				XY(x, y + i);
//				printf("\b                                                 \b");
//			}
//			for (int i = 0; i < max_show && i + start < n; i++)
//			{
//				XY(x, i + y);
//				printf("%s", s[i + start]);
//			}
//
//			if (max_show + start >= n)
//				max_pick = n - start;
//			else
//				max_pick = max_show;
//
//		case 72: case 'w': case 80: case 's':	
//			BGcolor(142);	XY(x, pick + y - 1);	printf("%s", s[pick + start - 1]);
//			BGcolor(14);
//			break;
//		}
//
//
//		c = _getch();
//
//		switch (c)
//		{//72 : len, 80 : xuong, 75 : trai, 77 : phai, 13 : enter, 27 : esc
//		case 75: case 'a':	//Left
//			(page == 1) ? page = max_page : page--;	//Qua trang giam
//			break;
//
//		case 77: case 'd':  //Right
//			(page == max_page) ? page = 1 : page++;	//Qua trang tang
//			break;
//
//		case 72: case 'w':	//Up
//			XY(x, pick + y - 1);	BGcolor(14);
//			printf("%s", s[pick + start - 1]);
//			(pick == 1) ? pick = max_pick : pick--;
//			break;
//
//		case 80: case 's':	//Down
//			XY(x, pick + y - 1);	BGcolor(14);
//			printf("%s", s[pick + start - 1]);
//			(pick == max_pick) ? pick = 1 : pick++;
//			break;
//
//		case 13:			//Enter
//			//-----------------Thao tac output day-----------------//
//			/*XY(0, 0);
//			printf("Lua chon thu %d ne", pick + start);*/
//			return pick + start;
//			break;
//		}
//
//	} while (c != 27);//Khac Nut ESC
//
//}