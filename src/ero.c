#include <stdlib.h>
#include <string.h>

#include "../include/ero.h"


/*
Swap the rows mtrx[a] and mtrx[b]
*/
void e_switch(int a, int b, mtrx_t A)
{
	double *tmp = malloc(A.m_cols * sizeof(**A.get));
	
	memcpy(tmp, A.get[a], A.m_cols * sizeof(**A.get));
	
	memcpy(A.get[a], A.get[b], A.m_cols * sizeof(**A.get));
	memcpy(A.get[b], tmp, A.m_cols * sizeof(** A.get));
	
	free(tmp);
}

/*
Scale every element in mtrx[a] by c
*/
void e_scale(int a, double c, mtrx_t A)
{
	for(int i = 0; i < A.m_cols; i++)
		A.get[a][i] *= c;
}

/*
Add c*mtrx[a] to mtrx[b]
*/
void e_add(int a, double c, int b, mtrx_t A)
{
	for(int i = 0; i < A.m_cols; i++)
		A.get[b][i] += c * A.get[a][i];
}