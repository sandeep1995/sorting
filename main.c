/*
* Sorting Algorithms in C
* @sandeepemon
*/
#include<stdio.h>
#include<stdlib.h>
#define max 20
/*
* Printing the Array
*/
void display(int a[], int n) {
	int i;
	printf("\nArray is: \n");
	for (i = 0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
/*
* Array Scanning
*/
void take_input(int a[], int n) {
	int i;
	printf("\nEnter Array\n");
	for (i = 0; i<n; i++) {
		printf("\na[%d]:  ", i);
		scanf("%d", &a[i]);
	}
}
/*
* Swap to positions
*/
void swap_position(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*
* Bubble Sort
*/
void bubble_sort(int a[], int n) {
	int i, j;
	take_input(a, n);
	display(a, n);
	for (i = 0; i<n; i++) {
		for (j = 0; j<n - i - 1; j++) {
			if (a[j]>a[j + 1]) { // if next value is smaller than bring it to front
				swap_position(&a[j + 1], &a[j]);
			}
		}
	}
	printf("\nAfter Sorting\n");
	display(a,n);
}

void modified_bubble_sort(int a[], int n) {
	int i, j, flag = 1; // default flag is 1
	take_input(a, n);
	display(a, n);
	for (i = 0; i<n&&flag == 1; i++) { // start outer loop only if flag = 1
		flag = 0; // set flag to 0
		for (j = 0; j<n - i - 1; j++) {
			if (a[j]>a[j + 1]) {
				flag = 1; // if there is any comparision then set flag = 1
				swap_position(&a[j + 1], &a[j]);
			}
		}
	}
	printf("\nAfter Sorting\n");
	display(a,n);
}

void selection_sort(int a[], int n) {
	int i, j, small = a[0], index_of_small = 0; // consider first element to be the smallest
	take_input(a, n);
	display(a, n);
	for (i = 0; i<n; i++) {
		for (j = i + 1; j<n; j++) {
			if (a[j] < small) { // finding the smallest element of the array and its index
				small = a[j];
				index_of_small = j;
			}
		}
		a[i] = small; // put smallest element in the first
		a[index_of_small] = a[i]; // replace the first element in the position of smallest element
		small = a[i + 1]; // set the just next element to small again
	}
	printf("\nAfter Sorting\n");
	display(a,n);
}

void inserntion_sort(int a[], int n) {
	int i, index, temp;
	take_input(a, n);
	display(a, n);
	for (i = 1; i <= n - 1; i++) { // loop will start from 1 as first element is already sorted
		index = i;
		while (index > 0 && a[index]<a[index - 1]) { // need to sort the left sub array
			swap_position(&a[index], &a[index - 1]);
			index--; // decreament the left sorted array index
		}
	}
	printf("\nAfter Sorting\n");
	display(a,n);
}

void merge(int a[], int l, int m, int h) {
	int i, j, k, size1 = m - l + 1, size2 = h - m;
	int subL[size1], subR[size2]; // initialize two temporary array
	for (i = 0; i<size1; i++) {
		subL[i] = a[l + i]; // copy everything to left temp array upto size1
	} 
	for (j = 0; j<size2; j++) {
		subR[j] = a[m + 1 + j]; // copy everything to right temp array upto size2
	}
	k = l, i = j = 0;
	while (i<size1 && j<size2) {
		if (subL[i] <= subR[j]) { // sort and fill in the main array
			a[k] = subL[i];
			k++;
			i++;
		}
		else {
			a[k] = subR[j];
			k++;
			j++;
		}
	}

	while (i<size1) { // fill the remaining numbers to the main array if any
		a[k] = subL[i];
		k++;
		i++;
	}
	while (j<size2) {
		a[k] = subR[j];
		k++;
		j++;
	}
}

void merge_sort(int a[], int l, int h) {
	int m;
	if (l < h)
	{
		m = (l + h) / 2;
		merge_sort(a, l, m);
		merge_sort(a, m + 1, h);
		merge(a, l, m, h);
	}
}

void quick_sort(int a[], int l, int h){
    int left, right, pivot_index;
    if(l<h){
        pivot_index = l;
        left = l;
        right = h;
        while(left<right){
            while(a[left]<=a[pivot_index] && left < h) // increament left if pivot element is larger than left one
                left++;
            while(a[right]>a[pivot_index]) // // decrease right if pivot element is smaller than right one
                right--;
            if(left<right){
                swap_position(&a[left],&a[right]); 
            }
        }
        swap_position(&a[right],&a[pivot_index]);
        quick_sort(a,l,right-1);
        quick_sort(a,right+1,h);
    }
}
int main() {
	int n,ch, a[max];
	printf("\nSORTING\nEnter Array Size: ");
	scanf("%d", &n);
    printf("\n1. BUBBLE SORT\n2. MODIFIED BUBBLE SORT\n3. SELECTION SORT\n4. INSERTION SORT\n5. MERGE SORT\n6. QUICK SORT\nEnter Your Choice: ");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        bubble_sort(a,n);
        break;
    case 2:
        modified_bubble_sort(a,n);
        break;
    case 3:
        selection_sort(a,n);
        break;
    case 4:
        inserntion_sort(a,n);
        break;
    case 5:
        take_input(a, n);
        display(a, n);
        merge_sort(a,0,n-1);
        display(a, n);
        break;
    case 6:
        take_input(a, n);
        display(a, n);
        quick_sort(a,0,n-1);
        display(a, n);
        break;
    default:
        printf("\nWrong Choice");
    }
	return 0;
    /*
    * Thank You
    * Other sorting algos will also be added here soon
    */
}
