#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"poisson.h"
#include"fileprint.h"
#include"gauss.h"
#include"hat.h"
#include"lorentz.h"
#include"fredfunc.h"
#include"erfdfunc.h"
int main()
{
	time_t t;
	srand((unsigned) time(&t));
	int n;
	float base = 100;
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
	
	for(i=0; i<length; i++)
	{
		int prob = rand()%100;
		if(prob==1)
		{
			b[i+1]=1;
			int c = rand()%5;
			if(c==0)
			{
				printf("fred %d\n", i);
				i=fred(a,i, base, length);
			}
			else if(c==1)
			{
				printf("gauss %d\n", i);
				i=gaussian(a,i, base, length);
			}
			else if(c==2)
			{
				printf("lorentz %d\n", i);
				i=lorentzian(a,i, base, length);
			}
			else if(c==3)
			{
				printf("hat %d\n", i);
				i=tophat(a,i, base, length);
			}
			else if(c==4)
			{
				printf("erfd %d\n", i);
				i=erfd(a,i, base, length);
			}
		}
	}
	poissonNoise(a, length);
	output(a, length);
	return 0;
}
