# s21_matrix

**An educational project from School 21: a full implementation of matrix operations in pure C.**

**The project involved designing a matrix structure and implementing all fundamental operations on matrices: arithmetic, comparison, determinant, transpose, inversion, and more.**

**All functions are thoroughly tested using the `check` unit testing framework and validated with memory analysis tools (`valgrind`, `leaks`). Code style and static analysis were enforced using `clang-format` and `cppcheck`.**

```bash
make             # build the static library and test binary

make test        # compile and run unit tests

make gcov_report # generate HTML coverage report

make valgrind    # run memory checks using valgrind

make leaks       # run memory checks on macOS using leaks

make check       # run code style and static analysis tools

make clean       # remove build artifacts and reports

make rebuild     # full clean and rebuild
```