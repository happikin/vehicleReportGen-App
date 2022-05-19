#include <fstream>
using namespace std;

class File {
    fstream* file;
    public:
        void open(std::string&& path, std::ios::openmode mode=std::ios::in) {
            file = new fstream(path,mode);
        }
        fstream* get() {return file;}
};