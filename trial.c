#include <stdio.h>
typedef struct ArrayUtil ArrayUtil;

struct ArrayUtil {
	void* base_ptr;
	int typesize;
	int length;
};



int main(int argc, char const *argv[]){
	int array[] = {1,2,3};
	ArrayUtil a;
	
	a.base_ptr = array;
	a.typesize = sizeof(int);
	a.length = 3;

	printf("%p %d %d\n",a.base_ptr,a.typesize,a.length );

	return 0;
}