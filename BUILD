cc_library(
    name = "glad",
    srcs = ["glad.c"],
    hdrs = ["glad.h"],
)

exports_files(["vertex_shader.glsl", "fragment_shader.glsl"])

cc_library(
    name = "shader",
    srcs = ["shader.cpp"],
    hdrs = ["shader.h"],
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
    ],
)

cc_library(
    name = "camera",
    srcs = ["camera.cpp"],
    hdrs = ["camera.h"],
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
    ],
)

cc_library(
    name = "cube",
    srcs = ["cube.cpp"],
    hdrs = ["cube.h"],
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
        ":shader",
    ],
    visibility = ["//visibility:public"],
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
        ":cube",
        ":shader",
        ":camera",
    ],
    data = ["vertex_shader.glsl", "fragment_shader.glsl"]  # <== Ensure shaders are included
)