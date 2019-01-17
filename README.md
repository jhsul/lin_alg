# Linear Algebra C Library
This is an ongoing implementation of various linear algebra tools in C.

## The `mtrx_t` Type

### Usage

To make memory management easier, none of the operations make a new matrix. As such, **all operations change matrixes in place.** The exception

### Structure Definition

```C
typedef struct
{
	int m_rows;
	int m_cols;
	double **arr;
	double *data;
} mtrx_t;
```

- `data` points to an array holding the entire contents of the matrix.
- `arr` points to an array of the addresses of the first elements of each row.

For example:

```C
A    = [[a, b, c],
       [d, e, f],
       [g, h, i]]
     
data = [a, b, c, d, e, f, g, h, i]
arr  = [&a, &d, &g]
``` 
### Construction / Destruction

There is a basic constructor and destructor. Treat them like `malloc` and `free`:

```C
mtrx_t *init_mtrx(mtrx_t *A, int rows, int cols);
void del_mtrx(mtrx_t *A);
```

Example usage:

```C
mtrx_t A;
init_mtrx(&A, 3, 4);
//...
del_mtrx(&A);
```

### Copying

There is a function to make it easier to copy another matrix. `A` is the source, `B` is the destination.

```C
mtrx_t *cpy_mtrx(mtrx_t *A, mtrx_t *B);
```

Example **incorrect** copy:

```C
mtrx_t A;
init_mtrx(&A, 3, 3);
//...
mtrx_t B = A;
```
Since the data is stored in pointers, the elements will be stored in the same memory. There would be no practical reason to do this.

Example **correct** copy:

```C
mtrx_t A;
mtrx_t B;
init_mtrx(&A, 3, 3);
init_mtrx(&B, 3, 3);
//...
cpy_mtrx(&A, &B);
```

### Printing

This function makes it easier to print out a whole matrix. It (tries) to make the spacing as tight as possible while keeping all the columns lined up.

```C
void print_mtrx(mtrx_t *A);
```


## Elementary Row Operations

### Type I: Switch

```C
void e_switch(int a, int b, mtrx_t *A);
```

Switch rows `a` and `b` of matrix `A`

### Type II: Scale

```C
void e_scale(int a, double c, mtrx_t *A);
```

Scale row `a` of matrix `A` by `c`

### Type III: Add (with Scaling)

```C
void e_add(int a, double c, int b, mtrx_t *A);
```

Scale row `a` of matrix `A` by `c` and add it to row `b`
