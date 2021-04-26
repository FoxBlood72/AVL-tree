#include <iostream>
#include <fstream>
#include <chrono>
#include <string.h>
#include "AVLTree.hpp"
#include "TreeNode.hpp"

using namespace std;


void deleteTimeTest(AVLTree &tr, ofstream &g)
{
	int *copyElem = new int[tr.cardinal()];
	for(int i = 1; i < tr.cardinal(); i++)
		copyElem[i-1] = tr.k_element(i);
		
	auto start = chrono::steady_clock::now();
	for(int i = 0; i < tr.cardinal(); i++)
		tr.sterge(copyElem[i]);
		
	auto end = chrono::steady_clock::now();
	cout<<"Timpul stergerii tuturor elementelor din structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;
		
	delete []copyElem;
}

void maxTimeTest(AVLTree &tr, ofstream &g)
{
	auto start = chrono::steady_clock::now();
	g<<"Elementul maxim este: "<<tr.max()<<endl;
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasit maximul din strucutra: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;
}

void minTimeTest(AVLTree &tr, ofstream &g)
{
	auto start = chrono::steady_clock::now();
	g<<"Elementul minim este: "<<tr.min()<<endl;
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasit minimul din strucutra: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

}

void k_elementTimeTest(AVLTree &tr, ofstream &g)
{
	auto start = chrono::steady_clock::now();
	for(int i = 1; i <= tr.cardinal(); i++)
		g<<"Al "<<i<<" element este: "<<tr.k_element(i)<<endl;
		
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasi toate k_element() din structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

}

void succesorTimeTest(AVLTree &tr, ofstream &g)
{
	int *copyElem = new int[tr.cardinal()];
	for(int i = 1; i < tr.cardinal(); i++)
		copyElem[i-1] = tr.k_element(i);
	
	
	auto start = chrono::steady_clock::now();
	for(int i = 1; i < tr.cardinal(); i++)
	{
		int x = copyElem[i-1];
		g<<"Succesorul elementului "<<x<<" este "<<tr.succesor(x)<<endl;
	}
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasi toate succesoarele din structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

	
	delete []copyElem;
}

void predecesorTimeTest(AVLTree &tr, ofstream &g)
{
	int *copyElem = new int[tr.cardinal()];
	for(int i = 2; i < tr.cardinal(); i++)
		copyElem[i-2] = tr.k_element(i);
	
	
	auto start = chrono::steady_clock::now();
	for(int i = 2; i <= tr.cardinal(); i++)
	{
		int x = copyElem[i-2];
		g<<"Predecesorul elementului "<<x<<" este "<<tr.predecesor(x)<<endl;
	}
	
	auto end = chrono::steady_clock::now();
	cout<<"Timpul pentru a gasi toate predecesoarele din structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

	
	delete []copyElem;
}

int main(int argc, char *argv[]) {
	
	if(argc < 2)
	{
		cout<<"Va rugam sa dati cel putin un fisier de intrare"<<endl;
		return 1;
	}
	
	AVLTree *trees = new AVLTree[argc-1];
	
	ifstream f;
	for(int i = 1; i < argc; i++)
	{
		f.open(argv[i]);
		int x;
		auto start = chrono::steady_clock::now();
		while(f>>x)
			trees[i-1].insert(x);
		
		auto end = chrono::steady_clock::now();
		cout<<"Timpul pentru a insera toate elementele in structura: "<<chrono::duration <double, milli> (end - start).count() <<" ms"<<endl;

		f.close();
		
	}
	
	
	for(int i = 0; i < argc-1; i++)
	{
		string outputFile = "testOut";
		outputFile += to_string(i);
		outputFile += ".out";
		ofstream g(outputFile);
		cout<<"Se testeaza "<<i+1<<" fisier"<<endl;
		
		
		succesorTimeTest(trees[i], g);
		
		predecesorTimeTest(trees[i], g);
		
		k_elementTimeTest(trees[i], g);
		
		minTimeTest(trees[i], g);
		
		maxTimeTest(trees[i], g);
		
		deleteTimeTest(trees[i], g);
	}	
	
	
	
	
//	tr.printInorder(tr.root);

    return 0;
}