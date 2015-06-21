/* CS261- Assignment 1 - Q.1*/
/* Name: Drea McClure
 * Date: 01/10/2015
 * Solution description: This program creates a structure of 10 student records,
 * and randomly assigns ids and scores to the students.  Finally, the average, min,
 * and max scores are calculated.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student {
	int id;
	int score;
};

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

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/

	int total = 0;
	float average;
	int min = 100;
	int max = 0;
	int i;

	for(i=0;i<10; i++){
		total = total  + students[i].score;
		/*calculating max*/
		if(students[i].score > max){
			max = students[i].score;
		}
		/*calculating min*/
		if(students[i].score < min){
			min = students[i].score;
		}
	}

	average = (float) total/10;

	printf("\nSummary:\n");
	printf("min score: %d \n", min);
	printf("max score: %d \n", max);
	printf("average score: %3.2f \n", average);
     
}

void deallocate(struct student *stud){
     /*Deallocate memory from stud*/

	free(stud);
}

int main(){
	// initialize random number seed

	initializeSeed();

    struct student *stud = 0;
    
    /*call allocate*/
    
    stud = allocate();

    /*call generate*/
    
    generate(stud);

    /*call output*/
    
    output(stud);

    /*call summary*/

    summary(stud);
    
    /*call deallocate*/

    deallocate(stud);

    return 0;
}
