cmake_minimum_required(VERSION 3.31)
project(VARIABLES_Lesson)

# 普通变量的值按字符串处理；双引号可保留空格。
set(MyVar "hello world")
message("myVar =  ${MyVar}")

# 多个值会组成以分号分隔的列表。
set(pet my ${MyVar})
message(${pet})

# 变量名区分大小写；这里用变量值 dog 作为另一个变量名。
set(myVarr dog)
set(${myVarr} cat)
message("${myVarr}=${${myVarr}}")

# 多行字符串中可展开变量；引用时使用 ${变量名}。
set(multiline "
Hello,
${MyVar}
")
message("${multiline}")

# CACHE 变量会写入 CMakeCache.txt，BOOL 类型适合开关选项。
set(DEMO_IS_PARALLEL off CACHE BOOL "Is using parallel algorithm")

# block 中的普通变量是局部副本；离开 block 后外层值不变。
set(myVar cat)
block()
    set(myVar dog)
    message("myVar=${myVar}")
endblock()
message("myVar=${myVar}")

# PARENT_SCOPE 将赋值写到父级作用域；block 内仍读到局部值。
set(myVar cat)
block()
    set(myVar dog PARENT_SCOPE)
    message("myVar=${myVar}")
endblock()
message("myVar=${myVar}")

# PROPAGATE 让 block 内的变量修改在结束时传递到父级作用域。
set(myVar cat)
block(PROPAGATE)
set(myVar dog)
message("myVar=${myVar}") 
endblock()
message("myVar=${myVar}")