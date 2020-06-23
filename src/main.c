#include <genesis.h>
#include <string.h>

/*Timer variables*/
int timer = 0;
char label_timer[6] = "TIMER\0";
char str_timer[3] = "0";

/*String handling*/
int sign(int x) {
    return (x > 0) - (x < 0);
}

/*Update the timer on screen*/
void updateTimer(){
  /*Convert the int to a char*/
	sprintf(str_timer,"%d",timer);

  /*Remove the text on screen*/
	VDP_clearText(1,2,3);

  /*Draw the timer at 1,2*/
	VDP_drawText(str_timer,1,2);
}

int main(u16 hard)
{

  while(TRUE)
  {
      /* Display the timer label at 1,1 */
      VDP_drawText(label_timer, 1, 1);

      /* Call the timer display function */
      updateTimer();

      /*Increment the timer*/
      timer++;

      /*Wait for 1s*/
      waitMs	(1000);

      /*Wait vsync - always last - if you don't wait for vsync it flickers*/
      VDP_waitVSync();
  }
  return 0;
}
