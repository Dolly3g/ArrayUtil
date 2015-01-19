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
	int i,flag = 1,length;
	length = a.length>b.length?a.length:b.length;
	if(a.typesize == b.typesize){
		for(i=0 ; i<length ; i++){
			if(((int*)a.base_ptr)[i] != ((int*)b.base_ptr)[i]){
				flag = 0; 
			}
		}
	}
	else
		flag = 0;

	return flag;
}

ArrayUtil create (int typesize, int length){
	int i;
	int *array = calloc(typesize,length);
	ArrayUtil result = initializeArrayUtil(array,typesize,length);
	return result;
}

ArrayUtil resize (ArrayUtil a, int new_length){
	int size = new_length*a.typesize;
	a.length = new_length;
	a.base_ptr = realloc(a.base_ptr,size);
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
