/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:23:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/15 15:38:20 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits.h>

class Span
{
	private:
		std::vector<int>	_numbers;
		const unsigned int	_maxSize;
		int					_min;
		int					_max;

	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span & operator = (const Span &other);
		~Span();

		class SpanFullException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		class DifferentMaxSizeException : public std::exception {
			public:
				const char* what() const noexcept;
		};

		void		addNumber(int number);
		long long	shortestSpan() const;
		long long	longestSpan() const;

		template <typename Iterator>
		void		addRange(Iterator begin, Iterator end)
		{
			size_t rangeSize = std::distance(begin, end);

			if (_numbers.size() + rangeSize > _maxSize)
				throw SpanFullException();

			for (Iterator it = begin; it != end; ++it)
			{
				if (_numbers.empty())
				{
					_min = *it;
					_max = *it;
				}
				else
				{
					if (*it < _min)
						_min = *it;
					if (*it > _max)
						_max = *it;
				}
				_numbers.push_back(*it);
			}
		}
};

#endif
