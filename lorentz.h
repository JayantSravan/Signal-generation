//lorentzian(a, peak, length/2, length, base,dur);
int lorentzian(float* a, float peak ,int j, int length, float base, float dur)
{
	float gamma = dur;
	int i;
	int k;
	int c=0;
	for(i=0 ; i<length; i++)
	{
		a[i] =  (float)a[i] + (peak - (float)base)*((gamma* gamma)/(((float)i - j )*((float)i - j) + (gamma*gamma)));
		if(i>j && c==0 && a[i] <= 1.005*base)
		{
			k=i;
			c=1;
		}
	}
	return k;
}
