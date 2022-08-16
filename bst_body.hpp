/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_body.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:26:51 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/16 21:11:57 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <memory>
#include <cstddef>
#include <string>
#include <iostream>
#include <sys/_types/_size_t.h>


namespace ft
{
    template <class x = int>
        struct bst
    {
            typedef x type;
            typedef bst<type> my_bst;

            type value;
            my_bst *left;
            my_bst *right;
            bst(type value) : value(value), right(NULL), left(NULL) {}
    };
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<bst<T> > >
        class bst_body
    {
            typedef Alloc allocator_type;
            typedef T value_type;
            typedef Compare cmp;
            
            bst<T>          *head;
            allocator_type  alloc;
            size_t          size;
            cmp             compare;

            void inserthelper(bst<T> **root, bst<T> *_new)
            {
                if (*root == NULL)
                {
                    *root = _new;
                    return;
                }
                if (compare(_new->value, (*root)->value)) 
                    inserthelper(&((*root)->left), _new);
                else
                    inserthelper(&((*root)->right), _new);
            }
            void free_tree(bst<T> *x)
            {
                
            }
            void printinghelper(bst<T> *root, std::string name, int i)
            {
                if (!root)
                    return;
                printinghelper(root->left, "left", i + 1);
                std::cout << i << "  " <<  name << " :" << root->value << std::endl;
                printinghelper(root->right, "right", i + 1);
            }
            bool findhelper(bst<T> *root, T value)
            {
                if (root == NULL)
                  return false;
                if (root->value ==  value)
                    return true;
                return findhelper(root->left, value) || findhelper(root->right, value);
            }
            public:
                bst_body() : head(NULL), size(0) {};
                ~bst_body()
                {
                    // alloc.deallocate(head, this->size);
                    free_tree(this->head);
                }
                void insert(T el)
                {
                    if (find(el))
                        return;
                    inserthelper(&(this->head), makenew(el));
                    size++;
                }
                bool find(T value)
                {
                    return findhelper(this->head, value);
                }
                bst<T>    *makenew(T value)
                {
                    bst<T> *c = alloc.allocate(1);
                    c->value = value;
                    c->left = c->right = NULL;
                    return c;
                }
                void printing()
                {
                    if (size)
                        printinghelper(this->head, "root", 0);
                }
                size_t  Size()
                {
                    return size;
                }
            
    };
}
