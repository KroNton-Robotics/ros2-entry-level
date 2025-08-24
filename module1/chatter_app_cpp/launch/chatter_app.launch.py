from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([

        Node(
            package='chatter_app_cpp',
            executable='talker',
            name='chatter_publisher'
        ),

        Node(
            package='chatter_app_cpp',
            executable='listener',
            name='chatter_subscriber'
        )

    ])