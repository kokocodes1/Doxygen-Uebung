#ifndef MERGESORT_H
#define MERGESORT_H


bool check_sorted(int data[],int size,int from,int to);

void print_data_interval(int data[], int size,int from,int to);

void print_data(int data[],int size);

void rotate(int data[], int from, int to);

void mergesort(int data[], int size);

void test_sorting();

#endif