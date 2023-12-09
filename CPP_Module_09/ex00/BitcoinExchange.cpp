#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file;
	std::string line;
	file.open("data.csv");
	if(!file.is_open())
		return ;
	else
	{
		getline(file, line);
		while(getline(file, line))
		{
			size_t	pos;
			std::string date;
			pos = line.find(',');
			date = line.substr(0, pos);
			float nbBitcoin;
			std::string value;
			value = line.substr(pos + 1);
			if ((is_float(value) || is_int(value)) && is_dateValid(date))
			{
				nbBitcoin = strtof(value.c_str(), NULL);
				this->setData(date, nbBitcoin);
			}
		}
	}
	file.close();
}

bool	BitcoinExchange::is_int(std::string str)
{
	long nb = strtol(str.c_str(), NULL, 10);
	
	for (int i = 0; i < (int)strlen(str.c_str()); i++) 
	{
		if(!isdigit(str[i]))
		{
			if(i == 0 && (str[0] == '+' || str[0] == '-'))
				continue;
			return false;
		}
	}
	if (nb > INT_MAX || nb < INT_MIN)
	{
		return false;
	}
	return true;
}

bool	BitcoinExchange::is_float(std::string str)
{
	float f = strtof(str.c_str(), NULL);
	bool decimal;

	decimal = 0;
	for (int i = 0; i < (int)strlen(str.c_str()); i++) 
	{
		if (str[i] == '.')
		{
			if (decimal == 0)
				decimal = 1;
			else
				return 0;
		}
		else if (str[i] == 'f')
		{
			if(i == (int)strlen(str.c_str()) - 1)
				break;
			else
				return false;
		}
		else if(!isdigit(str[i]))
		{
			if(i == 0 && (str[0] == '+' || str[0] == '-'))
				continue;
			return false;
		}
	}
	if (f > FLT_MAX || f < FLT_MIN)
	{
		return false;
	}
	return true;
}

bool BitcoinExchange::myIsDigit(std::string str)
{
	for (size_t j = 0; j < str.length(); j++)
	{
		if(!isdigit(str[j]))
			return false;
	}
	return true;
}

bool  BitcoinExchange::is_dateValid(std::string date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5,2);
	std::string day = date.substr(8,2);
	if (!myIsDigit(year) || !myIsDigit(month) || !myIsDigit(day))
		return false;
	int intYear;
	int intMonth;
	int intDay;
	std::stringstream ssYear(year);
    std::stringstream ssMonth(month);
    std::stringstream ssDay(day);

    ssYear >> intYear;
    ssMonth >> intMonth;
    ssDay >> intDay;

	if((intMonth < 1 || intMonth > 12) && (intDay < 1 || intDay > 31) && (intYear < 2009 || intYear > 2022))
		return false;
	if((intMonth == 4 || intMonth == 6 || intMonth == 7 || intMonth == 9 || intMonth == 11) && intDay > 30)
		return false;
	if (intMonth == 2 )
	{
		if (intYear % 400 == 0 || (intYear % 4 == 0 && intYear % 100 != 0))
		{
			if (intDay > 29)
				return false;
		}
		else
		{
			if (intDay > 28)
				return false;
		}
	}
	return true;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
  this->date_nbBitcoin = other.date_nbBitcoin;
}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
  if (this != &src)
	this->date_nbBitcoin=(src.date_nbBitcoin);
  return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

void  BitcoinExchange::setData(std::string date, float nbBitcoin)
{
  this->date_nbBitcoin.insert(std::make_pair(date, nbBitcoin));
}

std::map<std::string, float>  BitcoinExchange::getData()
{
  return(this->date_nbBitcoin);
}
bool is_empty(std::ifstream& pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();
}

void  BitcoinExchange::readInput(std::string pathInput)
{
	std::ifstream	file;
	const char *filename;
	filename = pathInput.c_str();
	file.open(filename);
	if(!file.is_open())
	{
		std::cout << "Can't open the file." << std::endl;
		exit(EXIT_FAILURE) ;
	}
	else if (is_empty(file))
	{
		std::cout << "Empty file." << std::endl;
		exit(EXIT_FAILURE) ;
	}
	else
	{
		std::string line;
		getline(file, line);
		if (line != "date | value")
		{
        	std::cout << "Invalid file format" << std::endl;
        	exit(EXIT_FAILURE);
    	}
		while(getline(file, line))
		{
			size_t	pos;
			std::string date;
			pos = line.find('|');
			date = line.substr(0, pos - 1);
			float nbBitcoin;
			std::string value;
			value = line.substr(pos + 2);
			try
			{
				if (!is_dateValid(date))
					throw std::invalid_argument("Error: bad input => " + date + ".");
				if (!is_float(value) && !is_int(value))
					throw std::invalid_argument("Error: bad input - not a int or float");
				nbBitcoin = strtof(value.c_str(), NULL);
				if ( nbBitcoin > 1000)
					throw std::invalid_argument("Error: bad input - higher than 1000");
				if (nbBitcoin < 0)
					throw std::invalid_argument("Error: bad input - negative value");

				std::map<std::string, float>::iterator it = date_nbBitcoin.find(date);
				std::map<std::string, float>::iterator it_begin = date_nbBitcoin.begin();
				std::string previous;
				if(it == date_nbBitcoin.end())
				{
					while( it_begin->first < date)
					{
						previous = it_begin->first;
						it_begin++;
					}
					std::cout << date << " => " << date_nbBitcoin[previous] << " * " << nbBitcoin << " = " ;
					std::cout << date_nbBitcoin[previous] * nbBitcoin << std::endl;
				}
				else if(it != date_nbBitcoin.end())
				{
					std::cout << date << " => " << it->second << " * " << nbBitcoin << " = " ;
					std::cout << it->second * nbBitcoin << std::endl;
				}
			}
			catch(std::invalid_argument &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		file.close();
	}
}
