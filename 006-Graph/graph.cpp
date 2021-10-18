//
// Created by lindsey on 2021/10/14.
//

// 链接矩阵

#define VexMax 100

#include "../003-QueueAndStack//Queue.h"
#include <iostream>

using namespace std;

typedef struct {
    int VexNums;
    char Vexs[VexMax];
    int edge[VexMax][VexMax];
} GraphMatrix;

// 链接矩阵-广度优先遍历
/**
 * 分析时间复杂度，首先需要遍历每一个结点，再遍历每一个结点的连通向量，所以复杂度是O(N^2)
 * @param g
 */
void BFS(GraphMatrix *g);

// 链接矩阵-深度优先遍历
void DFS(GraphMatrix *g);

void BFS(GraphMatrix *g) {
    int vexNums = g->VexNums;
    Queue<int> *q = new Queue<int>;
    bool visited[vexNums];
    // 从第一个结点开始循环
    for (int i = 0; i < vexNums; i++) {
        if (!visited[i]) { // 没有被访问过就放入队列并设置访问状态
            q->push(i);
        }
        while (!q->isEmpty()) { // 取出队列中结点
            int vex = q->pop();
            cout << g->Vexs[vex] << endl;
            visited[i] = true;
            for (int i = 0; i < vexNums; i++) { // 遍历当前结点连通结点
                int linkE = g->edge[vex][i];
                if (linkE == 1 && !visited[i]) { // 没有被访问过就放入队列并设置访问状态
                    q->push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

bool visited[6];

void DFSTraverse(GraphMatrix *g,int v){
    int vexNums = g->VexNums;
    cout << g->Vexs[v] << endl;
    visited[v] = true;
    for (int j = 0; j < vexNums; j++) {
        int linkE = g->edge[v][j];
        if(linkE == 1 && !visited[j]){
            DFSTraverse(g,j);
        }
    }
}

void DFS(GraphMatrix *g){
    int vexNums = g->VexNums;
    for (int i = 0; i < vexNums; i++) {
        if(!visited[i]){
            DFSTraverse(g,i);
        }
    }
}


int main() {
    int vexNums = 6;
    int vertex[6][6] = {{0, 1, 1, 0, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {1, 0, 0, 0, 1, 0},
                        {1, 0, 0, 0, 0, 0},
                        {0, 1, 0, 1, 0, 0}};
    GraphMatrix g{vexNums, {'A', 'B', 'C', 'D', 'E', 'F'},
                  {
           {0, 1, 1, 1, 0, 0},
           {0, 0, 0, 0, 1, 0},
           {1, 0, 1, 0, 0, 0},
           {1, 0, 0, 0, 0, 0},
           {0, 0, 1, 0, 0, 0},
           {0, 1, 0, 1, 0, 0}}
    };
    BFS(&g);
//    DFS(&g);

}


