void output (float *a,int length)
{
	FILE *fp = fopen("data.txt", "w");
	fprintf(fp, "%d\n", length);
	int i;
	for(i=0; i<length; i++)
	{
		fprintf(fp, "%f\n", a[i]);
	}
	
	fclose(fp);
}
