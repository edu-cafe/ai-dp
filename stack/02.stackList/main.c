#include <stdio.h>
#include "stackArray.h"

#if 0
int main(void)
{
	// Stack�� ���� �� �ʱ�ȭ ///////
	Stack stack;
	StackInit(&stack);

	// ������ �ֱ� ///////
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	// ������ ������ ///////
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack));

	return 0;
}
#else

int main(void)
{
	// Stack�� ���� �� �ʱ�ȭ ///////
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