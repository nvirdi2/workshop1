//Navdeep Virdi

#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "ShoppingRec.h"

namespace sdds
{
    const char *const SHOPPING_DATA_FILE = "shoppinglist.csv";
    
    bool openFileForRead();
    bool openFileForOverwrite();
    bool freadShoppingRec(ShoppingRec *rec);
    
    void closeFile();
    void fwriteShoppintRec(const ShoppingRec *rec);

}

#endif