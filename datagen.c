#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"noise.h"
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
				printf("fred\t%d\t", i);
				i=fred(a,i, base, length);
				printf("%d\n", i);
			}
			else if(c==1)
			{
				printf("gauss\t%d\t", i);
				i=gaussian(a,i, base, length);
				printf("%d\n", i);
			}
			else if(c==2)
			{
				printf("lorentz\t%d\t", i);
				i=lorentzian(a,i, base, length);
				printf("%d\n", i);
			}
			else if(c==3)
			{
				printf("hat\t%d\t", i);
				i=tophat(a,i, base, length);
				printf("%d\n", i);
			}
			else if(c==4)
			{
				printf("erfd\t%d\t", i);
				i=erfd(a,i, base, length);
				printf("%d\n", i);
			}
		}
	}
	noise(a, length);
	output(a, length);
	return 0;
}
