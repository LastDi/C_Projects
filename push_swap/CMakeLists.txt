cmake_minimum_required(VERSION 3.10)
project(test C)

set(CMAKE_C_STANDARD 99)

add_executable(test push_swap.c small_sort_func.c push_swap.h free_func.c validate_func.c init_stack_func.c sort_func.c sort_rules_part_one.c sort_rules_part_two.c manipulation_func.c utils_func.c push_func.c)
#add_executable(test z_free_func_bonus.c z_get_next_line_bonus.c z_get_next_line_utils_bonus.c z_init_stack_func_bonus.c z_push_swap_bonus.c z_sort_rules_part_one_bonus.c z_sort_rules_part_three_bonus.c z_sort_rules_part_two_bonus.c z_start_checker_bonus.c z_validate_func_bonus.c)
