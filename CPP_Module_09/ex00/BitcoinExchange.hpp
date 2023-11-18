
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h> 
#include <string>

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
};


#endif
