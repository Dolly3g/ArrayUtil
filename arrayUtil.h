typedef struct ArrayUtil ArrayUtil;

struct ArrayUtil {
	void* base_ptr;
	int typesize;
	int length;
};

int areEqual(ArrayUtil a,ArrayUtil b);
ArrayUtil create(int typesize,int length);
ArrayUtil initializeArrayUtil(void* , int,int);