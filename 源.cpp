#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> SquareNumbers = {0};
vector<int> TriangularNumbers = {0};
void InitializeInputA(vector<int> &A)
{
	cout << "Input A (positive integers):\t(press ctrl+Z to exit)" << endl;
	int a = 0;
	while (cin >> a)
	{
		if (a > 0) { A.push_back(a); }
		else { cerr << "Invalid Input" << endl; exit(1); }
	}
}
int Findmin(vector<int> A)
{
	int M = A[0];
	for (unsigned int i = 1; i < A.size(); i++)
	{
		if (M > A[i])M = A[i];
	}
	return M;
}
int AddtionSquareFactor(vector<int> A, int n)
{
	if (A.size() > 1)
	{
		int last = A.back();
		A.pop_back();
		int sumSquare = 0;
		for (int i = 0; i < ceil(((double)n) / last) + 1 && n >= last * i * i; i++) 
		{
			if (i==0)sumSquare += AddtionSquareFactor(A, n - last * i * i);
			else sumSquare += 2 * AddtionSquareFactor(A, n - last * i * i);
		}
		return sumSquare;
	}
	else
	{
		if (n == 0)return 1;
		else 
		{
			if (n < 0)return 0;
			int p;
			vector<int>::iterator it;
			double quot = ((double)n) / A[0];
			if (quot - floor(quot) != 0)p = 0;
			else
			{
				it = find(SquareNumbers.begin(), SquareNumbers.end(), (int)quot);
				p = (it != SquareNumbers.end() ? 2 : 0);
			}
			return p;
		}
	}
}
int AddtionTriangularFactor(vector<int> A, int n)
{
	if (A.size() > 1)
	{
		int last = A.back();
		A.pop_back();
		int sumTriangular = 0;
		for (int i = 0; i < ceil(((double)n) / last) + 1 && n >= last * i * (i + 1) / 2; i++) 
		{
			sumTriangular += AddtionTriangularFactor(A, n - last * i * (i + 1) / 2);
		}
		return 2 * sumTriangular;
	}
	else
	{
		int p;
		vector<int>::iterator it;
		double quot = ((double)n) / A[0];
		if (quot - floor(quot) != 0) p = 0;
		else
		{
			it = find(TriangularNumbers.begin(), TriangularNumbers.end(), (int)quot);
			p = (it != TriangularNumbers.end() ? 1 : 0);
		}
		return 2 * p;
	}
}
int* FindRepNumber(vector<int> A, int nsq, int ntr)
{
	int min = Findmin(A);
	int maxSquare = ceil(sqrt(nsq / min));
	int maxTriangular = ceil(sqrt((2*(double)(ntr)) / ((double)min) + 0.25) - 0.5);
	for (int i = sqrt(SquareNumbers[SquareNumbers.size() - 1]) + 1; i < maxSquare; i++)
	{
		SquareNumbers.push_back(i * i);
	}
	for (int i = sqrt(2 * ((double)TriangularNumbers[TriangularNumbers.size() - 1]) + 0.25) + 0.5; i < maxTriangular; i++)
	{
		TriangularNumbers.push_back(i * (i + 1) / 2);
	}
	int* reps = new int[2];
	reps[0] = AddtionSquareFactor(A, nsq);
	reps[1] = AddtionTriangularFactor(A, ntr);
	return reps;
}
void Compute(vector<int> A, int module, int residueSquare, int residueTriangular)
{
	
	string outMessageN = "N(";
	string outMessaget = "t(";
	for (unsigned int i = 0; i < A.size(); i++)
	{
		outMessageN += to_string(A[i]);
		outMessaget += to_string(A[i]);
		if (i < A.size() - 1){outMessageN += ", "; outMessaget += ", ";}
		else { outMessageN += "; "; outMessaget += "; "; }
	}//Êä³ö×Ö·û´®´¦Àí

	int* reps;
	for(int isq = residueSquare, itr = residueTriangular,i=0;i<100;i++,isq+=module,itr+=module)
	{
		reps = FindRepNumber(A, isq, itr);
		cout << outMessageN << isq << ")=" << reps[0] << "\t\t\t" << outMessaget << itr << ")=" << reps[1] << endl;
		delete[] reps;
	}
}


int main()
{
	/*
	vector<int> A;
	InitializeInputA(A);
	int module, residueSquare, residueTriangular;
	cin.clear();
	cout << "Input module:" << endl;
	cin >> module;
	cout << "Input residue (for square number):" << endl;
	cin >> residueSquare;
	cout << "Input residue (for triangular number):" << endl;
	cin >> residueTriangular;
	if (0 <= residueSquare && 0 <= residueTriangular && residueSquare < module && residueTriangular < module) {}
	else { cerr << "Invalid Input" << endl; exit(2); }
	Compute(A, module, residueSquare, residueTriangular);
	*/
	vector<int> A = { 1,3,24,28 };
	Compute(A, 8, 7, 0);
	
}