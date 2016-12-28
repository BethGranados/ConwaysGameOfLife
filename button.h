#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

class Button
{
private:

public:
    virtual ~Button() {}
    virtual void onClick() = 0;
};

#endif // BUTTON_H_INCLUDED
