#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphKruskal.h"
#include "DLinkedList.h"
#include "stackArray.h"

int compData(int d1, int d2)
{
    return (d1 - d2);
}

int PQWeightComp(Edge d1, Edge d2)
{
	return d2.weight - d1.weight;
}

void GraphInit(Graph * pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), compData);
	}

	pg->visitInfo= (int *)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

	// 우선순위 큐의 초기화
	PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestroy(Graph * pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);

	if(pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(Graph * pg, int fromV, int toV, int weight)
{
	Edge edge = {fromV, toV, weight};     // 간선의 정보 생성

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	// 간선의 정보를 우선순위 큐에 저장
	PEnqueue(&(pg->pqueue), edge);
}

// ConKruskalMST Helper function
void RecoverEdge(Graph * pg, int fromV, int toV, int weight)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

// 한쪽 방향의 간선 소멸: ConKruskalMST Helper function
void RemoveWayEdge(Graph * pg, int fromV, int toV)
{
	int edge;

	if(LFirst(&(pg->adjList[fromV]), &edge))
	{
		if(edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while(LNext(&(pg->adjList[fromV]), &edge))
		{
			if(edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

// 간선의 소멸: ConKruskalMST Helper function
void RemoveEdge(Graph * pg, int fromV, int toV)
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void ShowGraphEdgeInfo(Graph * pg)
{
	int i;
	int vx;

	for(i=0; i<pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 'A');

		if(LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 'A');

			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 'A');
		}
		printf("\n");
	}
}

void ShowGraphEdgeWeightInfo(Graph * pg)
{
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while(!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		printf("(%c-%c), w:%d \n", edge.v1+'A', edge.v2+'A', edge.weight);
	}
}



int VisitVertex(Graph * pg, int visitV)
{
	if(pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
	//	printf("%c ", visitV + 'A');
		return TRUE;
	}

	return FALSE;
}

#if 0
void DFShowGraphVertex(Graph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if(VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if(VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if(visitFlag == FALSE)
		{
			if(SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
#endif

// 두 정점이 연결되어 있다면 TRUE, 그렇지 않다면 FALSE 반환
int IsConnVertex(Graph * pg, int v1, int v2)
{
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if(nextV == v2)
		{
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if(VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{

				if(nextV == v2)
				{
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if(VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if(visitFlag == FALSE)
		{
			if(SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;
}


// MST 간선의 수 + 1 == 정점의 수
// 크루스칼 알고리즘 기반 최소 비용 신장 트리의 구성
void ConKruskalMST(Graph * pg)
{
	Edge recvEdge[20];    // 복원할 간선의 정보 저장
	Edge edge;
	int eidx = 0;
	int i;

	// MST를 형성할 때까지 아래의 while문을 반복
	while(pg->numE+1 > pg->numV)
	{
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2);

		if(!IsConnVertex(pg, edge.v1, edge.v2))
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}

	// 우선순위 큐에서 삭제된 간선의 정보를 회복
	for(i=0; i<eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);

}
