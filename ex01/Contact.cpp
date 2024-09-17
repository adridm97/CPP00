/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:14:53 by adrian            #+#    #+#             */
/*   Updated: 2024/09/13 16:12:47 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() { return ; }
Contact::~Contact() { return ; }

std::string Contact::getFirstName () const { return (this->_firstName); }
std::string Contact::getLastName () const { return (this->_lastName); }
std::string Contact::getNickName () const { return (this->_nickName); }
std::string Contact::getPhoneNumber () const { return (this->_phoneNumber); }
std::string Contact::getDarkestSecret () const { return (this->_darkestSecret); }

void Contact::setUserData(const std::string& firstName, const std::string& lastName, 
    const std::string& nickName, const std::string& phoneNum, const std::string& darkestSecret) {

  _firstName = firstName;
  _lastName = lastName;
  _nickName = nickName;
  _phoneNumber = phoneNum;
  _darkestSecret = darkestSecret;
}