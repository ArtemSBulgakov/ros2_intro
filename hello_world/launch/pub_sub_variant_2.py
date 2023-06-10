from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    description = LaunchDescription()
    description.add_action(Node(
        package='hello_world',
        executable='publisher_class_node',
        output='screen'
    ))
    description.add_action(Node(
        package='hello_world',
        executable='subscriber_node',
        output='screen'
    ))
    return description
