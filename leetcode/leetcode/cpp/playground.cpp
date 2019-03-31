#include "STLHeader.h"

int bsearch_func(vector<int> *array, int value, function<int(int, int)> compare_func)
{
  int left = 0;
  int right = array->size();
  int index = 0;

  while (left != right)
  {
    index = (left + right) / 2;

    int order = compare_func(value, array->at(index));
    if (order < 0)
    { // value < array-at(index) --> left
      right = index;
    }
    else if (order > 0)
    { // value > array->at(index) --> right
      left = index + 1;
    }
    else
    { // find value at index
      return index;
    }
  }

  //array->at(index) > value || array->at(index) < value
  return -1; // not found
}