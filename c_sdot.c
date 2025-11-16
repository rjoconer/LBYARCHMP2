#include <stdio.h>
#define MAX 5000

extern float sdot(int n, float *a, float *b);

int main() {
	int n;
	
	//get n (number of input values for vector A and B
	printf("Enter number of inputs: ");
	scanf("%d", &n);
	
	//initialize float values
	float a[MAX];
	float b[MAX];
	
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
	float res = sdot(n, a, b);
	
	//print result
	printf("Result: %f", res);
	
	return 0;
}
