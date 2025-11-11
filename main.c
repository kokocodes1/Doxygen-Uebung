/*!
@file main.c
@brief Dateien lesen und Median ausrechnen
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mergesort.h"

int count_numbers_in_file(char file_name[]){
	FILE *file;
	int count = 0;
	int disposable;

	file = fopen(file_name, "r");
	if (file == NULL) {
		printf("Error: Could not open file.\n");
		return -1;
	}

	while (fscanf(file, "%d", &disposable) != EOF) {
		count++;
	}

	fclose(file);
	return count;
}

/*! @brief Zahlen aus Datei in Array(DASS DIE RICHTIGE GRÖSSE HAT!!!) lesen
Vorsicht: Das Array, in das die Datei gelesen wird, muss die richtige Größe haben. Ermittelt wird sie von count_numbers_in_file.
@param[in] file_name Dateiname
@param[out] array Ausgabearray, muss die richtige Größe haben
@return 0 bei Erfolg, 1 wenn die Datei nicht gelesen werden konnte
*/
int fill_numbers_in_file(char file_name[], int array[]){
	FILE *file;
	int i = 0;

	file = fopen(file_name, "r");
	if (file == NULL) {
		printf("Error: Could not open file.\n");
		return 1;
	}

	while (fscanf(file, "%d", &array[i]) != EOF) {
		i++;
	}

	fclose(file);
	return 0;
}

int main(){
	char file_name[] = "data.txt";
	int size = count_numbers_in_file(file_name);
	if(size==-1){return 1;};
	printf("anzahl datensätze: %d \n",size);
	int* data= (int*) malloc(size * sizeof(int));
	int fill_success = fill_numbers_in_file(file_name,data);
	if(fill_success==1) {return 1;};
	printf("unsortierte Daten:");
	print_data(data,size);
	mergesort(data,size);
	printf("sortierte Daten:");
	print_data(data,size);
	float median;
	if(size%2==0){
		median=((float)data[size/2]+data[size/2-1])/2;
	} else{
		median=(float)data[(size-1)/2];
	}
	printf("median: %f\n",median);
	
	free(data);
}