//Maya Jairam
//Wheel of Fortune
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//changes puzzle into underscores
string underscore(string x);
//sees if the guess to solve the puzzle is correct
bool iscorrect(string x, string y);
//can be used to determine if a letter is a vowel or consonant
bool isvowel(char x);
//counts the number of times the letter shows up
int count(char x,string z);
//changes the underscores into letters if it is correct
string reveal(char x, string known,string unkown);
int main(){
	srand(time(0));	
	int choice, money = 0, spinvalue, tries;
	char consonant, vowel, letter;
	string guess;
	int wheel[24] = {5000, 500, 900, 700, 300, 800, 550, 400, 500, 600, 350, 500, 900, 0, 650, 1, 700, -1, 800, 500, 450, 500, 300, 0};
	string puzzles[] = {"Afterschool Activities", "Air Hockey", "A Family Game Of Charades", "A Hand Of Blackjack", "Blowing Up Balloons", "Bouncing On A Trampoline",
	"Building A Gingerbread House", "Carousel Ride", "Checkers And Chess", "Crossword Puzzle", "Deck Of Playing Cards", "Driving Through Wide Open Spaces", 
	"Ferris Wheels And Merry Go Rounds", "Going On A Scavenger Hunt", "High Velocity Paintball", "I Spy With My Little Eye", "International Book Fair", "Learning How To Surf",
	"Masquerade Balls", "Masks And Costumes", "Penny Slot Machine", "Playing Connect The Dots", "Pranks And Practical Jokes", "Riding a Mechanical Bull", "Rock Paper Scissors"};
		cout<<"\t\t\tWelcome to Wheel of Fortune!\nYou will be given a puzzle and you will try to solve it. Good luck!\n";	
	//repeating the game three times
	for(int i = 0; i<=2; i++){
		string puzzle = puzzles[rand() % 25];
		string puzzlelength = underscore(puzzle);
		cout<<"Round "<<i+1<<endl;
		cout<<"The topic is: Fun and Games"<<endl;	
		cout<<puzzlelength<<endl;	
		//cout<<puzzle<<endl;	 
		do{
			tries = 0;
			cout<< "\n1. Spin the Wheel \n2. Buy a Vowel \n3. Solve the Puzzle\n";
			cout<< "Select a choice: ";
			cin>>choice;
			//making sure the choice is a number
			do{
				if(isalpha(choice)){
				cout<<"Enter a choice number: ";
				cin>>choice;					
				}
			}while(isalpha(choice) == true);
			tries += 1;		
			if(choice == 1){
				spinvalue = wheel[rand() % 24];
				if(spinvalue == 0){
					money = 0;
					cout<<"You've gone bankrupt!\n";				
				}
				else if(spinvalue == -1)
					cout<<"You lost a turn!\n";
				else if(spinvalue == 1){
					//using a new variable called letter because it can be either a vowel or consonant in a free play
					cout<<"You have a free play! Choose any letter: ";
					cin>>letter;
					puzzlelength = reveal(letter,puzzle,puzzlelength);
					cout<<puzzlelength<<endl;					
				}
				else{
				cout<<"You landed on $"<<spinvalue<<".\n";
				cout<<"Enter a consonant: ";
				cin>>consonant;
				do{
					if(isvowel(consonant)){
						cout<<"Enter a consonant: ";
						cin>>consonant;					
					}	
				}while(isvowel(consonant)==true);					
				money += count(consonant,puzzle) * spinvalue;
				puzzlelength = reveal(consonant, puzzle, puzzlelength);
				cout<<puzzlelength<<endl<<"You have: $"<<money<<endl;										
				}
			}
			if(choice == 2){
				do{
				if(money<250){
					cout<<"You cannot buy a vowel because you don't have enough money. Please select another choice: ";
					cin>>choice;				
				}	
				}while(choice == 2 and money < 250);
				cout<<"Enter a vowel: ";
				cin>>vowel;
				do{
					if(isvowel(vowel)==false){
						cout<<"Enter a vowel: ";
						cin>>vowel;
					}
				}while(isvowel(vowel)==false);
				money -= 250;
				if(isvowel(vowel))
					puzzlelength = reveal(vowel,puzzle,puzzlelength);
				cout<<puzzlelength<<endl<<"You have: $"<<money<<endl;
			}
			if(choice == 3){
				//trying to get the full sentence
				cout<<"Enter your guess: "<<endl;
				cin.ignore();
				getline(cin,guess);
				if(iscorrect(guess,puzzle)){
					cout<<"That is correct!\n";		
					puzzlelength = puzzle;
					money += 1000;			
				}
				else
					cout<<"Sorry!\n";
			cout<<"You have: $"<<money<<endl;
			}			
	}while(puzzlelength!=puzzle and tries<15);
	cout<<"The puzzle is: "<<puzzle<<endl;	
}
	cout<<"Thanks for being on the show! You have won $"<<money<<"!!!";
}
string underscore(string x){
	for(int i = 0; i<x.length(); i++){
		if(isalpha(x[i]))
			 x[i]='_';
	}
	return x;
}
bool iscorrect(string x, string y){
	for(int i = 0; i<=y.length(); i++){
		if(isalpha(x[i])){
			if(tolower(x[i]) != y[i] and toupper(x[i]) != y[i])
				return false;			
		}
	}
	return true;
}
bool isvowel(char x){
	string vowels = "aeiou";
	for(int i = 0; i<=vowels.length(); i++){
		if(tolower(x) == vowels[i])
			return true;		
	}
	return false;	
}
int count(char x, string z){
	int count = 0;
	for(int i = 0; i<=z.length(); i++){
		if(tolower(x)==z[i] or toupper(x)==z[i])
			count +=1;
	}
	return count;	
}
string reveal(char x, string known, string unknown){
	for(int i = 0; i<=known.length(); i++){
		if(tolower(x)==known[i] or toupper(x)==known[i])
			unknown[i]=known[i];		
	}
	return unknown;
}
