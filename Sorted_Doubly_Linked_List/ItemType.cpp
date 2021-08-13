//
//  ItemType.cpp
//  Sorted_Doubly_Linked_List
//
//  Created by 세광 on 2021/08/12.
//

#include "ItemType.hpp"

ItemType::ItemType() : id(-1), name("") {}
ItemType::ItemType(int id, string name) : id(id), name(name) {}
ItemType::ItemType(const ItemType& rhs) {
    SetId(rhs.id);
    SetName(rhs.name);
}
ItemType::~ItemType() {}

int ItemType::GetId() const { return id; }
string ItemType::GetName() const { return name; }
void ItemType::SetId(int id) { this->id = id; }
void ItemType::SetName(string name) { this->name = name; }

bool ItemType::operator>(const ItemType& rhs) const {
    return id > rhs.id;
}
bool ItemType::operator<(const ItemType& rhs) const {
    return id < rhs.id;
}
bool ItemType::operator==(const ItemType& rhs) const {
    return id == rhs.id;
}
ItemType ItemType::operator=(const ItemType& rhs) {
    SetId(rhs.id);
    SetName(rhs.name);
    return *this;
}
