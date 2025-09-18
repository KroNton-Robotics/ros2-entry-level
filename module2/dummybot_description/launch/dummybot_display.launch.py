import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue

def generate_launch_description():
    """
    Launch file to display a URDF model in RViz.
    It starts the necessary nodes:
    - robot_state_publisher: to publish the robot's state and TF transforms
    - joint_state_publisher_gui: to manually control the joint values
    - rviz2: to visualize the robot model

    Change the 'urdf_path' and 'rviz_config_path' to point to your
    specific URDF file and RViz configuration file.
    """
    
    # Get the package share directory
    pkg_share = get_package_share_directory('dummybot_description')

    # Declare a launch argument for the URDF file
    urdf_path = os.path.join(pkg_share, 'urdf', 'dummybot.xacro')

    # Declare a launch argument for the RViz config file
    rviz_config_path = os.path.join(pkg_share, 'rviz', 'display.rviz')
    
    # Robot Description parameter with xacro processing
    robot_description = ParameterValue(
        Command(['xacro ', urdf_path]),
        value_type=str
    )

    # Node for robot_state_publisher
    robot_state_publisher_node = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description}]
    )

    # Node for joint_state_publisher_gui
    joint_state_publisher_node = Node(
        package='joint_state_publisher_gui',
        executable='joint_state_publisher_gui'
    )

    # Node for rviz2
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', rviz_config_path]
    )

    return LaunchDescription([
        robot_state_publisher_node,
        joint_state_publisher_node,
        rviz_node
    ])
