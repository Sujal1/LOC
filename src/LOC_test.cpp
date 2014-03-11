/*******************************************************************************************************/
/* Program Assignment   :   2                                                                         */
/* Name                 :   Sujal Manandhar                                                          */
/* Date                 :   January 27, 2014                                                        */
/* Description:         :   counts the number of lines in a code and the lines in individual parts */
/**************************************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

#include "LOC_test.hpp"
//#define BOOST_TEST_MODULE MyTest
//#include <boost/test/minimal.hpp>

using namespace std;


/************************************************/
// This is the beginning of the main function **/
/**********************************************/




   //LOC_test::ifstream myfile;

    int LOC_test::check_file_type(string filename)
    {
        int index = filename.find(".");
        cout << index << endl;
        string extension = filename.substr(index+1, 3);
        if (extension != "cpp" || extension != "hpp")
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void LOC_test::open_file(string filename)
    {

        if (check_file_type(filename) == 1)
        {
            myfile.open(filename.c_str());

            if (!myfile)
            {
                cout << "ERROR READING FILE";
                exit(EXIT_SUCCESS);
            }
        }
        else
        {
            cout << "The file is not a cpp or hpp file" << endl;
            exit(EXIT_SUCCESS);
        }
    }

    int LOC_test::get_LOC()
    {
        vector<string> part_name;
        vector<int> part_length;
        vector<int> part_number;

        string current_line, previous_line;
        int braces_count = 0, number_of_lines = 0, total_number_of_lines = 0, line_length = 0;
        bool comment_section = false, declaration_section = true;

        string filename = "test-LOC.cpp";
      //  ifstream myfile;// = openfile (filename);

        while (getline(myfile, current_line))
        {
            current_line = current_line.substr(0, current_line.length()-1);  //removing addditional character at the end that comes with getline
            line_length = current_line.length();
            current_line.erase(remove(current_line.begin(), current_line.end(), '\t'), current_line.end());
            cout << current_line << endl;

            if (current_line == "" || current_line == " " || current_line.substr (0,2) == "//" || current_line.substr (0,8) == "#include" || current_line == "public:" || current_line == "private:" || current_line == "protected:")
            {
                continue;
            }

            else if (line_length > 1 && current_line.substr (0,2) == "/*")
            {
                if (current_line.substr(line_length-2, 2) == "*/")
                {
                   continue;
                }
                comment_section = true;
                continue;
            }

            else if (comment_section == true && line_length > 1 && current_line.substr(line_length-2, 2) == "*/")
            {
                comment_section = false;
                continue;
            }

            if (current_line == "{")
            {
                if (declaration_section)
                {
                    if (number_of_lines > 1)
                    {
                        number_of_lines = number_of_lines - 1;
                        part_name.push_back("Global Declaration Part");
                        part_length.push_back(number_of_lines);
                    }
                    declaration_section = false;
                }
                if (braces_count == 0)
                {
                    part_name.push_back(previous_line);
                    number_of_lines = 1;
                }
                braces_count++;
                continue;
            }

            if (current_line == "}" || current_line == "};")
            {
                braces_count --;

                if (braces_count == 0)
                {
                    part_length.push_back(number_of_lines);
                    number_of_lines = 0;
                }
                continue;
            }

            if (comment_section == false)
            {
                number_of_lines++;
            }

            previous_line = current_line;
     }

        if (part_name.size() == 0)
        {
            part_name.push_back("Declaration Part");
            part_length.push_back(number_of_lines);
        }

        for (int i = 0; i < part_name.size(); i++) {
            cout << part_name.at(i)<< " has " << part_length.at(i) << " lines." << endl << endl;
            total_number_of_lines += part_length.at(i);
        }

       // cout << "Total number of lines is " << total_number_of_lines << endl;
        return total_number_of_lines;
    }
//int test_main( int, char *[] )             // note the name!
//{
//    // six ways to detect and report the same error:
////    BOOST_CHECK( add( 2,2 ) == 4 );        // #1 continues on error
//    BOOST_CHECK(loc_test.get_LOC() == 7 );
//    return 0;
//
////    cout << "Continued" << endl;
////    BOOST_REQUIRE( add( 2,2 ) ==  4);      // #2 throws on error
////    cout << "Again Continued" << endl;
////    if( add( 2,2 ) != 4 )
////        BOOST_ERROR( "Ouch..." );          // #3 continues on error
////    if( add( 2,2 ) != 4 )
////        BOOST_FAIL( "Ouch..." );           // #4 throws on error
////    if( add( 2,2 ) != 4 ) throw "Oops..."; // #5 throws on error
////
////    return add( 2, 2 )?0:1;
//}
