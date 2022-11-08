/* generic_list.c */

#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

void int64_t_print(int64_t i) { printf("%" PRId64, i); }
void double_print(double d) { printf("%lf", d); }
void float_print(float f) {printf("%f", f);}
void newline_print() { puts(""); }

#define DEFINE_LIST(type)               				\                                
  struct list_##type {                                                  \
    type value;                                                         \
    struct list_##type* next;                                           \
  }; \
  struct list_##type* create_list_##type(type val){\
    struct list_##type* list = malloc(sizeof(struct list_##type));\
    if (list == NULL) return NULL;\
    list->value = val;\
    list->next = NULL;\
    return list;\
  };\
  void list_##type##_push(struct list_##type* head, type val){ \
    struct list_##type* next = create_list_##type(val);\
    if (next == NULL) return;\
    while (head->next != NULL){\
        head = head->next;\
    };\
    head->next = next;\
  }; \
  void list_##type##_print(struct list_##type* list){ \
    bool first = true;\
    while (list != NULL){\
        if (!first) {printf("->");}\
        else {first = false;}\
        type##_print(list->value);\
        list = list->next;\
    }\
    newline_print();\
  };
DEFINE_LIST(int64_t)
DEFINE_LIST(double)
DEFINE_LIST(float)

int main(){
    struct list_int64_t* list1 = create_list_int64_t(1);
    list_int64_t_push(list1, (int64_t) 2);
    list_int64_t_push(list1, (int64_t) 3);
    list_int64_t_print(list1);
    
    struct list_double* list2 = create_list_double(1.0);
    list_double_push(list2, 2.0);
    list_double_push(list2, 3.0);
    list_double_print(list2);
    
    struct list_float* list3 = create_list_float(1.0);
    list_float_push(list3, (float) 2.0);
    list_float_push(list3, (float) 3.0);
    list_float_print(list3);
    
    return 0;
};






