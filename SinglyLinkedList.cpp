//
// Created by antonioalanxs on 30/06/2022.
//

#include <iostream>
#include "SinglyLinkedList.h"

using std::cout;
using std::endl;

void Create(TList &head_ptr) {
    head_ptr = nullptr;
}

void PushFront(TList &head_ptr, int value) {
    TNode* new_node_ptr = new TNode;
    new_node_ptr->value = value;
    new_node_ptr->next = head_ptr;
    head_ptr = new_node_ptr;
}

void PushBack(TList &head_ptr, int value) {
    TNode* new_node_ptr = new TNode;
    new_node_ptr->value = value;
    new_node_ptr->next = nullptr;
    if (head_ptr == nullptr) {
        head_ptr = new_node_ptr;
    } else {
        TList aux_ptr = head_ptr;
        while (aux_ptr->next != nullptr) {
            aux_ptr = aux_ptr->next;
        }
        aux_ptr->next = new_node_ptr;
    }
}

/**
 * Traverse linked list using two-pointers. Move one pointer by one and the other pointers by two. When the fast
 * pointer reaches the end, the slow pointer will reach the middle of the linked list.
 * @param head_ptr
 * @param last_ptr
 * @return pointer to a middle node.
 * @author antonioalanxs
 */
TNode* Middle(TList head_ptr, TNode* last_ptr) {
    if (head_ptr != nullptr) {
        if (last_ptr == head_ptr || head_ptr->next == nullptr) {
            return head_ptr;
        }
        TList aux_slow_ptr = head_ptr;
        TList aux_fast_ptr = head_ptr->next;
        while (aux_fast_ptr != last_ptr) {
            aux_fast_ptr = aux_fast_ptr->next;
            aux_slow_ptr = aux_slow_ptr->next;
            if (aux_fast_ptr != last_ptr) { // So that there is no case where we advance towards NULL (we are at the
                // last node), which would cause a SIGSEV error when trying to compare the
                // loop condition.
                aux_fast_ptr = aux_fast_ptr->next;
            }
        }
        return aux_slow_ptr;
    }
    return nullptr;
}

void Show(TList head_ptr) {
    while (head_ptr != nullptr) {
        cout << head_ptr->value << " -> ";
        head_ptr = head_ptr->next;
    }
    cout << "NULL";
}

/**
 * The famous binary search algorithm, but implemented in a singly linked list and recursively.
 * @param head_ptr
 * @param last_ptr which will be initialized to null at the beginning since it will only be needed if one or more
 * splits of the list to the left occur.
 * @param target
 * @return boolean that depends on if the target value is found.
 * @author antonioalanxs
 */
bool BinarySearch(TList head_ptr, TList last_ptr, int target) {
    if (head_ptr != nullptr) {
        TNode* middle_node_ptr = Middle(head_ptr, last_ptr);
        int current_value = middle_node_ptr->value;

        if (current_value == target) {
            return true;
        }

        if (head_ptr == middle_node_ptr) { // Case where we can't split the list further and current_value =/= target.
            return false;
        }

        if (target > current_value) {
            return BinarySearch(middle_node_ptr->next, last_ptr, target);
        }

        return BinarySearch(head_ptr, middle_node_ptr, target); // current_value > target
    }
    return false;
}
