## Пятнашки
### Общее задание:
Реализовать на языке С++ один из нижеперечисленных вариантов и написать и сгенерировать документацию при помощи doxygen. Для возможности тестирования классов написать

тестовую программу с меню или набор unit-тестов. В случае написания unit-тестов необходимо
проверить не менее 30 тестов случаев с использованием библиотеки UnitTest++.
Каждый из реализованных классов должен иметь следующие свойства:
- инкапсуляция;
- отделение консольного пользовательского интерфейса программы от реализации класса;
- конструктор копирования и оператор =, если это уместно;
- деструктор, если это необходимо;
- операторы для сравнения (операторы ==, !=);
- операторы для работы с потоками ввода (>>) и вывода (<<);
- взаимная независимость класса и пользовательского интерфейса, использующего его;
- отделение объявления класса в h-файл, а реализации — в cpp-файл.

### Детали:
Описать класс, реализующий игру-головоломку "Пятнашки". Начальное размещение номеров — случайное. Реализовать методы для осуществления перестановки клеток, для проверки правильной расстановки клеток. Класс должен реализовывать следующие возможности:
- cлучайное начальное размещение номеров;
- перестановка клеток;
- получения значения клетки (оператор []);
- проверка правильной расстановки клеток.