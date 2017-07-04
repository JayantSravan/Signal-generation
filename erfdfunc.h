//erfd(a, length/2, length, base, peak, dur);
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

int fred2(float *a, int i, int base, int length, float peak, float dur)
{
	i++;
	i = exponential2(a, i, peak, dur, length, base);
	return i;
}
//erfd(a, length/2, length, base, peak, dur);
int erfd(float *a, int i,int length, float base, float peak, float dur)
{
	int j=i;
	i = fred2(a, i,base, length, peak, dur);
	return i;
}

