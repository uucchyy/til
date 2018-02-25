#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

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

};

int main()
{

    string uri = "/uri";
    string path = "/path";
    string attr = "1";
    Mapping *m = new Mapping(uri, path, attr);

    printf("%s\n", m->getUri().c_str());

} 
