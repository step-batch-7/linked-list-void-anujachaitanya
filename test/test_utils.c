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
