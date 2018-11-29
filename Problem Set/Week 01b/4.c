#include"Queue.h"
#include <assert.h>

#define MAXITEMS 10

static struct {
    int item[MAXITEMS];
    int tail;
} queueObject;

void QueueInit(){   // set up empty queue
    queueObject.tail = -1;
}

int  QueueIsEmpty(){    // check whether queue is empty
    return (queueObject.tail < -1);
}

void QueueEnqueue(int atom){ // insert int at end of queue
    assert(queueObject.tail < MAXITEMS - 1);
    queueObject.tail ++;
    queueObject.item[queueObject.tail] = atom;
}

int  QueueDequeue(){    // remove int from front of queue
    assert(queueObject.tail > -1);
    int i = queueObject.item[0];

    for (int j = 0; j < queueObject.tail; j ++){
        queueObject.item[j] = queueObject.item[j + 1];
    }

    queueObject.tail --; 
    return i;
}
