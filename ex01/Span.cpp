/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:23:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/15 15:13:41 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N):_maxSize(N)
{
	_numbers.reserve(N);
};

Span::Span(const Span &other):_maxSize(other._maxSize)
{
	_numbers = other._numbers;
};

Span & Span::operator = (const Span &other)
{
	if (this == &other)
		return *this;
	if (_maxSize != other._maxSize)
		throw DifferentMaxSizeException();
	_numbers = other._numbers;
	_min = other._min;
	_max = other._max;
	return *this;
};

Span::~Span(){};

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	if (_numbers.empty())
	{
		_min = number;
		_max = number;
	}
	else
	{
		if (number < _min)
			_min = number;
		if (number > _max)
			_max = number;
	}
	_numbers.push_back(number);
};
long long	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	long long minSpan = static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]);
	for (size_t i = 2; i < sorted.size(); i++)
	{
		long long span = static_cast<long long>(sorted[i]) - static_cast<long long>(sorted[i - 1]);
		if (span == 0)
			return 0;
		if (span < minSpan)
			minSpan = span;
	}

	return minSpan;
};

long long	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();
	return (static_cast<long long>(_max) - static_cast<long long>(_min));
};


//EXCEPTIONS
const char * Span::SpanFullException::what() const noexcept
{return "Span is already full";};

const char * Span::NotEnoughNumbersException::what() const noexcept
{return "Not enough numbers to find a span";};

const char * Span::DifferentMaxSizeException::what() const noexcept
{return "Cannot assign Span of different max size";};
