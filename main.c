#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/rref.h"
#include "include/ops.h"

int main()
{
	int rows = 3;
	int cols = 3;
	
		
	double ra[] = {0, 0, 5},
		   rb[] = {1, 0, -99},
		   rc[] = {0, 134, 130};
		   
	double rd[] = {3, 5, 1},
		   re[] = {2390, -11, 0},
		   rf[] = {190, 1, 139};
		   
	mtrx_t A, B, C;
	
	init_mtrx(&A, 3, 3);
	init_mtrx(&B, 3, 3);
	init_mtrx(&C, 3, 3);	
	
	memcpy(A.get[0], ra, sizeof(ra));
    memcpy(A.get[1], rb, sizeof(rb));
    memcpy(A.get[2], rc, sizeof(rc));
    
    memcpy(B.get[0], rd, sizeof(rd));
    memcpy(B.get[1], re, sizeof(re));
    memcpy(B.get[2], rf, sizeof(rf));
    
    cpy_mtrx(A, B);
	
	print_mtrx(A);
	print_mtrx(B);
	
	m_add(&A, &B, &C);
	print_mtrx(C);
	e_switch(0,1,C);
	
	print_mtrx(C);
	
	del_mtrx(&A);
	del_mtrx(&B);
	del_mtrx(&C);
	
}