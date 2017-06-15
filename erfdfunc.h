int exponential2(float *a, int i, int peak, int lag, int length, int base)
{
	
	int diff = (peak - base);
	float factor = 0.00;
	while((float)(diff) > (factor * pow(2.72 , ((float)(lag)/100) *lag)))
	{
		factor+=0.02;
	}
	int j= 0 ;
	while( factor * pow(2.72, (float)(lag)/100*j) > 0.001 * (float)base)
	{
		j--;
	}
	
	while(i<length && a[i-1] < peak )
	{
		
		a[i] = base + factor * pow(2.72, ((float)(lag)/100)*j);
		i++;
		j++;
	}
	return i;
}

int fred2(float *a, int i, int base, int length)
{
	i++;
	int peak = base + (0.3 + ((float)(rand()%5))/10)*base;
	int dur = 5 + rand()%10;
	i = exponential2(a, i, peak, dur, length, base);
	return i;
}

int erfd(float *a, int i, float base,int length)//, int peak, int dur)
{
	int j=i;
	i = fred2(a, i,base, length);
	return i;
}

