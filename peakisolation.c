#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
int peaks[100][2];
int main()
{
	FILE *fp = fopen("data.txt", "r");
	float base=99.5;
	
	int n;
	char c[10];
	fgets(c, 10 , fp);
	n = atoi(c);
	printf("%d\n", n);
	float *a = malloc(n * sizeof(float));
	int i=0,j=0;
	while(fgets(c, 10, fp)!=NULL)
	{
		if(j%2==0)
		{
			a[i] = atof(c);
			i++;
		}
		j++;
	}
	fclose(fp);
	int stride = 8;
	int l=0, r=stride-1;
	int p=0;
	j=0;
	while(j < n)
	{
		if(a[j] > 1.115 * base)
		{
			printf("%d->",l);
			peaks[p][0]=l;
			int r=j;
			while(a[r] > 1.1 * base)
			{
				r+=stride;
			}
			printf("%d\n", r);
			peaks[p][1]=r;
			p++;
			l=r;
			j=r+stride;
		}
		else
		{
			l=j;
			j++;
		}
		
	}	
	
	rmdir("peaks");
	mkdir("peaks", ACCESSPERMS);
	for(i=0; i<p; i++)
	{
		char buff[20];
		snprintf (buff, sizeof(buff), "%d",i);
		char ext[5]= ".txt";
		strcat(buff, ext);
		char dest[20] = "peaks/";
		strcat(dest, buff);
		fp=fopen(dest, "w");
		
		int m = peaks[i][1] - peaks[i][0] + 1;
		snprintf (buff, sizeof(buff), "%d",m);
		fputs(buff, fp);
		fputs("\n", fp);
		for(j=peaks[i][0]; j<peaks[i][0] + m; j++)
		{
			snprintf (buff, sizeof(buff), "%f", a[j]);
			fputs(buff, fp);
			fputs("\n", fp);
		}
		fclose(fp);
	}
	return 0;
}
