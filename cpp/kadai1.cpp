#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

// g++ kadai1.cpp -std=c++11

using namespace std;

class Mapping {
private:
    string uri;
    string path;
    string attr;

public:
    Mapping(string uri, string path, string attr): uri(uri), path(path), attr(attr)
    {
    }

    string getUri() {
        return uri;
    }

    string getPath() {
        return path;
    }

    string getAttr() {
        return attr;
    }

};

class FileReader {
private:
    vector<string> split(string& input, char delimiter)
    {
        istringstream stream(input);
        string field;
        vector<string> result;
        while (getline(stream, field, delimiter)) {
            result.push_back(field);
        }
        return result;
    }

public:
    FileReader()
    {
    }

    list<vector<string>> load(string& path)
    {
        list<vector<string>> lst;
        ifstream ifs(path);

        string line;
        while (getline(ifs, line)) {
            vector<string> strvec = split(line, ',');
            lst.push_back(strvec);
        }

        return lst;
    }

};

class MappingRule {
private:
    string path;
    list<Mapping*> rules;

public:
    MappingRule(string path): path(path)
    {
        FileReader* reader = new FileReader();
        list<vector<string>> lst = reader->load(path);

        for(auto itr = lst.begin(); itr != lst.end(); ++itr)
        {
            Mapping* m = new Mapping(itr->at(0), itr->at(1), itr->at(2));
            rules.push_back(m);
        }

        if (rules.size() == 0)
        {
            printf("Bad ARGV!: mapping_file is not found!\n");
            exit(EXIT_FAILURE);
        }

        delete reader;
    }

    list<Mapping*> getList() {
        return rules;
    }

    string isMath(string path) {
        for(auto itr = rules.begin(); itr != rules.end(); ++itr) 
        {
            if (path == (*itr)->getUri().c_str()) 
            {
                return (*itr)->getPath().c_str();
            }
        }

        return "no mapping";
    }

    void showAll()
    {
        printf("=======================================\n");
        for(auto itr = rules.begin(); itr != rules.end(); ++itr) 
        {
            printf("%s, %s, %s\n", (*itr)->getUri().c_str(), (*itr)->getPath().c_str(), (*itr)->getAttr().c_str());
        }
        printf("=======================================\n\n");
    }

    ~MappingRule()
    {
        cout << "[debug] destructor" << endl;
        for(auto itr = rules.begin(); itr != rules.end(); ++itr) 
        {
            delete *itr;
        }
    }
};


int main(int argc, char *argv[])
{
    string path;

    if (argc == 2) {
        path = argv[1];
    }
    else {
        printf("Bad ARGV!\nUse: kadai <path_to_mapping_file>\n");
        exit(EXIT_FAILURE);
    }

    MappingRule* mapping = new MappingRule(path);
    string input;

    for (;;) 
    {
        cout << "uriを入力してください: ";

        cin >> input;

        if (input == "/all") 
        {
            mapping->showAll();
            continue;
        }

        cout << mapping->isMath(input) << endl << endl;;
    }

    delete mapping;
    mapping = NULL;

} 
