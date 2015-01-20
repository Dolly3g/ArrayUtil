#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>

ArrayUtil initializeArrayUtil (void* base_pointer,int typesize,int length){
	ArrayUtil a;
	a.base_ptr = base_pointer;
	a.typesize = typesize;
	a.length = length;
	return a;
}

int areEqual (struct ArrayUtil a, struct ArrayUtil b){
	int i;
	int *base_a = (int*)a.base_ptr;
	int *base_b = (int*)b.base_ptr;

	if(a.typesize == b.typesize && a.length == b.length){
		for(i=0 ; i<a.length ; i++){
			if(base_a[i] != base_b[i]){
				return 0;
			}
		}
	}
	return 1;
}

ArrayUtil create (int typesize, int length){
	int i;
	int *array = calloc(typesize,length);
	ArrayUtil result = initializeArrayUtil(array,typesize,length);
	return result;
}

ArrayUtil resize (ArrayUtil a, int new_length){
	int i,size = new_length*a.typesize;
	int* base_a = (int*)a.base_ptr;
	a.base_ptr = realloc(a.base_ptr,size);
	for (i = a.length ; i < new_length ; i++) {
		base_a[i] = 0;
	}
	a.length = new_length;
	return a;
}

int findIndex(ArrayUtil util,void* x){
	int i;
	float* _x = x;
	float* base_ptr = util.base_ptr;
	for(i=0 ; i<util.length ; i++){
		if(base_ptr[i] == *_x)
			return i;
	}
	return -1;
};

void dispose(ArrayUtil util){
	free(util.base_ptr);
	util.base_ptr = NULL;
}