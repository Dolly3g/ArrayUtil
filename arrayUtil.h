typedef struct ArrayUtil ArrayUtil;

struct ArrayUtil {
	void* base_ptr;
	int typesize;
	int length;
};

int areEqual(ArrayUtil a,ArrayUtil b);
ArrayUtil create(int,int);
ArrayUtil resize(ArrayUtil a,int length);
ArrayUtil initializeArrayUtil(void* , int,int);
int findIndex(ArrayUtil,void*);