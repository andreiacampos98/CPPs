
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
		std::vector<int> _vector;
        std::deque<int>   _deque;

		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(PmergeMe const &copy);
		PmergeMe &operator=(PmergeMe const &copy);

		bool myIsDigit(std::string str);
		bool verifyArgs(int argc, char **argv);

		/*Vector*/
		void createPairs(std::vector<int> &v, std::vector<std::vector<int> > &vv);
		void mergeSortRecursively(std::vector<std::vector<int> > &vv);
		void merge(std::vector<std::vector<int> > &left, std::vector<std::vector<int> > &right, std::vector<std::vector<int> > &vv);
		void mergeInsertionSort(std::vector<int> &v);
		void insertationSort(std::vector<int> &S, size_t n, std::vector<std::vector<int> > &vv);

		/*deque*/
		void lcreatePairs(std::deque<int> &v, std::deque<std::deque<int> > &vv);
		void lmergeSortRecursively(std::deque<std::deque<int> > &vv);
		void lmerge(std::deque<std::deque<int> > &left, std::deque<std::deque<int> > &right, std::deque<std::deque<int> > &vv);
		void lmergeInsertionSort(std::deque<int> &v);
		void linsertationSort(std::deque<int> &S, size_t n, std::deque<std::deque<int> > &vv);
};

#endif
