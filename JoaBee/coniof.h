#ifndef CONIOF_H_INCLUDED
#define CONIOF_H_INCLUDED

struct areaxy
{
    int x1;
    int y1;
    int x2;
    int y2;
};

typedef struct areaxy axy;

void textcolor (int iColor);

void delay(unsigned int mseconds);

void gotoxy(int x, int y);

#endif //CONIOF_H_INCLUDED
