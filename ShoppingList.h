//Navdeep Virdi

#ifndef SDDS_SHOPPINGLIST_H
#define SDDS_SHOPPINGLIST_H

namespace sdds
{
    bool loadList();
    bool saveList();
    bool listIsEmpty();

    void displayList();
    void removeBoughtItems();
    void removeItem(int index);
    void clearList();
    void toggleBought();
    void addItemToList();
    void removeItemfromList();
} 

#endif