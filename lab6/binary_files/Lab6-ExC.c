// File: Lab6-F15-exC.c
// Lab 6 - Exercise C - Fall 2015

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct IntVector{

    // an integer pointer that is supposed to point to a dynamically allocated
    // array. To be safely used, should be always pointing to a dynamically
    // allocated space or to be set to NULL.
    int* vector_storage;

    // represents the size of the array that vector_storage points to. Will be
    // zero if vector_storage is a NULL-pointer
    int size;

} IntVector;

void display_array(const IntVector *arr);
/*
 * PROMISES:
 * if array is not empty (vector_storage != NULL), displays the integer values
 * in vector_storage[0] to vector_storage[size-1], one value per line.
 */

IntVector* read_binary_file (void);
/*
 * PROMISES:
 * - opens a binary file stream. Terminates the program if unable to access
 *   and open the stream,
 * - dynamically creates an object of IntVector,
 * - reads a number as stream of bytes (sizeof(int)) from binary file
 *   (one at a time), expands the size of the storage on the heap, as needed and
 *   places that number into the newly allocated element of the array,
 * - at the end it closes the file.
 * PLEASE NOTICE: the memory management policy used in this small exercise
 * is not an efficient policy. A better policy could be to reallocate the
 * memory in a bigger block (say n elements) and when the n elements are used,
 * then call the function realloc to expand the size of the array with again
 * of the same size block.
 */

void save_table(const IntVector *arr,  int k);

/* REQUIRES:
 *  arr pointing to an object of IntVector.
 *  0 < k <= arr->size.
 *
 * PROMISES:
 *  The existing integer numbers in an array that arr->vector_stroage points to,
 *  should be saved into a text file called table.txt, in a tabular format with
 *  k columns.
 *  Each number must be saved in a field of 5. For example if the value in one of
 *  the elements of arr->vector->storage is 45, it will be printed as: ***45
 *  (assume each asterisk represents a blank space).
 */

int main(void) {

    IntVector *intArr;
    intArr = read_binary_file();
    if(intArr != NULL)
        display_array(intArr);
    else
        return 0;

    int col = 11;
    save_table(intArr, col);

    free(intArr->vector_storage);
    free (intArr);

    return 0;
}

void display_array(const IntVector* array) {
    int i;
    for (i =0; i < array ->size; i++ )
        printf("%10d\n", array ->vector_storage[i]);
}

IntVector* read_binary_file(void) {
    char filename[100];
    IntVector *arr = malloc(sizeof (IntVector));
    if(arr == NULL){
        printf("malloc faild: Memory was unavailable...\n");
        exit(1);
    }
    FILE *fp;
    printf("\nEnter the name of binary file to open and to read from: ");
    fgets(filename, 100, stdin);

    if(filename[strlen(filename)-1] == '\n')
      filename[strlen(filename)-1] = '\0';


    if((fp = fopen (filename, "rb")) == NULL){
        fprintf(stdout, "Sorry cannot open the binary file %s.\n", filename);
        exit(1);
    }

    arr -> size = 0;
    int num;
    unsigned long v = fread(&num, sizeof(int), 1, fp);
    if(v == 1){
        arr->vector_storage = malloc(sizeof(int));
        if(arr->vector_storage == NULL){
            printf("malloc failed: Memory was unavailable...\n");
            exit(1);
        }
    }
    else return NULL;

    while(1) {
        arr -> vector_storage[arr -> size] = num;
        (arr -> size)++;


        unsigned long v = fread(&num, sizeof(int), 1, fp);
        if(v < 1) break;
        // reallocate memory and check if it was a successful operation
        if((arr->vector_storage = realloc(arr -> vector_storage, sizeof(int) * (arr -> size + 1))) == NULL){
            printf("realloc faild: Memory was unavailable...\n");
            exit(1);
        }

    }

    fclose(fp);
    return arr;
}

void save_table(const IntVector *arr, int k){
    /* REQUIRES:
     *  arr pointing to an object of IntVector.
     *  0 < k <= arr->size.
     *
     * PROMISES:
     *  The existing integer numbers in an array that arr->vector_stroage points to,
     *  should be saved into a text file called table.txt, in a tabular format with
     *  k columns.
     *  Each number must be saved in a field of 5. For example if the value in one of
     *  the elements of arr->vector->storage is 45, it will be printed as: ***45
     *  (assume each asterisk represents a blank space).
     */

     char filename[10] = "table.txt";
     int i, j;
     FILE* fp = fopen(filename, "w");
     if (fp == NULL) {
         printf("Sorry, could not save text file table.txt");
         exit(1);
     }
     for (i = 0, j = 0; i < arr->size; i++, j++) {
         if (j == k) {
             fwrite("\n", 1, 1, fp);
             j = 0;
         }
         size_t n = fprintf(fp, "%5d", arr->vector_storage[i]);
         if (n != 5) {
             printf("Sorry, could not save text file table.txt");
             exit(1);
         }
     }
     fclose(fp);
}
