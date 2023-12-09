#pragma once
#include <iostream>
#include <map>

class ATarget;

class TargetGenerator
{
	private:
		TargetGenerator(TargetGenerator const &copy);
		TargetGenerator &operator=(TargetGenerator const &copy);
		std::map < std::string, ATarget*> _target;
	public:
		TargetGenerator();
		~TargetGenerator();

		void learnTargetType(ATarget *target);
		void forgetTargetType(std::string const &type);
		ATarget* createTarget(std::string const &type);
};

#include "ATarget.hpp"
