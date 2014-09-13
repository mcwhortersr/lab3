#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);
/*
*Function: initialize
*Returns: a pointer to the arrayList struct
*
*Purpose: The purpose of this function is to take a primitiveType type and initialize
* an arrayList struct and a default array size of 4.
*
*
*/
arrayList * initialize(primitiveType type)
{
   arrayList * arr = malloc(sizeof(arrayList));
   arr -> array =  malloc(getSize(type)*4);
   arr -> arraySize = 4;
   arr -> numElements = 0;
   arr -> type = type;
   arr -> elementSize = getSize(type);
   return arr;
}

/*
*Function: getSize 
*Returns: an int representing the size of the type in bytes
*
*Purpose: To return an integer representing the size of the primitievType parameter
*/
int getSize(primitiveType type)
{
   if(type == charType)
       return sizeof(char);
   else if(type == shortType)
       return sizeof(short);
   else if(type == intType);
       return sizeof(int);
   
}

/*
*Function: addElement 
*Returns: Nothing
*
*Purpose: Takes in an arrayList pointer, and a pointer to an element of unknown type.
* If the array in the arrayList is full, the function will allocate enough memory to accomodate the new array of arraySize*2.
* After making sure the array is big enough, the function will add the element to the arrayList.
*/
void addElement(arrayList * arylstP, void * element)
{


   if((arylstP -> numElements)>= (arylstP -> arraySize)){
    
       int newArraySize = arylstP -> arraySize *2;
       
       void * newArray =  malloc(2* (arylstP -> numElements*arylstP->elementSize) );
       int i;  
           for(i=0;i<((arylstP -> numElements) * (arylstP->elementSize)) ; i++){
            ((char *) newArray)[i] = *((char *)(arylstP->array+i));
           }
           free(arylstP->array);
           arylstP -> arraySize = newArraySize;
           arylstP -> array = newArray;
    }

   
   if (arylstP->type == charType)
   {
      *(((char *) arylstP->array) + arylstP->numElements) = *((char *) element); 
   }
   if (arylstP->type == intType)
   {
      *(((int *) arylstP->array) + arylstP->numElements) = *((int *) element);
   }
   if (arylstP->type == shortType)
   {
      *(((short *) arylstP->array) + arylstP->numElements) = *((short *) element); 
   }

   arylstP->numElements++;
   return;
}

/*
*Function: removeElement 
*Returns: Nothing
*
*Purpose: Takes in an arrayList pointer, and an integer.
*
*Removes the element specified by the index parameter from the arrayList
*/
void removeElement(arrayList * arylstP, int index)
{
   int i;
   if(arylstP -> type == intType){        
        for(i=index;i<arylstP ->numElements-1;i++){
            *((int *)arylstP->array+i) = *((int*)arylstP->array+i+1);
        }
   }
   if(arylstP -> type == shortType){
        for(i=index;i<arylstP ->numElements-1;i++){
            *((short *)arylstP->array+i) = *((short *)arylstP->array+i+1);
        }
   }
   if(arylstP -> type == charType){
        for(i=index;i<arylstP ->numElements-1;i++){
            *((char *)arylstP->array+i) = *((char *)arylstP->array+i+1);
        }
   }

    
   arylstP->numElements--;
   return;
}
      

/*
*Function: printArray 
*Returns: Nothing
*
*Purpose: Takes in an arrayList pointer, and an integer.
*
*Prints every item in the arrayList
*/
void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
          printf("%02x ",*((char *)arylstP->array+i)& 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", *((short *)arylstP->array+i)&0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", *((int *)arylstP->array+i)&0xffffffff);
   }
   printf("\n");
}

