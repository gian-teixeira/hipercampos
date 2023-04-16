#include "hipercampos.h"

// Novo vetor a partir de dois pontos
Vector2D new_vector(Point A, Point B) {
	return (Vector2D){ B->x - A->x, B->y - A->y };
}

int relative_position(Vector2D u, Vector2D v) {
    //     Determinado pelo seno do ângulo entre os vetores, o módulo do
    // produto vetorial (mais especificamente, seu coeficiente z) permite que  
    // a verificação da posição relativa de v em relação a u, sendo que
    //     > 0 : esquerda (LEFT)
    //     < 0 : direita  (RIGHT)
	int cross_z = u.x*v.y - u.y*v.x;
	return (int)(cross_z < 0);
}

// Verifica se um ponto (inside_point) pode ser encapsulado por outro (outside_point)
// sem que as arestas formadas entre eles e as âncoras se interceptem.
int are_valid_partners(Point outside_point, Point inside_point, Point anchor_A, Point anchor_B) {
    Vector2D A_to_point = new_vector(anchor_A, outside_point);
	Vector2D B_to_point = new_vector(anchor_B, outside_point);
	Vector2D A_to_partner = new_vector(anchor_A, inside_point);
    Vector2D B_to_partner = new_vector(anchor_B, inside_point);
    
    // RIGHT e LEFT são macros definidas no cabeçalho do módulo e servem como
    // legendas para o retorno da função relative_position()
    return (relative_position(A_to_point, A_to_partner) == RIGHT 
            && relative_position(B_to_point, B_to_partner) == LEFT);
}

// Função principal do programa, responsável por encontrar um encadeamento (chaining)
// ótimo de triângulos.
Point get_max_chaining_point(PointList list) {
	Point betterChainingPoint = list->begin;

    for(Point currentPoint = list->begin + 1; currentPoint != list->end; currentPoint++) {
        
        // A nulidade e posterior verificação evita a necessidade de alocação de desalocação
        // de um novo ponto auxiliar.
        Point betterPartner = NULL;
        
        // A compatibilidade do ponto atual é testada, a princípio, com todos os pontos
        // que estão abaixo dele, a fim de que se encontre aquele que já tem o maior 
        // encademento.
        for(Point currentPartner = currentPoint - 1; currentPartner >= list->begin; currentPartner--){   
            if(are_valid_partners(currentPoint, currentPartner, list->anchor_A, list->anchor_B)){
                if(!betterPartner || currentPartner->chaining_length > betterPartner->chaining_length){
					betterPartner = currentPartner;
                }
            }
        }

        if(!betterPartner) continue;
        
        currentPoint->better_partner = betterPartner;
        currentPoint->chaining_length = betterPartner->chaining_length + 1;
        if(currentPoint->chaining_length > betterChainingPoint->chaining_length)
            betterChainingPoint = currentPoint;
    }
    
    return betterChainingPoint;
}
