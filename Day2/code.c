#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *fptr;
int size = 2500;
int finalScore;
int finalScoreTwo;
bool partOne;

void calcStrategy() {
    if(fptr == NULL) {
	exit(0);
    }
    // Opponent's play
    char *oPlay = (char*) malloc (size * sizeof(char));
    // My play
    char *mPlay= (char*) malloc (size * sizeof(char));

    

    for(int i = 0; i < 2500; i++) {
	fscanf(fptr, "%s %s", (oPlay + i), (mPlay + i));
	
	printf("Part One: \n");
	switch(oPlay[i]) {
	    case 'A':
		printf("Opponent chose rock!\n");
    		switch(mPlay[i]) {
		    case 'X':
			finalScore += (1 + 3);
			printf("Draw!\n");
			break;
		    case 'Y':
			finalScore += (2 + 6);
			printf("Won!\n");
			break;
		    case 'Z':
			finalScore += (3 + 0);
			printf("Lost!\n");
			break;
		}
		break;
	    case 'B':
		printf("Opponent chose paper\n”");
		switch(mPlay[i]) {
		    case 'X':
			finalScore += (1 + 0);
			printf("Lost!\n");
			break;
		    case 'Y':
			finalScore += (2 + 3);
			printf("Draw\n");
			break;
		    case 'Z':
			finalScore += (3 + 6);
			printf("Won!\n");
			break;
		}
		break;
	    case 'C':
		printf("Opponent chose scissors\n");
		switch(mPlay[i]) {
		    case 'X':
			finalScore += (1 + 6);
			printf("Won!\n");
			break;
		    case 'Y':
			finalScore += (2 + 0);
			printf("Lost!\n");
			break;
		    case 'Z':
			finalScore += (3 + 3);
			printf("Draw!\n");
			break;
		}
		break;
	}

	printf("Part Two: \n");
	switch(mPlay[i]) {
	    case 'X':
		printf("I need to lose!\n");
    		switch(oPlay[i]) {
		    case 'A':
			finalScoreTwo += (3 + 0);
			printf("I chose scissors!\n");
			break;
		    case 'B':
			finalScoreTwo += (1 + 0);
			printf("I chose rock!\n");
			break;
		    case 'C':
			finalScoreTwo += (2 + 0);
			printf("I chose paper!\n");
			break;
		}
		break;
	    case 'Y':
		printf("I need to get a draw!\n”");
		switch(oPlay[i]) {
		    case 'A':
			finalScoreTwo += (1 + 3);
			printf("I chose rock!\n");
			break;
		    case 'B':
			finalScoreTwo += (2 + 3);
			printf("I chose paper!\n");
			break;
		    case 'C':
			finalScoreTwo += (3 + 3);
			printf("I chose scissors!\n");
			break;
		}
		break;
	    case 'Z':
		printf("I need to win!\n");
		switch(oPlay[i]) {
		    case 'A':
			finalScoreTwo += (2 + 6);
			printf("I chose paper!\n");
			break;
		    case 'B':
			finalScoreTwo += (3 + 6);
			printf("I chose scissors!\n");
			break;
		    case 'C':
			finalScoreTwo += (1 + 6);
			printf("I chose rock!\n");
			break;
		}
		break;
    }
	printf("Current Total Score for Part One: %d\n", finalScore);
	printf("Current Total Score for Part Two: %d\n", finalScoreTwo);
	}
    }

int main() {
    fptr = fopen("/home/hannes/GithubRepos/AdventOfCode/Day2/Input", "r");
    calcStrategy();
    return 0;
}

