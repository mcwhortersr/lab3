#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

arrayList * initialize(primitiveType type)
{
   arrayList * arr = malloc(sizeof(arrayList));
   arr -> array =  malloc(getSize(type)*4);
   arr -> arraySize = 4;
   arr -> numElements = 0;
   arr -> type = type;

   return arr;
}

int getSize(primitiveType type)
{
   if(type == charType)
       return sizeof(char);
   else if(type == shortType)
       return sizeof(short);
   else if(type == intType);
       return sizeof(int);
   return ;
}

void addElement(arrayList * arylstP, void * element)
{
   if((arylstP -> numElements)>= (arylstP -> arraySize)){
    
       arrayList * newArr = malloc(sizeof(arrayList));       
       newArr -> arraySize = arylstP -> arraySize *2;
       newArr -> array =  malloc(arraySize);
       newArr -> numElements = arylstP;
       newArr -> type = type;
       
       for(int i = 0;i<sizeof(arylstP[i]/sizeof(byte)) ; i++){
            (char *)
    
       }
   }
   if(arylstP -> type == charType){
       
   }
   else if(arylstP -> type = intType){

   }
   else if(arylstP -> = shortType){

   }
   aryLstP[arylstP->(arraySize+4)] = element;
   aryLstP -> arraySize = (arylstP -> arraySize)+4;
   
   return;
}

void removeElement(arrayList * arylstP, int index)
{
   
   return;
}
      

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff);
   }
   printf("\n");
}

