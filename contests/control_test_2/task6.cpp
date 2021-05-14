//
// Created by Meevere on 5/14/2021.
//

#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::endl;

namespace control2 {

    struct Node {
        int data;
        Node *left, *right, *right_sibling;
        int level;
    };

    void insert(Node** root, int data) {
        if (*root == NULL) {
            *root = new Node;
            (*root)->data = data;
            (*root)->left = NULL;
            (*root)->right = NULL;
            (*root)->right_sibling = NULL;
            (*root)->level = 0;
            return;
        }
        if ((*root)->data > data)
            insert(&((*root)->left), data);
        if ((*root)->data < data)
            insert(&((*root)->right), data);
    }

    void mark_levels(Node* root) {
        if (!root)
            return;
        if (root->left) {
            root->left->level = root->level + 1;
            mark_levels(root->left);
        }
        if (root->right) {
            root->right->level = root->level + 1;
            mark_levels(root->right);
        }
    }

    void clear(Node* root) {
        if (!root)
            return;
        clear(root->left);
        clear(root->right);
        delete root;
    }

    void build_siblings(Node* root);

    void print_siblings(Node* root) {
        if (!root)
            return;
        cout << root->data << " ";
        print_siblings(root->right_sibling);
    }

    bool print_level(Node* root, int level) {
        if (!root)
            return false;
        if (root->level == level) {
            print_siblings(root);
            cout << endl;
            return true;
        }
        if (print_level(root->left, level))
            return true;
        if (print_level(root->right, level))
            return true;
        return false;
    }

    void build_siblings(Node* node){
        if(!node) return;

        std::deque<Node*> cur_nodes;
        std::deque<Node*> next_nodes;

        cur_nodes.push_back(node);

        while(true) {

            for (auto elem : cur_nodes) {
                if(elem->left) next_nodes.push_back(elem->left);
                if(elem->right) next_nodes.push_back(elem->right);
            }

            // if we are on the last level - there are no nodes left to check
            if(next_nodes.empty()) break;

            for( int i=1; i<next_nodes.size(); i++){
                next_nodes[i-1]->right_sibling = next_nodes[i];
            }

            cur_nodes = next_nodes;
            next_nodes.clear();
        }
    }


    int task6() {
        int n;
        cin >> n;
        Node *root = NULL;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            insert(&root, tmp);
        }
        mark_levels(root);
        build_siblings(root);
        int level;
        cin >> level;
        print_level(root, level);;
        clear(root);
        return 0;
    }
}