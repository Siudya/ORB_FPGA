############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project HLS_myGaussianFilter
set_top gaussian_filter_accel
add_files ./xf_gaussian_filter_config.h
add_files ./xf_gaussian_filter_accel.cpp -cflags "-I ../xfopencv/include -D__SDSVHLS -std=c++0x"
add_files ./xf_config_params.h
add_files ./my_gaussian_filter.hpp
open_solution "solution1"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 3 -name default
config_export -format ip_catalog -rtl verilog
csynth_design
export_design -rtl verilog -format ip_catalog
close_project
