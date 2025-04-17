//
// Created by calvi on 2025-03-12.
//

#include <fstream>
#include <algorithm>
#include <vector>
#include "spell_checker.h"
#include "binary_search_tree.h"

void SpellChecker::spelling_checker(const std::string& test_file, const std::string& dictionary_file, const std::string& file_to_save) {

    BinarySearchTree bst;

    //create an array containing the dictionary words
    get_dictionary(dictionary_file, bst);

    if (_dictionary_array == nullptr) {
        std::cerr << "Error handling file" << std::endl;
        return;
    }

    //Build a balanced binary search tree
    bst.balance_tree(_dictionary_array, _file_length, bst._root);

    //create a vector containing all the misspelled words
    std::vector<std::string> misspelled_words = create_spelling_errors_list(test_file, bst);

    //print the misspelled words to the console
    print_misspelled_words(misspelled_words);

    //save the binary search tree in a .txt file
    bst.save_tree_to_file(file_to_save);

    delete[] _dictionary_array;

}

void SpellChecker::get_dictionary(const std::string& dictionary_file, BinarySearchTree& bst) {

    std::fstream file(dictionary_file, std::ios::in | std::ios::out);

    if (!file.is_open()) {
        std::cerr << "Error: could not open or create file " << dictionary_file << std::endl;
        return;
    }

    std::string line;

    //get the length of the file and find the longest word (for tree formatting)
    while (getline(file, line)) {
        _file_length++;
        if (line.length() > bst._longest_word_length) {
            bst._longest_word_length = line.length();
        }
    }

    // Reset the file stream to the beginning
    file.clear();
    file.seekg(0, std::ios::beg);

    _dictionary_array = new std::string[_file_length];
    _file_length = 0;

    //add all dictionary words into the array
    while (getline(file, line)) {
        _dictionary_array[_file_length] = line;
        _file_length++;
    }

    std::sort(_dictionary_array, _dictionary_array + _file_length);
}

std::vector<std::string> SpellChecker::create_spelling_errors_list(const std::string& test_file, BinarySearchTree& bst) {

    std::ifstream file(test_file);
    std::string word;
    std::vector<std::string> misspelled_words;

    if (!file.is_open()) {
        std::cerr << "Error: could not open or create file " << test_file << std::endl;
        return misspelled_words;
    }

    //append all misspelled words to the vector
    while (file >> word) {
        std:: string raw_word = filter_word(word);
        std::string misspelled_word = find_spelling_errors(raw_word, bst);

        if (!misspelled_word.empty()) {
            misspelled_words.push_back(misspelled_word);
        }
    }

    return misspelled_words;
}

std::string SpellChecker::find_spelling_errors(const std::string& raw_word, BinarySearchTree& bst) {

    //search the tree to identify misspelled words
    if (!raw_word.empty() && !bst.search(raw_word)) {
        return raw_word;
    }

    return {};
}

std::string SpellChecker::filter_word(std::string word) {

    //remove non-alpha characters from the word
    word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
        return !std::isalpha(static_cast<unsigned char>(c));
    }), word.end());

    //convert all characters in the word to lowercase
    std::transform(word.begin(), word.end(), word.begin(), [](char c) {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    });

    return word;
}

void SpellChecker::print_misspelled_words(std::vector<std::string> misspelled_words) {
    size_t vector_length = misspelled_words.size();

    std::cout << "\nMisspelled Words" << std::endl;
    std::cout << "-----------------" << std::endl;

    for (size_t x = 0; x < vector_length; ++x) {
        std::cout << misspelled_words[x] << std::endl;
    }

    std::cout << "-----------------" << std::endl;

}