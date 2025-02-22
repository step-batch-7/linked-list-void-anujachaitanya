#include <stdio.h>
#include "test_utils.h"

Status int_equal(Element no1, Element no2)
{
  return *(int *)no1 == *(int *)no2;
}

Status char_equal(Element char1, Element char2)
{
  return *(char *)char1 == *(char *)char2;
}

void test_for_add_to_list_empty_list(void)
{
  char description[] = "Should add element in the empty list";
  int expected_values[1] = {5};
  int a = 5;
  List_ptr expected = init_linked_list(expected_values, 1, 4);
  List_ptr actual = create_list();
  add_to_list(actual, &a);
  Status result = assert_void_linked_list(expected, actual, int_equal);
  show_result(result, description);
}

void test_for_add_to_list_in_long_list(void)
{
  char description[] = "Should add element in the long list";
  int expected_values[3] = {1, 2, 5};
  int actual_values[] = {1, 2, 5};
  List_ptr expected = init_linked_list(expected_values, 3, 4);
  List_ptr actual = create_list();
  add_to_list(actual, &actual_values[0]);
  add_to_list(actual, &actual_values[1]);
  add_to_list(actual, &actual_values[2]);
  Status result = assert_void_linked_list(expected, actual, int_equal);
  show_result(result, description);
}

void test_add_to_start_for_empty_list(void)
{
  char description[] = "Should add element in the start for empty list";
  int expected_values[1] = {5};
  int a = 5;
  List_ptr expected = init_linked_list(expected_values, 1, 4);
  List_ptr actual = create_list();
  add_to_start(actual, &a);
  Status result = assert_void_linked_list(expected, actual, int_equal);
  show_result(result, description);
}

void test_add_to_start_in_long_list(void)
{
  char description[] = "Should add element in the long list";
  int expected_values[3] = {5, 1, 2};
  int actual_values[] = {1, 2};
  int new_number = 5;
  List_ptr expected = init_linked_list(expected_values, 3, 4);
  List_ptr actual = create_list();
  add_to_list(actual, &actual_values[0]);
  add_to_list(actual, &actual_values[1]);
  add_to_start(actual, &new_number);
  Status result = assert_void_linked_list(expected, actual, int_equal);
  show_result(result, description);
}

void test_insert_at_for_empty(void)
{
  char description[] = "Should insert the element in empty list";
  int expected_values[1] = {3};
  int value = 3;
  List_ptr expected = init_linked_list(expected_values, 1, 4);
  List_ptr actual = create_list();
  insert_at(actual, &value, 0);
  Status result = assert_void_linked_list(actual, expected, int_equal);
  show_result(result, description);
}

void test_insert_at_in_middle_of_list(void)
{
  char description[] = "Should add element in the long list";
  int expected_values[3] = {1, 5, 2};
  int actual_values[] = {1, 2};
  int new_number = 5;
  List_ptr expected = init_linked_list(expected_values, 3, 4);
  List_ptr actual = create_list();
  add_to_list(actual, &actual_values[0]);
  add_to_list(actual, &actual_values[1]);
  insert_at(actual, &new_number, 1);
  Status result = assert_void_linked_list(expected, actual, int_equal);
  show_result(result, description);
}

void test_insert_at_for_invalid_position(void)
{
  char description[] = "Should add element in the long list";
  int expected_values[2] = {1, 2};
  int actual_values[] = {1, 2};
  int new_number = 5;
  List_ptr expected = init_linked_list(expected_values, 2, 4);
  List_ptr actual = create_list();
  add_to_list(actual, &actual_values[0]);
  add_to_list(actual, &actual_values[1]);
  insert_at(actual, &new_number, 7);
  Status result = assert_void_linked_list(expected, actual, int_equal);
  show_result(result, description);
}

void test_insert_at_for_last_position(void)
{
  char description[] = "Should add element in the long list";
  int expected_values[3] = {1, 2, 5};
  int actual_values[] = {1, 2};
  int new_number = 5;
  List_ptr expected = init_linked_list(expected_values, 3, 4);
  List_ptr actual = create_list();
  add_to_list(actual, &actual_values[0]);
  add_to_list(actual, &actual_values[1]);
  insert_at(actual, &new_number, 2);
  Status result = assert_void_linked_list(expected, actual, int_equal);
  show_result(result, description);
}

void test_remove_from_end_for_empty_list(void)
{
  char description[] = "Should not remove from empty list";
  char expected_values[0];
  List_ptr expected = init_linked_list(expected_values, 0, 1);
  List_ptr actual = create_list();
  remove_from_end(actual);
  Status result = assert_void_linked_list(actual, expected, char_equal);
  show_result(result, description);
}

void test_remove_from_in_long_list(void)
{
  char description[] = "Should remove element in the long list";
  int expected_values[2] = {1, 2};
  int actual_values[] = {1, 2};
  int new_number = 5;
  List_ptr expected = init_linked_list(expected_values, 2, 4);
  List_ptr actual = create_list();
  add_to_list(actual, &actual_values[0]);
  add_to_list(actual, &actual_values[1]);
  add_to_list(actual, &new_number);
  Element removed = remove_from_end(actual);
  Status result = assert_void_linked_list(expected, actual, int_equal) && assert_result(removed, &new_number, int_equal);
  show_result(result, description);
}

void test_remove_from_start_fro_empty_list(void)
{
  char description[] = "Should not remove from start in the empty list";
  char expected_values[0];
  List_ptr expected = init_linked_list(expected_values, 0, 1);
  List_ptr actual = create_list();
  remove_from_start(actual);
  Status result = assert_void_linked_list(actual, expected, char_equal);
  show_result(result, description);
}

void test_remove_from_start_in_the_long_list(void)
{
  char description[] = "Should remove element from start in the long list";
  int expected_values[2] = {1, 2};
  int actual_values[] = {1, 2};
  int new_number = 5;
  List_ptr expected = init_linked_list(expected_values, 2, 4);
  List_ptr actual = create_list();
  add_to_list(actual, &new_number);
  add_to_list(actual, &actual_values[0]);
  add_to_list(actual, &actual_values[1]);
  Element removed = remove_from_start(actual);
  Status result = assert_void_linked_list(expected, actual, int_equal) && assert_result(removed, &new_number, int_equal);
  show_result(result, description);
}

void test_remove_at_for_invalid_position(void)
{
  char description[] = "Should not remove  the element for invalid position";
  int expected_values[0] = {};
  int value = 3;
  List_ptr expected = init_linked_list(expected_values, 0, 4);
  List_ptr actual = create_list();
  insert_at(actual, &value, 8);
  Status result = assert_void_linked_list(actual, expected, int_equal);
  show_result(result, description);
}

void test_remove_at_for_empty_list(void)
{
  char description[] = "Should not remove from empty list";
  char expected_values[0];
  List_ptr expected = init_linked_list(expected_values, 0, 1);
  List_ptr actual = create_list();
  remove_at(actual, 0);
  Status result = assert_void_linked_list(actual, expected, char_equal);
  show_result(result, description);
}
int main(void)
{
  test_for_add_to_list_empty_list();
  test_for_add_to_list_in_long_list();
  test_add_to_start_for_empty_list();
  test_add_to_start_in_long_list();
  test_insert_at_for_empty();
  test_insert_at_in_middle_of_list();
  test_insert_at_for_invalid_position();
  test_insert_at_for_last_position();
  test_remove_from_end_for_empty_list();
  test_remove_from_in_long_list();
  test_remove_from_start_fro_empty_list();
  test_remove_from_start_in_the_long_list();
  test_remove_at_for_invalid_position();
  test_remove_at_for_empty_list();
  return 0;
}