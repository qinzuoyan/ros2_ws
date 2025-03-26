# ROS2 Exercise

## Build
Build all packages:
```bash
colcon build
```

Build selected packages:
```bash
colcon build --packages-select hello_world_cpp complex_communication_cpp
```

## Run

Run talker/listener demo:
```
ros2 run demo_nodes_cpp talker
ros2 run demo_nodes_py listener
```

Run turtlesim demo:
```
ros2 run turtlesim turtlesim_node
ros2 run turtlesim turtle_teleop_key
```

Run hello_world_node:
```
source install/setup.bash
ros2 run hello_world_cpp hello_world_node
```

## Tools
List packages:
```
ros2 pkg list
```

List executables of a package:
```
ros2 pkg executables hello_world_cpp
```

Show the install path of a package:
```
ros2 pkg prefix hello_world_cpp
```

Show the content of package.xml for a package:
```
ros2 pkg xml hello_world_cpp
```


## Docs
* https://zhuanlan.zhihu.com/p/22566509168

