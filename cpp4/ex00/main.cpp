/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:37:03 by aperez-b          #+#    #+#             */
/*   Updated: 2023/10/18 17:34:13 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "DogCat.hpp"
#include "Wrong.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog("Carnivore");
	const Animal		*i = new Cat();
	const WrongAnimal	*k = new WrongCat();
	const WrongAnimal	*h = new WrongAnimal();

	i->makeSound();
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	h->makeSound();
	delete meta;
	delete i;
	delete j;
	delete k;
}
