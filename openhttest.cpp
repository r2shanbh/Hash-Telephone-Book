/*
 * main.cpp
 *
 *  Created on: Oct. 7, 2020
 *      Author: Raksha
 */
#include<iostream>
#include "hashA.h"
#include <string>
#include <map>

/// using maps to use switch case on string and detect user input
// code inspiration from - https://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c4067/Switch-on-Strings-in-C.htm
enum class user_commands {random,n,i,s,d,exit};

std::map <std::string, user_commands> commands_map {{"random",user_commands::random},
													{"n",user_commands::n},
													{"i",user_commands::i},
													{"s",user_commands::s},
													{"d",user_commands::d},
													{"e",user_commands::exit}
												};



int main() {
	std::string cmdline;
	user_commands value;
	HashTable table;

	while (std::getline(std::cin,cmdline)){
		value=commands_map[cmdline.substr(0,1)];

		switch(value) {

			case user_commands::exit :
				if(cmdline.substr(1,3)=="xit"){
					return 0;
				}

				break;

			case user_commands::n :{
				int n_size = std::stoi(cmdline.substr(2));

				table.initialize(n_size);
			}
				break;

			case user_commands::i :{
				int dif=cmdline.find(";")-2;
				long int i_key= std::stoll( cmdline.substr(2,dif) );

				std::string i_caller=cmdline.substr(cmdline.find(";")+1);

				table.insert(i_key, i_caller);
			}
				break;

			case user_commands::s :{
				long int s_key = std::stoll(cmdline.substr(2));

				table.printCaller(s_key);
			}
			    break;

			case user_commands::d :{
				long int d_key = std::stoll(cmdline.substr(2));

				table.deletion(d_key);
			}
				break;

			default :
				break;

		}
	}

	return 0;
}
