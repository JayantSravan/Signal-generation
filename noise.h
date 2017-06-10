
void noise(float *a, int length)
{
	int i=0;
	for(i=0; i<length; i++)
	{
		int error= -1 * sqrt(a[i]) + rand()%(int)(2*sqrt(a[i]));
		a[i]+=error;
	}
}
