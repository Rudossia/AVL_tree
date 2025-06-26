#ifndef MENU_LIST_H
#define MENU_LIST_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "../tree/tree.h"

namespace menu_list {

template <typename T, typename U>
class AVLMenu {
    Tree::avl_tree<T, U> tree;
public:
    void insert() {
        T key;
        U value;
        std::cout << "Enter key and value: ";
        std::cin >> key >> value;
        tree.insert(key, value);
    }
    void view() {
        tree.view_tree();
    }
    void remove() {
        T key;
        std::cout << "Enter key to remove: ";
        std::cin >> key;
        tree.remove(key);
        std::cout << "Remove method pass.\n";
    }
    void find() {
        T key;
        std::cout << "Enter key to find: ";
        std::cin >> key;
        // TODO: реализовать метод find в avl_tree
        // auto node = tree.find(key);
        std::cout << "Find method not implemented yet.\n";
    }
    void clear() {
        // TODO: реализовать метод clear в avl_tree
        // tree.clear();
        std::cout << "Clear method not implemented yet.\n";
    }

    void height() {
        // TODO: реализовать метод height в avl_tree
        // std::cout << "Tree height: " << tree.height() << "\n";
        std::cout << "Height method not implemented yet.\n";
    }
	void export_dot() {
	    std::string base;
	    std::cout << "Enter base filename (without extension): ";
	    std::cin >> base;

	    std::string dot_name = base + ".dot";
	    std::string png_name = base + ".png";

	    tree.generate_dot(dot_name);
	    std::cout << "DOT file created: " << dot_name << "\n";

	    std::string dot_cmd = "dot -Tpng " + dot_name + " -o " + png_name;
	    system(dot_cmd.c_str());

	    std::cout << "PNG image created: " << png_name << "\n";
	}
    std::vector<std::pair<std::string, std::function<void()>>> get_menu() {
        return {
            {"Insert",    [&]() { insert(); }},
            {"View",      [&]() { view(); }},
            {"Remove",    [&]() { remove(); }},
            {"Find",      [&]() { find(); }},
            {"Clear",     [&]() { clear(); }},
            {"Height",    [&]() { height(); }},
            {"Export DOT",[&]() { export_dot(); }}
        };
    }
};

void run_typed_menu();

}

#endif
