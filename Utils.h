//Navdeep Virdi

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
    bool ValidYesResponse(char ch);
    bool yes();

    void flushkeys();
    void readCstr(char cstr[], int len);
    
    int readInt(int min, int max);
} 

#endif