# c-matrix
## About
c-matrix is a linear-algebra library for C++ which includes iterative and parallelized solutions for all applicable operations.
The goal is to compare how much improvement can be made on simple matrix operations like addition and multiplication if simple multi-threading is added.

## Usage
Don't. Seriously, if you need a linear algebra library for any practical applications, you shouldn't use c-matrix. This is a hobby project made for my own learning & is not maintained or fully functional. Instead I would highly recommend that you use [Eigen](http://eigen.tuxfamily.org).

If you're some kind of masochist and still (for whatever reason) want to use c-matrix please feel free to. It's licenced under the [MIT Licence](https://github.com/ikhatri/c-matrix/blob/master/LICENSE), and you're free to use it however you wish.

## Features
c-matrix currently supports the following operations:
* Addition of two cmatrix objects
* Subtraction of two cmatrix objects
* Multiplication of two cmatrix objects
* Multiplication of a cmatrix object and another type
    * cmatrix * int
    * cmatrix * float
    * cmatrix * double

I'll add more as I have more time to work on this project.