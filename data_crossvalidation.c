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
int main()
{
	time_t t;
	srand((unsigned) time(&t));
	int n;
	float base = 100;
	n=8;
	int length= pow(2,n);
	float a[length];
	
	int i;
	
	for(i=0; i<length ; i++)
	{
		a[i] = base;
	}
	float peak = 150 + rand()%200;
	float dur;
	
	int type=1 + rand()%5;
	
	if( type==1 )
	{
		dur = 2 + rand()%13;
		fred(a, 50, length, base, peak, dur);
	}
	else if(type==2)
	{
		dur = 5 + rand()%21;
		gaussian(a, peak, length/2, dur, length, base);
	}
	else if(type==3)
	{
		dur = 5 + rand()%21;
		lorentzian(a, peak, length/2, length, base,dur);
	}
	else if(type==4)
	{
		dur = 15 + rand()%21;
		tophat(a, peak, dur, length/2, length, base);
	}
	else if(type==5)
	{
		dur = 3 + rand()%13;
		erfd(a, 1, length, base, peak, dur);
	}
	
	poissonNoise(a, length);
	output(a, length, type);
	return 0;
}
