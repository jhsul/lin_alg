#ifndef ERO_H
#define ERO_H

#include "mtrx.h"

void e_switch(int a, int b, mtrx_t A);
void e_scale(int a, double c, mtrx_t A);
void e_add(int a, double c, int b, mtrx_t A);

#endif