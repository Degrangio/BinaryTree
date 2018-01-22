#include "Node.H"
#include "TreeNode.H"

template<typename Data>
struct Tree
{
    Tree():
	tree_structure(),
	linked_list()
    {
	buildTree();
	buildList();
    }

    void buildTree()
    {
	for(int i = 0;i < MAX_SIZE; ++i)
	{
	    int parent = (i - 1) / 2;
	    int left = (2 * i) + 1;
	    int right = (2 * i) + 2;
	    
	    if(parent > 0)
	    {
	    	tree_structure[i].parent = &(tree_structure[parent]);
	    }

	    if(left <= MAX_SIZE)
	    {
		tree_structure[i].left_child = &(tree_structure[left]);
	    }
	    
	    if(right <= MAX_SIZE)
	    {
		tree_structure[i].right_child = &(tree_structure[right]);
	    }
	}
	tree_begin = &tree_structure[0];
   }

    void buildList()
    {
	for(int i = 0;i < MAX_SIZE; ++i)
	{
	   if(i < MAX_SIZE - 1)
	   {
	   	linked_list[i].next = &(linked_list[i+1]);
	   }
	   if(i != 0)
	   {
		linked_list[i].prev = &(linked_list[i-1]);
	   }
	}
	list_begin = &linked_list[0];
    }

    void buildListFromTree()
    {
	traverse(*tree_begin, *list_begin);	
    }

    void traverse(TreeNode<Data> &current_node, Node<Data>  &list_position)
    {
	current_node.is_visited = true;
	list_position.value = current_node.value;
	list_position.next->prev = &list_position;
	
	if(current_node.left_child && !(current_node.left_child->is_visited))
	{
	    traverse(*(current_node.left_child), *(list_position.next));
	}
	else if(current_node.right_child && !(current_node.right_child->is_visited))
	{
	    traverse(*(current_node.right_child), *(list_position.next));
	}
    }

    static const int MAX_SIZE = 7;
   
    TreeNode<Data> *tree_structure;
    TreeNode<Data> *tree_begin;
    Node<Data> *linked_list;
    Node<Data> *list_begin;
};

