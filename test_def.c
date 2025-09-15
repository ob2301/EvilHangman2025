#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"
Status test_oboukantar_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
    MY_STRING hString = NULL;
    Status status = FAILURE;
    hString = my_string_init_default();
    if(my_string_get_capacity(hString) != 7)
 {
    printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
    strncpy(buffer, "test_oboukantar_get_capacity_on_init_default_returns_7\n"
    "Did not receive 7 from get_capacity after init_default\n", length);
 }
    else
 {
 status = SUCCESS;
 strncpy(buffer, "test_oboukantar_get_capacity_on_init_default_returns_7\n"
 , length);
 }
 my_string_destroy(&hString);
 return status;
}

Status test_oboukantar_my_string_c_str_returns_correct_NULL_terminated_string(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("Hello World");
    int bad = 0;
    char* correct = "Hello World";
    char* compare= my_string_c_str(hMy_string1);
    int b=0;
    for (int i = 0; correct[i] != '\0'; i++) {
         b++;
    }
    if (11==b) {
         for (int i = 0; i<b; i++) {
             if (correct[i] != compare[i]) {
                 bad++;
                 break;
             }
         }
    }
    else {
         bad++;
    }
    if (bad != 0) {
        printf("Expected 'Hello World' from my_string_c_str but got '%s\n'", compare);
        strncpy(buffer, "test_oboukantar_my_string_c_str_returns_correct_NULL_terminated_string\n"
        "Did not receive correct NULL terminated string from my_string_c_str\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_c_str_returns_correct_NULL_terminated_string\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_destroy_sets_pointer_to_NULL(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_default();
    my_string_destroy(&hMy_string1);
    if (hMy_string1 != NULL) {
        printf("Expected MY_STRING object to be 0x0 (NULL) after calling my_string_destroy but got %p\n", hMy_string1);
        strncpy(buffer, "test_oboukantar_my_string_destroy_sets_pointer_to_NULL\n"
        "Did not set MY_STRING object to 0x0 (NULL)\n", length);
    }
    else
    {
	status = SUCCESS;    
        strncpy(buffer, "test_oboukantar_my_string_destroy_sets_pointer_to_NULL\n"
        , length);
    }
    return status;
}
Status test_oboukantar_my_string_extraction_returns_success_on_success(char* buffer, int length) {
    FILE* fp;
    if ((fp = fopen("dictionary.txt", "r")) == NULL) {
        exit(1);
    }
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_default();
    status = my_string_extraction(hMy_string1, fp);
    if (status != SUCCESS)
    {
        printf("Expected 1 (SUCCESS) from my_string_extraction but got %d\n", status);
        strncpy(buffer, "test_oboukantar_my_string_extraction_returns_success_on_success\n"
        "Did not receive 1 (SUCCESS) from my_string_extraction\n", length);
    }
    else
    {
        strncpy(buffer, "test_oboukantar_my_string_extraction_returns_success_on_success\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    fclose(fp);
    return status;
}
Status test_oboukantar_my_string_concat_increases_right_amount_of_capacity(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("Hello ");
    MY_STRING hMy_string2 = my_string_init_c_string("World");
    my_string_concat(hMy_string1, hMy_string2);
    if (my_string_get_capacity(hMy_string1) != 12)
    {
        printf("Expected 12 from my_string_get_capacity after my_string_concat but got %d\n", my_string_get_capacity(hMy_string1));
        strncpy(buffer, "test_oboukantar_my_string_concat_increases_right_amount_of_capacity\n"
        "Did not receive 12 from my_string_get_capacity after my_string_concat\n", length);
    }
    else
    {
	status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_concat_increases_right_amount_of_capacity\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    my_string_destroy(&hMy_string2);
    return status;
}
Status test_oboukantar_my_string_concat_increases_right_amount_of_size(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("Hello ");
    MY_STRING hMy_string2 = my_string_init_c_string("World");
    my_string_concat(hMy_string1, hMy_string2);
    if (my_string_get_size(hMy_string1) != 11)
    {
        printf("Expected 11 from my_string_get_size after my_string_concat but got %d\n", my_string_get_size(hMy_string1));
        strncpy(buffer, "test_oboukantar_my_string_concat_increases_right_amount_of_size\n"
        "Did not receive 11 from my_string_get_size after my_string_concat\n", length);
    }
    else
    {
        status = SUCCESS;
	strncpy(buffer, "test_oboukantar_my_string_concat_increases_right_amount_of_size\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    my_string_destroy(&hMy_string2);
    return status;
}
Status test_oboukantar_my_string_insertion_returns_success_on_success(char* buffer, int length) {
     Status status = FAILURE;
     MY_STRING hMy_string1 = my_string_init_c_string("Hello World");
     printf("Output from my_string_insertion: ");
     status = my_string_insertion(hMy_string1, stdout);
     printf("\n");
     if (status != SUCCESS)
     {
         printf("Expected 1 (SUCCESS) from my_string_insertion but got %d\n", status);
         strncpy(buffer, "test_oboukantar_my_string_insertion_returns_success_on_success\n"
         "Did not receive 1 (SUCCESS) from my_string_insertion\n", length);
     }
    else {
        strncpy(buffer, "test_oboukantar_my_string_insertion_returns_success_on_success\n"
        , length);

    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_push_back_increases_right_amount_of_capacity(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("Hello World");
    my_string_push_back(hMy_string1, '!');
    my_string_push_back(hMy_string1, '!');
    if (my_string_get_capacity(hMy_string1) != 24)
    {
        printf("Expected 24 from my_string_get_capacity but got %d\n", my_string_get_capacity(hMy_string1));
        strncpy(buffer, "test_oboukantar_my_string_push_back_increases_right_amount_of_capacity\n"
        "Did not receive 24 for string with 13 characters from my_string_get_capacity after my_string_push_back twice on string with 11 characters\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_push_back_increases_right_amount_of_capacity\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_push_back_increases_right_amount_of_size(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("Hello World");
    my_string_push_back(hMy_string1, '!');
    if (my_string_get_size(hMy_string1) != 12)
    {
        printf("Expected 12 from my_string_get_size but got %d\n", my_string_get_size(hMy_string1));
        strncpy(buffer, "test_oboukantar_my_string_push_back_increases_right_amount_of_size\n"
        "Did not receive 12 for string with 12 characters from my_string_get_size after my_string_push_back on string with 11 characters\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_push_back_increases_right_amount_of_size\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_pop_back_decreases_right_amount_of_size(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("Hello World");
    my_string_pop_back(hMy_string1);
    if (my_string_get_size(hMy_string1) != 10)
    {
        printf("Expected 10 from my_string_get_size but got %d\n", my_string_get_size(hMy_string1));
        strncpy(buffer, "test_oboukantar_my_string_pop_back_decreases_right_amount_of_size\n"
        "Did not receive 10 for string with 10 characters from my_string_get_size after my_string_pop_back on string with 11 characters\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_pop_back_decreases_right_amount_of_size\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_at_returns_NULL_if_index_out_of_bounds(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("Hello");
    char *b = my_string_at(hMy_string1, 5);
    if (b != NULL)
    {
       printf("Expected 'NULL' from my_string_at but got '%c\n'", *b);
       strncpy(buffer, "test_oboukantar_my_string_at_returns_NULL_if_index_out_of_bounds\n"
       "Did not receive NULL for index out of bouncds from my_string_at\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_at_returns_NULL_if_index_out_of_bounds\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_at_returns_correct_character_at_valid_index(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string = my_string_init_c_string("Hello");
    char* temp = my_string_at(hMy_string, 1);
    if ('e' !=*temp) {
        printf("Expected 'e' from my_string_at but got '%c\n'", *temp);
        strncpy(buffer, "test_oboukantar_my_string_at_returns_correct_character_at_valid_index\n"
        "Did not receive correct character at index 1 from my_string_at\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_at_returns_correct_character_at_valid_index\n"
        , length);
    }
    my_string_destroy(&hMy_string);
    return status;
}
Status test_oboukantar_my_string_init_c_string_creates_correct_string(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("Hello World");
    int bad = 0;
    char* correct = "Hello World";
    char* compare= my_string_c_str(hMy_string1);
    int b=0;
    for (int i = 0; correct[i] != '\0'; i++) {
         b++;
    }
    if (11==b) {
         for (int i = 0; i<11; i++) {
             if (correct[i] != compare[i]) {
                 bad++;
                 break;
             }
         }
    }
    else {
         bad++;
    }
    if (bad != 0) {
        printf("Expected 'Hello World' to be created from my_string_init_c_string but got '%s\n'", compare);
        strncpy(buffer, "test_oboukantar_my_string_init_c_string_creates_correct_string\n"
        "Correct string not created through my_string_init_c_string\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_init_c_string_creates_correct_string\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_empty_returns_false_on_NON_empty_string(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_c_string("hello");
    if (my_string_empty(hMy_string1) != FALSE)
    {
        printf("Expected 0 (for FALSE) from my_string_empty but got %d\n", my_string_empty(hMy_string1));
        strncpy(buffer, "test_oboukantar_test_my_string_empty_returns_false_on_NON_empty_string\n"
        "Did not receive FALSE for NON-empty string from my_string_empty\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_test_my_string_empty_returns_false_on_NON_empty_string\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_empty_returns_true_on_empty_string(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string1 = my_string_init_default();
    if (my_string_empty(hMy_string1) != TRUE)
    {
        printf("Expected 1 (for TRUE) from my_string_empty but got %d\n", my_string_empty(hMy_string1));
        strncpy(buffer, "test_oboukantar_test_my_string_empty_returns_true_on_empty_string\n"
        "Did not receive TRUE for empty string from my_string_empty\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_test_my_string_empty_returns_true_on_empty_string\n"
        , length);
    }
    my_string_destroy(&hMy_string1);
    return status;
}
Status test_oboukantar_my_string_concat_returns_correct_string(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hResult = my_string_init_c_string("String1+");
    MY_STRING hAppend = my_string_init_c_string("String2");

    my_string_concat(hResult, hAppend);

    int works = 0;
    char* one = "String1+String2";
    char* two = my_string_c_str(hResult);

    int count2 = 0;

    for (int i = 0; two[i] != '\0'; i++) {
        count2++;
    }

    if (15 == count2) {
        for (int i = 0; i<count2; i++) {
            if (one[i] != two[i]) {
                works++;
            }
        }
    } else {
        works++;
    }
    if (works !=0)
    {
        printf("Expected string 'String1+String2' but got '%s\n'", my_string_c_str(hResult));
        strncpy(buffer, "test_oboukantar_my_string_concat_returns_correct_string\n"
        "Did not receive correct string from my_string_concat\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_concat_returns_correct_string\n"
        , length);
    }
    my_string_destroy(&hResult);
    my_string_destroy(&hAppend);
    return status;
}
Status test_oboukantar_my_string_pop_back_deletes_last_character_in_string(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string = NULL;
    hMy_string = my_string_init_c_string("dog");
    my_string_pop_back(hMy_string);

    int bad = 0;
    char* one = my_string_c_str(hMy_string);
    char* correct = "do";

    int count = 0;
    for (int i = 0; one[i] != '\0'; i++) {
        count++;
    }
    if (count == 2) {
        for (int i = 0; one[i] != '\0'; i++) {
            if (one[i] != correct[i]) {
                bad++;
                break;
            }
        }
    }
    else {
        bad++;
    }
    
    if (bad !=0)
    {
        printf("Expected string 'do' but got '%s\n'", my_string_c_str(hMy_string));
        strncpy(buffer, "test_oboukantar_my_string_pop_back_deletes_last_character_in_string\n"
        "Did not receive correct string from my_string_pop_back\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_pop_back_deletes_last_character_in_string\n"
        , length);
    }

    my_string_destroy(&hMy_string);
    return status;
}
Status test_oboukantar_my_string_push_back_creates_correct_new_string(char* buffer, int length) {
    Status status = FAILURE;
    MY_STRING hMy_string = NULL;
    hMy_string = my_string_init_default();

    my_string_push_back(hMy_string, 'd');
    my_string_push_back(hMy_string, 'o');
    my_string_push_back(hMy_string, 'g');

    int works = 0;
    char* one = "dog\0";
    char* two = my_string_c_str(hMy_string);

    int count2 = 0;

    for (int i = 0; two[i] != '\0'; i++) {
        count2++;
    }

    if (3 == count2) {
        for (int i = 0; i<count2; i++) {
            if (one[i] != two[i]) {
                works++;
            }
        }
    } else {
        works++;
    }
    if (works !=0)
    {
        printf("Expected string 'dog' but got '%s\n'", my_string_c_str(hMy_string));
        strncpy(buffer, "test_oboukantar_my_string_push_back_creates_correct_new_string\n"
        "Did not receive correct string after my_string_push_back\n", length);
    }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_my_string_push_back_creates_correct_new_string\n"
        , length);
    }

    my_string_destroy(&hMy_string);
    return status;
}
Status test_oboukantar_get_pos_value_on_my_string_compare(char* buffer, int length)
{
    Status status = FAILURE;

     MY_STRING apple1=my_string_init_c_string("apple");
     MY_STRING apple2=my_string_init_c_string("app");
     int check = my_string_compare(apple1, apple2);
     if (check <= 0||check==0xBEEF)
        {
        printf("Expected positive value but got %d\n", my_string_compare(apple1, apple2));
        strncpy(buffer, "test_oboukantar_get_pos_value_on_my_string_compare\n"
        "Did not receive positive value from my_string_compare when left string was larger\n", length);
        }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_get_pos_value_on_my_string_compare\n"
        , length);
    }

    my_string_destroy(&apple1);
    my_string_destroy(&apple2);
    return status;
}
Status test_oboukantar_get_neg_value_on_my_string_compare(char* buffer, int length)
{
    Status status = FAILURE;

    MY_STRING apple1 = my_string_init_c_string("app");
    MY_STRING apple2 = my_string_init_c_string("apple");
    if (my_string_compare(apple1, apple2) >= 0){
        printf("Expected negative value but got %d\n", my_string_compare(apple1, apple2));
        strncpy(buffer, "test_oboukantar_get_neg_value_on_my_string_compare\n"
        "Did not receive negative value from my_string_compare when left string was smaller\n", length);
        }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_get_neg_value_on_my_string_compare\n"
        , length);
    }

    my_string_destroy(&apple1);
    my_string_destroy(&apple2);
    return status;
}
Status test_oboukantar_get_zero_on_same_my_string_compare(char* buffer, int length)
{
    Status status = FAILURE;

    MY_STRING apple1 = my_string_init_c_string("apple");
    MY_STRING apple2 = my_string_init_c_string("apple");

    if (my_string_compare(apple1, apple2) != 0)
        {
        printf("Expected zero but got %d\n", my_string_compare(apple1, apple2));
        strncpy(buffer, "test_oboukantar_get_zero_on_same_my_string_compare\n"
        "Did not receive 0 from my_string_compare after comparing two same strings\n", length);
        }
    else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_get_zero_on_same_my_string_compare\n"
        , length);
    }
    
    my_string_destroy(&apple1);
    my_string_destroy(&apple2);
    return status;
}
Status test_oboukantar_get_capacity_of_six_on_init_hello(char* buffer, int length)
{   
    Status status = FAILURE;
    MY_STRING hString = NULL;
    hString = my_string_init_c_string("hello");
    if(my_string_get_capacity(hString) != 6)
    {
        printf("Expected a capacity of 6 but got %d\n", my_string_get_capacity(hString));
        strncpy(buffer, "test_oboukantar_get_capacity_of_six_on_init_hello\n"
        "Did not receive 6 from get_capacity after init of hello\n", length);
    }
else
    {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_get_capacity_of_six_on_init_hello\n"
        , length);
    }
    my_string_destroy(&hString);
    return status;
}
Status test_oboukantar_get_size_of_five_on_init_hello(char* buffer, int length)
{
   Status status = FAILURE;	
   MY_STRING hString = NULL;
   hString = my_string_init_c_string("hello");
   if(my_string_get_size(hString) != 5)
   {
        printf("Expected a size of 5  but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_oboukantar_get_size_of_five_on_init_hello\n"
        "Did not receive 5 from get_size after init of hello\n", length);
 }
        else
 {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_get_size_of_five_on_init_hello\n"
        , length);
 }
        my_string_destroy(&hString);
        return status;
}
Status test_oboukantar_init_default_returns_nonNULL(char* buffer, int length)
{
        Status status = FAILURE;
        MY_STRING hString = NULL;
        hString = my_string_init_default();
        if(hString == NULL)
 {
        strncpy(buffer, "test_oboukantar_init_default_returns_nonNULL\n"
        "my_string_init_default returns NULL", length);
 }
        else
 {	 
        status = SUCCESS;
        my_string_destroy(&hString);
        strncpy(buffer, "\ttest_oboukantar_init_default_returns_nonNULL\n", length);
 }
        return status;
}
Status test_oboukantar_get_size_on_init_default_returns_0(char* buffer, int length)
{
        Status status=FAILURE;
        MY_STRING hString = NULL;
        hString = my_string_init_default();
        if(my_string_get_size(hString) != 0)
 {
        printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
        strncpy(buffer, "test_oboukantar_get_size_on_init_default_returns_0\n"
        "Did not receive 0 from get_size after init_default\n", length);
 }
        else
 {
        status = SUCCESS;
        strncpy(buffer, "test_oboukantar_get_size_on_init_default_returns_0\n", length);
 }
        my_string_destroy(&hString);
        return status;
}
