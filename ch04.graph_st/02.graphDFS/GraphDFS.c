#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphDFS.h"
#include "stackArray.h"

int compData(int d1, int d2)
{
    return (d1 - d2);
}

// 그래프의 초기화
void GraphInit(Graph * pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;     // 초기의 간선 수는 0개

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), compData);
	}

	// 탐색 정보 등록을 위한 공간의 할당 및 초기화
	pg->.......= (int *)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

// 그래프 리소스의 해제
void GraphDestroy(Graph * pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);

    if(pg->visitInfo != NULL)
		free(pg->visitInfo);
}

// 간선의 추가
void AddEdge(Graph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

// 유틸리티 함수: 간선의 정보 출력
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

int VisitVertex(Graph * pg, int visitV)
{
	if(pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 'A');     // 방문 정점 출력
		return TRUE;
	}

	return FALSE;
}

// Depth First Search: 정점의 정보 출력
void DFShowGraphVertex(Graph * pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	// DFS를 위한 스택의 초기화
	........(&stack);

	.......(pg, visitV);    // 시작 정점 방문
	.......(&stack, visitV);

	while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if(VisitVertex(pg, nextV) == TRUE)  //방문시도 & 방문에 성공하면
		{
			......(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else    //방문시도 & 이미 방문한곳
		{
			while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if(VisitVertex(pg, nextV) == TRUE)
				{
					.....(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if(visitFlag == FALSE)  //연결된 정점과의 방문이 모두 완료되면
		{
			if(SIsEmpty(&stack) == TRUE)    // 스택이 비면 DFS종료
				break;
			else
				visitV = ......(&stack);  //되돌아감
		}
	}

	// 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
