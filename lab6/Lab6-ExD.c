// lab6-ExD.c
//  Lab6 Exercise D - Fall 2015

/* The purpose of this exercise is to practice dynamic allocation of c-strings
 * on the memory. Also showing you a tiny step towards concept of data
 * abstraction that is a bigger topic taught later in this course (in C++).
 *
 * Note: Users of the struct String must be aware of it restrictions: Functions
 * in this program require the instances of String contain a valid c-string.
 * Notice that an array of characters with one element that contains a '\0' is
 * considered as an empty (but valid) c-string.
 */

#include "Lab6-ExD.h"

void test_copying(void);
void test_appending(void);
void test_truncating(void);

int main(void) {

#if 0
    test_copying();
#endif

#if 1
    test_truncating();
#endif

#if 1
    test_appending();
#endif

    return 0;
}

void create_empty_string (String *str) {

    if(str -> dynamic_storage != NULL)
        free(str -> dynamic_storage);

    str -> dynamic_storage = malloc (sizeof(char) * 1);
    if(str ->dynamic_storage == NULL) {
        printf("malloc failed ...\n");
        exit(1);
    }

    str -> dynamic_storage[0] = '\0';
    str -> length = 0;
}

void String_cpy(String *dest, const char* source) {

    if(dest -> dynamic_storage != NULL){
        free(dest->dynamic_storage);
        dest ->dynamic_storage = NULL;
    }

    if(source != NULL || source [0] != '\0' ) {
        // allocate storate space equal to length of source plus one for '\0'
        dest -> dynamic_storage = malloc(strlen(source)+1);
        if(dest -> dynamic_storage == NULL){
            printf("malloc failed: Memory was unavailable...\n");
            exit(1);
        }

        strcpy(dest -> dynamic_storage , source);
        dest -> length = (int)strlen(source);
    }
}

void String_copy(String *dest, const String* source) {
    if(dest -> dynamic_storage != NULL){
        free(dest->dynamic_storage);
        dest->dynamic_storage = NULL;
    }

    if(source ->dynamic_storage != NULL) {
        // allocate storate space equal to length of source plus one for '\0'
        dest -> dynamic_storage = malloc(strlen(source->dynamic_storage)+1);
        if(dest -> dynamic_storage == NULL){
            printf("malloc failed: Memory was unavailable...\n");
            exit(1);
        }

        strcpy(dest -> dynamic_storage , source ->dynamic_storage);
        dest -> length = source -> length;
    }
}

void display_String(const String* s){
    if(s -> length > 0)
        printf("%s      %zu\n", s->dynamic_storage, s -> length);
    else
        printf("%s      %zu\n", "String is empty", s -> length);
}


void String_append(String *dest, const String* source){
     char* old_storage = dest->dynamic_storage;
     dest->dynamic_storage = malloc((dest->length + source->length + 1) * sizeof(char));
     int i,j;
     for (i = 0; i < dest->length; i++)
        dest->dynamic_storage[i] = old_storage[i];
     for (j = 0; j < source->length; j++)
        dest->dynamic_storage[i+j] = source->dynamic_storage[j];
     dest->dynamic_storage[i+j] = '\0';
     dest->length += source->length;
     free(old_storage);
}

void String_truncate(String *dest, int new_length){
    if (new_length >= dest->length)
        return;
    char* old_storage = dest->dynamic_storage;
    dest->dynamic_storage = malloc((new_length + 1) * sizeof(char));
    int i;
    for (i = 0; i < new_length; i++) {
        dest->dynamic_storage[i] = old_storage[i];
    }
    dest->dynamic_storage[i] = '\0';
    dest->length = new_length;
    free(old_storage);
}


void test_copying(void){
    printf("\nTesting String_cpy and String_copy started: \n");

    String st1 = {NULL, 0};
    String st2 = {NULL, 0};
    String st3 = {NULL, 0};
    String st4 = {NULL, 0};

    // The following four lines creates instances of STring with valid
    // c-strings of length zero. Means it allocates one element for the
    //dynamic_storage and initializes that element with '\0'.
    create_empty_string(&st1);
    create_empty_string(&st2);
    create_empty_string(&st3);
    create_empty_string(&st4);

    display_String(&st1);     // displays: String is empty      0
    display_String(&st2);     // displays: String is empty      0
    display_String(&st3);     // displays: String is empty      0
    display_String(&st4);     // displays: String is empty      0

    //copies "William Shakespeare" int the string_stirage in object st1
    String_cpy(&st1, "William Shakespeare");

    // Must display: William Shakespeare      19
    display_String(&st1);

    String_cpy(&st2, "Aaron was Here!!!!");

    // Must display: Aaron was Here!!!!      18
    display_String(&st2);

    String_cpy(&st3, "But now he is in Italy");

    // Must display: But now he is in Italy      22
    display_String(&st3);

    //copies the  c-string in st4 into the string_storage in object st1
    String_copy(&st1, &st4);

    // Must display: String is empty      0
    display_String(&st1);

    String_cpy(&st2, "");
    // Must display: String is empty      0
    display_String(&st2);

    String_copy(&st2, &st3);
    // Must display: But now he is in Italy      22
    display_String(&st2);

    create_empty_string(&st2);

    // Must display: String is empty      0
    display_String(&st1);

    printf("\nTesting String_cpy and String_copy finished...\n");
    printf("------------------------------------------------------------\n");
}

void test_appending(void) {
    printf("\nTesting String_append started: \n");

    String st1 = {NULL, 0};
    String st2 = {NULL, 0};
    String st3 = {NULL, 0};
    String st4 = {NULL, 0};

    create_empty_string(&st1); // creates an empty object with a valid c-string
    create_empty_string(&st2); // creates an empty object with a valid c-string
    create_empty_string(&st3); // creates an empty object with a valid c-string
    create_empty_string(&st4); // creates an empty object with a valid c-string

    String_cpy(&st1, "Aaron was Here. ");

    // Must display: Aaron was Here.       16
    display_String(&st1);

    String_cpy(&st2, "He left a few minutes ago.");

    // Must display: He left a few minutes ago.      26
    display_String(&st2);

    String_append(&st4, &st3);

    // Must display: String is empty      0
    display_String(&st4);

    String_append(&st1, &st2);

    // Must display: Aaron was Here. He left a few minutes ago.      42
    display_String(&st1);

    create_empty_string(&st1);

    // Must display: String is empty      0
    display_String(&st1);

    String_cpy(&st1, "GET THE BALL ROLLING");

    // Must display: GET THE BALL ROLLING      20
    display_String(&st1);

    String_cpy(&st2, "!");
    String_append(&st1, &st2);

    // Must displays: GET THE BALL ROLLING!      21
    display_String(&st1);

    String_append(&st1, &st4);

    // Must display: GET THE BALL ROLLING!      21
    display_String(&st1);

    printf("\nTesting String_append finished...\n");
    printf("------------------------------------------------------------\n");
}

void test_truncating (void) {
    printf("\nTesting String_truncate started: \n");

    String st1 = {NULL, 0};
    String_cpy(&st1, "Computer Engineering.");

    // Must display: Computer Engineering.      21
    display_String(&st1);

    String_truncate(&st1, 8);

    // Must display: Computer      8
    display_String(&st1);

    String_truncate(&st1, 3);

    // Must displays: Com      3
    display_String(&st1);

    String_truncate(&st1, 7);

    // Must display: Com      3
    display_String(&st1);

    String_truncate(&st1, 1);

    // Must display: C      1
    display_String(&st1);

    String_truncate(&st1, 0);

    // Must display: String is empty      0
    display_String(&st1);

    String_cpy(&st1, "Truncate done Successfully.");

    // Must display: Truncate done Successfully.      27
    display_String(&st1);

    printf("\nTesting String_truncate finished... \n");
    printf("------------------------------------------------------------\n");
}
