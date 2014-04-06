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
  //tail=NULL;
}
LinkedList::~LinkedList()
{
  //destroy_LinkedList();
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
    LinkedList * newList, *temp;
    newList=new LinkedList;
    newList->setLineNum(LineNum);
    newList->previous=NULL;

    if (LList==NULL)
    {
      LList=newList;
      LList->previous=NULL;    //Sets the left child of the child node to null
      //tail = LList;
     cout<< "the tail link number is "<<"\t"<<LList->getLineNum()<<"\n";
    }
    //insert at left child <
    else
    {
        temp=LList;
        while(temp!=NULL)
        {
          temp=temp->previous;
        }
        LList->previous=newList;
    }
}


