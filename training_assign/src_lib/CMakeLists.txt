
# create library from source file
# create libRead_write_lib.a from read_write.c
add_library(Read_Write_lib read_write.c)

# Make sure the compiler can find and link to library
target_include_directories(Read_Write_lib PUBLIC $(CMAKE_CURRENT_SOURCE_DIR))
