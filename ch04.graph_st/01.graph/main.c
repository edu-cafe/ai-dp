#include <stdio.h>
#include "Graph.h"

int main(void)
{
	Graph graph;
	GraphInit(&graph, 5);     // A, B, C, D, E의 정점 생성

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);

	ShowGraphEdgeInfo(&graph);

	GraphDestroy(&graph);
	return 0;
}
