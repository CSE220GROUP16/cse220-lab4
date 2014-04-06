//
//  Token.cpp
//  Lab4
//
//  Created by Bryce Holton.
//
#include <string>
#include <iostream>
#include <stdio.h>
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

    cout<<"identifier\t line number\n";
    cout<<"~~~~~~~~~~~~\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    cout<<leaf->mytoken->getTokenString()<<"\t";
    LinkedList*temp;
    temp=leaf->myLlist;
    while(temp!=NULL)
    {
        cout<<temp->getLineNum()<<"\t";
    }
  }
}


void btree::insert(string key, int LN)
{

    btree * newtree, *temp, * current;
    newtree = new btree;
    newtree->IDValue=key;
    newtree->mytoken=new Token;
    newtree->mytoken->setTokenString(key);
    newtree->myLlist=new LinkedList;
    newtree->myLlist->setLineNum(LN);
    newtree->Lleaf=NULL;
    newtree->Rleaf=NULL;
    bool isToken = false;
    bool insertLleaf = false;


    if (root == NULL)
    {
        root=new btree;
        root = newtree;
        cout<< "i am at the root  and the key is "<<root->mytoken->getTokenString()<<"\n";
    }
    else
    {
        current = root;

        //insert at left leaf
        while(current)
        {
            if (key==current->mytoken->getTokenString())
            {
                 cout<< "match found "<<key<<"\t and "<<current->mytoken->getTokenString()<<"\n";
                isToken=true;
                break;
            }

            else if (key<current->mytoken->getTokenString())
            {
                cout<< "inside the left leaf "<<key<<"\t and "<<current->mytoken->getTokenString()<<"\n";
                temp = current;
                current=current->Lleaf;
                insertLleaf=true;
            }
            else
            {
                cout<< "inside the right leaf "<<key<<"\t and "<<current->mytoken->getTokenString()<<"\n";
                temp = current;
                current=current->Rleaf;
            }
        }

        if(isToken==true)
        {
             cout<< "building the linkedlist "<<"\n";
            current->myLlist->insert(LN, current->myLlist);
        }
        else
        {
            if (insertLleaf)
            {
               temp->Lleaf=newtree;
               cout<< "i am at the leaf  and the key is "<<temp->mytoken->getTokenString()<<"\n";
            }
            else
            {
                temp->Rleaf=newtree;
            }

            //temp->mytoken=newtree->mytoken;
            //temp->myLlist=newtree->myLlist;
            //temp->Lleaf=NULL;
            //temp->Rleaf=NULL;

        }
    }
    //insert at root
    //cout<< "i am at inside insert  and the key is "<<key<<"\n";
/*
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
    //cout<< "i am at the end and the key is "<<leaf->IDValue<<"\n
    */
}


