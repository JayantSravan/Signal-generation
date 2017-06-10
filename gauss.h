int gaussian(float* arr, int j, int base, int length)//, float a, float b, float c, int length, int base)
{
	int i=0;
	float c = 5 + rand()%10;
	float b = 3* c;
	float a = base + base/10 + rand()%(base/10);
	for(i=0; (i+j)<length && i<6*c; i++)
	{
		arr[i+j] =  base + (a - base) * pow(2.72, -(i-b)*(i-b)/(2*(c*c)) );
	}
	return j+i;
}
