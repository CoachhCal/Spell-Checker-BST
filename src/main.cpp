#include "spell_checker.h"

int main(int argc, char **argv) {

    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const std::string test_file = argv[1];
    const std::string dictionary_file = argv[2];
    const std::string file_to_save = argv[3];

    SpellChecker spell_checker;
    spell_checker.spelling_checker(test_file, dictionary_file, file_to_save);

    return 0;

}