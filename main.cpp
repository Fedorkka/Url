#include <iostream>
#include "Url.h"

int main() {

    Url u1("https://github.com/torvalds/linux/blob/master/kernel/time/hrtimer.c");
    std::cout << u1.getInfoStr();
    return 0;
}
