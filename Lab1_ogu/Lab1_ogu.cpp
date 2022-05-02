// Lab1_ogu.cpp: This file contains the "main" function. This is where the program starts and ends.

/*For each element of a given array of integers to determine the minimum number of bits,
sufficient to record this number.

Form an array, each element of which
will be equal to the number of bits required to store the corresponding element of the specified array*/

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

// global variables and identifiers with substitution
#define N 10


// initialize functions
void menu(int* arr, int array[N][2]);
void addArr(int* arr);
void fillArr(int* arr);
void printArr(int* arr);
void printArr(int* arr);
void makeBitsArr(int* arr, int array[N][2]);
void printArr(int i, int array[N][2]);
int numBits(int n);
void makeBitsArr(char s, int* arr, int array[N][2]);



int main()
{
	setlocale(LC_ALL, "Rus");
	int array[N];
	int array2[N][2];
	menu(array, array2);
	
	system("pause");
	return 0;
}


void menu(int* arr, int array[N][2]) {
	cout << "Ogu. Varinat 13. Task: \n";
	cout << "\t \"For each element of a given array of integers determine the minimum number of bits, \n ";
	cout << "sufficient to write this number. \n";
	cout << "\t Create an array, each element of which will be equal to the number of bits,";
	cout << "\n which is necessary to save the corresponding element of the specified array\"";
	while (true) {
		cout << "\n\nSelect operation:";
		cout << "\n Fill array \n \t 1 - Fill array with keyboard (" << N << " elements) \n \t 2 - Fill with random integers \ n Array with values of minimum number of bits needed to store number \n \t 3 - implementation option 1 \n \t 4 - implementation option 2" << endl;
		int k;
		cin >> k;
		switch (k) {
		case 1: addArr(arr);
			break;
		case 2: fillArr(arr);
			break;
		case 3: makeBitsArr(arr, array);
			break;
		case 4: makeBitsArr('s', arr, array);
			break;
		}
	}
}

//Fill in the array manually
void addArr(int* arr) {
	cout << "\nВведите значения в диапазоне от "<< INT_MAX << " до "<< INT_MIN <<"\n" << endl;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (temp <= INT_MAX && temp>= INT_MIN) {
			arr[i]=temp;
		}
	}
	printArr(arr);
}

//Fill array randomly (one-dimensional)
void fillArr(int* arr) {
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		//(b-a+1)+a
		arr[i] = rand()% 4294967296 - 2147483648;
	}
	printArr(arr);
}

//Print one-dimensional
void printArr(int* arr) {
	cout << "\nСформированный массив:" << endl;
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

//Print two-dimensional
void printArr(int i, int array[N][2]) {
	cout << "\nСформированный массив:" << endl;
	for (int i = 0; i < N; i++) {
		cout << "Число: " << array[i][0]<< " " << "Количество бит: " << array[i][1] << endl;
	}
	cout << endl << endl;
}



//Create a two-dimensional array from the number of the original array and the number of bits that this number occupies 1 option
void makeBitsArr(int* arr, int array[N][2]) {
	for (int i = 0; i < N; i++) {
		array[i][0] = arr[i];
		array[i][1] = numBits(arr[i]);
	}
	printArr(2, array);
}

//Calculate how many minimum bits per number you need
// & - AND
int numBits(int n)
{
	int count = 0;
	if (n == 0) {
		return 0;
	}
	for (int i = 0; i < 32; i++) {
		if ((1 << i) & n) {
			count = i;
		}
	}
	return ++count;
}



//Create a two-dimensional array from the number of the original array and the number of bits that this number occupies 2 option
void makeBitsArr(char s, int* arr, int array[N][2]) {
	for (int i = 0; i < N; i++) {
		array[i][0] = arr[i];
		if (arr[i]>0) {
			array[i][1] = floor(log2(arr[i])) + 1;
		}else if (arr[i] == 0 || arr[i] == -0) {
			array[i][1] = 0;
		}else {
			int temp = -arr[i];
			array[i][1] = 8*4;
		}
	}	
	printArr(2, array);
}

