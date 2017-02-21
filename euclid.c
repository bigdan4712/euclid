#include <stdio.h>
#include <unistd.h>

int main(void) {

	long long int a,b,x,y,d;

	while(1){
		printf("Enter two digits greater than zero: \n");
		scanf("%lld %lld",&a,&b);
		if((a==0) && (b==0)) 
			printf("A and B cannot both be zero!\n");
		else break;
	}
	

	asm(	"	movq	%%rax, %%r12 /*move a into r12		*/	\n"
		"	movq	%%rbx, %%r13 /*move b into r13		*/	\n"
		"	xorq	%%r10, %%r10 /*make xnext 0		*/	\n"
		"	xorq	%%rsi, %%rsi /*make x 0			*/	\n"
		"	xorq	%%r11, %%r11 /*make ynext 0		*/	\n"
		"	xorq	%%rdi, %%rdi /*make y zero		*/	\n"
		"	incq	%%rsi	     /*increment x by one	*/	\n"
		"	incq	%%r11	     /*increment ynext to 1	*/	\n"
		"	jmp	2f	     /*jump to 2 forward	*/	\n"
		"1:	movq	%%r12, %%rax /*move a into rax		*/	\n"
		"	movq	%%r13, %%rbx /*move r13 into rbx	*/	\n"
		"	cqto		     /*clear out rax		*/	\n"
		"	idivq	%%rbx	     /*divide rax by rbx	*/	\n"
		"	movq	%%rax, %%r8  /*move floor to q		*/	\n"
		"	movq	%%rdx, %%r9  /*move mod to r		*/	\n"
		"	movq	%%r10, %%rax /*move xnext into rax	*/	\n"
		"	movq	%%rsi, %%r10 /*move x into xnext's reg	*/	\n"
		"	movq	%%rax, %%rsi /*move xnext into x	*/	\n"
		"	imulq	%%r8	     /*multiply q to xnext	*/	\n"
		"	subq	%%rax, %%r10 /*sub x - result		*/	\n"
		"	movq	%%r11, %%rax /*mov ynext to rax		*/	\n"	
		"	movq	%%rdi, %%r11 /*move y into ynext's reg  */	\n"
		"	movq	%%rax, %%rdi /*move ynext into y	*/	\n"
		"	imulq	%%r8	     /*multiply q to ynext	*/	\n"
		"	subq	%%rax, %%r11 /*sub y - result		*/	\n"
		"	movq	%%r13, %%r12 /*mov b to a		*/	\n"
		"	movq	%%r9, %%r13  /*mov r to b		*/	\n"
		"2:	movq	%%r13, %%rbx /*mov b to rbx for cmp	*/	\n"
		"	andq	%%rbx, %%rbx /*check to see if zero	*/	\n"
		"	jnz	1b	     /*jump to 1 if not zero	*/	\n"
		"	movq	%%r12, %%r14 /*move a to d		*/	\n"
		"	movq	%%r14, %%rcx /*move d to rcx		*/	\n"
		"	movq	%%rsi, %%rax /*move x to rax		*/	\n"
		"	movq	%%rdi, %%rbx /*move y to rbx 		*/	\n"
	:	"=c" (d), "=a" (x), "=b" (y)
	:	"a" (a), "b" (b)
	:
	 );

	printf("The results: X: %lld Y: %lld D: %lld\n",x,y,d);

	return 0;

}
