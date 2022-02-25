//Librerías que utilizaremos
#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>

//Namespace
using namespace std;

//Funciones 

//Función Selection Sort fue tomada por la página GeeksForGeeks.com
// C++ program for implementation of selection sort
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// Swap the found minimum element with the first element
		swap(&arr[min_idx], &arr[i]);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//Función Bubble Sort fue tomada por la página GeeksForGeeks.com

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)	
	
	// Last i elements are already in place
	for (j = 0; j < n-i-1; j++)
		if (arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
}

//Función QuickSort fue tomada por la página de GeeksForGeeks.com

/* C++ implementation of QuickSort */
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

//Función MergeSort fue tomada por la página de GeeksForGeeks.com

void merge(int array[], int const left, int const mid, int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
  
    // Create temp arrays
    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end){
    if (begin >= end)
        return; // Returns recursively
  
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


//Generaremos valores aleatorios [0,250]
void vector_aleatorio(int vect[], int n){

srand(time(NULL));

for(int i=0; i<n; i++){
	vect[i]= rand()%251;
}

}	
	


int main(){
	
//Definiremos tamaños
int tamanios[]= {100,500,1000,1500,2000,2500};
int tamanios1=6;
int replicas=15;

//Repeticiones que utilizaremos

double tiempoSelection[15][6];
double tiempoBubble[15][6];
double tiempoQuick[15][6];
double tiempoMerge[15][6];

clock_t t_0;
int*vect;

//Crear indicador

for (int indicador=1; indicador<5; indicador++){
	if (indicador==1){ 
	for (int i=0; i<tamanios1; i++){
		for (int j=0; j<replicas; j++){
			
			vect = new int[tamanios[i]];
			vector_aleatorio(vect,tamanios[i]);
			t_0= clock(); 
			selectionSort(vect,tamanios[i]);
			
			tiempoSelection[j][i]= (clock()-t_0) / (double) CLOCKS_PER_SEC;
			
		}
	}
	
ofstream my_file("selectionSort.csv");

for(int i=0; i<tamanios1; i++){
	my_file << tamanios[i] << ",";	
}

my_file << endl;
       
       for (int i=0; i<replicas; i++){ 
         for (int j=0; j<tamanios1; j++){
         	my_file << tiempoSelection [i][j]<< ",";
         	
		 }
		 
		 my_file << endl;
		 
	   }
	   
	   my_file.close();
	   
	
	}
	
if (indicador==2){ 
	for (int i=0; i<tamanios1; i++){
		for (int j=0; j<replicas; j++){
			
			vect = new int[tamanios[i]];
			vector_aleatorio(vect,tamanios[i]);
			t_0= clock(); 
			bubbleSort(vect,tamanios[i]);
			
			tiempoBubble[j][i]= (clock()-t_0) / (double) CLOCKS_PER_SEC;
			
		}
	}
	
ofstream my_file("BubbleSort.csv");

for(int i=0; i<tamanios1; i++){
	my_file << tamanios[i]<< ",";	
}

my_file << endl;
       
       for (int i=0; i<replicas; i++){ 
         for (int j=0; j<tamanios1; j++){
         	my_file << tiempoBubble [i][j]<< ",";
         	
		 }
		 
		 my_file << endl;
		 
	   }
	   
	   my_file.close();
	   
	
	}
	
if (indicador==3){ 
	for (int i=0; i<tamanios1; i++){
		for (int j=0; j<replicas; j++){
			
			vect = new int[tamanios[i]];
			vector_aleatorio(vect,tamanios[i]);
			t_0= clock(); 
			quickSort(vect,0,tamanios[i]-1);
			
			tiempoQuick[j][i]= (clock()-t_0) / (double) CLOCKS_PER_SEC;
			
		}
	}
	
ofstream my_file("QuickSort.csv");

for(int i=0; i<tamanios1; i++){
	my_file << tamanios[i]<< ",";	
}

my_file << endl;
       
       for (int i=0; i<replicas; i++){ 
         for (int j=0; j<tamanios1; j++){
         	my_file << tiempoQuick [i][j]<< ",";
         	
		 }
		 
		 my_file << endl;
		 
	   }
	   
	   my_file.close();
	   
	
	}
	
if (indicador==4){ 
	for (int i=0; i<tamanios1; i++){
		for (int j=0; j<replicas; j++){
			
			vect = new int[tamanios[i]];
			vector_aleatorio(vect,tamanios[i]);
			t_0= clock(); 
			mergeSort(vect,0,tamanios[i]-1);
			
			tiempoMerge[j][i]= (clock()-t_0) / (double) CLOCKS_PER_SEC;
			
		}
	}
	
ofstream my_file("MergeSort.csv");

for(int i=0; i<tamanios1; i++){
	my_file << tamanios[i]<< ",";	
}

my_file << endl;
       
       for (int i=0; i<replicas; i++){ 
         for (int j=0; j<tamanios1; j++){
         	my_file << tiempoMerge[i][j]<< ",";
         	
		 }
		 
		 my_file << endl;
		 
	   }
	   
	   my_file.close();
	   
	
	}	
	
	
}
	
}






