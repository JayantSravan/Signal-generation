int tophat(float *a, int j, float base, int length)// float peak, float dur, float mid, int length, int base)
{
	int i;
	int peak = base + base/10 + rand()%((int)base/2);
	int dur = 20 + rand()%20;
	//printf("%d\n",dur);
	for(i=0; i<dur && i+j<length; i++)
	{
		//printf("%d ", i);
		a[i+j] = peak;
	}
	//printf("\n");
	return j+i;
}
