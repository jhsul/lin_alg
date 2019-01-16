#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/rref.h"


int main()
{
	int rows = 3;
	int cols = 3;
	
		
	double ra[] = {1, 3223, 5},
		   rb[] = {2, 0, -99},
		   rc[] = {14, 134, 130};
		   
	mtrx_t A;
	mtrx_t B;
	
	init_mtrx(&A, 3, 3);
	init_mtrx(&B, 3, 3);	
	
	memcpy(A.arr[0], ra, sizeof(ra));
    memcpy(A.arr[1], rb, sizeof(rb));
    memcpy(A.arr[2], rc, sizeof(rc));
	
	print_mtrx(&A);
	
	cpy_mtrx(&A, &B);
	
	print_mtrx(&B);
	
	A.arr[0][1] = 10.0;
	
	print_mtrx(&A);
	print_mtrx(&B);
	
	
	del_mtrx(&A);
	del_mtrx(&B);
	
}