//Copyright Kildishev Maxim 2017

#include "include/Sort_app.h"
#include "include/Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <string.h>
#include <sstream>

SortApp::SortApp() : message_("") {}

void SortApp::help(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a sort application. \n\n" +
        "Pleass provide arguments in the following format:\n\n" +

        " $ " + appname + " <length_> <sort_type_> <array_elem_1> ..." +
        " <array_elem_length>\n\n" +

        "Where all arguments is a int-precision numbers, " +
        " and <sort_type_> is a choice of the kind of sort\n";
}

double parseInt(const char* args) {
	char* end = 0;
	int value = strtol(args, &end, 10);

	if (end[0]) {
		throw std::string("Wrong number format!");
	}

	return value;
}

bool SortApp::validateNumberOfSort(const char** argv)
{
    int sort_choise = parseInt(argv[2]);
    if (parseInt(argv[2]) < 1 || parseInt(argv[2]) > 4) {
        help(argv[0], "Error: Sort number should be between 1 and 4\n");
        return false;
    }
    return true;
}
bool SortApp::validateNumberOfArguments(int argc, const char** argv)
{
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    else if (parseInt(argv[1]) != (argc - 3)) {
        help(argv[0],
             "Error: Arguments count should be equal (array_length + 2)\n");
        return false;
    }
    return true;
}




std::string SortApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc,argv)) {
        return message_;
    }

	if (!validateNumberOfSort(argv)) {
		return message_;
	}

    try {
        args.length_ = parseInt(argv[1]);
        args.sort_type_ = parseInt(argv[2]);
        args.array_ = new int[args.length_];
        for (int i = 0; i < args.length_; i++) {
            args.array_[i] = parseInt(argv[3+i]);
         }
        }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;
    Sort sort(args.array_, args.length_);
    switch (args.sort_type_) {
        case 1:
        sort.QuickSort(0, args.length_-1);
        stream << "Sorted array: ";
        for (int i = 0; i < args.length_; i++)
            stream << sort[i] << " ";
        stream << "\n";

        break;

        case 2:
        sort.PasteSort();
        stream << "Sorted array: ";
        for (int i = 0; i < args.length_; i++)
            stream << sort[i] << " ";
        stream << "\n";

        break;

        case 3:
        sort.ChoiceSort();
        stream << "Sorted array: ";
        for (int i = 0; i < args.length_; i++)
            stream << sort[i] << " ";
        stream << "\n";

        break;

        case 4:
        sort.MergeSort(0, args.length_-1);
        stream << "Sorted array: ";
        for (int i = 0; i < args.length_; i++)
            stream << sort[i] << " ";
        stream << "\n";

        break;
    }
    message_ = stream.str();
    return message_;
}