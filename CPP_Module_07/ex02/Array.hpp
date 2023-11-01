/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:59:02 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/01 12:01:59 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
class Array
{
	private:
		T*				_arr;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int size);
		Array(Array const &src);
		Array &operator=(Array const &src);
		~Array();

		T& operator[]( unsigned int i ) const;
		unsigned int	size();
	
	class HigherThanSize: public std::exception
	{
		virtual const char* what() const throw()
		{
			return "The index value doesn't belong to the range.";
		}
	};
};

template<typename T>
Array<T>::Array(): _arr(new T[0]), _size(0)
{
	std::cout << "Array constructor called." << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n):_arr(new T[n]), _size(n)
{
	if (n < 0)
		throw Array<T>::HigherThanSize();
	std::cout << "Array constructor called with size defined equal to " << n << "." << std::endl;
}

template<typename T>
Array<T>::Array(Array<T> const &src): _arr(new T[src._size]), _size(src._size)
{
	for (unsigned int i=0; i < src._size; i++)
	{
		_arr[i] = src._arr[i];
	}
	std::cout << "Default copy called." << std::endl;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &src)
{
	if (this != &src)
	{
		delete [] _arr;
		_arr = new T[src._size];
		_size = src._size;
		for (unsigned int i=0; i < src._size; i++)
		{
			_arr[i] = src._arr[i];
		}
		
	}
	std::cout << "Copy Array operator overload." << std::endl;
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array destroyed." << std::endl;
	delete [] _arr;
}

template<typename T>
T& Array<T>::operator[]( unsigned int i ) const
{
	if (i >= _size)
		throw Array<T>::HigherThanSize();
	return(_arr[i]);
}

template<typename T>
unsigned int	Array<T>::size()
{
	return (_size);
}
