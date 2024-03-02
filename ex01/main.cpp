/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:48:58 by fabou-za          #+#    #+#             */
/*   Updated: 2023/01/02 04:24:29 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>

typedef struct s_data {
	int count;
	int number;
}Data;

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	Data *data = reinterpret_cast<Data*>(raw);
	return (data);
}

int main()
{

	Data data;

	data.count = 100;
	data.number = 8000;

	std::cout << " data.count : " << data.count << std::endl;
	std::cout << " data.number : " << data.number << std::endl;

	uintptr_t raw = serialize(&data);
	Data *returnedData = deserialize(raw);
	std::cout << " data.count : " << returnedData->count << std::endl;
	std::cout << " data.number : " << returnedData->number <<std::endl;

	return (0);
}
