project(example)

message("Test Codes")

SET ( SUBDIRS
    dlOpen
)

foreach(SUBDIR ${SUBDIRS})
  add_subdirectory(${SUBDIR})
endforeach()

