#include <stdio.h>
#include <stdlib.h>

#include "../include/mtrx.h"

int width(mtrx_t A)
{
	double x = A.get [0][0];
	for(int r = 0; r < A.m_rows; r++)
	{
		for(int c = 0; c < A.m_cols; c++)
		{
			if ((A.get[r][c] < 0 ? (-10) * A.get[r][c] : A.get[r][c]) > x)
				x = A.get[r][c] < 0 ? (-10)*A.get[r][c] : A.get[r][c];
		}
	}
	int i = 0;
	int y = (int) x;
	while(y /= 10)
		i++;
	return i+4; // +1 for extra step, +3 for decimal places
}

mtrx_t *init_mtrx(mtrx_t *A, int rows, int cols)
{
	A -> m_rows = rows;
	A -> m_cols = cols;
	A -> get = calloc(rows, sizeof(A -> get));
	A -> data = calloc(rows * cols, sizeof(A -> data));
	
	for(int i = 0; i < rows; i++)
        A -> get[i] = A -> data + (i * cols);
	
	return A;
}

/*
A: Source
B: Destination
*/
mtrx_t cpy_mtrx(mtrx_t A, mtrx_t B)
{
	for(int r = 0; r < A.m_rows; r++)
	{
		for(int c = 0; c < A.m_cols; c++)
		{
			B.get[r][c] = A.get[r][c];
		}
	}
	return B;
}

void del_mtrx(mtrx_t *A)
{
	free(A->data);
    free(A->get);
}

void print_mtrx(mtrx_t A)
{
	int w = width(A);
	int p = 2;
	
	printf("\n");
	for(int r = 0; r < A.m_rows; r++)
	{
		for(int c = 0; c < A.m_cols; c++)
		{
			/* top left */
			if(!r && !c)
				printf("[[%*.*f, ", w, p, A.get[r][c]);
			
			/* bottom right */
			else if(r == A.m_rows - 1 && c == A.m_cols - 1)
				printf("%*.*f]] %i x %i\n", w, p,  A.get[r][c], A.m_rows, A.m_cols);
				
			/* left side */
			else if(!c)
				printf(" [%*.*f, ", w, p, A.get[r][c]);
			
			/* right side */
			else if(c == A.m_cols - 1)
				printf("%*.*f],", w, p, A.get[r][c]);
			
			/* middle elements */
			else
				printf("%*.*f, ", w, p, A.get[r][c]);
				
		}
		if(r != A.m_rows-1)
			printf("\n");
	}
}