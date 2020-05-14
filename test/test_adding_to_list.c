#include <stdio.h>
#include "test_utils.h"

Status int_equal(Element no1, Element no2)
{
  return *(int *)no1 == *(int *)no2;
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

int main(void)
{
  test_for_add_to_list_empty_list();
  test_for_add_to_list_in_long_list();
  test_add_to_start_for_empty_list();
  return 0;
}