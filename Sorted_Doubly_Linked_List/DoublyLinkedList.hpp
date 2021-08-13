//
//  DoublyLinkedList.hpp
//  Sorted_Doubly_Linked_List
//
//  Created by 세광 on 2021/08/12.
//

#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include "ItemType.hpp"

struct NodeType {
    ItemType data;
    NodeType *prev;
    NodeType *next;
};

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    NodeType* GetpFirst() const;
    NodeType* GetpLast() const;
    int GetLength() const;
    void SetpFirst(NodeType *pFirst);
    void SetpLast(NodeType *pLast);
    void SetLength(int length);
    
    bool IsEmpty();
    void MakeEmpty();
    int Add(ItemType item);
    int Delete(ItemType item);
    int Replace(ItemType item);
    int Get(ItemType &item);
    
private:
    NodeType *pFirst;
    NodeType *pLast;
    int length;
};

#endif /* DoublyLinkedList_hpp */
