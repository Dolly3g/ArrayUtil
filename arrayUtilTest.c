#include "arrayUtil.h"
#include "expr_assert.h"
#include <stdlib.h>

void test_areEqual_returns_1_for_same_arrays () {
	int array1[] = {1,2,3};
	int array2[] = {1,2,3};

	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,sizeof(int),3);
	a2 = initializeArrayUtil(array2,sizeof(int),3);

	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_for_different_arrays () {
	int array1[] = {1,2,3};
	int array2[] = {1,2,4};

	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,sizeof(int),3);
	a2 = initializeArrayUtil(array2,sizeof(int),3);

	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_0_for_arrays_with_same_contents_but_different_sequence () {
	int array1[] = {1,2,3};
	int array2[] = {3,2,1};

	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,sizeof(int),3);
	a2 = initializeArrayUtil(array2,sizeof(int),3);

	assertEqual(areEqual(a1,a2),0);
}

void test_create_returns_ArrayUtil_instance_for_typesize_and_length (){
	int typesize = sizeof(int);
	int length = 3;
	int array[] = {0,0,0};
	ArrayUtil a;
	ArrayUtil result;
	a = initializeArrayUtil(array,sizeof(int),length);
	result = create(typesize,length);
	assertEqual(areEqual(a,result),1);
	free(result.base_ptr);

}