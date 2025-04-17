//
// Created by calvi on 2025-03-12.
//

#ifndef SPELL_CHECKER_SPELL_CHECKER_H
#define SPELL_CHECKER_SPELL_CHECKER_H


#include <string>
#include "binary_search_tree.h"

class SpellChecker {
public:

    int _file_length {0};
    std::string* _dictionary_array {nullptr};

    void spelling_checker(const std::string&, const std::string&, const std::string&);
    void get_dictionary(const std::string&, BinarySearchTree&);
    static std::vector<std::string> create_spelling_errors_list(const std::string&, BinarySearchTree&);
    static std::string find_spelling_errors(const std::string&, BinarySearchTree&);
    static std::string filter_word(std::string);
    static void print_misspelled_words(std::vector<std::string>);

};


#endif //SPELL_CHECKER_SPELL_CHECKER_H