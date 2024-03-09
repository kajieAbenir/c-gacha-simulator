/*
	ABENIR, BRENT KYRJEH L. - 32F COM.E.T.
	ABENIR_PLD1_FINALS_PROJECT_FINALNAGYUDNASIYA.c 22:05 5172023
	
	updated: 3/9/2024 - for web portfolio purposes.
*/

/*
	PROJECT CONCEPT: PITY-LESS GACHA SIMULATION PROGRAM
	
	DESCRIPTION: PROGRAM THAT SIMULATES THE RNG OF A GACHA GAME. 
	PITY IS AN RNG CAPPING SYSTEM WHICH CAPS THE RNG TO FORCE GETTING A 5-STAR ITEM.
	IN THIS PROJECT, IT'S THE TRADITIONAL PITY-LESS SYSTEM THAT I'M SIMULATING.
	
	NOTABLE GACHA CONCEPTS: [FATE: GRAND ORDER]
*/

// everything.
#include <stdio.h>

// includes getch()
#include <conio.h>

// includes srand() function and NULL pointer
#include <stdlib.h>

//  includes time() [check srand() implementation]
#include <time.h>

// includes sleep() and usleep()

// usleep() = 1/1M seconds 
// e.g. usleep(1000000) = 1 second sleep

// sleep() = regular seconds
// e.g. sleep(5) = 5 seconds
#include <unistd.h>

// prototypes area.

void welcomeScreen();
void resultGenerator(int pullAmt);
void checkTotalPulls(int fiveStar, int fourStar, int totalPulls);

// global variables.
int totalFourStar = 0;
int totalFiveStar = 0;
int totalPulls = 0;

int main() {
	// goes to welcome screen.
	welcomeScreen();
	
	// if user inputs 0 in welcomeScreen, it will exit program (return 0).
    return 0;
}

// welcome screen.

/*
	GACHA RATES:
	> 5 STAR [ RAREST ]	= 2 / 100 	OR 2%
	> 4 STAR [ RARE ] 	= 19 / 100 	OR 19%
	> 3 STAR [ COMMON ]	= 79 / 100	OR 79%
*/
void welcomeScreen(){
	int pulls = 0;
	
	system("cls");
	
	printf("\tGACHA SIMULATOR!!!\n\n");
	printf("****************************************\n\n");
	printf("GACHA RATES:\n5-STAR = 2/100 // 4-STAR = 19/100 // 3-STAR = 79/100\n");
	printf("\nNOTE: Featured and non-featured 5-star has the same chance (1/100).");
	printf("\nNOTE 2: This simulation has NO PITY ALGORITHM.\n\n");
	printf("****************************************\n\n");
	printf("Will you do a single (x1) or bundle (x10) pull?.\n");
	printf("Input 11 to check pull history. \n");
	printf("Input 0 to exit.\n\n");
	printf("Response: ");
	
	scanf("%d",&pulls);
	
	// verification point.
	
	if(pulls == 0) {
		return;
	} else if(pulls == 1 || pulls == 10) {
		system("cls");
		resultGenerator(pulls);
	} else if(pulls == 11) {
		checkTotalPulls(totalFiveStar, totalFourStar, totalPulls);
	} else {
		welcomeScreen();
	}
}

// generates result.
void resultGenerator(int pullAmt){
	
	int five_star = 0;
	int four_star = 0;
	
	// function used to tell computer to generate random numbers.
	srand(time(NULL));
	
	// for-loop to generate result until the pull count.
	for (int i = 0; i < pullAmt; i++) {
	    
	    // integrates with an int variable to generate number UP TO 100.
		int result = rand() %100;
	    
	    // prints the LOSE 50/50 dialog.
	    if (result == 1){
	    	
			// prints the text red, 1 in 1;31 is bold, 31 is crimson red. 033 is escape cmd.
			printf("\033[1;31m");
			
			printf("- - - - - - -\n");
			printf("***** 5-STAR NON-FEATURED!\nVery unfortunate...\n");
			printf("- - - - - - -\n");
			
			// prints the next text back to white.
			printf("\033[0;37m");
			
			// adds the count of 5 star obtained.
			five_star++;
			
			// delays input to 1 sec.
			sleep(1);
		}
			
			
		// prints the WIN 50/50 dialog.
        else if (result == 2) {
        	
			// prints the text yellow.
			printf("\033[1;33m");
			
			printf("\n- - - - - - -\n");
			printf("***** 5-STAR FEATURED!\n You got the limited item!\n");
			printf("- - - - - - -\n\n");
			
			// prints the next text back to white.
			printf("\033[0;37m");
			
			// adds the count of 5 star obtained.
            five_star++;
            
            // delays input to 1 sec.
			sleep(1);
        } 
        
        // 4 star.
        else if (result > 2 && result < 21) {
        	
        	// prints the text purple/violet (whatever unsa na nga color gyud) 
        	printf("\033[1;35m");
        	
        	printf("**** 4-STAR\n");
        	
        	// prints the next text back to white.
        	printf("\033[0;37m");
        	
        	// adds the count of 4 star obtained.
        	four_star++;
        	
        	// delays input to 100K microseconds.
        	usleep(100000);
		}
		
		// everthing else is a 3 star. common item.
		else {
            //white text. nothing fancy in gacha games.
            printf("\033[0;37m");
			printf("*** 3-star\n");
			printf("\033[0;37m");
			
			// delays input to 100K microseconds.
        	usleep(100000);
			
			// there's no need to tell you how much 3 star you obtained since these are common items.
        }
	}
	
	printf("\n- - - - -\n\nPulls made: %d\n\n", pullAmt);
	
	// delays output to 500K microseconds (0.5 seconds)
	usleep(500000);
	
	printf("\033[1;33m");
	printf("5-STAR: %d\n", five_star);
	
	// delays output to 500K microseconds (0.5 seconds)
	usleep(500000);
	
	printf("\033[1;35m");
	printf("\n4-STAR: %d\n\n", four_star);
	
	// delays output to 500K microseconds (0.5 seconds)
	usleep(500000);
	
    printf("\033[0;37m");
	printf("Press ENTER to continue...");
	
	totalFiveStar += five_star;
	totalFourStar += four_star;
	totalPulls += pullAmt;
	
	// waits for ENTER...
	getch();

    //reset mechanism
    pullAmt = 0;
    five_star = 0;
    four_star = 0;
    
    // goes back to title screen.
    welcomeScreen();
}

void checkTotalPulls(int fiveStar, int fourStar, int totalPulls){
	
	printf("\n****************************************\n");
	
	// delays output to 500K microseconds (0.5 seconds)
	usleep(500000);
	
	printf("\nTOTAL PULLS: %d\n", totalPulls);
	
	// delays output to 500K microseconds (0.5 seconds)
	usleep(500000);
	
	printf("\033[1;33m");
	printf("\nTOTAL 5-STAR: %d\n", fiveStar);
	
	// delays output to 500K microseconds (0.5 seconds)
	usleep(500000);
	
	printf("\033[1;35m");
	printf("TOTAL 4-STAR: %d\n\n", fourStar);
	
	// delays output to 500K microseconds (0.5 seconds)
	usleep(500000);
	
    printf("\033[0;37m");
	printf("Press ENTER to continue...");
	
	// waits for ENTER...
	getch();
    
    welcomeScreen();
}
