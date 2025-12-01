#ifndef H_BINARY_TREE
#define H_BINARY_TREE

struct binary_node
{
	binary_node(int _value) : value(_value), left(nullptr), right(nullptr) {}
	int value;
	binary_node* left;
	binary_node* right;
};

binary_node* generate_binary_search_tree(int size);

int leaf_count(binary_node* root);
int single_parent_count(binary_node* root);

#endif
