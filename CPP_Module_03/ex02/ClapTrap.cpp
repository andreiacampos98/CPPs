#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default")
{
    this->_hit_points = 10;
    this->_energy_points = 10;
    this->_attack_damage = 0;
    std::cout << "ClapTrap created" <<std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name)
{
    this->_hit_points = 10;
    this->_energy_points = 10;
    this->_attack_damage = 0;
    std::cout << "ClapTrap created named " << this->_name <<std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "Copy constructor called" << std::endl;
	setName(copy._name);
    setAttackDamage(copy._attack_damage);
    setEnergyPoints(copy._energy_points);
    setHitPoint(copy._hit_points);
}

ClapTrap &ClapTrap::operator = (const ClapTrap &src)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    this->_hit_points = src.getHitPoint();
    this->_energy_points = src.getEnergyPoints();
    this->_attack_damage = src.getAttackDamage();
    this->_name=src.getName();
	return(*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " destroyed." <<std::endl;
}

std::string ClapTrap::getName(void) const
{
    return(this->_name);
}

int ClapTrap::getHitPoint(void) const
{
    return(this->_hit_points);
}

int ClapTrap::getEnergyPoints(void) const
{
    return(this->_energy_points);
}

int ClapTrap::getAttackDamage(void) const
{
    return(this->_attack_damage);
}

void ClapTrap::setName(const std::string name)
{
    this->_name=name;
}

void ClapTrap::setHitPoint(const int value)
{
    this->_hit_points=value;
}

void ClapTrap::setEnergyPoints(const int value)
{
    this->_energy_points=value;
}

void ClapTrap::setAttackDamage(const int value)
{
    this->_attack_damage=value;
}

void ClapTrap::attack(const std::string& target)
{
    if( this->_hit_points > 0 && this->_energy_points > 0)
    {
        std::cout << "ClapTrap " << this->_name <<" attacks " << target << ", causing ";
        std::cout << this->_hit_points << " points of damage!" <<std::endl;
        this->_energy_points--;
    }
    if( this->_energy_points <= 0 && this->_hit_points > 0 )
    {
        std::cout << "ClapTrap " << this->_name <<" can't atack without energy points." << std::endl;
    }
    if (this->_hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name <<" is dead."<<std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if( this->_hit_points > 0)
    {
        std::cout << "ClapTrap " << this->_name << " was damaged for ";
        std::cout << amount << " hitpoints!" << std::endl;
        this->_hit_points = this->_hit_points - amount;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " is dead."<<std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if( this->_energy_points <= 0 && this->_hit_points > 0)
    {
        std::cout << "ClapTrap " << this->_name <<" can't repair without energy points." <<std::endl;
    }
    if( this->_energy_points > 0 && this->_hit_points > 0)
    {
        this->_energy_points--;
        this->_hit_points = this->_hit_points + amount;
        std::cout << "ClapTrap " << this->_name << " repaired ";
        std::cout << amount << " points of damage." << std::endl;
    }
    if (this->_hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name <<" is dead." <<std::endl;
    }
}
