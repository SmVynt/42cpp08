/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:53:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/15 17:27:21 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack & operator = (const MutantStack &other);
		~MutantStack();

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
		// Unpacking the underlying container's iterator type, since Stack is just a wrapper

		iterator		begin();
		iterator		end();

		const_iterator	begin() const;
		const_iterator	end() const;

		reverse_iterator	rbegin();
		reverse_iterator	rend();

		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif
