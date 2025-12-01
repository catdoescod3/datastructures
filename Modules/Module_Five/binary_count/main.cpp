#include "binary_tree.hpp"
#include <print>

void print_inorder(binary_node* root)
{
    if (!root) return;
    print_inorder(root->left);
    std::print("{} ", root->value);
    print_inorder(root->right);
}

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        std::println("===== TREE {} =====", i);

        binary_node* root = generate_binary_search_tree(10);

        std::print("In-order: ");
        print_inorder(root);
        std::println();

        int leaves = leaf_count(root);
        int singles = single_parent_count(root);

        std::println("Leaf count:           {}", leaves);
        std::println("Single-parent count:  {}", singles);
        std::println();
    }

    return 0;
}

