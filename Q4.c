/* CS261- Assignment 1 - Q.4*/
/* Name: Drea McClure
 * Date: 01/11/2015
 * Solution description: This program sorts an array of student structures in
 * ascending order based on their scores.
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/

		struct student *i;
		struct student *j;
		struct student temp;

		for(i = students; i < students + n; i++){
			for(j = i + 1; j < students + n; j++){
				if((struct student*)j->score < (struct student*)i->score){
					temp = *j;
					*j = *i;
					*i = temp;
				}
			}
		}
}

struct student* allocate() {
     /* Allocate memory for ten students */

	struct student *students = malloc(10 * sizeof(struct student));

	/* Return pointer to allocated memory */

	return students;

}

void initializeSeed() {
	srand(time(0));
}

int randomNumber(int max) {
	return (rand() % max);
}

void initStudent(int id, int score, struct student *s)
{
	s->id = id;
	s->score = score;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

	int id[10];
	int score[10];

	int i;
	int j;
	int used = 0;  // 0 is false, 1 is true
	int tempNumber;

	for (i=0;i<10;i++) {

		while (used==0) {
			/* get random number */

			tempNumber = randomNumber(10) + 1; /* have to add 1 to call to get 1 thru 10 */

			/* walk thru the student array and check to see if random number is used */

			for (j=0;j<10;j++) {
				if (id[j] == tempNumber) {
					used = 1;
				}
			}

			if (used!=1) {
				break; /* if number is not used, stop checking and break out of while loop */
			} else {
				used = 0; /* keep on checking */
			}
		}

		used = 0;  /* reset the used check flag */

		id[i] = tempNumber;
	}

	for (i=0;i<10;i++) {
		tempNumber = randomNumber(101); /* do 101 because the randomNumber will return 0 to max-1 */
		score[i]= tempNumber;
	}

	/* now add student id and score to each pointer struct */

	for (i=0;i<10;i++) {
		initStudent(id[i], score[i], &students[i]);
	}

}

void printStudent(struct student s)
{
	printf("Student id is %d\n", s.id);
	printf("Student score is %d\n", s.score);
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

	int i;

	for (i=0;i<10;i++){
		printStudent(students[i]);
	}

}


void deallocate(struct student *stud){
     /*Deallocate memory from stud*/

	free(stud);
}

int main(){
    /*Declare an integer n and assign it a value.*/
	int n = 10;
	struct student *stud = 0;
    
    /*Allocate memory for n students using malloc.*/
	stud = allocate();
    
    /*Generate random IDs and scores for the n students, using rand().*/
	generate(stud);
    
    /*Print the contents of the array of n students.*/
	printf("Student list before sort \n");
	output(stud);

    /*Pass this array along with n to the sort() function*/
	 sort(stud, n);
    
    /*Print the contents of the array of n students.*/
	 printf("Student list after sort \n");
	 output(stud);

	 /*call deallocate*/
	 deallocate(stud);
    
    return 0;
}
