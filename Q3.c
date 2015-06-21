/* CS261- Assignment 1 - Q.3*/
/* Name: Drea McClure
 * Date: 01/11/2015
 * Solution description: Program sorts a set length, pointer array with random numbers
 * in ascending order.
 */
 
#include <stdio.h>

void initializeSeed() {
	srand(time(0));
}

int randomNumber(int max) {
	return (rand() % max);
}

void sort(int* number, int n){
    /*Sort the given array number , of length n*/

	int *i;
	int *j;
	int temp;
	for(i = number; i < number + n; i++){
		for(j = i + 1; j < number + n; j++){
			if(*j < *i){
				temp = *j;
				*j = *i;
				*i = temp;
			}
		}
	}
}

int main(){
	int i;

    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
	int *numbers = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
	initializeSeed();

	for(i =0; i < n; i ++){
		numbers[i] = randomNumber(100);/*Will return a number from 0 to 99*/
	}

    /*Print the contents of the array.*/

	for(i = 0; i < n; i ++){
		printf("Contents of array[%d]: %d\n", i, numbers[i]);
	}

    /*Pass this array along with n to the sort() function of part a.*/

	sort(numbers,n);
    
    /*Print the contents of the array.*/

	for(i = 0; i < n; i ++){
			printf("Contents of sorted array[%d]: %d\n", i, numbers[i]);
	}

    return 0;
}
