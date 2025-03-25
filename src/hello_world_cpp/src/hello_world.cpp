#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared("hello_world_cpp");
    
    // 输出日志信息
    RCLCPP_INFO(node->get_logger(), "Hello World!");
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
