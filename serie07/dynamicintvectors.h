
/*
 * Memory allocation and initialization of
 * a dynamic int vector of length n
 */
int* mallocintvector(int n);

/*
 * Free a dynamic vector of arbitrary length and
 * set the pointer to NULL
 */
int* freeintvector(int* vector);

/*
 * Re-allocation of dynamic int vector and
 * initialization of the new entries
 */
int* reallocintvector(int* vector, int n, int nnew);

/*
 * Allocate dynamic int vector of length n
 * and read entries from keyboard
 */
int* scanintvector(int n);

/*
 * Print dynamic int vector of length n to
 * shell
 */
void printintvector(int* vector, int n);

/*
 * Determine the maximum value of a vector
 */
int maxintvector(int* vector, int n);

/*
 * Determine the minimum value of a vector
 */
int minintvector(int* vector, int n);
