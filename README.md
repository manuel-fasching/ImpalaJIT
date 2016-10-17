# ImpalaJIT
A lightweight JIT compiler for flexible data access in simulation applications

# Building ImpalaJIT
1.) Install tcc-0.9.26 - www.tinycc.org / libtcc.a should be placed at /usr/local/lib
2.) cd build/
2.) cmake ../
3.) make

# Run ImpalaJIT
The binary takes an absolute path to a C File as parameter. e.g.
./ImpalaJIT /home/user/ImpalaJIT/test.c