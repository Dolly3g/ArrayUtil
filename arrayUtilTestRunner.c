#include <stdio.h>
typedef void TestFn(void);
typedef struct{
	char* name; 
	TestFn* fn;
} Test;

//code to be updated starts
TestFn setup,teardown,fixtureSetup,fixtureTearDown,test_areEqual_returns_1_for_same_arrays,test_areEqual_returns_0_for_different_arrays,test_areEqual_returns_0_for_arrays_with_same_contents_but_different_sequence,test_create_returns_ArrayUtil_instance_for_typesize_and_length,test_resize_returns_shrinked_resized_ArrayUtil_for_ArrayUtil_and_length,test_resize_returns_lareger_resized_ArrayUtil_0_initislized_for_ArrayUtil_and_length,test_findIndex_returns_the_3_if_the_search_element_is_on_3rd_location,test_findIndex_returns_neg_1_if_the_search_element_not_found,test_dispose_returns,test_findFirst_returns_6_when_asked_for_even_number,test_findFirst_12_when_asked_for_divisible_by_6;
Test test[] = {"test_areEqual_returns_1_for_same_arrays",test_areEqual_returns_1_for_same_arrays,"test_areEqual_returns_0_for_different_arrays",test_areEqual_returns_0_for_different_arrays,"test_areEqual_returns_0_for_arrays_with_same_contents_but_different_sequence",test_areEqual_returns_0_for_arrays_with_same_contents_but_different_sequence,"test_create_returns_ArrayUtil_instance_for_typesize_and_length",test_create_returns_ArrayUtil_instance_for_typesize_and_length,"test_resize_returns_shrinked_resized_ArrayUtil_for_ArrayUtil_and_length",test_resize_returns_shrinked_resized_ArrayUtil_for_ArrayUtil_and_length,"test_resize_returns_lareger_resized_ArrayUtil_0_initislized_for_ArrayUtil_and_length",test_resize_returns_lareger_resized_ArrayUtil_0_initislized_for_ArrayUtil_and_length,"test_findIndex_returns_the_3_if_the_search_element_is_on_3rd_location",test_findIndex_returns_the_3_if_the_search_element_is_on_3rd_location,"test_findIndex_returns_neg_1_if_the_search_element_not_found",test_findIndex_returns_neg_1_if_the_search_element_not_found,"test_dispose_returns",test_dispose_returns,"test_findFirst_returns_6_when_asked_for_even_number",test_findFirst_returns_6_when_asked_for_even_number,"test_findFirst_12_when_asked_for_divisible_by_6",test_findFirst_12_when_asked_for_divisible_by_6};
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