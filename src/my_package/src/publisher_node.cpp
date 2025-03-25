#include "rclcpp/rclcpp.hpp"
#include "my_interfaces/msg/my_message.hpp"

class PublisherNode : public rclcpp::Node {
public:
    PublisherNode() : Node("my_publisher") {
        publisher_ = this->create_publisher<my_interfaces::msg::MyMessage>("my_topic", 10);
        timer_ = this->create_wall_timer(
            std::chrono::seconds(1),
            [this]() {
                auto message = my_interfaces::msg::MyMessage();
                message.id = count_++;
                message.data = "Hello ROS2";
                message.value = 3.14;
                publisher_->publish(message);
                RCLCPP_INFO(this->get_logger(), "Publishing: id=%d, data=%s, value=%.2f", 
                          message.id, message.data.c_str(), message.value);
            });
    }

private:
    rclcpp::Publisher<my_interfaces::msg::MyMessage>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    int count_ = 0;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PublisherNode>());
    rclcpp::shutdown();
    return 0;
}
