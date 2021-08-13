//
//  ItemType.hpp
//  Sorted_Doubly_Linked_List
//
//  Created by 세광 on 2021/08/12.
//

#ifndef ItemType_hpp
#define ItemType_hpp

#include <iostream>
#include <string>

using namespace std;

class ItemType {
public:
    ItemType();
    ItemType(int id, string name);
    ItemType(const ItemType& rhs);
    ~ItemType();
    
    int GetId() const;
    string GetName() const;
    void SetId(int id);
    void SetName(string name);
    
    bool operator>(const ItemType& rhs) const;
    bool operator<(const ItemType& rhs) const;
    bool operator==(const ItemType& rhs) const;
    ItemType operator=(const ItemType& rhs);
    
private:
    int id;
    string name;
};

#endif /* ItemType_hpp */
