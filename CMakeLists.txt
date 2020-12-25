cmake_minimum_required(VERSION 3.17)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ray_tracer main.cpp vec3.cpp vec3.h color.h ray.cpp ray.h)