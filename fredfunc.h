int exponential(float *a, int i, int peak, int lag, int length, int base)
{
	
	int diff = (peak - base);
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

int fred(float *a, int i, int base, int length)
{
	i++;
	int peak = base + (0.1 + ((float)(rand()%6))/10)*base;
	
	int dur;
	dur = 5 + rand()%15;
	
	i = exponential(a, i, peak, dur, length, base);
	return i;
}

