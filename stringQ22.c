
#include <stdio.h>

int main(int argc,char* argv[]) { 
  /*having issues with this in particular...*/

  int number;    
  int newNumber;
  int i;
  printf("Enter a number in decimal...");
  scanf("%d",&number);

  /*                        */

  printf("%d in binary is: ",number);
  for(i = 31;i >= 0;i--) {
    newNumber = (number>>i);
    if(newNumber & 1) {
      printf("1");
    }
    else {
  printf("0");
}
   }  


  return 0;
}
//Output-
Enter a number in decimal...30.78
30 in binary is: 00000000000000000000000000011110