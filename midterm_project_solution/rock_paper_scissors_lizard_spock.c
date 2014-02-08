/*
Final Project: Rock Paper Scissors Lizards Spock (Courtesy: Rice University)
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int name_to_number(char *);
char * number_to_name(int);
void rpsls(char *,int);
void stat(void);

int tie,player_wins,computer_wins;

int main(){
	int i,r;
	srand(time(NULL));
	rpsls("rock",rand());
	rpsls("Spock",rand());
	rpsls("paper",rand());
	rpsls("lizard",rand());
	rpsls("scissors",rand());	
	stat();
	return 0;
}

char * number_to_name(int number){
    if (number == 0 )
        return "rock";
    else if (number == 1)
        return "Spock";
    else if (number == 2)
        return "paper";
    else if (number == 3)
        return "lizard";
    else if (number == 4)
        return "scissors";
    else 
        printf("Error: Invalid number");
}
int name_to_number(char *name){

    if (name == "rock")
        return 0;
    else if (name =="Spock")
        return 1;
    else if (name =="paper")
        return 2;
    else if (name =="lizard")
        return 3;
    else if (name =="scissors")
        return 4;
    else
        printf( "Error:Invalid Name");
}
void rpsls(char *name,int i)
{
 
	int player_number,comp_number,difference;
	
	char *comp_choice,*winner; 
	
	player_number = name_to_number (name);
   	
	srand(i);
	comp_number = rand()%5;
    
	difference = (player_number - comp_number);
	if (difference < 0)
	{
		difference = difference + 5;
	}
	
	difference = difference % 5;
    
	if (difference == 0)
	{
		winner = "Player and computer Tie!";
		tie++;
	}	
    else if (difference == 1 || difference == 2)
    {   
		 winner = "Player wins!";
		 player_wins++;
	}
	
	else if (difference == 3 || difference == 4)
    {
		winner = "Computer wins!";
		computer_wins++;
	}
	
	else
	{
        winner = "No one";
	}

    comp_choice = number_to_name(comp_number);
	printf ("Player chooses %s\n",number_to_name(player_number));
    printf ("Computer chooses %s\n",comp_choice);
    printf ("%s\n",winner);
	printf("\n");
    
}

void stat(void)
{	
	printf("###################################\n");
	printf("\t Game Stastics \t\n\n");
	printf("Computer wins: %d\n",computer_wins);
	printf("Player wins: %d\n",player_wins);
	printf("Computer & Player Tie: %d\n\n",tie);
	printf("###################################\n");

}