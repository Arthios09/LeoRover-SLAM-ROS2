# LeoRover-SLAM-ROS2
Packages and instructions needed to launch the Leo System and attached rplidar in ROS2 Humble. Please install the Zed SDK, Zed-ros2-wrapper, Nav2, SLAM-Toolbox, and robot-localization packages for ROS2 Humble.Tested on Ubuntu 22.04 ROS2 Humble

### Launching the Leo Rover
After turning on the Leo Rover, ssh with the provided credentials. Addresses for ssh are as follows pi@10.0.0.1 PW: raspberry, leoroverjetson1@10.0.0.120 or leoroverjetson2@10.0.0.161 PW: cory337d
, 
1. Open a terminal and launch the Leo Rover's main system
```
$ source /opt/ros/humble/setup.bash
$ ros2 run leo_bringup leo_system
```
2. Open a second terminal and launch the RPLidar node.
```.
$ source /opt/ros/humble/setup.bash
$ ros2 launch rplidar_ros rplidar_a2m12_launch.py
```
3. In order to get the Laserscan topic to appear correctly, and for the Nav2 SLAM to function, we need to use a series of tf transfoms. All are necessary for the tf tree to be complete. If not working please use rqt.
```
$ source /opt/ros/humble/setup.bash
$ ros2 run tf2_ros static_transform_publisher 0.1 0 0.02 3.14159 0 0 base_link laser
$ ros2 run tf2_ros static_transform_publisher 0.1 0 0.1 3.14159 0 0 base_link zed_camera_link

```

### Setting up a control computer and using RVIZ
Requirements: Ubuntu 22.04 ROS2 Humble
1. Pull this repository to your local computer, build, and install any required dependencies.
```
$ git pull https://github.com/Arthios09/LeoRover-SLAM-ROS2.git
$ rosdep update
$ rosdep install --from-paths src -y --ignore-src
$ colcon build --symlink-install
```
2. Open a terminal within this folder so that we can visualize the system.
```
$ source install/setup.bash
$ ros2 launch leo_viz rviz.launch.xml
```
Note: All required packages are already on-board the Leo Rover.

### Launching Aruco ROS
1. Make sure to be in the aruco_ros folder before executing
```
$ source install/setup.bash
$ ros2 launch aruco_ros single.launch.py marker_size:=.1 marker_id:=0 reference_frame:=base_link camera_frame:=camera_optical_frame
```

### Running preprogrammed drive scripts
1. To run preprogrammed commands, modify commands.txt and run the following program:
```
$ source install/setup.bash
$ ros2 run programmed_drive drive
```
2. To run the Aruco follow command
```
$ source install/setup.bash
$ ros2 run programmed_drive aruco_drive
```

### Running Foxglove
1. Due to the way the websocket is set up, we need to export the port to point correctly on the rover computer. Open a terminal:
```
$ source install/setup.bash
$ ros2 launch foxglove_bridge foxglove_bridge_launch.xml port:=8765
```
2. Now, launch Foxglove Studio
```
$ foxglove-studio
```
Set the port to default (8765), and use the provided template file to view the rover. Files may change.

### SLAM Implementation - Nav2
1. For installation of Nav2 and the required dependencies, please follow the guide at https://navigation.ros.org/getting_started/
2. To start the Nav2 + slamtec SLAM implementation, open 3 terminals and run:
```
$ source /opt/ros/humble/setup.bash
$ ros2 launch nav2_bringup navigation_launch.py params_file:=nav2_main.yaml
```
and
```
$ source /opt/ros/humble/setup.bash
$ ros2 launch slam_toolbox online_async_launch.py params_file:=mapper_params_main.yaml

$ source /opt/ros/humble/setup.bash
$ ros2 launch robot_localization ekf.launch.py params_file:=ekf.yaml

$ ros2 launch zed_wrapper zed_camera.launch.py camera_model:=zed2i  #zed node launch script

```

### Startup Scirpt
1. To start all necessary ROS2 nodes and services, open an ssh terminal connected to a Jetson and run:
```
$ python3 start_rover.py
```
### API Server
1. Please clone the repository and follow directions found at https://gitlab.com/roar-gokart/api-server
```
$ ros2 launch rosbridge_server rosbridge_websocket_launch.xml
```
2. To launch the websocket server:
```
$ roslaunch rosbridge_server rosbridge_websocket.launch
```
