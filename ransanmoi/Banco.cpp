#include "pch.h"
#include "Banco.h"

Banco::Banco()
{
	dk = 0;
	huong = 38;
	diem = 0;
	thang = 0;
	level = 1;
	dv = Hcn(XDAU+60, YDAU+60 , XDAU + RONG * 3, YDAU + RONG + 180);
	ran = Ran(XDAU + 10 * D, YDAU + 10 * D);
	moi = Moi(XDAU + 5 * D, YDAU + 10 * D, XDAU + 6 * D, YDAU + 11 * D);
	food = moibonus(XDAU + 7 * D, YDAU + 11 * D, XDAU + 8 * D, YDAU + 12 * D);
	
	
}

void Banco::draw(CClientDC* pDC)
{     
    
	CString strdiem;
	CString strlv;
	strlv.Format(_T("Level: %d"), level);
	strdiem.Format(_T("Diem: %d   "), diem);
	// Tăng kích thước văn bản
	CFont font, font1;
	font.CreatePointFont(200, _T("Arial"));  // Thay đổi thành kích thước mong muốn
	CFont* pOldFont = pDC->SelectObject(&font);

	font1.CreatePointFont(200, _T("Arial"));  
	CFont* pOldFont1 = pDC->SelectObject(&font1);

	pDC->SetTextColor(RGB(255, 0, 0));
	// Vẽ văn bản với kích thước và chế độ nền mới
	pDC->TextOutW(XDAU + 60, YDAU / 2, strdiem);
	pDC->TextOutW(XDAU + 300, YDAU / 2, strlv);
	pDC->SetTextColor(pDC->GetTextColor());
	pDC->SetTextColor(pDC->GetTextColor());

	
	dv.draw(pDC);
	ran.draw(pDC);
	moi.draw(pDC);

	
	
	if (diem % 5 == 0)
	{
		
		food.draw(pDC);
	}
	if (diem >= 10)
	{
		CString game;
		game.Format(_T("YOU WIN! "));
		pDC->TextOutW(XDAU + 10 * D, YDAU + 10 * D, game);


		CString strdiem;
		strdiem.Format(_T("Diem: %d   "), diem);
		pDC->TextOutW(XDAU + 20 * D, YDAU + 10 * D, strdiem);
	}
	else if (thang == 1)
	{
		CString endgame;
		endgame.Format(_T("GAME OVER! "));
		pDC->TextOutW(XDAU + 10*D, YDAU +10*D, endgame);


		CString strdiem;
		strdiem.Format(_T("Diem: %d   "), diem);
		pDC->TextOutW(XDAU + 20 * D, YDAU + 10 * D, strdiem);
	}
	
}



void Banco::capnhathinh(CClientDC* pDC)
{
	while (dk == 1)
	{
		
		draw(pDC);
		
		Sleep(30);
	}
}

void Banco::randichuyen()
{
	while (dk == 1)
	{
		if (thang ==1 || diem >= 10)
		{
			break;
		}
		if (huong == 38) 
		{
			ran.goup();
		}
		if (huong == 37) //sang trai
		{
			ran.goleft();
		}
		if (huong == 39) // sang phai
		{
			ran.goright();
		}
		if (huong == 40) // di xuong
		{
			ran.godown();
		}
		rananmoi();
		rananmoi2();
		
		
		ktdungduoi(); 
		if (diem <= 1)
		{
			kiemtrabien();
			Sleep(300);
		}
			else if (diem >= 2 && diem <= 5)
			{
			    kiemtrabien();
				level = 2;
				Sleep(100);
				
			}
			else if(diem >=6 && diem <=10 )
			{
			
				level = 3;
				test();
				Sleep(50);
				
			}
			
	}
}



void Banco::kiemtrabien()
{
	if (ran.dau.y2 <= dv.y1)
	{
		ran.dau.y2 = dv.y2;
		ran.dau.y1 = dv.y2 - D;
	}
	if (ran.dau.x2 <= dv.x1)
	{
		ran.dau.x2 = dv.x2;
		ran.dau.x1 = dv.x2 -D;
	}
	if (ran.dau.x1 >= dv.x2)
	{
		ran.dau.x1 = dv.x1;
		ran.dau.x2 = dv.x1+D ;
	}
	if (ran.dau.y1 >= dv.y2)
	{
		ran.dau.y1 = dv.y1;
		ran.dau.y2 = dv.y1+D ;
	}
}


void Banco::batdau()
{
	dk = 1;
	diem = 0;
}

void Banco::a()
{


	dk = 0;

}





int Banco::rananmoi()
{
	
	int mx = (ran.dau.x1 + ran.dau.x2) / 2;
	int my = (ran.dau.y1 + ran.dau.y2) / 2;
	if (moi.kttronghinh(CPoint(mx, my)) == 1)
	{
		diem++;
		
		ran.tangduoi();//tang 1 pt o duoi
		
		Sleep(20);
		
		taomoi();
		
		return 1;
	}
	else
		return 0;
}

int Banco::rananmoi2()
{
	int mx = (ran.dau.x1 + ran.dau.x2) / 2;
	int my = (ran.dau.y1 + ran.dau.y2) / 2;
	

	if (food.kttronghinh(CPoint(mx, my)) == 1)
	{
		
		ran.tangduoi2();//tang 2 pt o duoi
		
		Sleep(20);
		
		if (diem % 5 == 0)
		{
			newfood();
			diem = diem + 2;
		}
			
		
		
			return 1;
		
	}
	
	return 0;
}

void Banco::taomoi()
{
	
	int g = RONG / D;
	int r = rand() % g;
	int mx = XDAU + r * D;
	r = rand() % g;
	int my = YDAU + r * D;

	int minX = 50 + 60;
	int minY = 50 + 60;
	int maxX = 50 + 600 * 3 - D;  // Trừ D để không vượt quá biên
	int maxY = 50 + 600 + 180 - D;

	while (mx < minX || mx > maxX || my < minY || my > maxY)
	{
		 r = rand() % g;
		 mx = XDAU + r * D;
		 r = rand() % g;
		 my = YDAU + r * D;
		 
	}
	
	moi = Moi(mx, my, mx + D, my + D);
	

	
}

void Banco::newfood()
{
	int g1 = RONG / D;
	int r1 = rand() % g1;
	int mx1 = XDAU + r1 * D;
	r1 = rand() % g1;
	int my1 = YDAU + r1 * D;

	int minX = XDAU + 60;
	int minY = YDAU + 60;
	int maxX = XDAU + RONG * 3 - D;  // Trừ D để không vượt quá biên
	int maxY = YDAU + RONG + 180 - D;

	while (mx1 < minX || mx1 > maxX || my1 < minY || my1 > maxY)
	{
		r1 = rand() % g1;
		mx1 = XDAU + r1 * D;
		r1 = rand() % g1;
		my1= YDAU + r1 * D;
		
	}
	food = moibonus(mx1, my1, mx1 + D, my1 + D);
	
	
}

void Banco::test()
{

	if (ran.dau.y2 <= dv.y1)
	{
		
		thang = 1;

	}
	if (ran.dau.x2 <=dv.x1)
	{
		
		thang = 1;

	}
	if (ran.dau.x1 >= dv.x2)
	{
		
		thang = 1;

	}
	if (ran.dau.y1 >= dv.y2)
	{
		
		thang = 1;

	}



}

void Banco::ktdungduoi()
{
	
	if (ran.ktdaudungduoi() == 1)
	{
		thang = 1;
		
	}
	
}






