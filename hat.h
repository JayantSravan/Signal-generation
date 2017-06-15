int tophat(float *a, int j, float base, int length)
{
	int i;
	int peak = base + (0.1 + ((float)(rand()%6))/10)*base;
	int dur = 20 + rand()%20;
	for(i=0; i<dur && i+j<length; i++)
	{
		a[i+j] = peak;
	}
	return j+i;
}
