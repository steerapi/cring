/*
 ============================================================================
 Name        : ring.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ring/ring.h"

int main(void) {
	rnode *ring = create_ring(5);
	printf("size: %d\n", ring_count(ring));
	shrink_ring(ring, 10);
	printf("size: %d\n", ring_count(ring));
	expand_ring(ring, 5);
	printf("size: %d\n", ring_count(ring));

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
