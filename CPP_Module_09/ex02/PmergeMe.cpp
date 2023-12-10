#include "PmergeMe.hpp"

template<class T>
void	print(T &typeContainer)
{
	typename T::iterator it;
	for(it = typeContainer.begin(); it != typeContainer.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::vector<int>	v;
	std::deque<int>		d;

	if(this->verifyArgs(argc, argv))
	{
		for (int i=1; i < argc ; i++)
		{
			v.push_back(atoi(argv[i]));
			d.push_back(atoi(argv[i]));
		}

		std::cout << "Before: ";
		print(v);
		print(d);

		std::cout << "After: ";
		print(v);
		print(d);
		std::cout << "Time to proccess a range of " << " elements with std::[...] : " << "us" << std::endl;
		std::cout << "Time to proccess a range of " << " elements with std::[...] : " << "us" << std::endl;
	}
	else
	{
		std::cout << "Inputs invalid. Should be a positive integer and can't repeat the same value.\n";
	}
}

PmergeMe::~PmergeMe(){}
//PmergeMe::PmergeMe(PmergeMe const &copy){}
//PmergeMe &PmergeMe::operator=(PmergeMe const &copy){}

bool PmergeMe::myIsDigit(std::string str)
{
	for (size_t j = 0; j < str.length(); j++)
	{
		if(!isdigit(str[j]))
			return false;
	}
	return true;
}

bool PmergeMe::verifyArgs(int argc, char **argv)
{
	for (int i=1; i < argc ; i++)
	{
		if (!myIsDigit(argv[i]))
			return false;
		if (atoi(argv[i]) < 0)
			return false;
	}
	for (int k = 1; k < argc ; k++)
	{
		int j = k + 1;
		while(j < argc)
		{
			if (atoi(argv[k]) == atoi(argv[j]))
				return false;
			j++;
		}
	}
	return true;
}

/*The Ford-Johnson merge-insertion sort is a three-step algorithm, let n be the number of elements to sort:

    1. Split the collection in n/2 pairs of 2 elements and order these elements pairwise. 
	If the number of elements is odd, the last element of the collection isn't paired with any element.
	https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/
	
	2. Recursively sort the pairs of elements by their highest value. 
	If the number of elements is odd, the last element is not considered a highest value and is left at the end of the collection. 
	Consider that the highest values form a sorted list that we will call the main chain while the rest of the elements 
	will be known as pend elements. Tag the elements of the main chain with the names a1,a2,a3,...,an/2 
	then tag the pend elements with the names b1,b2,b3,...,bn/2. For every k, we have the relation bk≤ak.
	
	3. Insert the pend elements into the main chain. We know that the first pend element b1 is lesser than a1; 
	we consider it to be part of the main chain which then becomes {b1,a1,a2,a3,...,an/2}. 
	Now, we need to insert the other pend elements into the main chain in a way that ensures that the size of the insertion 
	area is a power of 2 minus 1 as often as possible. 
	Basically, we will insert b3 in {b1,a1,a2} (we know that it is less than a3), then we will insert b2 into {b1,a1,b3} 
	no matter where b3 was inserted. Note that during these insertions, the size of the insertion area is always at most 3.
	
	The value of the next pend element bk to insert into the main chain while minimizing the number of 
	comparisons actually corresponds to the next Jacobsthal number. We inserted the element 3 first, 
	so the next will be 5 then 11 then 21, etc...
	
	To sum up, the insertion order of the first pend elements into the main chain is as follows: 
	b1,b3,b2,b5,b4,b11,b10,b9,b8,b7,b6,....*/

void PmergeMe::generateJacobsthalSequence(std::vector<size_t> &v)
{
	for (size_t i = 0; i < v.size(); i++)
		v[i] = (pow(2, i + 2) - pow(-1, i + 2)) / 3;
}

void	PmergeMe::createPairs(std::vector<int> &v, std::vector<std::vector<int> > &vv)
{
	size_t	nbVector = v.size() / 2.0;

	vv.resize(nbVector);
	vv.assign(nbVector, std::vector<int>(2));
	for (size_t i = 0 ; i < nbVector; i++)
	{
		if (( 2 * i + 1) == nbVector)
		{
			vv[i][0] = -1;
			vv[i][1] = v[2*i];
		}
		else{
			vv[i][0] = std::min(v[2 * i], v[2*i + 1]);
			vv[i][1] = std::max(v[2 * i], v[2*i + 1]);
		}
	}
}

void	PmergeMe::mergeInsertionSort(std::vector<int> &v)
{
	std::vector<std::vector<int> > vv;
	createPairs(v, vv);
}

/*public static final int K = 5;
public static void insertionSort(int A[], int p, int q) {
    for (int i = p; i < q; i++) {
        int tempVal = A[i + 1];
        int j = i + 1;
        while (j > p && A[j - 1] > tempVal) {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = tempVal;
    }
    int[] temp = Arrays.copyOfRange(A, p, q +1);
    Arrays.stream(temp).forEach(i -> System.out.print(i + " "));
    System.out.println();
}

public static void merge(int A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int[] LA = Arrays.copyOfRange(A, p, q +1);
    int[] RA = Arrays.copyOfRange(A, q+1, r +1);
    int RIDX = 0;
    int LIDX = 0;
    for (int i = p; i < r - p + 1; i++) {
        if (RIDX == n2) {
            A[i] = LA[LIDX];
            LIDX++;
        } else if (LIDX == n1) {
            A[i] = RA[RIDX];
            RIDX++;
        } else if (RA[RIDX] > LA[LIDX]) {
            A[i] = LA[LIDX];
            LIDX++;
        } else {
            A[i] = RA[RIDX];
            RIDX++;
        }
    }
}

public static void sort(int A[], int p, int r) {
    if (r - p > K) {
        int q = (p + r) / 2;
        sort(A, p, q);
        sort(A, q + 1, r);
        merge(A, p, q, r);
    } else {
        insertionSort(A, p, r);
    }
}*/
