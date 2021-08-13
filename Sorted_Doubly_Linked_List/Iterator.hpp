//
//  Iterator.hpp
//  Sorted_Doubly_Linked_List
//
//  Created by 세광 on 2021/08/12.
//

#ifndef Iterator_hpp
#define Iterator_hpp

#include "DoublyLinkedList.hpp"

class Iterator {
public:
    Iterator(const DoublyLinkedList &dlist);
    ~Iterator();
    
    DoublyLinkedList GetdList() const;
    NodeType* GetpCurPointer() const;
    void SetpCurPointer(NodeType* pCurPointer);
    
    bool NotNull();
    bool NextNotNull();
    bool PrevNotNull();
    ItemType First();
    ItemType Next();
    ItemType Prev();
    NodeType GetCurrentNode();
    
private:
    const DoublyLinkedList &dList;
    NodeType *pCurPointer;
};

#endif /* Iterator_hpp */
