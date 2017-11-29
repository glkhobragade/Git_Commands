#include<iostream>
#include<memory>

template <typename T>
struct name
{
    int p;
    int q;
    T r;
};

template <typename T, typename X = struct name<T> >
class test
{
    public:
    T x;

    std::shared_ptr<X> getX(){

        struct name<T> ghansham;
        ghansham.p = 9;
        ghansham.q = 8;
        ghansham.r = 7;
        return std::make_shared<struct name<T>>(ghansham);
    }
   /*
    X getX(){

        struct name<T> ghansham;
        ghansham.p = 9;
        ghansham.q = 8;
        ghansham.r = 7;
        return ghansham;
    }
 */
};

