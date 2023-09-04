#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"  // Replace with the appropriate message type

class PingSubscriberNode : public rclcpp::Node
{
public:
    PingSubscriberNode() : Node("ping_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "ping",
            10,
            [this](const std_msgs::msg::String::SharedPtr msg) {
                RCLCPP_INFO(this->get_logger(), "Received: %s", msg->data.c_str());
            });
    }

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PingSubscriberNode>());
    rclcpp::shutdown();
    return 0;
}
