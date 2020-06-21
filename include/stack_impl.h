#ifndef SEAMLESS_STACK_FRAME_IMPL
#define SEAMLESS_STACK_FRAME_IMPL

/* Таблица виртуальных функций интерфейса стека */
struct _stackvft
{
    int (*push)(void *, const void *);
    int (*pop) (void *, void *);
    int (*peek)(const void *, void *);
    int (*empty)(const void *);
    void (*dest)(void *);
};

/* База для стеков */
struct _stack
{
    struct _stackvft *vftptr; // Указатель на таблицу
    char _stack[]; // Указатель на реализацию
};

#endif // SEAMLESS_STACK_FRAME_IMPL
