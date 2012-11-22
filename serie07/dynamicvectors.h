
/*
 * Memory allocation and initialization of
 * a dynamic double vector of length n
 */
double* mallocvector(int n);

/*
 * Free a dynamic vector of arbitrary length and
 * set the pointer to NULL
 */
double* freevector(double* vector);

/*
 * Re-allocation of dynamic double vector and
 * initialization of the new entries
 */
double* reallocvector(double* vector, int n, int nnew);

/*
 * Allocate dynamic double vector of length n
 * and read entries from keyboard
 */
double* scanvector(int n);

/*
 * Print dynamic double vector of length n to
 * shell
 */
void printvector(double* vector, int n);

/*
 * Determine the maximum value of a vector
 */
double maxvector(double* vector, int n);

/*
 * Determine the minimum value of a vector
 */
double minvector(double* vector, int n);
