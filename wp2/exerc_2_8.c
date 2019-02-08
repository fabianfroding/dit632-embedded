/* ==================================== 
File name: exerc_2_8.c
Date: 2019-02-7
Group Number:02
Members that contributed:
Fabian
Oliver
Demonstration code: [none] 
====================================== */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile)
{
  printf("enter value between 1-3\n");
  int val;
  scanf ("%d",&val);

  while(val > 3 || val < 1){
    printf("lets try this again, enter a value between 1-3\n");
    scanf ("%d",&val);
  }
  return val;  
};

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner(int player){
  if(player == 0){
    printf("winner is Computor\n");
  }else if (player == 1){
    printf("winner is Human\n");
  }
};

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in: 
 * out: true or false
 */
int play_again(){
  int playAgain;
  do{
    printf("do you want to play again?\n y --> 1\n n --> 0\n");
    scanf("%d", &playAgain);
  }while(playAgain < 0 || playAgain > 1);
  return playAgain;
};

/* ---------------- Logic ----------------*/

/*
 * computer_choice 
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a 
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile){
  int val;
  if(pile==4){
    val = 3;
  }else if (pile == 3){
    val = 2;
  }else if(pile < 3){
    val = 1;
  }else{
    val = (rand() % 3+1);
  }
  return val;
};

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle(int player){
  if(player == 1){
    return 0;
  }else{
    return 1;
  }
};

/* --------------------- Utilities -------------*/
void clear_stdin(){

};

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
  int playAgain = 1;
while(playAgain == 1){
  int pile,    /* This is how many coins we have */
      player,  /* Who is playing? */
      n_coins; /* Number of coins taken */

  srand(time(0)); /* Setup random */

  printf("Välkommen till NIM by ...");

  pile = MAX_COINS; /* Set start values (= init) */
  player = HUMAN;

  /* 
   *  Program main loop 
   */
  while( true ) {	

    printf("Det ligger %d  mynt i högen\n", pile );
    
    if( player == HUMAN ){
      n_coins = human_choice(pile);      
    }else{
      n_coins = computer_choice(pile);
      printf("- Jag tog %d\n", n_coins);      
    }
    pile -= n_coins;
    player = toggle( player );
      
    if( pile <= 1 ){
      break;
    }
  }
  /*
   * end main loop
   */
  write_winner( player );   
  printf("Avslutat\n");
  playAgain = play_again();
  }
  return 0;
}