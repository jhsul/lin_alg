#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/rref.h"


int main()
{
	int rows = 3;
	int cols = 3;
	
	
	//double **mtrx = test_init(rows, cols);
		
	double ra[] = {1, 3223, 5},
		   rb[] = {2, 0, -99},
		   rc[] = {14, 134, 130};
		   
	t_mtrx *A = init_mtrx(rows, cols);
	
	memcpy(A -> arr[0], ra, sizeof(ra));
    memcpy(A -> arr[1], rb, sizeof(rb));
    memcpy(A -> arr[2], rc, sizeof(rc));
	
	print_mtrx(A);
	
	
	del_mtrx(A);
	
	/*
	double **mtrx = malloc(rows * sizeof *mtrx);
	double *data = malloc(rows * cols * sizeof *data);

	for (int i = 0; i < rows; i++, data += cols)
  	mtrx[i] = data;
  	
  	free(*mtrx);
	free(mtrx);

	*/
}