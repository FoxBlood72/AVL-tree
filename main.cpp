#include <iostream>
#include <fstream>
#include <chrono>
#include <string.h>
#include "AVLTree.hpp"
#include "TreeNode.hpp"

using namespace std;


void deleteTimeTest(AVLTree &tr, ofstream &g, int *result, int k)
{
//	int *copyElem = new int[tr.cardinal()];
//	for(int i = 1; i < tr.cardinal(); i++)
//		copyElem[i-1] = tr.k_element(i);
		
	auto start = chrono::steady_clock::now();
	for(int i = 0; i < tr.cardinal(); i++)
		tr.sterge(result[i]);
		
	auto end = chrono::steady_clock::now();
	cout<<"Timpul stergerii tuturor elementelor din structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;
		
//	delete []copyElem;
}

void maxTimeTest(AVLTree &tr, ofstream &g, int *result, int k)
{
	auto start = chrono::steady_clock::now();
	int max = tr.max();
	g<<"Elementul maxim este: "<<max<<endl;
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasit maximul din strucutra: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;
	if(result[k-1] != max)
		cout<<"EROARE IN GASIREA MINIMULUI: "<<result[k-1]<<endl;
}

void minTimeTest(AVLTree &tr, ofstream &g, int *result, int k)
{
	auto start = chrono::steady_clock::now();
	int min = tr.min();
	g<<"Elementul minim este: "<<min<<endl;
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasit minimul din strucutra: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;
	if(result[0] != min)
		cout<<"EROARE IN GASIREA MINIMULUI: "<<result[0]<<endl;
}

void k_elementTimeTest(AVLTree &tr, ofstream &g, int *result, int k)
{
	auto start = chrono::steady_clock::now();
	for(int i = 1; i <= tr.cardinal(); i++)
	{
		int k_elem = tr.k_element(i);
		g<<"Al "<<i<<" element este: "<<tr.k_element(i)<<endl;
		if(k_elem != result[i-1])
			cout<<"EROARE IN K_ELEMENT PENTRU ELEMENTUL "<<k_elem<<endl;
	}
		
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasi toate k_element() din structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

}

void succesorTimeTest(AVLTree &tr, ofstream &g, int *result, int k)
{
//	int *copyElem = new int[tr.cardinal()];
//	for(int i = 1; i < tr.cardinal(); i++)
//		copyElem[i-1] = tr.k_element(i);
	
	
	auto start = chrono::steady_clock::now();
	
	for(int i = 1; i < tr.cardinal(); i++)
	{
		int x = result[i-1];
		int mySuccess = tr.succesor(x);
		g<<"Succesorul elementului "<<x<<" este "<<mySuccess<<endl;
		if(mySuccess != result[i])
			cout<<"EROARE GASITA IN SUCCESOR ELEMENT: "<<x<<endl;
	}
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasi toate succesoarele din structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

	
//	delete []copyElem;
}

void predecesorTimeTest(AVLTree &tr, ofstream &g, int *result, int k)
{
//	int *copyElem = new int[tr.cardinal()];
//	for(int i = 2; i <= tr.cardinal(); i++)
//		copyElem[i-2] = tr.k_element(i);
	
	
	auto start = chrono::steady_clock::now();
	for(int i = 2; i <= tr.cardinal(); i++)
	{
		int x = result[i-1];
		int myPredecessor = tr.predecesor(x);
		g<<"Predecesorul elementului "<<x<<" este "<<myPredecessor<<endl;
		if(myPredecessor != result[i-2])
			cout<<"EROARE GASITA IN PREDECESOR ELEMENT: "<<x<<endl;
	}
	
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasi toate predecesoarele din structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

	
//	delete []copyElem;
}

int main(int argc, char *argv[]) {
	
	if(argc < 2)
	{
		cout<<"Va rugam sa dati cel putin un fisier de intrare"<<endl;
		return 1;
	}
	
	if((argc - 1) % 2 != 0)
	{
		cout<<"Va rugam sa introduceti un fisier de rezultate pentru toate fisierele"<<endl;
		return 1;
	}
	
	AVLTree *trees = new AVLTree[(argc-1) / 2]; // structura de date
	
	ifstream f;
	for(int i = 1; i < argc; i += 2)
	{
		f.open(argv[i]);
		int x;
		auto start = chrono::steady_clock::now();
		while(f>>x)
			trees[(i-1) / 2].insert(x);
		
		auto end = chrono::steady_clock::now();
		cout<<"Timpul pentru a insera toate elementele in structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

		f.close();
		
	}
	
	
	for(int i = 0; i < (argc-1) / 2; i++)
	{
		string outputFile = "testOut";
		outputFile += to_string(i);
		outputFile += ".out";
		
		string resultf = "result";
		resultf += to_string(i+1);
		resultf += ".txt";
		
		ofstream g(outputFile);
		
		
		ifstream resultFile(argv[i*2 + 2]);
		int *orderedElements = new int[400000];
		int k_result = 0;
		int resx;
		while(resultFile>>resx)
		{
			orderedElements[k_result] = resx;
			k_result++;
		}
		cout<<"Se testeaza fisierul numarul "<<i+1<<endl;
		
		
		
		succesorTimeTest(trees[i], g, orderedElements, k_result);
		
		predecesorTimeTest(trees[i], g, orderedElements, k_result);
		
//		k_elementTimeTest(trees[i], g, orderedElements, k_result);
		
		minTimeTest(trees[i], g, orderedElements, k_result);
		
		maxTimeTest(trees[i], g, orderedElements, k_result);
		
		deleteTimeTest(trees[i], g, orderedElements, k_result);
		
		delete []orderedElements;
	}	
	
	
	
	
//	tr.printInorder(tr.root);

    return 0;
}