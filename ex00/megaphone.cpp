/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:34:04 by aduenas-          #+#    #+#             */
/*   Updated: 2024/09/29 18:25:11 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

void strToUpper(string str)
{    
    for(int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
    cout << str << " ";
}

int main(int argc, char **argv)
{
    string str;
    if (argc < 2)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
    {
        str = argv[i];
        strToUpper(str);
    }
    cout << endl;
    return (0);
}

