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
	char *base_a = (char*)a.base_ptr;
	char *base_b = (char*)b.base_ptr;

	if(a.typesize == b.typesize && a.length == b.length){
		for(i=0 ; i<a.length*a.typesize ; i++){
			if(base_a[i] != base_b[i]){
				return 0;
			}
		}
	}
	else
		return 0;
	return 1;
}

ArrayUtil create (int typesize, int length){
	char *array = calloc(typesize,length*typesize);
	ArrayUtil result = initializeArrayUtil(array,typesize,length);
	return result;
}

ArrayUtil resize (ArrayUtil a, int new_length){
	int i,size = new_length*a.typesize;
	char* base_a = (char*)a.base_ptr;
	a.base_ptr = realloc(a.base_ptr,size);
	for (i = a.length*a.typesize ; i <= size ; i++) {
		base_a[i] = 0;
	}
	a.length = new_length;
	return a;
}

int findIndex(ArrayUtil util,void* x){
	int i,size = util.typesize*util.length;
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

void* findFirst (ArrayUtil util, int (*fn)(void*,void*),void* hint){
	int i;
	int base_util;
	void *item;
	for(i=0 ; i<util.length ; i++){
		base_util = ((int*)util.base_ptr)[i];
		item = &base_util;
		if(fn(hint,item))
			return item;
	}
	return NULL;
}

void forEach(ArrayUtil util, void (*operation)(void*, void*), void* hint){
	int i;
	int base;
	void* base_of_ele;
	for (i = 0 ; i<util.length ; i++) {
		base = ((int*)util.base_ptr)[i];
		base_of_ele = (void*)&base;
		operation(hint,&((int*)util.base_ptr)[i]);
	}
};

void* reduce(ArrayUtil util, void* (*reducer)(void*,void*,void*),void* hint,void* pv){
	int i;
	void* cv;
	for(i=0 ; i<util.length ; i++){
		cv = (void*)&((int*)util.base_ptr)[i];
		pv = reducer(hint,pv,(cv));
	}
	return pv;
};

int count(ArrayUtil util, int (*fn_ptr)(void *, void *), void *hint){
	int i,count =0;
	void* base;
	for(i=0 ; i<util.length ; i++) {
		base = (void*)&((int*)util.base_ptr)[i];
		fn_ptr(hint,base) && count++;
	}
	return count;
};