/*CHEN, Hannah / G01*/
//1e3 -> milliseconds
//release version

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************************************************************************/
/*  x86 SIMD ISA (code in asmfunc1.asm file)   */
/*************************************************************************/
extern void SIMDdotProduct(int n, double* sdot, double* A, double* B);

/*************************************************************************/
/*  x86-64 (code in asmfunc2.asm file)    */
/*************************************************************************/
extern void x86dotProduct(int n, double* sdot, double* A, double* B);

/*************************************************************************/
/*  C program codes     */
/*************************************************************************/
void dotProduct(int n, double* sdot, double* A, double* B) {
    *sdot = 0.0;
    for (int i = 0; i < n; i++) {
        *sdot += A[i] * B[i];
    }
}

double bulkRunC(unsigned int vector_size) {
    const unsigned int n = vector_size;
    const unsigned int ARRAY_BYTES = n * sizeof(double);

    //declare array
    double* A, * B;
    double* sdot;

    A = (double*)malloc(ARRAY_BYTES);
    B = (double*)malloc(ARRAY_BYTES);
    sdot = (double*)malloc(ARRAY_BYTES);

    //timer variables
    clock_t start, end;

    //initialize array
    for (unsigned int i = 0; i < n; i++) {
        A[i] = (double)1.0;
        B[i] = (double)1.0;
    }

    /*C version*/
    //flush out cache
    dotProduct(n, sdot, A, B);

    //time here
    start = clock();
    dotProduct(n, sdot, A, B);
    end = clock();
    double time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

    //error checking
    double       expected_sdot = 0.0;
    double       actual_sdot = 0.0;

    for (unsigned int i = 0; i < n; i++) {
        expected_sdot = expected_sdot + (A[i] * B[i]);
    }

    actual_sdot = *sdot;

    printf("Expected sdot is: %.5lf\n", expected_sdot);
    printf("Actual sdot is: %.5lf\n", actual_sdot);
    if (expected_sdot == actual_sdot) {
        printf("Expected sdot and Actual sdot matched. Result is CORRECT!\n\n");
    }
    else {
        printf("Expected sdot and Actual sdot do not match. Result is WRONG!\n\n");
    }
    /* End of C version */

    free(A);
    free(B);
    free(sdot);

    return time_taken;
}

/*************************************************************************/
/*  call x86-64 program codes     */
/*************************************************************************/
double bulkRunx86(unsigned int vector_size) {
    const unsigned int n = vector_size;
    const unsigned int ARRAY_BYTES = n * sizeof(double);

    //declare array
    double* A, * B;
    double* sdot;

    A = (double*)malloc(ARRAY_BYTES);
    B = (double*)malloc(ARRAY_BYTES);
    sdot = (double*)malloc(ARRAY_BYTES);

    //timer variables
    clock_t start, end;

    //initialize array
    for (unsigned int i = 0; i < n; i++) {
        A[i] = (double)1.0;
        B[i] = (double)1.0;
    }

    /* x86-64 SIMD YMM */
    //flush out cache
    x86dotProduct(n, sdot, A, B);

    //time here
    start = clock();
    x86dotProduct(n, sdot, A, B);
    end = clock();
    double time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

    //error checking
    double  expected_sdot = 0.0;
    double  actual_sdot = 0.0;

    for (unsigned int i = 0; i < n; i++) {
        expected_sdot = expected_sdot + (A[i] * B[i]);
    }

    actual_sdot = *sdot;

    printf("(x86-64) Expected sdot is: %.5lf\n", expected_sdot);
    printf("(x86-64) Actual sdot is: %.5lf\n", actual_sdot);
    if (expected_sdot == actual_sdot) {
        printf("(x86-64) Expected sdot and Actual sdot matched. Result is CORRECT!\n\n");
    }
    else {
        printf("(x86-64) Expected sdot and Actual sdot do not match. Result is WRONG!\n\n");
    }
    /* End of x86-64 version */

    free(A);
    free(B);
    free(sdot);

    return time_taken;
}

/*************************************************************************/
/*  call x86-64 SIMD ISA program codes   */
/*************************************************************************/
double bulkRunSIMDYMM(unsigned int vector_size) {
    const unsigned int n = vector_size;
    const unsigned int ARRAY_BYTES = n * sizeof(double);

    //declare array
    double* A, * B;
    double* sdot;

    A = (double*)malloc(ARRAY_BYTES);
    B = (double*)malloc(ARRAY_BYTES);
    sdot = (double*)malloc(ARRAY_BYTES);

    //timer variables
    clock_t start, end;

    //initialize array
    for (unsigned int i = 0; i < n; i++) {
        A[i] = (double)1.0;
        B[i] = (double)1.0;
    }

    /* x86-64 SIMD YMM */
    //flush out cache
    SIMDdotProduct(n, sdot, A, B);

    //time here
    start = clock();
    SIMDdotProduct(n, sdot, A, B);
    end = clock();
    double time_taken = ((double)(end - start)) * 1e6 / CLOCKS_PER_SEC;

    //error checking
    double  expected_sdot = 0.0;
    double  actual_sdot = 0.0;

    for (unsigned int i = 0; i < n; i++) {
        expected_sdot = expected_sdot + (A[i] * B[i]);
    }

    actual_sdot = *sdot;

    printf("(x86_SIMD_ISA) Expected sdot is: %.5lf\n", expected_sdot);
    printf("(x86_SIMD_ISA) Actual sdot is: %.5lf\n", actual_sdot);
    if (expected_sdot == actual_sdot) {
        printf("(x86_SIMD_ISA) Expected sdot and Actual sdot matched. Result is CORRECT!\n\n");
    }
    else {
        printf("(x86_SIMD_ISA) Expected sdot and Actual sdot do not match. Result is WRONG!\n\n");
    }
    /* End of x86-64 SIMD YMM */

    free(A);
    free(B);
    free(sdot);

    return time_taken;
}

/************************************************************************************************/
/*  main function for calling the bulkRun functions of the C, x86-64, and x86 SIMD ISA kernels  */
/************************************************************************************************/
int main() {
    int numberOfRuns = 30;
    double* timeResults = (double*)malloc(numberOfRuns * sizeof(double));
    double totalResult = 0;

    unsigned int array_size = 1 << 26;

    /*************************************************************************/
    /* run C program */
    /*************************************************************************/
    for (int i = 0; i < numberOfRuns; i++) {
        timeResults[i] = bulkRunC(array_size);
        totalResult += timeResults[i];
    }

    printf("\n\nC Program total number of runs: %d.\n", numberOfRuns);
    for (int i = 0; i < numberOfRuns; i++)
        printf("Run number %d takes %f microseconds.\n", i + 1, timeResults[i]);

    //get average time taken
    double aveResult = totalResult / numberOfRuns;
    printf("\nFor C Program, the average run time result of %d runs for an array size of %d is %f microseconds.\n\n\n",
        numberOfRuns, array_size, aveResult);

    /*************************************************************************/
    /* call x86-64 program */
    /*************************************************************************/
    timeResults = (double*)malloc(numberOfRuns * sizeof(double));
    totalResult = 0;

    for (int i = 0; i < numberOfRuns; i++) {
        timeResults[i] = bulkRunx86(array_size);
        totalResult += timeResults[i];
    }

    printf("\n\n(x86-64) Program total number of runs: %d.\n", numberOfRuns);
    for (int i = 0; i < numberOfRuns; i++)
        printf("(x86-64) Run number %d takes %f microseconds.\n", i + 1, timeResults[i]);

    //get average time taken
    aveResult = totalResult / numberOfRuns;
    printf("\nFor (x86-64) Program, the average run time result of %d runs for an array size of %d is %f microseconds.\n\n\n",
        numberOfRuns, array_size, aveResult);

    /*************************************************************************/
    /*  call x86 SIMD ISA program   */
    /*************************************************************************/
    timeResults = (double*)malloc(numberOfRuns * sizeof(double));
    totalResult = 0;

    for (int i = 0; i < numberOfRuns; i++) {
        timeResults[i] = bulkRunSIMDYMM(array_size);
        totalResult += timeResults[i];
    }

    printf("\n\nx86_SIMD_ISA Program total number of runs: %d.\n", numberOfRuns);
    for (int i = 0; i < numberOfRuns; i++)
        printf("x86_SIMD_ISA Run number %d takes %f microseconds.\n", i + 1, timeResults[i]);

    //get average time taken
    aveResult = totalResult / numberOfRuns;
    printf("\nFor x86_SIMD_ISA Program, the average run time result of %d runs for an array size of %d is %f microseconds.\n\n\n",
        numberOfRuns, array_size, aveResult);

    return 0;
}