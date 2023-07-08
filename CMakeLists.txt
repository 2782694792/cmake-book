# 1. 设置最低版本，低于该版本发出致命错误
cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
# 2. 声明项目名称、版本和支持的编程语言 cpp
project(CMGCC7.3.0 VERSION 0.1.0 LANGUAGES CXX)

# 3. 添加源代码文件目录
set(TITLE Chap01) # 设置变量——标题
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
# 4. 添加头文件目录
include_directories(${PROJECT_SOURCE_DIR}/include INC)

# 5. 创建目标，生成静态库
# add_library(Chap01
#     STATIC 
#     ./include/Chap01/Message.hpp
#     ./src/Chap01/Message.cpp
# )

# 6. 对象库，一次性创建静态库和动态库
set(MAKE_OBJ_LIB OFF) # 设置变量初始化
option(MAKE_OBJ_LIB "Compile sources into a object-library?" OFF) # 设置选项，默认false，cmake 编译时通过 -DUSE_LIB=ON 选项，切换库的行为
if(MAKE_OBJ_LIB)
    list(APPEND _sources # 局部变量，下划线声明
        "./include/${TITLE}/Message.hpp" 
        # "./src/${TITLE}/Message.cpp"
    )
    add_library(${TITLE}-objs
        # OBJECT ./include/${TITLE}/Message.hpp
        # ./src/${TITLE}/Message.cpp
        OBJECT ${_sources}
    )
    ## 6.1 创建动态库
    add_library(${TITLE}-shared
        SHARED $<TARGET_OBJECTS:${TITLE}-objs>
    )
    set_target_properties(${TITLE}-shared
        PROPERTIES OUTPUT_NAME ${TITLE}
    )

    ## 6.2 创建静态库
    add_library(${TITLE}-static
        SHARED $<TARGET_OBJECTS:${TITLE}-objs>
    )
    set_target_properties(${TITLE}-shared
        PROPERTIES OUTPUT_NAME ${TITLE}
    )

    ## 6.3 库文件输出路径
    LIBRARY_OUTPUT_DIRECTORY(${PROJECT_SOURCE_DIR}/lib)

    # z1. 将目标静态库链接到可执行文件
    
    target_link_libraries(${OUTPUT} ${TITLE}-static)
else()
    message(STATUS "Compile sources into a library? ${MAKE_OBJ_LIB}")
endif(MAKE_OBJ_LIB)

# z. 设置可执行文件的输出名称
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) ## 设置输出文件路径
set(OUTPUT ${PROJECT_NAME}_${TITLE})
add_executable(${OUTPUT} ${SRC})

