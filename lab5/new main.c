#include <stdio.h>
#include <stdlib.h>

typedef struct array_list{
	int n;
	int* (*get_int_array_list)(int);
	void (*set_value_list)(int*, int);
	void (*print_array_list)(int*, int);
} array_list_t;

int* get_int_array(int n) {
    int* arr = (int*)calloc(n, sizeof(int));
    return arr;
}

void set_value(int* p, int v) {
    *p = v;
}
void print_array(int* p, int n) {
    printf("[");
    for(int i = 0; i < n; i++) i != n-1 ? printf("%d, ", *(p+i)) : printf("%d]", *(p+(n-1)));
}

char* ptr;
char* func(char a[], char b[]) {
	int len_a = 0;
	int len_b = 0;
	while(a[len_a++]);
	while(b[len_b++]);
	ptr = (char*)calloc(len_a + len_b - 1, sizeof(char));
	for(int i = 0; i < len_a - 1; i++) {
		ptr[i] = a[i];
	}
	for(int i = 0; i < len_b - 1; i++) {
		ptr[len_a - 1 + i] = b[i];
	}
	ptr[len_a + len_b - 1] = '\0';
	return ptr;
}

char* add_str_func(char a[], char b[], char* (*func_ptr)(char*, char*)) {
	return func_ptr(a, b);
}

int main(void) {
    printf("No.1 ——————————\n");
    int n = 10;
    int *ip = get_int_array(n);
    
    for(int i = 0; i < n; i++) set_value(ip+i, i+1);
    
    print_array(ip, n);
    free(ip);
    ip = NULL;
  	printf("\nNo.2 -------------------\n");
  	array_list_t p;
	  p.n = 20;
	  p.get_int_array_list = get_int_array;
	  p.set_value_list = set_value;
	  p.print_array_list = print_array;
	  int* iptr = p.get_int_array_list(p.n);
	  for(int i = 0; i < p.n; i++) {
		  p.set_value_list(iptr + i, i + 1);
	  }
	  p.print_array_list(iptr, p.n);
	  printf("\nNo.3 -------------------\n");
	  char a[] = "IU!IU!";
	  char b[] = "@CGU";
	  printf("add_str_func = %s\n", add_str_func(a, b, func));
	  free(ip);
	  free(iptr);
	  free(ptr);
	  return 0;
}
