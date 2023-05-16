#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int global_init = 10;
int global_not_init[1000000];
const int global_const = 20;

char *global_pstr = "global hello";

/*пункт d*/
void f2() {
    int a = 1234567;
    printf("f2: %d\n", a);
}

/*пункт e*/
void change_buffer(void) {//функция из пункта "e"
    char *buffer = malloc(100);
    if (buffer == NULL) {
        printf("Failed to allocate memory for the buffer!\n");
        return;
    }
    strcpy(buffer, "hello world");
    printf("Buffer: %s\n", buffer);
    free(buffer);


    printf("Buffer after free: %s\n", buffer);

    char *buffer2 = malloc(100);
    if (buffer2 == NULL) {
        printf("Failed to allocate memory for the second buffer!\n");
        return;
    }

    strcpy(buffer2, "hello world");
    printf("Second buffer: %s\n", buffer2);

    char *mid = buffer2 + (strlen(buffer2) / 2);
    printf("Pointer to the middle of the second buffer: %s\n", mid);

    free(mid);

    printf("Second buffer after free pointed to by the pointer to the middle: %s\n", buffer2);

    free(buffer2);
}


int *get_unexist_adress() {
    int x = 42;
    int *ptr = &x;
    return ptr;
}

/* пункт а*/
void f() {
    int local;
    static int static_not_init;
    static int static_init = 5;

    char *local_pstr = "local hello";

    const int local_const = 30;

    char local_arr[] = "local hello array";

    printf("\nf vars:\n");
    printf("local:            %p (%d)\n", &local, local);
    printf("static_init:      %p (%d)\n", &static_init, static_init);
    printf("static_not_init:  %p (%d)\n", &static_not_init, static_not_init);
    printf("local_pstr:       %p %p (%s)\n", &local_pstr, local_pstr, local_pstr);
    printf("local_const:      %p (%d)\n", &local_const, local_const);
    printf("local_arr:        %p %p (%s)\n", &local_arr, &local_arr[5], local_arr);
}

//TODO
int main(void) {
    printf("function f() address:     %p\n", f);

    printf("\nglobal vars:\n");

    printf("global_init:      %p (%d)\n", &global_init, global_init);
    printf("global_not_init:  %p %p (%d)\n", &global_not_init, &global_not_init[8100], global_not_init);
    printf("global_pstr:      %p %p (%s)\n", &global_pstr, global_pstr, global_pstr);
    printf("global_const:     %p (%d)\n", &global_const, global_const);

    f();
    f2();

    printf("pid: %d\n", getpid());

    // get_unexist_adress();
    // change_buffer();

    sleep(50);
    return 0;
}

//TODO b,c