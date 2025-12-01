#include "binary_tree.hpp"
#include <random>
#include <cassert>

static void insert_binary_search_tree(binary_node*& root, int value)
{
	if (root == nullptr) 
	{
        root = new binary_node(value);
        return;
    }

	if (value < root->value)
	{
		insert_binary_search_tree(root->left, value);
	} 
	else 
	{
		insert_binary_search_tree(root->right, value);
	}
}

binary_node* generate_binary_search_tree(int size)
{
	binary_node* root = nullptr;
	for (int i = 0; i < size; i++)
	{
		int inserted_value = rand() % 100;
		insert_binary_search_tree(root , inserted_value);
	}

	return root;
} 

static int leaf_count_helper(binary_node* root, int count)
{
	if (!root) return 0;

	if (!root->left && !root->right)
	{
		return count + 1;
	}

	return leaf_count_helper(root->left, count) 
		+ leaf_count_helper(root->right, count);
}

int leaf_count(binary_node* root)
{
	return leaf_count_helper(root, 0);
}

int single_parent_count(binary_node* root)
{
	if (!root) return 0;

    bool is_single = !root->left ^ !root->right;

    return (is_single ? 1 : 0)
		+ single_parent_count(root->left)
		+ single_parent_count(root->right);
}
