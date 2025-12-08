#ifndef __QUEUE_H__
#define __QUEUE_H__

//存储的数据类型
typedef int Data_type;

//链式队列的结点类型
typedef struct node
{
	Data_type data;
	struct node *pnext;
}Que_node;

//链式队列对象类型
typedef struct queue
{
	Que_node *pfront;  //指向队头的指针
	Que_node *ptail;   //指向队尾的指针
	int clen;          //当前队列的结点个数
}Queue;


Queue *create_queue();
int enter_queue(Queue *pque, Data_type data);
int out_queue(Queue *pque, Data_type *pdata);
int is_empty_queue(Queue *pque);
void clear_queue(Queue *pque);
void destroy_queue(Queue **ppque);
void queue_for_each(Queue *pque);
int get_front_queue(Queue *pque, Data_type *pdata);


#endif
