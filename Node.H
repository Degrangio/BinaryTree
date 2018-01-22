template<typename Data>
struct Node
{
    Node():
	prev(0),
	next(0)
    {
    }

    Data value;

    Node *prev;
    Node *next;
};
