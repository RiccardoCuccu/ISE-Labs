#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	FILE *flog;
	float caratteri[100], pacchetti[100];
	float temp = 0, media = 0, varianza = 0;
	int i = 0, j = 0;
	
	if((flog=fopen("log.txt", "rt"))==NULL) {
		printf("Errore nell'apertura del file\n");
		exit(1);
	}
	
	while(!feof(flog)) {
		fscanf(flog,"%f\t%f\n", &caratteri[i], &pacchetti[i]);
		i++;
	}

	for(j=0; j<i; j++) {
		media += caratteri[j] * pacchetti[j];
	}

	//media = media/100;
	media = media/11;

	for(j=0; j<i; j++) {
		temp = caratteri[j] - media;
		varianza += pow(temp,2) * pacchetti[j];
	}

	//varianza = varianza/100;
	varianza = varianza/11;

	printf("Media: %f\nVarianza: %f\n", media, varianza);
	// Media: 10.454545
	// Varianza: 5.702480 
	
	fclose(flog);
	
	return 0;
}
