# Spell Checker

## Overview
This C++ console application serves as a **spell checker**, identifying misspelled words in a document by comparing them against a **balanced binary search tree** populated with words from a provided dictionary file.

## Features
- **Binary Search Tree (BST):** Stores dictionary words efficiently for quick lookup.
- **Automated Tree Balancing:** Implements **balanced BST construction** to optimize search performance.
- **Spell Checking:** Reads a document and flags words **not found** in the dictionary.
- **Console Output:** Displays a list of misspelled words.
- **File Output:** Saves the balanced BST structure for later examination.

## Implementation Details
1. **Dictionary Parsing:** Reads a provided dictionary file and inserts words into a BST.
2. **Balancing the BST:** Uses a **balanced construction method** to ensure optimal lookup efficiency.
3. **Spell Checking Process:** Reads a document, searches each word in the BST, and flags any word **not found**.
4. **Results Handling:** Outputs misspelled words to the console and saves the final BST structure to a file.

## Usage
To execute the program from the command line, navigate into the cmake-build-debug folder and run:

```sh
Spell_Checker.exe ../tests/test.txt ../tests/dictionary.txt ../output/tree_file.txt
