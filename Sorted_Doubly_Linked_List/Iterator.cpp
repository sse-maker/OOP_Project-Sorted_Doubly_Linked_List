//
//  Iterator.cpp
//  Sorted_Doubly_Linked_List
//
//  Created by 세광 on 2021/08/12.
//

#include "Iterator.hpp"

Iterator::Iterator(const DoublyLinkedList &dlist) : dList(dlist), pCurPointer(dlist.GetpFirst()) {}
Iterator::~Iterator() {}

DoublyLinkedList Iterator::GetdList() const { return dList; }
NodeType* Iterator::GetpCurPointer() const { return pCurPointer; }
void Iterator::SetpCurPointer(NodeType* pCurPointer) { this->pCurPointer = pCurPointer; }

bool Iterator::NotNull() {
    return pCurPointer != NULL;
}
bool Iterator::NextNotNull() {
    return pCurPointer->next != NULL;
}
bool Iterator::PrevNotNull() {
    return pCurPointer->prev != NULL;
}
ItemType Iterator::First() {
    return dList.GetpFirst()->data;
}
ItemType Iterator::Next() {
    pCurPointer = pCurPointer->next;
    return pCurPointer->data;
}
ItemType Iterator::Prev() {
    pCurPointer = pCurPointer->prev;
    return pCurPointer->data;
}
NodeType Iterator::GetCurrentNode() {
    return *pCurPointer;
}
