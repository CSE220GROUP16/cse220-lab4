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
}
btree::~btree()
{
  //destroy_tree(root);
}

void btree::destroy_tree(btree * leaf)
{
    //set leaf to root pointer
      static int i = 1;
      if (i)
      {
        i =0;
        leaf = root;
      }
      if(leaf!=NULL)
      {
          destroy_tree(leaf->Lleaf);
          destroy_tree(leaf->Rleaf);
          //call delete list
          delete leaf;
      }
}

void btree::display_tree(btree * leaf)
{
    //point to root and display header line
    static int i = 1;
    if (i)
    {
        i =0;
        leaf = root;
        cout<<"identifier\t line number\n";
        cout<<"~~~~~~~~~~~~\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
    //display tree by recursive for code density
    if(leaf!=NULL)
    {
        display_tree(leaf->Lleaf);
        display_tree(leaf->Rleaf);
        cout<<leaf->mytoken->getTokenString()<<"\t\t";
        leaf->myLlist.display_list();
        cout<<endl;
    }

    /*
     //display tree to travel to lowest leaf and up
     btree * temp, *current;

     //start from the root
     current = root;
     cout<<"identifier\t line number\n";
     cout<<"~~~~~~~~~~~~\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
     while(current != NULL)
     {
        // print data if no more left leaf
        if(current->Lleaf == NULL)
        {
        cout<<current->mytoken->getTokenString()<<"\t\t";
        current->myLlist.display_list();
        cout<<endl;
        current = current->Rleaf;
        }

        //search for the lowest left leaf
        else
        {
            temp = current->Lleaf;
            while(temp->Rleaf != NULL && temp->Rleaf != current)
            temp = temp->Rleaf;

            //point to the next leaf in the tree
            if(temp->Rleaf == NULL)
            {
            temp->Rleaf = current;
            current = current->Lleaf;
            }

            //print data if no more right leaf
            else
            {
            temp->Rleaf = NULL;
            cout<<current->mytoken->getTokenString()<<"\t\t";
            current->myLlist.display_list();
            cout<<endl;
            current = current->Rleaf;
            }
        }
     }
     */
}

// insert data to the tree
void btree::insert(string key, int LN)
{
    //create new leaf
    btree * newtree, *temp, * current;
    newtree = new btree;
    newtree->IDValue=key;
    newtree->mytoken=new Token;
    newtree->mytoken->setTokenString(key);
    newtree->Lleaf=NULL;
    newtree->Rleaf=NULL;
    bool isToken = false;
    bool insertLleaf = false;

    // insert at the root
    if (root == NULL)
    {
        root = newtree;
        root->myLlist.insert(LN);
        //cout<< "at root "<<key<<"\t and "<<root->mytoken->getTokenString()<<"\n";
    }
    // insert new leaf
    else
    {
        //pointer to the root
        current = root;

        //search for the next leaf position
        while(current)
        {
            // search for match identifier
            if (key==current->mytoken->getTokenString())
            {
                isToken=true;
                break;
            }
            //go to the left leaf if incoming data is less
            else if (key<current->mytoken->getTokenString())
            {
                temp = current;
                current=current->Lleaf;
                insertLleaf=true;
            }
            //go to the right leaf if incoming data is greater
            else
            {
                temp = current;
                current=current->Rleaf;
            }
        }
        // no new leaf needed if identifier already existed just add to the list
        if(isToken==true)
        {
            current->myLlist.insert(LN);
        }
        //insert new leaf
        else
        {
            if (insertLleaf)
            {
               temp->Lleaf=newtree;
               temp->Lleaf->myLlist.insert(LN);
            }
            else
            {
                temp->Rleaf=newtree;
                temp->Rleaf->myLlist.insert(LN);
            }
        }
    }
}


