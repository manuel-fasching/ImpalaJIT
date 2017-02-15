# ImpalaJIT
A lightweight JIT compiler for flexible data access in simulation applications

# Building ImpalaJIT
1. cd build
2. cmake ../
3. make

# Regenerate Parser, Scanner and ASM
This step is only necessary if you have modified compiler/parser.yy, compiler/scanner.ll or code-gen/assembly/assembly.dasc.
Prerequisites for the "generate" task are:
Bison (Tested with version 3.0.4): https://www.gnu.org/software/bison/
Flex (Tested with version 2.6.0): https://github.com/westes/flex

1. make generate

# Install ImpalaJIT as Shared Library
1. make install

# Uninstall ImpalaJIT
1. make uninstall

# License
ImpalaJIT is release under the MIT License (see [COPYING](COPYING))