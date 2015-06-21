/* CS261- Assignment 1 - Q.5*/
/* Name: Drea McClure
 * Date: 01/11/2015
 * Solution description: This program takes in a string and changes it
 * so that every other character alternates from upper to lower case.
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/

	/*create a counter*/

	int i = 0;

	int flag = 1;  /* flag to check to change to upper or lower case */
				   /* 1 is upper case 0 is lower case */

	/* decided to use the built in c library toupper and tolower functions
	 * referenced toupper code tutorial from:
	 * http://www.tutorialspoint.com/c_standard_library/c_function_toupper.htm
	 */

	while(word[i]){
		if (flag==1) {
			word[i] = toupper(word[i]);
			flag = 0;
		} else if (flag==0) {
			word[i] = tolower(word[i]);
			flag = 1;
		}

		i++;
	}
}

int main(){
    /*Read word from the keyboard using scanf*/

	char inputString[255];

	printf("Please enter in a word with no spaces that is less than 255 characters: ");
	scanf("%s", &inputString);

	printf("You have entered: %s \n", &inputString);
    
    /*Call sticky*/

	sticky(&inputString);

    /*Print the new word*/

	printf("Sticky changed to: %s", &inputString);

    
    return 0;
}
