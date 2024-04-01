#include "IsingSpin.hpp"
#include <cassert>

IsingSpin::IsingSpin() : sz(1) {}

IsingSpin::~IsingSpin() {}

void IsingSpin::set_up() { sz = 1; }

void IsingSpin::set_dw() { sz = -1; }

void IsingSpin::set_sz(int sz_spec) {
    assert(sz_spec == 1 or sz_spec == -1);
    sz = sz_spec;
}

void IsingSpin::flip() {
    sz *= -1;
}

int IsingSpin::_sz() const {
	return sz;
}