#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int compData(int d1, int d2)
{
    return (d1 - d2);
}

// 그래프의 초기화
void GraphInit(Graph * pg, int nv)
{
	int i;

	pg->adjList = .........
	pg->numV = ....;
	pg->numE = ...;     // 초기의 간선 수는 0개

	for(i=0; i<nv; i++)
	{
		......(&(pg->adjList[i]));
		........(&(pg->adjList[i]), compData);
	}
}

// 그래프 리소스의 해제
void GraphDestroy(Graph * pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);
}

// 간선의 추가
void AddEdge(Graph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), ....);
	LInsert(&(pg->adjList[toV]), .....);
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
