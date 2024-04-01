#ifndef ISINGSPIN_HPP
#define ISINGSPIN_HPP

class IsingSpin {
public:
    IsingSpin();
    ~IsingSpin();

    int _sz() const;
    void set_up();
    void set_dw();
    void set_sz(int sz_spec);
    void flip();

protected:
    int sz; // It's the spin direction of the object +/-1
};

#endif // ISINGSPIN_HPP
