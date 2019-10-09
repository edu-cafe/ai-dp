#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include "DLinkedList.h"

// 정점의 이름들을 상수화
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;   // 정점의 수
	int numE;   // 간선의 수
	List * adjList;   // 간선의 정보
	int * visitInfo;
} Graph;

// 그래프의 초기화
void GraphInit(Graph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(Graph * pg);

// 간선의 추가
void AddEdge(Graph * pg, int fromV, int toV);

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(Graph * pg);


// Breadth First Search: 정점의 정보 출력
void BFShowGraphVertex(Graph * pg, int startV);

#endif
