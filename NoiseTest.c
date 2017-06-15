#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"poisson.h"
#include"fileprint.h"

int main()
{
	time_t t;
	srand((unsigned) time(&t));
	int n;
	float base = 150;
	scanf("%d", &n);
	n = n%25;
	int length= pow(2,n);
	float a[length], b[length];
	
	int i;
	
	for(i=0; i<=length ; i++)
	{
		a[i] = base;
		b[i] = 0;
	}
	
	
	poissonNoise(a, length);
	output(a, length);
	return 0;
}
