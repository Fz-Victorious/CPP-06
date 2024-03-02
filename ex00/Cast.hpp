/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cast.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:23:54 by fabou-za          #+#    #+#             */
/*   Updated: 2023/01/02 05:15:17 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAST_HPP
#define CAST_HPP
#include <iostream>
#include <limits>
#include <iomanip>

class Cast
{
	private:
		std::string _arg;
		std::string _type;
		char _char;
		int _int;
		float _float;
		double _double;
		bool _print_int;

		void getType();
		bool argIsInt();
		bool argIsFloat();
		bool argIsDouble();
		bool argIsChar();

		void cast();
		void castFromChar();
		void castFromInt();
		void castFromFloat();
		void castFromDouble();

		void printAll() const;
		void printChar() const ;
		void printInt() const ;
		void printFloat() const ;
		void printDouble() const ;

		Cast();

	public:
		Cast(std::string const &arg);
		Cast(Cast const &obj);
		Cast &operator=(Cast const &obj);
		~Cast();
};

#endif
