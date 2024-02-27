#include <stdio.h>

#define NUM_OF_STUDENTS 5
#define YEAR 2023
#define CLASS 86


int REGISTERNUMBER[NUM_OF_STUDENTS];      // RN 
float WRITENEXERCISE[NUM_OF_STUDENTS][4];  // WE
float SUMWE[NUM_OF_STUDENTS];       // sum of written exercise
int NUMBERWE[NUM_OF_STUDENTS];      //number of exercise that delivered     
int PARTICIPATIONRIGHT[NUM_OF_STUDENTS] = {0};    // PAR
float WRITENEXAMS[NUM_OF_STUDENTS][2] = {0}; 
float FINALGRADE[NUM_OF_STUDENTS] = {0};     


void input_data();  
void exams();       
void input_grade(); 
void final_grade(); 
void print_data();  

int main()
{
    input_data(); 
    exams();      
	print_data(); 
    input_grade();
    final_grade(); 
    print_data();  
    return 0; 
}


void input_data()
	{
	for (int i = 0; i < NUM_OF_STUDENTS; i++ ) {
	printf("RN %dst student:",i + 1);
	scanf("%d",&REGISTERNUMBER[i]);
	while (REGISTERNUMBER[i] < 1000 || REGISTERNUMBER[i] > 10000) 
	{
		printf("Wrong Value!\n");
		printf("RN %dst student:",i + 1);
		scanf("%d",&REGISTERNUMBER[i]);
	} 
	for (int j = 0; j < 4; j++) {
	printf("Grade of %d Exercise(0-10 or -1 for not submitting):",j + 1);
	scanf("%f", &WRITENEXERCISE[i][j]);
	while (&WRITENEXERCISE[i][j] > -1 || &WRITENEXERCISE[i][j] < 10) 
	{
		printf("Wrong Value!");
		printf("Grade of %j exercise(0-10 or -1 for not submitting):");
		scanf("%f", &WRITENEXERCISE[i][j]);
	}
	}
	}
}


void exams()
{
	for (int i = 0; i < NUM_OF_STUDENTS;i++) 
	{	
		SUMWE[i] = 0;
        NUMBERWE[i] = 0;
		for (int j = 0; j < 4; j++) {
			if (WRITENEXERCISE[i][j] != -1) {
				SUMWE[i] = SUMWE[i] + WRITENEXERCISE[i][j];
				NUMBERWE[i] = NUMBERWE[i] + 1;
			}
		}
	    if (SUMWE[i] >= 20 && NUMBERWE[i] >= 3) {
            PARTICIPATIONRIGHT[i] = 1;
        }
	}
}


void input_grade()
{
	    for (int i = 0; i < NUM_OF_STUDENTS;i++) {
		if (PARTICIPATIONRIGHT[i] == 1) {
		printf("Give grade of the Final Exam (0-10) for the student with RN %d: ",REGISTERNUMBER[i]);
		scanf("%f",&WRITENEXAMS[i][0]);
		}
		}
		printf(" \n");
		for  (int i = 0; i< NUM_OF_STUDENTS; i++) {
				if (PARTICIPATIONRIGHT[i] == 1 && WRITENEXAMS[i][0] < 5 ) {
		printf("Give grade of the repeat examinations (0-10) for the student with RN %d: ",REGISTERNUMBER[i]);
		scanf("%f",&WRITENEXAMS[i][1]);
		}
		}
}	

void final_grade()
{	
	float sum;
    for  (int i = 0; i< NUM_OF_STUDENTS; i++) {
		sum = 0;
			if ( WRITENEXAMS[i][0] >= 5 || WRITENEXAMS[i][1] >= 5) {
				for (int y = 0; y < 4; y++) {
					if (WRITENEXERCISE[i][y] != -1) {
						sum =  sum + WRITENEXERCISE[i][y];
					}
				}
				if ( WRITENEXAMS[i][0] >= 5 ) {
					FINALGRADE[i] =  (0.3 * ( sum / 4)) + (0.7 * WRITENEXAMS[i][0]);
				} else {
					FINALGRADE[i] =  (0.3 * ( sum / 4)) + (0.7 * WRITENEXAMS[i][1]);
				}
			}
	}
}


void print_data()
{
	printf(" \n");
	printf("---- GRADING ( Student Year %d - %d - Class: %d \n) -----",YEAR , YEAR + 1,CLASS);
	printf(" \n");
	printf("RN | RE1 | RE2 | RE3 | RE4 | PAR | Final | Repeat | Grade |\n");
	for (int i = 0; i < NUM_OF_STUDENTS;i++) {
		if ( WRITENEXAMS[i][0] != 0 && WRITENEXAMS[i][1] != 0 && FINALGRADE[i] != 0) {
		printf("%d | %.1f | %.1f | %.1f | %.1f | %d | %.1f | %.1f | %.2f |\n",REGISTERNUMBER[i],WRITENEXERCISE[i][0],WRITENEXERCISE[i][1],WRITENEXERCISE[i][2],WRITENEXERCISE[i][3],PARTICIPATIONRIGHT[i],WRITENEXAMS[i][0],WRITENEXAMS[i][1],FINALGRADE[i]);
		}else if ( WRITENEXAMS[i][0] == 0) {
			printf("%d | %.1f | %.1f | %.1f | %.1f | %d |   |   |   |\n",REGISTERNUMBER[i],WRITENEXERCISE[i][0],WRITENEXERCISE[i][1],WRITENEXERCISE[i][2],WRITENEXERCISE[i][3],PARTICIPATIONRIGHT[i]);
		}else {
			printf("%d | %.1f | %.1f | %.1f | %.1f | %d | %.1f |   | %.2f |\n",REGISTERNUMBER[i],WRITENEXERCISE[i][0],WRITENEXERCISE[i][1],WRITENEXERCISE[i][2],WRITENEXERCISE[i][3],PARTICIPATIONRIGHT[i],WRITENEXAMS[i][0],FINALGRADE[i]);
		}
	}

}

