#include <stdlib.h>
void mQsort(void *base, size_t nel, size_t width, int (*compar)(void *, void *))
{
  size_t list1_length;
  size_t list2_length;
  void *pivot = alloca(width);
  void *temp = alloca(width);

  if (nel < 2)
  {
    return;
  }

  memset(pivot, base + (nel - 1) * width, width);

  list1_length = 0;

  for (size_t i = 0; i < nel - 1; i++)
  {
    if (compar(base + i * width, pivot) < 0)
    {
      //find item < pivot, move left
      memset(temp, base + list1_length * width, width);
      memset(base + list1_length * width, base + i * width, width);
      memset(base + i * width, temp, width);

      ++list1_length;
    }
    else
    {
      //item > pivot already in the right position
    }
  }

  list2_length = nel - list1_length - 1;
  memset(base + (nel - 1) * width, base + (list1_length - 1) * width, width);
  memset(base + (list1_length - 1) * width, pivot, width);

  mQsort(base, list1_length, width, compar);
  mQsort(base + list1_length * width, list2_length, width, compar);
}

typedef struct TNode
{
  struct TNode *left;
  struct TNode *right;
} * TNodeRef;

void preOrderTranverse(TNodeRef node, void (*visit)(TNodeRef node))
{
  if (node == NULL)
  {
    return;
  }

  visit(node);
  preOrderTranverse(node->left, visit);
  preOrderTranverse(node->right, visit);
}

void inOrderTranverse(TNodeRef node, void (*visit)(TNodeRef node))
{
  if (node == NULL)
  {
    return;
  }

  inOrderTranverse(node->left, visit);
  visit(node);
  inOrderTranverse(node->right, visit);
}

void postOrderTranverse(TNodeRef node, void (*visit)(TNodeRef node))
{
  if (node == NULL) {
    return ;
  }
  
  postOrderTranverse(node->left, visit);
  postOrderTranverse(node->right, visit);
  visit(node);
}
