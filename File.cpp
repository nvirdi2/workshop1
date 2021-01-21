//Navdeep Virdi

#include "File.h"
#include <cstddef>
#include <stdio.h>

namespace sdds
{
    FILE *sfptr = nullptr;

    bool openFileForRead()
    {
        sfptr = fopen(SHOPPING_DATA_FILE, "r");
        return sfptr != NULL;
    }


    bool freadShoppingRec(ShoppingRec *rec)
    {
        int flag = 0;
        bool done = fscanf(sfptr, "%[^,],%d,%d\n",
                              rec->m_title, &rec->m_quantity, &flag) == 3;
        rec->m_bought = !!flag;
        return done;
    }


    bool openFileForOverwrite()
    {
        sfptr = fopen(SHOPPING_DATA_FILE, "w");
        return sfptr != NULL;
    }


    void fwriteShoppintRec(const ShoppingRec *rec)
    {
        fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
    }


    void closeFile()
    {
        if (sfptr)
            fclose(sfptr);
    }
} 