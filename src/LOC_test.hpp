#include <string.h>
#include <fstream>

using namespace std;


class LOC_test
{

    public:

    ifstream myfile;

    int check_file_type(string filename);

    void open_file(string filename);

    int get_LOC();
};
