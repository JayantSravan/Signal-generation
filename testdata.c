#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"erfdfunc.h"
#include"fredfunc.h"
#include"gauss.h"
#include"lorentz.h"
#include"hat.h"
#include"poisson.h"
#include"fileprint.h"
void clear(float* b, int length)
{
	int i=0;
	for(i=0; i<length; i++)
	{
		b[i]=0;
	}
}

void add(float* a, float* b, int length)
{
	int i;
	for(i=0; i<length; i++)
	{
		a[i]= a[i] + b[i];
	}
	clear(b, length);
}
void add2(float* a, float* b, int length)
{
	int i;
	for(i=0; i<length; i++)
	{
		if(b[i]>100.01)
		{
			a[i]= b[i];
		}
	}
	clear(b, length);
}
int main()
{
	time_t t;
	srand((unsigned) time(&t));
	
	int n;
	scanf("%d", &n);
	int length = pow(2, n);
	
	float a[length], b[length];
	float base = 100;
	float peak = 150;
	
	int i=0;
	for(i=0; i<length; i++)
	{
		a[i]=base;
		b[i]= 0;
	}
	
	i=0;
	while(i<length)
	{
		int p = rand()%100;
		if(p==1)
		{
			int choice = rand()%5;
			if(choice == 0)
			{
				float dur = (500 + rand()%1000)/100;
				printf("fred - %f %d\n", dur, i);
				peak = 150 + rand()%120;
				i = fred(b , i, length, base, peak, dur);
				add2(a, b, length);
			}
			else if(choice==1)
			{
				float dur = 5 + rand()%20;
				printf("gaussian - %f %d\n", dur, i);
				peak = 150 + rand()%120;
				gaussian(b, peak, i , dur, length, base);
				add(a,b ,length);
				i=i+100;
			}
			else if(choice==2)
			{
				float dur = (500 + rand()%1000)/100;
				printf("lorentzian - %f %d\n", dur, i);
				peak = 150 + rand()%120;
				lorentzian(b, peak, i , length, base, dur);
				add(a,b,length);
				i=i+100;
			}
			else if(choice==3)
			{
				float dur = (1500 + rand()%2000)/100;
				printf("tophat - %f %d\n", dur, i);
				peak = 150 + rand()%120;
				tophat(b, peak, dur, i , length, base);
				add2(a,b,length);
				i=i+100;
			}
			else if(choice==4)
			{
				float dur = (700 + rand()%1000)/100;
				printf("erfd - %f %d\n", dur, i);
				peak = 150 + rand()%120;
				erfd(b, i, length, base, peak, dur);
				add2(a,b,length);
				i=i+150;
			}
		}
		i++;
	}
	poissonNoise(a, length);
	output(a, length, 0);
	return 0;
}
