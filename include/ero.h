#ifndef ERO_H
#define ERO_H

#include "mtrx.h"

void e_switch(int a, int b, t_mtrx *A);
void e_scale(int a, double c, t_mtrx *A);
void e_add(int a, double c, int b, t_mtrx *A);

#endif