project(MYTEST)    # 指定工程名字
# 编译main.cpp(注意这里可以添加多个cpp文件编译)，生成main.exe的可执行文件
#aux_source_directory(. CPP_LIST)     # 搜索当前目录下所有的cpp文件
#add_executable(main ${CPP_LIST})
add_executable(stl stl.cpp)
add_executable(linkedlist linkedlist.cpp)
add_executable(template template.cpp)

add_executable(function function.cpp func.cpp)
add_executable(zhizhen zhizhen.cpp)
add_executable(basic basic_class.cpp)
add_executable(stream stream.cpp)
add_definitions("-Wall -g")     # 添加可调试编译选项
