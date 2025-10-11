
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # Get the urdf file

    urdf_path = os.path.join(
        get_package_share_directory('dummybot_description'),
        'urdf',
        'dummybot.xacro'
    )

    # Launch configuration variables specific to simulation
    x_pose = LaunchConfiguration('x_pose', default='0.0')
    y_pose = LaunchConfiguration('y_pose', default='0.0')
    
    # New launch configuration for the robot name
    robot_name = LaunchConfiguration('robot_name', default='dummybot')

    # Declare the launch arguments
    declare_x_position_cmd = DeclareLaunchArgument(
        'x_pose', default_value='0.0',
        description='Specify x position of the robot')

    declare_y_position_cmd = DeclareLaunchArgument(
        'y_pose', default_value='0.0',
        description='Specify y position of the robot')

    # New launch argument for the robot name
    declare_robot_name_cmd = DeclareLaunchArgument(
        'robot_name', default_value='dummybot',
        description='Specify the name of the robot')

    start_gazebo_ros_spawner_cmd = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-name', robot_name,
            "-topic", "robot_description",
            '-x', x_pose,
            '-y', y_pose,
            '-z', '0.5'
        ],
        output='screen',
    )

    bridge_params = os.path.join(
        get_package_share_directory('dummybot_gazebo'),
        'config',
        'bridge.yaml'
    )

    start_gazebo_ros_bridge_cmd = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '--ros-args',
            '-p',
            f'config_file:={bridge_params}',
        ],
        output='screen',
    )


    ld = LaunchDescription()

    # Declare the launch options
    ld.add_action(declare_x_position_cmd)
    ld.add_action(declare_y_position_cmd)

    
    # Add the new robot_name launch argument
    ld.add_action(declare_robot_name_cmd)

    # Add any conditioned actions
    ld.add_action(start_gazebo_ros_spawner_cmd)
    ld.add_action(start_gazebo_ros_bridge_cmd)

    return ld