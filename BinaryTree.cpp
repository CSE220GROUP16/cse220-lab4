//
//  Token.cpp
//  Lab4
//
//  Created by Bryce Holton.
//
#include<string>
#include<iostream>
#include "BinaryTree.h"
using namespace std;

btree::btree()
{
  //root=NULL;
}
btree::~btree()
{
  //destroy_tree(root);
}

void btree::destroy_tree(btree * leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->Lleaf);
    destroy_tree(leaf->Rleaf);
    delete leaf;
  }
}

void btree::display_tree(btree * leaf)
{
  if(leaf!=NULL)
  {
    display_tree(leaf->Lleaf);
    display_tree(leaf->Rleaf);
    //display only valid leaf token string
    cout<< "the leaf data is "<<"\t"<<leaf->myLlist->getLineNum()<<"\t"<<leaf->mytoken->getTokenString()<<"\n";
  }
}


void btree::insert(string key, int LN, btree * leaf)
{
    /*
    btree * mytree, *temp;
    mytree = new btree;
    mytree->IDValue=key;
    mytree->mytoken=new Token;
    mytree->mytoken->setTokenString(key);
    mytree->myLlist=new LinkedList;
    mytree->myLlist->setLineNum(LN);

    if (root == NULL)
    {
        root=mytree;
        root->Lleaf=NULL;
        root->Rleaf=NULL;
        cout<< "i am at the root  and the key is "<<root->mytoken->getTokenString()<<"\n";
    }
    else
    {
        temp = root;

        //insert at left leaf
        while(key<temp->mytoken->getTokenString()&&temp->Lleaf!=NULL)
        {
            temp = root->Lleaf;
          cout<< "i am at the leaf  and the key is "<<key<<"\n";
        }

        //insert at right leaf
    }
*/

    //insert at root
    //cout<< "i am at inside insert  and the key is "<<key<<"\n";

    if (root==NULL)
    {
      root=new btree;
      root->IDValue=key;
      root->mytoken=new Token;
      root->mytoken->setTokenString(key);
      root->myLlist=new LinkedList;
      root->myLlist->setLineNum(LN);
      root->Lleaf=NULL;    //Sets the left child of the child node to null
      root->Rleaf=NULL;   //Sets the right child of the child node to null
      leaf=root;
      //cout<< "i am at the root  and the key is "<<root->mytoken->getTokenString()<<"\n";
    }

    //insert at left child <
  else if(key<leaf->mytoken->getTokenString())
  {
      //cout<< "i am at the left leaf  and the key is "<<leaf->IDValue<<"\n";
    if(leaf->Lleaf!=NULL)
    {
        insert(key, LN, leaf->Lleaf);
    }
    else
    {
      leaf->Lleaf=new btree;
      leaf->Lleaf->IDValue=key;

      leaf->Lleaf->mytoken=new Token;
      leaf->Lleaf->mytoken->setTokenString(key);

      leaf->Lleaf->myLlist=new LinkedList;
      leaf->Lleaf->myLlist->setLineNum(LN);

      leaf->Lleaf->Lleaf=NULL;    //Sets the left child of the child node to null
      leaf->Lleaf->Rleaf=NULL;   //Sets the right child of the child node to null
    }
    //cout<< "i am at the Lleaf  and the key is "<<leaf->Lleaf->IDValue<<"\n";

  }
  //insert at right child >=
  else //if(key, leaf->IDValue)
  {
      //cout<< "i am at the right leaf  and the key is "<<leaf->mytoken->getTokenString()<<"\n";
    if(leaf->Rleaf!=NULL)
      insert(key, LN, leaf->Rleaf);
    else
    {
      leaf->Rleaf=new btree;
      leaf->Rleaf->IDValue=key;

      leaf->Rleaf->mytoken=new Token;
      leaf->Rleaf->mytoken->setTokenString(key);

      leaf->Rleaf->myLlist=new LinkedList;
      leaf->Rleaf->myLlist->setLineNum(LN);

      leaf->Rleaf->Lleaf=NULL;  //Sets the left child of the child node to null
      leaf->Rleaf->Rleaf=NULL; //Sets the right child of the child node to null
    }
    //cout<< "i am at the Rleaf  and the key is "<<leaf->Rleaf->IDValue<<"\n";
  }
    //cout<< "i am at the end and the key is "<<leaf->IDValue<<"\n";
}


