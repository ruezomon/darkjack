#include <stdexcept>
#include <string>

class InitException : public std::exception {
private:
    std::string message;
public:
    inline InitException(const char* msg) :
    message(msg) {}

    inline const char* what() const noexcept {
        return message.c_str();
    }
};