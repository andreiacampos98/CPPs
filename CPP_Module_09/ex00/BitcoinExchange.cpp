#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Constructor BitcoinExchange\n";
  std::ifstream	file;
  std::string line;
  file.open("data.csv");
	if(!file.is_open())
		return ;
  else
  {
    while(getline(file, line))
    {
      size_t  pos;
      std::string date;
      pos = line.find(',');
      date = line.substr(0, pos);
      float nbBitcoin;
      std::string value;
      value = line.substr(pos + 1);
      nbBitcoin = strtof(value.c_str(), NULL);
      this->setData(date, nbBitcoin);
      std::cout << date << nbBitcoin << std::endl;
    }
  }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
  (void)other;
  std::cout << "Copy\n";
}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
  std::cout << "Copy assignment\n";
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
