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
void* findFirst (ArrayUtil, int(*)(void*,void*),void*);
void forEach (ArrayUtil,void(*)(void*,void*),void*);
void* reduce (ArrayUtil,void*(*)(void*,void*,void*),void*,void*);
int count (ArrayUtil,int(*)(void*,void*),void*);