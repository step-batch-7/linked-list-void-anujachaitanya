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

int main(void)
{
  test_for_add_to_list_empty_list();
  return 0;
}