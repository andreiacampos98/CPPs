
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <deque>
#include <vector>
/*https://iq.opengenus.org/merge-insertion-sort/*/
/*Binary Search - https://www.youtube.com/watch?v=-OVB5pOZJug*/

class PmergeMe{
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		//PmergeMe &operator=(PmergeMe const &copy);

		bool myIsDigit(std::string str);
		bool verifyArgs(int argc, char **argv);
		void createPairs(std::vector<int> &v, std::vector<std::vector<int> > &vv);
		void mergeSortRecursively(std::vector<std::vector<int> > &vv);
		void merge(std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &right, std::vector<std::vector<int> > &vv);
		void mergeInsertionSort(std::vector<int> &v);
		void generateJacobsthalSequence(std::vector<size_t> &v);
};

#endif
