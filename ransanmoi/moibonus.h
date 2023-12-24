#pragma once
#include "Tron.h"
class moibonus :
    public Tron
{
public:
    moibonus() :Tron() {}
    moibonus(int mx1, int my1, int mx2, int my2) :Tron(mx1, my1, mx2, my2) {}
    void draw(CClientDC* pDC);
};

