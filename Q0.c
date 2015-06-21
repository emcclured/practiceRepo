/* CS261- Assignment 1 - Q. 0*/
/* Name: Drea McClure
 * Date: 01/09/2015
 * Solution description: Program with a function to print the value
 * of an integer pointed to by iptr, the address pointed to by iptr,
 * and the address of iptr itself.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("Value pointed to by iptr: %d\n",*iptr);
     
     /*Print the address pointed to by iptr*/
	printf("Address pointed to by iptr: %x\n", &iptr);
     
     /*Print the address of iptr itself*/
	printf("Address pf the iptr itself: %x\n", iptr);

}

int main(){
    
    /*declare an integer x*/
	int x;
    
    /*print the address of x*/
	printf("The address of x: %x\n", &x);
    
    /*Call fooA() with the address of x*/
	fooA(&x);
    
    /*print the value of x*/
    printf("The value of x: %d\n", x );
    
    return 0;
}
