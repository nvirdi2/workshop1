//Navdeep Virdi

#include <iostream>

#include "ShoppingList.h"
#include "ShoppingRec.h"
#include "File.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
    const int MAX_NO_OF_RECS = 15;
    ShoppingRec recs[MAX_NO_OF_RECS] = {};
    int noOfRecs = 0;


    bool loadList()
    {
        ShoppingRec shpr = {};
        bool x = false;

        if (openFileForRead())
        {
            x = true;

            while (noOfRecs < MAX_NO_OF_RECS && freadShoppingRec(&shpr))
            {
                recs[noOfRecs++] = shpr;
            }
            closeFile();
        }
        return x;
    }


    bool saveList()
    {
        bool x = false;

        if (openFileForOverwrite())
        {
            x = true;

            for (int i = 0; i < noOfRecs; i++)
            {
                fwriteShoppintRec(&recs[i]);
            }
            closeFile();
        }
        return x;
    }


void clearList()
    {
        cout << "This will remove all the items from the list;" << endl
             << "Are you sure? (Y)es/(N)o" << endl;

        if (yes())
        {
            noOfRecs = 0;
        }

        else
        {
            cout << "Cancelled!" << endl;
        }
    }


    void removeItem(int index)
    {
        if (index > 0 && index < noOfRecs)
        {
            noOfRecs--;

            for (int i = index; i < noOfRecs; i++)
            {
                recs[i] = recs[i + 1];
            }
        }
    }

 void addItemToList()
    {
        if (noOfRecs < MAX_NO_OF_RECS)
        {
            recs[noOfRecs] = getShoppingRec();
            noOfRecs += !isShoppingRecEmpty(&recs[noOfRecs]);
        }

        else
        {
            cout << "Shopping List is full!" << endl;
        }
    }


    void toggleBought()
    {
        cout << "Item number: ";
        toggleBoughtFlag(&recs[readInt(1, noOfRecs) - 1]);
    }

    bool listIsEmpty()
    {
        return noOfRecs == 0;
    }


    void removeItemfromList()
    {
        if (!listIsEmpty())
        {
            int x = 0;
            cout << "Item number to delete: ";
            x = readInt(1, noOfRecs);

            cout << "Deleting following item, are you sure?" << endl;
            displayShoppingRec(&recs[x - 1]);
            cout << "(Y)es/(N)o: ";

            if (yes())
            {
                removeItem(x - 1);
            }

            else
            {
                cout << "Cancelled!" << endl;
            }
        }

        else
        {
            cout << "List is empty!" << endl;
        }
    }


    void removeBoughtItems()
    {
        if (!listIsEmpty())
        {
            cout << "Removing bought items, are you sure?" << endl;
            cout << "(Y)es/(N)o: ";
            
            if (yes())
            {
                
                for (int i = 0; i < noOfRecs; i++)
                {
                   
                    if (recs[i].m_bought)
                        removeItem(i--);
                }
            }
           
            else
            {
                cout << "Cancelled!" << endl;
            }
        }
        
        else
        {
            cout << "List is empty!" << endl;
        }
    }

    
    void displayList()
    {
        for (int i = 0; i < noOfRecs; i++)
        {
            cout << (i + 1) << "-";
            displayShoppingRec(&recs[i]);
        }
    }
}