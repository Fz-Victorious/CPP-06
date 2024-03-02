/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:24:34 by fabou-za          #+#    #+#             */
/*   Updated: 2023/01/02 04:53:30 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

int	main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		Cast num(argv[1]);
    }
	else
		std::cout << "you've entered too many args or less args" << std::endl;
	return (0);
}
