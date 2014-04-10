//
//  Token.h
//  Lab4
//
//  Created by Bryce Holton.
//

#ifndef __Lab4__LINKEDLIST__
#define __Lab4__LINKEDLIST__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Common.h"

using namespace std;

// Node class
class Node {
    int data;
    Node* next;

  public:
    Node();
    ~Node();
    int GetData();
    Node* GetNext();
    void SetData(int LN);
    void SetNext(Node* NextNode);
    void destroy_node();
};

// List class
class List {
    Node *head;

  public:
    List();
    ~List();
    void display_list();
    void insert(int data);
    void destroy_list();
};


#endif /* defined(__Lab4__Token__) */
