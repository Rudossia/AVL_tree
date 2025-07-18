# AVL Tree Project

Этот проект реализует **AVL-дерево** на C++ с шаблонным классом `avl_tree<T, U>` и предоставляет **интерактивное консольное меню** для работы с деревом.

## Возможности

* Вставка узлов (`insert`) с ключом `T` и значением `U`
* Обход дерева (`view_tree`) (in-order)
* Удаление узлов (`remove`) — заготовка, нужно реализовать
* Поиск узлов (`find`) — заготовка, нужно реализовать
* Очистка дерева (`clear`) — заготовка, нужно реализовать
* Получение высоты дерева (`height`) — заготовка, нужно реализовать
* Экспорт структуры дерева в формат Graphviz (`generate_dot` + `dot`)

## Структура проекта

```
├── Makefile             # Скрипт сборки
├── main.cpp             # Точка входа, вызывает menu_list::run_typed_menu()
├── tree/                # Реализация AVL-дерева
│   ├── tree.h           # Шаблонный класс avl_tree<T, U> и include "tree.tpp"
│   └── tree.tpp         # Реализация методов шаблона
├── menu/                # Интерактивное меню
│   ├── menu.h           # Обёртка AVLMenu<T,U> и прототип run_typed_menu()
│   └── menu.cpp         # Реализация run_typed_menu()
└── README.md            # Этот файл
```

## Зависимости

* **C++11** или выше
* **Graphviz** (для экспорта дерева в изображение)
  * Установить: `sudo apt install graphviz`
## Сборка

```bash
# В корне проекта
make
```

Makefile настроен на компиляцию `main.cpp` и `menu/menu.cpp` с включением заголовков из папок `tree` и `menu`.

## Запуск

```bash
./avl_tree_program
```

### Пример работы

1. Выбор типов шаблона: `int, std::string` или `std::string, double`
2. Интерактивное меню:

   ```
   1. Insert
   2. View
   3. Remove
   4. Find
   5. Clear
   6. Height
   7. Export DOT
   0. Exit
   ```
3. Ввод ключей и значений по запросу
4. Для `Export DOT` вводится базовое имя (без расширения) и автоматически генерируется `.dot` и `.png`

## TODO

* Реализовать методы `find`, `clear`, `height` в `avl_tree`
* Добавить поддержку дополнительных методов (например, обход в других порядках)
* Расширить выбор типов шаблонов

