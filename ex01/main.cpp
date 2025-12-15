/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:47:57 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/15 15:17:50 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#define VEC_SIZE 30000

int main()
{
	srand(time(NULL));
	Span sp(VEC_SIZE);

	std::cout << "Checking empty Span" << std::endl;
	try	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "...................." << std::endl;

	std::cout << "Adding numbers + 1 extra" << std::endl;
	for (int i = 0; i < VEC_SIZE; i++)
		sp.addNumber(rand() * (rand() % 2 ? 1 : -1));
	std::cout << "Added " << VEC_SIZE << " numbers." << std::endl;
	try	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "...................." << std::endl;

	std::cout << "Checking Span" << std::endl;
	try	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}

	return 0;

	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	// return 0;
}
