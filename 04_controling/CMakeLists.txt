cmake_minimum_required(VERSION 3.30)
project(controling VERSION 0.1)
# 当表达式为1,ON,YES,TRUE,Y,非零数值的时候，为真，不区分大小写
# 当表达式为0,OFF,NO,FLASE,N,IGNORE,NOTFOUNT,*-NOTFOUND,""的时候，为假
# 特别的，对于字符串，只有字符串内内容为真值常量的带引号形式的时候，结果才为真
# (建议)在条件判断中，不使用字符串
# (建议)使用比较运算符对字符串进行判断
# 对于变量
# 其值不等于FALSE常量的时候，结果为真

#CMAKE_SOURCE_DIR 为CMAKELISTS所在位置
#CMAKE_BINARY_DIR 为构建目录

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "错误:禁止源码内编译")
endif()

set(v "hello")
if(v)# 视为变量
    message("${v} is true")
else()
    message("${v} if false")
endif()

if(${v})# 视为字符串
    message("${v} is true")
else()
    message("${v} if false")
endif()

#CMAKE中，逻辑运算符用关键字 AND OR NOT
#比较运算符，对于数值，使用LESS GREATER EQUAL LESS_EQUAL GREATER_EQUAL
#对于字符串，前面加上STR
#对于版本号，加上VERSION_
#对于路径，仅有PATH_EQUAL

if("/home" PATH_EQUAL "//home")
    message("PATH_EQUAL is true")
else()
    message("PATH_EQUAL is false")
endif()

if("/path//to/myfile" STREQUAL "/path/to/myfile")
    message("PATH_EQUAL is true")
else()
    message("PATH_EQUAL is false")
endif()
#正则表达式
if("my phone number is 12345" MATCHES "my phone number is ([0-9]+)")
    message("phone number:${CMAKE_MATCH_1}")
endif()

#存在性测试
set(list1 a b c d)
set(list2 e f g)
set(a "f")

if(a IN_LIST list1)
    message("a is in list1")
elseif(a IN_LIST list2)
    message("a is in list2")
else()
    message("a is not in list1 or list2")
endif()

unset(a) #此时 a未被引用，被当作字符串
if(a IN_LIST list1)
    message("a is in list1")
elseif(a IN_LIST list2)
    message("a is in list2")
else()
    message("a is not in list1 or list2")
endif()

#循环
foreach(v IN LISTS list1 list2)
    message("v=${v}")
endforeach()
foreach(v IN ZIP_LISTS list1 list2)
    message("v=${v_0},${v_1}")
endforeach()
foreach(v RANGE 1 8 2)
    message("v=${v}")
endforeach()
