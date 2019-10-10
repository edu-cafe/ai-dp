#include <stdio.h>
#include "stackArray.h"

#if 0
int main(void)
{
	// Stack의 생성 및 초기화 ///////
	Stack stack;
	StackInit(&stack);

	// 데이터 넣기 ///////
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	// 데이터 꺼내기 ///////
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}
#else

int main(void)
{
	// Stack의 생성 및 초기화 ///////
	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
    printf("\n-----------------------------\n");

	SPush(&stack, 1);  SPush(&stack, 2);
	printf("\nPeek->%d\n", SPeek(&stack));
	SPush(&stack, 3);  SPush(&stack, 4);
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));
    printf("\n-----------------------------\n");

    SPush(&stack, 1);  SPush(&stack, 2);
	printf("\nPop->%d\n", SPop(&stack));
    SPush(&stack, 3);  SPush(&stack, 4);
    while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}
#endif