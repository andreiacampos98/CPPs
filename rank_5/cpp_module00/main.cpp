/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 08:31:23 by anaraujo          #+#    #+#             */
/*   Updated: 2023/12/02 08:49:24 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

int main()
{
	//Warlock bob;                            //Does not compile
	//Warlock bob("Bob", "the magnificent");  //Compiles
	//Warlock jim("Jim", "the nauseating");   //Compiles
	//bob = jim;                              //Does not compile
	//Warlock jack(jim);                      //Does not compile
	Warlock const richard("Richard", "Mistress of Magma");
  	richard.introduce();
	std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

	Warlock* jack = new Warlock("Jack", "the Long");
	jack->introduce();
	jack->setTitle("the Mighty");
	jack->introduce();

	delete jack;

	return (0);
}
