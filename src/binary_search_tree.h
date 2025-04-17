//
// Created by calvi on 2025-03-11.
//

#ifndef SPELL_CHECKER_BINARY_SEARCH_TREE_H
#define SPELL_CHECKER_BINARY_SEARCH_TREE_H


#include <iostream>
#include <vector>

class BinarySearchTree {

    struct Node;
    using NodePtr = Node*;

    struct Node {
        std::string _data;
        Node* _left {nullptr};
        Node* _right {nullptr};
    };

public:
    Node* _root {nullptr};
    int _longest_word_length {0};

    ~BinarySearchTree();
    void insert(const std::string&);
    void insert(const std::string&, NodePtr&);
    bool search(const std::string&) const;
    void balance_tree(std::string*, int, NodePtr&);
    void print_tree(std::ostream& output, NodePtr& node, int indent);
    void save_tree_to_file(std::string);

private:
    void clear(Node* node);

};


#endif //SPELL_CHECKER_BINARY_SEARCH_TREE_H