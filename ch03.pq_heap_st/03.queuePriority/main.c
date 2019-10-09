#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch1-ch2;
}

int main(void)
{
    PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	PEnqueue(&pq, 'F');
	PEnqueue(&pq, 'D');
	PEnqueue(&pq, 'E');
	printf("%c \n", PDequeue(&pq));

	while(!PQIsEmpty(&pq))
		printf("%c \n", PDequeue(&pq));

	return 0;
}
#if 0
int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	while(!PQIsEmpty(&pq))
		printf("%c \n", PDequeue(&pq));

	return 0;
}
#endif
