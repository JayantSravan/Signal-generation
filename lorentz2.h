void lorentzian(float* a, int j,float base, int length)//float peak, float mid, float dur, int length, int base)
{

	//printf("%f\n", gamma);
	float peak = base + base/10 + rand()%((int)base/2);
	float dur = 5 + rand()%10;
	float mid = dur/2;
	int i;
	for(i=0; i<length; i++)
	{
		a[i] =  (float)base + ((peak-base)*dur)/((i-mid)*(i-mid)+dur);
	}
}

