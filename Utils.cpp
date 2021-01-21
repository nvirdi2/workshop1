//Navdeep Virdi

#include <iostream>
#include "Utils.h"
using namespace std;

namespace sdds
{
   void flushkeys() 
   {
      while (cin.get() != '\n');
   }


   bool ValidYesResponse(char ch) 
   {
      return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
   }  


int readInt(int min, int max) 
   {
      int x = 0;
      bool completed = false;

      while (!completed) 
      {
         cin >> x;
         if (!cin) {
            cin.clear();
            cout << "Bad integer, try agian: ";
         }

         else 
         {
            if (x >= min && x <= max) 
            {
               completed = true;
            }
            else
            {
               cout << "Value out of range (" << min << "<=x<=" << max << "): ";
            }
         }

         flushkeys();
      }

   return x;
   }


   bool yes() 
   {
      char ch = 0;

      do 
      {
         cin >> ch;
         flushkeys();
      } while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");

      return ch == 'y' || ch == 'Y';
   }


   void readCstr(char cstr[], int len) 
   {
      char buf[1024] = {};
      int i;
      cin.getline(buf, 1024);

      for (i = 0; i < len && buf[i]; i++)
      {
         cstr[i] = buf[i];
      }

      cstr[i] = 0;
   }
}