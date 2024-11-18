cmake_minimum_required(VERSION 3.29)
project(estrutura_de_dados_arvores C)

set(CMAKE_C_STANDARD 11)

add_executable(estrutura_de_dados_arvores
    main.c
        arvore-tad.h
        pilha-arvore-tad.h
        arvore-pilha.h)
