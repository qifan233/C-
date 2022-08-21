#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Queue
{
	int data;
	struct Queue* next;
	struct Queue* tail;
}QNode;

QNode* Origin(QNode* q);
QNode* Destroy(QNode* q);
QNode* PushBack(QNode* q, int x);
QNode* PopFront(QNode* q);
int QueueFront(QNode* q);
int QueueBack(QNode* q);
int QueueSize(QNode* q);
bool QueueEmpty(QNode* q);