template<typename Data>
struct TreeNode
{
    TreeNode():
	is_visited(false),
	parent(0),
	left_child(0),
	right_child(0)
    {
    }

    Data value;

    TreeNode *parent;
    TreeNode *left_child;
    TreeNode *right_child;
    bool is_visited;
};
