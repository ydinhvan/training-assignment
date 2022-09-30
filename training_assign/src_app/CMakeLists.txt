
# build application from source file

add_executable(App main.c execute_command.c signal_handler.c)

#add dependence of target
#syntax
# add-dependencies(target target_dependencies)
#
add_dependencies(App 
                Read_Write_lib)

# link to library
target_link_libraries(App LINK_PUBLIC Read_Write_lib)