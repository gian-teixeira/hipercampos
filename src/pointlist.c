#include "pointlist.h"

PointList create_list(int length) {
	PointList list = (PointList)malloc(sizeof(struct PointList));
        list->anchor_A = (Point)malloc(sizeof(struct Point));
        list->anchor_B = (Point)malloc(sizeof(struct Point));
            list->anchor_A->y = list->anchor_B->y = 0;
        // O vetor de pontos é iniciado com tamanho maior que o argumento a 
        // fim de possibilitar que list->end aponte para uma posição "vazia" 
        // depois de todos os elementos.
		list->points = (Point)malloc((length + 1) * sizeof(struct Point));
		list->end = list->points + length;
		list->begin = list->points;
		list->size = length;
    
	return list;
}

// Função que implementa o funcionamento do algoritmo selection sort e fica 
// responsável por ordenar a lista de pontos.
void sort_list(PointList list) {
    Point helper = (Point)malloc(sizeof(struct Point));
    for(Point current_point = list->begin; current_point != list->end - 1; current_point++)
        for(Point current_partner = current_point + 1; current_partner != list->end; current_partner++)
            if(current_point->y > current_partner->y){
                *helper = *current_point;
                *current_point = *current_partner;
                *current_partner = *helper;
            }
    free(helper);
}

// A lista de pontos é alocada dinamicamente, então sua desalocação precisa
// ser feita de forma ativa. Essa função possui justamente esse objetivo.
int erase_list(PointList list) {
	if(list == NULL) return 0;

    free(list->anchor_A);
    free(list->anchor_B);
    free(list->points);
    free(list);
	
	return 1;
}
