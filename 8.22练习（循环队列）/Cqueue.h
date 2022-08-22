#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Queue
{
	int data;
	struct Queue* next;
}QNode;

typedef struct Pos
{
	QNode* queue;

};

QNode* Origin(QNode* q);
QNode* Destroy(QNode* q);
void PushBack(QNode** top, QNode** tail, int x);
void PopFront(QNode** top, QNode** tail);
int QueueFront(QNode* top, QNode* tail);
int QueueBack(QNode* top, QNode* tail);
int QueueSize(QNode* top, QNode* tail);
bool QueueEmpty(QNode* top, QNode* tail);
void Prin(QNode* top, QNode* tail);