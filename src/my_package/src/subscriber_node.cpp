#include "rclcpp/rclcpp.hpp"
#include "my_interfaces/msg/my_message.hpp"

class SubscriberNode : public rclcpp::Node {
public:
    SubscriberNode() : Node("my_subscriber") {
        subscriber_ = this->create_subscription<my_interfaces::msg::MyMessage>(
            "my_topic", 10,
            [this](const my_interfaces::msg::MyMessage::SharedPtr msg) {
                RCLCPP_INFO(this->get_logger(), "Received: id=%d, data=%s, value=%.2f", 
                          msg->id, msg->data.c_str(), msg->value);
            });
    }

private:
    rclcpp::Subscription<my_interfaces::msg::MyMessage>::SharedPtr subscriber_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SubscriberNode>());
    rclcpp::shutdown();
    return 0;
}
