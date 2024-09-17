/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:52 by adrian            #+#    #+#             */
/*   Updated: 2024/09/13 16:13:58 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _darkestSecret;
    std::string _phoneNumber;
    
public:
    Contact();
    ~Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getDarkestSecret() const;
    std::string getPhoneNumber() const;

    void setUserData(const std::string& firstName, const std::string& lastName, 
        const std::string& nickName, const std::string& phoneNum, const std::string& darkestSecret);
};

# endif