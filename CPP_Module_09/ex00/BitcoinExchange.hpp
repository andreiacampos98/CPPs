
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>
#include <stdlib.h>
#include <filesystem>
#include <exception>

class BitcoinExchange
{
  private:
    std::map <std::string, float> date_nbBitcoin;
  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange &src);
    void  setData(std::string date, float nbBitcoin);
    std::map<std::string, float>  getData();

    bool	is_int(std::string str);
    bool	is_float(std::string str);
    bool  is_dateValid(std::string date);
    bool  myIsDigit(std::string str);
    void  readInput(std::string pathInput);

};


#endif
