#include <iostream>
#include <type_traits>
#include <typeinfo>
template <typename T, typename U>
struct decay_equiv : 
    std::is_same<typename std::decay<T>::type, U>::type 
{};
template<typename T>
void myfunc(){
    std::cout << __PRETTY_FUNCTION__ << '\n';
};
int main()
{

    ::std::cout << ::std::boolalpha << ::std::is_same<::std::decay<int&&>::type,int>::type::value << ::std::endl
        << decay_equiv<const int*,const int*>::value << ::std::endl;    
    int a = 1 ;
    myfunc<::std::decay<int(int)>::type>();
    myfunc<decltype(a)>();
}
