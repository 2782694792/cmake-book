#pragma once

#include <iostream>
#include <string>

class Message {
public:
    Message(const std::string& m) : message_(m) {}

    friend std::ostream& operator<<(std::ostream& os, Message& obj) {
        return obj.printObject(os);
    }

private:
    std::string   message_;
    std::ostream& printObject(std::ostream& os) {

        os << "This is my very nice message: " << std::endl;
        os << message_;

        return os;
    }
};