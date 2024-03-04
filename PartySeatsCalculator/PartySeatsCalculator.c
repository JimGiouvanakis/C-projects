#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

#define N 5
#define BONUS 50

/*Ορισμός δομής party*/
struct party {
    int id;
    char name[25];
    int votes;
    float percentage;
    int seats;
};


int answer = 0;
int winner;
struct party election_results [N];
int votes_in_total = 0;

void vote_update (){
 for (int i = 0; i < N; i++) {
		int votes = -1;
		while ( votes < 0) {
		printf("Give the amount of valid votes for the party with code %d \n",election_results[i].id);
		scanf("%d",&votes);
		}
		election_results[i].votes = election_results[i].votes + votes;
		votes_in_total = votes_in_total + votes;		
 }
		for (int i = 0; i < N; i++) {
 		election_results[i].percentage = (1.0 * election_results[i].votes / votes_in_total) * 100;
		}
}

int winning_party(){
	int max = -1;
	int position;
	for (int i = 0; i < N; i++) {
		if (election_results[i].votes > max ) {
			max = election_results[i].votes ;
			position = i;
		}
	}
	return position;
}

void seat_distribution(){
	float total_percentage = 100;
	float temp,decimal;
	for (int i = 0; i < N; i++) {
		election_results[i].seats = 0;
		if (election_results[i].percentage < 3 ) {
		total_percentage = total_percentage - election_results[i].percentage;
		}
	}
	for (int i = 0; i < N; i++) {
		if (election_results[i].percentage >= 3 ) {
		temp = (election_results[i].percentage / total_percentage) * 250;
		decimal =  temp - (int)temp;
		if (decimal < 0.5 ) {
			temp = (int)floor(temp); // round down
		} else {
			temp = (int)ceil(temp); // round up
		}
		election_results[i].seats = election_results[i].seats +  temp;
		}
	}
	
}


int main() {

for ( int i = 0; i < N; i++) {

election_results[i].votes = 0;
election_results[i].id = -1;

while (election_results[i].id < 0) {
printf("Give data for the %d party \n",i + 1);
printf("Give the party id\n");
scanf("%d",&election_results[i].id);
}
printf("Give the name of the party\n");
scanf("%s",election_results[i].name);
printf("%s",election_results[i].name);
}
do{
printf("Enter 1 to enter the constituency results or 2 to print the final percentages of participating parties and the allocation of seats \n");
scanf("%d",&answer);

if (answer == 1) {  /*where */
 vote_update ();
    }
    else {	
     winner = winning_party();
	  election_results[winner].seats = election_results[winner].seats + BONUS;
	  seat_distribution();
	  printf("The final percentage and the seats of the parties are:\n");
	  for (int i = 0; i < N; i++) {
		printf("ID:%d Name:%s Percentage:%.1f Seats:%d\n",election_results[i].id,election_results[i].name,election_results[i].percentage,election_results[i].seats);
	  }
    }
}while (answer==1);
return 0;
}
