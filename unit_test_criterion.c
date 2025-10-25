#include <criterion/criterion.h>
#include "my_string.h"

Test(my_string_unit, init_default_returns_non_null) {
    MY_STRING hString = my_string_init_default();
    cr_assert_not_null(hString);
    my_string_destroy(&hString);
}

Test(my_string_unit, get_capacity_on_init_default_returns_7) {
    MY_STRING hString = my_string_init_default();
    cr_assert_eq(my_string_get_capacity(hString), 7);
    my_string_destroy(&hString);
}

Test(my_string_unit, get_size_on_init_default_returns_0) {
    MY_STRING hString = my_string_init_default();
    cr_assert_eq(my_string_get_size(hString), 0);
    my_string_destroy(&hString);
}

Test(my_string_unit, my_string_destroy_sets_pointer_to_NULL) {
    MY_STRING hString = my_string_init_default();
    my_string_destroy(&hString);
    cr_assert_null(hString);
}

Test(my_string_unit, my_string_init_c_string_creates_correct_string) {
    MY_STRING hString = my_string_init_c_string("Hello World");
    cr_assert_str_eq(my_string_c_str(hString), "Hello World");
    my_string_destroy(&hString);
}

Test(my_string_unit, my_string_empty_returns_true_on_empty_string) {
    MY_STRING hString = my_string_init_default();
    cr_assert_eq(my_string_empty(hString), TRUE);
    my_string_destroy(&hString);
}

Test(my_string_unit, my_string_empty_returns_false_on_non_empty_string) {
    MY_STRING hString = my_string_init_c_string("hello");
    cr_assert_eq(my_string_empty(hString), FALSE);
    my_string_destroy(&hString);
}

Test(my_string_unit, my_string_get_size_after_push_back) {
    MY_STRING hString = my_string_init_c_string("Hello");
    my_string_push_back(hString, '!');
    cr_assert_eq(my_string_get_size(hString), 6);
    my_string_destroy(&hString);
}

Test(my_string_unit, my_string_pop_back_decreases_size) {
    MY_STRING hString = my_string_init_c_string("Hello");
    my_string_pop_back(hString);
    cr_assert_eq(my_string_get_size(hString), 4);
    my_string_destroy(&hString);
}

Test(my_string_unit, my_string_at_returns_correct_character) {
    MY_STRING hString = my_string_init_c_string("Hello");
    char *ch = my_string_at(hString, 1);
    cr_assert_eq(*ch, 'e');
    my_string_destroy(&hString);
}

Test(my_string_unit, my_string_at_returns_null_if_out_of_bounds) {
    MY_STRING hString = my_string_init_c_string("Hi");
    char *ch = my_string_at(hString, 10);
    cr_assert_null(ch);
    my_string_destroy(&hString);
}

Test(my_string_unit, my_string_compare_returns_zero_for_same_strings) {
    MY_STRING a = my_string_init_c_string("apple");
    MY_STRING b = my_string_init_c_string("apple");
    cr_assert_eq(my_string_compare(a, b), 0);
    my_string_destroy(&a);
    my_string_destroy(&b);
}

Test(my_string_unit, my_string_compare_returns_positive_for_left_greater) {
    MY_STRING a = my_string_init_c_string("banana");
    MY_STRING b = my_string_init_c_string("apple");
    cr_assert_gt(my_string_compare(a, b), 0);
    my_string_destroy(&a);
    my_string_destroy(&b);
}

Test(my_string_unit, my_string_compare_returns_negative_for_left_smaller) {
    MY_STRING a = my_string_init_c_string("app");
    MY_STRING b = my_string_init_c_string("apple");
    cr_assert_lt(my_string_compare(a, b), 0);
    my_string_destroy(&a);
    my_string_destroy(&b);
}

Test(my_string_unit, my_string_c_str_returns_null_terminated_string) {
    MY_STRING s = my_string_init_c_string("Hello World");
    char *result = my_string_c_str(s);
    cr_assert_str_eq(result, "Hello World");
    my_string_destroy(&s);
}

Test(my_string_integration, concat_produces_correct_string) {
    MY_STRING hResult = my_string_init_c_string("Hello ");
    MY_STRING hAppend = my_string_init_c_string("World");
    my_string_concat(hResult, hAppend);
    cr_assert_str_eq(my_string_c_str(hResult), "Hello World");
    my_string_destroy(&hResult);
    my_string_destroy(&hAppend);
}

Test(my_string_integration, concat_updates_size_and_capacity) {
    MY_STRING hResult = my_string_init_c_string("Hello ");
    MY_STRING hAppend = my_string_init_c_string("World");
    my_string_concat(hResult, hAppend);
    cr_assert_eq(my_string_get_size(hResult), 11);
    cr_assert_eq(my_string_get_capacity(hResult), 12);
    my_string_destroy(&hResult);
    my_string_destroy(&hAppend);
}

Test(my_string_integration, extraction_reads_word_from_file) {
    FILE *fp = fopen("dictionary.txt", "r");
    cr_assert_not_null(fp);
    MY_STRING hString = my_string_init_default();
    Status status = my_string_extraction(hString, fp);
    cr_assert_eq(status, SUCCESS);
    cr_assert_gt(my_string_get_size(hString), 0);
    my_string_destroy(&hString);
    fclose(fp);
}

Test(my_string_integration, pop_and_push_create_correct_string_sequence) {
    MY_STRING hString = my_string_init_default();
    my_string_push_back(hString, 'd');
    my_string_push_back(hString, 'o');
    my_string_push_back(hString, 'g');
    my_string_pop_back(hString);
    cr_assert_str_eq(my_string_c_str(hString), "do");
    my_string_destroy(&hString);
}

Test(my_string_integration, assignment_and_swap_work_correctly) {
    MY_STRING a = my_string_init_c_string("cat");
    MY_STRING b = my_string_init_c_string("dog");
    my_string_assignment(a, b);
    cr_assert_str_eq(my_string_c_str(a), "dog");
    my_string_swap(a, b);
    cr_assert_str_eq(my_string_c_str(a), "dog");
    my_string_destroy(&a);
    my_string_destroy(&b);
}
