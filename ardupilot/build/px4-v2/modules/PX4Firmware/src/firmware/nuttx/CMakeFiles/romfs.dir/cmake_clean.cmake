file(REMOVE_RECURSE
  "romfs.o"
  "libromfs.pdb"
  "libromfs.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/romfs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
