//tophat(a, peak, dur, length/2, length, base);
int tophat(float *a,float peak,float dur, int j, int length, float base)
{
	int i;

	for(i=0; i<dur && i+j-(int)dur/2<length; i++)
	{
		a[i+j - (int)dur/2] = peak;
	}
	return j+i;
}
