/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:23:05 by fabou-za          #+#    #+#             */
/*   Updated: 2023/01/01 21:26:09 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

Cast::Cast(std::string const &arg) : _arg(arg), _print_int(true)
{
	this->getType();
}

Cast::~Cast()
{
}

Cast::Cast(Cast const &ob)
{
	*this = ob;
}

Cast &Cast::operator=(Cast const &ob)
{
	if (this != &ob)
	{
		this->_arg = ob._arg;
		this->_type = ob._type;
		this->_char = ob._char;
		this->_int = ob._int;
		this->_float = ob._float;
		this->_double = ob._double;
		this->_print_int = ob._print_int;
	}
	return (*this);
}

void Cast::getType()
{
	if (!this->argIsInt() && !this->argIsChar() && !this->argIsFloat() && !this->argIsDouble())
	{
		std::cout << "argument type unkown" << std::endl;
		return;
	}
	this->cast();
	this->printAll();
}

bool Cast::argIsChar()
{
	if (_arg.length() != 1)
		return (false);
	this->_type = "char";
	this->_char = _arg[0];
	this->_print_int = true;
	return (true);
}

bool Cast::argIsInt()
{
	size_t end_indx;
	try
	{
		this->_int = stoi(_arg, &end_indx);
		if (end_indx != this->_arg.length())
			return (false);
		this->_type = "int";
		return (true);
	}
	catch (const std::exception &e)
	{
		_print_int = false;
		return (false);
	}
}

bool Cast::argIsFloat()
{
	size_t end_indx;

	try
	{
		this->_float = stof(_arg, &end_indx);
		if (this->_arg != "-inff" && this->_arg != "+inff" && this->_arg != "nanf")
		{
			if (end_indx != this->_arg.length() - 1 || _arg.find('.') == std::string::npos || _arg.c_str()[end_indx] != 'f')
				return (false);
		}
		this->_type = "float";
		return (true);
	}
	catch (const std::exception &e)
	{
		return (false);
	}
}

bool Cast::argIsDouble()
{
	size_t end_indx;
	try
	{
		this->_double = stod(_arg, &end_indx);
		if (this->_arg != "-inf" && this->_arg != "+inf" && this->_arg != "nan")
		{
			if (end_indx != this->_arg.length() || ((_arg.find('.')) == std::string::npos) || _arg.c_str()[end_indx] != '\0')
				return (false);
		}
		this->_type = "double";
		return (true);
	}
	catch (const std::exception &e)
	{
		return (false);
	}
}

void Cast::cast()
{
	if (this->_type == "char")
		castFromChar();
	else if (this->_type == "int")
		castFromInt();
	else if (this->_type == "float")
		castFromFloat();
	else if (this->_type == "double")
		castFromDouble();
}

void Cast::castFromChar()
{
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<double>(this->_char);
}

void Cast::castFromInt()
{
	this->_char = static_cast<char>(this->_int);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
}

void Cast::castFromFloat()
{
	if (_print_int)
	{
		this->_char = static_cast<char>(this->_float);
		this->_int = static_cast<int>(this->_float);
	}
	this->_double = static_cast<double>(this->_float);
}

void Cast::castFromDouble()
{
	if (_print_int)
	{
		this->_char = static_cast<char>(this->_double);
		this->_int = static_cast<int>(this->_double);
	}
	this->_float = static_cast<float>(this->_double);
}

void Cast::printAll() const
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void Cast::printChar() const
{
	if (!_print_int || this->_int < -128 || this->_int > 127)
		std::cout << "char: impossible" << std::endl;
	else if (this->_int > 126 || this->_int < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << _char << "'" << std::endl;
}

void Cast::printInt() const
{
	if (!_print_int)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
}

void Cast::printFloat() const
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << _float << "f" << std::endl;
}

void Cast::printDouble() const
{
	std::cout << "double: " << std::fixed << std::setprecision(1) << _double << std::endl;
}
