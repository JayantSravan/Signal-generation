int gaussian(float* arr, int j, int base, int length)//, float a, float b, float c, int length, int base)
{
	int i=0;
	float c = 5 + rand()%10;
	float b = 3* c;
	float a = base + (0.3 + ((float)(rand()%5))/10)*base;
	int k;
	int p=0;
	for(i=0; i<length; i++)
	{
		arr[i] = arr[i] + (a - base) * pow( 2.72, -(i-j)*(i-j)/(2*c*c) );
		if(i>j && p==0 && arr[i]<= 1.001* base)
		{
			k=i;
			p=1;
		}
	}
	return k;
}
