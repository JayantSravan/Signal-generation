int lorentzian(float* a, int j, float base, int length)
{
	int peak = base + base/10 + rand()%((int)base/2);
	float gamma = 1/(3.1412 * (peak - (float)base));
	int i;
	int k= j+3;
	for(i=0; i<7 && i+j<length; i++)
	{
		a[i+j] =  (float)base + (peak - (float)base)*((gamma* gamma)/(((float)i +j - k)*((float)i + j - k) + (gamma*gamma)));
	}
	return i+j;
}
