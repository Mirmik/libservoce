#!/usr/bin/env python3

from wheel.bdist_wheel import bdist_wheel as bdist_wheel_
from setuptools import setup, Extension, Command
from distutils.util import get_platform

class bdist_wheel(bdist_wheel_):
    def finalize_options(self):
        from sys import platform as _platform
        platform_name = get_platform()
        if _platform == "linux" or _platform == "linux2":
            # Linux
            platform_name = 'manylinux1_x86_64'

        bdist_wheel_.finalize_options(self)
        self.universal = True
        self.plat_name_supplied = True
        self.plat_name = platform_name

#zenlib_stub = Extension('zenlib_stub.so',
#    sources = [ 
#        "src/stub.cpp",
#    ]
#)

setup(
    name = 'servoce',
    #packages = ['servoce'],
    version = '0.1',
    license='MIT',
    description = 'wraper to opencascade',
    author = 'Sorokin Nikolay',
    author_email = 'mirmikns@yandex.ru',
    url = 'https://mirmik.github.io/servoce/',
    keywords = ['testing', 'cad'],
    classifiers = [],

    include_package_data=True,
    package_data={'servoce': ['libservoce.so']},

    #ext_modules = [zenlib_stub],
    cmdclass = {"bdist_wheel" : bdist_wheel}
)
