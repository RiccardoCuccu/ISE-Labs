#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv[])
{
	FILE *flog;
	float caratteri, pacchetti;
	float temp = 0;
	float media = 0;
	float varianza = 0;
	int i = 0;
	int j = 0;
	
	float vettore_caratteri[100];
	float vettore_pacchetti[100];

	if((flog=fopen("log.txt", "rt"))==NULL) {
		printf("Errore nell'apertura del file");
		exit(1);
	}
	
	while(!feof(flog)) {
		fscanf(flog,"%f\t%f\n", &caratteri, &pacchetti);
		vettore_caratteri[i] = caratteri;
		vettore_pacchetti[i] = pacchetti;
		i++;
	}

	for(j=0; j<i; j++) {
		media += vettore_caratteri[j] * vettore_pacchetti[j];
	}

	//media = media/100;
	media = media/11;

	for(j=0; j<i; j++) {
		temp = vettore_caratteri[j] - media;
		varianza += pow(temp,2) * vettore_pacchetti[j];
	}

	//varianza = varianza/100;
	varianza = varianza/11;

	printf("Media: %f\nVarianza: %f\n", media, varianza);
	// Media: 10.454545                                                                                              
	// Varianza: 5.702480 
	
	fclose(flog);
	
	return 0;
}
