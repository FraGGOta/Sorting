#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *arr, int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
        while (arr[j] > pivot) {
		j--;
	}

        if (i <= j) {
        	tmp = arr[i];
        	arr[i] = arr[j];
        	arr[j] = tmp;
        	i++;
        	j--;
        }
    }
    return i;
}

void quickSort(int *arr, int left, int right) 
{
	int index = partition(arr, left, right);
	if (left < index - 1) {
		quickSort(arr, left, index - 1);
	}
	if (index < right) {
		quickSort(arr, index, right);
	}
}

void insertion(int *arr, int n)
{
	int j, point;
	for(int i = 1; i <= n - 1; i++) {
	    point = arr[i];
	    j = i;
		while(j > 0 && arr[j - 1] > point) {
		    arr[j] = arr[j - 1];
		    j = j - 1;
		}
		arr[j] = point;
	}
}

void bubbleSort(int* arr, int n)
{
	int tmp;
	for (int j = 0; j < n; ++j) {
		for(int i = 0;  i < n - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
			    tmp = arr[i + 1];
			    arr[i + 1] = arr[i];
			    arr[i] = tmp;
			}
		}
	}
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;


	if (largest != i) {
		int tmp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = tmp;
		heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n-1; i >= 0; i--) {
		int tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		heapify(arr, i, 0);
	}
}

int findMax(int *arr, int n)
{
	int max = arr[0];

	for( int i = 1; i < n; i++) {

		if(max < arr[i]) {
			max = arr[i];
		}
	}
    return max;
}

void countSort(int *arr, int n, int max)
{
	int *y;
	y = (int*)malloc((max + 1) * sizeof(int));
	int f = 0;

	for (int i = 0; i < max + 1; ++i) {

	y[i] = 0;
	}

	for(int i = 0; i < n; i++) {
		y[arr[i]]++;
	}

	for(int i = 0; i < max + 1; i++) {
		for (int j = 0; j < y[i]; ++j) {
			arr[f] = i;
			f++;
		}
	}
}
