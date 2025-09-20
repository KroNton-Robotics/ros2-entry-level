import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

def generate_launch_description():


    pkg_share = get_package_share_directory('dummybot_description')

    urdf_path = os.path.join(pkg_share,'urdf','dummybot.xacro')

    robot_description= ParameterValue(

        Command(['xacro ', urdf_path]),
        value_type=str
    )

    robot_state_publisher_node= Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description':robot_description}]
    )

    joint_state_publisher_node= Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui'

    )


    return LaunchDescription([

        robot_state_publisher_node,
        joint_state_publisher_node
    ])