#ifndef MTRX_H
#define MTRX_H

typedef struct
{
	int m_rows;
	int m_cols;
	double **arr;
	double *data;
} t_mtrx;

int width(t_mtrx *A);

t_mtrx *init_mtrx(int rows, int cols);
void del_mtrx(t_mtrx *A);
void print_mtrx(t_mtrx *A);

#endif