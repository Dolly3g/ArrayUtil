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
	void* base = util.base_ptr;
	void* target = util.base_ptr + util.typesize*util.length;
	for(; base<=target; base+=util.typesize){
		if(fn(hint,base)){
			return base;
		}
	}
	return NULL;
}

void forEach(ArrayUtil util, void (*operation)(void*, void*), void* hint){
	void* base = util.base_ptr;
	void* target = base + util.length * util.typesize;
	for (; base<target ; base+=util.typesize) {
		operation(hint,base);
	}
};

void* reduce(ArrayUtil util, void* (*reducer)(void*,void*,void*),void* hint,void* pv){
	void* base = util.base_ptr;
	void* target = base + util.typesize*util.length;
	for(; base<target ; base+=util.typesize){
		pv = reducer(hint,pv,base);
	}
	return pv;
};

int count(ArrayUtil util, int (*fn_ptr)(void *, void *), void *hint){
	int count =0;
	int res;
	void* base = util.base_ptr;
	void* target = base + (util.typesize * util.length);
	for(; base<target ; base+=util.typesize) {
		res = fn_ptr(hint,base);
		res && count++;
	}
	return count;
};

void* findLast(ArrayUtil util, int (*fn)(void*, void*), void* hint){
	void* base = util.base_ptr;
	void* target = util.base_ptr + (util.length-1)*util.typesize;
	for (; target>base ; target-=util.typesize) {
		if(fn(hint,(void*)target))
			return (void*)target;
	}
	return NULL;
}

void map(ArrayUtil util1, ArrayUtil util2, void (*function)(void*, void*, void*), void* hint){
	void* src = util1.base_ptr;
	void* dest = util2.base_ptr;
	int size = util1.typesize > util2.typesize ? util1.typesize : util2.typesize;
	void* target = dest + util1.length*size;
	for (; dest<target ; dest+=util2.typesize, src+=util1.typesize){
		function(hint,src,dest);
	}
}

int filter(ArrayUtil util, int(*function)(void*, void*), void* hint, void **destination, int maxItems){
	int i,count=0;
	void* base = util.base_ptr;
	for (i=0 ; i<util.length ; base+=util.typesize,i++) {
		if(function(hint,base)){
			destination[count++] = base;
		}
	}
	return count;
}