MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	*this=copy;
}
MateriaSource const &MateriaSource::operator=(MateriaSource const &copy)
{
	std::cout << "MateriaSource copy assignment constructor" << std::endl;
	(void) copy;
	return (*this);
}

~MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource destroyed" << std::endl;
}
