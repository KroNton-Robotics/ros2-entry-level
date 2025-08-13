#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <std_msgs/msg/string.hpp>
#include <memory>

using std::placeholders::_1;

class SimpleLifecycleNode : public rclcpp_lifecycle::LifecycleNode
{

public:
    SimpleLifecycleNode(const std::string & node_name, bool intra_process_comms=false)
    :rclcpp_lifecycle::LifecycleNode(node_name,rclcpp::NodeOptions().use_intra_process_comms(intra_process_comms))
    {


    }
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State &){
        
        sub_= this->create_subscription<std_msgs::msg::String>("chatter",10,std::bind(&SimpleLifecycleNode::msgCallback,this,_1));
    }
    
    // ~SimpleLifecycleNode(){
        
    // }

private:

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
    void msgCallback(){

    }
};

