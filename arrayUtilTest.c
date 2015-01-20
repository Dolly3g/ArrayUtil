#include "arrayUtil.h"
#include "expr_assert.h"
#include <stdlib.h>

void test_areEqual_returns_1_for_same_int_arrays () {
	int array1[] = {1,2,3};
	int array2[] = {1,2,3};

	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,sizeof(int),3);
	a2 = initializeArrayUtil(array2,sizeof(int),3);

	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_1_for_same_float_arrays () {
	float array1[] = {1.2,2.2,3.2};
	float array2[] = {1.2,2.2,3.2};

	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,sizeof(float),3);
	a2 = initializeArrayUtil(array2,sizeof(float),3);

	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_1_for_same_char_arrays () {
	char array1[] = {'c','a','r'};
	char array2[] = {'c','a','r'};

	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,sizeof(char),3);
	a2 = initializeArrayUtil(array2,sizeof(char),3);

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

void test_create_returns_ArrayUtil_instance_for_typesize_and_length_that_can_be_used_for_char_arrays (){
	int typesize = sizeof(int);
	int length = 3;
	char array[] = {0,0,0};
	ArrayUtil a;
	ArrayUtil result;
	a = initializeArrayUtil(array,sizeof(char),length);
	result = create(typesize,length);
	assertEqual(areEqual(a,result),1);
	free(result.base_ptr);
}

void test_resize_returns_shrinked_resized_ArrayUtil_for_ArrayUtil_and_length (){
	int i,length = 5,value;
	int* input_array = (int*)malloc(sizeof(int)*5);
	int expected_array[] = {9,8,7};

	ArrayUtil a,result,expected;

	for(i=0,value=9 ; i<length ; i++){
		input_array[i] = value--;
	}

	a = initializeArrayUtil(input_array,sizeof(int),length);
	expected = initializeArrayUtil(expected_array,sizeof(int),3);
	result = resize(a,3);
	assertEqual(areEqual(expected,result),1);
}

void test_resize_returns_lareger_resized_ArrayUtil_0_initislized_for_ArrayUtil_and_length (){
	int i,length = 2,value;
	int* input_array = (int*)malloc(sizeof(int)*2);
	int expected_array[] = {9,10,0,0,0};

	ArrayUtil a,result,expected;
	input_array[0] = 9;
	input_array[1] = 10;
	a = initializeArrayUtil(input_array,sizeof(int),length);
	expected = initializeArrayUtil(expected_array,sizeof(int),5);
	result = resize(a,5);
	assertEqual(areEqual(expected,result),1);
}

void test_findIndex_returns_the_3_if_the_search_element_is_on_3rd_location (){
	float x = 3.5;
	float array[] = {0.1,1.8,2.0,3.5,4};
	ArrayUtil util = initializeArrayUtil(array,sizeof(float),5);
	assertEqual(findIndex(util,&x),3);
}


void test_findIndex_returns_neg_1_if_the_search_element_not_found (){
	int x = 3;
	int array[] = {1,8,21,2,4};
	ArrayUtil util = initializeArrayUtil(array,sizeof(int),5);
	assertEqual(findIndex(util,&x),-1);
}

/*void test_findIndex_returns_1_if_the_search_element_is_found_at_first_location (){
	char x = 'd';
	char array[] = {'a','d','x','v'};
	ArrayUtil util = initializeArrayUtil(array,sizeof(char),4);
	assertEqual(findIndex(util,&x),1);
}*/

void test_dispose_returns (){
	int length=3;
	int *array = (int*)malloc(sizeof(int)*length);
	ArrayUtil util = initializeArrayUtil(array,sizeof(int),length);
	dispose(util);
	//assertEqual((int*)util.base_ptr,NULL);
}

int isEven (void* hint, void *item){
	int* _hint = (int*)hint;
	int* _item = (int*)item;
	return *_item % *_hint == 0;
}

void test_findFirst_returns_6_when_asked_for_even_number (){
	int (*isEven_ptr)(void*,void*);
	int array[4] = {1,7,6,8};
	int hint = 2;
	int* result;
	ArrayUtil util = initializeArrayUtil(array,sizeof(int),4);

	isEven_ptr = &isEven;

	result = (int*)findFirst(util,isEven_ptr,(void*)&hint);
	assertEqual(*result,6);

}

int isGreaterThan (void *hint, void *item){
	int* _hint = (int*)hint;
	int* _item = (int*)item;
	return *_item > *_hint;
}

void test_findFirst_12_when_asked_for_divisible_by_6 (){
	int (*isGreaterThan_ptr)(void*,void*);
	int array[6] = {1,7,6,80,21,67};
	int hint = 50 ;
	int* result;
	ArrayUtil util = initializeArrayUtil(array,sizeof(int),6);

	isGreaterThan_ptr = &isGreaterThan;

	result = (int*)findFirst(util,isGreaterThan_ptr,(void*)&hint);
	assertEqual(*result,80);
}
