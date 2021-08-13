//
//  Application.hpp
//  Sorted_Doubly_Linked_List
//
//  Created by 세광 on 2021/08/12.
//

#ifndef Application_hpp
#define Application_hpp

#include "Iterator.hpp"

class Application {
public:
    Application();
    ~Application();
    
    void Run();
    int GetCommand();
    int AddItem();
    int DeleteItem();
    int UpdateItem();
    int SearchItem();
    void DisplayAllItem();
    void MakeEmptyList();
    
private:
    DoublyLinkedList *dList;
    int mCommand;
};

#endif /* Application_hpp */
