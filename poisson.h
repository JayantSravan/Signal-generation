
long double poisson (double lambda)
{
	double l;
	l = exp(-lambda);
	long double p =1;
	long double k = 0;
	do
	{
		double u = (double)(rand()%RAND_MAX)/RAND_MAX;
		p = p*u;
		k = k+1;
	}
	while(p > l);
	return k-1;
}

void poissonNoise(float* a, int length)
{
	int i;
	for(i=0; i<length; i++)
	{
		long double k = (long double)a[i];
		a[i] = poisson(k);
	}
}
