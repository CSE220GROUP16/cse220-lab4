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
  root=NULL;
}
btree::~btree()
{
  destroy_tree(root);
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
static int i = 0;
  if(leaf!=NULL)
  {
    display_tree(leaf->Lleaf);
    display_tree(leaf->Rleaf);
    //cout<< "the leaf data is "<<++i<<"\t"<<leaf->IDValue<<"\n";
  }

}

void btree::insert(string key, btree * leaf)
{
    //insert at root
    if (leaf==NULL)
    {
      leaf=new btree;
      leaf->IDValue=key;
      leaf->Lleaf=NULL;    //Sets the left child of the child node to null
      leaf->Rleaf=NULL;   //Sets the right child of the child node to null
      root = leaf;
      //cout<< "i am at the root  and the key is "<<root->IDValue<<"\n";
    }

    //insert at left child <
  else if(key<leaf->IDValue)
  {
    if(leaf->Lleaf!=NULL)
     insert(key, leaf->Lleaf);
    else
    {
      leaf->Lleaf=new btree;
      leaf->Lleaf->IDValue=key;
      leaf->Lleaf->Lleaf=NULL;    //Sets the left child of the child node to null
      leaf->Lleaf->Rleaf=NULL;   //Sets the right child of the child node to null
    }
    //cout<< "i am at the Lleaf  and the key is "<<leaf->Lleaf->IDValue<<"\n";

  }
  //insert at right child >=
  else //if(key, leaf->IDValue)
  {
    if(leaf->Rleaf!=NULL)
      insert(key, leaf->Rleaf);
    else
    {
      leaf->Rleaf=new btree;
      leaf->Rleaf->IDValue=key;
      leaf->Rleaf->Lleaf=NULL;  //Sets the left child of the child node to null
      leaf->Rleaf->Rleaf=NULL; //Sets the right child of the child node to null
    }
    //cout<< "i am at the Rleaf  and the key is "<<leaf->Rleaf->IDValue<<"\n";
  }

}


