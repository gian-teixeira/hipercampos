#ifndef POINTS
#define POINTS

#include <stdlib.h>

typedef struct Point {
    struct Point *better_partner; //DEBUG
	int chaining_length;
	int x;
    int y;
} *Point;

typedef struct PointList {
    Point anchor_A;
    Point anchor_B;
	Point points;
    Point begin;
    Point end;
	int size;
} *PointList;

PointList create_list(int length);
int erase_list(PointList list);
void sort_list(PointList list);

#endif