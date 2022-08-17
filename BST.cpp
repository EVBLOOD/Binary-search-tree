/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakllam <sakllam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:09:49 by sakllam           #+#    #+#             */
/*   Updated: 2022/08/17 12:38:47 by sakllam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "bst_body.hpp"


int main()
{
    ft::bst_body<int> root;
    // ft::bst_body<int, std::greater<int> > root;
    root.insert(0);
    root.insert(8);
    root.insert(10);
    root.insert(20);
    root.insert(17);
    // root.insert(17);
    // std::cout << root.find(0) << "\n";
    // std::cout << root.find(-1) << "\n";
    // std::cout << root.find(20) << "\n";
    // root.printing();
    root.free_tree();
    // system("leaks a.out");
}