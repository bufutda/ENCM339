// File: Lab6-F15-exB.c

#include <stdio.h>
#include <stdlib.h>

typedef struct IntVector{
    int* vector_storage;
    int size;
} IntVector;


int* build_and_populate (int n);

void create_binary_file(const IntVector * intV);

void display(const IntVector *intV);

void square_and_display(const IntVector* intV);

IntVector* read_binary_file (void);

int main(void) {

    IntVector intV1;
    intV1.size = 5;
    intV1.vector_storage = build_and_populate(intV1.size);
    display(&intV1);
    create_binary_file(&intV1);

    IntVector *intV2 = read_binary_file();
    // display(&intV1);
    square_and_display(intV2);
    free(intV1.vector_storage);

    // POINT 2 - Please write UNSAFE SAPCE beside the de-allocated spaces. Also
    // consider the values in the places deallocated "unknown" and show them with ??

    free(intV2 -> vector_storage);
    free(intV2);

    // POINT 3 - Please write UNSAFE SAPCE beside the de-allocated memories. Also
    // consider the values in the places deallocated "unknown" and show them with ??

    return 0;
}

int* build_and_populate (int n){
//5
    int * arr = malloc(n * sizeof (int));

    if(arr == NULL){
        printf("malloc failed: Memory was unavailable...");
        exit(1);
    }

    int i;
    for(i= 0; i < n; i++)
        arr[i] = (i+1) * 10;

    return arr;
}


void display(const IntVector* intV){
    printf("From function display:\n");
    int i;
    for (i = 0; i < intV ->size; i++ )
        printf("%10d\n", intV ->vector_storage[i]);
}

void square_and_display(const IntVector* intV){
    printf("\nFrom function square_and_display:\n");
    int i;
    for (i = 0; i < intV ->size; i++ )
        printf("%10d\n", intV ->vector_storage[i] *= intV ->vector_storage[i]);
    printf("hhhhhhh%d",intV->vector_storage[0]);
    // POINT ONE

}


void create_binary_file(const IntVector *intV){
    FILE *fp;
    char filename[30] = "numbers.bin";

    if((fp = fopen (filename, "wb")) == NULL){
        fprintf(stdin, "Sorry cannot open the binary file %s.", filename);
        exit(1);
    }

    size_t v = fwrite( intV -> vector_storage, sizeof(int) * intV->size, 1, fp);

    if(v != 1 ){
        fprintf(stderr, "writing to the file %s failed", filename);
        exit(1);
    }

    fclose(fp);
}




IntVector* read_binary_file(void) {
    char filename[100] = "numbers.bin";

    IntVector *arr = malloc(sizeof (IntVector));

    if(arr == NULL){
        printf("malloc faild: Memory was unavailable...");
        exit(1);
    }

    FILE *fp;

    if((fp = fopen (filename, "rb")) == NULL){
        fprintf(stdin, "Sorry cannot open the binary file %s.", filename);
        exit(1);
    }

    arr -> size = 0;
    int num;

    size_t v = fread(&num, sizeof(int), 1, fp);

    if(v == 1){
        arr->vector_storage = malloc(sizeof(int));
        if(arr->vector_storage == NULL){
            printf("malloc failed: Memory was unavailable...");
            exit(1);
        }
    }
    else {
        free(arr);
        return NULL;
    }

    while(1) {
        arr -> vector_storage[arr -> size] = num;
        arr -> size++;

        unsigned long v = fread(&num, sizeof(int), 1, fp);
        if(v < 1) break;

        arr->vector_storage = realloc(arr -> vector_storage, sizeof(int) *
                                                          (arr -> size + 1));
        if(arr -> vector_storage == NULL){
            printf("realloc faild: Memory was unavailable...");
            exit(1);
        }
    }

    fclose(fp);
    return arr;
}
