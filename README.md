# SFINAE_hw3

### **Реализовать функцию печати условного IP-адреса.**

Условность его заключается в том, что количество элементов не обязательно должно быть равно 4-ём или 8-ми, а также каждый элемент не обязательно должен быть числом из диапазона 0..255. От идеи IP-адреса остаётся фактически только вывод элементов через `.` (символ точки). 

Функцию нужно реализовать для различных входных параметров путём использования механизма SFINAE. Всего нужно выполнить 3 обязательных и один опциональный вариант функции.

1. Адрес может быть представлен в виде произвольного целочисленного типа. Выводить
побайтово в беззнаковом виде, начиная со старшего байта, с символом `.` (символ точки) в качестве разделителя. Выводятся все байты числа.
2. Адрес может быть представлен в виде строки. Выводится как есть, вне зависимости от
содержимого.
3. Адрес может быть представлен в виде контейнеров `std::list`, `std::vector`.
Выводится полное содержимое контейнера поэлементно и разделяется `.` (символом
точка). Элементы выводятся как есть.
4. Опционально адрес может быть представлен в виде `std::tuple` при условии, что все
типы одинаковы. Выводится полное содержимое поэлементно и разделяется `.` (одним символом точка). Элементы выводятся как есть. В случае, если типы кортежа не одинаковы,должна быть выдана ошибка при компиляции кода.

***Прикладной код должен содержать следующие вызовы:***

print_ip( int8_t{-1} ); // 255\n
print_ip( int16_t{0} ); // 0.0
print_ip( int32_t{2130706433} ); // 127.0.0.1
print_ip( int64_t{8875824491850138409} );// 123.45.67.89.101.112.131.41
print_ip( std::string{“Hello, World!”} ); // Hello, World!
print_ip( std::vector<int>{100, 200, 300, 400} ); // 100.200.300.400
print_ip( std::list<shot>{400, 300, 200, 100} ); // 400.300.200.100
print_ip( std::make_tuple(123, 456, 789, 0) ); // 123.456.789.0
