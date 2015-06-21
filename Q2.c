/* CS261- Assignment 1 - Q.2*/
/* Name: Drea McClure
 * Date: 01/10/2015
 * Solution description: This program demonstrates pass by value and pass
 * by reference differences.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/

	*a = *a * 2;
    
    /*Set b to half its original value*/

	*b = *b / 2;
    
    /*Assign a+b to c*/

	c = *a + *b;
    
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5;
	int y = 6;
	int z = 7;
	int temp;
    
    /*Print the values of x, y and z*/
	printf("x = %d y = %d z = %d\n", x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
	temp = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
	printf("Return value from foo = %d\n", temp);
    
    /*Print the values of x, y and z again*/
	printf("x = %d y = %d z = %d\n", x, y, z);
 
    /*Is the return value different than the value of z?  Why?*/
	printf("No, the return value is not different for z because it was passed by value.");

    return 0;
}
    
    
