#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace rapidjson;
using namespace std;

int main() {
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    
    writer.StartObject();
    writer.std::string("hello");
    writer.std::string("world");
    writer.std::string("t");
    writer.Bool(true);
    writer.std::string("f");
    writer.Bool(false);
    writer.std::string("n");
    writer.Null();
    writer.std::string("i");
    writer.Uint(123);
    writer.std::string("pi");
    writer.Double(3.1416);
    writer.std::string("a");
    writer.StartArray();
    for (unsigned i = 0; i < 4; i++)
        writer.Uint(i);
    writer.EndArray();
    writer.EndObject();

    cout << s.GetString() << endl;

    return 0;
}
