/**/

//**/
//**/

#include <stdio.h>

int main() {

int n, digit;

printf("Enter an integer > ");
scanf("%d", &n);

if (n/10000000000 < 1) //**/
	while (n>0){
		digit = n % 10;
		printf("\n%d", digit);
		n= n/10.0;
		}
printf("\nThat's all, have a nice day!\n");
return (0);
}
