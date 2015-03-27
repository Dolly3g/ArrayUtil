#include "expr_assert.h"
int x;
void setup(){
	x = 5;
}
void teardown(){
	x = 0;
}
void test_pass(){
	assert(3*2 == 6);
}
void test_fail(){
	assert(5 == 4);
}

void test_start_at_5(){
	assert(x == 5);
	x++;
}

void test_goto_6(){
	assertEqual(x,6);
}