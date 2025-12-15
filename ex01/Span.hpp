/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:23:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/15 15:13:16 by psmolin          ###   ########.fr       */
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
};

#endif
