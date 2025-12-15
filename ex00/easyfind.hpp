/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:34:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/15 13:56:51 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::iterator easyfind (T &container, int value)
{
	typename T::iterator a =  std::find(container.begin(), container.end(), value);
	if (a != container.end())
		return (a);
	throw std::runtime_error("Value not found in container");
}

#endif
