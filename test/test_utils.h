#include "../linkedlist.h"
#ifndef __TEST_UTILS_H
#define __TEST_UTILS_H

List_ptr init_linked_list(Element data, int length, int data_size);
Status assert_void_linked_list(List_ptr actual, List_ptr expected, Matcher matcher);
Status assert_result(Element actual_result, Element expected_result, Matcher matcher);
void show_result(Status result, char *description);
#endif