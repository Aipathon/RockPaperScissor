#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int processPlayerPick(char input[7]);
int getWinner(int playerPick, int botPick, const char * strBotPick);
const char * getStrBotPick(int botPick);
int simulateGame();

int main()
{
    int botCount = 0;
    int playerCount = 0;
    while(true)
    {
        int result = simulateGame();
        if(result == 0)
        {
            botCount++;
            playerCount++;
        }
        else if(result == 1) playerCount++;
        else botCount++;
        printf("Current score: \n Bot: %d", botCount);
        printf(" You: %d", playerCount);
        printf("\n");
    }
}


int simulateGame()
{
    //Cases: rock = 0; paper = 1; scissor = 2

    srand(time(0)); // Seed the random number generator
    int botPick = rand() % 3;
    printf("Input your pick. Valid choices are rock, paper and scissor \n");
    char strPlayerPick[7];
    scanf("%s", &strPlayerPick);
    int playerPick = processPlayerPick(strPlayerPick);
    while(playerPick == -1){
        printf("No valid input submitted. Please enter again. Valid choices are rock, paper and scissor \n");
        scanf("%s", &strPlayerPick);
        playerPick = processPlayerPick(strPlayerPick);
    }
    const char * strBotPick = getStrBotPick(botPick);
    int winner = getWinner(playerPick, botPick, strBotPick);
    return winner;
}

int processPlayerPick(char input[7])
{
    if(strcmp(input, "rock") == 0)
    {
        return 0;
    }
    if(strcmp(input, "paper") == 0)
    {
        return 1;
    }
    if(strcmp(input, "scissor") == 0)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

const char * getStrBotPick(int botPick)
 {
     if(botPick == 0)
     {
         return "rock";
     }
     else if(botPick == 1)
     {
         return "paper";
     }
     else if(botPick == 2)
     {
         return "scissor";
     }
     return "Error";
 }

int getWinner(int playerPick, int botPick, const char * strBotPick)
{
    //Cases: rock = 0; paper = 1; scissor = 2
    if(playerPick == botPick) //tie
    {
        printf("Tie\n");
        return 0;
    }
    else if((playerPick == 0 && botPick == 2) || (playerPick == 1 && botPick == 0) || (playerPick == 2 && botPick == 1)) //Player Wins
    {
        printf("You win, the bot chose ");
        printf("%s\n", strBotPick);
        return 1;
    }
    else //bot wins
    {
        printf("You loose, the bot chose ");
        printf("%s\n", strBotPick);
        return 2;
    }
}
