#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mergesort.h"

bool check_sorted(int data[],int size,int from,int to){
	for(int i=from+1;i<to&&i<size;i++){
		if(data[i-1]>data[i]){
			return false;
		}
	}
	return true;
}

void print_data_interval(int data[], int size,int from,int to){
    printf("[");
    for(int i=from;i<to&&i<size;i++){
        printf("%d,",data[i]);
    }
    printf("]\n");
}

void print_data(int data[],int size){
    print_data_interval(data,size,0,size);
}

/*! @brief Array-Rotier-Funktion
@param[in,out] data Array, auf dem die Rotation durchgeführt wird
@param[in] from Anfang der Verschiebung
@param[in] to Ende der Verschiebung
Verschiebt die Position aller Werte von "from"(einschließlich) bis "to"(nicht einschließlich) um 1,
 und der Wert von "to" kommt an den Anfang zu "from"*/
void rotate(int data[], int from, int to){
	if(from>=to){
		return;
	}
	int swap = data[to];
    for(int pos=to;pos>from;pos--){
        data[pos]=data[pos-1];
    }
    data[from]=swap;
}

/*! @brief In-place Mergesort.
@param[in,out] data Array, das sortiert werden soll
@param[in] size Größe des Arrays
Sortieralgorithmus.
Vor jedem Durchlauf sind gleich große Stücke von aufeinanderfolgende Zahlen sortiert (im Sourcecode wird die Länge als "step" benannt).
Nach jedem Durchlauf sind die sortierten Stücke doppelt so groß.
Die sortierten Stücke werden paarweise zusammengeführt zu doppelt so großen sortierten Stücken.
Dies geschieht durch 2 Pointer(im Sourcecode "i" und "pointer" genannt), die am Anfang von 2 aufeinanderfolgenden Stücken starten.
Wenn der Wert des 1. Pointers kleiner ist als der des 2. Pointers, dann bewegt der 1. Pointer sich weiter.
Wenn der Wert des 2. Pointers kleiner ist, dann wird er mit der funktion rotate() vor den Wert des 1. Pointer verschoben,
und beide Pointer bewegen sich weiter.
Dies geschieht bis die Pointer sich eingeholt haben oder der 2. Pointer seinen Bereich verlässt*/
void mergesort(int data[], int size){
    for(int step=1;step<=size;step*=2){
        for(int part=0;part<size;part+=step*2){
            int pointer=part+step;
            if(pointer>=size){continue;}
            for(int i=part;i<pointer&&i<size;i++){
                if(data[pointer]<data[i]){
                    rotate(data,i,pointer);
                    pointer++;
					if(pointer>=size||pointer>=part+step*2){break;}
				}
            }
        }
    }
}

void test_sorting(){
	const int size=50;
    int data[size];
    for(int i=0;i<size;i++){
        data[i]=rand()%100;
    }
	printf("vorher:");
    print_data(data,size);
    mergesort(data,size);
	printf("nachher:");
    print_data(data,size);
	printf("korrekt sortiert:%s\n",check_sorted(data,size,0,size)?"ja":"nein");
}