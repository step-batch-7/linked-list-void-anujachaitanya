#include "linkedlist.h"

void displayer(Element number)
{
  printf("%d", *(int *)number);
}

int main()
{
  List_ptr list = create_list();
  int a = 1;
  int b = 2;
  Element removed = remove_from_end(list);
  add_to_list(list, &a);
  add_to_list(list, &b);
  displayer(removed);
  return 0;
}
