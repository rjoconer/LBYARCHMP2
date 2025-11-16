#include <stdio.h>

extern float sdot(int n, float *a, float *b);

float sdotChecker (int n, float *a, float *b) {
	int i;
	float res = 0;
	
	for (i = 0; i < n; i++) {
		res += a[i] * b[i];
	}
	
	return res;
}

int main() {
	int n;
	
	//get n (number of input values for vector A and B
	printf("Enter number of inputs: ");
	scanf("%d", &n);
	
	//initialize float values
	float a[n];
	float b[n];
	
	//get values inside each vector
	int i;
	for (i = 0; i < n; i++)
	{
		printf("Enter value for A%d: ", i + 1);
		scanf("%f", &a[i]);
	}
	
	for (i = 0; i < n; i++)
	{
		printf("Enter value for B%d: ", i + 1);
		scanf("%f", &b[i]);
	}
	
	//perform sdot
	float cres = sdotChecker(n, a, b);
	float asmres = sdot(n, a, b);
	
	//print result using C checker
	printf("\n\nC Result: %f\n", cres);
	
	//print asm result
	printf("ASM Result: %f", asmres);
	
	return 0;
}
