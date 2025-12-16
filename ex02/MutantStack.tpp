/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:53:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/16 01:58:21 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> & MutantStack<T>::operator = (const MutantStack &other)
{
	if (this != &other)
		this->c = other.c;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::end() const
{
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator	MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator	MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator	MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator	MutantStack<T>::rend() const
{
	return this->c.rend();
}
