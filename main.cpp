#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <tuple>

template <typename T>
struct is_tuple : std::false_type {};

template <typename... Args>
struct is_tuple<std::tuple<Args...>> : std::true_type {};

template <
    typename T,
    typename = std::enable_if_t< is_tuple<std::decay_t<T>>::value>>
    void print_ip(const T& tuple)
{
    std::cout << "print tuple\n";
}

template <
    typename T,
    typename = std::enable_if_t< !is_tuple<std::decay_t<T>>::value>>
void print_ip(T t) {

    auto sz = sizeof(t) * 8;
    uint8_t mask = 0xff;

    if (t < 0) {
        // t = (~t) + (uint8_t)1;
        t = static_cast<uint8_t>(t);
    }

    do {
        sz -= 8;
        std::cout << std::to_string(static_cast<uint8_t>(t >> sz)) << ((sz != 0) ? "." : "\n");
    } while (sz);
}


void print_ip(std::string t) {
    std::cout << t << std::endl;
}

template <
    template<typename, typename> typename Container,
    typename Type,
    typename Allocator = std::allocator<Type>,
    typename = std::enable_if_t<
    std::is_same_v<Container<Type, Allocator>, std::vector<Type, Allocator>> ||
    std::is_same_v<Container<Type, Allocator>, std::list<Type, Allocator>>>>
    void print_ip(const Container<Type, Allocator>& container) {
    for (auto it = std::begin(container); it != std::end(container); ++it) {
        if (it != std::begin(container))
            std::cout << ".";
        std::cout << *it;
    }
    std::cout << std::endl;
}

int main() {
    print_ip(int8_t{ -1 }); // 255
    print_ip(int16_t{ 0 }); // 0.0
    print_ip(int32_t{ 2130706433 }); // 127.0.0.1
    print_ip(int64_t{ 8875824491850138409 });// 123.45.67.89.101.112.131.41
    print_ip(std::string{ "Hello, World!"}); // Hello, World!
    print_ip(std::vector<int>{100, 200, 300, 400}); // 100.200.300.400
    print_ip(std::list<short>{400, 300, 200, 100}); // 400.300.200.100
    print_ip(std::make_tuple(123, 456, 789, 0)); // 123.456.789.0

    return 0;
}