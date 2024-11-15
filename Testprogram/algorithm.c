#include "algorithm.h"

//
// Private
//

static void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

static int partition(int a[], int low, int high){
	// Pivot
	int pivot = a[high];

	int i = low - 1;

	for(int j = low; j <= high - 1; j++){
		if(a[j] < pivot){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], & a[high]);
	return i + 1;
}

static void quick_sort_recursive(int a[], int low, int high) {
	if (low < high){
		int pi = partition(a, low, high);
		quick_sort_recursive(a, low, pi-1);
		quick_sort_recursive(a, pi + 1, high);
	}
}

//
// Public
//
void bubble_sort(int *a, int n)
{
    for(int i= 0; i < n; i++){
        for(int j=0; j < n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp= a[j];
                a[j]= a[j+1];
                a[j+1]= temp;
            }
        } 
    }
	// TODO: bubble sort
}

void insertion_sort(int *a, int n)
{
    for(int i = 1; i < n; i++){
        int key = a[i]; //key är andra elementet
        int j = i-1; //första elementet

        while(j>= 0 && a[j] > key){
        a[j+1] = a[j]; //key = a[i] jämför key(andra element) med första element, key = första element
        j--; //j = j-1, --j
        
        }
        a[j+1] = key;
        
    }
	// TODO: insertion sort
}

void quick_sort(int *a, int n)
{
	quick_sort_recursive(a, 0, n - 1);
}

bool linear_search(const int *a, int n, int v)
{
    for(int i = 0; i< n; i++){
        if(a[i] == v){
            return true;
        }
	return false; // TODO: linear search
    }
}

bool binary_search(const int *a, int n, int v)
{
	return false; // TODO: binary search
}
