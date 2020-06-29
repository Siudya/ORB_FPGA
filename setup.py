from setuptools import setup, find_packages
import os
import shutil
import sys
import subprocess
from distutils.dir_util import copy_tree
hw_data_files = []
if os.geteuid() != 0:
    print("This program must be run as root. Aborting.")
    sys.exit(1)

if os.environ['BOARD'] != 'Pynq-Z2' and os.environ['BOARD'] != 'Pynq-Z1':
    print("Only supported on a Pynq-Z2 and Pynq-Z1 Board")
    exit(1)
	
def copy_notebooks():
    src_nb_dir = os.path.join(f'', 'pynq_notebook')
    dst_nb_dir = os.path.join(os.environ['PYNQ_JUPYTER_NOTEBOOKS'], 'ORB_FPGA')
    if os.path.exists(dst_nb_dir):
        shutil.rmtree(dst_nb_dir)
    copy_tree(src_nb_dir, dst_nb_dir)

def copy_overlays():
    src_ol_dir = os.path.join('hw/', '')
    dst_ol_dir = os.path.join(f'/usr/local/lib/python3.6/dist-packages/ORB_FPGA/overlays', '')
    copy_tree(src_ol_dir, dst_ol_dir)
    hw_data_files.extend([os.path.join("..", dst_ol_dir, f) for f in os.listdir(dst_ol_dir)])
	
	
copy_notebooks()
copy_overlays()
setup(
	name = "ORB_FPGA",
	version = 1.0,
	url = 'https://github.com/Siudya/ORB_FPGA',
	license = 'BSD 3-Clause License',
	author = "Liang Sen",

	include_package_data = True,
	packages = find_packages(),
	package_data = {
	'' : hw_data_files,
	},
	description = "ORB Feature Extractor on PYNQ",
    install_requires=[
        'pynq','numpy','matplotlib'
    ],
)
