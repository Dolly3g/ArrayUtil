#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)

#include "arrayUtil.h"
#include "expr_assert.h"
#include <stdlib.h>
#include <stdio.h>

void test_areEqual_returns_0_for_different_sized_arrays () {
	int array1[] = {1,2,3};
	char array2[] = "car";
	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,INT_SIZE,3);
	a2 = initializeArrayUtil(array2,CHAR_SIZE,3);

	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_0_for_different_lengthed_arrays () {
	ArrayUtil a1,a2;
	a1 = create(INT_SIZE,2);
	a2 = create(CHAR_SIZE,3);
	assertEqual(areEqual(a1,a2),0);
}
void test_areEqual_returns_1_for_same_int_arrays () {
	int array1[] = {1,2,3};
	int array2[] = {1,2,3};
	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,INT_SIZE,3);
	a2 = initializeArrayUtil(array2,INT_SIZE,3);

	assertEqual(areEqual(a1,a2),1);
}


void test_areEqual_returns_1_for_same_float_arrays () {
	float array1[] = {1.2,2.2,3.2};
	float array2[] = {1.2,2.2,3.2};
	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,FLOAT_SIZE,3);
	a2 = initializeArrayUtil(array2,FLOAT_SIZE,3);

	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_1_for_same_char_arrays () {
	char array1[] = "car";
	char array2[] = "car";
	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,CHAR_SIZE,3);
	a2 = initializeArrayUtil(array2,CHAR_SIZE,3);

	assertEqual(areEqual(a1,a2),1);
}

void test_areEqual_returns_0_for_different_arrays () {
	int array1[] = {1,2,3};
	int array2[] = {1,2,4};
	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,INT_SIZE,3);
	a2 = initializeArrayUtil(array2,INT_SIZE,3);

	assertEqual(areEqual(a1,a2),0);
}

void test_areEqual_returns_0_for_arrays_with_same_contents_but_different_sequence () {
	int array1[] = {1,2,3};
	int array2[] = {3,2,1};
	ArrayUtil a1,a2;
	a1 = initializeArrayUtil(array1,INT_SIZE,3);
	a2 = initializeArrayUtil(array2,INT_SIZE,3);

	assertEqual(areEqual(a1,a2),0);
}

void test_create_creates_ArrayUtil_instance_and_initializes_array_elements_with_0 (){
	int array[] = {0,0,0};
	ArrayUtil a,result;
	a = initializeArrayUtil(array,INT_SIZE,3);
	result = create(INT_SIZE,3);

	assertEqual(areEqual(a,result),1);
	free(result.base_ptr);
}

void test_resize_returns_shrinked_ArrayUtil_when_length_is_reduced (){
	int* input_array = (int*)malloc(INT_SIZE*2);
	int expected_array[] = {1};
	ArrayUtil a,result,expected;

	input_array[0] = 1;
	input_array[1] = 200;

	a = initializeArrayUtil(input_array,INT_SIZE,2);
	expected = initializeArrayUtil(expected_array,INT_SIZE,1);
	result = resize(a,1);
	assertEqual(areEqual(expected,result),1);
}

void test_resize_returns_stretched_ArrayUtil_setting_extra_elements_to_0 (){
	int* input_array = (int*)malloc(INT_SIZE);
	int expected_array[] = {1,0,0};
	ArrayUtil a,result,expected;

	input_array[0] = 1;
	a = initializeArrayUtil(input_array,INT_SIZE,1);
	expected = initializeArrayUtil(expected_array,INT_SIZE,3);
	result = resize(a,3);

	assertEqual(areEqual(expected,result),1);
	free(input_array);
}

void test_resize_returns_stretched_resized_char_ArrayUtil_0_initialized_for_ArrayUtil_and_length (){
	char* input_array = (char*)malloc(CHAR_SIZE*2);
	char expected_array[] = {'a','\0','\0'};
	ArrayUtil a,result,expected;

	input_array[0] = 'a';
	a = initializeArrayUtil(input_array,CHAR_SIZE,1);
	expected = initializeArrayUtil(expected_array,CHAR_SIZE,3);
	result = resize(a,3);
	
	assertEqual(areEqual(expected,result),1);
	free(input_array);
}


void test_findIndex_returns_3_if_the_search_float_is_on_3rd_location (){
	float x = 3.5;
	float array[] = {0.1,3.5,8.9};
	ArrayUtil util = initializeArrayUtil(array,FLOAT_SIZE,3);
	assertEqual(findIndex(util,&x),1);
}


void test_findIndex_returns_neg_1_if_the_search_int_is_not_found (){
	int x = 3;
	int array[] = {1,8,21};
	ArrayUtil util = initializeArrayUtil(array,INT_SIZE,3);
	assertEqual(findIndex(util,&x),-1);
}

/*void test_findIndex_returns_proper_index (){
	int x = 4;
	int array[] = {5,260,4};
	ArrayUtil util = initializeArrayUtil(array,INT_SIZE,2);
	assertEqual(findIndex(util,&x),2);
}*/

void test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location (){
	int x = 'a';
	char array[] = "car";
	ArrayUtil util = initializeArrayUtil(array,CHAR_SIZE,3);
	assertEqual(findIndex(util,&x),1);
}

int isEven (void* hint, void *item){
	int* _hint = (int*)hint;
	int* _item = (int*)item;
	return *_item % *_hint == 0;
}

void test_findFirst_returns_6_when_asked_for_even_integers (){
	int array[4] = {1,7,6,8};
	int hint = 2;
	int (*isEven_ptr)(void*,void*) = &isEven;
	ArrayUtil util = initializeArrayUtil(array,INT_SIZE,4);
	int* result = (int*)findFirst(util,isEven_ptr,(void*)&hint);

	assertEqual(*result,6);
}

int isGreaterThan (void *hint, void *item){
	int* _hint = (int*)hint;
	int* _item = (int*)item;
	return *_item > *_hint;
}

void test_findFirst_returns_12_when_asked_for_integers_divisible_by_6 (){
	int array[6] = {1,7,6,80,21,67};
	int hint = 50 ;
	int (*isGreaterThan_ptr)(void*,void*) = &isGreaterThan;
	ArrayUtil util = initializeArrayUtil(array,sizeof(int),6);
	int* result = (int*)findFirst(util,isGreaterThan_ptr,(void*)&hint);

	assertEqual(*result,80);
}

void operation (void* hint, void* item){
	int* _hint = hint;
	int* _item = item;
	*_item += *_hint;

}

void test_forEach_runs_task_for_every_integer (){
	int hint = 2;
	int array[] = {1,2};
	ArrayUtil util = initializeArrayUtil(array,INT_SIZE,2);
	void (*fn_ptr)(void*,void*) = &operation;
	forEach(util,fn_ptr,(void*)&hint);
	assertEqual(array[0],3);
}

void* sum (void* hint, void* pv, void* cv){
	int* _pv = (int*)pv;
	int* _cv = (int*)cv;
	int* result = (int*)malloc(INT_SIZE); 
	*result = *_pv + *_cv;
	return result;
}

void test_reduce_returns_sum_of_all_integers_of_array (){
	int hint = 2;
	int initial_value = 0;
	int array[] = {1,2,3};
	ArrayUtil util = initializeArrayUtil(array,INT_SIZE,3);
	void* (*fn_ptr)(void*,void*,void*) = &sum;
	int res = *(int*)reduce(util,fn_ptr,(void*)&hint,(void*)&initial_value);
	assertEqual(res,6);
}