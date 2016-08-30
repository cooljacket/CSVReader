#include <iostream>

#include "CSVReader.h"
#include "CSVContainerAdapter.h"
#include "CSVVectorContainer.h"
#include "CSVMapContainer.h"

using namespace std;

void display_v(const vector<vector<string> >& data) {
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 0; j < data[i].size(); ++j)
			cout << data[i][j] << '\t';
		cout << endl;
	}
}

void display_m(const map<string, vector<string> >& data) {
	map<string, vector<string> >::const_iterator it = data.begin();
	while (it != data.end()) {
		const vector<string>& row = it->second;
		for (int i = 0; i < row.size(); ++i)
			cout << row[i] << '\t';
		cout << endl;
		++it;
	}
}


int main() {
	/*
	// 1. 第一种示例使用方式
	CSVContainerAdapter* adapter_vec = new CSVVectorContainer();
	CSVReader::read("data_examples/input1.csv", adapter_vec);
	adapter_vec->display();

	cout << endl;

	CSVContainerAdapter* adapter_map = new CSVMapContainer();
	CSVReader::read("data_examples/input2.csv", adapter_map);
	adapter_map->display();*/


	// 2. 第二种示例使用方式，获取整张表的数据
	CSVVectorContainer vec;
	CSVReader::read("data_examples/input1.csv", &vec);
	// vec.display();
	vector<vector<string> >& data = vec.getData();
	display_v(data);

	vector<string> col2;
	vec.getColData(col2, 2);
	cout << col2.size() << ' ' << data.size() << endl;

	cout << endl;


	CSVMapContainer m;
	CSVReader::read("data_examples/input2.csv", &m);
	map<string, vector<string> >& data2 = m.getData();
	m.display();

	return 0;
}
