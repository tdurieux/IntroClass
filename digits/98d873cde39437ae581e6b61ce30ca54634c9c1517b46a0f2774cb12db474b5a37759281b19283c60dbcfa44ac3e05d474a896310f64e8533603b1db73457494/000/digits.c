//

#include <stdio.h>

int main()
{
  int digit, n;
  printf("\nEnter and integer > ");
  scanf("%d", &digit);
  while(digit != 0)
  {
    n = digit % 10;
    digit = (digit - n) / 10;
    printf("\n%d", n);
  }
  //
  printf("\nThat's all, have a nice day!\n");

  return 0;
}
