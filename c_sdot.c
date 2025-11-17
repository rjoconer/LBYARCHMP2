#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <math.h>   

extern float sdot(int n, float *a, float *b);

float sdotChecker (int n, float *a, float *b) {
	int i;
	float res = 0;
	
	for (i = 0; i < n; i++) {
		res += a[i] * b[i];
	}
	
	return res;
}

// Helper Function to initialize vectors with random float values.
void initialize_vectors(long n, float *a, float *b) {
    printf("Initializing vectors with %ld \n", n);
    for (long i = 0; i < n; i++) {
        a[i] = (float)rand() / (float)RAND_MAX;
        b[i] = (float)rand() / (float)RAND_MAX;
    }
}

int main() {
    long n_sizes[] = { 1L << 20, 1L << 24, 1L << 28 };
    int num_sizes = sizeof(n_sizes) / sizeof(n_sizes[0]);

    const int NUM_RUNS = 20;

    clock_t start, end;
    double c_time, asm_time, avg_c, avg_asm;

    srand(time(NULL));

    for (int i = 0; i < num_sizes; i++) {
        long n = n_sizes[i];
        printf("\n----------------------------------------------\n");
        printf("--- Testing for N = %ld (2^%d) ---\n", n, 20 + (i*4));
        printf("----------------------------------------------\n");

        float *a = (float*) malloc(n * sizeof(float));
        float *b = (float*) malloc(n * sizeof(float));

        if (a == NULL || b == NULL) {
            printf("Error: Could not allocate memory for N=%ld.\n", n);
            continue; 
        }

        initialize_vectors(n, a, b);

        printf("Timing C kernel (%d runs)...\n", NUM_RUNS);
        start = clock();
        for (int run = 0; run < NUM_RUNS; run++) {
            sdotChecker(n, a, b);
        }
        end = clock();
        c_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        avg_c = c_time / NUM_RUNS;

        printf("Timing ASM kernel (%d runs)...\n", NUM_RUNS);
        start = clock();
        for (int run = 0; run < NUM_RUNS; run++) {
            sdot(n, a, b); 
        }
        end = clock();
        asm_time = ((double) (end - start)) / CLOCKS_PER_SEC;
        avg_asm = asm_time / NUM_RUNS;

        printf("\n--- Results for N = %ld ---\n", n);
        float cres = sdotChecker(n, a, b);
        float asmres = sdot(n, a, b);

        printf("C Result:     %f\n", cres);
        printf("ASM Result:   %f\n", asmres);
        
        if (fabs(cres - asmres) < 0.0001) {
            printf("Correctness Check: PASSED\n");
        } else {
            printf("Correctness Check: FAILED\n");
        }

        printf("\n--- Performance for N = %ld ---\n", n);
        printf("C Kernel Average:   %f seconds\n", avg_c);
        printf("ASM Kernel Average: %f seconds\n", avg_asm);

        // Free up memory
        free(a);
        free(b);
    }

    printf("\nAll tests complete.\n");
	return 0;
}
