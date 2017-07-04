//gaussian(a, peak, length/2, dur, length, base);
int gaussian(float* arr,float peak, int j, float dur, int length, float base)
{
	int i=0;
	float c = dur;
	float b = 3* c;
	float a = peak;
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
