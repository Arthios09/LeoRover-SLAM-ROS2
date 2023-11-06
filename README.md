# LeoRover-SLAM-ROS2
Packages and instructions needed to launch the Leo System and attached rplidar in ROS2 Humble. Tested on Ubuntu 22.04 ROS2 Humble

### Launching the Leo Rover
After turning on the Leo Rover, ssh with the provided credentials.

1. Open a terminal and launch the Leo Rover's main system
```
$ source /opt/ros/humble/setup.bash
$ ros2 run leo_bringup leo_system
```
2. Open a second terminal and launch the RPLidar node.
```
$ source /opt/ros/humble/setup.bash
$ ros2 launch rplidar_ros rplidar_a2m12_launch.py
```

### Setting up the control computer
1. In order to get the Laserscan topic to appear correctly, we need to tie it to the correct frame. Open a terminal on the local computer and type:
```
$ source /opt/ros/humble/setup.bash
$ ros2 run tf2_ros static_transform_publisher 0.1 0 0.02 3.1415926 0 0 base_link laser
```
2. Now, open a separate terminal within this folder so that we can visualize the system.
```
$ source install/setup.bash
$ ros2 launch leo_viz rviz.launch.xml
```

### Running Foxglove
1. Due to the way the websocket is set up, we need to export the port to point correctly on the one computer. Open a terminal:
```
$ source install/setup.bash
$ ros2 launch foxglove_bridge foxglove_bridge_launch.xml port:=8765
```
2. Now, launch Foxglove Studio
```
$ foxglove-studio
```
Set the port to default (8765), and use the provided template file to view the rover. Files may change.
