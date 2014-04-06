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

class LinkedList
{
    LinkedList * tail;
    public:
        LinkedList();
        ~LinkedList();

        void insert(int LineNum, LinkedList * LList);
        //node *search(string key);
        void destroy_LinkedList();
        void display_LinkedList(LinkedList * LList);
        int getLineNum();
        void setLineNum(int LN);

    private:
        int LineNum;
        LinkedList * previous;
        void destroy_LinkedList(LinkedList *LList);
        //void insert(string key, btree *leaf);

        //node *search(string key, node *leaf);
        //btree *root, *left, *right;
};

#endif /* defined(__Lab4__Token__) */
