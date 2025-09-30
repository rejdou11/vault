#include "custom_enums.hpp"
#include "file_handler.hpp"

using namespace std;

int check_for_file(){
    ifstream file(VAULTFILE);
    if(!file){
        return 1;
    }
    file.close();

    return 0;
}

int initialize_file(string password){
    ofstream file(VAULTFILE);
    if(!file){
        cerr << "Error loading file!" << endl;
        return 1;
    }

    file << password << endl;

    file.close();

    return 0;
}

int generate_file(){
    ofstream file(VAULTFILE);
    if(!file){
        cerr << "Error loading file!" << endl;
        return 1;
    }
    file.close();

    return 0;
}

void read_file(vector<string>& lines){
    ifstream file(VAULTFILE);
    string line;

    while(getline(file, line)){
        lines.push_back(line);
    }
    file.close();
}

int find_key_word_pos(vector<string>& lines, string key_word){
    for(int i = 0; i < lines.size(); i++){
        int j = 0;
        string found_word = "";
        while(lines[i][j] != ' '){
            found_word += lines[i][j];
            j++;
        }
        if(found_word == key_word){
            return i;
        }
    }
    return -1;
}

void add_line(vector<string>& lines, string key_word, string mail, string name, string password){
    lines.push_back(key_word+" "+mail+" "+name+" "+password);
}

void remove_line(vector<string>& lines, string key_word){
    int pos = find_key_word_pos(lines, key_word);
    if(pos >= 0){
        lines[pos] = "";
    }else{
        cerr << "Couldn't find service!" << endl;
    }
}

void list_lines(vector<string>& lines){
    for(int i=0; i < lines.size(); i++){
        cout << lines[i] << endl;
    }
}

void write_file(vector<string>& lines){
    ofstream file(VAULTFILE, std::ios::trunc);  // overwrite file
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }

    for (const auto& line : lines) {
        if(line != ""){
            file << line << "\n";
        }
    }
}

int edit_file(Edit_Style edit_style, string key_word, string mail, string name, string password){
    if(check_for_file() == 1){
        return 1;
    }

    vector<string> lines;
    read_file(lines);
    
    switch(edit_style){
        case ADD:
            add_line(lines, key_word, mail, name, password);
            break;
        case REMOVE:
            remove_line(lines, key_word);
            break;
        case LIST:
            list_lines(lines);
            break;
    }

    write_file(lines);
    return 0;
}
