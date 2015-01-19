#include <stdio.h>
#include <stdlib.h>
typedef struct ArrayUtil ArrayUtil;

struct ArrayUtil {
	void* base_ptr;
	int typesize;
	int length;
};



int main(int argc, char const *argv[]){
	int *array;
	array = (int*)malloc(sizeof(int)*2);
	array[0] = 1;
	array[1] = 2;
	printf("%d %d %d\n",array[0],array[1],array[2] );
	array = realloc(array,4*4);	
	array[2] = 3;
	printf("%d %d\n",array[0],array[2] );


	return 0;
}	