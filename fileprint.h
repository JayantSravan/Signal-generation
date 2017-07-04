void output (float *a,int length, int type)
{
	FILE *fp = fopen("data.txt", "w");
	fprintf(fp, "%d %d\n", length, type);
	int i;
	for(i=0; i<length; i++)
	{
		fprintf(fp, "%f\n", a[i]);
	}
	
	fclose(fp);
}
