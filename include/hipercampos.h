#ifndef GEOMETRY
#define GEOMETRY
    
#include <sys/resource.h>
#include <stdio.h>
#include "pointlist.h"

#define LEFT 0
#define RIGHT 1

typedef struct Vector2D {
	float x;
	float y;
} Vector2D;

Vector2D new_vector(Point A, Point B);
int relative_position(Vector2D u, Vector2D v);
int is_valid_partner(Point P, Point Q, Point anchor_A, Point anchor_B);
Point get_max_chaining_point(PointList list);

#endif