#ifndef SEAMLESS_STACK_FRAME_IMPL
#define SEAMLESS_STACK_FRAME_IMPL

struct _stack
{
	int  (*push) (void *,       const void *);
	int  (*pop)  (void *,       void *);
	int  (*peek) (const void *, void *);
	int  (*empty)(const void *);
	void (*dest) (void *);
	char _stack[];
};

#endif // SEAMLESS_STACK_FRAME_IMPL
