#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
} MyArray;

void initArray(MyArray *arr, int capacity){
    arr->data = (int *)malloc(capacity * sizeof(int));
    arr->capacity = capacity;

    for (int i = 0; i<capacity; i++){
        *(arr->data +i) = 0;
    }
}

void put(MyArray * arr, int key, int value){
    if (key >= arr->capacity || key <0){
        printf("Key Error");
        return;
    }
    *(arr->data + key) = value;
}

int get(MyArray * arr, int key){
    if (key >= arr->capacity || key <0){
        printf("Key Error");
        return -1;
    }
    return *(arr->data+key);
}

void freeArray(MyArray * arr){
    free(arr->data);
}

int main(){
    MyArray arr;
    initArray(&arr, 5);

    put(&arr, 0, 10);
    put(&arr, 1, 20);
    put(&arr, 2, 30);

    for (int i = 0; i < arr.capacity; i++){
        printf("Index %d: %d\n", i, *(arr.data + i));
    }

    printf("Value at key 0: %d", get(&arr, 0));

    printf("Value at key 7: %d", get(&arr, 7));




    freeArray(&arr);
}