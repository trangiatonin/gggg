#include "pch.h"
#include "moibonus.h"

void moibonus::draw(CClientDC* pDC)
{
	CBrush* newb = new CBrush(RGB(0, 250, 250));
	CBrush* oldb;
	oldb = pDC->SelectObject(newb);
	Tron::draw(pDC);
	pDC->SelectObject(oldb);
}
