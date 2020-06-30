#include <stdio.h>
#include <stdlib.h>

int fir(int *samples, int *coefficients, int numCoefficients);

int main(int argc, char **argv[])
{
	FILE *fsamp, *fcoef, *fout;
	int campione, coefficiente;
	int numCoefficients = 10;
	int i = 0;
	int j = 0;
	
	int campioni[numCoefficients];
	int coefficienti[numCoefficients];
	
	int *samples = &campioni[0];
	int *coefficients = &coefficienti[0];
	
	if((fsamp=fopen("samples.txt", "rt"))==NULL) {
		printf("Errore nell'apertura del file");
		exit(1);
	}
	
	if((fcoef=fopen("coefficienti.txt", "rt"))==NULL) {
		printf("Errore nell'apertura del file");
		exit(1);
	}
	
	if((fout=fopen("output.txt", "wt"))==NULL) {
		printf("Errore nell'apertura del file");
		exit(1);
	}
	
	while(!feof(fsamp)) {
		fscanf(fsamp,"%d\n", &campione);		// legge i campioni
		campioni[i] = campione;
		printf("Campione: %d\n", campioni [i]);
		i++;
	}
	
	while(!feof(fcoef)) {
		fscanf(fcoef,"%d\n", &coefficiente);		// legge i coefficienti
		coefficienti[j] = coefficiente;
		printf("Coefficiente: %d\n", coefficienti[j]);
		j++;
	}

	int output = fir(samples, coefficients, numCoefficients);

	fprintf(fout,"%d\n", output);				// scrive sul file di output
	//printf("%d", output);
	
	fclose(fsamp);
	fclose(fcoef);
	fclose(fout);
	
	return 0;
}

int fir(int *samples, int *coefficients, int numCoefficients)
{
	int temp = 0;
	for (int i=0; i < numCoefficients; i++) {
		temp += samples[i] * coefficients[i];
	}
	return temp;
}
