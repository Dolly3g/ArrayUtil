#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define POINTER_SIZE sizeof(int*)
#include "arrayUtil.h"
#include "expr_assert.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


Student array_3_Students[3] = {{"Abu", 2, 88.5},{"Babu", 2, 98.25},{"Cabu", 2, 68.0}};

int isGreaterThanHint (void* hint, void* element) {
	float _ele = *((float*)element);
	float _hint = *((float*)hint);
	return _ele > _hint ? 1 : 0;
}

ArrayUtil util,expectedUtil;ArrayUtil util1,util2;
typedef struct Student{
	String name;
    int rollno;
    float age;
} student;

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

void test_findIndex_returns_neg_1_if_the_search_int_is_not_found (){
	int x = 3;
	int array[] = {1,8,21};
	ArrayUtil util = initializeArrayUtil(array,INT_SIZE,3);
	assertEqual(findIndex(util,&x),-1);
}
void test_findIndex_returns_3_if_the_search_float_is_on_3rd_location (){
	float x = 3.5;
	float array[] = {0.1,3.5,8.9};
	ArrayUtil util = initializeArrayUtil(array,FLOAT_SIZE,3);
	assertEqual(findIndex(util,&x),1);
}

void test_findIndex_returns_proper_index (){
	int x = 4;
	int array[] = {5,-23,4};
	ArrayUtil util = initializeArrayUtil(array,INT_SIZE,3);
	assertEqual(findIndex(util,&x),2);
}


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

int isVowel (void* hint, void* item){
	char* _item = (char*)item;
	if(*_item == 'a' || *_item == 'e' || *_item == 'i' || *_item == 'o' || *_item == 'u'){
		return 1;
	}
	return 0;
}
void test_findFirst_returns_e_when_asked_vowels (){
	char array[4] = {'d','e','d','a'};
	int hint;
	int (*isVowel_ptr)(void*,void*) = &isVowel;
	ArrayUtil util = initializeArrayUtil(array,CHAR_SIZE,4);
	char* result = (char*)findFirst(util,isVowel_ptr,(void*)&hint);
	assertEqual(*result,101);
}

void operation (void* hint, void* item){
	int* _hint = hint;
	int* _item = item;
	*_item += *_hint;
}

void test_forEach_adds_hint_to_every_integer (){
	int hint = 2;
	int array[] = {1,2};
	ArrayUtil util = initializeArrayUtil(array,INT_SIZE,2);
	void (*fn_ptr)(void*,void*) = &operation;
	forEach(util,fn_ptr,(void*)&hint);
	assertEqual(array[0],3);
}

void toUpperCase (void* hint, void* item){
	char* _item = (char*)item;
	*_item = toupper(*_item);
}

void test_forEach_changes_each_character_to_uppercase (){
	void* hint;
	char array[] = "dollY";
	ArrayUtil util = initializeArrayUtil(array,CHAR_SIZE,5);
	void (*fn_ptr)(void*,void*) = &toUpperCase;
	forEach(util,fn_ptr,hint);
	assertEqual(array[0],68);
}

void* sum (void* hint, void* pv, void* cv){
	int* _pv = (int*)pv;
	int* _cv = (int*)cv;
	int* result = (int*)malloc(INT_SIZE); 
	*result = *_pv + *_cv;
	return result;
}

void* addDecimals (void* hint, void* pv, void* cv){
	float* _pv = (float*)pv;
	float* _cv = (float*)cv;
	float* result = (float*)malloc(INT_SIZE); 
	*result = *_pv + *_cv;
	return result;	
}

void test_reduce_returns_sum_of_all_floats_of_array (){
	void* hint;
	float initial_value = 0;
	float array[] = {1.1,2.2,3.3};
	ArrayUtil util = initializeArrayUtil(array,FLOAT_SIZE,3);
	void* (*fn_ptr)(void*,void*,void*) = &addDecimals;
	float res = *(float*)reduce(util,fn_ptr,hint,(void*)&initial_value);
	assertEqual(res,(float)6.6);
}

void* greaterChar(void* hint, void* pv, void* cv){
	int _pv = *(char*)pv;
	int _cv = *(char*)pv;
	return _pv > _cv ? pv : cv;
}

void test_reduce_concats_the_characters_of_array (){
	void* hint;
	char initial_value = 0;
	char array[] = "doylo";
	ArrayUtil util = initializeArrayUtil(array,CHAR_SIZE,5);
	void* (*fn_ptr)(void*,void*,void*) = &greaterChar;
	int res = *(char*)reduce(util,fn_ptr,hint,(void*)&initial_value);
	assertEqual(res,111);
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

int isMultipleOf (void* hint,void* item){
	int _hint = *((int*)hint);
	int _item = *((int*)item);
	return _item%_hint != 0;

}

void test_count_returns_number_of_even_numbers_in_array_util (){
	int array[] = {9,6,4,3,7,1};
	int hint = 3;
	int (*isMultipleOf_ptr)(void*,void*) = &isMultipleOf;
	ArrayUtil util = initializeArrayUtil((void*)array,INT_SIZE,6);
	assertEqual(count(util,isMultipleOf_ptr,(void*)&hint),3);
}

void test_count_returns_number_of_vowels_in_array_util (){
	char *array = "dolli";
	void* hint;
	int (*isVowel_ptr)(void*,void*) = &isVowel;
	ArrayUtil util = initializeArrayUtil((void*)array,CHAR_SIZE,6);
	assertEqual(count(util,isVowel_ptr,hint),2);
}

void test_count_returns_decimal_numbers_greater_than_2_in_array_util (){
	float array[] = {1.0,5,7,3.0,1,9,2.2};
	float hint = 2.0;
	int (*isGreaterThanHint_ptr)(void*,void*) = &isGreaterThanHint;
	ArrayUtil util = initializeArrayUtil((void*)array,FLOAT_SIZE,7);
	assertEqual(count(util,isGreaterThanHint_ptr,(void*)&hint),5);
}

void test_findLast_returns_last_even_number_from_integer_array(){
	int array[] = {1,2,4,5};
	int hint = 2;
	ArrayUtil util = initializeArrayUtil((void*)array,INT_SIZE,4);
	int(*fn)(void*,void*) = &isEven;
	int* result = (int*)findLast(util,fn,(void*)&hint);
	assertEqual(*result,4);
}

void test_findLast_returns_NULL_if_element_is_not_found(){
	int array[] = {1,9,59,5};
	void* hint;
	ArrayUtil util = initializeArrayUtil((void*)array,INT_SIZE,4);
	int(*fn)(void*,void*) = &isEven;
	void* result = findLast(util,fn,(void*)&hint);
	assertEqual((int)result,'\0');
}

void test_findLast_returns_last_vowel_from_char_array(){
	char array[] = "okies";
	void* hint;
	ArrayUtil util = initializeArrayUtil((void*)array,CHAR_SIZE,4);
	int(*fn)(void*,void*) = &isVowel;
	char* result = (char*)findLast(util,fn,(void*)&hint);
	assertEqual(*result,'e');
}

void square_elements(void *hint, void *sourceItem, void *destinationItem){
	*(int*)destinationItem=*(int*)sourceItem * *(int*)sourceItem;
}

void test_map_returns_square_of_each_element_in_array(){
	void *hint;
	int array[]={1,2,3,4,5};
	int newArray[]={1,4,9,16,25};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={newArray,INT_SIZE,5};
	ArrayUtil mapped={calloc(5,INT_SIZE),INT_SIZE,5};
	map(util,mapped,square_elements,&hint);
	assert(areEqual(expected, mapped));
}

void toUpper (void* hint, void* sourceItem, void* destinationItem){
	char _source = *(char*)sourceItem;
	*(char*)destinationItem = toupper(_source);
}

void test_map_returns_upperCased_of_each_char_in_array(){
	void *hint;
	char array[]="abcd";
	char newArray[]="ABCD";
	ArrayUtil util={array,CHAR_SIZE,4};
	ArrayUtil expected={newArray,CHAR_SIZE,4};
	ArrayUtil mapped={calloc(4,CHAR_SIZE),CHAR_SIZE,4};
	void(*toUpper_ptr)(void*,void*,void*) = &toUpper;
	map(util,mapped,toUpper_ptr,&hint);
	assert(areEqual(expected, mapped));
}

void toAscii (void* hint, void* src, void* dest){
	char srcItem = *(char*)src;
	*(int*)dest = srcItem;
}

void test_map_returns_ascii_of_each_char_in_array(){
	void *hint;
	char array[]="abcd";
	int newArray[]={97,98,99,100};
	ArrayUtil util={array,CHAR_SIZE,4};
	ArrayUtil expected={newArray,INT_SIZE,4};
	ArrayUtil mapped={calloc(4,INT_SIZE),INT_SIZE,4};
	void(*toAscii_ptr)(void*,void*,void*) = &toAscii;
	map(util,mapped,toAscii_ptr,&hint);
	assert(areEqual(expected, mapped));
}

void test_filter_returns_only_even_numbers (){
	int hint=2;
	int maxItems = 4;
	int array[] = {1,2,5,4,6,8};
	void *dest[maxItems];
	ArrayUtil util={array,INT_SIZE,6};
	int(*isEven_ptr)(void*,void*) = &isEven;
	assertEqual(filter(util,isEven_ptr,(void*)&hint,dest,maxItems),4);
	assertEqual(*(int*)dest[0],array[1]);
	assertEqual(*(int*)dest[1],array[3]);
	assertEqual(*(int*)dest[2],array[4]);
	assertEqual(*(int*)dest[3],array[5]);
}

void test_filter_returns_only_vowels(){
	void* hint;
	int maxItems = 2;
	char array[] = "doolly";
	void *dest[maxItems];
	ArrayUtil util={array,CHAR_SIZE,6};
	int(*isVowel_ptr)(void*,void*) = &isVowel;
	assertEqual(filter(util,isVowel_ptr,(void*)&hint,dest,maxItems),2);
	assertEqual(*(char*)dest[0],array[1]);
	assertEqual(*(char*)dest[1],array[2]);
}
//------------------------------------------------------------------------------------------------------------------

void test_create_returns_same_array_if_array_lengths_are_same_and_values_are_same() {
	ArrayUtil a,b;
	int expected = 1,actual;
	a = create(INT_SIZE,2);
	b = create(INT_SIZE,2);
	assert(areEqual(a,b) == 1);
}

void intAddOperation(void* hint, void* item) {
	*((int *)item) = *((int *)hint) + *((int *)item);	
}

void test_forEach_gives_2_3_4_5_6_for_1_2_3_4_5_in_same_array(){
	ArrayUtil src = create(INT_SIZE,5);
	int *arr,i,hint = 1,*list;
	arr = (int*)src.base_ptr;
	for(i=0;i<5;i++){
		arr[i] = i+1;
	}
	list = ((int*)src.base_ptr);
	forEach(src,intAddOperation,&hint);
	assertEqual(list[0],2);
	assertEqual(list[1],3);
	assertEqual(list[2],4);
	assertEqual(list[3],5);
	assertEqual(list[4],6);
	dispose(src);
}
void test_resize_add_0_to_the_new_places_created_in_integer_array(){
	int input_array[] = {1,2,3};
	int expected_array[] = {1,2,3,0,0};
	ArrayUtil result, util1 = {input_array, INT_SIZE, 3};
	ArrayUtil expected = {expected_array, INT_SIZE ,5};
	result =  resize(util1,5);
	assert(areEqual(result , expected));
	dispose(result);
}

void test_resize_add_0_to_the_new_places_created_in_float_array(){
	float array[] = {1.1,2.2,3.2}, arr[] = {1.1,2.2,3.2,0.0,0.0};
	ArrayUtil array2, util1 = {array, FLOAT_SIZE, 3};
	ArrayUtil expected = {arr, FLOAT_SIZE ,5};

	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
	dispose(array2);
}
void test_resize_add_0_to_the_new_places_created_in_char_array(){
	char *array= "abc";
	char arr[] = {'a','b','c',0,0};
	ArrayUtil array2, util1 = {array, CHAR_SIZE, 3};
	ArrayUtil expected = {arr, CHAR_SIZE ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
	dispose(array2);
}
void test_resize_add_0_to_the_new_places_created_in_double_array(){
	double array[] = {1,2,3}, arr[] = {1,2,3,0.0,0.0};
	ArrayUtil array2, util1 = {array, DOUBLE_SIZE, 3};
	ArrayUtil expected = {arr, DOUBLE_SIZE ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
	dispose(array2);
}

void test_create_allocates_space_for_INT_array_and_assigns_zero_to_all_bytes(){
	ArrayUtil util = create(INT_SIZE,4);
	int intArray[] = {0,0,0,0};
	ArrayUtil expectedUtil;
	expectedUtil.base_ptr = intArray;
	expectedUtil.typesize = INT_SIZE;
	expectedUtil.length = 4;

	assertEqual(areEqual(expectedUtil,util),1);
}

void test_when_an_array_is_resized_into_smaller_size_the_array_is_trimmed(){
	ArrayUtil util = create(CHAR_SIZE, 3);
	ArrayUtil resizedUtil = resize(util, 2);
	char array[]={0,0,0};
	ArrayUtil expected = { (void*)array,CHAR_SIZE, 2};

	assert(areEqual(expected, resizedUtil));
}

void test_that_function_creates_new_array_or_not(){
	ArrayUtil array = create(INT_SIZE,3);
	int *createArray  = (int*)array.base_ptr;
	assertEqual(createArray[0], 0);
	assertEqual(createArray[2], 0);
	assertEqual(array.length, 3);
	assertEqual(array.typesize, 4);
}
void test_areEqual_returns_0_if_typeSize_of_two_arrays_are_not_equal(){
    int array1[] = {1,2,3,4};
    char array2[] = {'m','a','h','e'};
    ArrayUtil util1 = {array1,sizeof(int),4};
    ArrayUtil util2 = {array2,sizeof(char),4};
    assertEqual(areEqual(util1, util2), 0);
}

void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_putting_0s_in_new_created_spaces(){
    String array1[] = {"Mahesh","Kumar"}, array2[] = {"Mahesh","Kumar",0,0,0};
    ArrayUtil util1 = {array1,sizeof(char *),2};
    ArrayUtil util2 = {array2,sizeof(char *),5};
    assertEqual(areEqual(resize(util1, 5), util2), 1);    
}
void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_removing_extra_values(){
    String array1[] = {"Mahesh","Kumar","Kolla"}, array2[] = {"Mahesh","Kumar"};
    ArrayUtil util1 = {array1,sizeof(char *),3};
    ArrayUtil util2 = {array2,sizeof(char *),2};
    assertEqual(areEqual(resize(util1, 2), util2), 1);    
}
void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_double(){
	double a [] = {2.34};
	double b [] = {2.34};
	ArrayUtil array1 = {a, sizeof(double), 1};
	ArrayUtil array2 = {b, sizeof(double), 1};

	assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_string(){
	String a [] = {"hello"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};

	assert(areEqual(array1,array2));
};

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_not_be_equal_String(){
	String a [] = {"hallo"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};

	assertEqual(areEqual(array1,array2),0);
};
void test_create_should_set_the_length_and_typeSize_fields_of_array_to_the_values_passed_to_create_function(){
	ArrayUtil a = create(1,3);
	assert(a.length == 3);
	assert(a.typesize == 1);
	dispose(a);
}

void test_resize_should_grow_length_of_array_and_set_them_to_zero_when_new_size_is_more(){
	ArrayUtil a = create(4,2);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	for (i = 0; i < 20; ++i)
	{
		assert(((char*)a.base_ptr)[i] == 0);
	}
	dispose(a);
}
void test_resize_should_not_change_length_of_array_when_new_size_is_same_as_old_size(){
	ArrayUtil a = create(1,5);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	dispose(a);
}

void test_array_util_areEqual_returns_0_if_both_array_are_not_equal_in_length_and_elements(){
	int a[]={0,3,8,5,2,3,4,5}, b[]={1,5,2,3,7};
	ArrayUtil a_array = {a,sizeof(int),8};
	ArrayUtil b_array = {b,sizeof(int),5};
	assertEqual(areEqual(a_array, b_array),0);
}
void test_create_allocates_space_for_DOUBLE_array_and_assigns_zero_to_all_bytes(){
	double doubleArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){doubleArray,sizeof(double),4};
	util = create(sizeof(double),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}

void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o'},sizeof(char),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(char []){'a','e','i','o',0,0},sizeof(char),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o','u'},sizeof(char),5};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(char []){'a','e'},sizeof(char),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89,0,0},sizeof(double),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111},sizeof(double),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_FLOAT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89},sizeof(float),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89,0,0},sizeof(float),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_INT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(int []){1,2,3,4},sizeof(int),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(int []){1,2,3,4,0,0},sizeof(int),6}; 
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_create_Structures_with_all_fields_NULL(){
    student temp = {0,0.0};
    student Student[1] = {temp};
    ArrayUtil expected = {Student,sizeof(student),1};
	util1 = create(sizeof(student),1);    
    assert(areEqual(expected,util1));
};

void test_Create_creates_new_array_of_float_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(float[]){0,0},FLOAT_SIZE,2};
	ArrayUtil newUtil = create(FLOAT_SIZE, 2);
	assertEqual(areEqual(expectedUtil,newUtil ), 1);
	dispose(newUtil);
}
void test_Create_creates_new_charArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(char[]){0,0,0},CHAR_SIZE,3};
	ArrayUtil newUtil =create(CHAR_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}
void test_Create_creates_new_doubleArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(double[]){0,0},DOUBLE_SIZE,2};
	ArrayUtil newUtil =create(DOUBLE_SIZE, 3);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}
void test_Create_creates_new_intArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(int[]){0,0,0},INT_SIZE,3};
	ArrayUtil newUtil =create(INT_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
	dispose(newUtil);
}

void test_Create_creates_new_floatArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil util = {(float[]){0,0},FLOAT_SIZE,2};
	ArrayUtil newUtil =create(FLOAT_SIZE, 3);
	assertEqual(areEqual(util, newUtil), 0);
	dispose(newUtil);
}

void test_resize_should_contain_the_initial_array_element(){
	int src[]={5,3},i;
	ArrayUtil util={src,sizeof(int),4},array;
	int* base;
	array = resize(util,15);
	base = (int *)(array.base_ptr);
	assertEqual(base[0], 5);
	assertEqual(base[1], 3);
	assertEqual(base[14], 0);

	free(array.base_ptr);
};

void test_areEqual_returns_0_when_length_is_equal_but_typeSize_is_not_equal(){
	int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void element_into_element_plus_one(void* hint, void* item){
	*((int *)item)= *((int *)item) * ((*((int *)item))+1);
}

void test_forEach_does_multiplication_of_item_with_item_plus_one(){
	void *hint;
	int array[]={1,2,3,4,5};
	int incremented[]={2,6,12,20,30};
	ArrayUtil util={array,INT_SIZE,5};
	ArrayUtil expected={incremented,INT_SIZE,5};
	forEach(util,element_into_element_plus_one,&hint);
	assert(areEqual(util,expected));
}
void *add_all(void* hint, void* previousItem, void* item){
	*((int*)item)= *((int*)previousItem) + *((int*)item);
	return ((int*)item);
}


void test_reduce_gives_15_when_elements_are_1_2_3_4_5_and_initial_value_is_0(){
	void *hint;
	int intialValue=0;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),15);
}
void test_reduce_gives_30_when_elements_are_1_2_3_4_5_and_initial_value_is_15(){
	void *hint;
	int intialValue=15;
	int array[]={1,2,3,4,5};
	ArrayUtil util={array,INT_SIZE,5};
	void *return_value=reduce(util,add_all,&hint,&intialValue);
	assertEqual(*((int*)return_value),30);
}




ArrayUtil utils[3];
int array_1[1] = {1};
int array_1_2[2] = {1, 2};
int array_1_3[2] = {1, 3};
int array_0_0[2] = {0, 0};
int array_1_0[2] = {1, 0};
char array_null_null[2] = {'\0', '\0'};
float array_flt_flt[2] = {0, 0};
double array_dble_dble[2] = {0, 0};
String array_empty_strings[2] = {"", ""};
void_star array_void_stars[1] = {0x0};
char_star array_char_stars[1] = {(char *)('\0')};
int_star array_int_stars[1] = {(int *)(0)};
// float_star array_float_stars[1] = {(float **)(0.0)};

int10 array_int10_0s[1] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
float5 array_float5_0s[1] = {{0.0, 0.0, 0.0, 0.0, 0.0}};
Student array_Students[1] = {{"", 0, 0.0}};


void test_create_001(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int");
	ArrayUtil util1 = {array_0_0, sizeOf_int, 2};
	ArrayUtil util2 = create(sizeOf_int, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_002(){
	log("returns an ArrayUtil with bytes initialized to NULL for char");
	ArrayUtil util1 = {array_null_null, sizeOf_char, 2};
	ArrayUtil util2 = create(sizeOf_char, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_003(){
	log("returns an ArrayUtil with bytes initialized to ZERO for float");
	ArrayUtil util1 = {array_flt_flt, sizeOf_float, 2};
	ArrayUtil util2 = create(sizeOf_float, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_004(){
	log("returns an ArrayUtil with bytes initialized to ZERO for double");
	ArrayUtil util1 = {array_dble_dble, sizeOf_double, 2};
	ArrayUtil util2 = create(sizeOf_double, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
/*void test_create_005(){
	log("returns an ArrayUtil with bytes initialized to ZERO for char[256]");
	ArrayUtil util1 = {array_empty_strings, sizeOf_String, 2};
	ArrayUtil util2 = create(sizeOf_String, 2);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}*/
void test_create_006(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int[10]");
	ArrayUtil util1 = {array_int10_0s, sizeOf_int10, 1};
	ArrayUtil util2 = create(sizeOf_int10, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_007(){
	log("returns an ArrayUtil with bytes initialized to ZERO for float[5]");
	ArrayUtil util1 = {array_float5_0s, sizeOf_float5, 1};
	ArrayUtil util2 = create(sizeOf_float5, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_008(){
	log("returns an ArrayUtil with bytes initialized to ZERO for struct");
	ArrayUtil util1 = {array_Students, sizeOf_Student, 1};
	ArrayUtil util2 = create(sizeOf_Student, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_009(){
	log("returns an ArrayUtil with bytes initialized to ZERO for void *");
	ArrayUtil util1 = {array_void_stars, sizeOf_void_star, 1};
	ArrayUtil util2 = create(sizeOf_void_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_010(){
	log("returns an ArrayUtil with bytes initialized to ZERO for char *");
	ArrayUtil util1 = {array_char_stars, sizeOf_char_star, 1};
	ArrayUtil util2 = create(sizeOf_char_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_create_011(){
	log("returns an ArrayUtil with bytes initialized to ZERO for int *");
	ArrayUtil util1 = {array_int_stars, sizeOf_int_star, 1};
	ArrayUtil util2 = create(sizeOf_int_star, 1);
	assertEqual(areEqual(util1, util2), YES);
	dispose(util2);
}
void test_findIndex_returns_index_of_the_String_element_where_it_presents(){
    String array1[] = {"Mahesh","Kumar","Kolla"};
    String element = "Kumar";
    ArrayUtil util1 = {array1,sizeof(String),3};
    assertEqual(findIndex(util1,&element), 1);
}

void test_findIndex_returns_index_of_the_char_element_where_it_presents(){
    char array1[] = {'m','a','h','e','s','h'};
    char element = 's';
    ArrayUtil util1 = {array1,sizeof(char),6};
    assertEqual(findIndex(util1,&element), 4);
}

void test_findIndex_returns_index_of_the_float_element_where_it_presents(){
    float array1[] = {1.1,2.2,3.3,4.4};
    float element = 4.4;
    ArrayUtil util1 = {array1,sizeof(float),4};
    assertEqual(findIndex(util1,&element), 3);
}

void test_findIndex_returns_index_of_the_integer_element_where_it_presents(){
    int array1[] = {1,2,3,4,5};
    int element = 2;
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(findIndex(util1,&element), 1);
}


void test_findFirst_gives_occurence_of_first_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	MatchFunc *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){3.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,(float)8.3);
}

int hasPassed(void* hint, void *item){
	Student student = *(Student*)item;
	float passMark = *(float*)hint;
	return (student.percentage >= passMark);
}
void test_findFirst_returns_the_first_student_who_has_passed_the_exam_struct_array(){
	ArrayUtil a = {array_3_Students,sizeof(Student),3};
	Student *got;
	String name;
	float passMark = 80.0;
	got = (Student*)findFirst(a,hasPassed,&passMark);
	assertEqual(strcmp(got->name,"Abu"),0);
}

int isUpperCase(void* a,void *b){
	int _a = *((char*)a);
	int _b = *((char*)b);
	return _a==_b ? 1 : 0;	
}

void test_findLast_returns_the_last_element_if_there_is_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','C','D','e'},CHAR_SIZE,5};
	int x = 'D';
	assertEqual(*((char*)findLast(a,isUpperCase,&x)),x);
}

void test_findLast_returns_the_last_element_if_there_is_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,8,10},sizeof(int),5};
	int x = 2;
	assertEqual(*((int*)findLast(a,isEven,&x)),10);
}

//-----Prasenjit-------

int isDivisible(void* a,void *b){
	return (*((int*)a)%*((int*)b) == 0) ? 1 : 0;
}

void intConvertFunc(void* hint, void* sourceItem, void* destinationItem){

	*((int *)destinationItem) = *((int *)hint) + *((int *)sourceItem);
}

void charConvertFunc(void* hint, void* sourceItem, void* destinationItem){
	*((char*)destinationItem) = *((char*)sourceItem) - 32;
}

void test_findLast_returns_null_if_there_is_no_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,7,9},sizeof(int),5};
	int x = 2;
	assertEqual((int)findLast(a,isEven,&x),'\0');
}

void test_map_gives_2_3_4_5_6_for_1_2_3_4_5_for_integer_array(){
	ArrayUtil src = {(int[]){1,2,3,4,5},sizeof(int),5},dest = create(sizeof(int),5);
	ArrayUtil tmp = {(int[]){2,3,4,5,6},sizeof(int),5};
	int hint = 1;
	map(src,dest,intConvertFunc,&hint);
	assert(areEqual(dest,tmp)==1);
	dispose(dest);
}

void test_map_gives_A_B_C_D_E_for_a_b_c_d_e_for_character_array(){
	ArrayUtil src = {(char[]){'a','b','c','d','e'},sizeof(char),5},dest = create(sizeof(char),5);
	ArrayUtil tmp = {(char[]){'A','B','C','D','E'},sizeof(char),5};
	char hint = 32;
	map(src,dest,charConvertFunc,&hint);
	assertEqual(areEqual(dest,tmp),1);
	dispose(dest);
}

//------------------------------------Maheshasur-----------------------------

int isCapital(void *hint, void *item) {
    return((*(char *)item >=65) && (*(char *)item <= 91));
}

int isGreaterThan5(void *hint, void *item) {
    return(*(float *)item > 5);
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_capital(){
    char array1[] = {'k','M','k'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual(*(char *)(findFirst(util1,&isCapital,0)), 'M');
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_even(){
    int hint = 2;
    int array1[] = {1,2,3,4,5};
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(*(int *)(findFirst(util1,&isEven,(void*)&hint)), 2);
}

void test_findFirst_returns_the_adsdress_of_first_element_in_the_array_greater_than_5() {
    float array1[] = {1.1,6.6,5.5,8.8,2.2};
    ArrayUtil util1 ={array1, sizeof(float),5};
    assertEqual(*(float *)(findFirst(util1,&isGreaterThan5,0)), (float)6.6);
}

//-------------------------------Parmatma-------------------------------

int compare(void *hint,void* item){
	if(*(char*)item=='a')
		return 1;
	return 0;
};


int stringCompare(void *hint, void* item){
	String str ="hello";
	String getItem = *(String*)item;
	if(getItem==str)
		return 1;
	return 0;
}

int isEqual(void* hint, void* item){
	int _item = *(int*)item;
	int _hint = *(int*)hint;
	printf("\nitem= %d hint= %d\n",_item,_hint );
	if(_item == _hint)
		return 1;
	return 0;
}


/*
void test_filter_will_return_the_array_a_a_a(){
	char a[]={'a','a','a','b','d'},hint=3;
	int length;
	void* result;
	ArrayUtil array = {a, sizeof(char), 5};
	length = filter(array,compare,&hint,&result,5);

	assertEqual(length,3);
	assertEqual(((char*)result)[1],'a');
};

void test_filter_will_return_the_array_string_contain_hello(){
	int length,hint=9;
	void* result,*expected;
	ArrayUtil array = create(sizeof(String),2);
	((char**)array.base_ptr)[0]="hello";
	((char**)array.base_ptr)[1]="gello";
	length = filter(array,stringCompare,&hint,&result,2);
	expected = ((String*)result)[0];
	
	assertEqual(length,1);
	assertEqual(strcmp(expected,"hello"),0);
};


void test_filter_will_return_the_array_of_8_8_8(){
	int a[]={1,8,8,7,8,9},hint=8,length;
	int *result[3];
	ArrayUtil array = {a,sizeof(int), 6};
	length = filter(array,isEqual,&hint,(void**)&result,5);
	assertEqual(length,3);
	assertEqual(*result[0],8);
	assertEqual(*result[1],8);
	assertEqual(*result[2],8);
};

void test_filter_will_return_the_array_of_only_one_element_8_point_9_in_double(){
	double a[]={8.4,8.4,8.9},hint=3.9;
	int length;
	void* result;
	ArrayUtil array = {a, sizeof(double), 3};
	length = filter(array,isEqual,&hint,&result,2);

	assertEqual(((double*)result)[0],(float)8.9);
	assertEqual(length,1);
	free(result);
};
*/
void test_filter_will_return_the_array_of_only_two_8_point_7_in_float(){
	float a[]={1.4,8.4,8.9,7,8,9.0},hint=3;
	int length;
	float* result[5];
	ArrayUtil array = {a, sizeof(float), 6};
	length = filter(array,isGreaterThanHint,&hint,(void**)&result,5);

	assertEqual(length,5);
	assertEqual(*result[0],(float)8.4);
	assertEqual(*result[1],(float)8.9);
	assertEqual(*result[2],(float)7);
	assertEqual(*result[3],(float)8);
	assertEqual(*result[4],(float)9);
};