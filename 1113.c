#include <stdio.h>
#define MAX 6
int queue[MAX] = {0,0,15,25,35,45};
int front = 2;
int rear = 5;
int isEmpty()
{
    return front == -1;
}
void enqueue(int data)
{
    if((rear +1)%MAX == front)
    {
        printf("Queue Full\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear = (rear +1)%MAX;
    queue[rear] = data;
}
int dequeue()
{
    if (isEmpty())
        return-1;
    int data =queue[front];
    queue[front]=0;
    if (front ==rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1)%MAX;
    }
    return data;
}
int getFront()
{
    if (isEmpty())
        return -1;
    return queue[front];
}
int main()
{
    dequeue();
    dequeue();
    enqueue(55);
    enqueue(65);
    enqueue(75);
    dequeue();
    enqueue(85);
    
    printf("Final Queue:\n");
    for (int i=0;i<MAX; i++)
    {
        printf ("[%d]",queue[i]);
    }
    return 0;
}