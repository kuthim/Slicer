
#-----------------------------------------------------------------------------
set(BASELINE ${CMAKE_CURRENT_SOURCE_DIR}/../Data/Baseline)
set(CLP ${MODULE_NAME})

#-----------------------------------------------------------------------------
add_executable(${CLP}Test ${CLP}Test.cxx)
target_link_libraries(${CLP}Test ${CLP}Lib ${SlicerExecutionModel_EXTRA_EXECUTABLE_TARGET_LIBRARIES})
set_target_properties(${CLP}Test PROPERTIES LABELS ${CLP})
set_target_properties(${CLP}Test PROPERTIES FOLDER ${${CLP}_TARGETS_FOLDER})

set(testname ${CLP}Test)
add_test(NAME ${testname} COMMAND ${SEM_LAUNCH_COMMAND} $<TARGET_FILE:${CLP}Test>
  --compare ${BASELINE}/GaussianBlurImageFilterTest.nhdr
  ${TEMP}/GaussianBlurImageFilterTest.nhdr
  ModuleEntryPoint
  --sigma 2.5 ${TEST_DATA}/CTHeadAxial.nhdr ${TEMP}/GaussianBlurImageFilterTest.nhdr
  )
set_property(TEST ${testname} PROPERTY LABELS ${CLP})

