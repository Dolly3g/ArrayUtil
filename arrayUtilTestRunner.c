#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_areEqual_returns_0_for_different_sized_arrays,test_areEqual_returns_0_for_different_lengthed_arrays,test_areEqual_returns_1_for_same_int_arrays,test_areEqual_returns_1_for_same_float_arrays,test_areEqual_returns_1_for_same_char_arrays,test_areEqual_returns_0_for_different_arrays,test_areEqual_returns_0_for_arrays_with_same_contents_but_different_sequence,test_create_creates_ArrayUtil_instance_and_initializes_array_elements_with_0,test_resize_returns_shrinked_ArrayUtil_when_length_is_reduced,test_resize_returns_stretched_ArrayUtil_setting_extra_elements_to_0,test_resize_returns_stretched_resized_char_ArrayUtil_0_initialized_for_ArrayUtil_and_length,test_findIndex_returns_3_if_the_search_float_is_on_3rd_location,test_findIndex_returns_neg_1_if_the_search_int_is_not_found,test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location,test_findFirst_returns_6_when_asked_for_even_integers,test_findFirst_returns_12_when_asked_for_integers_divisible_by_6,test_forEach_runs_task_for_every_integer,test_reduce_returns_sum_of_all_integers_of_array,test_count_returns_number_of_even_numbers_in_array_util;
Test test[] = {"test_areEqual_returns_0_for_different_sized_arrays",test_areEqual_returns_0_for_different_sized_arrays,"test_areEqual_returns_0_for_different_lengthed_arrays",test_areEqual_returns_0_for_different_lengthed_arrays,"test_areEqual_returns_1_for_same_int_arrays",test_areEqual_returns_1_for_same_int_arrays,"test_areEqual_returns_1_for_same_float_arrays",test_areEqual_returns_1_for_same_float_arrays,"test_areEqual_returns_1_for_same_char_arrays",test_areEqual_returns_1_for_same_char_arrays,"test_areEqual_returns_0_for_different_arrays",test_areEqual_returns_0_for_different_arrays,"test_areEqual_returns_0_for_arrays_with_same_contents_but_different_sequence",test_areEqual_returns_0_for_arrays_with_same_contents_but_different_sequence,"test_create_creates_ArrayUtil_instance_and_initializes_array_elements_with_0",test_create_creates_ArrayUtil_instance_and_initializes_array_elements_with_0,"test_resize_returns_shrinked_ArrayUtil_when_length_is_reduced",test_resize_returns_shrinked_ArrayUtil_when_length_is_reduced,"test_resize_returns_stretched_ArrayUtil_setting_extra_elements_to_0",test_resize_returns_stretched_ArrayUtil_setting_extra_elements_to_0,"test_resize_returns_stretched_resized_char_ArrayUtil_0_initialized_for_ArrayUtil_and_length",test_resize_returns_stretched_resized_char_ArrayUtil_0_initialized_for_ArrayUtil_and_length,"test_findIndex_returns_3_if_the_search_float_is_on_3rd_location",test_findIndex_returns_3_if_the_search_float_is_on_3rd_location,"test_findIndex_returns_neg_1_if_the_search_int_is_not_found",test_findIndex_returns_neg_1_if_the_search_int_is_not_found,"test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location",test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location,"test_findFirst_returns_6_when_asked_for_even_integers",test_findFirst_returns_6_when_asked_for_even_integers,"test_findFirst_returns_12_when_asked_for_integers_divisible_by_6",test_findFirst_returns_12_when_asked_for_integers_divisible_by_6,"test_forEach_runs_task_for_every_integer",test_forEach_runs_task_for_every_integer,"test_reduce_returns_sum_of_all_integers_of_array",test_reduce_returns_sum_of_all_integers_of_array,"test_count_returns_number_of_even_numbers_in_array_util",test_count_returns_number_of_even_numbers_in_array_util};
char testFileName[] = {"arrayUtilTest.c"};
void _setup(){/*CALL_SETUP*/}
void _teardown(){/*CALL_TEARDOWN*/}
void fixtureSetup(){}
void fixtureTearDown(){}
//code to be updated ends

int testCount;
int passCount;
int currentTestFailed;

int assert_expr(int expr, const char* fileName, int lineNumber, const char* expression){
	if(expr) return 0;
	currentTestFailed = 1;
	printf("\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
	return 1;
}
int assert_equal(int val1, int val2, const char* fileName, int lineNumber,const char* expr1,const char* expr2){
	if(val1 == val2) return 0;
	currentTestFailed = 1;
	printf("\t %d == %d: failed in assertEqual(%s,%s) at %s:%d\n",val1,val2,expr1,expr2, fileName,lineNumber);
	return 1;
}

void runTest(char* name, TestFn test){
	testCount++,currentTestFailed=0;
	printf("**  %s\n",name);
	_setup();
		test();
	_teardown();
	if(!currentTestFailed) passCount++;	
}
int main(int argc, char const *argv[]){		
	int i,total = sizeof(test)/sizeof(Test);	
	fixtureSetup();
	testCount=0,passCount=0;
	printf("**------ %s ------\n",testFileName);
	for (i = 0; i < total; ++i)
		runTest(test[i].name,test[i].fn);	
	printf("** Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
	fixtureTearDown();	
	return 0;
}