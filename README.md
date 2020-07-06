## Introduction
This project implements a ORB feature extractor accelerator on FPGA (on PYNQ-Z2 board).
## Quick Start
Run these command lines on your Pynq-Z2 Board (tested on v2.4):
```
sudo pip3 install https://github.com/Siudya/ORB_FPGA
```
## Contents of each folder
### ip
HLS sources files 
### pynq_arch
Vivado project
### pynq_notebook
Notebook run in Jupyter Notebook
### soft_ware_test
A .cpp file that test the same process on CPU 
### test_data
Images for test
### hw
.bit and .hwh files for PYNQ  

## How to rebuild Vivado project
**vivado 2018.3** is required.  

### Step 1: rebuild HLS IP
Open **Vivado HLS** command terminal and run these commands :  
```
cd <path-to-proj>/ip
vivado_hls -f build_ip.tcl
```  
This should take about half an hour.
### Step 2: rebuild top project
Open **Vivado** command terminal and run these commands :  
```
cd <path-to-proj>/pynq_arch
source pynq_arch.tcl
```
