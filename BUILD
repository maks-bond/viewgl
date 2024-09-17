cc_library(
    name = "glad",
    srcs = ["glad.c"],
    hdrs = ["glad.h"],
)

cc_binary(
    name = "viewgl",
    srcs = ["main.cpp"],
    copts = [
        "-I/usr/include/GL",  # Path to OpenGL headers
        "-I/usr/local/include",  # Common path for GLFW/GLEW headers
    ],
    linkopts = [
        "-L/usr/lib",  # Path to OpenGL libraries
        "-L/usr/local/lib",  # Common path for GLFW/GLEW libraries
        "-lGL",
        "-lglfw",
        "-lGLEW",
    ],
    deps = [
        ":glad",
    ]
)