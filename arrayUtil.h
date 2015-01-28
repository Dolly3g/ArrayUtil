typedef struct ArrayUtil ArrayUtil;
typedef char* String;
typedef int int10[10];
typedef float float5[5];
typedef struct Stud { char name[27]; int clas ; float percentage; } Student;
typedef void *void_star;
typedef char *char_star;
typedef int *int_star;
typedef float *float_star;
typedef int (MatchFunc)(void*,void*);



#define log(test_description) int log = (printf("\t     %s\n\n", test_description))
#define sizeOf_char sizeof(char)
#define sizeOf_int sizeof(int)
#define sizeOf_float sizeof(float)
#define sizeOf_double sizeof(double)
#define sizeOf_String sizeof(String)
#define sizeOf_Student sizeof(Student)
#define sizeOf_int10 sizeof(int10)
#define sizeOf_float5 sizeof(float5)
#define sizeOf_void_star sizeof(void_star)
#define sizeOf_char_star sizeof(char_star)
#define sizeOf_int_star sizeof(int_star)
#define sizeOf_float_star sizeof(float_star)
#define YES 1
#define NO 0

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
void map(ArrayUtil, ArrayUtil,void(*)(void*,void*,void*), void*);
void* reduce (ArrayUtil,void*(*)(void*,void*,void*),void*,void*);
int count (ArrayUtil,int(*)(void*,void*),void*);
void* findLast (ArrayUtil,int(*)(void*,void*),void*);
int filter(ArrayUtil,int(*)(void*,void*),void*,void**,int);