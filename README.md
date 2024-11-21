## Resources

https://lodev.org/cgtutor/raycasting.html

https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/
Make Your Own Raycaster Part 1
https://www.youtube.com/watch?v=gYRrGTC7GtA&ab_channel=3DSage

https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf


/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d jhj.cub                                                                                                                                                                                                          19:16
Error: map file could not be opened
[1]    47633 segmentation fault (core dumped)  ./cub3d jhj.cub


[ok] wrong number of arguments
[ok] wrong extension

[ko] map that doesnt exist

./cub3d maps/map_samples.cub                                                                                                                                                                                        19:45
Error: map file could not be opened
[1]    54822 segmentation fault (core dumped)  ./cub3d maps/map_samples.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d mapss/map_samples.cub                                                                                                                                                                                       19:48
Error: map file could not be opened
[1]    54922 segmentation fault (core dumped)  ./cub3d mapss/map_samples.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d samples.cub                                                                                                                                                                                                 19:48
Error: map file could not be opened
[1]    54994 segmentation fault (core dumped)  ./cub3d samples.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:48
Texture error: invalid texture path.
[1]    55353 segmentation fault (core dumped)  ./cub3d maps/map_sample.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:50
Texture error: duplicated texture path.
[1]    55513 segmentation fault (core dumped)  ./cub3d maps/map_sample.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:51
[1]    55644 killed     ./cub3d maps/map_sample.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:51
Error: invalid color(s).
Please input valid RGB color(s) in theformat "R,G,B", where R, G, and B are integer values between 0 and 255.

/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:52
Error: map file has invalid line.
[1]    55946 segmentation fault (core dumped)  ./cub3d maps/map_sample.cub


valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup

./content_map:
1.0-incomplete_map.cub  3.0-unidentified_content.cub  4.1-map_after_map.cub
2.0-map_no_player.cub   3.1-wrong_char.cub
2.1-double_player.cub   4.0-element_after_map.cub

./info:
1.0-invalid_ext.cbb             2.6-map_texture_more_then_complete.cub
1.1-empty_file.cub              2.7-map_wrong_SO_texture.cub
1.2-only_map.cub                3.0-wrong_color_content.cub
2.0-double_texture.cub          3.1-map_duplicate_color.cub
2.1-missing_texture.cub         3.2-map_missing_color.cub
2.2-wrong_texture_content.cub   3.3-double_color.cub
2.3-wrong_texture_ext.cub       3.4-map_wrong_color.cub
2.4-map_duplicate_WE.cub        4.0-mixed_infos_OKAY.cub
2.5-map_texture_incomplete.cub

./wall:
1-open_wall_left.cub   4-open_wall.cub          7-open_line.cub
2-open_wall_right.cub  5-map_leaky_borders.cub
3-open_wall_down.cub   6-open_inside.cub


valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/1.0-incomplete_map.cub
Error: invalid map edges.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/2.0-map_no_player.cub
Error: map contains invalid number of players

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/2.1-double_player.cub
Error: map contains invalid number of players

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/3.0-unidentified_content.cub
Error: invalid map


valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/3.1-wrong_char.cub
Error: map contains invalid characters

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/4.0-element_after_map.cub
Error: map file has invalid line.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/4.1-map_after_map.cub
Error: invalid map
==29755== 460 bytes in 14 blocks are definitely lost in loss record 1,695 of 1,721
==29755==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==29755==    by 0x10CF91: ft_calloc (ft_calloc.c:31)
==29755==    by 0x10D3D8: ft_strdup (ft_strdup.c:30)
==29755==    by 0x10C1D5: handle_map_line (load_map.c:14)
==29755==    by 0x10C1D5: load_map_content (load_map.c:34)
==29755==    by 0x10BFFB: load_map_file (load_map_file.c:63)
==29755==    by 0x10AA99: ft_init_data (data.c:129)
==29755==    by 0x10A7D5: main (main.c:20)

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/1.0-invalid_ext.cbb
Error: invalid map extension
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/1.1-empty_file.cub
Error: map file could not be read.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/1.2-only_map.cub
Error: map file has invalid line.
==12627== 65 bytes in 1 blocks are still reachable in loss record 1,661 of 1,721
==12627==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==12627==    by 0x10DA91: extract_remaining (get_next_line.c:164)
==12627==    by 0x10DB7F: get_next_line (get_next_line.c:198)
==12627==    by 0x10C3BB: parse_textures (load_textures.c:81)
==12627==    by 0x10BF43: load_map_file (load_map_file.c:57)
==12627==    by 0x10AA99: ft_init_data (data.c:129)
==12627==    by 0x10A7D5: main (main.c:20)

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.0-double_texture.cub
Texture error: duplicated texture path.
==12805== 473 bytes in 1 blocks are still reachable in loss record 1,695 of 1,721
==12805==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==12805==    by 0x10DA91: extract_remaining (get_next_line.c:164)
==12805==    by 0x10DB7F: get_next_line (get_next_line.c:198)
==12805==    by 0x10C4B9: parse_textures (load_textures.c:91)
==12805==    by 0x10BF43: load_map_file (load_map_file.c:57)
==12805==    by 0x10AA99: ft_init_data (data.c:129)
==12805==    by 0x10A7D5: main (main.c:20)

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.1-missing_texture.cub
Error: map file has invalid line.
==12961== 414 bytes in 1 blocks are still reachable in loss record 1,695 of 1,721
==12961==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==12961==    by 0x10DA91: extract_remaining (get_next_line.c:164)
==12961==    by 0x10DB7F: get_next_line (get_next_line.c:198)
==12961==    by 0x10C4B9: parse_textures (load_textures.c:91)
==12961==    by 0x10BF43: load_map_file (load_map_file.c:57)
==12961==    by 0x10AA99: ft_init_data (data.c:129)
==12961==    by 0x10A7D5: main (main.c:20)

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.2-wrong_texture_content.cub
Texture error: invalid texture path.
==13127== 573 bytes in 1 blocks are still reachable in loss record 1,697 of 1,721
==13127==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==13127==    by 0x10DA91: extract_remaining (get_next_line.c:164)
==13127==    by 0x10DB7F: get_next_line (get_next_line.c:198)
==13127==    by 0x10C3BB: parse_textures (load_textures.c:81)
==13127==    by 0x10BF43: load_map_file (load_map_file.c:57)
==13127==    by 0x10AA99: ft_init_data (data.c:129)
==13127==    by 0x10A7D5: main (main.c:20)

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.3-wrong_texture_ext.cub
Texture error: invalid texture path.
==13270== 538 bytes in 1 blocks are still reachable in loss record 1,697 of 1,721
==13270==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==13270==    by 0x10DA91: extract_remaining (get_next_line.c:164)
==13270==    by 0x10DB7F: get_next_line (get_next_line.c:198)
==13270==    by 0x10C4B9: parse_textures (load_textures.c:91)
==13270==    by 0x10BF43: load_map_file (load_map_file.c:57)
==13270==    by 0x10AA99: ft_init_data (data.c:129)
==13270==    by 0x10A7D5: main (main.c:20)
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.4-map_duplicate_WE.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.5-map_texture_incomplete.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.6-map_texture_more_then_complete.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.7-map_wrong_SO_texture.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.0-wrong_color_content.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.1-map_duplicate_color.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.2-map_missing_color.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.3-double_color.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.4-map_wrong_color.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/4.0-mixed_infos_OKAY.cub
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d s


valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/1-open_wall_left.cub
Error: invalid map extern walls.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/2-open_wall_right.cub
Error: invalid map extern walls.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/3-open_wall_down.cub
Error: invalid map extern walls.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/5-map_leaky_borders.cub
Error: invalid map extern walls.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/6-open_inside.cub
Error: invalid map edges.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/7-open_line.cub

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup
