//
//  Token.h
//  Lab4
//
//  Created by Bryce Holton.
//

#ifndef __Lab4__BINARYTREE__
#define __Lab4__BINARYTREE__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Common.h"
#include "Token.h"
#include "LinkedList.h"

using namespace std;

class btree
{
    public:
        btree();
        ~btree();
        void insert(string key, int LN);
        //void destroy_tree();
        void destroy_tree(btree * leaf);
        //void display_tree();
        void display_tree(btree *leaf);

    private:
        string IDValue;
        Token * mytoken;
        List myLlist;
        btree * Lleaf, *Rleaf;

        //void destroy_tree(btree *leaf);
        //void insert(string key, btree *leaf);
};
static btree * root;

#endif /* defined(__Lab4__Token__) */
