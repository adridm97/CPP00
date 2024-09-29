/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:16:48 by adrian            #+#    #+#             */
/*   Updated: 2024/09/29 18:29:33 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"
#include <iomanip>
#include <limits>

class PhoneBook
{
    private:
        int   _num_of_contact;
        Contact _contacts[8];
    public:
        PhoneBook();
        ~PhoneBook();

        void addContact();
        bool searchContact() const;
        void displayContact(int index) const;
};

# endif