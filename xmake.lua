add_requires("ftxui", "libsdl", "libsdl_ttf", "libsdl_image")

add_includedirs("src", "src/core", "src/core/rules")

target("core")
    set_kind("shared")
    add_files("src/core/**.cpp")

target("console")
    set_kind("binary")
    add_files("src/console/**.cpp")
    add_packages("ftxui")
    add_deps("core")
    set_default(true)


target("graphic")
    set_kind("binary")
    add_files("src/graphics/**.cpp")
    add_packages("libsdl", "libsdl_ttf", "libsdl_image")
    set_rundir("$(projectdir)/bin")
    add_deps("core")
    set_default(false)