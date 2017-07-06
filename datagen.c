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
int main(int argc, char** argv)
{
	time_t t;
	srand((unsigned) time(&t));
	int n;
	float base = 100;
	n=7;
	int length= pow(2,n);
	float a[length];
	
	int i;
	
	for(i=0; i<length ; i++)
	{
		a[i] = base;
	}
	float peak = 150;
	float dur;
	//scanf("%f%f", &peak, &dur);
	int type=0;
	if(argc==3 && strcmp(argv[1], "f\0")==0 )
	{
		type = 1;
		dur = atof(argv[2])/10;
		fred(a, 1, length, base, peak, dur);
	}
	else if(argc==3 && strcmp(argv[1], "g\0")==0)
	{
		type = 2;
		dur = atof(argv[2])/10;
		gaussian(a, peak, length/2, dur, length, base);
	}
	else if(argc==3 && strcmp(argv[1], "l\0")==0)
	{
		type = 3;
		dur = atoi(argv[2])/10;
		lorentzian(a, peak, length/2, length, base,dur);
	}
	else if(argc==3 && strcmp(argv[1], "t\0")==0)
	{
		type = 4;
		dur = atoi(argv[2])/10;
		tophat(a, peak, dur, length/2, length, base);
	}
	else if(argc==3 && strcmp(argv[1], "e\0")==0)
	{
		type = 5;
		dur = atoi(argv[2])/10;
		erfd(a, 1, length, base, peak, dur);
	}
	else
	{
		printf("Please check the parameters\n");
	}
	
	poissonNoise(a, length);
	output(a, length, type);
	return 0;
}
