//Author: Rebecca Lopez
//Date: May 6, 2025
//Purpose: Project 10


#include<stdio.h>

#define WORD_MAX 5
#define MAX_GUESS 6

int openFile(char word[]);
int lowercase(char c);
int validGuess(char guess[]);
void getUserInput(char guess[]);
int rightGuess(char guess[], char word[]);
void formatGuess(char guess[], char word[]);
void printLine();
void displayGuesses(char guesses[][WORD_MAX +1], int count, char word[]);

int main(){
	char word[WORD_MAX +1], guesses[MAX_GUESS][WORD_MAX +1];
	int guessCount = 0, win = 0;
	
	if(!openFile(word)){
		return 1;
	}
	while(guessCount < MAX_GUESS && !win){
		if(guessCount == MAX_GUESS -1){
			printf("FINAL GUESS: ");
		}
		else{
			printf("GUESS %d! Enter your guess: ", guessCount +1);
		}
	getUserInput(guesses[guessCount]);
	printLine();
	win = rightGuess(guesses[guessCount], word);
	guessCount++;
	displayGuesses(guesses, guessCount, word);
	}
	if(win){
		printf("You got it!\n");
	}
	else{
		printf("You lost :( Better luck next time!\n");
	}
	



return 0;

}

int openFile(char word[]){
	FILE *file = fopen("mystery.txt", "r");
	if (file == NULL){
		printf("The file did not open; try again!");
		return 0;
	}
	for(int i = 0; i < WORD_MAX; i++){
		int c = fgetc(file);
		if(c == EOF){
			fclose(file);
			return 0;
		}
		word[i] = (char)c;
	}
	word[WORD_MAX] = '\0';
	fclose(file);
	return 1;

}

int lowercase(char c){
	return c >= 'a' && c <= 'z';
}

int validGuess(char guess[]){
	int i = 0;
	while (guess[i] != '\0'){
		if (!lowercase(guess[i])){
			return 0;
		}
		i++;
	}
	return i == WORD_MAX;	
}

void getUserInput(char guess[]){
	while (1){
		scanf(" %s", guess);
		if (!validGuess(guess)){
			printf("Your guess must be 5 letters long.\nPlease try again: ");
		}
		else{
			break;
		}
	}
}

int rightGuess(char guess[], char word[]){
	for(int i = 0; i < WORD_MAX; i++){
		if(guess[i] != word[i]){
			return 0;
		}
	}
	return 1;
}

void printLine(){
	for(int i = 0; i < 28; i++){
		printf("=");
	}
	printf("\n");
}

void formatGuess(char guess[], char word[]){
	for(int i = 0; i < WORD_MAX; i++){
		if(guess[i] == word[i]){
			printf("%c", guess[i] -32);
		}
		else{
			printf("%c", guess[i]);
		}
	}
	printf("\n");
	for(int i = 0; i < WORD_MAX; i++){
		int guesses = 0; 
		if(guess[i] != word[i]){
			for(int r = 0; r < WORD_MAX; r++){
				if(guess[i] == word[r] && guess[r] != word[r]){
					guesses = 1;
					break;
				}
			}
		}
	printf("%c", guesses ? '^': ' ');
	}
	printf("\n");
}

void displayGuesses(char guesses[][WORD_MAX + 1], int count, char word[]){
	for(int i = 0; i < count; i++){
		formatGuess(guesses[i], word);
	}
}
