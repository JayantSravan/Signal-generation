int lorentzian(float* a, int j, float base, int length)
{
	int peak = base + (0.3 + ((float)(rand()%5))/10)*base;
	float gamma = 5 + (float)(rand()%100000)/100000;
	float dur = 5 + rand()%10;
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
