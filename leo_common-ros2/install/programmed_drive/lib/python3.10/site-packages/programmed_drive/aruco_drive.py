import geometry_msgs.msg
import rclpy
from rclpy.node import Node

class ArucoDriverNode(Node):
    def __init__(self):
        super().__init__('ArucoDriverNode')

        stamped = self.declare_parameter('stamped', False).value
        frame_id = self.declare_parameter('frame_id', '').value
        if not stamped and frame_id:
            raise Exception("'frame_id' can only be set when 'stamped' is True")

        if stamped:
            TwistMsg = geometry_msgs.msg.TwistStamped
        else:
            TwistMsg = geometry_msgs.msg.Twist

        self.twist_msg = TwistMsg()

        if stamped:
            self.twist = self.twist_msg.twist
            self.twist_msg.header.stamp = self.get_clock().now().to_msg()
            self.twist_msg.header.frame_id = frame_id
        else:
            self.twist = self.twist_msg


        self.pub = self.create_publisher(TwistMsg, 'cmd_vel', 10)
        self.sub = self.create_subscription(geometry_msgs.msg.TransformStamped, 'aruco_single/transform', self.listener_callback, 10)

    def listener_callback(self, msg):
        #self.get_logger().info(int(msg.transform.translation.x))

        error = msg.transform.translation

        #slow adjustment controls, no PID
        self.twist.linear.x = 0.0
        self.twist.angular.z = 0.0
        self.twist.linear.y = 0.0
        self.twist.linear.z = 0.0
        self.twist.angular.x = 0.0
        self.twist.angular.y = 0.0
        epsilon = 0.05

        print(error.y)

        if(error.y > epsilon):
            self.twist.linear.x = 0.7
            self.twist.angular.z = 2.0
            print("left")
        elif(error.y < -epsilon):
            self.twist.linear.x = 0.7
            self.twist.angular.z = -2.0
            print("right")
        elif(error.x > epsilon):
            self.twist.linear.x = 1.0
            self.twist.angular.z = 0.0
            print("straight")
        else:
            self.twist.linear.x = 0.0
            self.twist.angular.z = 0.0
            raise Exception("Achieved goal")


        self.pub.publish(self.twist_msg)
        


def main():
    rclpy.init()

    node = ArucoDriverNode()
    
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

    # parameters


if __name__ == '__main__':
    main()
