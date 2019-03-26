#include <STLHeader.h>

struct TNode
{
  TNode *left;
  TNode *right;
};

void preOrderTranverse(TNode *node, void (*visit)(TNode *node))
{
  if (node == NULL)
  {
    return;
  }
  // preOrder --> root | root->left | root->right
  stack<TNode *> stack;
  TNode *rover;
  stack.push(node);

  while (!stack.empty())
  {
    rover = stack.top();
    stack.pop();
    visit(rover);
    if (rover->left)
    {
      stack.push(rover->left);
    }
    if (rover->right)
    {
      stack.push(rover->right);
    }
  }
}

void inOrderTranverse(TNode *node, void (*visit)(TNode *node))
{
  if (node == NULL)
  {
    return;
  }

  stack<TNode *> stack;
  TNode *rover = node;

  while (rover && stack.empty())
  { //rover != NULL || !stack.empty()
    if (rover->left)
    {
      stack.push(rover->left);
      rover = rover->left;
    }
    else
    {
      TNode *top = stack.top();
      stack.pop();
      visit(top);
      rover = rover->right;
    }
  }
}

void postOrderTranverse(TNode *node, void (*visit)(TNode *node))
{
  if (node == NULL)
  {
    return;
  }
  stack<TNode *> fStack;
  stack<TNode *> tStack;
  TNode *rover;
  tStack.push(node);
  while (!tStack.empty())
  {
    rover = tStack.top();
    tStack.pop();

    if (rover->left != nullptr)
    {
      tStack.push(rover->left);
    }

    if (rover->right != nullptr)
    {
      tStack.push(rover->right);
    }
    fStack.push(rover);
  }

  while (!fStack.empty())
  {
    rover = fStack.top;
    visit(rover);
    fStack.pop();
  }
}

int nodeHeight(TNode *node)
{
  if (node == nullptr)
  {
    return 0;
  }
  return 1 + max(nodeHeight(node->left), nodeHeight(node->right));
}
