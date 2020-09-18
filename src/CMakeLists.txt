project(example)

message("Test Codes")

SET ( SUBDIRS
    dlOpen
    jsonWrapper
)

foreach(SUBDIR ${SUBDIRS})
  add_subdirectory(${SUBDIR})
endforeach()

