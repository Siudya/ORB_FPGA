from setuptools import setup
import os
import shutil
import sys
import subprocess

if os.geteuid() != 0:
    print("This program must be run as root. Aborting.")
    sys.exit(1)

if os.environ['BOARD'] != 'Pynq-Z2' and os.environ['BOARD'] != 'Pynq-Z1':
    print("Only supported on a Pynq-Z2 and Pynq-Z1 Board")
    exit(1)

setup(
	name = "ORB_FPGA",
	version = 1.0,
	url = 'https://github.com/Siudya/ORB_FPGA',
	license = 'BSD 3-Clause License',
	author = "Liang Sen",

	include_package_data = True,
	packages = ['respeaker'],
	package_data = {
	'' : ['*.bit','*.py','*.bin','*.txt', '*.cpp', '*.h', '*.sh','*.hwh'],
	},
	description = "ORB Feature Extractor on PYNQ",
    install_requires=[
        'pynq','numpy','opencv-python','matplotlib'
    ],
)

if 'install' in sys.argv:
	if os.path.isdir(os.environ["PYNQ_JUPYTER_NOTEBOOKS"]+"/ORB_FPGA/"):
		shutil.rmtree(os.environ["PYNQ_JUPYTER_NOTEBOOKS"]+"/ORB_FPGA/")
	shutil.copytree("pynq_notebook/",os.environ["PYNQ_JUPYTER_NOTEBOOKS"]+"/ORB_FPGA/")
