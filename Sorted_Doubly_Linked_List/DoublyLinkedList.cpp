//
//  DoublyLinkedList.cpp
//  Sorted_Doubly_Linked_List
//
//  Created by 세광 on 2021/08/12.
//

#include "Iterator.hpp"

DoublyLinkedList::DoublyLinkedList() : pFirst(NULL), pLast(NULL), length(0) {}
DoublyLinkedList::~DoublyLinkedList() { MakeEmpty(); }

NodeType* DoublyLinkedList::GetpFirst() const { return pFirst; }
NodeType* DoublyLinkedList::GetpLast() const { return pLast; }
int DoublyLinkedList::GetLength() const { return length; }
void DoublyLinkedList::SetpFirst(NodeType *pFirst) { this->pFirst = pFirst; }
void DoublyLinkedList::SetpLast(NodeType *pLast) { this->pLast = pLast; }
void DoublyLinkedList::SetLength(int length) { this->length = length; }

bool DoublyLinkedList::IsEmpty() {
    return length == 0;
}

void DoublyLinkedList::MakeEmpty() {
    NodeType *temp;
    Iterator makeEmpty(*this);
    
    while (makeEmpty.NextNotNull()) {
        temp = makeEmpty.GetpCurPointer();
        makeEmpty.Next();
        delete temp;
    }
    delete makeEmpty.GetpCurPointer();
    this->pFirst = NULL;
    this->pLast = NULL;
    this->length = 0;
}

int DoublyLinkedList::Add(ItemType item) {
    NodeType *newNode = new NodeType;
    newNode->data = item;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    if (IsEmpty()) {
        SetpFirst(newNode);
        SetpLast(newNode);
        SetLength(length + 1);
        return 1;
    } else {
        Iterator add(*this);
        while (add.NotNull()) {
            if (newNode->data == add.GetCurrentNode().data) {
                cout << "Id already exists" << endl;
                return 0;
            } else if (newNode->data < add.GetCurrentNode().data) {
                if (add.GetpCurPointer() == pFirst) pFirst = newNode;
                else add.GetCurrentNode().prev->next = newNode;
                newNode->prev = add.GetpCurPointer()->prev;
                newNode->next = add.GetpCurPointer();
                SetLength(length + 1);
                return 1;
            }
            add.SetpCurPointer(add.GetCurrentNode().next);
        }
        newNode->prev = pLast;
        pLast->next = newNode;
        SetpLast(newNode);
        SetLength(length + 1);
        return 1;
    }
}

int DoublyLinkedList::Delete(ItemType item) {
    Iterator del(*this);
    
    while (del.NotNull()) {
        if (item == del.GetCurrentNode().data) {
            if (del.NextNotNull() && del.PrevNotNull()) {
                del.GetCurrentNode().prev->next = del.GetCurrentNode().next;
                del.GetCurrentNode().next->prev = del.GetCurrentNode().prev;
            } else if (del.NextNotNull()) {
                SetpFirst(del.GetCurrentNode().next);
                del.GetCurrentNode().next->prev = NULL;
            } else if (del.PrevNotNull()) {
                SetpLast(del.GetCurrentNode().prev);
                del.GetCurrentNode().prev->next = NULL;
            } else {
                SetpFirst(NULL);
                SetpLast(NULL);
            }
            delete del.GetpCurPointer();
            SetLength(length - 1);
            return 1;
        }
        del.SetpCurPointer(del.GetCurrentNode().next);
    }
    return 0;
}

int DoublyLinkedList::Replace(ItemType item) {
    Iterator replace(*this);
    
    while (replace.NotNull()) {
        if (item == replace.GetCurrentNode().data) {
            replace.GetpCurPointer()->data = item;
            return 1;
        }
        replace.SetpCurPointer(replace.GetCurrentNode().next);
    }
    return 0;
}

int DoublyLinkedList::Get(ItemType &item) {
    Iterator get(*this);
    int i = 1;
    
    while (get.NotNull()) {
        if (item == get.GetCurrentNode().data) {
            item = get.GetCurrentNode().data;
            cout << "Node number: " << i << endl;
            cout << "ID: " << item.GetId() << endl;
            cout << "Name: " << item.GetName() << endl << endl;
            return 1;
        }
        i++;
        get.SetpCurPointer(get.GetCurrentNode().next);
    }
    return 0;
}
