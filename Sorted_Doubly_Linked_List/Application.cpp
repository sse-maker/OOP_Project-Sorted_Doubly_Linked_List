//
//  Application.cpp
//  Sorted_Doubly_Linked_List
//
//  Created by 세광 on 2021/08/12.
//

#include "Application.hpp"

Application::Application() : dList(NULL), mCommand(0) {}
Application::~Application() {
    MakeEmptyList();
    //delete dList;
}

void Application::Run() {
    dList = new DoublyLinkedList;
    
    while (true) {
        switch (GetCommand()) {
            case 1:
                if (AddItem() == 1) cout << endl << "Data added" << endl;
                else cout << endl << "Error! Data has not been added" << endl;
                break;
            
            case 2:
                if (DeleteItem() == 1) cout << endl << "Data deleted" << endl;
                else cout << endl << "Error! Data has not been deleted" << endl;
                break;
                
            case 3:
                if (UpdateItem() == 1) cout << endl << "Data updated" << endl;
                else cout << endl << "Error! Data has not been updated" << endl;
                break;
                
            case 4:
                if (SearchItem() == 0) cout << "Error! key does not exist" << endl;
                break;
                
            case 5:
                DisplayAllItem();
                break;
                
            case 6:
                MakeEmptyList();
                break;
                
            case 0:
                cout << "Quit" << endl;
                return;
                
            default:
                cout << "Error! Wrong command" << endl;
                return;
        }
    }
}
int Application::GetCommand() {
    int command;
    
    cout << endl << endl;
    cout << "\t---ID -- Command ----- " << endl;
    cout << "\t    1 : Add new item" << endl;
    cout << "\t    2 : Delete item" << endl;
    cout << "\t    3 : Update item" << endl;
    cout << "\t    4 : Search item by ID" << endl;
    cout << "\t    5 : Print all on screen" << endl;
    cout << "\t    6 : Make empty list" << endl;
    cout << "\t    0 : Quit" << endl;
    
    cout << endl << "\t Choose a Command--> ";
    cin >> command;
    cout << endl;
    
    return command;
}

int Application::AddItem() {
    int newKey;
    string newName;
    cout << "Enter the key of new item: "; cin >> newKey;
    cout << "Enter the name of new item: "; cin >> newName;
    ItemType newItem(newKey, newName);
    return dList->Add(newItem);
}

int Application::DeleteItem() {
    int deleteKey;
    cout << "Enter the key that want to delete: "; cin >> deleteKey;
    ItemType deleteItem;
    deleteItem.SetId(deleteKey);
    return dList->Delete(deleteItem);
}

int Application::UpdateItem() {
    int updateKey;
    string updateName;
    cout << "Enter the key of the item that want to update: "; cin >> updateKey;
    cout << "Enter the name of the item that want to update: "; cin >> updateName;
    ItemType updateItem(updateKey, updateName);
    return dList->Replace(updateItem);
}

int Application::SearchItem() {
    int searchKey;
    cout << "Enter the key of the item that want to find: "; cin >> searchKey;
    ItemType searchItem;
    searchItem.SetId(searchKey);
    return dList->Get(searchItem);
}

void Application::DisplayAllItem() {
    if (dList->GetLength() == 0) cout << "There is nothing in the list" << endl;
    NodeType *currNode = dList->GetpFirst();
    for (int i = 1; i <= dList->GetLength(); i++) {
        cout << "Node number: " << i << endl;
        cout << "ID: " << currNode->data.GetId() << endl;
        cout << "Name: " << currNode->data.GetName() << endl << endl;
        currNode = currNode->next;
    }
}

void Application::MakeEmptyList() {
    if (dList->GetpFirst() == NULL) return;
    dList->MakeEmpty();
    cout << "All memory has been deleted" << endl;
}
