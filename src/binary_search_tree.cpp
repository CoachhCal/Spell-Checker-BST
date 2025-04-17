//
// Created by calvi on 2025-03-11.
//

#include "binary_search_tree.h"
#include <iomanip>
#include <algorithm>
#include <fstream>

BinarySearchTree::~BinarySearchTree() {
    clear(_root);
}

void BinarySearchTree::insert(const std::string& data) {
    insert(data, _root);
}

void BinarySearchTree::insert(const std::string& data, NodePtr& node) {
    if (node == nullptr) {

        node = new Node({data});
    } else if (data < node->_data) {

        //need to look left because data is less than nodes value
        insert(data, node->_left);
    } else if (data > node->_data) {

        insert(data, node->_right);
    } else {
        std::cout << "Node value" << data << " already exists\n";
    }
}

void BinarySearchTree::print_tree(std::ostream& output, NodePtr& node, int indent) {
    if (node != nullptr) {

        print_tree(output, node->_right, indent + _longest_word_length);
        output << std::setw(indent) << "" << std::left << node->_data << std::endl;
        print_tree(output, node->_left, indent + _longest_word_length);
    }
}

void BinarySearchTree::clear(Node* node) {
    if (node) {
        clear(node->_left);
        clear(node->_right);
        delete node;
    }
}

bool BinarySearchTree::search(const std::string& data) const {

    auto node = _root;

    //search for node
    while (node != nullptr) {
        if (data < node->_data) {
            //take left path
            node = node->_left;

        } else if (data > node->_data) {
            //take right path
            node = node->_right;

        } else {
            //node has been found
            return true;
        }
    }
    return false;
}

void BinarySearchTree::balance_tree(std::string* word_array, int array_length, NodePtr& node) {

    if (array_length <= 0) {
        node = nullptr;
        return;
    }

    // Find the middle element and insert into tree
    int mid = array_length / 2;
    this->insert(word_array[mid]);

    // Recursively balance the left and right subtrees
    balance_tree(word_array, mid, node->_left);
    balance_tree(word_array + mid + 1, array_length - mid - 1, node->_right);
}

void BinarySearchTree::save_tree_to_file(std::string file_name) {

    std::ofstream out_file(file_name);

    if (!out_file.is_open()) {
        std::cerr << "Error: Unable to open file " << file_name << std::endl;
        return;
    }

    print_tree(out_file, _root, 0);

}