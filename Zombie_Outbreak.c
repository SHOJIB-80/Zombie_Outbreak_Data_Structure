#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

typedef struct {
    int row;
    int col;
    int time;
} Cell;

typedef struct {
    Cell items[MAX_SIZE * MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, Cell cell) {
    if (q->rear == MAX_SIZE * MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = cell;
}

Cell dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        Cell empty = {-1, -1, -1};
        return empty;
    }
    Cell item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

int timeToInfectCity(int grid[][MAX_SIZE], int n) {
    if (n == 0) return 0;

    Queue q;
    initQueue(&q);
    int uninfected = 0;
    int maxTime = 0;

    // Initialize queue with infected cells and count uninfected
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                Cell cell = {i, j, 0};
                enqueue(&q, cell);
            } else if (grid[i][j] == 0) {
                uninfected++;
            }
        }
    }

    // If no uninfected cells or no infection started
    if (uninfected == 0) return 0;
    if (isEmpty(&q)) return -1;

    // Directions: up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!isEmpty(&q)) {
        Cell current = dequeue(&q);
        maxTime = current.time > maxTime ? current.time : maxTime;

        for (int k = 0; k < 4; k++) {
            int ni = current.row + directions[k][0];
            int nj = current.col + directions[k][1];

            if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                grid[ni][nj] = 1;
                uninfected--;
                Cell newCell = {ni, nj, current.time + 1};
                enqueue(&q, newCell);
            }
        }
    }

    return uninfected == 0 ? maxTime : -1;
}

int main() {
    int n;
    printf("Enter grid size (N): ");
    scanf("%d", &n);

    int grid[MAX_SIZE][MAX_SIZE];
    printf("Enter grid (0 for safe, 1 for infected):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = timeToInfectCity(grid, n);
    if (result == -1) {
        printf("Not all areas could be infected!\n");
    } else {
        printf("Time to infect entire city: %d hours\n", result);
    }

    return 0;
}