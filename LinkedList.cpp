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

Node::Node()
{

}
Node::~Node()
{

}

void Node::SetData(int LN)
{
    data = LN;
}
void Node::SetNext(Node* NextNode)
{
    next = NextNode;
}
int Node::GetData()
{
    return data;
}
Node* Node::GetNext()
{
    return next;
}
// initialize head
List::List()
{
    head = NULL;
}
// destructor
List::~List()
{

}

// Print all data in the list
void List::display_list() {

    // head pointer
    Node *temp = head;

    // print the list
    if ( temp != NULL )
    {
        while ( temp != NULL )
        {
        cout << temp->GetData()<<"\t";
        temp = temp->GetNext();
        }
    }
    else
    {}
}

// insert at the end of the list
void List::insert(int data) {

    // Create a new node to store new data
    Node* temp, *newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);
    temp = head;

    if ( temp != NULL )
    {
        while ( temp->GetNext() != NULL )
        {
        temp = temp->GetNext();
        }
    temp->SetNext(newNode);
    }
    else
    {
    head = newNode;
    }
}

// deallocate memory delete the list
void List::Delete(int data)
{

    // head pointer
    Node *temp = head;

    // delete the list
    if ( head != NULL )
    {
        while ( head != NULL )
        {
        temp=head;
        head = head->GetNext();
        delete temp;
        }
    }
    else
    {}
}
