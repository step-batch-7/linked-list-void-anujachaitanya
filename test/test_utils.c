#include "test_utils.h"

List_ptr init_linked_list(Element data, int length, int data_size)
{
  List_ptr new_list = create_list();
  while (new_list->length < length)
  {
    Element data_to_add = data + (new_list->length * data_size);
    add_to_list(new_list, data_to_add);
  }
  return new_list;
}

void show_result(Status result, char *description)
{
  if (result)
  {
    printf("✅");
  }
  else
  {
    printf("❌");
  }
  printf("%s\n", description);
}

Status assert_void_linked_list(List_ptr actual, List_ptr expected, Matcher matcher)
{
  if (actual->length != expected->length)
  {
    return Failure;
  }
  Status result = Success;
  Node_ptr actual_p_walk = actual->first;
  Node_ptr expected_p_walk = expected->first;
  while (actual_p_walk != NULL)
  {
    result = matcher(actual_p_walk->element, expected_p_walk->element);
    actual_p_walk = actual_p_walk->next;
    expected_p_walk = expected_p_walk->next;
    if (!result)
    {
      break;
    }
  }
  return result;
}

Status assert_result(Element actual_result, Element expected_result, Matcher matcher)
{
  return matcher(actual_result, expected_result);
};