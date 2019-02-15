#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/rref.h"

mtrx_t *ref(mtrx_t *A)
{
	//find first nonzero column
	
	return A;
}

/*mtrx_t *rref(mtrx_t *A)
{
	int c = 0;
	int r = 0;
	bool found = false;
	for(c = 0; c < A->m_cols && !found; c++)
	{
		if(!A->get[r][c])
		{
			for(int tmp = r; (tmp < A->m_rows) && !found; tmp++)
			{
				if(A->get[r][c])
				{
					found = true;
					e_switch(tmp, r, A);
				}
			}
		}
		//e_scale(r, 1.0/A->get[r][c], A);
	}
	return A;
}*/