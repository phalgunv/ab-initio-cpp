#include <assert.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


void *malloc1(size_t size) {
  void *p = sbrk(0);
  void *request = sbrk(size);
  if (request == (void*) -1) {
    return NULL; // sbrk failed.
  } else {
    assert(p == request); // Not thread safe.
    return p;
  }
}


int main()
{
	int b = 4;
	int *a = (int *)malloc1(sizeof(int)*b);
	printf("sizeof a is %d",b);
	printf("%x",a);
}
	
