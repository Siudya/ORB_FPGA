############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project comFAST
set_top fast_accel
add_files ./xf_config_params.h
add_files ./myFAST.h
add_files ./myFAST.cpp -cflags "-I ../xfopencv/include -D__SDSVHLS__ -std=c++0x"
open_solution "solution1"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 3 -name default
config_export -format ip_catalog -rtl verilog
csynth_design
export_design -rtl verilog -format ip_catalog
close_project
