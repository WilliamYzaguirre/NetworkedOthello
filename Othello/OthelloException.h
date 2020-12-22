#ifndef OTHELLOEXCEPTION_H
#define OTHELLOEXCEPTION_H

#include <string>

class OthelloException
{
public:
    explicit OthelloException(const std::string reason)
        :reason_{reason}
    {
    }

    std::string reason() const {return reason_;}

private:
    std::string reason_;
};

#endif // OTHELLOEXCEPTION_H
