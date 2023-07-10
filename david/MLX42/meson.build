project('MLX42', 'c', version : '0.1',)

glfw_dep = dependency('glfw3')

inc = include_directories('include')

file = ['src/font/mlx_font.c',
  'src/mlx_cursor.c',
  'src/mlx_exit.c',
  'src/mlx_images.c',
  'src/mlx_init.c',
  'src/mlx_keys.c',
  'src/mlx_loop.c',
  'src/mlx_monitor.c',
  'src/mlx_mouse.c',
  'src/mlx_put_pixel.c',
  'src/mlx_window.c',
  'src/textures/mlx_png.c',
  'src/textures/mlx_texture.c',
  'src/textures/mlx_xpm42.c',
  'src/utils/mlx_compare.c',
  'src/utils/mlx_error.c',
  'src/utils/mlx_list.c',
  'src/utils/mlx_utils.c']


static_library('MLX42',
  file,
  dependencies: glfw_dep,
  include_directories : inc,
  install : true)
