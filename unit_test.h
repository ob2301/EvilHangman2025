#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_oboukantar_init_default_returns_nonNULL(char* buffer, int length);
Status test_oboukantar_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_oboukantar_get_size_of_five_on_init_hello(char* buffer, int length);
Status test_oboukantar_get_capacity_of_six_on_init_hello(char* buffer, int length);
Status test_oboukantar_get_zero_on_same_my_string_compare(char* buffer, int length);
Status test_oboukantar_get_neg_value_on_my_string_compare(char* buffer, int length);
Status test_oboukantar_get_pos_value_on_my_string_compare(char* buffer, int length);
Status test_oboukantar_my_string_push_back_creates_correct_new_string(char* buffer, int length);
Status test_oboukantar_my_string_pop_back_deletes_last_character_in_string(char* buffer, int length);
Status test_oboukantar_my_string_concat_returns_correct_string(char* buffer, int length);
Status test_oboukantar_my_string_empty_returns_true_on_empty_string(char* buffer, int length);
Status test_oboukantar_my_string_empty_returns_false_on_NON_empty_string(char* buffer, int length);
Status test_oboukantar_my_string_init_c_string_creates_correct_string(char* buffer, int length);
Status test_oboukantar_my_string_at_returns_correct_character_at_valid_index(char* buffer, int length);
Status test_oboukantar_my_string_at_returns_NULL_if_index_out_of_bounds(char* buffer, int length);
Status test_oboukantar_my_string_pop_back_decreases_right_amount_of_size(char* buffer, int length);
Status test_oboukantar_my_string_push_back_increases_right_amount_of_size(char* buffer, int length);
Status test_oboukantar_my_string_push_back_increases_right_amount_of_capacity(char* buffer, int length);
Status test_oboukantar_my_string_insertion_returns_success_on_success(char* buffer, int length);
Status test_oboukantar_my_string_concat_increases_right_amount_of_size(char* buffer, int length);
Status test_oboukantar_my_string_concat_increases_right_amount_of_capacity(char* buffer, int length);
Status test_oboukantar_my_string_extraction_returns_success_on_success(char* buffer, int length);
Status test_oboukantar_my_string_destroy_sets_pointer_to_NULL(char* buffer, int length);
Status test_oboukantar_my_string_c_str_returns_correct_NULL_terminated_string(char* buffer, int length);
Status test_oboukantar_get_capacity_on_init_default_returns_7(char* buffer, int length);

#endif
