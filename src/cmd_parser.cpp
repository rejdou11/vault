#include "cmd_parser.hpp"
#include "custom_enums.hpp"
#include "file_handler.hpp"

using namespace std;

void simple_print(std::string txt){
    cout << txt << endl;
}

int help_command(){
    simple_print("Adding: -a / -add (service) (mail) (username) (password)");
    simple_print("Removing: -r / -remove (service)");
    simple_print("Listing: -l / -list (can use service/mail/username) to list only with selected criteria or empty to list all");

    return 0;
}

void add_flag(Edit_Style edit_style, char* argv[]){
    edit_file(edit_style, string(argv[2]), string(argv[3]), string(argv[4]), string(argv[5]));
}

void remove_flag(Edit_Style edit_style, char* argv[]){
    edit_file(edit_style, string(argv[2]), " ", " ", " ");
}

void list_flag(Edit_Style edit_style){
    edit_file(edit_style, " ", " ", " ", " ");
}

int parse_first_arg(char* arg, char* argv[]){
    Edit_Style edit_style = LIST;
    if(strcmp(arg, "-h") == 0){
        help_command();
    } else if(strcmp(arg, "-help") == 0){
        help_command();
    } else if(strcmp(arg, "-a") == 0){
        add_flag(ADD, argv);
    } else if(strcmp(arg, "-add") == 0){
        edit_style = ADD;
        add_flag(edit_style, argv);
    } else if(strcmp(arg, "-r") == 0){
        edit_style = REMOVE;
        remove_flag(edit_style, argv);
    } else if(strcmp(arg, "-remove") == 0){
        edit_style = REMOVE;
        remove_flag(edit_style, argv);
    } else if(strcmp(arg, "-l") == 0){
        edit_style = LIST;
        list_flag(edit_style);
    } else if(strcmp(arg, "-list") == 0){
        edit_style = LIST;
        list_flag(edit_style);
    }else {
        simple_print("Use -h/-help to list all commands");
    }

    return 0;
}

int first_run(){
    if(check_for_file() == 0){
        return 1;
    }

    return 0;
}

int parse_input(int argc, char* argv[]){
    if(argc == 1) {
        if(first_run() == 0){
            if(generate_file() == 0){
                cout << "File was generated succesfully!" << endl;
            }
        } else {
            simple_print("Use -h/-help to list all commands");
        }
        return 1;
    }

    parse_first_arg(argv[1], argv);
    return 0;
}
