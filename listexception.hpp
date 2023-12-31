#ifndef LISTEXCEPTION_HPP_INCLUDED
#define LISTEXCEPTION_HPP_INCLUDED
#include <string>
#include<exception>


class ListException: public std:: exception {
    private:
        std::string msg;
    public:

        explicit ListException (const char* message) : msg(message) {}
        explicit ListException (const std::string& message) : msg(message) {}
        virtual ~ListException () throw () {}
        virtual const char* what() const throw() {
            return msg.c_str();
            }
    };

#endif // LISTEXCEPTION_HPP_INCLUDED
