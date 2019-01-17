#ifndef MTRX_H
#define MTRX_H

typedef struct
{
	int m_rows;
	int m_cols;
	double **get;
	double *data;
} mtrx_t;

int width(mtrx_t *A);

mtrx_t *init_mtrx(mtrx_t *A, int rows, int cols);
mtrx_t *cpy_mtrx(mtrx_t *A, mtrx_t *B);

void del_mtrx(mtrx_t *A);
void print_mtrx(mtrx_t *A);

#endif