#pragma once
#include "Hcn.h"
#include "Ran.h"
#include "Moi.h"
#include "moibonus.h"
#define XDAU 50
#define YDAU 50
#define RONG 600



class Banco
{
public:
	
	int dk, diem, level;
	int huong;
	int thang;
	
	Hcn dv;
	
	
	Ran ran;
	Moi moi;
	moibonus food;
	

	
	Banco();
	void draw(CClientDC* pDC);
	void capnhathinh(CClientDC* pDC);
	void randichuyen();
	void kiemtrabien();
	void batdau();
	void a();
	
	int rananmoi();
	int rananmoi2();
	void taomoi();
	void newfood();
	void ktdungduoi();
	void test();
	
	
};

