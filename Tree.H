#include "Node.H"
#include "TreeNode.H"

template<typename Data>
struct Tree
{
    static const int MAX_SIZE = 31;

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
	
		    if(left < MAX_SIZE)
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
    	for(int i = 0;i < MAX_SIZE;++i)
    	{
    		if(i < MAX_SIZE - 1)
    		{
    			linked_list[i].next = &linked_list[i + 1];
  			}
  			if(i > 0)
  			{
  				linked_list[i].prev = &linked_list[i - 1];
  			}
		}
  		list_begin = &linked_list[0];
    }

    void buildListFromTree()
    {
    	list_position = list_begin;
		traverse(*tree_begin);	
    }

    void traverse(TreeNode<Data> &current_node)
    {
		current_node.is_visited = true;
		list_position->value = current_node.value;
		list_position = list_position->next;
		if(current_node.left_child) 
		{
			if(!(current_node.left_child->is_visited))
			{
		    	traverse(*(current_node.left_child));
			}
		}
		if(current_node.right_child)
		{
			if(!(current_node.right_child->is_visited))
			{
		    	traverse(*(current_node.right_child));
		    }
		}
    }
   
    Node<Data>  *list_position;
    TreeNode<Data> tree_structure[MAX_SIZE];
    TreeNode<Data> *tree_begin;
    Node<Data> linked_list[MAX_SIZE];
    Node<Data> *list_begin;
};