#include <stdio.h>
#include "GraphDFS.h"

int main(void)
{
	Graph graph;
	GraphInit(&graph, 7);      // A, B, C, D, E, F, G의 정점 생성

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	DFShowGraphVertex(&graph, A); printf("\n");
	DFShowGraphVertex(&graph, C); printf("\n");
	DFShowGraphVertex(&graph, E); printf("\n");
	DFShowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
	return 0;
}
