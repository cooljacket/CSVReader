#include "CSVVectorContainer.h"
#include <iostream>
using namespace std;


void CSVVectorContainer::addToRow(const string& cell) {
	m_row.push_back(cell);
}


void CSVVectorContainer::addToRowDone() {
	m_table.push_back(m_row);
	m_row.clear();
}


void CSVVectorContainer::display() const {
	for (int i = 0; i < m_table.size(); ++i) {
		for (int j = 0; j < m_table[i].size(); ++j)
			cout << m_table[i][j] << '\t';
		cout << endl;
	}
}