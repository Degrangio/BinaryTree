#include <iostream>
#include "Tree.H"


void setTreeValues(TreeNode<int> *tree)
{
  for(int i = 0; i < Tree<int>::MAX_SIZE; ++i)
  {
    tree[i].value = 0;
  }
  
  tree[15].value = 5;
  tree[16].value = 15;
  tree[17].value = 9;
  tree[18].value = 81;
  tree[19].value = 23;
  tree[20].value = 37;
  tree[21].value = 45;
  tree[22].value = 8;
  tree[23].value = 11;
  tree[24].value = 16;
  tree[25].value = 72;
  tree[26].value = 63;
  tree[27].value = 7;
  tree[28].value = 71;
  tree[29].value = 99;
  tree[30].value = 2;
}

void printList(Node<int> *list)
{
  Node<int> *iterator = list;
  
  //Print Forwards
  while(iterator->next)
  {
	std::cout<<iterator->value<<std::endl;
	iterator = iterator->next;
  }
  std::cout<<iterator->value<<std::endl;
  std::cout<<std::endl;
  
  //Print Backwards
  while(iterator->prev)
  {
  	std::cout<<iterator->value<<std::endl;
  	iterator = iterator->prev;
  }
  std::cout<<iterator->value<<std::endl;
}

static Tree<int> binary_tree;

int main()
{
  setTreeValues(binary_tree.tree_begin);
  binary_tree.buildListFromTree();
  printList(binary_tree.list_begin);
}
