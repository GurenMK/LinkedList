//Alexander Urbanyak


#include <iostream>
#include "node1.h"

using namespace main_savitch_5;


node *create_list();
//Post-condition: create a list in descending order
node *create_list_2();
//Post-condition: create a list in descending order
node *merge_lists(node *l1, node *l2);
//Post-condition: create a list in ascending order containing elements of the provided lists without duplicates
std::ostream& operator << (std::ostream& output, const node *head_ptr);

int main() {
    node *list = create_list();
    node *list_2 = create_list_2();
    node *merge = merge_lists(list, list_2);
    std::cout << "List 1: " << list << std::endl;
    std::cout << "List 2: " << list_2 << std::endl;
    std::cout << "Merged: " << merge << std::endl;
    return 0;
}

node *create_list() {
    node *list = NULL;
    list_head_insert(list, 4);
    list_head_insert(list, 5);
    list_head_insert(list, 6);
    list_head_insert(list, 7);
    list_head_insert(list, 8);
    list_head_insert(list, 9);
    return list;
}

node *create_list_2() {
    node *list = NULL;
    list_head_insert(list, 1);
    list_head_insert(list, 2);
    list_head_insert(list, 3);
    list_head_insert(list, 4);
    list_head_insert(list, 5);
    list_head_insert(list, 6);
    return list;
}

node *merge_lists(node *l1, node *l2) {
    node *list = NULL;
    if (l1 ->data() > l2 ->data()) {
        list_head_insert(list, l1 ->data());
        l1 = l1 ->link();
    }
    else {
        list_head_insert(list, l2 ->data());
        l2 = l2 ->link();
    }

    for (node *list_2 = l2; list_2 != NULL; list_2 = list_2 ->link()) {
        for (node *list_1 = l1; list_1 != NULL; list_1 = list_1->link()) {
            if (list_1->data() > l2->data() && list_search(list, list_1->data()) == NULL) 
             {
                list_head_insert(list, list_1->data());
            }
        }
        if (l1->data() > list_2->data() && list_search(list, list_2->data()) == NULL) {
            list_head_insert(list, list_2->data());
        }
    }
    return list;
}

std::ostream& operator << (std::ostream& output, const node *head_ptr) {
    const node *list = head_ptr;
    while(list != NULL) {
        output << list ->data() << " ";
        list = list ->link();
    }
    return output;
}