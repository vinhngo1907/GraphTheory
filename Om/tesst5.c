#include <stdio.h>

#define MAXN 100
#define NO_EDGE 0
#define INF 99999

typedef struct{
	int C[MAXN][MAXN];
	int F[MAXN][MAXN];
	int n;
}Graph;

typedef struct{
	int dir;
	int pre;
	int sigma;
}Label;
Label labels[MAXN];

typedef struct{
	int front, rear;
	int data[50];
}Queue;

void make_null_queue(Queue *Q){
	Q->front = 0;
	Q->rear = -1;
}

void enqueue(Queue *Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}

int top(Queue *Q){
	return Q->data[Q->front];
}

void dequeue(Queue *Q){
	Q->front++;
}

int empty(Queue *Q){
	return Q->rear < Q->front;
}

void init_flow(Graph *G){
	int i, j;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->n; j++)
			G->F[i][j] = 0;
	
}

void init_graph(Graph *G, int n){
	G->n = n;
	int i, j;
	for(i = 1; i <= G->n; i++)
		for(j = 1; j <= G->n; j++)
			G->C[i][j] = 0;
}

int min(int x, int y){
	return (x < y) ? x : y;
}

int FordFullkerson(Graph *G, int s, int t){
	init_flow(G);
	Queue Q;
	int sum_flow = 0, u, v;
	do{
		for(u = 1; u <= G->n; u++)
			labels[u].dir = 0;
			
		labels[s].dir = +1;
		labels[s].pre = s;
		labels[s].sigma = INF;
		
		make_null_queue(&Q);
		enqueue(&Q, s);
		
		int found = 0;
		while(!empty(&Q)){
			int x = top(&Q);
			dequeue(&Q);
			for(v = 1; v <= G->n; v++){
				if(labels[v].dir == 0 && G->C[x][v] != NO_EDGE && G->F[x][v] < G->C[x][v]){
					labels[v].dir = +1;
					labels[v].pre = x;
					labels[v].sigma = min(labels[x].sigma, G->C[x][v] - G->F[x][v]);
					enqueue(&Q, v);
				}
				
				if(labels[v].dir == 0 && G->C[v][x] != NO_EDGE && G->F[x][v] > 0){
					labels[v].dir = -1;
					labels[v].pre = x;
					labels[v].sigma = min(labels[x].sigma, G->F[x][v]);
					enqueue(&Q, v);
				}
			}
			
			if(labels[t].dir != 0){
				found = 1;
				break;
			}	
		}
		
		if(found == 1){
			int x = t;
			int sigma = labels[t].sigma;
			sum_flow += sigma;
			while(x != s){
				int u = labels[x].pre;
				if(labels[x].dir > 0)
					G->F[u][x] += sigma;
				else{
					G->F[x][u] -= sigma;
					printf("sigma: %d\n",sigma);
				}
				x = u;
			}
		}else
			break;
	}while(1);
	
	return sum_flow;
}

int main(){
	freopen("luong.txt","r",stdin);
	Graph G;
	int n, m, u, v, c, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v, &c);
		G.C[u][v] = c;
	}
	
	int max_flow = FordFullkerson(&G, 1, n);
	printf("Max flow: %d\n", max_flow);
	
	printf("X0: ");
	for(u = 1; u <= n; u++)
		if(labels[u].dir != 0)
			printf("%d ", u);
			
	printf("\nY0: ");
	for(u = 1; u <= n; u++)
		if(labels[u].dir == 0)
			printf("%d ", u);
	return 0;
}
