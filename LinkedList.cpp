//
//  LinkedList.cpp
//  Lab4
//
//  Created by Bryce Holton.
//
#include<string>
#include<iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
  tail=NULL;
}
LinkedList::~LinkedList()
{
  destroy_LinkedList(tail);
}
void LinkedList::setLineNum(int LN)
{
    this->LineNum=LN;
}

int LinkedList::getLineNum()
{
    return this->LineNum;
}

void LinkedList::destroy_LinkedList(LinkedList * LList)
{
  if(LList!=NULL)
  {
    destroy_LinkedList(LList->previous);
    delete LList;
  }
}

void LinkedList::display_LinkedList(LinkedList * LList)
{
    LinkedList * temp = LList;
  while(temp!=NULL)
  {
    //display_LinkedList(LList->previous);
    cout<< "the link number is "<<"\t"<<temp->LineNum<<"\n";
    temp=temp->previous;
  }

}

void LinkedList::insert(int LineNum, LinkedList * LList)
{

    //insert at tail if tail == NULL
    //cout<< "the tail link number is "<<"\t"<<LList->LineNum<<"\n";

    if (LineNum==1)
    {
      LList=new LinkedList();
      LList->LineNum=LineNum;
      LList->previous=NULL;    //Sets the left child of the child node to null
      //tail = LList;
     cout<< "the tail link number is "<<"\t"<<LList->LineNum<<"\n";
    }

    //insert at left child <
  else
  {
     if(LList->previous!=NULL)
     insert(LineNum, LList->previous);
     else
     {
      LList->previous=new LinkedList();
      LList->previous->LineNum=LineNum;
      LList->previous->previous=NULL;
     }

      //cout<< "the link number is "<<"\t"<<LList->LineNum<<"\n";
   }





}


