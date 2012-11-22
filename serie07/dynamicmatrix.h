
/*
 * Memory allocation and initialization of
 * a dynamic double matrix of length m by n
 */
double* mallocmatrix(int m, int n);

/*
 * Free a dynamic matrix of arbitrary length and
 * set the pointer to NULL
 */
double* freematrix(double* matrix);

/*
 * Re-allocation of dynamic double matrix and
 * initialization of the new entries
 */
double* reallocmatrix(double* matrix, int m, int n, int mnew, int nnew);

/*
 * Allocate dynamic double matrix of length m by n
 * and read entries from keyboard
 */
double* scanmatrix(int m, int n);

/*
 * Print dynamic double matrix of length m by n to
 * shell
 */
void printmatrix(double* matrix, int m, int n);

/*
 * Cuts off row j from the matrix
 */
double* cutOffRowJ(double* matrix, int m, int n, int j);

/*
 * Cuts off column k from the matrix
 */
double* cutOffColK(double* matrix, int m, int n, int k);
