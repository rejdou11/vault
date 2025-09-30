#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define VAULTFILE "vault.txt"

int check_for_file();

int initialize_file(std::string password);

int generate_file();

int edit_file(Edit_Style edit_style, std::string key_word, std::string mail, std::string name, std::string password);
