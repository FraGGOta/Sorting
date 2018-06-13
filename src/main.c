#include "sorts.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main()
{
	int *arr; //Указатель на массив
	int n, sort; //Кол-во элементов в массиве, переменная для выбора сортировки
	clock_t start, end; //Время
	int choice; //Переменная для выбора заполенния массива
	int max;

	//Считываение количества элементов
	printf ("\nEnter the number of elements:\n\nEnter: ");
		scanf("%d",&n);

         //Выделение памяти для массива
	arr = (int*)malloc(n * sizeof(int));

	//Выбор заполнения массива
	printf("\nArray filling:\n\n1. Random numbers\n2. In ascending order\n3. In descending order\n\nSelect: ");
		scanf ("%d",&choice);

	if(choice == 1){
		srand(time(0));
		for (int i=0;i<n;i++) {
			arr[i]=rand()%1000-500;
		}
	}else if(choice == 2){
		for(int i=0;i<n;i++) {
			arr[i]=i+1;
		}
	}else if(choice == 3){
		for(int i=0;i<n;i++) {
			arr[i]=n-i;
		}
	}else {
		printf("\nError\n");
		return 0;
	}

	//Меню выбора сортировки
	printf("\nSORTS:\n\n1. QuickSort\n2. InsertionSort\n3. BubbleSort\n4. HeapSort\n5. CountingSort\n\nSelect sort: ");
		scanf("%d", &sort);

	if (sort == 1) {
		start = clock();
		quickSort(arr, 0, n-1);
		end = clock();
	} else if (sort == 2) {
		start = clock();
		insertion(arr, n);
		end = clock();
	} else if (sort == 3) {
		start = clock();
		bubbleSort(arr, n);
		end = clock();
	} else if (sort == 4) {
		start = clock();
		heapSort(arr, n);
		end = clock();
	} else if (sort == 5) {
		start = clock();
		max = findMax(arr, n);
		countSort(arr, n, max); 
		end = clock();
	} else {
		printf("\nError\n");
		return 0;
	}

	//Вычисление и вывод времени выполнения сортировки
	double timer = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nTime: %f sec.\n\n", timer);

	free(arr);

    return 0;
}
