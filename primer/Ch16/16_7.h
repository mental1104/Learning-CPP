#ifndef EX16_7
#define EX16_7

template<typename T, typename N>
constexpr unsigned SizeOfArray(const T (&arr)[N])
{
    return N;
}