#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 100
typedef struct {
    int n;
    int A[MAXN][MAXN];
}Graph;
void init_graph(Graph* G, int n){
    G->n=n;
    int i,j;
    for(i=1;i<=G->n;i++)
        for(j=1;j<=G->n;j++){
            G->A[i][j]=0;
        }
}
void add_edge(Graph* G, int u, int v){
    G->A[u][v]=1;
}
int degree(Graph*G, int n){
    int i,j=0;
    for(i=1;i<=G->n;i++)
        if(G->A[i][n]!=0)
            j++;
    return j;
    
}
typedef struct {
    int size;
    int A[MAXN];
}List;
void make_null_list(List *L){
    L->size=0;
}
int empty_list(List* L){
    return L->size==0;
}
void push_back(List* L, int n){
    L->size++;
    L->A[L->size]=n;
}
int  element_at(List* L, int x){
    return L->A[x];
}
void copy(List* S1, List* S2){
    S1->size=S2->size;
    make_null_list(S1);
    int i;
    for(i=1;i<=S2->size;i++)
        S1->A[i]=S2->A[i];
}
int rank[MAXN];
void ranking(Graph* G){
    int d[MAXN];
    List S1,S2;
    make_null_list(&S1);
    int i,j;
    for(i=1;i<=G->n;i++){
        d[i]=degree(G, i);
        if(d[i]==0)
            push_back(&S1, i);
    }
    int k=0;
    while(!empty_list(&S1)){
 		make_null_list(&S2);
        int y;
        for(j=1;j<=S1.size;j++){
            y=element_at(&S1, j);
            rank[y]=k;
            for(i=1;i<=G->n;i++)
                if(G->A[y][i]==1){
                    d[i]--;
                    if(d[i]==0)
                        push_back(&S2, i);
                }
        }
        k++;
        for(j=1;j<=S2.size;j++) printf("List 3: %d\n",element_at(&S2,j));
        copy(&S1, &S2);
        for(j=1;j<=S1.size;j++) printf("List 4: %d\n",element_at(&S1,j));
    }
}
int main(){
    Graph G;
    freopen("t.txt","r",stdin);
    int n,m,u,v,i, j;
    scanf("%d%d",&n,&m);
    init_graph(&G, n);
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        add_edge(&G, u, v);
    }
    for (j=1;j<=n;j++) rank[j]=-1;
    ranking(&G);
    for(i=1;i<=n;i++){
        printf("%d\n",rank[i]);
    }
    return 0;
}
