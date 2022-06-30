//
// Created by antonioalanxs.
//

#ifndef RECURSIVE_BINARY_SEARCH_ON_SINGLY_LINKED_LIST_SINGLYLINKEDLIST_H
#define RECURSIVE_BINARY_SEARCH_ON_SINGLY_LINKED_LIST_SINGLYLINKEDLIST_H

typedef struct TNode {
    int value;
    TNode* next;
} TNode;

typedef TNode* TList;

void Create(TList &head_ptr);
void PushFront(TList &head_ptr, int value);
void PushBack(TList &head_ptr, int value);
TNode* Middle(TList head_ptr, TNode* last_ptr);
void Show(TList head_ptr);
bool BinarySearch(TList head_ptr, TList last_ptr, int target);

#endif
