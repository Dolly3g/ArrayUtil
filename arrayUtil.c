typedef struct ArrayUtil ArrayUtil;

struct ArrayUtil {
	void* base_ptr;
	int typesize;
	int length;
};

int array[] = {1,2,3};
ArrayUtil a;


