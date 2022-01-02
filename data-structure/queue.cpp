#include <iostream>
#include <cstdlib>

#define MAX_QUEUE_SIZE 5

using std::cout;
using std::cin;
using std::string;

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void error(char *message) {
    cout << message;
    exit(1);
}

void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q) {
    cout << "QUEUE(front=" << q->front << " rear=" << q->rear << ") = ";
    if (!is_empty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            cout << q->data[i] << " | ";
            if (i == q->rear) {
                break;
            }
        } while (i != q->front);
    }
    cout << "\n";
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        error("Queue is full.");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        error("Queue is full.");
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q) {
    if (is_empty(q)) {
        error("Queue is empty.");
    }
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main() {
    QueueType queue;
    int element;

    init_queue(&queue);
    cout << "--inqueue--\n";
    while (!is_full(&queue)) {
        cout << "input: ";
        cin >> element;
        enqueue(&queue, element);
        queue_print(&queue);
    }
    cout << "Queue is full.\n";

    cout << "--dequeue--\n";
    while (!is_empty(&queue)) {
        element = dequeue(&queue);
        cout << "What is dequeued?: " << element << "\n";
        queue_print(&queue);
    }
    cout << "Queue is empty.\n";
    return 0;
}