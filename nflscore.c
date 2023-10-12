#include <stdio.h>
void nflscore(int score) {
	for (int td2 = 0; td2 <=score; td2++) {
		for(int tdfg = 0; tdfg <=score; tdfg++) {
			for(int td = 0; td <=score; td++) {
				for(int fg = 0; fg <=score; fg++) {
					for (int safe = 0; safe <=score; safe++) {
						if ((8*(td2) + 7*(tdfg)+6*(td)+3*(fg)+2*(safe)) == (score)) {
							printf("%d TD + 2pts, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", td2, tdfg, td, fg, safe);
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
	printf("Enter the NFL Score: ");
	scanf("%d", &score);
	while (score!= 0 && score!=1 && score >=2){
		nflscore(score);
		printf("Enter the NFL Score: ");
		scanf("%d", &score);
	}
	return(0);
}
