#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_begin = this->_target.begin();
    std::map<std::string, ATarget *>::iterator it_end = this->_target.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->_target.clear();
}

TargetGenerator::TargetGenerator(TargetGenerator const &copy)
{
	*this = copy;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &copy)
{
	this->_target = copy._target;
	return(*this);
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
        _target.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
	std::map<std::string, ATarget *>::iterator it = _target.find(type);
	if (it != _target.end())
		delete it->second;
    _target.erase(type);
}

ATarget* TargetGenerator::createTarget(std::string const &type)
{
	std::map<std::string, ATarget *>::iterator it = _target.find(type);
    if (it != _target.end())
        return _target[type];
    return NULL;
}
 /*VER O TARGET GENERATOR*/