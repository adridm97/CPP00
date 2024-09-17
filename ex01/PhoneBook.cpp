/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 21:16:53 by adrian            #+#    #+#             */
/*   Updated: 2024/09/16 18:50:22 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _num_of_contact(0)
{
    return;
}

bool isNonEmpty(const std::string& str) {
    return str.find_first_not_of(' ') != std::string::npos;
}
PhoneBook::~PhoneBook(){return ;}
void    PhoneBook::addContact()
{
    std::string firstName, lastName, nickName, phoneNum, darkestSecret;
    while (true) {
        std::cout << "Introduce el nombre: ";
        std::getline(std::cin, firstName);
        if (isNonEmpty(firstName)) break;
        std::cerr << "El nombre no puede estar vacío o solo contener espacios. Inténtalo de nuevo." << std::endl;
    }
    while (true) {
        std::cout << "Introduce el apellido: ";
        std::getline(std::cin, lastName);
        if (isNonEmpty(lastName)) break;
        std::cerr << "El apellido no puede estar vacío o solo contener espacios. Inténtalo de nuevo." << std::endl;
    }
    while (true) {
        std::cout << "Introduce el apodo: ";
        std::getline(std::cin, nickName);
        if (isNonEmpty(nickName)) break;
        std::cerr << "El apodo no puede estar vacío o solo contener espacios. Inténtalo de nuevo." << std::endl;
    }
    while (true) {
        std::cout << "Introduce el número de teléfono: ";
        std::getline(std::cin, phoneNum);
        if (isNonEmpty(phoneNum)) break;
        std::cerr << "El número de teléfono no puede estar vacío o solo contener espacios. Inténtalo de nuevo." << std::endl;
    }
    while (true) {
        std::cout << "Introduce el secreto más oscuro: ";
        std::getline(std::cin, darkestSecret);
        if (isNonEmpty(darkestSecret)) break;
        std::cerr << "El secreto más oscuro no puede estar vacío o solo contener espacios. Inténtalo de nuevo." << std::endl;
    }
    int index = _num_of_contact % 8;
    _contacts[index].setUserData(firstName, lastName, nickName, phoneNum, darkestSecret);
    _num_of_contact++;
}


std::string formatField(const std::string& field) {
    if (field.length() > 10) {
        return field.substr(0, 9) + '*';  // Trunca y añade '*'
    } else {
        return field + std::string(10 - field.length(), ' ');  // Rellena con espacios
    }
}

bool    PhoneBook::searchContact() const
{
    if (_num_of_contact == 0) {
        std::cerr << "No hay contactos para buscar." << std::endl;
        return false;
    }

    std::cout << std::setw(6) << "Index" 
              << " | " << std::setw(10) << "First Name" 
              << " | " << std::setw(10) << "Last Name" 
              << " | " << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < std::min(_num_of_contact, 8); i++) {
        std::cout << std::setw(6) << (i + 1) 
                  << " | " << formatField(_contacts[i].getFirstName()) 
                  << " | " << formatField(_contacts[i].getLastName()) 
                  << " | " << formatField(_contacts[i].getNickName()) << std::endl;
    }
    std::string input;
    int index;
    std::cout << "Introduce el índice del contacto que quieres ver: ";
    if (!(std::cin >> index)) {
        std::cerr << "Entrada no válida. Introduce un número." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    try {
        if (index < 1 || index > std::min(_num_of_contact, 8)) {
            throw std::out_of_range("Índice fuera de rango.");
        }
        displayContact(index - 1);
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}
void PhoneBook::displayContact(int index) const {
    std::cout << "Nombre: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "Apellido: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Apodo: " << _contacts[index].getNickName() << std::endl;
    std::cout << "Número de teléfono: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Secreto oscuro: " << _contacts[index].getDarkestSecret() << std::endl;
}