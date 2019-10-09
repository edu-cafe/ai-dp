#include <stdio.h>
#include "GraphKruskal.h"

int main(void)
{
	Graph graph;
	GraphInit(&graph, 6);      // A, B, C, D, E, F의 정점 생성

	AddEdge(&graph, A, B, 9);
	AddEdge(&graph, B, C, 2);
	AddEdge(&graph, A, C, 12);
	AddEdge(&graph, A, D, 8);
	AddEdge(&graph, D, C, 6);
	AddEdge(&graph, A, F, 11);
	AddEdge(&graph, F, D, 4);
	AddEdge(&graph, D, E, 3);
	AddEdge(&graph, E, C, 7);
	AddEdge(&graph, F, E, 13);

	ShowGraphEdgeInfo(&graph);
	printf("---------------------\n");
	ConKruskalMST(&graph);

	ShowGraphEdgeInfo(&graph);
	printf("---------------------\n");
	ShowGraphEdgeWeightInfo(&graph);

	GraphDestroy(&graph);
	return 0;
}
