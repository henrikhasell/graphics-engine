cmake_minimum_required(VERSION 3.7)
project("Rendering Engine")

include_directories(include)

add_executable(engine
    src/application.cpp
    src/camera.cpp
    src/configuration.cpp
    src/loader.cpp
    src/main.cpp
    src/model.cpp
    src/program.cpp
    src/renderer.cpp
    src/shader.cpp
    src/simple.cpp
    src/texture.cpp
)

# target_link_libraries(engine
#     mingw32
#     SDL2main
#     SDL2
#     OpenGL32
#     glew32
#     yaml
#     assimp
# )

target_link_libraries(engine
        SDL2main
        SDL2
        SDL2_image
        GL
        GLEW
        yaml
        assimp
        )
