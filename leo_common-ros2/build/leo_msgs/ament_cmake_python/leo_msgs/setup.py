from setuptools import find_packages
from setuptools import setup

setup(
    name='leo_msgs',
    version='1.1.0',
    packages=find_packages(
        include=('leo_msgs', 'leo_msgs.*')),
)
