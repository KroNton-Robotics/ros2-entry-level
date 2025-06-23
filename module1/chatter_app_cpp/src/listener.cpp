#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class ChatterSubscriber : public rclcpp::Node
{
public:
  ChatterSubscriber()
  : Node("Chatter_subscriber")
  {
    auto topic_callback =
      [this](std_msgs::msg::String::UniquePtr msg) -> void {
        
      };
    subscription_ =
      this->create_subscription<std_msgs::msg::String>("chatter", 10, topic_callback);
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
  void topic_callback(std_msgs::msg::String::UniquePtr msg){
        RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
  }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ChatterSubscriber>());
  rclcpp::shutdown();
  return 0;
}