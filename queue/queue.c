#include "queue.h"
#include <stdlib.h>
#include <stdio.h>



Queue *create_queue()
{
	Queue *pque = malloc(sizeof(Queue));
	if (NULL == pque)
	{
		printf("fail malloc\n");
		return NULL;
	}
	pque->pfront = NULL;
	pque->ptail = NULL;
	pque->clen = 0;

	return pque;
		
}
int enter_queue(Queue *pque, Data_type data)
{
	Que_node *pnode = malloc(sizeof(Que_node));	
	if (NULL == pnode)
	{
		printf("fail malloc\n");
		return -1;
	}
	pnode->data = data;
	pnode->pnext = NULL;
	
	if (is_empty_queue(pque))
	{
		pque->ptail = pnode;
		pque->pfront = pnode;
	}
	else
	{
		pque->ptail->pnext = pnode;
		pque->ptail = pnode;
	}
	pque->clen++;

	return 0;
}
/**************************
 *返回值：返回出队的元素个数
 *   为空：0
 *   成功：1
 * ************************/
int out_queue(Queue *pque, Data_type *pdata)
{
	if (is_empty_queue(pque))
	{
		return 0;
	}
	
	if (pdata != NULL)
	{
		*pdata = pque->pfront->data;
	}
	Que_node *pdel = pque->pfront;
	pque->pfront = pdel->pnext;
	free(pdel);
	if (NULL == pque->pfront)
	{
		pque->ptail = NULL;
	}

	pque->clen--;
	return 1;
}
int is_empty_queue(Queue *pque)
{
	return NULL == pque->pfront;
}
void clear_queue(Queue *pque)
{
	while (!is_empty_queue(pque))
	{
		out_queue(pque, NULL);
	}
}
void destroy_queue(Queue **ppque)
{
	clear_queue(*ppque);
	free(*ppque);
	*ppque = NULL;
}
void queue_for_each(Queue *pque)
{
	Que_node *p = pque->pfront;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->pnext;
	}
	printf("\n");
}
int get_front_queue(Queue *pque, Data_type *pdata)
{
	if (is_empty_queue(pque))
	{
		return 0;
	}
	if (pdata != NULL)
	{
		*pdata = pque->pfront->data;
	}

	return 1;
}
