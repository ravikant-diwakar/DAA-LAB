#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NODES 100

struct Queue {
    int data[MAX_NODES];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

bool isEmpty(struct Queue *q) {
    return q->front == -1;
}

void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_NODES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->data[++(q->rear)] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return value;
}

void bfs(int graph[MAX_NODES][MAX_NODES], int n, int start) {
    bool visited[MAX_NODES] = {false};
    int distance[MAX_NODES] = {-1};
    struct Queue q;
    initQueue(&q);

    visited[start] = true;
    distance[start] = 0;
    enqueue(&q, start);

    printf("BFS Traversal: ");
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node + 1);

        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                distance[i] = distance[node] + 2;
                enqueue(&q, i);
            }
        }
    }

    printf("\nDistance [");
    for (int i = 0; i < n; i++) {
        printf("%d", distance[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int graph[MAX_NODES][MAX_NODES] = {0};

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1;
    }

    int start;
    scanf("%d", &start);

    bfs(graph, n, start - 1);

    return 0;
}
