#include "menu.h"
namespace menu_list {
	void run_typed_menu() {
	    std::cout << "Choose template type:\n";
	    std::cout << "1. int, std::string\n";
	    std::cout << "2. std::string, double\n";
	    int choice;
	    std::cin >> choice;

	    if (choice == 1) {
	        AVLMenu<int, std::string> menu;
	        auto cmds = menu.get_menu();
	        while (true) {
	            std::cout << "\nMenu:\n";
	            for (size_t i = 0; i < cmds.size(); ++i)
	                std::cout << i + 1 << ". " << cmds[i].first << "\n";
	            std::cout << "0. Exit\n";

	            std::cout << "Choose command: "; 
	            size_t cmd;
	            std::cin >> cmd;
	            if (cmd == 0 || cmd > cmds.size()) break;
	            cmds[cmd-1].second();
	        }
	    }
	    else if (choice == 2) {
	        AVLMenu<std::string, double> menu;
	        auto cmds = menu.get_menu();
	        while (true) {
	            std::cout << "\nMenu:\n";
	            for (size_t i = 0; i < cmds.size(); ++i)
	                std::cout << i + 1 << ". " << cmds[i].first << "\n";
	            std::cout << "0. Exit\n";

	            std::cout << "Choose command: "; 
	            size_t cmd;
	            std::cin >> cmd;
	            if (cmd == 0 || cmd > cmds.size()) break;
	            cmds[cmd-1].second();
	        }
	    }
	    else {
	        std::cout << "Invalid choice.\n";
	    }
	}

}
