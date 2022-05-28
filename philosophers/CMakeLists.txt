cmake_minimum_required(VERSION 3.16)
project(My_PHILO C)

set(CMAKE_C_STANDARD 99)

add_executable(My_PHILO philo.c print.c philo.h utils.c free.c actions.c init.c)
