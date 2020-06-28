## 文件夹内所含内容
### ip
包含了加速器的HLS代码
### pynq_arch
包含了加速器系统结构
### pynq_notebook
在PYNQ的Jupyter Notebook中运行的notebook
### soft_ware_test
包含了在CPU上运行的测试代码
### test_data
包含了测试用的图片
### hw
可以直接在PYNQ上使用的.bit和.hwh文件
## 如何重建vivado工程
使用vivado 2018.3
### 第一步：重建HLS IP
打开vivado HLS 命令行工具，运行以下命令：
```
cd <path-to-source_code>/ip
vivado_hls -f build_ip.tcl
```
### 第二步：重建vivado系统工程
打开vivado命令行工具，运行以下命令：
```
cd <path-to-source_code>/pynq_arch
source pynq_arch.tcl
```
## 运行软件测试要求
需要安装opencv2.4.13，支持C++11。