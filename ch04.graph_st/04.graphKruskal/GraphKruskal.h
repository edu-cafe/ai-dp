#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include "DLinkedList.h"
#include "PriorityQueue.h"

#include "Edge.h"

// 정점의 이름들을 상수화
enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;
	int numE;
	List * adjList;
	int * visitInfo;
	PQueue pqueue;    // 간선의 가중치 정보 저장
} Graph;

// 그래프의 초기화
void GraphInit(Graph * pg, int nv);

// 그래프의 리소스 해제
void GraphDestroy(Graph * pg);

// 간선의 추가
void AddEdge(Graph * pg, int fromV, int toV, int weight);

// 간선의 정보 출력
void ShowGraphEdgeInfo(Graph * pg);

// Depth First Search: 정점의 정보 출력
//void DFShowGraphVertex(Graph * pg, int startV);
int IsConnVertex(Graph * pg, int v1, int v2);   // 두 정점이 연결되어 있는지를 검사함

// 크루스칼 최소 비용 신장 트리의 구성
void ConKruskalMST(Graph * pg);

// 간선의 가중치 정보 출력
void ShowGraphEdgeWeightInfo(Graph * pg);

#endif
