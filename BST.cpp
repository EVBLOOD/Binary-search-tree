/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:09:49 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/17 16:26:36 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "bst_body.hpp"


int main()
{
    ft::bst_body<int> root;
    // ft::bst_body<int, std::greater<int> > root;
    root.insert(5);
    root.insert(2);
    root.insert(7);
    root.insert(10);
    root.insert(20);
    root.insert(17);
    root.remove(5);
    root.remove(2);
    root.remove(17);
    root.remove(20);
    root.remove(7);
    root.remove(10);
    root.remove(0);
    // root.insert(17);
    // std::cout << root.find(0) << "\n";
    // std::cout << root.find(-1) << "\n";
    // std::cout << root.find(20) << "\n";
    root.printing();
    // root.free_tree();
    // system("leaks a.out");
}