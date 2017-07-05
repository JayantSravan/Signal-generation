int exponential(float *a, int i, int peak, int lag, int length, float base)
{
	
	float diff = (peak - base);
	float factor = 0.00;
	while((float)(diff) > (factor * pow(2.72 , ((float)(lag)/100) *lag)))
	{
		factor+=0.02;
	}
	int j=lag-1;
	a[i] = base + factor * pow(2.72, ((float)(lag)/100)*j);
	j--; i++;
	while(i<length && a[i-1]>(1.001)*base)
	{
		
		a[i] = base + factor * pow(2.72, ((float)(lag)/100)*j);
		i++;
		j--;
	}
	return i;
}

int fred(float *a, int i, int length, float base, float peak, float dur)
{
	i++;
	
	i = exponential(a, i+40, peak, dur, length, base);
	return i;
}

