#include <stdio.h>
#include "GraphBFS.h"

int main(void)
{
	Graph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	BFShowGraphVertex(&graph, A); printf("\n");
	BFShowGraphVertex(&graph, C); printf("\n");
	BFShowGraphVertex(&graph, E); printf("\n");
	BFShowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
	return 0;
}
