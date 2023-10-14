#include <stdio.h>
void nflscore(int score) { // Takes in score of user choice.
	for (int td2 = 0; td2 <=score; td2++) { // Iterates through each combination of touch down and two pointer from 0 to score.
		for(int tdfg = 0; tdfg <=score; tdfg++) { // Iterates through each combination of touch down and field goal from 0 to score.
			for(int td = 0; td <=score; td++) { // Iterates through each combination of touch down from 0 to score.
				for(int fg = 0; fg <=score; fg++) { // Iterates through each combination of field goal from 0 to score.
					for (int safe = 0; safe <=score; safe++) { // Iterates through each combination of safeties from 0 to score.
						if ((8*(td2) + 7*(tdfg)+6*(td)+3*(fg)+2*(safe)) == (score)) { // Multiplies the amount of each type of scoring method by the point associated to it, and compares it to the score the user wants.
							printf("%d TD + 2pts, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdfg, td, fg, safe); // If this is possible, then this is a valid combination and it is printed.
						}
					}
				}
			}
		}
	}
}


int main() {
	printf("Enter 0 or 1 to STOP \n");
	int score;
	printf("Enter the NFL Score: "); // Asks for score.
	scanf("%d", &score); // Scans in the score and stores into score variable.
	while (score!= 0 && score!=1 && score >=2){ // Will keep asking for score and printing combinations until user enters a score less than 2.
		nflscore(score);
		printf("Enter 0 or 1 to STOP \n");
		printf("Enter the NFL Score: ");
		scanf("%d", &score);
	}
	return(0);
}
