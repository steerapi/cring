/*
 * ring.h
 *
 *  Created on: Feb 19, 2012
 *      Author: Au
 */

#ifndef RING_H_
#define RING_H_

typedef struct rnode {
	void *data;
	struct rnode *next;
} rnode;

int ring_count(rnode *head) {
	int count = 0;
	rnode *node = head;
	while (head != node->next) {
		count++;
		node = node->next;
	}
	count++;
	return count;
}

rnode *create_ring(int size) {
	int i;
	rnode* head = malloc(sizeof(rnode));
	rnode* node = head;
	for (i = 0; i < size - 1; ++i) {
		node->next = malloc(sizeof(rnode));
		node = node->next;
	}
	node->next = head;
	return head;
}

void expand_ring(rnode *oldring, int num) {
	rnode * newring = create_ring(num);
	rnode *old = oldring->next;
	oldring->next = newring;
	rnode *node = newring;
	while (node->next != newring) {
		node = node->next;
	}
	node->next = old;
}

void shrink_ring(rnode *node, int num) {
	int i;
	for (i = 0; i < num; ++i) {
		if (node->next == node) {
			return;
		}
		rnode *torem = node->next;
		node->next = node->next->next;
		free(torem);
	}
}

#endif /* RING_H_ */
