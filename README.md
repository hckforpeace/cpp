# C++ Modules

A complete walk through the **42 School C++ Modules** (`CPP00` → `CPP09`): ten self-contained modules that build up from C++ basics to templates, the STL, and classic algorithms — one exercise at a time.

Every program is written in **C++98** and compiled with `-Wall -Wextra -Werror`, following the 42 coding constraints (no STL before Module 08, no `printf`, no friends/operators outside the prescribed scope, etc.).

> [!NOTE]
> This is a learning repository. Each exercise is a standalone mini-project with its own `Makefile`, source files, and entry point — designed to be built and run independently.

## Modules at a glance

| Module | Theme | Highlights |
| --- | --- | --- |
| **CPP00** | Namespaces, classes, member functions, stdio streams | `megaphone`, a `PhoneBook`, an account/bank ledger |
| **CPP01** | Memory, references, pointers to members | Zombies on stack vs. heap, a `Weapon` shared by reference, file replace, the `Harl` logger |
| **CPP02** | Ad-hoc polymorphism, operator overloading, orthodox canonical form | A `Fixed`-point number class, BSP point-in-triangle test |
| **CPP03** | Inheritance | The `ClapTrap` → `ScavTrap` → `FragTrap` → `DiamondTrap` family |
| **CPP04** | Subtype polymorphism, abstract classes, interfaces | `Animal`/`Cat`/`Dog`, deep copy with `Brain`, the materia/character system |
| **CPP05** | Repetition and exceptions | The `Bureaucrat`, signable `Form`s, and the `Intern` that makes them |
| **CPP06** | Type conversion & casting | A scalar converter, (de)serialization, runtime type identification |
| **CPP07** | C++ templates | `swap`/`min`/`max`, a generic `iter`, a templated `Array` |
| **CPP08** | Templated containers, iterators, algorithms | `easyfind`, a `Span`, a `MutantStack` |
| **CPP09** | STL in practice | `BitcoinExchange`, a Reverse Polish Notation calculator, the `PmergeMe` merge-insertion sort |

## Repository layout

```
.
├── cpp00/ … cpp09/        # one directory per module
│   ├── ex00/              # one directory per exercise
│   │   ├── Makefile       # builds this exercise only
│   │   ├── *.hpp / *.cpp  # sources
│   │   └── main.cpp       # entry point
│   └── …
```

## Requirements

- A C++ compiler supporting C++98 (`c++` / `clang++` / `g++`)
- `make`

## Build & run

Each exercise is built on its own. `cd` into any exercise directory and run `make`:

```sh
cd cpp00/ex01
make
./PhoneBook
```

The produced binary's name is defined by the `NAME` variable in that exercise's `Makefile` (it varies per exercise — e.g. `megaphone`, `PhoneBook`, `bank`, `Fixed`, `btc`, `RPN`, `PmergeMe`).

Every `Makefile` provides the standard 42 targets:

| Target | Action |
| --- | --- |
| `make` / `make all` | Compile the exercise |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and the binary |
| `make re` | `fclean` then rebuild |

### A few examples

```sh
# CPP00 — shout in uppercase
cd cpp00/ex00 && make && ./megaphone "hello world"

# CPP05 — bureaucrats, forms and exceptions
cd cpp05/ex03 && make && ./BUREAUCRAT

# CPP09 — convert a value to its Bitcoin price on a given date
cd cpp09/ex00 && make && ./btc input.txt

# CPP09 — evaluate a Reverse Polish Notation expression
cd cpp09/ex01 && make && ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

> [!TIP]
> Some exercises ship sample data alongside the sources — for instance `cpp09/ex00` includes `data.csv` and `input.txt`, ready to feed into the program.
