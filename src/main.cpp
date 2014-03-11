#include <string.h>
#include <fstream>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

#include "LOC_test.hpp"

using namespace std;

int main()
{
    LOC_test lt;
    lt.open_file("test-LOC.cpp");
    cout << "Total lines of code is " << lt.get_LOC();
    //lt.check_file_type("fs.cpplo");
	return 0;
}

