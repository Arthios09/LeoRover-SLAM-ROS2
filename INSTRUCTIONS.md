# LeoRover Setup and User Guide
Kai Mohl | ka.mohl@berkeley.edu | kai.mohl36@gmail.com

## 1. Master Link List

### Rover Use and Activation:

### Note: Please see the private doc for unlisted links, passwords, hyperlinks, and pictures
Private Document Link: https://docs.google.com/document/d/13QJeMEwr39OPiz0HjwH_UOHRjEEE9kCBeV8xATVtMiI/edit?usp=sharing

Github Repo
LeoRover Documentation
RPLidar Repo ROS2

### Rover Background Knowledge and Important Concepts:

https://developer.nvidia.com/embedded/jetpack-sdk-60 
ROS2 Humble
Nav2/SLAM

## 2. Hardware Setup

### Hardware Scheme: 

Along with the included RaspberryPi and LeoCore controller, the rover is equipped with a number of additional sensors and extra compute. The controller handles the basic wheel, motor, battery, and IMU monitoring and control. The RaspberryPi along with the more powerful Nvidia Jetson Orin Nano run all ROS2 nodes, allowing for function anywhere, regardless of access to a computer running ROS or internet access. The two computers are connected via an ethernet cable, permitting the transmission of ROS topic data. The RPLiDAR A2M12 and ZED stereo camera allow for accurate obstacle detection, navigation, and mapping. The Zed camera is our primary sensor for the detection of Aruco tags, objects, and people, while the 2D LiDAR provides information exclusively for SLAM.

### Attaching and Charging Batteries:

Our LeoRover uses 2 batteries per rover as opposed to the base version’s single battery (with 4 batteries, 2 per rover, existing in Cory 337D). The battery with the button connects to the internal power cable and powers the Raspberry pi, wheel motors, controller, etc. The other battery quarter powers the Nvidia Jetson.
Use an hex key to remove the 3 screws connecting the battery quarters and the rover body. The Jetson battery may be plugged into its wall socket charger, with a red light indicating charging and a green light indicating full battery. The main battery may be plugged into its wall socket charger. Once plugged in, press the button on the side panel. Once pressed, the battery will begin charging, with a red light indicating charging and a green light indicating full battery

### Removing Adding and Changing Hardware Attachments:

A full set of hex keys are recommended for deconstructing and reconstructing rover components. For the Nvidia Jetson mounts, holding plates, and other 3D printed components please see the CAD files in the main repo. For base LeoRover components, please see the Fictionlab website. 

### Raise3D Printer:

Cory337D contains a Raise 3D Pro printer. The slicing software can be found online on the Raise3D website. Please follow the instructions to properly slice your STL and print using this printer. Although there is a Dremel printer, I have no personal experience using it and recommend using the Raise3D Pro. 

## 3. Software Setup and Development

### Software Scheme:

Both the Raspberry Pi and Nvidia Jetson run on Ubuntu 22.04 and ROS2 Humble. Through their shared network (via ethernet cable) ros topic data, nodes, and services are shared between them. Please regularly run sudo apt update/sudo apt upgrade to insure all packages are up to date.
The rover’s navigation stack is centered around two open source libraries, Nav2 and SLAM toolbox. Reading through the documentation of these libraries is highly recommended. The config/param files for these ros packages exist in the repo. Please see documentation for modification instructions, parameter definitions, and syntax. 
The rover’s sensor fusion uses an EKF to combine odometry information collected by the wheel encoders, IMUs, LiDAR, and Zed Camera. Please see the EKF config files and source code in the Github repository for modifications.

The rover’s connection to external devices is permitted through its onboard wifi chip. Although the onboard wifi does not have to be connected to another wifi network/the internet, connection to the rover’s wifi is necessary to ssh into either computer and transmit information via the api server/websockets. Two methods of communication exist for accessing ROS data and functions on the rover. The api server is used for running ROS2 commands on the rover from a remote device that cannot ssh and/or is not using Ubuntu 22.04. The rosbridge suite websocket server is used to monitor topic data from a remote device that cannot ssh and/or is not using Ubuntu 22.04.

### Setting Up a New Rover or Computer:

To flash the base onboard RaspberryPi please follow the LeoRover Ros2 (experimental) guide here. A microSD, microSD-SD adapter, and a computer are required. 

To flash the Nvidia Jetson Orin Nano please follow the Jetpack 6.0 guide here. To flash Jetpack 6.0 (Ubuntu 22.04), a microSD, microSD-SD adapter, and a computer are required. It is recommended to plug the Jetson into a monitor to more easily navigate the setup menus and BIOS. 
Once both computers have been flashed, please proceed to the ROS2 Humble guide to install ROS, rosdep, and necessary dependencies.

The Zed cameras require the installation of CUDA (comes with Jetpack 6.0), and the Zed SDK. Please check the cuda version using nvcc and confirm that the base requirements are satisfied for the latest version of the Zed SDK. Once this is complete, you may proceed to pulling packages from the LeoRover repository and installing Nav2/Robot Localization or any new packages.

When installing Nav2, SLAM toolbox, and Robot Localization there are 2 options, installing debian packages, or building from source. Installing the prebuilt packages provides easy use (while only having to source /opt/ros/humble/setup.bash) and maintains the ability to specify custom param files for quick modifications. Building from source allows greater control and potential modification of the provided packages however can increase your risk of running into ROS2 related errors and issues (out of date dependencies/versions, conflicts with other packages in the directory, etc.). The two functioning rovers utilize Nav2/SLAM toolbox (both on the Nav2 guide) installed through debian packages and Robot Localization built from source (due to customization of the ekf node).  
Finally, the communication between the rover and phone must be set up. The rover uses two methods of communication, an API server linked on the github to transmit and execute commands from the phone to the rover, and rosbridge suite websockets for direct topic publication and monitoring from the phone. The API server may be pulled and ran (python main.py) with or without a virtual environment. Rosbridge suite may be installed via the prebuilt ros2 humble packages and ran with the command “ros2 launch rosbridge_server rosbridge_websocket_launch.xml”. The ports to access these will be displayed when activated.


### Rover Activation and Use:

For instructions and specific commands used to activate the rover, please see the README in the rover repo linked at the start of this document. 
Although many commands, functions, and software abilities are available for use, the essential ROS2 nodes for the rover are:
Raspi - leo_system and rplidar_a2m12_launch.py
Jetson - static transforms, navigation_launch.py, online_async_launch.py (SLAM), ekf.launch.py, zed_camera.launch.py, rosbridge_websocket_launch.xml, and the api server
To activate the api server, cd into api_folder/api_server and run python main.py. See linked documentation on repo. 
All of these functions except the api-server can be started with a single command, “python3 start_rover.py” or “ros2 launch leo_common-ros2 rover_comp_launch.xml“. For development and testing, it is recommended to launch nodes individually to monitor output and restart nodes in the event of failure. 

### Control Computer Setup:

To use a control computer, create a partition and install Ubuntu 22.04, ros2 humble, and necessary dependencies and packages (instructions of ROS2 Humble website). Once this is complete, see the control computer section in the README of the repo to visualize with RVIZ. All nodes can be run from a control computer if desired.

### Development and Troubleshooting:

If you are having issues with running new packages, remember to colcon build, source your workspace, look for online resources (ie: stack exchange, github forums) for solutions, and ask those in the lab for help. Contact me using any of the contacts listed at the top of the document for help. 
For future development purposes, please fork the main repository (or duplicate it under your ownership). Features including object/body detection have great potential for future projects, so consider utilizing these for demos. If the Nvidia Jetson is substituted for the VIA AI Transforma, these functions, and integration with the Zed are no longer possible. In this case, remove the Zed and do not run the Zed activation node. 
Sometimes, the rover’s onboard packages are ahead of the committed/pushed github repo. Please login to your github/create a github key on the rover so that you can check git status and make new commits/pulls from both your computer and the rover.


## 4. Recommendations

### Useful Software Tools:

Nmap - Allows you to scan ports (finding new jetson address on network)
Apt package manager - Frequently update your linux system using the apt package management command line tools. 
Solidworks/Tinkercad/Any cad software - Make new attachments for the rover
Useful Hardware Tools:
Full Hexkey Set - A full set of hex wrenches are necessary for modifying the rover and replacing batteries. These should be accessible in the lab.
Phillips Head Screwdriver - Necessary to dismantle the batter quarters and main electronics box of the rover.

### Qualifications:

The most effective individuals to work on the project will be those that have completed at least EE106a (see my 106a project using the rover here!) and ideally 106b, although due to the limited amount of new software developments necessary to fulfill needs for the Qualcomm demo, I do not believe these are strict requirements. If you are looking to recruit more robotics students to work on the team, the spare rover/the rover project in general could potentially be offered to those in 106a looking for a final project (under the research category). Please clear this with Allen, Franco, or the active advisor and team lead.
The most important qualifications for working with the rover are an interest in robotics and a desire to learn ROS/CAD/Network architecture. When I began working with the rover, I had not taken either robotics course and had never used Linux, ROS, or C++. The rover is a great platform for learning and experimenting with, so it is a great tool for those looking to gain new skills and begin involvement in lab research. 
Make sure to upkeep the physical components that see stress. The wheels/wheel attachment bar but have their screws tightened and be readjusted every so often so as to prevent failure.

### Suggested Changes/Additions:

Remove SSH password 
Some of the nodes, especially SLAM toolbox, occasionally fail/are unreliable beyond 30 minutes to an hour. This should ideally be fixed.
Request the purchase of the LeoRover charging station for in use charging and battery hotswapping. Will save time not having to reactivate rover (~5-6 minute process) and will reduce stress caused by battery charging/life during live demos.
Do something cool with object/body detection. Read through the zed ROS object/body tracking sections for topic information and use. See my 106a project for potential inspiration on flashy use cases.
Nav2 is occasionally clunky, so it may be worthwhile long term to write a custom nav stack. Please ask for Michael Wu’s contact as he may have suggestions/advice.
Deadman’s switch - As soon as connection via ssh/websocket/apiserver is lost for X time, auto run return to base. Shouldn't be very hard but would be a nice feature to implement. 
Robotic arm attachment would allow for more complex tasks, however would increase compute load significantly.
If switching permanently to VIA Transforma, investment in a new 3D LiDAR (as opposed to the current 2D) may be necessary to allow for object/body tracking functions.



