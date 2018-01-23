#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> getDirList(char* dirName) {
    vector<string> files = vector<string>();

    const int inputLen = strlen(dirName);
    if (inputLen > MAX_PATH - 2) {
        std::cerr << "Input too long.";
        exit(1);
    }

    char searchpath[MAX_PATH] = {0,};
    strcpy(searchpath, dirName);
    const char lastChar = searchpath[inputLen - 1];
    const bool isDelimited = lastChar == '\\' || lastChar == '/';
    if (isDelimited) {
        strcat(searchpath, "*");
    } else {
        strcat(searchpath, "/*");
    }

    WIN32_FIND_DATA findFileContext;
    HANDLE findHandle = FindFirstFile(searchpath, &findFileContext);
    if (findHandle != INVALID_HANDLE_VALUE) {
        do {
            char* fullFileName;
            fullFileName = strcpy(fullFileName, dirName);
            fullFileName = strcat(fullFileName,(isDelimited ? "" : "/"));
            fullFileName = strcat(fullFileName, findFileContext.cFileName);

            if (findFileContext.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                // std::cout << fullFileName << endl;
                files.push_back((string)fullFileName);
            } else {
                // std::cout << fullFileName << endl;
                files.push_back((string)fullFileName);
            }
        } while (FindNextFile(findHandle, &findFileContext) != 0);

        FindClose(findHandle);
    }
    return files;
}

void printVector(vector<string> files) {
    vector<string>::iterator vectorIterator;

    for (vectorIterator = files.begin(); vectorIterator != files.end(); vectorIterator++ ) {
        cout << *vectorIterator << endl;
    }
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Missing argument path";
        return -1;
    }

    char * inputDir = argv[1];
    std::cout << "Files inside \"" << inputDir << "\"" << std::endl;

    vector<string> dirList = getDirList(inputDir);

    printVector(dirList);
}
