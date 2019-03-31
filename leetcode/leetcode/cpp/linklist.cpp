#include "STLHeader.h"

template <class ValueType>
struct LinkNode
{
  SLinkNode *last;
  SLinkNode *next;
  ValueType value;
};

template <class ValueType>
struct SLinkNode
{
  SLinkNode *next;
  ValueType value;
};

int listLength(SLinkNode<int> *head)
{
  int l = 0;
  auto rover = head;
  while (rover != nullptr)
  {
    ++l;
    rover = rover->next;
  }
  return l;
}

void reverseList(SLinkNode<int> *head)
{
  if (head->next == nullptr)
  {
    return;
  }

  SLinkNode<int> *last = nullptr;
  auto rover = head;
  while (rover != nullptr)
  {
    auto temp = rover->next;
    rover->next = last;
    last = rover;
    rover = temp;
  }
}


