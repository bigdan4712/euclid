#include <stdio.h>
#include <unistd.h>

int main(void) {

	long long int a, b, d, x, y, xnew, ynew, r, tmp;

	while(1){
		printf("Enter two digits greater than zero: \n");
		scanf("%lld %lld",&a,&b);
		if((a==0) && (b==0)) 
			printf("A and B cannot both be zero!\n");
		else break;
	}
	

	/*asm( "

	:
	:
	:
	 );*/

	return 0;

}
