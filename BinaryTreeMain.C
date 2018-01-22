#include <iostream>
#include "Tree.H"


void setTreeValues(TreeNode<int> *tree)
{
  for(int i = 0; i < Tree<int>::MAX_SIZE; ++i)
  {
    tree[i].value = 0;
  }
   
  tree[3].value = 1;
  tree[4].value = 2;
  tree[5].value = 3;
  tree[6].value = 4;	
}

void printList(Node<int> *list)
{
  Node<int> *iterator = list;
  while(iterator->next)
  {
	std::cout<<iterator->value;
	iterator = iterator->next;
  }
}

int main()
{
  Tree<int> binary_tree;
  setTreeValues(binary_tree.tree_begin);
  binary_tree.buildListFromTree();
  printList(binary_tree.list_begin);
}
