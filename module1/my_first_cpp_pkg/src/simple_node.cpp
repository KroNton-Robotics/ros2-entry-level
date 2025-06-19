#include "rclcpp/rclcpp.hpp"


/* This example creates a basic ROS 2 node called "simple_node" 
that outputs a startup message when initialized. */

class SimpleNode : public rclcpp::Node
{
public:
  SimpleNode()
  : Node("simple_node")
  {
    RCLCPP_INFO(this->get_logger(), "Simple node Is starting up...");

  }
    ~SimpleNode()
    {
        RCLCPP_INFO(this->get_logger(), "Simple node Is shutting down...");
    }
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleNode>());
  rclcpp::shutdown();
  return 0;
}