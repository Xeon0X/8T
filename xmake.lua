add_requires("ftxui", "libsdl_ttf", "libsdl_image")
add_requires("imgui" , {configs = {sdl2 = true, sdl2_renderer = true,sdl2_opengl3 = true}})
add_requires("libsdl", {configs = {sdlmain = false}})
add_requires("opengl", "glfw")
add_includedirs("src", "src/core", "src/core/rules")
set_languages("c++17")
set_warnings("all") 

target("core")
    set_kind("static")
    add_files("src/core/**.cpp")

target("graphic_files")
    set_kind("static")
    add_packages("libsdl", "libsdl_ttf", "libsdl_image", "imgui","opengl", "glfw")
    add_files("src/graphics/**.cpp")

target("console")
    set_kind("binary")
    add_files("src/console/**.cpp")
    add_packages("ftxui")
    add_deps("core")
    set_default(false)
    set_targetdir("bin")



target("graphic")
    set_kind("binary")
    add_files("src/menu/**.cpp")
    add_packages("libsdl", "libsdl_ttf", "libsdl_image", "imgui","opengl", "glfw")
    add_deps("graphic_files")
    set_rundir("$(projectdir)/bin")
    add_deps("core")
    set_default(true)
    set_targetdir("bin")


target("test")
    set_kind("binary")
    add_files("src/core/**.cpp")
    set_default(false)
    set_targetdir("bin")
    