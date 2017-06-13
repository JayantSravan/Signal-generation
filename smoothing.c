#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"smoothout.h"
void smoothing(float* init, float* smooth, float base, int n)
{
	float a, b, c, d, e;
	int i=0;
	float* dummy = malloc(n * sizeof(float));
	for(i=0; i<n; i++)
	{
		if(i-2>=0)
		{
			a = smooth[i-2];
		}
		else
			a = base;
		if(i-1>=0)
		{
			b = smooth[i-1];
		}
		else
			b = base;
			
		c= smooth[i];
		if(i+1<n)
		{
			d = smooth[i+1];
		}
		else
			d = base;
		if(i+2<n)
		{
			e = smooth[i+2];
		}
		else
			e = base;
			
		dummy[i] = (a + 2*b + 3*c + 2*d + e)/9;
	}
	for(i=0; i<n; i++)
	{
		smooth[i] = dummy[i];
	}
}
int main(int argc, char** argv)
{
	
	FILE *fp = fopen("data.txt", "r");
	float base=100;
	
	int n;
	char c[10];
	fgets(c, 10 , fp);
	n = atoi(c);
	printf("%d\n", n);
	float *init = malloc(n * sizeof(float));
	float *smooth = malloc(n * sizeof(float));
	
	int i=0,j=0;
	while(fgets(c, 10, fp)!=NULL)
	{
		if(j%2==0)
		{
			init[i] = atof(c);
			smooth[i] = atof(c);
			i++;
		}
		j++;
	}
	fclose(fp);
	
	int m = atoi(argv[1]);
	
	for(i=0; i<m; i++)
	{
		smoothing(init, smooth, base, n);
	}
	output(smooth,n);
	
	return 0;
}
