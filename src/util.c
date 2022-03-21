#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void* emalloc(size_t size)
{
	void *p;

	if (!(p = malloc(size))) {
    printf("malloc: out of memory");
    exit(1);
  }

	return p;
}


void* ecalloc(size_t nmemb, size_t size) {
  void *p;

	if (!(p = calloc(nmemb, size))) {
    printf("calloc: out of memory");
    exit(1);
  }

	return p;
}