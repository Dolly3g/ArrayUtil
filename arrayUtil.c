#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

	char* array = calloc(new_length,size);
	ArrayUtil result = {array,a.typesize,new_length};
	for (i =0 ; i < size ; i++) {
		if(i > a.typesize*a.length-1){
			break;
		}
		array[i] = base_a[i];
	}
	return result;
}

int findIndex(ArrayUtil util,void* ele){
	int i=0,size = util.typesize*util.length;
	char* base = ((char*)util.base_ptr);
	char* target = ((char*)base+size);
	while(base<target){
		if(memcmp(base,ele,util.typesize) == 0 ){
			return i;
		}
		base+=util.typesize;
		i++;
	}
	return -1;
};

void dispose(ArrayUtil util){
	free(util.base_ptr);
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