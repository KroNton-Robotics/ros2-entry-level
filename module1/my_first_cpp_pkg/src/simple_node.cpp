#include "rclcpp/rclcpp.hpp"


/* This example creates a basic ROS 2 node called "simple_node" 
that outputs a startup message when initialized. */

class SimpleNode : public rclcpp::Node
{

  public:

    SimpleNode(): Node("simple_node")// member initializer list
    {
      RCLCPP_INFO(this->get_logger(), "Simple node Is starting up...");

      //RCLCPP_INFO → Logs a message at the "INFO" level (general operational messages).
      //this->get_logger() → Gets the logger associated with this node (includes the node name in logs).
    }

};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<SimpleNode>();  // Heap allocation + shared_ptr
  
  rclcpp::spin(node);  
  rclcpp::shutdown();
  return 0;
}