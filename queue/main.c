#include <stdio.h>
#include "queue.h"


int main(int argc, const char *argv[])
{
	Queue *pque = NULL;
	Data_type data;

	pque = create_queue();	
	if (NULL == pque)
	{
		return -1;
	}
	
	enter_queue(pque, 1);
	enter_queue(pque, 2);
	enter_queue(pque, 3);
	enter_queue(pque, 4);
	
	queue_for_each(pque);
	
		
	int ret = out_queue(pque, &data);
	if (ret > 0)
	{
		printf("out : %d\n", data);
	}
	
	queue_for_each(pque);

	destroy_queue(&pque);


	return 0;
}
