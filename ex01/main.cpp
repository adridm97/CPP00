/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:40:55 by adrian            #+#    #+#             */
/*   Updated: 2024/09/13 16:23:14 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main(void)
{
    PhoneBook phonebook;
    std::string input;
    std::cout << "Wellcome to the PhoneBook!" << std::endl;
    std::cout << std::endl;
    while (42)
    {
        std::cout << "ENTER YOUR COMMAND --> ";
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            std::cerr << "EOF command ! try a valid one" << std::endl;
            return(1) ;
        }
        else if (input == "ADD")
			phonebook.addContact();
        else if (input == "SEARCH")
			phonebook.searchContact();
        else if (input == "EXIT")
            return (0);
        else
        {
            std::cerr << std::endl << "Invalid command detected !" << std::endl;
            std::cerr << "You migth enter a valid command" << std::endl;
        }
    } 
    return  (0);
}