#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/lifecycle_node.hpp>
#include <std_msgs/msg/string.hpp>
#include <memory>
#include <thread>

using std::placeholders::_1;
using namespace std::chrono_literals;

class SimpleLifecycleNode : public rclcpp_lifecycle::LifecycleNode
{

public:
    SimpleLifecycleNode(const std::string & node_name, bool intra_process_comms=false)
    :rclcpp_lifecycle::LifecycleNode(node_name,rclcpp::NodeOptions().use_intra_process_comms(intra_process_comms))
    {


    }
    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_configure(const rclcpp_lifecycle::State &){
        
        sub_= this->create_subscription<std_msgs::msg::String>("chatter",10,std::bind(&SimpleLifecycleNode::msgCallback,this,_1));
        RCLCPP_INFO(this->get_logger(),"Lifecycle Node on_configure() called");
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }
    

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_shutdown(const rclcpp_lifecycle::State &){
        
        sub_.reset();
        RCLCPP_INFO(this->get_logger(),"Lifecycle Node on_shutdown() called");
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_cleanup(const rclcpp_lifecycle::State &){
        
        sub_.reset();
        RCLCPP_INFO(this->get_logger(),"Lifecycle Node on_cleanup() called");
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_activate(const rclcpp_lifecycle::State & state){
        
        LifecycleNode::on_activate(state);
        RCLCPP_INFO(this->get_logger(),"Lifecycle Node on_activate() called");
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

    rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn on_deactivate(const rclcpp_lifecycle::State & state ){
        
        LifecycleNode::on_deactivate(state);
        RCLCPP_INFO(this->get_logger(),"Lifecycle Node on_deactivate() called");
        std::this_thread::sleep_for(2s);
        return rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn::SUCCESS;
    }

private:

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
    void msgCallback(const std_msgs::msg::String & msg){
        auto state=get_current_state();
        if (state.label()=="active"){
            RCLCPP_INFO_STREAM(this->get_logger(),"Lifecycle Node heard: "<<msg.data.c_str());
        }
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::executors::SingleThreadedExecutor executor;
    auto node = std::make_shared<SimpleLifecycleNode>("simple_lifecycle_node");
    executor.add_node(node->get_node_base_interface());
    executor.spin();
    rclcpp::shutdown();
    return 0;
}