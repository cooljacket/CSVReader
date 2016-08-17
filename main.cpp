#include <iostream>

#include "CSVReader.h"
#include "CSVContainerAdapter.h"
#include "CSVVectorContainer.h"
#include "CSVMapContainer.h"

using namespace std;


int main() {
	CSVContainerAdapter* adapter_vec = new CSVVectorContainer();
	CSVReader::read("data_examples/input1.csv", adapter_vec);
	adapter_vec->display();

	cout << endl;

	CSVContainerAdapter* adapter_map = new CSVMapContainer();
	CSVReader::read("data_examples/input2.csv", adapter_map);
	adapter_map->display();

	return 0;
}