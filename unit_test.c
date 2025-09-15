#include <stdio.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
 test_oboukantar_init_default_returns_nonNULL,
 test_oboukantar_get_size_on_init_default_returns_0,
 test_oboukantar_get_size_of_five_on_init_hello,
 test_oboukantar_get_capacity_of_six_on_init_hello,
 test_oboukantar_get_zero_on_same_my_string_compare,
 test_oboukantar_get_neg_value_on_my_string_compare,
 test_oboukantar_get_pos_value_on_my_string_compare,
 test_oboukantar_my_string_push_back_creates_correct_new_string,
 test_oboukantar_my_string_pop_back_deletes_last_character_in_string,
 test_oboukantar_my_string_concat_returns_correct_string,
 test_oboukantar_my_string_insertion_returns_success_on_success,
 test_oboukantar_my_string_empty_returns_true_on_empty_string,
 test_oboukantar_my_string_empty_returns_false_on_NON_empty_string,
 test_oboukantar_my_string_init_c_string_creates_correct_string,
 test_oboukantar_my_string_at_returns_correct_character_at_valid_index,
 test_oboukantar_my_string_at_returns_NULL_if_index_out_of_bounds,
 test_oboukantar_my_string_pop_back_decreases_right_amount_of_size,
 test_oboukantar_my_string_push_back_increases_right_amount_of_size,
 test_oboukantar_my_string_push_back_increases_right_amount_of_capacity,
 test_oboukantar_my_string_concat_increases_right_amount_of_size,
 test_oboukantar_my_string_concat_increases_right_amount_of_capacity,
 test_oboukantar_my_string_extraction_returns_success_on_success,
 test_oboukantar_my_string_destroy_sets_pointer_to_NULL,
 test_oboukantar_my_string_c_str_returns_correct_NULL_terminated_string,
 test_oboukantar_get_capacity_on_init_default_returns_7
 };
 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;
 for(i=0; i<number_of_functions; i++) {
   if(tests[i](buffer, 500) == FAILURE) {
     printf("FAILED: Test %d failed miserably\n", i);
     printf("\t%s\n", buffer);
     failure_count++;
   }
   else
   {
     // printf("PASS: Test %d passed\n", i);
     // printf("\t%s\n", buffer);
     success_count++;
   }
 }
 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);
 return 0;
}
