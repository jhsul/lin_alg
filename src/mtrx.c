#include <stdio.h>
#include <stdlib.h>

#include "../include/mtrx.h"

int width(t_mtrx *A)
{
	double x = A -> arr [0][0];
	for(int r = 0; r < A -> m_rows; r++)
	{
		for(int c = 0; c < A -> m_cols; c++)
		{
			if ((A -> arr[r][c] < 0 ? (-10) * A -> arr[r][c] : A -> arr[r][c]) > x)
				x = A -> arr[r][c] < 0 ? (-10)*A -> arr[r][c] : A -> arr[r][c];
		}
	}
	int i = 0;
	int y = (int) x;
	while(y /= 10)
		i++;
	return i+4; // +1 for extra step, +3 for decimal places
}

t_mtrx init_mtrx(int rows, int cols)
{
	t_mtrx A;
	A.m_rows = rows;
	A.m_cols = cols;
	A.arr = malloc(rows * sizeof(*A.arr));
	A.data = malloc(rows * cols * sizeof(*A.data));
	
	double *tmp = A.data;
	
	for(int i = 0; i < rows; i++, tmp += cols)
		A.arr[i] = tmp;
	
	return A;
}
void del_mtrx(t_mtrx *A)
{
	
	free(A -> arr);
}

void print_mtrx(t_mtrx *A)
{
	int w = width(A);
	int p = 2;
	
	printf("\n");
	for(int r = 0; r < A -> m_rows; r++)
	{
		for(int c = 0; c < A -> m_cols; c++)
		{
			/* top left */
			if(!r && !c)
				printf("[[%*.*f, ", w, p, A -> arr[r][c]);
			
			/* bottom right */
			else if(r == A -> m_rows - 1 && c == A -> m_cols - 1)
				printf("%*.*f]] %i x %i\n", w, p,  A -> arr[r][c], A -> m_rows, A -> m_cols);
				
			/* left side */
			else if(!c)
				printf(" [%*.*f, ", w, p, A -> arr[r][c]);
			
			/* right side */
			else if(c == A -> m_cols - 1)
				printf("%*.*f],", w, p, A -> arr[r][c]);
			
			/* middle elements */
			else
				printf("%*.*f, ", w, p, A -> arr[r][c]);
				
		}
		if(r != A -> m_rows-1)
			printf("\n");
	}
}