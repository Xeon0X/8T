add_requires("ftxui", "libsdl_ttf", "libsdl_image")
add_requires("libsdl", {configs = {sdlmain = false}})
add_includedirs("src", "src/core", "src/core/rules")
set_languages("c++17")

target("core")
    set_kind("static")
    add_files("src/core/**.cpp")

target("console")
    set_kind("binary")
    add_files("src/console/**.cpp")
    add_packages("ftxui")
    add_deps("core")
    set_default(true)
    set_targetdir("bin")


target("graphic")
    set_kind("binary")
    add_files("src/graphics/**.cpp")
    add_packages("libsdl", "libsdl_ttf", "libsdl_image")
    set_rundir("$(projectdir)/bin")
    add_deps("core")
    set_default(true)
    set_targetdir("bin")


target("test")
    set_kind("binary")
    add_files("src/core/**.cpp")
    set_default(true)
    set_targetdir("bin")
    