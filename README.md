This is a simple project, that allows you to play the classic game rock, paper, scissor against a bot.

You can do with the code whatever you want

Documentation:

The pick of the player/bot are stored as a number: 0 = rock, 1 = paper, 2 = scissor. This will be referenced as the pickNumber
The outcome of a game is being parsed as a number: 0 = tie, 1 = player wins, 2 = bot wins

Variables: 
char strPlayerPick : Input of the player as a string
int playerPick : pickNumber of the player
int botPick : pickNumber of the bot
char strBotPick : Pick of the bot

Methods:

Main: 
Keeps track of the scores for the bot and the player. Simulates games as long as you want to play

int simulateGame:
return values: 0 (tie), 1 (player wins), 2 (bot wins)
The method generates a random number between 0 and 2 as pick for the bot. 0 means rock, 1 means paper and 3 means scissor. 
The code then takes an input from the player, checks if the player provided a valid input (rock, paper or scissor) and requests a new input in cas the given input is wrong.
The method than checks who won using the getWinner method

int processPlayerPick(char input[7])
Return Value: pickNumber; -1 is returned if no valid input has been entered
(valid) Inputs: rock, paper, scissor
Turn the input string from the player into the pickNumber

const char * getStrBotPick(int botPick)
Return values: rock, paper, scissor (corresponding to the pickNumber)
turn the botPick into its corresponding name, to allow or it bein printed out

int getWinner(int playerPick, int botPick, const char * strBotPick)
return values: game outcome (see above)

strBotPick is only used for printing the pick of the bot
