if(EXISTS "/nfs/homes/dafranco/TRONCOMMUN/cub3d/cub3d/cub/david/MLX42/tests/build/unit_tests[1]_tests.cmake")
  include("/nfs/homes/dafranco/TRONCOMMUN/cub3d/cub3d/cub/david/MLX42/tests/build/unit_tests[1]_tests.cmake")
else()
  add_test(unit_tests_NOT_BUILT unit_tests_NOT_BUILT)
endif()
