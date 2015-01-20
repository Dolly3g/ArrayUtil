typedef struct ArrayUtil ArrayUtil;

struct ArrayUtil {
	void* base_ptr;
	int typesize;
	int length;
};

int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil create(int,int);
ArrayUtil resize(ArrayUtil,int);
ArrayUtil initializeArrayUtil(void*,int,int);
int findIndex(ArrayUtil,void*);
void dispose(ArrayUtil);