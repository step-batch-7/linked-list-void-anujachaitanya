#include "linkedlist.h"
Node_ptr create_node(Element data)
{
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->element = data;
  new_node->next = NULL;
  return new_node;
}

List_ptr create_list(void)
{
  List_ptr new_list = malloc(sizeof(LinkedList));
  new_list->length = 0;
  new_list->first = NULL;
  new_list->last = NULL;
  return new_list;
}

Status add_to_list(List_ptr list, Element data)
{
  Node_ptr new_node = create_node(data);
  if (list->first == NULL)
  {
    list->first = new_node;
  }
  else
  {
    list->last->next = new_node;
  }
  list->last = new_node;
  list->length++;
  return Success;
}

Status add_to_start(List_ptr list, Element data)
{
  Node_ptr new_node = create_node(data);
  if (list->first == NULL)
  {
    list->first = new_node;
    list->last = new_node;
  }
  else
  {
    Node_ptr temp = list->first;
    list->first = new_node;
    new_node->next = temp;
  }
  list->length++;
  return Success;
}

Status insert_at(List_ptr list, Element data, int position)
{
  if (position > list->length || position < 0)
  {
    return Failure;
  }

  if (position == 0)
  {
    return add_to_start(list, data);
  }

  if (position == list->length)
  {
    return add_to_list(list, data);
  }

  Node_ptr p_walk = list->first;
  Node_ptr previous_node = list->first;
  int counter = 0;
  while (counter != position)
  {
    previous_node = p_walk;
    p_walk = p_walk->next;
    counter++;
  }
  Node_ptr new_node = create_node(data);
  previous_node->next = new_node;
  new_node->next = p_walk;
  list->length++;
  return Success;
}

List_ptr reverse(List_ptr list)
{
  List_ptr reverse_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    add_to_start(reverse_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return reverse_list;
}

List_ptr map(List_ptr list, Mapper mapper)
{
  List_ptr new_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    Element map_result = (*mapper)(p_walk->element);
    add_to_list(new_list, map_result);
    p_walk = p_walk->next;
  }
  return new_list;
}

List_ptr filter(List_ptr list, Predicate predicate)
{
  List_ptr new_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    Status filter_result = (*predicate)(p_walk->element);
    if (filter_result)
    {
      add_to_list(new_list, p_walk->element);
    }
    p_walk = p_walk->next;
  }
  return new_list;
}

Element reduce(List_ptr list, Element init, Reducer reducer)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    init = reducer(init, p_walk->element);
    p_walk = p_walk->next;
  }
  return init;
}

void forEach(List_ptr list, ElementProcessor processor)
{
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    (*processor)(p_walk->element);
    p_walk = p_walk->next;
  }
}

Element remove_from_start(List_ptr list)
{
  if (list->first == NULL)
  {
    return NULL;
  }

  if (list->length == 1)
  {
    Element element_to_be_free = list->first->element;
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    return element_to_be_free;
  }

  Node_ptr temp = list->first;
  list->first = list->first->next;
  list->length--;
  return temp->element;
}

Element remove_from_end(List_ptr list)
{
  if (list->first == NULL)
  {
    return NULL;
  }

  if (list->length == 1)
  {
    Element element_to_be_free = list->first->element;
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    return element_to_be_free;
  }

  int count = 1;
  Node_ptr p_walk = list->first;
  while (count < list->length - 1)
  {
    p_walk = p_walk->next;
    count++;
  }
  Node_ptr last_node = list->last;
  list->last = p_walk;
  p_walk->next = NULL;
  list->length--;
  return last_node->element;
}

Element remove_at(List_ptr list, int position)
{
  if (list->first == NULL || position >= list->length || position < 0)
  {
    return NULL;
  }

  if (position == 0)
  {
    return remove_from_start(list);
  }

  if (position == list->length - 1)
  {
    return remove_from_end(list);
  }

  int count = 0;
  Node_ptr p_walk = list->first;
  Node_ptr previous_node = list->first;
  while (count < position)
  {
    previous_node = p_walk;
    p_walk = p_walk->next;
    count++;
  }
  previous_node->next = p_walk->next;
  list->length--;
  return p_walk->element;
}

Status add_unique(List_ptr list, Element element, Matcher matcher)
{
  Status matched = Failure;
  Node_ptr p_walk = list->first;
  while (p_walk != NULL && (!matched))
  {
    matched = matcher(element, p_walk->element);
    p_walk = p_walk->next;
  }
  if (!matched)
  {
    return add_to_list(list, element);
  }
  return Failure;
}

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher)
{
  int counter = 0;
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    Status matched = matcher(element, p_walk->element);
    if (matched)
    {
      return remove_at(list, counter);
    }
    counter++;
    p_walk = p_walk->next;
  }
  return NULL;
}

List_ptr remove_all_occurrences(List_ptr list, Element element, Matcher matcher)
{
  int counter = 0;
  List_ptr removed_list = create_list();
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    Status matched = matcher(element, p_walk->element);
    p_walk = p_walk->next;
    if (matched)
    {
      Element removed_element = remove_at(list, counter);
      add_to_list(removed_list, removed_element);
    }
    counter++;
  }
  return removed_list;
};

Status clear_list(List_ptr list)
{
  while (list->first != NULL)
  {
    remove_from_start(list);
  }
  return Success;
};